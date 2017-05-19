//---------------------------------------------------------------------------

#pragma hdrstop

#include "Polygon.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

Polygons::Polygons(double xA, double yA,
				double xB, double yB,
				double xC, double yC,
				double xD, double yD,
				double xE, double yE){
	xCoordA = xA;
	xCoordB = xB;
	xCoordC = xC;
	xCoordD = xD;
	xCoordE = xE;
	yCoordA = yA;
	yCoordB = yB;
	yCoordC = yC;
	yCoordD = yD;
	yCoordE = yE;
}
double Polygons::getxCoordA() {
	return xCoordA;
}

double Polygons::getxCoordB() {
	return xCoordB;
}

double Polygons::getxCoordC() {
	return xCoordC;
}

double Polygons::getxCoordD() {
	return xCoordD;
}

double Polygons::getxCoordE() {
	return xCoordE;
}

double Polygons::getyCoordA() {
	return yCoordA;
}

double Polygons::getyCoordB() {
	return yCoordB;
}

double Polygons::getyCoordC() {
	return yCoordC;
}

double Polygons::getyCoordD() {
	return yCoordD;
}

double Polygons::getyCoordE() {
	return yCoordE;
}

double Polygons::xCenterCoord() {
	return (xCoordA + xCoordB + xCoordC + xCoordD + xCoordE) / 5.;
}

double Polygons::yCenterCoord() {
    return (yCoordA + yCoordB + yCoordC + yCoordD + yCoordE) / 5.;
}

double Polygons::Square() {
	double S = (xCoordA + xCoordB)*(yCoordB - yCoordA);
	S += (xCoordB + xCoordC)*(yCoordC - yCoordB);
	S += (xCoordC + xCoordD)*(yCoordD - yCoordC);
	S += (xCoordD + xCoordE)*(yCoordE - yCoordD);
	S += (xCoordE + xCoordA)*(yCoordA - yCoordE);
	S /= 2.;
	return S;
}

double Polygons::Perimeter() {
	double P = sqrt(pow(xCoordA, 2) + pow(yCoordA, 2));
	P += sqrt(pow(xCoordB, 2) + pow(yCoordB, 2));
	P += sqrt(pow(xCoordC, 2) + pow(yCoordC, 2));
	P += sqrt(pow(xCoordD, 2) + pow(yCoordD, 2));
	P += sqrt(pow(xCoordE, 2) + pow(yCoordE, 2));
	return P;
}

void Polygons::setCenter(double x, double y) {
	double deltaX = x - xCenterCoord();
	double deltaY = y - yCenterCoord();
	xCoordA += deltaX;
	xCoordB += deltaX;
	xCoordC += deltaX;
	xCoordD += deltaX;
	xCoordE += deltaX;
	yCoordA += deltaY;
	yCoordB += deltaY;
	yCoordC += deltaY;
	yCoordD += deltaY;
	yCoordE += deltaY;
}

void Polygons::setPointA(double x, double y) {
	xCoordA = x;
	yCoordA = y;
}

void Polygons::setPointB(double x, double y) {
	xCoordB = x;
	yCoordB = y;
}

void Polygons::setPointC(double x, double y) {
	xCoordC = x;
	yCoordC = y;
}

void Polygons::setPointD(double x, double y) {
	xCoordD = x;
	yCoordD = y;
}

void Polygons::setPointE(double x, double y) {
	xCoordE = x;
	yCoordE = y;
}
