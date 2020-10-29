#ifndef TRAPEZE_HPP
#define TRAPEZE_HPP

#include <iostream>
#include <tuple>
#include <vector>

template<class T>
struct Trapeze {
	/* Cords of left bottom corner, greater and smaller base, heigth */
	std::pair<T, T> Cord;
	T GreaterBase, SmallerBase, Height;

	Trapeze(const std::pair<T, T> & cord, T greaterBase, T smallerBase, T height) : Cord(cord), GreaterBase(greaterBase), SmallerBase(smallerBase), Height(height) {
		if (SmallerBase > GreaterBase) {
			std::swap(SmallerBase, GreaterBase);
		}
	}
};

template<class T>
T CalcSquare(const Trapeze<T> & trapeze) {
	return (trapeze.Height * (trapeze.GreaterBase + trapeze.SmallerBase)) / 2.0;
}

template<class T>
std::ostream & operator << (std::ostream & out, const Trapeze<T> & trapeze) {
	T d = (trapeze.GreaterBase - trapeze.SmallerBase) / 2.0;
	out << "Trapeze {";
	out << std::pair<T, T>(trapeze.Cord.first, trapeze.Cord.second) << ", ";
	out << std::pair<T, T>(trapeze.Cord.first + d, trapeze.Cord.second + trapeze.Height) << ", ";
	out << std::pair<T, T>(trapeze.Cord.first + trapeze.SmallerBase + d, trapeze.Cord.second + trapeze.Height) << ", ";
	out << std::pair<T, T>(trapeze.Cord.first + trapeze.GreaterBase, trapeze.Cord.second);
	out << "}";
	return out;
}

#endif /* TRAPEZE_HPP */