//---------------------------------------------------------------------------

#ifndef CircleH
#define CircleH
//---------------------------------------------------------------------------
#endif

class Circle {
	public:
		Circle(double x = 300, double y = 300, double r = 100);
		void setCenter(double x, double y);
		void setRadius(double x);
		double Square();
		double Perimeter();
		double xLeftTop();
		double yLeftTop();
		double xRightBottom();
		double yRightBottom();
		double getxCenter();
		double getyCenter();
        double getRadius();
	private:
		double xCenter;
		double yCenter;
		double radius;
};
