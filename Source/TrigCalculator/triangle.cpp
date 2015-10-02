#include "header.h"

//Triangle Layout
//http://sub.allaboutcircuits.com/images/01002.png

//---------- Info Functions ----------

//Checks whether specified triangle has a right angle in it
bool Triangle::hasRightAngle(){
	if (angleA == 90 || angleB == 90 || angleC == 90){
		return true;
	}else{
		return false;
	}
}

//Returns number of sides which have been specified
int Triangle::countSides(){
	int sides = 0;
	if (sideA != 0){ sides++; }
	if (sideB != 0){ sides++; }
	if (sideC != 0){ sides++; }
	return sides;
}

//Returns number of angles which have been specified
int Triangle::countAngles(){
	int angles = 0;
	if (angleA != 0){ angles++; }
	if (angleB != 0){ angles++; }
	if (angleC != 0){ angles++; }
	return angles;
}

//---------- Calculate Functions ----------

//Calculate the values which have not been specified to the triangle
int Triangle::calculateMissingValues(){

	//Stop user from entering incorrect angles
	if (angleA != 0 && angleB != 0 && angleC != 0 && angleA + angleB + angleC != 180){
		//Return 0 for fail, caller can use error property
		errorDescription = "The angles given must equal 180 degrees";
		return 0;
	}
	if ((angleA == 0 || angleB == 0 || angleC == 0) && angleA + angleB + angleC >= 180){
		//Return 0 for fail, caller can use error property
		errorDescription = "Angles cannot equal to more than 180 degrees";
		return 0;
	}

	//Stop user from entering incorrect sides
	if (sideA != 0 && sideB != 0 && sideC != 0){
		if ((sideA + sideB < sideC) ||
			(sideC + sideB < sideA) ||
			(sideC + sideA < sideB)){
			//Return 0 for fail, caller can use error property
			errorDescription = "Incorrect sides any two sides must equal to more than the third";
			return 0;
		}
	}

	//Check if all values are given
	if (countSides() == 3 && countAngles() == 3){
		return 1;
	}

	//-- Non-right angle triangle --

	//Calculate 2 angles if all sides are given
	if (countSides() == 3){
		calculateAngleFromAllSides();
	}

	//Calculate 3rd angle if two angles are given
	if (countAngles() == 2){
		calculateThirdAngle();
	}

	//-- Right angle triangle --
	if (hasRightAngle()){

		//Calculate the missing sides using trig ratio
		if (countSides() == 1 && countAngles() != 1){
			calculateTrigonometrySides();
		}

		//Calculate the missing sides using pythagoras
		if (countSides() == 2){
			calculatePythagorasTheorem();
		}
		
		//Calculate the missing angles using trig
		if (countSides() == 3){
			calculateTrigonometryAngles();
		}
	}

	//Calculate 2 angles if all sides are given
	if (countSides() == 3){
		calculateAngleFromAllSides();
	}

	//Calculate 3rd angle if two angles are given
	if (countAngles() == 2){
		calculateThirdAngle();
	}

	//Calculate area
	calculateTriangleArea();

	//When finished round final values to 2 decimal places
	roundValues();

	//Check that each value has been calculated
	if (angleA == 0 || angleB == 0 || angleC == 0 || sideA == 0 || sideB == 0 || sideC == 0){
		//Return 0 for fail, caller can use error property
		errorDescription = "Not enough data please enter more sides or angles";
		return 0;
	}

	return 1;
}

//---------- Maths Functions ----------

