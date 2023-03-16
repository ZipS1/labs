#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

class Shape
{
public:
	virtual double getArea() = 0;
	virtual double getPerimeter() = 0;
	virtual ~Shape() {};
};

class Circle : public Shape
{
public:
	Circle(double rad) : radius(rad) {}
	double getArea();
	double getPerimeter();

private:
	double radius;
};

class Parallelogram : public Shape
{
public:
	Parallelogram(double b, double h, double ang) : 
		base(b), height(h), angle(ang) {}
	double getArea();
	double getPerimeter();

private:
	double base;
	double height;
	double angle;
};

class Trapezoid : public Shape
{
public:
	Trapezoid(double upper, double bottom, double rightside, double leftside) :
		upperBase(upper), bottomBase(bottom), rightSide(rightside), leftSide(leftside) {}
	double getArea();
	double getPerimeter();

private:
	void calculateHeight();
	double height = 0;
	double upperBase;
	double bottomBase;
	double leftSide;
	double rightSide;
};