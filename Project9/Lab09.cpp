#include <iostream>
#include <string>
#include <iomanip>
#include "windows.h"
using namespace std;

struct Node
{
	int  kolvo_kom;    //- ���-�� ������;
	int etaz;        //- ����;
	double plachyad;    //- �������;
	char adres[20];    //- �����

	Node* next;    // ��������� �� ��������� ������.
};

void Menu();
Node* addNode(Node* first); // - ���������� ������ � ������;
Node* deleteNode(Node* first); // - �������� ������ �� ��������� ������ �����
void outNode(Node* first); // - ����� ���� ������.
void outNodeNum(Node* first); // ����� ����� ������

int main()
{
	system("color F0");
	setlocale(LC_ALL, "Russian");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	

	////////////////////////////////////////////////////////
	Node* first = new Node;  first->kolvo_kom = 1;  first->etaz = 1; first->plachyad = 25;  strcpy_s(first->adres, 20, "��.������");
	Node* f1 = new Node;     f1->kolvo_kom = 3;     f1->etaz = 2;  f1->plachyad = 50;     strcpy_s(f1->adres, 20, "��.����������");
	Node* f2 = new Node;     f2->kolvo_kom = 4;     f2->etaz = 3;   f2->plachyad = 75; strcpy_s(f2->adres, 20, "��.���������");
	Node* f3 = new Node;     f3->kolvo_kom = 2;     f3->etaz = 4;    f3->plachyad = 100;      strcpy_s(f3->adres, 20, "��.���������");

	first->next = f1;
	f1->next = f2;
	f2->next = f3;
	f3->next = NULL;
	////////////////////////////////////////////////////////
	int k = 5;
	while (k != 6)
	{
		switch (k)
		{
		case 1: first = addNode(first); break;
		case 2: outNode(first); break;
		case 3:	outNodeNum(first); break;
		case 4: first = deleteNode(first); break;
		case 5: Menu(); break;
		case 6: break;
		default: cout << "  ������! ����� �� 1 �� 6.\n";
		}
		cout << "\n������� ������ �����: ";
		cin >> k;
	}
	getchar(); // �����	
	return 0;
}


void Menu()
{
	system("cls");
	cout << "\n";
	cout << "1 - �������� ������\n";
	cout << "2 - ������� ��� ������\n";
	cout << "3 - ������ �� �����\n";
	cout << "4 - ����� � ��������� ����������� ��������( �������� , ���� ������/ ���������� , ���� ��������� ���) \n";
	cout << "5 - �������� �����\n";
	cout << "6 - �����\n";
}

Node* addNode(Node* first)
{
	cout << "______________________________________________\n";
	Node* pv = new Node;
	cout << "������ � ������: \n";
	cout << "������� ���-�� ������ > ";
	cin >> pv->kolvo_kom;
	cout << "������� ���� > ";
	cin >> pv->etaz;
	cout << "������� �������  > ";
	cin >> pv->plachyad;
	cout << "������� ����� > ";
	cin >> pv->adres;
	cout << "\n";
	pv->next = NULL;
	cout << "______________________________________________\n";
	if (first == NULL)
	{
		first = pv;
	}
	else
	{
		Node* p = first;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = pv;
	}
	return first;
}

void outNode(Node* first)
{


	cout << setiosflags(ios::right);
	cout << "_________________________________________________________________\n";
	cout << "������ �� �������:\n";
	cout << "      ���-�� ������  ����    �������      �����           \n";
	cout << "  ----------------- �������� � �������� --------------    \n";

	Node* pv = first;
	while (pv)
	{
		cout << setw(15) << pv->kolvo_kom << setw(10) << pv->etaz << setw(10) << pv->plachyad;
		cout << setw(20) << pv->adres << endl;
		pv = pv->next;
	}
	cout << "_________________________________________________________________\n";
}

