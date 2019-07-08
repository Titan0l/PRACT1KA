#include <iostream>
#include <iomanip>
using namespace std;
int Z(double&, double, const double);

int main() {
	system("color F0");
	double xn, x_konech, dx, eps, sum;
	const int MaxIter = 1000;
	setlocale(LC_ALL, "RUS");
	cout << "\t X начальное: "; cin >> xn;
	cout << "\t X коннечное: "; cin >> x_konech;
	cout << "\t dx: "; cin >> dx;
	cout << "\t eps: "; cin >> eps;
	cout << "Значение аргумента" << "\t|\t" << "Значение функции" << "\t|\t" << "Количество просуммированных членов ряда.\n" << '\n';
	unsigned num;
	for (double x = xn; x < x_konech; x += dx) {
		sum = 0;
		num = Z(sum, x, eps);


		if (num > MaxIter) {

			cout << fixed << setw(20) << setprecision(2) << x << "\t|\t" <<
				setw(20) << setprecision(15) << "РЯД РАСХОДИТСЯ !!" << "\t|\t"
				<< setw(6) << num
				<< '\n';
		}

		else cout << fixed << setw(20) << setprecision(2) << x << "\t|\t" <<
			setw(20) << setprecision(15) << sum << "\t|\t"
			<< setw(6) << num
			<< '\n';
	}

	system("pause");
}

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
