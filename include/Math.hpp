#pragma once

class Vector2f{
public:
	Vector2f()
	:m_x(0.0f), m_y(0.0f)
	{}
	Vector2f(float x, float y)
	:m_x(x), m_y(y)
	{}
	float x();
	float y();
	void print();

private:
	float m_x, m_y;

};