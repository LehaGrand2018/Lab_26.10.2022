#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
//#define DEBUG
#ifdef DEBUG



void InputSize(int& SIZE) {
	cout << "Input vector size: ";
	while (SIZE < 1) {
		cin >> SIZE;
		if (SIZE < 1) {
			cout << "Size must be more then 0, input another number: ";
		}
	}
	cout << endl << "======================================================" << endl << endl;

}

void PrintVector(vector<int>& arr, const int& SIZE) {
	cout << endl << "Vector: ";
	for (int i = 0; i < SIZE; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void KeyboardInput(vector<int>& arr, const int& SIZE) {
	cout << "Input vector: ";
	for (int i = 0; i < SIZE; i++) {
		cin >> arr[i];
	}
	PrintVector(arr, SIZE);
};

void RandomInput(vector<int>& arr, const int& SIZE) {

	srand(time(NULL));
	int minRange = 0, maxRange = 0;

	while (minRange == maxRange) {
		cout << "Input random numbers minimum range: ";
		cin >> minRange;
		cout << "Input random numbers maximum range: ";
		cin >> maxRange;
	}


	for (int i = 0; i < SIZE; i++) {
		arr[i] = minRange + rand() % (maxRange - minRange + 1);
	}
	PrintVector(arr, SIZE);

};

void FileInput(vector<int>& arr, const int& SIZE, fstream& fin) {
	for (int i = 0; i < SIZE; i++) {
		fin >> arr[i];
	}
	PrintVector(arr, SIZE);
}

void SwitchInMethod(vector<int>& arr, const int& SIZE, fstream& fin) {

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

void NumberOfMinElement(vector<int>& arr, const int SIZE) {

	cout << endl << endl << "-------------------------------------------------------------------" << endl;
	cout << "NUMBER OF MINIMUM ELEMENT" << endl;
	cout << "-------------------------------------------------------------------" << endl << endl;

	int minElement = abs(arr[0]);
	int index = 0;
	for (int i = 0; i < SIZE; i++) {
		if (abs(arr[i]) <= minElement) {
			minElement = abs(arr[i]);
			index = i + 1;
		}
	}
	cout << "Number of min element: " << index << endl;

};

int FindNullElementNumber(vector<int>& arr, const int SIZE) {

	int index = -1;
	for (int i = 0; i < SIZE; i++) {
		if (arr[i] == 0) {
			index = i;
		}
	}
	if (index == -1) {
		cout << "Null element not founded." << endl << endl;
		index = SIZE - 1;
	}
	return index;
}

void SumOfElBeforeNullEl(vector<int>& arr, const int SIZE) {
	

	cout << endl << "-------------------------------------------------------------------" << endl;
	cout << "SUM OF ELEMENTS BEFORE LAST NULL ELEMENT" << endl;
	cout << "-------------------------------------------------------------------" << endl << endl;

	int sum = 0;
	int i = 0;
	
	int temp = FindNullElementNumber(arr, SIZE);
	while ( i != temp) {
		sum += arr[i];
		i++;
	}
	if (temp == SIZE - 1) {
		cout << "Sum of all vector elements: " << sum << endl << endl;
	} else {
		cout << "Sum of elements before the last null element: " << sum << endl << endl;
	}
	
	cout << "-------------------------------------------------------------------" << endl;

}


void SortVector(vector<int>& arr, const int SIZE) {

	cout << endl << "-------------------------------------------------------------------" << endl;
	cout << "SORT VECTOR" << endl;
	cout << "-------------------------------------------------------------------" << endl << endl;

	vector<int> temp_vector;

	int i = 2;
	while ( i < SIZE) {
		temp_vector.push_back(arr[i]);
		i += 3;
	}
	temp_vector.push_back(arr[0]);

	for (int i = 1; i < SIZE; i++) {
		if ((i + 1) % 3)
			temp_vector.push_back(arr[i]);
	}
	for (int i = 0; i < SIZE; i++) {
		arr[i] = temp_vector[i];
	}

	PrintVector(arr, SIZE);
}

int main() {
	setlocale(LC_ALL, "Rus");

	int SIZE = 0;

	InputSize(SIZE);


	vector<int> arr(SIZE);
	fstream fin("input.txt");
	fstream fout("output.txt");

	SwitchInMethod(arr, SIZE, fin);

	NumberOfMinElement(arr, SIZE);

	SumOfElBeforeNullEl(arr, SIZE);

	SortVector(arr, SIZE);
	return 0;
}

#endif // DEBUG
// 4 5 6 -1 -5 4 9 7 0 9 8 0 6 3 4 4 5 6 7 7 5 6