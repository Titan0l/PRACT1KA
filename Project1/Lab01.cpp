#include <math.h>
#include<cmath>
#include <iostream>
using namespace std;

void main() {


	setlocale(LC_ALL, "RUS");
	double a, z1, z2, b;
	cout << "¬ведите a" << endl;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	z1 = ((sin(a) + cos(2 * b - a)) / (cos(a) - sin(2 * b - a)));
	z2 = ((1 + sin(2 * b)) / (cos(2 * b)));
	cout << "z1= " << z1 << endl;
	cout << "z2= " << z2 << endl;
	system("pause");
}