void outNodeNum(Node* first) //����� ������ �� �����
{
	int kom, eta;
	double pl;
	char ad[20];
	cout << "_________________________________________________________________\n";
	cout << "\n===������� ������ ������ , ��������� ������===\n";

	cout << "���-�� ������ > ";
	cin >> kom;
	cout << "���� > ";
	cin >> eta;
	cout << "�������  > ";
	cin >> pl;
	cout << "����� > ";
	cin >> ad;
	cout << "\n";
	int count = 0;
	//&& temp->adres==ad
	Node* temp = first;
	while (temp)
	{
		if (temp->etaz == eta && temp->kolvo_kom == kom && temp->plachyad == pl && !strcmp(temp->adres, ad))
		{
			int kom1, eta1;
			double pl1;
			char ad1[20];
			count = 1;
			cout << "===������� ������ ������ �� �����;===\n";
			cout << "���-�� ������ > ";
			cin >> kom1;
			cout << "���� > ";
			cin >> eta1;
			cout << "�������  > ";
			cin >> pl1;
			cout << "����� > ";
			cin >> ad1;
			temp->etaz = eta1;
			temp->kolvo_kom = kom1;
			temp->plachyad = pl1;
			strcpy_s(temp->adres, 20, ad1);
			cout << "\n";

			cout << " ����� �������� �������!\n";
			cout << "______________________________________________\n";
		}
		temp = temp->next;

	}
	if (count == 0) cout << " ����� ������ ���\n";
}

Node* deleteNode(Node* first)
{
	cout << "______________________________________________\n";
	int kom, eta;
	double pl;
	char ad[20];

	cout << "������� ���-�� ������: ";
	cin >> kom;
	cout << "������� ����: ";
	cin >> eta;
	cout << "������� �������: ";
	cin >> pl;
	
	Node* temp = first;
	int k = -1;
	int N = 0;
	while (temp)
	{
		if (temp->etaz == eta && temp->kolvo_kom == kom && ((temp->plachyad <= pl * 1.1) && (temp->plachyad >= 0.9*pl)))
		{
			k = N;

			cout << "_________________________________________________________________\n";
			cout << "������ �� ������:\n";
			cout << "      ���-�� ������  ����    �������      �����           \n";
			cout << "  ----------------- �������� � �������� --------------    \n";
			cout << setw(15) << temp->kolvo_kom << setw(10) << temp->etaz << setw(10) << temp->plachyad;
			cout << setw(20) << temp->adres << endl;
		}
		temp = temp->next;
		N++;
	}
	N--;
	if (k != -1)
	{
		temp = first;
		// ���� ����� ������� 1-� ���� � �� ������������ ��� � ������
		if (k == 0 && N == 0)
		{
			delete first;
			cout << "  �������� ������ �������!\n";
			cout << "______________________________________________\n";
			return NULL;
		}
		// ���� ����� ������� 1-� ���� � �� �� ������������ � ������
		if (k == 0 && N > 0)
		{
			temp = temp->next;
			delete first;
			cout << "  �������� ������ �������!\n";
			cout << "______________________________________________\n";
			return temp;
		}
		// ���� ����� ������� ���� ���-�� � �������� ������, �� �� ����������
		Node* el = first;
		temp = first->next;
		while (temp->next)
		{
			if (temp->etaz == eta)
			{
				el->next = temp->next;
				delete temp;
				cout << "  �������� ������ �������!\n";
				cout << "______________________________________________\n";
				return first;
			}
			el = el->next;
			temp = temp->next;
		}
		// ���� ����� ������� ��������� ����
		el->next = NULL;
		delete temp;
		cout << "  �������� ������ �������!\n";
		cout << "______________________________________________\n";
		return first;
	}
	else
	{
		cout << "______________________________________________\n";
		Node* pv = new Node;

		pv->kolvo_kom = kom;
		pv->etaz = eta;
		pv->plachyad = pl;
		cout << "������� ������ ���.������� ����� ��� ��������� ������ � ������ > ";
		cin >> ad;
		strcpy_s(pv->adres, 20, ad);
		cout << "\n";
		pv->next = NULL;

		if (first == NULL)
		{
			first = pv;
		}
		else
		{
			Node* p = first;
			while (p->next != NULL)
			{
				p = p->next;
			}
			p->next = pv;
		}
		cout << " ����������� ������ �������� � ������!\n";
		cout << "______________________________________________\n";
		return first;
	}
}