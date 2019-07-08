#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;


////////////////////////////////////////////////////////////////////////////////
double z1(double a, double b) { return   ((sin(a) + cos(2 * b - a)) / (cos(a) - sin(2 * b - a))); };
double z2(double a, double b) { return  ((1 + sin(2 * b)) / (cos(2 * b))); };

void lab1() {


	setlocale(LC_ALL, "RUS");
	double a, b;
	cout << "Введите a" << endl;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "z1= " << z1(a, b) << endl;
	cout << "z2= " << z2(a, b) << endl;

}
////////////////////////////////////////////////////////////////////////////////
int Z(double& sum, double x, const double eps) {
	unsigned int n = 1;
	double member;
	do {
		member = pow(x, n) / (pow(2, n)*n);

		if (n % 2 == 0) sum -= member;
		else sum += member;
		++n;
	} while (fabs(member) > eps);
	return n;
}

void lab2() {
	double xn, x_konech, dx, eps, sum;
	const int MaxIter = 1000;
	cout << "\t X начальное: "; cin >> xn;
	cout << "\t X коннечное: "; cin >> x_konech;
	cout << "\t dx: "; cin >> dx;
	cout << "\t eps: "; cin >> eps;

	unsigned num;
	for (double x = xn; x < x_konech; x += dx) {
		sum = 0;
		num = Z(sum, x, eps);


		if (num > MaxIter) {

			cout << fixed << setw(6) << setprecision(2) << x << "\t|\t" <<
				setw(20) << setprecision(15) << "РЯД РАСХОДИТСЯ !!" << "\t|\t"
				<< setw(6) << num
				<< '\n';
		}

		else cout << fixed << setw(6) << setprecision(2) << x << "\t|\t" <<
			setw(20) << setprecision(15) << sum << "\t|\t"
			<< setw(6) << num
			<< '\n';
	}
}
////////////////////////////////////////////////////////////////////////////////

int kolel(int *A, const int q, int n, int k) {
	int kol_vo = 0;
	for (int i = 0; i < q; ++i) {
		if ((A[i] >= n) && (A[i] <= k)) ++kol_vo;
	}; return kol_vo;
}

int sum(int *A, const int q) {
	int sumotr = 0;
	int max = A[0];
	int maxnum = 0;
	for (int i = 1; i < q; ++i)	if (A[i] > max) { maxnum = i; max = A[i]; };
	++maxnum;
	for (; maxnum < q; ++maxnum)  sumotr += A[maxnum];
	return sumotr;
}
void fsort(int *A, const int q) {
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
}
void lab3() {
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

	cout << endl;

}
////////////////////////////////////////////////////////////////////////////////

void fsdvig(int **A, const int A1, const int A2, int n, int u) {
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
	cout << "Введите количество сдвигов " << endl;
	int n;
	cin >> n;
	fsdvig(A, A1, A2, n, u);
	for (int i = 0; i < A1; i++) {
		cout << endl;
		for (int j = 0; j < A2; j++) {
			cout << " " << A[i][j];

		}
	};
	cout << endl;
}
////////////////////////////////////////////////////////////////////////////////
void zamen(char *line) {
	int flag = 0;
	char * p = line;
	for (; *p; ++p) {
		if ((isspace(*p) || ispunct(*p))) flag = 0; // пробел или переход на новую строку

		else {
			if (!flag && strchr("AEIOUY", toupper(*p)))
				*p = toupper(*p); // заменяет на прописную букву
			flag = 1;
		}
	}
}

int lab5() {
	const int len = 81;

	char line[len];

	ifstream fin("text.txt");
	if (!fin) {
		cout << "Ошибка открытия файла." << endl; return 1;
	}

	while (fin.getline(line, len)) {


		zamen(line);
		cout << line << endl;

	}
}
////////////////////////////////////////////////////////////////////////////////
struct NOTE {
	string fio;
	int phone;
	int date[2];
};


void Sort(NOTE *studs, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (studs[i].fio > studs[j].fio) {
				NOTE buf = studs[i];
				studs[i] = studs[j];
				studs[j] = buf;
			}
		}
	}
}

void lab6() {
	setlocale(LC_ALL, "rus");
	cout << "Введите количество записей: ";
	int n;
	cin >> n;
	NOTE *nt = new NOTE[n];
	for (int i = 0; i != n; i++) {
		cout << "Введите ФИО" << endl;
		cin >> nt[i].fio;
		cout << "Введите телефон" << endl;
		cin >> nt[i].phone;
		cout << "Введите день, месяц, год рождения " << endl;
		cin >> nt[i].date[0];
		cin >> nt[i].date[1];
		cin >> nt[i].date[2];

	}
	cout << endl;


	Sort(nt, n);
	cout << "\n ===Сортированный список по алфавиту=== \n " << endl;
	for (int i = 0; i < n; i++) {

		cout << nt[i].fio << endl;
		cout << nt[i].phone << endl;
		cout << nt[i].date[0] << endl;
		cout << nt[i].date[1] << endl;
		cout << nt[i].date[2] << endl;
		cout << endl;

	}
	cout << endl;
	int k;
	cout << " Введите месяц рождения: "; cin >> k;
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (k == nt[i].date[1]) {
			flag += 1;
			if (flag == 1)cout << "\n ===Люди , родившиеся в " << k << " месяце=== \n" << endl;
			cout << nt[i].fio << endl;
			cout << nt[i].phone << endl;
			cout << nt[i].date[0] << endl;
			cout << nt[i].date[1] << endl;
			cout << nt[i].date[2] << endl;
			cout << endl;
		}



	}
	if (flag == 0) cout << "\n Людей с таким месяцем рождения нет! \n" << endl;
	system("pause");
	delete[]nt;
}





////////////////////////////////////////////////////////////////////////////////
void main() {
	system("color F0");
	setlocale(LC_ALL, "RUS");
	int p;
	cout << "Введите номер лабы" << endl;
	cin >> p;
	switch (p) {
	case 1:
		lab1();
		break;
	case 2:
		lab2();
		break;
	case 3:
		lab3();
		break;
	case 4:
		lab4();
		break;
	case 5:
		lab5();
		break;
	case 6:
		lab6();
		break;
	};
	system("pause");
}
