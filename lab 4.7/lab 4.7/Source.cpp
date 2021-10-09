#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double xp, xk, dx, x, eps, a, R = 0, S = 0;
	int n;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;

	cout << fixed;
	cout << "----------------------------------" << endl;
	cout << "|" << setw(7) << "x|"
		<< setw(11) << "ln(1-x)|"
		<< setw(11) << "S|"
		<< setw(4) << "n|" << endl;
	cout << "----------------------------------" << endl;

	for (x = xp; x <= xk; x += dx)
	{
		n = 1;
		a = x;
		S = a;
		do
		{
			n++;
			R = x * (n - 1.) / n;
			a *= R;
			S += a;
		} while (abs(a) >= eps);
		S = -S;
		cout << "|" << setw(6) << setprecision(2) << x << "|"
			<< setw(10) << setprecision(4) << log(1 - x) << "|"
			<< setw(10) << setprecision(4) << S << "|"
			<< setw(3) << n << "|" << endl;
	}
	cout << "----------------------------------" << endl;
	return 0;
}