#include <iostream>
#include <iomanip>

using namespace std;





template<class Type> Type kolel(Type *A, int q, Type n, Type  k) {
	int kol_vo = 0;
	for (int i = 0; i < q; ++i) {
		if ((A[i] >= n) && (A[i] <= k)) ++kol_vo;
	}; return kol_vo;
}

template<class T> T sum(T *A, const int q) {
	T sumotr = 0;
	T max = A[0];
	int maxnum = 0;
	for (int i = 1; i < q; ++i)	if (A[i] > max) { maxnum = i; max = A[i]; };
	++maxnum;
	for (; maxnum < q; ++maxnum)  sumotr += A[maxnum];
	return sumotr;
}
template<class Ty> Ty fsort(Ty *A, const int q) {
	Ty R;
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < q - i - 1; j++) {
			if (fabs(A[j]) < fabs(A[j + 1])) {

				R = A[j];
				A[j] = A[j + 1];
				A[j + 1] = R;

			}
		}
	};
	return 1;
}
void lab3() {
	int q;
	cout << "Введите размерность массива" << endl;
	cout << "N=";
	cin >> q;
	int *A = new int[q];

	//INTEGER

	// заполнение массива 
	cout << "!!!Заполните массив натуральных чисел А!!!" << endl;
	for (int i = 0; i < q; ++i) cin >> A[i];

	//количество элементов массива, лежащих в диапазоне от А до В.
	int n, k;
	cout << "Введите начальное значение диапазона" << endl;
	cin >> n;
	cout << "Введите конечное значение диапазона" << endl;
	cin >> k;
	cout << "\n===Количество элементов массива, лежащих в диапазоне от А до В=== \t" << kolel(A, q, n, k) << endl;
	//поиск суммы
	cout << "\n===Cумма элементов массива, расположенных после максимального элемента=== \t" << sum(A, q) << endl;
	// массив до перестановки
	cout << "\n===Массив до перестановки===\n" << endl;
	for (int i = 0; i < q; ++i) cout << "A[" << i << "]=" << A[i] << endl;
	//упорядоченый массив
	fsort(A, q);
	// массив после перестановки
	cout << "\n===Массив после упорядочивания модулей  его элементов по убыванию===\n" << endl;
	for (int i = 0; i < q; ++i) cout << "A[" << i << "]=" << A[i] << endl;


	//DOUBLE

	double *B = new double[q];
	cout << "\n !!!Заполните массив вещественных чисел B !!! \n" << endl;
	for (int i = 0; i < q; ++i) cin >> B[i];

	//количество элементов массива, лежащих в диапазоне от А до В.
	double nD, kD;
	cout << "Введите начальное значение диапазона" << endl;
	cin >> nD;
	cout << "Введите конечное значение диапазона" << endl;
	cin >> kD;
	cout << "\n===Количество элементов массива, лежащих в диапазоне от А до В=== \t" << kolel(B, q, nD, kD) << endl;
	//поиск суммы
	cout << "\n===Cумма элементов массива, расположенных после максимального элемента=== \t" << sum(B, q) << endl;
	// массив до перестановки
	cout << "\n===Массив до перестановки===\n" << endl;
	for (int i = 0; i < q; ++i) cout << "B[" << i << "]=" << B[i] << endl;
	//упорядоченый массив
	fsort(B, q);
	// массив после перестановки
	cout << "\n===Массив после упорядочивания модулей  его элементов по убыванию===\n" << endl;
	for (int i = 0; i < q; ++i) cout << "B[" << i << "]=" << B[i] << endl;
	cout << endl;

}
////////////////////////////////////////////////////////////////////////////////

template<class fs> fs fsdvig(fs **A, const int A1, const int A2, int n, int u) {
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
		} return 0;
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
	};

}

void lab4() {
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
	cout << "Приведенный массив натуральных чисел размерностью  " << A1 << " на " << A2 << endl;

	cout << "\nВведите зачения массива A\n" << endl;
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
	//double


	cout << "Приведенный массив вещественных чисел размерностью  " << A1 << " на " << A2 << endl;

	cout << "\nВведите зачения массива В\n" << endl;
	double** B;
	B = new double*[A1];
	for (int i = 0; i < A1; i++)
		B[i] = new double[A2];
	//заполнение
	for (int i = 0; i < A1; i++) {
		for (int j = 0; j < A2; j++) {
			cout << i << "," << j << " элемент ";
			cin >> B[i][j];
		}
	};
	// menu
	cout << "Выберите сдвиг (вправо-1 , вниз-2)" << endl;
	int u;
	cin >> u;
	cout << "Введите количество сдвигов " << endl;
	int n;
	cin >> n;
	fsdvig(A, A1, A2, n, u);
	fsdvig(B, A1, A2, n, u);
	cout << "\nИзмененный массив натуральных чисел\n" << endl;
	for (int i = 0; i < A1; i++) {
		cout << endl;
		for (int j = 0; j < A2; j++) {
			cout << setw(4) << A[i][j];

		}
	};
	cout << "\n Измененный массив вещественных чисел\n" << endl;
	for (int i = 0; i < A1; i++) {
		cout << endl;
		for (int j = 0; j < A2; j++) {
			cout << setw(4) << B[i][j];

		}
	};
	cout << endl;




}



void main() {
	system("color F0");
	setlocale(LC_ALL, "RUS");
	int p;
	cout << "Введите номер лабы(3,4)" << endl;
	cin >> p;
	switch (p) {
	case 3:
		lab3();
		break;
	case 4:
		lab4();
		break;
	};
	system("pause");
}
