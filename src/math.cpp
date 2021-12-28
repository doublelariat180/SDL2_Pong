#include <iostream>

#include "Math.hpp"

float Vector2f::x(){
	return m_x;
}

float Vector2f::y(){
	return m_y;
}

void Vector2f::print(){
	std::cout << m_x << ", " << m_y << std::endl;
}