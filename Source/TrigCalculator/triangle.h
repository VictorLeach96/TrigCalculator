#include "header.h"

class Triangle{
	public:

		//Constructor
		Triangle(){
			//Reset all values to 0
			sideA = 0.0f; sideB = 0.0f; sideC = 0.0f;
			angleA = 0.0f; angleB = 0.0f; angleC = 0.0f;
			area = 0.0f;
		}

		//Sides
		double sideA;
		double sideB;
		double sideC;

		//Angles
		double angleA;
		double angleB;
		double angleC;

		//Area
		double area;
		
		//Calculate Functions
		int calculateMissingValues();
		std::string errorDescription;

	private:

		//Info Functions
		bool hasRightAngle();
		int countSides();
		int countAngles();

		//Maths Functions
		void calculateThirdAngle();
		//Right Angle
		void calculatePythagorasTheorem();
		void calculateTrigonometrySides();
		void calculateTrigonometryAngles();
		//Non Right Angle
		void calculateAngleFromAllSides();
		void calculateNonRightAngleSides();
		void calculateNonRightAngleAngles();
		//Area
		void calculateTriangleArea();

		//Backend Math Functions
		double convertRadians(double radians);
		double convertDegrees(double degrees);
		double roundToDecimal(double value, int precision);
		void roundValues();
};