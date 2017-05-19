//---------------------------------------------------------------------------

#ifndef PolygonH
#define PolygonH
//---------------------------------------------------------------------------
#endif

class Polygons {
	public:
		Polygons(double xA = 30, double yA = 30,
				double xB = 100, double yB = 50,
				double xC = 170, double yC = 170,
				double xD = 130, double yD = 170,
				double xE = 40, double yE = 200);
		double getxCoordA();
		double getxCoordB();
		double getxCoordC();
		double getxCoordD();
		double getxCoordE();
		double getyCoordA();
		double getyCoordB();
		double getyCoordC();
		double getyCoordD();
		double getyCoordE();
		double xCenterCoord();
		double yCenterCoord();
		double Square();
		double Perimeter();
		void setCenter(double x, double y);
		void setPointA(double x, double y);
		void setPointB(double x, double y);
		void setPointC(double x, double y);
		void setPointD(double x, double y);
		void setPointE(double x, double y);
	private:
		double xCenter;
		double yCenter;
		double xCoordA;
		double xCoordB;
		double xCoordC;
		double xCoordD;
		double xCoordE;
		double yCoordA;
		double yCoordB;
		double yCoordC;
		double yCoordD;
		double yCoordE;
};
