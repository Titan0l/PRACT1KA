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
	cout << "������� ����������� �������" << endl;
	cout << "N=";
	cin >> q;
	int *A = new int[q];

	//INTEGER

	// ���������� ������� 
	cout << "!!!��������� ������ ����������� ����� �!!!" << endl;
	for (int i = 0; i < q; ++i) cin >> A[i];

	//���������� ��������� �������, ������� � ��������� �� � �� �.
	int n, k;
	cout << "������� ��������� �������� ���������" << endl;
	cin >> n;
	cout << "������� �������� �������� ���������" << endl;
	cin >> k;
	cout << "\n===���������� ��������� �������, ������� � ��������� �� � �� �=== \t" << kolel(A, q, n, k) << endl;
	//����� �����
	cout << "\n===C���� ��������� �������, ������������� ����� ������������� ��������=== \t" << sum(A, q) << endl;
	// ������ �� ������������
	cout << "\n===������ �� ������������===\n" << endl;
	for (int i = 0; i < q; ++i) cout << "A[" << i << "]=" << A[i] << endl;
	//������������ ������
	fsort(A, q);
	// ������ ����� ������������
	cout << "\n===������ ����� �������������� �������  ��� ��������� �� ��������===\n" << endl;
	for (int i = 0; i < q; ++i) cout << "A[" << i << "]=" << A[i] << endl;


	//DOUBLE

	double *B = new double[q];
	cout << "\n !!!��������� ������ ������������ ����� B !!! \n" << endl;
	for (int i = 0; i < q; ++i) cin >> B[i];

	//���������� ��������� �������, ������� � ��������� �� � �� �.
	double nD, kD;
	cout << "������� ��������� �������� ���������" << endl;
	cin >> nD;
	cout << "������� �������� �������� ���������" << endl;
	cin >> kD;
	cout << "\n===���������� ��������� �������, ������� � ��������� �� � �� �=== \t" << kolel(B, q, nD, kD) << endl;
	//����� �����
	cout << "\n===C���� ��������� �������, ������������� ����� ������������� ��������=== \t" << sum(B, q) << endl;
	// ������ �� ������������
	cout << "\n===������ �� ������������===\n" << endl;
	for (int i = 0; i < q; ++i) cout << "B[" << i << "]=" << B[i] << endl;
	//������������ ������
	fsort(B, q);
	// ������ ����� ������������
	cout << "\n===������ ����� �������������� �������  ��� ��������� �� ��������===\n" << endl;
	for (int i = 0; i < q; ++i) cout << "B[" << i << "]=" << B[i] << endl;
	cout << endl;

}
////////////////////////////////////////////////////////////////////////////////

template<class fs> fs fsdvig(fs **A, const int A1, const int A2, int n, int u) {
	int R1;
	if (u == 1) {
		int p_cel = n / A2; // ������� ������ 
		int p_ost = n % A2; // ������� �� �������
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
	cout << "������� ����������� ������� ������� " << endl;
	int A1, A2, k;


	do {
		cout << " ������� ���-�� ����� = ";
		cin >> A1;
		if (A1 < 1) k = 0;
		else  k = 1;
	} while (k == 0);

	do {
		cout << "������� ���-�� �������� = ";
		cin >> A2;
		if (A2 < 1) k = 0;
		else  k = 1;
	} while (k == 0);
	cout << "����������� ������ ����������� ����� ������������  " << A1 << " �� " << A2 << endl;

	cout << "\n������� ������� ������� A\n" << endl;
	int** A;
	A = new int*[A1];
	for (int i = 0; i < A1; i++)
		A[i] = new int[A2];
	//����������
	for (int i = 0; i < A1; i++) {
		for (int j = 0; j < A2; j++) {
			cout << i << "," << j << " ������� ";
			cin >> A[i][j];
		}
	};
	//double


	cout << "����������� ������ ������������ ����� ������������  " << A1 << " �� " << A2 << endl;

	cout << "\n������� ������� ������� �\n" << endl;
	double** B;
	B = new double*[A1];
	for (int i = 0; i < A1; i++)
		B[i] = new double[A2];
	//����������
	for (int i = 0; i < A1; i++) {
		for (int j = 0; j < A2; j++) {
			cout << i << "," << j << " ������� ";
			cin >> B[i][j];
		}
	};
	// menu
	cout << "�������� ����� (������-1 , ����-2)" << endl;
	int u;
	cin >> u;
	cout << "������� ���������� ������� " << endl;
	int n;
	cin >> n;
	fsdvig(A, A1, A2, n, u);
	fsdvig(B, A1, A2, n, u);
	cout << "\n���������� ������ ����������� �����\n" << endl;
	for (int i = 0; i < A1; i++) {
		cout << endl;
		for (int j = 0; j < A2; j++) {
			cout << setw(4) << A[i][j];

		}
	};
	cout << "\n ���������� ������ ������������ �����\n" << endl;
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
	cout << "������� ����� ����(3,4)" << endl;
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
