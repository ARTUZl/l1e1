//---------------------------------------------------------------------------

#ifndef TriangleH
#define TriangleH
//---------------------------------------------------------------------------
#endif

class Triangle {
	public:
	// Constructor
		Triagle(double ay = 100, double by = 200, double cy = 300,
				double ax = 100, double bx = 200, double cx = 200);
	// Set main points of Triangle
		void setCenter(double x, double y);
		void setPointA(double x, double y);
		void setPointB(double x, double y);
		void setPointC(double x, double y);
	// Get information about Triangle
		double Square();
		double Perimeter();
	// Get coordinats of points A,B,C
		double getyCoordA();
		double getyCoordB();
		double getyCoordC();
		double getxCoordA();
		double getxCoordB();
		double getxCoordC();
	// Get lenght of side AB,BC,CA
		double sideAB();
		double sideBC();
		double sideCA();
    // Calculate coordinats of center
		double xCenter();
		double yCenter();
	private:
	// Coordinats of points A,B,C
		double xCoordA;
		double xCoordB;
		double xCoordC;
		double yCoordA;
		double yCoordB;
		double yCoordC;
	// Calculate length of side
		double side(double x1, double y1, double x2, double y2);
};
