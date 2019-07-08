#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
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

int main() {
	system("color F0");
	setlocale(LC_ALL, "rus");
	cout << "������� ���������� �������: ";
	int n;
	cin >> n;
	NOTE *nt = new NOTE[n];
	for (int i = 0; i != n; i++) {
		cout << "������� ���" << endl;
		cin >> nt[i].fio;
		cout << "������� �������" << endl;
		cin >> nt[i].phone;
		cout << "������� ����, �����, ��� �������� " << endl;
		cin >> nt[i].date[0];
		cin >> nt[i].date[1];
		cin >> nt[i].date[2];

	}
	cout << endl;


	Sort(nt, n);
	cout << "\n ===������������� ������ �� ��������=== \n " << endl;
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
	cout << " ������� ����� ��������: "; cin >> k;
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (k == nt[i].date[1]) {
			flag += 1;
			if (flag == 1)cout << "\n ===���� , ���������� � " << k << " ������=== \n" << endl;
			cout << nt[i].fio << endl;
			cout << nt[i].phone << endl;
			cout << nt[i].date[0] << endl;
			cout << nt[i].date[1] << endl;
			cout << nt[i].date[2] << endl;
			cout << endl;
		}



	}
	if (flag == 0) cout << "\n ����� � ����� ������� �������� ���! \n" << endl;
	system("pause");
	delete[]nt;

	return 0;
}