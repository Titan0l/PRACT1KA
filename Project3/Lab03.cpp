#include <iostream>
#include <math.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	int q;

	cout << "������� ����������� �������" << endl;
	cout << "N=";
	cin >> q;
	int *A = new int[q];

	// ���������� ������� 

	cout << "��������� ������ �" << endl;
	for (int i = 0; i < q; ++i) cin >> A[i];


	//���������� ��������� �������, ������� � ��������� �� � �� �.
	int n, k;
	int kol_vo = 0;
	cout << "������� ��������� �������� ���������" << endl;
	cin >> n;
	cout << "������� �������� �������� ���������" << endl;
	cin >> k;

	for (int i = 0; i < q; ++i) {
		if ((A[i] >= n) && (A[i] <= k)) ++kol_vo;
	};


	cout << "\n===���������� ��������� �������, ������� � ��������� �� � �� �=== \t" << kol_vo << endl;

	//����� �����
	int sumotr = 0;
	int max = A[0];
	int maxnum = 0;
	for (int i = 1; i < q; ++i)	if (A[i] > max) { maxnum = i; max = A[i]; };
	++maxnum;
	for (; maxnum < q; ++maxnum)  sumotr += A[maxnum];

	cout << "\n===C���� ��������� �������, ������������� ����� ������������� ��������=== \t" << sumotr << endl;
	cout << "���� ������� :" << max << endl;
	////////

		// ������ �� ������������

	cout << "\n===������ �� ������������===\n" << endl;
	for (int i = 0; i < q; ++i) cout << "A[" << i << "]=" << A[i] << endl;


	//������������ ������

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
	// ������ ����� ������������
	cout << "\n===������ ����� �������������� �������  ��� ��������� �� ��������===\n" << endl;
	for (int i = 0; i < q; ++i) cout << "A[" << i << "]=" << A[i] << endl;

	cout << endl;
	system("pause");
	return 0;
}
