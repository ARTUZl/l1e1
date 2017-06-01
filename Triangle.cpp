//---------------------------------------------------------------------------

#pragma hdrstop

#include "Triangle.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
Triangle::Triagle(double ay, double by, double cy,
		  double ax, double bx, double cx){
	 xCoordA = ax;
	 xCoordB = bx;
	 xCoordC = cx;
	 yCoordA = ay;
	 yCoordB = by;
	 yCoordC = cy;
}

void Triangle::setCenter(double x, double y) {
	double deltaX = x - xCenter();
	double deltaY = y - yCenter();
	setPointA(xCoordA + deltaX, yCoordA + deltaY);
	setPointB(xCoordB + deltaX, yCoordB + deltaY);
	setPointC(xCoordC + deltaX, yCoordC + deltaY);
}

void Triangle::setPointA(double x, double y) {
	xCoordA = x;
	yCoordA = y;
}

void Triangle::setPointB(double x, double y) {
	xCoordB = x;
	yCoordB = y;
}

void Triangle::setPointC(double x, double y) {
	xCoordC = x;
	yCoordC = y;
}

double Triangle::Square() {
	double p = (sideAB() + sideBC() + sideCA())/2.;
	return sqrt(p*(p-sideAB())*(p-sideBC())*(p-sideCA()));
}

double Triangle::Perimeter() {
	return sideAB()+sideBC()+sideCA();
}

double Triangle::getxCoordA() {
	return xCoordA;
}

double Triangle::getxCoordB() {
	return xCoordB;
}

double Triangle::getxCoordC() {
	return xCoordC;
}

double Triangle::getyCoordA() {
	return yCoordA;
}

double Triangle::getyCoordB() {
	return yCoordB;
}

double Triangle::getyCoordC() {
	return yCoordC;
}

double Triangle::side(double x1, double y1, double x2, double y2) {
	return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}

double Triangle::sideAB() {
	return side(xCoordA, yCoordA, xCoordB, yCoordB);
}

double Triangle::sideBC() {
	return side(xCoordB, yCoordB, xCoordC, yCoordC);
}

double Triangle::sideCA() {
	return side(xCoordC, yCoordC, xCoordA, yCoordA);
}

double Triangle::xCenter() {
	double medx = (xCoordA + xCoordB) / 2.;
	if (xCoordC < medx) {
		return (medx - xCoordC) * 2/3. + xCoordC;
	}
	else {
		return (xCoordC - medx) * 1/3. + medx;
	}
}

double Triangle::yCenter() {
	double medy = (yCoordA + yCoordB) / 2.;
	if (xCoordC < medy) {
		return (medy - yCoordC) * 2/3. + yCoordC;
	}
	else {
		return (yCoordC - medy) * 1/3. + medy;
	}
}
