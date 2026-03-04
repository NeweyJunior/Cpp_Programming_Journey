#include <iostream>
#include <iomanip>
#define SENSIVITY 10000000

using namespace std;

void menu();
void smallMenu();
double integralCalculate(double lower, double upper);

int main(){
	menu();
	
	while(true){
		int processNumber;
	
		cout << "Please enter a process number: ";
		cin >> processNumber;
		cout << "===============================================================" << endl;
		
		//if user enters a letter:
		if(cin.fail()){
			cin.clear();
			cin.ignore(1000,'\n');
			cout << "Please select a valid process." << endl;
			cout << "===============================================================" << endl;
			continue;
		}
		
		//if user wants to exit: 
		if(processNumber == -1){
			cout << "See you!" << endl;
			cout << "===============================================================" << endl;
			return 0;
		}
		//if user enters wrong value:
		if(processNumber != -1 && processNumber != 1 && processNumber != 2 && processNumber != 3){
			cout << "Please select a valid process." << endl;
			cout << "===============================================================" << endl;
			continue;
		}
		
		//if user enters correct value:
		switch(processNumber){
			case 1: 
				{
				double upper,lower;
				cout << "Please enter a upper limit: ";
				cin >> upper;
				cout << "===============================================================" << endl;
				cout << "Please enter a lower limit: ";
				cin >> lower;
				cout << "===============================================================" << endl;
				cout << "Result: " << integralCalculate(lower, upper) <<endl;
				break;
				}
			case 2:
				cout << "This process is coming soon..." << endl;
				break;
			case 3:
				cout << "This process is coming soon..." << endl;
				break;
		}
		smallMenu();
	}
	
	return 0;
}
double integralCalculate(double lower, double upper){
	double wide = (upper - lower) / SENSIVITY;
	double highPoint;
	double highPointValue;
	double result = 0;
	
	for(int k = 1; k < SENSIVITY; k++){
		highPoint = lower + k * (wide);
		highPointValue = (highPoint) * (highPoint);
		
		result += highPointValue * wide;
	}
	return result;
}

void menu(){
	cout << "================== WELCOME TO THE CALCULATOR ==================" << endl;
	cout << "-1) Exit" << endl;
	cout << "1) Calculate Integral (x^2)" << endl;
	cout << "2) Calculate Derivative" << endl;
	cout << "3) Calculate Limit" << endl;
	cout << "===============================================================" << endl;
}

void smallMenu(){
	cout << "===============================================================" << endl;
	cout << "-1) Exit" << endl;
	cout << "1) Calculate Integral (x^2)" << endl;
	cout << "2) Calculate Derivative" << endl;
	cout << "3) Calculate Limit" << endl;
	cout << "===============================================================" << endl;
}
