//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <math.h>
#include "main.h"
#include "Circle.h"
#include "Polygon.h"
#include "Triangle.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
Triangle ShapeTriangle;
Circle ShapeCircle;
Polygons ShapePolygon;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SaveClick(TObject *Sender)
{
	TRect r;
	r.Left = 25;
	r.right = 700;
	r.Top = 25;
	r.Bottom = 700;
	Canvas->Brush->Color = clWhite;
	Canvas->FillRect(r);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SaveTrianglePointsClick(TObject *Sender)
{
// Set points values for object ShapeTriangle
	ShapeTriangle.setPointA(StrToFloat(xCoordA->Text),StrToFloat(yCoordA->Text));
	ShapeTriangle.setPointB(StrToFloat(xCoordB->Text),StrToFloat(yCoordB->Text));
	ShapeTriangle.setPointC(StrToFloat(xCoordC->Text),StrToFloat(yCoordC->Text));
// Set values for edit form of center's point
	xCoordCenter->Text = FloatToStr(ShapeTriangle.xCenter());
	yCoordCenter->Text = FloatToStr(ShapeTriangle.yCenter());
// Clear PaintBox
	TRect r;
	r.Left=0;
	r.right=1000;
	r.Bottom=1000;
	r.Top=0;
	PaintBox->Canvas->Brush->Color=clWhite;
	PaintBox->Canvas->FillRect(r);
// Drawing ShapeTriangle object
	PaintBox->Canvas->MoveTo(ShapeTriangle.getxCoordA(),ShapeTriangle.getyCoordA());
	PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordB(),ShapeTriangle.getyCoordB());
	PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordC(),ShapeTriangle.getyCoordC());
	PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordA(),ShapeTriangle.getyCoordA());
// Drawing center of triangle
	PaintBox->Canvas->Ellipse(ShapeTriangle.xCenter()-2,ShapeTriangle.yCenter()-2,ShapeTriangle.xCenter()+2,ShapeTriangle.yCenter()+2);
// Set info
   	LabelInfoText->Caption = "Square: " + FloatToStr(ShapeTriangle.Square()) + "\n" + "Perimeter: " + FloatToStr(ShapeTriangle.Perimeter());

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SaveCenterPointClick(TObject *Sender)
{
// Set new center coord of Triange
	ShapeTriangle.setCenter(StrToFloat(xCoordCenter->Text),StrToFloat(yCoordCenter->Text));
// Clear PaintBox
	TRect r;
	r.Left=0;
	r.right=1000;
	r.Bottom=1000;
	r.Top=0;
	PaintBox->Canvas->Brush->Color=clWhite;
	PaintBox->Canvas->FillRect(r);
// Redrawing triangle
	PaintBox->Canvas->MoveTo(ShapeTriangle.getxCoordA(),ShapeTriangle.getyCoordA());
	PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordB(),ShapeTriangle.getyCoordB());
	PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordC(),ShapeTriangle.getyCoordC());
	PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordA(),ShapeTriangle.getyCoordA());
// Drawing center of triangle
	PaintBox->Canvas->Ellipse(ShapeTriangle.xCenter()-2,ShapeTriangle.yCenter()-2,ShapeTriangle.xCenter()+2,ShapeTriangle.yCenter()+2);