//Calculate missing side using pythagoras
void Triangle::calculatePythagorasTheorem(){
	//Init virtual triangles vars
	double a = 0;
	double b = 0;
	double c = 0;
	double ans = 0;

	//Assign each actual side to virtual triangle
	if (angleA == 90){
		a = sideC;
		b = sideB;
		c = sideA;
	}else if (angleB == 90){
		a = sideA;
		b = sideC;
		c = sideB;
	}else if (angleC == 90){
		a = sideB;
		b = sideA;
		c = sideC;
	}

	//Choose an equasion and calculate missing side
	if (c == 0){
		ans = sqrt( (a * a) + (b * b) );
	}else if (b == 0){
		ans = sqrt( (c * c) - (a * a) );
	}else if (a == 0){
		ans = sqrt( (c * c) - (b * b) );
	}

	//Assign missing side to actual triangle
	if (sideA == 0){
		sideA = ans;
	}else if (sideB == 0){
		sideB = ans;
	}else if (sideC == 0){
		sideC = ans;
	}
}

//Calculate missing sides using triganometry
void Triangle::calculateTrigonometrySides(){
	if (angleA == 90){
		if (angleB != 0){
			if (sideA != 0){
				sideC = sideA * cos( convertDegrees(angleB) );
			}else if (sideB != 0){
				sideC = sideB / tan( convertDegrees(angleB) );
			}else if (sideC != 0){
				sideB = sideC * tan( convertDegrees(angleB) );
			}
		}else if (angleC != 0){
			if (sideA != 0){
				sideC = sideA * sin( convertDegrees(angleC) );
			}else if (sideB != 0){
				sideC = sideB * tan( convertDegrees(angleC) );
			}else if (sideC != 0){
				sideA = sideC / sin( convertDegrees(angleC) );
			}
		}
	}else if (angleB == 90){
		if (angleA != 0){
			if (sideA != 0){
				sideB = sideA / sin( convertDegrees(angleA) );
			}else if (sideB != 0){
				sideA = sideB * sin( convertDegrees(angleA) );
			}else if (sideC != 0){
				sideA = sideC * tan( convertDegrees(angleA) );
			}
		}else if (angleC != 0){
			if (sideA != 0){
				sideC = sideA * tan( convertDegrees(angleC) );
			}else if (sideB != 0){
				sideC = sideB * sin( convertDegrees(angleC) );
			}else if (sideC != 0){
				sideA = sideC / tan( convertDegrees(angleC) );
			}
		}
	}else if (angleC == 90){
		if (angleA != 0){
			if (sideA != 0){
				sideB = sideA / tan( convertDegrees(angleA) );
			}else if (sideB != 0){
				sideA = sideB * tan( convertDegrees(angleA) );
			}else if (sideC != 0){
				sideB = sideC * cos( convertDegrees(angleA) );
			}
		}else if (angleB != 0){
			if (sideA != 0){
				sideB = sideA * tan( convertDegrees(angleB) );
			}else if (sideB != 0){
				sideA = sideB / tan( convertDegrees(angleB) );
			}else if (sideC != 0){
				sideA = sideC * cos( convertDegrees(angleB) );
			}
		}
	}
}

//Calculate missing angles using trigonometry
void Triangle::calculateTrigonometryAngles(){
	if (angleA == 90){
		if (angleB == 0){
			angleB = convertRadians( acos( sideC / sideA ) );
		}
		if (angleC == 0){
			angleC = convertRadians( acos( sideB / sideA ) );
		}
	}else if (angleB == 90){
		if (angleA == 0){
			angleA = convertRadians( acos( sideC / sideB ) );
		}
		if (angleC == 0){
			angleC = convertRadians( acos( sideA / sideB ) );
		}
	}else if (angleC == 90){
		if (angleA == 0){
			angleA = convertRadians( acos( sideB / sideC ) );
		}
		if (angleB == 0){
			angleB = convertRadians( acos( sideA / sideC ) );
		}
	}
}

//Calculate 3rd angle of the triangle if two angles are given
void Triangle::calculateThirdAngle(){
	if (angleA != 0 && angleB != 0){
		angleC = 180-(angleA + angleB);
	}else if (angleA != 0 && angleC != 0){
		angleB = 180-(angleA + angleC);
	}else if (angleC != 0 && angleB != 0){
		angleA = 180-(angleC + angleB);
	}
}

