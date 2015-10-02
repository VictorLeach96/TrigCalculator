#include "header.h"

//String double conversions
string to_string(double number){
	stringstream ss (stringstream::in | stringstream::out);
	ss << number;
	return ss.str();
}

//Pad string with spaces
string pad_string(int newSize, string value){
	//Calculate space needed on each side of the string
	int spaceSize = (newSize-value.size())/2;

	//Insert spaces at start and end
	value.insert(value.begin(),spaceSize, ' ');
	value.insert(value.end(),spaceSize, ' ');

	//Fix inprecision with divisions
	if (value.size() == newSize - 1){
		value.append(" ");
	}

	return value;
}

//Input a value into the console
double input(string text){
	//Ask user and inpu value
	cout << "Please enter " << text << endl;
	double var;
	cin >> var;

	//If input failed
	if (!cin || cin.fail()){
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		return 0;
	}else{
		return var;
	}
}

//Main
int main(){
	system("cls");

	//Set the console width and height
	HWND console = GetConsoleWindow();
	RECT rect;
	GetWindowRect(console, &rect);
	MoveWindow(console, rect.left, 50, 800, 900, TRUE);

	//Loop the program
	while(1){

		//Show the welcome message
		cout << "  _______   _          _____      _            _       _             " << endl;
		cout << " |__   __| (_)        / ____|    | |          | |     | |            " << endl;
		cout << "    | |_ __ _  __ _  | |     __ _| | ___ _   _| | __ _| |_ ___  _ __ " << endl;
		cout << "    | | '__| |/ _` | | |    / _` | |/ __| | | | |/ _` | __/ _ \\| '__|" << endl;
		cout << "    | | |  | | (_| | | |___| (_| | | (__| |_| | | (_| | || (_) | |   " << endl;
		cout << "    |_|_|  |_|\\__, |  \\_____\\__,_|_|\\___|\\__,_|_|\\__,_|\\__\\___/|_|  " << endl;
		cout << "               __/ |                                                 " << endl;
		cout << "              |___/                                                  " << endl;
		cout << endl << endl << endl;
	
		//Display the reference trinagle
		cout << "                /\\" << endl;
		cout << "               /  \\" << endl;
		cout << "              /    \\" << endl;
		cout << "             /   b  \\" << endl;
		cout << "            /        \\" << endl;
		cout << "           /          \\" << endl;
		cout << "          /            \\" << endl;
		cout << "         /              \\" << endl;
		cout << "        /                \\" << endl;
		cout << "     C /                  \\ A" << endl;
		cout << "      /                    \\" << endl;
		cout << "     /                      \\" << endl;
		cout << "    /                        \\" << endl;
		cout << "   /                          \\" << endl;
		cout << "  /                            \\" << endl;
		cout << " /                              \\" << endl;
		cout << "/ a                            c \\" << endl;
		cout << "-----------------------------------" << endl;
		cout << "                B" << endl;
		cout << endl << endl << endl;
		cout << "Please enter each of the values listed on the triangle, to leave it blank use 0" << endl;
		cout << endl;

		//Get each of the values from the user
		Triangle obj;

		//Angles
		obj.angleA = input("angle a");
		obj.angleB = input("angle b");
		obj.angleC = input("angle c");
		//Sides
		obj.sideA = input("side a");
		obj.sideB = input("side b");
		obj.sideC = input("side c");
		cout << endl;
	
		//Make calculation
		if (obj.calculateMissingValues() == 0){

			//Print out calculation error and stop execution
			cout << obj.errorDescription << endl << endl;
			system("pause");
		}else{

			//Convert all  values to strings
			string sideA = pad_string(7,to_string(obj.sideA));
			string sideB = pad_string(7,to_string(obj.sideB));
			string sideC = pad_string(7,to_string(obj.sideC));
			
			string angleA = pad_string(7,to_string(obj.angleA));
			string angleB = pad_string(7,to_string(obj.angleB));
			string angleC = pad_string(7,to_string(obj.angleC));

			string area = pad_string(7,to_string(obj.area));

			//Print out answers
			cout << "                /\\" << endl;
			cout << "               /  \\" << endl;
			cout << "              /    \\" << endl;
			cout << "             /      \\" << endl;
			cout << "            / " << angleB << "\\" << endl;
			cout << "           /          \\" << endl;
			cout << "          /            \\" << endl;
			cout << "         /              \\" << endl;
			cout << "        /                \\" << endl;
			cout << "" << sideC << "/       Area       \\" << sideA << endl;
			cout << "      /      " << area << "^2     \\" << endl;
			cout << "     /                      \\" << endl;
			cout << "    /                        \\" << endl;
			cout << "   /                          \\" << endl;
			cout << "  /                            \\" << endl;
			cout << " /                              \\" << endl;
			cout << "/" << angleA << "                  " << angleC << "\\" << endl;
			cout << "-----------------------------------" << endl;
			cout << "              " << sideB << endl << endl << endl;

			//Print out continue message
			system("pause");
		}

		//Clear the screen and buffer
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		system("cls");
	}

	return 1;
}