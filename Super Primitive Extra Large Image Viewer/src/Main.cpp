#include <SDL\SDL.h>
#include <SDL\SDL_ttf.h>
#include <SDL\SDL_image.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Vector2.h"
#include <sstream>
#include <chrono>
#include <thread>
#include "Vector3.h"
#include "helpers.h"
#include "draw.h"
#include "algorithms.h"
#include "Matrix3.h"
#include "Triangle.h"
#include <fstream>
#include "Building.h"
#include "Graphics.h"
#include "globals.h"
#include "ScreenSpaceTransformer.h"
#include "VerticeList.h"
#include <algorithm>
#include "Model.h"
Vector2 SCREEN_SIZE(1920,1080);

double FPS_UPDATE_INTERVAL= 0.3333;
SDL_Window* WINDOW;
using namespace std;
#undef main
bool PRESENTER_ACTIVE = false;
int main()
{
	VerticeList verticeList;
	globals::verticeList = &verticeList;
	uint64_t framesRendered = 0;
	uint64_t lastFpsUpdateFramesRendered = 0;
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
//	WINDOW = SDL_CreateWindow("Miner's Land", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_SIZE.x, SCREEN_SIZE.y, 0);
	SDL_Surface* windowSurface = SDL_GetWindowSurface(WINDOW);
	SDL_Surface* background = IMG_Load("C:/Users/AdmiralMyxtaR/Pictures/4334.png");
	TTF_Font* fpsFont = TTF_OpenFont("c:/windows/fonts/arial.ttf", 20);
	SDL_Surface* fpsSurface = TTF_RenderText_Blended(fpsFont, "nan FPS", { 255,255,255 });
	SDL_Surface* pxRateSurface = TTF_RenderText_Blended(fpsFont, "nan px/s", { 255,255,255 });
	cout << TTF_GetError();
	string fpsString, pxRateString;
	auto lastFpsUpdateTime = chrono::high_resolution_clock::now();
	Vector3 cameraPos(0,0,-1);
	Vector3 cameraAngle;
	Vector3 cameraSpeed(0,0,0);
	Vector3 cameraAngleNormal;
	double maxCamSpeed = 1.0/60;
	Vector3 unit = { 1,1,1 };
	
	std::vector<Building> buildings;
	Graphics graphics;
	std::ifstream f("e:/fc/3d/sphere.raw");
	ScreenSpaceTransformer sst(SCREEN_SIZE);
	globals::sst = &sst;
	globals::graphics = &graphics;
	globals::cameraAngle = &cameraAngle;
	globals::cameraPos = &cameraPos;
	double x, y, z, dx, dy, dz;
	/*while (f)
	{
		f >> x >> y >> z >> dx >>dy>>dz;
		Vector3 pos(x, y, z);
		Vector3 dims(dx,dy,dz);
		buildings.push_back(Building(pos, dims));
	}*/
	Vector3 min = Vector3(1,1,1)*INFINITY;
	Vector3 max = -min;	
	Model sphere;
	{
		std::vector <Triangle> polygons;
		while (f)
		{
			Vector3 v[3];
			f >> x >> y >> z;
			v[0] = { x,y,z };
			f >> x >> y >> z;
			v[1] = { x,y,z };
			f >> x >> y >> z;
			v[2] = { x,y,z };
			polygons.emplace_back(v[0], v[1], v[2]);
			for (int i = 0; i < 3; ++i)
			{
				min.x = std::min(min.x, v[i].x);
				min.y = std::min(min.y, v[i].y);
				min.z = std::min(min.z, v[i].z);
				max.x = std::max(max.x, v[i].x);
				max.y = std::max(max.y, v[i].y);
				max.z = std::max(max.z, v[i].z);
			}
		}
		sphere = Model(Vector3(0, 0, 0), nullptr, polygons);
	}
	
	SDL_Event events;
	auto lastFrameTime = chrono::high_resolution_clock::now();
	//std::cout << polygons.size() << " triangles" << std::endl << verticeList.vertices.size() << " vertices" << std::endl << polygons.size() * 3 - verticeList.vertices.size() << " shared vertices" << endl;
	while (true)
	{
		SDL_PollEvent(&events);
		if (cameraAngle == Vector3(0, 0, 0)) cameraAngleNormal = { 1,0,0 };
		else cameraAngleNormal = cameraAngle / cameraAngle.length();
		SDL_Scancode& key = events.key.keysym.scancode;
		if (key == SDL_SCANCODE_D) cameraPos += Vector3(0.01, 0, 0);
		if (key == SDL_SCANCODE_A) cameraPos -= Vector3(0.01, 0, 0);

		if (key == SDL_SCANCODE_W) cameraPos += cameraAngleNormal*maxCamSpeed;
		if (key == SDL_SCANCODE_S) cameraPos -= cameraAngleNormal*maxCamSpeed;

		if (key == SDL_SCANCODE_UP) cameraAngle += Vector3(0.0, 0, 0.01);
		if (key == SDL_SCANCODE_DOWN) cameraAngle -= Vector3(0.0, 0, 0.01);

		if (key == SDL_SCANCODE_LEFT) cameraAngle += Vector3(0.0, 0.01, 0.00);
		if (key == SDL_SCANCODE_RIGHT) cameraAngle -= Vector3(0.0, 0.01, 0.00);

		if (key == SDL_SCANCODE_Z) cameraAngle += Vector3(0.01, 0.0, 0.0);
		if (key == SDL_SCANCODE_C) cameraAngle -= Vector3(0.01, 0.00, 0.0);

		if (key == SDL_SCANCODE_U) cameraPos += Vector3(0.0, 0.010, 0.00);
		if (key == SDL_SCANCODE_I) cameraPos -= Vector3(0.0, 0.01, 0.00);

		if (key == SDL_SCANCODE_I) sphere.addPos(Vector3(0.01, 0, 0));
		if (key == SDL_SCANCODE_K) sphere.addPos(Vector3(-0.01, 0, 0));
		if (key == SDL_SCANCODE_J) sphere.addPos(Vector3(0.0, 0.01, 0));
		if (key == SDL_SCANCODE_K) sphere.addPos(Vector3(0.0, -0.01, 0));
		if (key == SDL_SCANCODE_N) sphere.addPos(Vector3(0, 0, 0.01));
		if (key == SDL_SCANCODE_M) sphere.addPos(Vector3(0.0, 0, -0.01));

		cameraAngle.x = fmod(cameraAngle.x, 2 * M_PI);
		cameraAngle.y = fmod(cameraAngle.y, 2 * M_PI);
		cameraAngle.z = fmod(cameraAngle.z, 2 * M_PI);

		double currFrameTime = (chrono::high_resolution_clock::now() - lastFrameTime).count()*1e-9;

		cameraPos += cameraSpeed*currFrameTime;
		lastFrameTime = chrono::high_resolution_clock::now();
		//verticeList.transform();
		Matrix3 rot = getRotationMatrix(cameraAngle);
		globals::rotationMatrix = &rot;
	//	for (auto& it : buildings) it.draw(graphics.renderer, SCREEN_SIZE.y, cameraPos, cameraAngle);
		//for (auto& it : polygons) it.draw();
		sphere.draw();
		graphics.flip();
		graphics.clear();
		//SDL_RenderPresent(graphics.renderer);
		framesRendered++;
		//verticeList.beginNewFrame();
		//graphics.drawLine(Vector2(10000000, 10000000), Vector2(-10000000, -10000000),255,255,255);
		auto currTime = chrono::high_resolution_clock::now();
		double timeSinceLastFpsUpdate = (currTime - lastFpsUpdateTime).count()*1e-9;
		if (timeSinceLastFpsUpdate >= 0.5)
		{
			uint64_t framesDelta = framesRendered - lastFpsUpdateFramesRendered;
			double fps = framesDelta / timeSinceLastFpsUpdate;
			lastFpsUpdateFramesRendered = framesRendered;
			lastFpsUpdateTime = currTime;
			cout << fps << " FPS" << "\n";
		}
	}
}