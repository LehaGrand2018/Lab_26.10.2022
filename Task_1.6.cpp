#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;

#define DEBUG
#ifdef DEBUG




void InputSize(int &SIZE) {
	cout << "Input vector size: ";
	while (SIZE < 1) {
		cin >> SIZE;
		if (SIZE < 1) {
			cout << "Size must be more then 0, input another number: ";
		}
	}
	cout << endl << "======================================================" << endl << endl;
	
}

void PrintVector(vector<double>& arr, const int& SIZE) {
	cout << endl << "Vector: ";
	for (int i = 0; i < SIZE; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void KeyboardInput(vector<double>& arr, const int& SIZE) {
	cout << "Input vector: ";
	for (int i = 0; i < SIZE; i++) {
		cin >> arr[i];
	}
	PrintVector(arr, SIZE);
};

void RandomInput(vector<double>& arr, const int& SIZE) {

	srand(time(NULL));
	int minRange = 0, maxRange = 0, precision = -1;

	while (minRange == maxRange) {
		cout << "Input random numbers minimum range: ";
		cin >> minRange;
		cout << "Input random numbers maximum range: ";
		cin >> maxRange;
		
	}
	while (precision < 0) {
		cout << "Input number of simbols after dot: ";
		cin >> precision;
	}
	
	
	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand() % (int)pow(10, precision + 1);
		arr[i] = minRange + (arr[i] / pow(10, precision + 1)) * (maxRange - minRange);
	}
	PrintVector(arr, SIZE);
	
};

void FileInput(vector<double>& arr, const int& SIZE, fstream& fin) {
	for (int i = 0; i < SIZE; i++) {
		fin >> arr[i];
	}
	PrintVector(arr, SIZE);
}

void SwitchInMethod(vector<double>& arr, const int& SIZE, fstream& fin) {
	
	cout << "1. Input from keyboard" << endl;
	cout << "2. Random input" << endl;
	cout << "3. Input vector from file input.txt" << endl << endl;

	int mode;
	cout << "Mode: ";
	cin >> mode;
	cout << endl << "===================================================================" << endl << endl;
	switch (mode)
	{
	case 1:
		KeyboardInput(arr, SIZE);
		break;
	case 2:
		RandomInput(arr, SIZE);
		break;
	case 3: 
		FileInput(arr, SIZE, fin);
		break;
	default:
		break;
	}

};

void NumberOfMinElement(vector<double>& arr, const int SIZE) {

	cout << endl << endl << "-------------------------------------------------------------------" << endl;
	cout << "NUMBER OF MINIMUM ELEMENT" << endl;
	cout << "-------------------------------------------------------------------" << endl << endl;

	double minElement = abs(arr[0]);
	int index = 0;
	for (int i = 0; i < SIZE; i++) {
		if (abs(arr[i]) <= minElement) {
			minElement = abs(arr[i]);
			index = i + 1;
		}
	}
	cout << "Number of min element: " << index << endl;


};

int FindNegElementNumber(vector<double>& arr, const int SIZE) {
	
	int index = 0;
	for (int i = 0; i < SIZE; i++){
		if (arr[i] < 0) {
			index = i;
			break;
		}
	}

	return index;
}

void SummOfNegativeElenents(vector<double>& arr, const int SIZE) {
	double sum = 0;
	for (int i = FindNegElementNumber(arr, SIZE) + 1; i < SIZE; i++) {
		sum += arr[i];
	}
	cout << endl << "-------------------------------------------------------------------" << endl;
	cout << "SUM OF NEGATIVE ELEMENTS" << endl;
	cout << "-------------------------------------------------------------------" << endl << endl;

	cout << "Sum of elements after first negative element: " << sum << endl << endl;
	cout << "-------------------------------------------------------------------" << endl;
}

void DeleteElements(vector<double>& arr, const int SIZE) {

	cout << endl << "-------------------------------------------------------------------" << endl;
	cout << "DELETE ELEMENTS" << endl;
	cout << "-------------------------------------------------------------------" << endl << endl;
	double number;
	cout << "Enter number to delete: ";
	cin >> number;

	int counter = 0;

	for (int i = 0; i < SIZE; i++) {

		if (arr[i] == number) {
			counter++;
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE - 1; j++) {
					if (arr[j] == number) {
						swap(arr[j], arr[j + 1]);
					}
				}
			}
		}

	}

	for (int i = 0; i < SIZE; i++) {
		if (arr[i] == number) {
			arr[i] = 0;
		}
	}

	PrintVector(arr, SIZE);

};

int main() {
	setlocale(LC_ALL, "Rus");
	
	int SIZE = 0;

	InputSize(SIZE);


	vector<double> arr(SIZE);
	fstream fin("input.txt");
	fstream fout("output.txt");

	SwitchInMethod(arr, SIZE, fin);
	
	NumberOfMinElement(arr, SIZE);
	SummOfNegativeElenents(arr, SIZE);
	DeleteElements(arr, SIZE);
	return 0;
}
#endif // DEBUG