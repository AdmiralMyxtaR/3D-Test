#pragma once
struct SDL_Rect;
struct Vector2
{
	double x, y;
	Vector2();
	Vector2(double _x, double _y);
	Vector2(SDL_Rect& rect, bool initByPos);
	Vector2 zero();
	void nullify();
	bool isNull();
	Vector2 operator+(Vector2& other);
	Vector2 operator-(Vector2& other);
	Vector2 operator*(Vector2& other);
	Vector2 operator/(Vector2& other);
	Vector2 operator*(double mult);
	Vector2 operator/(double div);
	friend Vector2 operator-(Vector2& v);
	void operator+=(Vector2& other);
	void operator-=(Vector2& other);
	void operator*=(Vector2& other);
	void operator/=(Vector2& other);
	void operator*=(double mult);
	bool operator==(Vector2& other);
	double length();
	double distance(Vector2& other);
	double dot(Vector2& rhs);
	Vector2 abs();
};