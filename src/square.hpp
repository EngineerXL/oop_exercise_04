#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <iostream>
#include <tuple>
#include <vector>

template<class T>
struct Square {
	/* Cords of left bottom corner, side */
	std::pair<T, T> Cord;
	T Side;

	Square(const std::pair<T, T> & cord, T side) : Cord(cord), Side(side) {}
};

template<class T>
T CalcSquare(const Square<T> & Sq) {
	return Sq.Side * Sq.Side;
}

template<class T>
std::ostream & operator << (std::ostream & out, const Square<T> & sq) {
	out << "Square {";
	out << std::pair<T, T>(sq.Cord.first, sq.Cord.second) << ", ";
	out << std::pair<T, T>(sq.Cord.first, sq.Cord.second + sq.Side) << ", ";
	out << std::pair<T, T>(sq.Cord.first + sq.Side, sq.Cord.second + sq.Side) << ", ";
	out << std::pair<T, T>(sq.Cord.first + sq.Side, sq.Cord.second);
	out << "}";
	return out;
}

#endif /* SQUARE_HPP */