// Set info
	LabelInfoText->Caption = "Square: " + FloatToStr(ShapeTriangle.Square()) + "\n" + "Perimeter: " + FloatToStr(ShapeTriangle.Perimeter());
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TimerTopTimer(TObject *Sender)
{
// Clear PaintBox
	TRect r;
	r.Left=0;
	r.right=1000;
	r.Bottom=1000;
	r.Top=0;
	PaintBox->Canvas->Brush->Color=clWhite;
	PaintBox->Canvas->FillRect(r);

	switch (TimerTop->Tag) {
		// ================
		// === Triangle ===
		// ================
		case 1:
		// Set new coords
			ShapeTriangle.setPointA(ShapeTriangle.getxCoordA(),ShapeTriangle.getyCoordA()-1);
			xCoordA->Text = FloatToStr(ShapeTriangle.getxCoordA());
			yCoordA->Text = FloatToStr(ShapeTriangle.getyCoordA());
			ShapeTriangle.setPointB(ShapeTriangle.getxCoordB(),ShapeTriangle.getyCoordB()-1);
			xCoordB->Text = FloatToStr(ShapeTriangle.getxCoordB());
			yCoordB->Text = FloatToStr(ShapeTriangle.getyCoordB());
			ShapeTriangle.setPointC(ShapeTriangle.getxCoordC(),ShapeTriangle.getyCoordC()-1);
			xCoordC->Text = FloatToStr(ShapeTriangle.getxCoordC());
			yCoordC->Text = FloatToStr(ShapeTriangle.getyCoordC());
			xCoordCenter->Text = FloatToStr(ShapeTriangle.xCenter());
			yCoordCenter->Text = FloatToStr(ShapeTriangle.yCenter());
		// Redrawing triangle
			PaintBox->Canvas->MoveTo(ShapeTriangle.getxCoordA(),ShapeTriangle.getyCoordA());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordB(),ShapeTriangle.getyCoordB());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordC(),ShapeTriangle.getyCoordC());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordA(),ShapeTriangle.getyCoordA());
		// Drawing center of triangle
			PaintBox->Canvas->Ellipse(ShapeTriangle.xCenter()-2,ShapeTriangle.yCenter()-2,ShapeTriangle.xCenter()+2,ShapeTriangle.yCenter()+2);
		break;
		// ==============
		// === Circle ===
		// ==============
		case 2:
		// Set new coords
			ShapeCircle.setCenter(ShapeCircle.getxCenter(),ShapeCircle.getyCenter()-1);
			yCoordCenterCircle->Text = FloatToStr(ShapeCircle.getyCenter());
		// Redrawing circle
			PaintBox->Canvas->Ellipse(ShapeCircle.xLeftTop(),ShapeCircle.yLeftTop(),ShapeCircle.xRightBottom(),ShapeCircle.yRightBottom());
		// Redrawing center of circle
			PaintBox->Canvas->Ellipse(ShapeCircle.getxCenter()-2, ShapeCircle.getyCenter()-2, ShapeCircle.getxCenter()+2, ShapeCircle.getyCenter()+2);
		break;
		// ===============
		// === Polygon ===
		// ===============
		case 3:
		// Set new coords
			ShapePolygon.setCenter(ShapePolygon.xCenterCoord(),ShapePolygon.yCenterCoord()-1);
		// Drawing Polygon
			PaintBox->Canvas->MoveTo(ShapePolygon.getxCoordA(),ShapePolygon.getyCoordA());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordB(),ShapePolygon.getyCoordB());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordC(),ShapePolygon.getyCoordC());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordD(),ShapePolygon.getyCoordD());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordE(),ShapePolygon.getyCoordE());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordA(),ShapePolygon.getyCoordA());
		// Drawing center of polygon
			PaintBox->Canvas->MoveTo(ShapePolygon.xCenterCoord(),ShapePolygon.yCenterCoord());
			PaintBox->Canvas->Ellipse(ShapePolygon.xCenterCoord()-2,ShapePolygon.yCenterCoord()-2,ShapePolygon.xCenterCoord()+2,ShapePolygon.yCenterCoord()+2);
		// Set "edit" of points
			xCoordPA->Text = FloatToStr(ShapePolygon.getxCoordA());
			xCoordPB->Text = FloatToStr(ShapePolygon.getxCoordB());
			xCoordPC->Text = FloatToStr(ShapePolygon.getxCoordC());
			xCoordPD->Text = FloatToStr(ShapePolygon.getxCoordD());
			xCoordPE->Text = FloatToStr(ShapePolygon.getxCoordE());
			yCoordPA->Text = FloatToStr(ShapePolygon.getyCoordA());
			yCoordPB->Text = FloatToStr(ShapePolygon.getyCoordB());
			yCoordPC->Text = FloatToStr(ShapePolygon.getyCoordC());
			yCoordPD->Text = FloatToStr(ShapePolygon.getyCoordD());
			yCoordPE->Text = FloatToStr(ShapePolygon.getyCoordE());
		// Set "edit" of center
			xCenterPolygon->Text = FloatToStr(ShapePolygon.xCenterCoord());
			yCenterPolygon->Text = FloatToStr(ShapePolygon.yCenterCoord());
		break;
		default:
			// EMPTY
		break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TimerBottomTimer(TObject *Sender)
{
// Clear PaintBox
	TRect r;
	r.Left=0;
	r.right=1000;
	r.Bottom=1000;
	r.Top=0;
	PaintBox->Canvas->Brush->Color=clWhite;
	PaintBox->Canvas->FillRect(r);

	switch (TimerBottom->Tag) {
		// ================
		// === Triangle ===
		// ================
		case 1:
		// Set new coords
			ShapeTriangle.setPointA(ShapeTriangle.getxCoordA(),ShapeTriangle.getyCoordA()+1);
			xCoordA->Text = FloatToStr(ShapeTriangle.getxCoordA());
			yCoordA->Text = FloatToStr(ShapeTriangle.getyCoordA());
			ShapeTriangle.setPointB(ShapeTriangle.getxCoordB(),ShapeTriangle.getyCoordB()+1);
			xCoordB->Text = FloatToStr(ShapeTriangle.getxCoordB());
			yCoordB->Text = FloatToStr(ShapeTriangle.getyCoordB());
			ShapeTriangle.setPointC(ShapeTriangle.getxCoordC(),ShapeTriangle.getyCoordC()+1);
			xCoordC->Text = FloatToStr(ShapeTriangle.getxCoordC());
			yCoordC->Text = FloatToStr(ShapeTriangle.getyCoordC());
			xCoordCenter->Text = FloatToStr(ShapeTriangle.xCenter());
			yCoordCenter->Text = FloatToStr(ShapeTriangle.yCenter());
		// Redrawing triangle
			PaintBox->Canvas->MoveTo(ShapeTriangle.getxCoordA(),ShapeTriangle.getyCoordA());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordB(),ShapeTriangle.getyCoordB());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordC(),ShapeTriangle.getyCoordC());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordA(),ShapeTriangle.getyCoordA());
		// Drawing center of triangle
			PaintBox->Canvas->Ellipse(ShapeTriangle.xCenter()-2,ShapeTriangle.yCenter()-2,ShapeTriangle.xCenter()+2,ShapeTriangle.yCenter()+2);
		break;
		// ==============
		// === Circle ===
		// ==============
		case 2:
		// Set new coords
			ShapeCircle.setCenter(ShapeCircle.getxCenter(),ShapeCircle.getyCenter()+1);
			yCoordCenterCircle->Text = FloatToStr(ShapeCircle.getyCenter());
		// Redrawing circle
			PaintBox->Canvas->Ellipse(ShapeCircle.xLeftTop(),ShapeCircle.yLeftTop(),ShapeCircle.xRightBottom(),ShapeCircle.yRightBottom());
		// Redrawing center of circle
			PaintBox->Canvas->Ellipse(ShapeCircle.getxCenter()-2, ShapeCircle.getyCenter()-2, ShapeCircle.getxCenter()+2, ShapeCircle.getyCenter()+2);
		break;
		// ===============
		// === Polygon ===
		// ===============
		case 3:
        // Set new coords
			ShapePolygon.setCenter(ShapePolygon.xCenterCoord(),ShapePolygon.yCenterCoord()+1);
		// Drawing Polygon
			PaintBox->Canvas->MoveTo(ShapePolygon.getxCoordA(),ShapePolygon.getyCoordA());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordB(),ShapePolygon.getyCoordB());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordC(),ShapePolygon.getyCoordC());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordD(),ShapePolygon.getyCoordD());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordE(),ShapePolygon.getyCoordE());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordA(),ShapePolygon.getyCoordA());
		// Drawing center of polygon
			PaintBox->Canvas->MoveTo(ShapePolygon.xCenterCoord(),ShapePolygon.yCenterCoord());
			PaintBox->Canvas->Ellipse(ShapePolygon.xCenterCoord()-2,ShapePolygon.yCenterCoord()-2,ShapePolygon.xCenterCoord()+2,ShapePolygon.yCenterCoord()+2);
		// Set "edit" of points
			xCoordPA->Text = FloatToStr(ShapePolygon.getxCoordA());
			xCoordPB->Text = FloatToStr(ShapePolygon.getxCoordB());
			xCoordPC->Text = FloatToStr(ShapePolygon.getxCoordC());
			xCoordPD->Text = FloatToStr(ShapePolygon.getxCoordD());
			xCoordPE->Text = FloatToStr(ShapePolygon.getxCoordE());
			yCoordPA->Text = FloatToStr(ShapePolygon.getyCoordA());
			yCoordPB->Text = FloatToStr(ShapePolygon.getyCoordB());
			yCoordPC->Text = FloatToStr(ShapePolygon.getyCoordC());
			yCoordPD->Text = FloatToStr(ShapePolygon.getyCoordD());
			yCoordPE->Text = FloatToStr(ShapePolygon.getyCoordE());
		// Set "edit" of center
			xCenterPolygon->Text = FloatToStr(ShapePolygon.xCenterCoord());
			yCenterPolygon->Text = FloatToStr(ShapePolygon.yCenterCoord());
		break;
		default:
			// EMPTY
		break;
	}
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::TimerRightTimer(TObject *Sender)
{
	// Clear PaintBox
	TRect r;
	r.Left=0;
	r.right=1000;
	r.Bottom=1000;
	r.Top=0;
	PaintBox->Canvas->Brush->Color=clWhite;
	PaintBox->Canvas->FillRect(r);

	switch (TimerRight->Tag) {
		// ================
		// === Triangle ===
		// ================
		case 1:
		// Set new coords
			ShapeTriangle.setPointA(ShapeTriangle.getxCoordA()+1,ShapeTriangle.getyCoordA());
			xCoordA->Text = FloatToStr(ShapeTriangle.getxCoordA());
			yCoordA->Text = FloatToStr(ShapeTriangle.getyCoordA());
			ShapeTriangle.setPointB(ShapeTriangle.getxCoordB()+1,ShapeTriangle.getyCoordB());			xCoordB->Text = FloatToStr(ShapeTriangle.getxCoordB());
			yCoordB->Text = FloatToStr(ShapeTriangle.getyCoordB());
			ShapeTriangle.setPointC(ShapeTriangle.getxCoordC()+1,ShapeTriangle.getyCoordC());
			xCoordC->Text = FloatToStr(ShapeTriangle.getxCoordC());
			yCoordC->Text = FloatToStr(ShapeTriangle.getyCoordC());
			xCoordCenter->Text = FloatToStr(ShapeTriangle.xCenter());
			yCoordCenter->Text = FloatToStr(ShapeTriangle.yCenter());
		// Redrawing triangle
			PaintBox->Canvas->MoveTo(ShapeTriangle.getxCoordA(),ShapeTriangle.getyCoordA());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordB(),ShapeTriangle.getyCoordB());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordC(),ShapeTriangle.getyCoordC());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordA(),ShapeTriangle.getyCoordA());
		// Drawing center of triangle
			PaintBox->Canvas->Ellipse(ShapeTriangle.xCenter()-2,ShapeTriangle.yCenter()-2,ShapeTriangle.xCenter()+2,ShapeTriangle.yCenter()+2);
		break;
		// ==============
		// === Circle ===
		// ==============
		case 2:
        // Set new coords
			ShapeCircle.setCenter(ShapeCircle.getxCenter()+1,ShapeCircle.getyCenter());
			xCoordCenterCircle->Text = FloatToStr(ShapeCircle.getxCenter());
		// Redrawing circle
			PaintBox->Canvas->Ellipse(ShapeCircle.xLeftTop(),ShapeCircle.yLeftTop(),ShapeCircle.xRightBottom(),ShapeCircle.yRightBottom());
		// Redrawing center of circle
			PaintBox->Canvas->Ellipse(ShapeCircle.getxCenter()-2, ShapeCircle.getyCenter()-2, ShapeCircle.getxCenter()+2, ShapeCircle.getyCenter()+2);
		break;
		// ===============
		// === Polygon ===
		// ===============
		case 3:
		// Set new coords
			ShapePolygon.setCenter(ShapePolygon.xCenterCoord()+1,ShapePolygon.yCenterCoord());
		// Drawing Polygon
			PaintBox->Canvas->MoveTo(ShapePolygon.getxCoordA(),ShapePolygon.getyCoordA());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordB(),ShapePolygon.getyCoordB());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordC(),ShapePolygon.getyCoordC());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordD(),ShapePolygon.getyCoordD());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordE(),ShapePolygon.getyCoordE());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordA(),ShapePolygon.getyCoordA());
		// Drawing center of polygon
			PaintBox->Canvas->MoveTo(ShapePolygon.xCenterCoord(),ShapePolygon.yCenterCoord());
			PaintBox->Canvas->Ellipse(ShapePolygon.xCenterCoord()-2,ShapePolygon.yCenterCoord()-2,ShapePolygon.xCenterCoord()+2,ShapePolygon.yCenterCoord()+2);
		// Set "edit" of points
			xCoordPA->Text = FloatToStr(ShapePolygon.getxCoordA());
			xCoordPB->Text = FloatToStr(ShapePolygon.getxCoordB());
			xCoordPC->Text = FloatToStr(ShapePolygon.getxCoordC());
			xCoordPD->Text = FloatToStr(ShapePolygon.getxCoordD());
			xCoordPE->Text = FloatToStr(ShapePolygon.getxCoordE());
			yCoordPA->Text = FloatToStr(ShapePolygon.getyCoordA());
			yCoordPB->Text = FloatToStr(ShapePolygon.getyCoordB());
			yCoordPC->Text = FloatToStr(ShapePolygon.getyCoordC());
			yCoordPD->Text = FloatToStr(ShapePolygon.getyCoordD());
			yCoordPE->Text = FloatToStr(ShapePolygon.getyCoordE());
		// Set "edit" of center
			xCenterPolygon->Text = FloatToStr(ShapePolygon.xCenterCoord());
			yCenterPolygon->Text = FloatToStr(ShapePolygon.yCenterCoord());
		break;
		default:
			// EMPTY
		break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TimerLeftTimer(TObject *Sender)
{
	// Clear PaintBox
	TRect r;
	r.Left=0;
	r.right=1000;
	r.Bottom=1000;
	r.Top=0;
	PaintBox->Canvas->Brush->Color=clWhite;
	PaintBox->Canvas->FillRect(r);

	switch (TimerLeft->Tag) {
		// ================
		// === Triangle ===
		// ================
		case 1:
		// Set new coords
			ShapeTriangle.setPointA(ShapeTriangle.getxCoordA()-1,ShapeTriangle.getyCoordA());
			xCoordA->Text = FloatToStr(ShapeTriangle.getxCoordA());
			yCoordA->Text = FloatToStr(ShapeTriangle.getyCoordA());
			ShapeTriangle.setPointB(ShapeTriangle.getxCoordB()-1,ShapeTriangle.getyCoordB());
			xCoordB->Text = FloatToStr(ShapeTriangle.getxCoordB());
			yCoordB->Text = FloatToStr(ShapeTriangle.getyCoordB());
			ShapeTriangle.setPointC(ShapeTriangle.getxCoordC()-1,ShapeTriangle.getyCoordC());
			xCoordC->Text = FloatToStr(ShapeTriangle.getxCoordC());
			yCoordC->Text = FloatToStr(ShapeTriangle.getyCoordC());
			xCoordCenter->Text = FloatToStr(ShapeTriangle.xCenter());
			yCoordCenter->Text = FloatToStr(ShapeTriangle.yCenter());
		// Redrawing triangle
			PaintBox->Canvas->MoveTo(ShapeTriangle.getxCoordA(),ShapeTriangle.getyCoordA());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordB(),ShapeTriangle.getyCoordB());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordC(),ShapeTriangle.getyCoordC());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordA(),ShapeTriangle.getyCoordA());
		// Drawing center of triangle
			PaintBox->Canvas->Ellipse(ShapeTriangle.xCenter()-2,ShapeTriangle.yCenter()-2,ShapeTriangle.xCenter()+2,ShapeTriangle.yCenter()+2);
		break;
		// ==============
		// === Circle ===
		// ==============
		case 2:
        // Set new coords
			ShapeCircle.setCenter(ShapeCircle.getxCenter()-1,ShapeCircle.getyCenter());
            xCoordCenterCircle->Text = FloatToStr(ShapeCircle.getxCenter());
		// Redrawing circle
			PaintBox->Canvas->Ellipse(ShapeCircle.xLeftTop(),ShapeCircle.yLeftTop(),ShapeCircle.xRightBottom(),ShapeCircle.yRightBottom());
		// Redrawing center of circle
			PaintBox->Canvas->Ellipse(ShapeCircle.getxCenter()-2, ShapeCircle.getyCenter()-2, ShapeCircle.getxCenter()+2, ShapeCircle.getyCenter()+2);
		break;
		// ===============
		// === Polygon ===
		// ===============
		case 3:
		// Set new coords
			ShapePolygon.setCenter(ShapePolygon.xCenterCoord()-1,ShapePolygon.yCenterCoord());
		// Drawing Polygon
			PaintBox->Canvas->MoveTo(ShapePolygon.getxCoordA(),ShapePolygon.getyCoordA());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordB(),ShapePolygon.getyCoordB());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordC(),ShapePolygon.getyCoordC());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordD(),ShapePolygon.getyCoordD());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordE(),ShapePolygon.getyCoordE());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordA(),ShapePolygon.getyCoordA());
		// Drawing center of polygon
			PaintBox->Canvas->MoveTo(ShapePolygon.xCenterCoord(),ShapePolygon.yCenterCoord());
			PaintBox->Canvas->Ellipse(ShapePolygon.xCenterCoord()-2,ShapePolygon.yCenterCoord()-2,ShapePolygon.xCenterCoord()+2,ShapePolygon.yCenterCoord()+2);
		// Set "edit" of points
			xCoordPA->Text = FloatToStr(ShapePolygon.getxCoordA());
			xCoordPB->Text = FloatToStr(ShapePolygon.getxCoordB());
			xCoordPC->Text = FloatToStr(ShapePolygon.getxCoordC());
			xCoordPD->Text = FloatToStr(ShapePolygon.getxCoordD());
			xCoordPE->Text = FloatToStr(ShapePolygon.getxCoordE());
			yCoordPA->Text = FloatToStr(ShapePolygon.getyCoordA());
			yCoordPB->Text = FloatToStr(ShapePolygon.getyCoordB());
			yCoordPC->Text = FloatToStr(ShapePolygon.getyCoordC());
			yCoordPD->Text = FloatToStr(ShapePolygon.getyCoordD());
			yCoordPE->Text = FloatToStr(ShapePolygon.getyCoordE());
		// Set "edit" of center
			xCenterPolygon->Text = FloatToStr(ShapePolygon.xCenterCoord());
			yCenterPolygon->Text = FloatToStr(ShapePolygon.yCenterCoord());
		break;
		default:
			// EMPTY
		break;
	}
}
//---------------------------------------------------------------------------
double xRotateCoord(double x,double y, double m, double n, int i) {
	double a = i*M_PI/180.0;
	return x*cos(a) - sin(a)*y - m*(cos(a) - 1) + n*sin(a);
}

