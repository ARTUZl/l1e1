//---------------------------------------------------------------------------

#pragma hdrstop

#include "Circle.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

Circle::Circle(double x, double y, double r) {
	xCenter = x;
	yCenter = y;
	radius = r;
}

void Circle::setCenter(double x, double y) {
	xCenter = x;
	yCenter = y;
}

void Circle::setRadius(double x) {
	radius = x;
}

double Circle::Square() {
	return M_PI*pow(radius,2);
}

double Circle::Perimeter() {
	return 2*M_PI*radius;
}

double Circle::xLeftTop() {
	return xCenter - radius;
}

double Circle::yLeftTop() {
	return yCenter - radius;
}

double Circle::xRightBottom() {
	return xCenter + radius;
}

double Circle::yRightBottom() {
	return yCenter + radius;
}

double Circle::getxCenter() {
	return xCenter;
}

double Circle::getyCenter() {
    return yCenter;
}

double Circle::getRadius() {
    return radius;
}
