#include <iostream>
#include <math.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	int q;

	cout << "Введите размерность массива" << endl;
	cout << "N=";
	cin >> q;
	int *A = new int[q];

	// заполнение массива 

	cout << "Заполните массив А" << endl;
	for (int i = 0; i < q; ++i) cin >> A[i];


	//количество элементов массива, лежащих в диапазоне от А до В.
	int n, k;
	int kol_vo = 0;
	cout << "Введите начальное значение диапазона" << endl;
	cin >> n;
	cout << "Введите конечное значение диапазона" << endl;
	cin >> k;

	for (int i = 0; i < q; ++i) {
		if ((A[i] >= n) && (A[i] <= k)) ++kol_vo;
	};


	cout << "\n===Количество элементов массива, лежащих в диапазоне от А до В=== \t" << kol_vo << endl;

	//поиск суммы
	int sumotr = 0;
	int max = A[0];
	int maxnum = 0;
	for (int i = 1; i < q; ++i)	if (A[i] > max) { maxnum = i; max = A[i]; };
	++maxnum;
	for (; maxnum < q; ++maxnum)  sumotr += A[maxnum];

	cout << "\n===Cумма элементов массива, расположенных после максимального элемента=== \t" << sumotr << endl;
	cout << "Макс элемент :" << max << endl;
	////////

		// массив до перестановки

	cout << "\n===Массив до перестановки===\n" << endl;
	for (int i = 0; i < q; ++i) cout << "A[" << i << "]=" << A[i] << endl;


	//упорядоченый массив

	int R;
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < q - i - 1; j++) {
			if (fabs(A[j]) < fabs(A[j + 1])) {

				R = A[j];
				A[j] = A[j + 1];
				A[j + 1] = R;

			}
		}
	};
	// массив после перестановки
	cout << "\n===Массив после упорядочивания модулей  его элементов по убыванию===\n" << endl;
	for (int i = 0; i < q; ++i) cout << "A[" << i << "]=" << A[i] << endl;

	cout << endl;
	system("pause");
	return 0;
}