double yRotateCoord(double x,double y, double m, double n, int i) {
	double a = i*M_PI/180.0;
	return x*sin(a) + cos(a)*y - n*(cos(a) - 1) - m*sin(a);
}

void __fastcall TMainForm::TimerRotateRightTimer(TObject *Sender)
{
	// Clear PaintBox
	TRect r;
	r.Left=0;
	r.right=1000;
	r.Bottom=1000;
	r.Top=0;
	PaintBox->Canvas->Brush->Color=clWhite;
	PaintBox->Canvas->FillRect(r);
	// define x,y,m,n
	double x = 0, y = 0, m = 0, n = 0;
	switch (TimerRotateRight->Tag) {
		// ================
		// === Triangle ===
		// ================
		case 1:
		// Set new coords
			x = ShapeTriangle.getxCoordA();
			y = ShapeTriangle.getyCoordA();
			m = ShapeTriangle.xCenter();
			n = ShapeTriangle.yCenter();
			ShapeTriangle.setPointA(xRotateCoord(x,y,m,n,1),yRotateCoord(x,y,m,n,1));
			xCoordA->Text = FloatToStr(x);
			yCoordA->Text = FloatToStr(y);

			x = ShapeTriangle.getxCoordB();
			y = ShapeTriangle.getyCoordB();
			ShapeTriangle.setPointB(xRotateCoord(x,y,m,n,1),yRotateCoord(x,y,m,n,1));
			xCoordB->Text = FloatToStr(x);
			yCoordB->Text = FloatToStr(y);

			x = ShapeTriangle.getxCoordC();
			y = ShapeTriangle.getyCoordC();
			ShapeTriangle.setPointC(xRotateCoord(x,y,m,n,1),yRotateCoord(x,y,m,n,1));
			xCoordC->Text = FloatToStr(x);
			yCoordC->Text = FloatToStr(y);

			xCoordCenter->Text = FloatToStr(m);
			yCoordCenter->Text = FloatToStr(n);
		// Redrawing triangle
			PaintBox->Canvas->MoveTo(ShapeTriangle.getxCoordA(),ShapeTriangle.getyCoordA());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordB(),ShapeTriangle.getyCoordB());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordC(),ShapeTriangle.getyCoordC());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordA(),ShapeTriangle.getyCoordA());
		// Drawing center of triangle
			PaintBox->Canvas->Ellipse(ShapeTriangle.xCenter()-2,ShapeTriangle.yCenter()-2,ShapeTriangle.xCenter()+2,ShapeTriangle.yCenter()+2);
		break;
		// ==============
		// === Circle ===
		// ==============
		case 2:
		// ======EMPTY=======
		break;
		// ===============
		// === Polygon ===
		// ===============
		case 3:
		// Set new coords
			x = ShapePolygon.getxCoordA();
			y = ShapePolygon.getyCoordA();
			m = ShapePolygon.xCenterCoord();
			n = ShapePolygon.yCenterCoord();
			ShapePolygon.setPointA(xRotateCoord(x,y,m,n,1),yRotateCoord(x,y,m,n,1));
			xCoordPA->Text = FloatToStr(x);
			yCoordPA->Text = FloatToStr(y);

			x = ShapePolygon.getxCoordB();
			y = ShapePolygon.getyCoordB();
			ShapePolygon.setPointB(xRotateCoord(x,y,m,n,1),yRotateCoord(x,y,m,n,1));
			xCoordPB->Text = FloatToStr(x);
			yCoordPB->Text = FloatToStr(y);

			x = ShapePolygon.getxCoordC();
			y = ShapePolygon.getyCoordC();
			ShapePolygon.setPointC(xRotateCoord(x,y,m,n,1),yRotateCoord(x,y,m,n,1));
			xCoordPC->Text = FloatToStr(x);
			yCoordPC->Text = FloatToStr(y);

			x = ShapePolygon.getxCoordD();
			y = ShapePolygon.getyCoordD();
			ShapePolygon.setPointD(xRotateCoord(x,y,m,n,1),yRotateCoord(x,y,m,n,1));
			xCoordPD->Text = FloatToStr(x);
			yCoordPD->Text = FloatToStr(y);

			x = ShapePolygon.getxCoordE();
			y = ShapePolygon.getyCoordE();
			ShapePolygon.setPointE(xRotateCoord(x,y,m,n,1),yRotateCoord(x,y,m,n,1));
			xCoordPE->Text = FloatToStr(x);
			yCoordPE->Text = FloatToStr(y);
		// Drawing Polygon
			PaintBox->Canvas->MoveTo(ShapePolygon.getxCoordA(),ShapePolygon.getyCoordA());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordB(),ShapePolygon.getyCoordB());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordC(),ShapePolygon.getyCoordC());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordD(),ShapePolygon.getyCoordD());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordE(),ShapePolygon.getyCoordE());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordA(),ShapePolygon.getyCoordA());
		// Drawing center of polygon
			PaintBox->Canvas->MoveTo(ShapePolygon.xCenterCoord(),ShapePolygon.yCenterCoord());
			PaintBox->Canvas->Ellipse(ShapePolygon.xCenterCoord()-2,ShapePolygon.yCenterCoord()-2,ShapePolygon.xCenterCoord()+2,ShapePolygon.yCenterCoord()+2);
		break;
		default:
		// EMPTY
		break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TimerRotateLeftTimer(TObject *Sender)
{
// Clear PaintBox
	TRect r;
	r.Left=0;
	r.right=1000;
	r.Bottom=1000;
	r.Top=0;
	PaintBox->Canvas->Brush->Color=clWhite;
	PaintBox->Canvas->FillRect(r);
// define x,y,m,n
	double x = 0, y = 0, m = 0, n = 0;
	switch (TimerRotateLeft->Tag) {
		// ================
		// === Triangle ===
		// ================
		case 1:
		// Set new coords
			x = ShapeTriangle.getxCoordA();
			y = ShapeTriangle.getyCoordA();
			m = ShapeTriangle.xCenter();
			n = ShapeTriangle.yCenter();
			ShapeTriangle.setPointA(xRotateCoord(x,y,m,n,-1),yRotateCoord(x,y,m,n,-1));
			xCoordA->Text = FloatToStr(x);
			yCoordA->Text = FloatToStr(y);

			x = ShapeTriangle.getxCoordB();
			y = ShapeTriangle.getyCoordB();
			ShapeTriangle.setPointB(xRotateCoord(x,y,m,n,-1),yRotateCoord(x,y,m,n,-1));
			xCoordB->Text = FloatToStr(x);
			yCoordB->Text = FloatToStr(y);

			x = ShapeTriangle.getxCoordC();
			y = ShapeTriangle.getyCoordC();
			ShapeTriangle.setPointC(xRotateCoord(x,y,m,n,-1),yRotateCoord(x,y,m,n,-1));
			xCoordC->Text = FloatToStr(x);
			yCoordC->Text = FloatToStr(y);

			xCoordCenter->Text = FloatToStr(m);
			yCoordCenter->Text = FloatToStr(n);
		// Redrawing triangle
			PaintBox->Canvas->MoveTo(ShapeTriangle.getxCoordA(),ShapeTriangle.getyCoordA());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordB(),ShapeTriangle.getyCoordB());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordC(),ShapeTriangle.getyCoordC());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordA(),ShapeTriangle.getyCoordA());
		// Drawing center of triangle
			PaintBox->Canvas->Ellipse(ShapeTriangle.xCenter()-2,ShapeTriangle.yCenter()-2,ShapeTriangle.xCenter()+2,ShapeTriangle.yCenter()+2);
		break;
		// ==============
		// === Circle ===
		// ==============
		case 2:
		// ======EMPTY=======
		break;
		// ===============
		// === Polygon ===
		// ===============
		case 3:
		// Set new coords
			x = ShapePolygon.getxCoordA();
			y = ShapePolygon.getyCoordA();
			m = ShapePolygon.xCenterCoord();
			n = ShapePolygon.yCenterCoord();
			ShapePolygon.setPointA(xRotateCoord(x,y,m,n,-1),yRotateCoord(x,y,m,n,-1));
			xCoordPA->Text = FloatToStr(x);
			yCoordPA->Text = FloatToStr(y);

			x = ShapePolygon.getxCoordB();
			y = ShapePolygon.getyCoordB();
			ShapePolygon.setPointB(xRotateCoord(x,y,m,n,-1),yRotateCoord(x,y,m,n,-1));
			xCoordPB->Text = FloatToStr(x);
			yCoordPB->Text = FloatToStr(y);

			x = ShapePolygon.getxCoordC();
			y = ShapePolygon.getyCoordC();
			ShapePolygon.setPointC(xRotateCoord(x,y,m,n,-1),yRotateCoord(x,y,m,n,-1));
			xCoordPC->Text = FloatToStr(x);
			yCoordPC->Text = FloatToStr(y);

			x = ShapePolygon.getxCoordD();
			y = ShapePolygon.getyCoordD();
			ShapePolygon.setPointD(xRotateCoord(x,y,m,n,-1),yRotateCoord(x,y,m,n,-1));
			xCoordPD->Text = FloatToStr(x);
			yCoordPD->Text = FloatToStr(y);

			x = ShapePolygon.getxCoordE();
			y = ShapePolygon.getyCoordE();
			ShapePolygon.setPointE(xRotateCoord(x,y,m,n,-1),yRotateCoord(x,y,m,n,-1));
			xCoordPE->Text = FloatToStr(x);
			yCoordPE->Text = FloatToStr(y);
		// Drawing Polygon
			PaintBox->Canvas->MoveTo(ShapePolygon.getxCoordA(),ShapePolygon.getyCoordA());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordB(),ShapePolygon.getyCoordB());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordC(),ShapePolygon.getyCoordC());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordD(),ShapePolygon.getyCoordD());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordE(),ShapePolygon.getyCoordE());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordA(),ShapePolygon.getyCoordA());
		// Drawing center of polygon
			PaintBox->Canvas->MoveTo(ShapePolygon.xCenterCoord(),ShapePolygon.yCenterCoord());
			PaintBox->Canvas->Ellipse(ShapePolygon.xCenterCoord()-2,ShapePolygon.yCenterCoord()-2,ShapePolygon.xCenterCoord()+2,ShapePolygon.yCenterCoord()+2);
		break;
		default:
		// EMPTY
		break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::topClick(TObject *Sender)
{
	if (ComboBox->Text == "Triangle") {
		TimerTop->Tag = 1;
	}
	else if (ComboBox->Text == "Circle") {
		TimerTop->Tag = 2;
	}
	else if (ComboBox->Text == "Polygon") {
		TimerTop->Tag = 3;
	}
    bottom->Enabled = false;
	TimerTop->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::bottomClick(TObject *Sender)
{
	if (ComboBox->Text == "Triangle") {
		TimerBottom->Tag = 1;
	}
	else if (ComboBox->Text == "Circle") {
		TimerBottom->Tag = 2;
	}
	else if (ComboBox->Text == "Polygon") {
		TimerBottom->Tag = 3;
	}
	top->Enabled = false;
	TimerBottom->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::leftClick(TObject *Sender)
{
	if (ComboBox->Text == "Triangle") {
		TimerLeft->Tag = 1;
	}
	else if (ComboBox->Text == "Circle") {
		TimerLeft->Tag = 2;
	}
	else if (ComboBox->Text == "Polygon") {
		TimerLeft->Tag = 3;
	}
	right->Enabled = false;
	TimerLeft->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::rightClick(TObject *Sender)
{
    if (ComboBox->Text == "Triangle") {
		TimerRight->Tag = 1;
	}
	else if (ComboBox->Text == "Circle") {
		TimerRight->Tag = 2;
	}
	else if (ComboBox->Text == "Polygon") {
		TimerRight->Tag = 3;
	}
	left->Enabled = false;
	TimerRight->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::stopClick(TObject *Sender)
{
	// Disable TTimer
	TimerTop->Enabled = false;
	TimerBottom->Enabled = false;
	TimerLeft->Enabled = false;
	TimerRight->Enabled = false;
	TimerRotateLeft->Enabled = false;
	TimerRotateRight->Enabled = false;
	TimerSizeL->Enabled = false;
	TimerSizeS->Enabled = false;
	// Activate all deactivated buttons
	top->Enabled = true;
	bottom->Enabled = true;
	left->Enabled = true;
	right->Enabled = true;
	sizeS->Enabled = true;
	sizeL->Enabled = true;
	if(ComboBox->Text != "Circle"){
		rotateLeft->Enabled = true;
		rotateRight->Enabled = true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::rotateRightClick(TObject *Sender)
{
	if (ComboBox->Text == "Triangle") {
		TimerRotateRight->Tag = 1;
	}
	else if (ComboBox->Text == "Circle") {
		TimerRotateRight->Tag = 2;
	}
	else if (ComboBox->Text == "Polygon") {
		TimerRotateRight->Tag = 3;
	}
	rotateLeft->Enabled = false;
	TimerRotateRight->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::rotateLeftClick(TObject *Sender)
{
	if (ComboBox->Text == "Triangle") {
		TimerRotateLeft->Tag = 1;
	}
	else if (ComboBox->Text == "Circle") {
		TimerRotateLeft->Tag = 2;
	}
	else if (ComboBox->Text == "Polygon") {
		TimerRotateLeft->Tag = 3;
	}
	rotateRight->Enabled = false;
	TimerRotateLeft->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ComboBoxSelect(TObject *Sender)
{
	if (ComboBox->Text == "Triangle") {
		PanelTriangleCenter->Visible = true;
		PanelTrianglePoints->Visible = true;
		PanelCircleRadius->Visible = false;
		PanelCircleCenter->Visible = false;
		PanelAction->Visible = true;
		rotateLeft->Enabled = true;
		rotateRight->Enabled = true;
		PanelPolygonPoints->Visible = false;
		PanelPolygonCenter->Visible = false;
	}
	else if (ComboBox->Text == "Circle") {
        PanelTriangleCenter->Visible = false;
		PanelTrianglePoints->Visible = false;
		PanelCircleRadius->Visible = true;
		PanelCircleCenter->Visible = true;
		PanelAction->Visible = true;
		rotateLeft->Enabled = false;
		rotateRight->Enabled = false;
		PanelPolygonPoints->Visible = false;
		PanelPolygonCenter->Visible = false;
	}
	else if (ComboBox->Text == "Polygon") {
        PanelTriangleCenter->Visible = false;
		PanelTrianglePoints->Visible = false;
		PanelCircleRadius->Visible = false;
		PanelCircleCenter->Visible = false;
		PanelAction->Visible = true;
		rotateLeft->Enabled = true;
		rotateRight->Enabled = true;
		PanelPolygonPoints->Visible = true;
		PanelPolygonCenter->Visible = true;
	}
	else {
		PanelTriangleCenter->Visible = false;
		PanelTrianglePoints->Visible = false;
		PanelCircleRadius->Visible = false;
		PanelCircleCenter->Visible = false;
		PanelAction->Visible = false;
		rotateLeft->Enabled = false;
		rotateRight->Enabled = false;
		PanelPolygonPoints->Visible = false;
		PanelPolygonCenter->Visible = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::saveRadiusClick(TObject *Sender)
{
// Clear PaintBox
	TRect r;
	r.Left = 0;
	r.right = 1000;
	r.Bottom = 1000;
	r.Top = 0;
	PaintBox->Canvas->Brush->Color=clWhite;
	PaintBox->Canvas->FillRect(r);
//  Set the radius of circle
	ShapeCircle.setRadius(StrToFloat(circleRadius->Text));
// Drawing circle
	PaintBox->Canvas->Ellipse(ShapeCircle.xLeftTop(),ShapeCircle.yLeftTop(),ShapeCircle.xRightBottom(),ShapeCircle.yRightBottom());
// Drawing center of circle
	PaintBox->Canvas->Ellipse(ShapeCircle.getxCenter()-2, ShapeCircle.getyCenter()-2, ShapeCircle.getxCenter()+2, ShapeCircle.getyCenter()+2);
// Set info
	LabelInfoText->Caption = "Square: " + FloatToStr(ShapeCircle.Square()) + "\n" + "Perimeter: " + FloatToStr(ShapeCircle.Perimeter());
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SaveCenterCircleClick(TObject *Sender)
{
// Clear PaintBox
	TRect r;
	r.Left = 0;
	r.right = 1000;
	r.Bottom = 1000;
	r.Top = 0;
	PaintBox->Canvas->Brush->Color=clWhite;
	PaintBox->Canvas->FillRect(r);
// Set center of circle
	ShapeCircle.setCenter(StrToFloat(xCoordCenterCircle->Text),StrToFloat(yCoordCenterCircle->Text));
// Drawing circle
	PaintBox->Canvas->Ellipse(ShapeCircle.xLeftTop(),ShapeCircle.yLeftTop(),ShapeCircle.xRightBottom(),ShapeCircle.yRightBottom());
// Drawing center of circle
	PaintBox->Canvas->Ellipse(ShapeCircle.getxCenter()-2, ShapeCircle.getyCenter()-2, ShapeCircle.getxCenter()+2, ShapeCircle.getyCenter()+2);
// Set info
	LabelInfoText->Caption = "Square: " + FloatToStr(ShapeCircle.Square()) + "\n" + "Perimeter: " + FloatToStr(ShapeCircle.Perimeter());
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TimerSizeLTimer(TObject *Sender)
{
// Clear PaintBox
	TRect r;
	r.Left = 0;
	r.right = 1000;
	r.Bottom = 1000;
	r.Top = 0;
	PaintBox->Canvas->Brush->Color=clWhite;
	PaintBox->Canvas->FillRect(r);

    float m = 0, n = 0;
	switch(TimerSizeL->Tag) {
	// ================
	// === Triangle ===
	// ================
		case 1:
        // Save old center coords
			m = ShapeTriangle.xCenter();
			n = ShapeTriangle.yCenter();
		// Set new center and decrease size
			ShapeTriangle.setCenter(0,0);
			ShapeTriangle.setPointA(ShapeTriangle.getxCoordA()*1.02,ShapeTriangle.getyCoordA()*1.02);
			ShapeTriangle.setPointB(ShapeTriangle.getxCoordB()*1.02,ShapeTriangle.getyCoordB()*1.02);
			ShapeTriangle.setPointC(ShapeTriangle.getxCoordC()*1.02,ShapeTriangle.getyCoordC()*1.02);
		// Return old center
			ShapeTriangle.setCenter(m,n);
		// Redrawing triangle
			PaintBox->Canvas->MoveTo(ShapeTriangle.getxCoordA(),ShapeTriangle.getyCoordA());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordB(),ShapeTriangle.getyCoordB());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordC(),ShapeTriangle.getyCoordC());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordA(),ShapeTriangle.getyCoordA());
		// Drawing center of triangle
			PaintBox->Canvas->Ellipse(ShapeTriangle.xCenter()-2,ShapeTriangle.yCenter()-2,ShapeTriangle.xCenter()+2,ShapeTriangle.yCenter()+2);
		// Set info
			LabelInfoText->Caption = "Square: " + FloatToStr(ShapeTriangle.Square()) + "\n" + "Perimeter: " + FloatToStr(ShapeTriangle.Perimeter());
		break;
	// ==============
	// === Circle ===
	// ==============
		case 2:
		if(ShapeCircle.getRadius() > 400) break;
		// Set new radius
			ShapeCircle.setRadius(ShapeCircle.getRadius()+0.5);
            circleRadius->Text = FloatToStr(ShapeCircle.getRadius());
		// Redrawing circle
			PaintBox->Canvas->Ellipse(ShapeCircle.xLeftTop(),ShapeCircle.yLeftTop(),ShapeCircle.xRightBottom(),ShapeCircle.yRightBottom());
		// Redrawing center of circle
			PaintBox->Canvas->Ellipse(ShapeCircle.getxCenter()-2, ShapeCircle.getyCenter()-2, ShapeCircle.getxCenter()+2, ShapeCircle.getyCenter()+2);
        // Set info
			LabelInfoText->Caption = "Square: " + FloatToStr(ShapeCircle.Square()) + "\n" + "Perimeter: " + FloatToStr(ShapeCircle.Perimeter());
		break;
	// ===============
	// === Polygon ===
	// ===============
		case 3:
        // Save old center coords
			m = ShapePolygon.xCenterCoord();
			n = ShapePolygon.yCenterCoord();
		// Set new center and decrease size
			ShapePolygon.setCenter(0,0);
			ShapePolygon.setPointA(ShapePolygon.getxCoordA()*1.02,ShapePolygon.getyCoordA()*1.02);
			ShapePolygon.setPointB(ShapePolygon.getxCoordB()*1.02,ShapePolygon.getyCoordB()*1.02);
			ShapePolygon.setPointC(ShapePolygon.getxCoordC()*1.02,ShapePolygon.getyCoordC()*1.02);
			ShapePolygon.setPointD(ShapePolygon.getxCoordD()*1.02,ShapePolygon.getyCoordD()*1.02);
			ShapePolygon.setPointE(ShapePolygon.getxCoordE()*1.02,ShapePolygon.getyCoordE()*1.02);
		// Return old center
			ShapePolygon.setCenter(m,n);
		// Set "edit" of points
			xCoordPA->Text = FloatToStr(ShapePolygon.getxCoordA());
			xCoordPB->Text = FloatToStr(ShapePolygon.getxCoordB());
			xCoordPC->Text = FloatToStr(ShapePolygon.getxCoordC());
			xCoordPD->Text = FloatToStr(ShapePolygon.getxCoordD());
			xCoordPE->Text = FloatToStr(ShapePolygon.getxCoordE());
			yCoordPA->Text = FloatToStr(ShapePolygon.getyCoordA());
			yCoordPB->Text = FloatToStr(ShapePolygon.getyCoordB());
			yCoordPC->Text = FloatToStr(ShapePolygon.getyCoordC());
			yCoordPD->Text = FloatToStr(ShapePolygon.getyCoordD());
			yCoordPE->Text = FloatToStr(ShapePolygon.getyCoordE());
		// Drawing Polygon
			PaintBox->Canvas->MoveTo(ShapePolygon.getxCoordA(),ShapePolygon.getyCoordA());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordB(),ShapePolygon.getyCoordB());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordC(),ShapePolygon.getyCoordC());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordD(),ShapePolygon.getyCoordD());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordE(),ShapePolygon.getyCoordE());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordA(),ShapePolygon.getyCoordA());
		// Drawing center of polygon
			PaintBox->Canvas->MoveTo(ShapePolygon.xCenterCoord(),ShapePolygon.yCenterCoord());
			PaintBox->Canvas->Ellipse(ShapePolygon.xCenterCoord()-2,ShapePolygon.yCenterCoord()-2,ShapePolygon.xCenterCoord()+2,ShapePolygon.yCenterCoord()+2);
		// Set info
			LabelInfoText->Caption = "Square: " + FloatToStr(ShapePolygon.Square()) + "\nPerimeter: " + FloatToStr(ShapePolygon.Perimeter());
		break;
		default:
		break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TimerSizeSTimer(TObject *Sender)
{
	// Clear PaintBox
	TRect r;
	r.Left = 0;
	r.right = 1000;
	r.Bottom = 1000;
	r.Top = 0;
	PaintBox->Canvas->Brush->Color=clWhite;
	PaintBox->Canvas->FillRect(r);

	float m = 0, n = 0;
	switch(TimerSizeS->Tag) {
	// ================
	// === Triangle ===
	// ================
		case 1:
		// Save old center coords
			m = ShapeTriangle.xCenter();
			n = ShapeTriangle.yCenter();
		// Set new center and decrease size
			ShapeTriangle.setCenter(0,0);
			ShapeTriangle.setPointA(ShapeTriangle.getxCoordA()*0.98,ShapeTriangle.getyCoordA()*0.98);
			ShapeTriangle.setPointB(ShapeTriangle.getxCoordB()*0.98,ShapeTriangle.getyCoordB()*0.98);
			ShapeTriangle.setPointC(ShapeTriangle.getxCoordC()*0.98,ShapeTriangle.getyCoordC()*0.98);
		// Return old center
			ShapeTriangle.setCenter(m,n);
		// Redrawing triangle
			PaintBox->Canvas->MoveTo(ShapeTriangle.getxCoordA(),ShapeTriangle.getyCoordA());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordB(),ShapeTriangle.getyCoordB());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordC(),ShapeTriangle.getyCoordC());
			PaintBox->Canvas->LineTo(ShapeTriangle.getxCoordA(),ShapeTriangle.getyCoordA());
		// Drawing center of triangle
			PaintBox->Canvas->Ellipse(ShapeTriangle.xCenter()-2,ShapeTriangle.yCenter()-2,ShapeTriangle.xCenter()+2,ShapeTriangle.yCenter()+2);
		// Set info
			LabelInfoText->Caption = "Square: " + FloatToStr(ShapeTriangle.Square()) + "\n" + "Perimeter: " + FloatToStr(ShapeTriangle.Perimeter());
		break;
	// ==============
	// === Circle ===
	// ==============
		case 2:
		if(ShapeCircle.getRadius() < 2) break;
        // Set new radius
			ShapeCircle.setRadius(ShapeCircle.getRadius()-0.5);
            circleRadius->Text = FloatToStr(ShapeCircle.getRadius());
		// Redrawing circle
			PaintBox->Canvas->Ellipse(ShapeCircle.xLeftTop(),ShapeCircle.yLeftTop(),ShapeCircle.xRightBottom(),ShapeCircle.yRightBottom());
		// Redrawing center of circle
			PaintBox->Canvas->Ellipse(ShapeCircle.getxCenter()-2, ShapeCircle.getyCenter()-2, ShapeCircle.getxCenter()+2, ShapeCircle.getyCenter()+2);
        // Set info

			LabelInfoText->Caption = "Square: " + FloatToStr(ShapeCircle.Square()) + "\n" + "Perimeter: " + FloatToStr(ShapeCircle.Perimeter());
		break;
	// ===============
	// === Polygon ===
	// ===============
		case 3:
        // Save old center coords
			m = ShapePolygon.xCenterCoord();
			n = ShapePolygon.yCenterCoord();
		// Set new center and decrease size
			ShapePolygon.setCenter(0,0);
			ShapePolygon.setPointA(ShapePolygon.getxCoordA()*0.98,ShapePolygon.getyCoordA()*0.98);
			ShapePolygon.setPointB(ShapePolygon.getxCoordB()*0.98,ShapePolygon.getyCoordB()*0.98);
			ShapePolygon.setPointC(ShapePolygon.getxCoordC()*0.98,ShapePolygon.getyCoordC()*0.98);
			ShapePolygon.setPointD(ShapePolygon.getxCoordD()*0.98,ShapePolygon.getyCoordD()*0.98);
			ShapePolygon.setPointE(ShapePolygon.getxCoordE()*0.98,ShapePolygon.getyCoordE()*0.98);
		// Return old center
			ShapePolygon.setCenter(m,n);
		// Set "edit" of points
			xCoordPA->Text = FloatToStr(ShapePolygon.getxCoordA());
			xCoordPB->Text = FloatToStr(ShapePolygon.getxCoordB());
			xCoordPC->Text = FloatToStr(ShapePolygon.getxCoordC());
			xCoordPD->Text = FloatToStr(ShapePolygon.getxCoordD());
			xCoordPE->Text = FloatToStr(ShapePolygon.getxCoordE());
			yCoordPA->Text = FloatToStr(ShapePolygon.getyCoordA());
			yCoordPB->Text = FloatToStr(ShapePolygon.getyCoordB());
			yCoordPC->Text = FloatToStr(ShapePolygon.getyCoordC());
			yCoordPD->Text = FloatToStr(ShapePolygon.getyCoordD());
			yCoordPE->Text = FloatToStr(ShapePolygon.getyCoordE());
		// Drawing Polygon
			PaintBox->Canvas->MoveTo(ShapePolygon.getxCoordA(),ShapePolygon.getyCoordA());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordB(),ShapePolygon.getyCoordB());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordC(),ShapePolygon.getyCoordC());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordD(),ShapePolygon.getyCoordD());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordE(),ShapePolygon.getyCoordE());
			PaintBox->Canvas->LineTo(ShapePolygon.getxCoordA(),ShapePolygon.getyCoordA());
		// Drawing center of polygon
			PaintBox->Canvas->MoveTo(ShapePolygon.xCenterCoord(),ShapePolygon.yCenterCoord());
			PaintBox->Canvas->Ellipse(ShapePolygon.xCenterCoord()-2,ShapePolygon.yCenterCoord()-2,ShapePolygon.xCenterCoord()+2,ShapePolygon.yCenterCoord()+2);
		// Set info
			LabelInfoText->Caption = "Square: " + FloatToStr(ShapePolygon.Square()) + "\nPerimeter: " + FloatToStr(ShapePolygon.Perimeter());
		break;
		default:
		break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::sizeLClick(TObject *Sender)
{
	if (ComboBox->Text == "Triangle") {
		TimerSizeL->Tag = 1;
	}
	else if (ComboBox->Text == "Circle") {
		TimerSizeL->Tag = 2;
	}
	else if (ComboBox->Text == "Polygon") {
		TimerSizeL->Tag = 3;
	}
	sizeS->Enabled = false;
	TimerSizeL->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::sizeSClick(TObject *Sender)
{
    if (ComboBox->Text == "Triangle") {
		TimerSizeS->Tag = 1;
	}
	else if (ComboBox->Text == "Circle") {
		TimerSizeS->Tag = 2;
	}
	else if (ComboBox->Text == "Polygon") {
		TimerSizeS->Tag = 3;
	}
	sizeL->Enabled = false;
	TimerSizeS->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::choosePointSelect(TObject *Sender)
{
	if (choosePoint->Text == "Point A") {
		LabelPointPA->Visible = true;
		LabelPointPB->Visible = false;
		LabelPointPC->Visible = false;
		LabelPointPD->Visible = false;
		LabelPointPE->Visible = false;
		xCoordPA->Visible = true;
		xCoordPB->Visible = false;
		xCoordPC->Visible = false;
		xCoordPD->Visible = false;
		xCoordPE->Visible = false;
		yCoordPA->Visible = true;
		yCoordPB->Visible = false;
		yCoordPC->Visible = false;
		yCoordPD->Visible = false;
		yCoordPE->Visible = false;
	}
	else if(choosePoint->Text == "Point B") {
		LabelPointPA->Visible = false;
		LabelPointPB->Visible = true;
		LabelPointPC->Visible = false;
		LabelPointPD->Visible = false;
		LabelPointPE->Visible = false;
		xCoordPA->Visible = false;
		xCoordPB->Visible = true;
		xCoordPC->Visible = false;
		xCoordPD->Visible = false;
		xCoordPE->Visible = false;
		yCoordPA->Visible = false;
		yCoordPB->Visible = true;
		yCoordPC->Visible = false;
		yCoordPD->Visible = false;
		yCoordPE->Visible = false;
	}
	else if(choosePoint->Text == "Point C") {
		LabelPointPA->Visible = false;
		LabelPointPB->Visible = false;
		LabelPointPC->Visible = true;
		LabelPointPD->Visible = false;
		LabelPointPE->Visible = false;
		xCoordPA->Visible = false;
		xCoordPB->Visible = false;
		xCoordPC->Visible = true;
		xCoordPD->Visible = false;
		xCoordPE->Visible = false;
		yCoordPA->Visible = false;
		yCoordPB->Visible = false;
		yCoordPC->Visible = true;
		yCoordPD->Visible = false;
		yCoordPE->Visible = false;
	}
	else if(choosePoint->Text == "Point D") {
		LabelPointPA->Visible = false;
		LabelPointPB->Visible = false;
		LabelPointPC->Visible = false;
		LabelPointPD->Visible = true;
		LabelPointPE->Visible = false;
		xCoordPA->Visible = false;
		xCoordPB->Visible = false;
		xCoordPC->Visible = false;
		xCoordPD->Visible = true;
		xCoordPE->Visible = false;
		yCoordPA->Visible = false;
		yCoordPB->Visible = false;
		yCoordPC->Visible = false;
		yCoordPD->Visible = true;
		yCoordPE->Visible = false;
	}
	else if(choosePoint->Text == "Point E") {
		LabelPointPA->Visible = false;
		LabelPointPB->Visible = false;
		LabelPointPC->Visible = false;
		LabelPointPD->Visible = false;
		LabelPointPE->Visible = true;
		xCoordPA->Visible = false;
		xCoordPB->Visible = false;
		xCoordPC->Visible = false;
		xCoordPD->Visible = false;
		xCoordPE->Visible = true;
		yCoordPA->Visible = false;
		yCoordPB->Visible = false;
		yCoordPC->Visible = false;
		yCoordPD->Visible = false;
		yCoordPE->Visible = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SavePolygonPointsClick(TObject *Sender)
{
	// Clear PaintBox
	TRect r;
	r.Left = 0;
	r.right = 1000;
	r.Bottom = 1000;
	r.Top = 0;
	PaintBox->Canvas->Brush->Color=clWhite;
	PaintBox->Canvas->FillRect(r);
	// Save Points of Polygon
	ShapePolygon.setPointA(StrToFloat(xCoordPA->Text),StrToFloat(yCoordPA->Text));
	ShapePolygon.setPointB(StrToFloat(xCoordPB->Text),StrToFloat(yCoordPB->Text));
	ShapePolygon.setPointC(StrToFloat(xCoordPC->Text),StrToFloat(yCoordPC->Text));
	ShapePolygon.setPointD(StrToFloat(xCoordPD->Text),StrToFloat(yCoordPD->Text));
	ShapePolygon.setPointE(StrToFloat(xCoordPE->Text),StrToFloat(yCoordPE->Text));
	// Set "edit" of center
	xCenterPolygon->Text = FloatToStr(ShapePolygon.xCenterCoord());
	yCenterPolygon->Text = FloatToStr(ShapePolygon.yCenterCoord());
	// Drawing Polygon
	PaintBox->Canvas->MoveTo(ShapePolygon.getxCoordA(),ShapePolygon.getyCoordA());
	PaintBox->Canvas->LineTo(ShapePolygon.getxCoordB(),ShapePolygon.getyCoordB());
	PaintBox->Canvas->LineTo(ShapePolygon.getxCoordC(),ShapePolygon.getyCoordC());
	PaintBox->Canvas->LineTo(ShapePolygon.getxCoordD(),ShapePolygon.getyCoordD());
	PaintBox->Canvas->LineTo(ShapePolygon.getxCoordE(),ShapePolygon.getyCoordE());
	PaintBox->Canvas->LineTo(ShapePolygon.getxCoordA(),ShapePolygon.getyCoordA());
	// Drawing center of polygon
	PaintBox->Canvas->MoveTo(ShapePolygon.xCenterCoord(),ShapePolygon.yCenterCoord());
    PaintBox->Canvas->Ellipse(ShapePolygon.xCenterCoord()-2,ShapePolygon.yCenterCoord()-2,ShapePolygon.xCenterCoord()+2,ShapePolygon.yCenterCoord()+2);
	// Set info
	LabelInfoText->Caption = "Square: " + FloatToStr(ShapePolygon.Square()) + "\nPerimeter: " + FloatToStr(ShapePolygon.Perimeter());
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SaveCenterPolygonClick(TObject *Sender)
{
    // Clear PaintBox
	TRect r;
	r.Left = 0;
	r.right = 1000;
	r.Bottom = 1000;
	r.Top = 0;
	PaintBox->Canvas->Brush->Color=clWhite;
	PaintBox->Canvas->FillRect(r);
	// Save center of Polygon
	ShapePolygon.setCenter(StrToFloat(xCenterPolygon->Text),StrToFloat(yCenterPolygon->Text));
	// Set "edit" of points
	xCoordPA->Text = FloatToStr(ShapePolygon.getxCoordA());
	xCoordPB->Text = FloatToStr(ShapePolygon.getxCoordB());
	xCoordPC->Text = FloatToStr(ShapePolygon.getxCoordC());
	xCoordPD->Text = FloatToStr(ShapePolygon.getxCoordD());
	xCoordPE->Text = FloatToStr(ShapePolygon.getxCoordE());
	yCoordPA->Text = FloatToStr(ShapePolygon.getyCoordA());
	yCoordPB->Text = FloatToStr(ShapePolygon.getyCoordB());
	yCoordPC->Text = FloatToStr(ShapePolygon.getyCoordC());
	yCoordPD->Text = FloatToStr(ShapePolygon.getyCoordD());
	yCoordPE->Text = FloatToStr(ShapePolygon.getyCoordE());
	// Drawing Polygon
	PaintBox->Canvas->MoveTo(ShapePolygon.getxCoordA(),ShapePolygon.getyCoordA());
	PaintBox->Canvas->LineTo(ShapePolygon.getxCoordB(),ShapePolygon.getyCoordB());
	PaintBox->Canvas->LineTo(ShapePolygon.getxCoordC(),ShapePolygon.getyCoordC());
	PaintBox->Canvas->LineTo(ShapePolygon.getxCoordD(),ShapePolygon.getyCoordD());
	PaintBox->Canvas->LineTo(ShapePolygon.getxCoordE(),ShapePolygon.getyCoordE());
	PaintBox->Canvas->LineTo(ShapePolygon.getxCoordA(),ShapePolygon.getyCoordA());
	// Drawing center of polygon
	PaintBox->Canvas->MoveTo(ShapePolygon.xCenterCoord(),ShapePolygon.yCenterCoord());
	PaintBox->Canvas->Ellipse(ShapePolygon.xCenterCoord()-2,ShapePolygon.yCenterCoord()-2,ShapePolygon.xCenterCoord()+2,ShapePolygon.yCenterCoord()+2);
	// Set info
	LabelInfoText->Caption = "Square: " + FloatToStr(ShapePolygon.Square()) + "\nPerimeter: " + FloatToStr(ShapePolygon.Perimeter());
}
//---------------------------------------------------------------------------




