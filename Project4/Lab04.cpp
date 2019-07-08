#include <math.h>
#include <iostream>
#include <iomanip> // для setw
using namespace std;

void main() {
	system("color F0");
	int p;

	setlocale(LC_ALL, "RUS");
	cout << "Введите размерность массива массива " << endl;
	int A1, A2, k;


	do {
		cout << " Введите кол-во строк = ";
		cin >> A1;
		if (A1 < 1) k = 0;
		else  k = 1;
	} while (k == 0);

	do {
		cout << "Введите кол-во столбцов = ";
		cin >> A2;
		if (A2 < 1) k = 0;
		else  k = 1;
	} while (k == 0);
	cout << "Приведенный массив размерностью " << A1 << " на " << A2 << endl;

	cout << "Введите зачения массива " << endl;
	int** A;
	A = new int*[A1];
	for (int i = 0; i < A1; i++)
		A[i] = new int[A2];
	//заполнение
	for (int i = 0; i < A1; i++) {
		for (int j = 0; j < A2; j++) {
			cout << i << "," << j << " элемент ";
			cin >> A[i][j];
		}
	};
	// menu
	cout << "Выберите сдвиг (вправо-1 , вниз-2)" << endl;
	int u;
	cin >> u;
	int n;
	cout << "Введите количество сдвигов " << endl;
	cin >> n;
	int R1;
	if (u == 1) {



		int p_cel = n / A2; // деление нацело 
		int p_ost = n % A2; // остаток от деления
		if (p_cel == 0) p_cel = 1;
		for (int i = 0; i < A1; ++i) {
			for (int m = 0; m < p_cel; ++m) {
				for (int j = 0; j < p_ost; ++j) {

					R1 = A[i][j]; A[i][j] = A[i][j + 1]; A[i][j + 1] = R1;
				}
			}
		}
	}

	else if (u == 2) {
		int p_cel = n / A1;
		int p_ost = n % A1;
		if (p_cel == 0) p_cel = 1;
		for (int j = 0; j < A2; ++j) {
			for (int m = 0; m < p_cel; ++m) {
				for (int i = 0; i < p_ost; ++i) {

					R1 = A[i][j]; A[i][j] = A[i + 1][j]; A[i + 1][j] = R1;
				};
			}
		}
	}
	for (int i = 0; i < A1; i++) {
		cout << endl;
		for (int j = 0; j < A2; j++) {
			cout << " " << A[i][j];

		}
	};
	cout << endl;
	system("pause");
}