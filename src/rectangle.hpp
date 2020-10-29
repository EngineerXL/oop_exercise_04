#ifndef RECTANGLE_CPP
#define RECTANGLE_CPP

#include <iostream>
#include <tuple>
#include <vector>

template<class T>
struct Rectangle {
	/* Cords of left bottom corner, width and height */
	std::pair<T, T> Cord;
	T Width, Height;

	Rectangle(const std::pair<T, T> & cord, T width, T height) : Cord(cord), Width(width), Height(height) {}
};

template<class T>
T CalcSquare(const Rectangle<T> & rectangle) {
	return rectangle.Width * rectangle.Height;
}

template<class T>
std::ostream & operator << (std::ostream & out, const Rectangle<T> & rectangle) {
	out << "Rectanle {";
	out << std::pair<T, T>(rectangle.Cord.first, rectangle.Cord.second) << ", ";
	out << std::pair<T, T>(rectangle.Cord.first, rectangle.Cord.second + rectangle.Height) << ", ";
	out << std::pair<T, T>(rectangle.Cord.first + rectangle.Width, rectangle.Cord.second + rectangle.Height) << ", ";
	out << std::pair<T, T>(rectangle.Cord.first + rectangle.Width, rectangle.Cord.second);
	out << "}";
	return out;
}

#endif /* RECTANGLE_CPP */