//Calculate 2 angles where all sides are given
void Triangle::calculateAngleFromAllSides(){
	angleA = convertRadians( acos( ( (sideB * sideB) + (sideC * sideC) - (sideA * sideA)) / (2 * sideB * sideC) ) );
	angleB = convertRadians( acos( ( (sideC * sideC) + (sideA * sideA) - (sideB * sideB)) / (2 * sideC * sideA) ) );
}

//Calculate non right angle sides
// Didn't have time to complete this to a 100% working state
void Triangle::calculateNonRightAngleSides(){
	if (sideA != 0){
		sideB = (sideA * sin(convertDegrees(angleB))) / sin(convertDegrees(angleA));
		sideC = (sideA * sin(convertDegrees(angleC))) / sin(convertDegrees(angleA));
	}
	if (sideB != 0){
		sideA = (sideB * sin(convertDegrees(angleA))) / sin(convertDegrees(angleB));
		sideC = (sideB * sin(convertDegrees(angleC))) / sin(convertDegrees(angleB));
	}
	if (sideC != 0){
		sideA = (sideC * sin(convertDegrees(angleA))) / sin(convertDegrees(angleC));
		sideB = (sideC * sin(convertDegrees(angleB))) / sin(convertDegrees(angleC));
	}
}

//Calculate the an additional value of the triangle
// Didn't have time to complete this to a 100% working state
void Triangle::calculateNonRightAngleAngles(){
	if (sideA == 0){
		if (angleA != 0){
			sideA = sqrt( ( (sideC * sideC) + (sideB * sideB) ) - ( 2 * sideC * sideB ) * cos(convertDegrees(angleA)) );
		}else if (angleB != 0){
			angleC = convertRadians(asin( ( sideC * sin(convertDegrees( angleB ))) / sideB ));
		}else if (angleC != 0){
			angleB = convertRadians(asin( ( sideB * sin(convertDegrees( angleC ))) / sideC ));
		}
	}else if (sideB == 0){
		if (angleA != 0){
			angleC = convertRadians(asin( ( sideC * sin(convertDegrees( angleA ))) / sideA ));
		}else if (angleB != 0){
			sideB = sqrt( ( (sideC * sideC) + (sideA * sideA) ) - ( 2 * sideC * sideA ) * cos(convertDegrees(angleB)) );
		}else if (angleC != 0){
			angleA = convertRadians(asin( ( sideA * sin(convertDegrees( angleC ))) / sideC ));
		}
	}else if (sideC == 0){
		if (angleA != 0){
			angleB = convertRadians(asin( ( sideB * sin(convertDegrees( angleA ))) / sideA ));
		}else if (angleB != 0){
			angleA = convertRadians(asin( ( sideA * sin(convertDegrees( angleB ))) / sideB ));
		}else if (angleC != 0){
			sideC = sqrt( ( (sideB * sideB) + (sideA * sideA) ) - ( 2 * sideB * sideA ) * cos(convertDegrees(angleC)) );
		}
	}
}

//Calculate area of the triangle
void Triangle::calculateTriangleArea(){
	area = 0.5 * sideB * sideC * sin(convertDegrees( angleA ));
}

//---------- Backend Functions ----------

//Convert between radians and degrees
double Triangle::convertRadians(double radians) {
  return (radians * 180) / 3.14159265;
}
double Triangle::convertDegrees(double degrees) {
  return (degrees * 3.14159265) / 180;
}

//Round an double to a specified precision
double Triangle::roundToDecimal(double value, int precision){
    int precisionValue = std::pow(10,(double)precision);
    return floor( value*(precisionValue) + 0.5 )/precisionValue;
}

//Round values to 2 decimal places
void Triangle::roundValues(){
	angleA = roundToDecimal(angleA,3);
	angleB = roundToDecimal(angleB,3);
	angleC = roundToDecimal(angleC,3);

	sideA = roundToDecimal(sideA,3);
	sideB = roundToDecimal(sideB,3);
	sideC = roundToDecimal(sideC,3);

	area = roundToDecimal(area,3);
}