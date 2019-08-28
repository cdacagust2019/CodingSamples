#include <iostream>
#include <cmath>

using namespace std;

double Income(double invest, short duration, float rate)
{
	double amount = invest * pow(1 + rate / 100, duration);
	return amount - invest;
}

//call to this function may be replaced by its body (implementation)
inline double Income(double invest, short duration)
{
	return Income(invest, duration, duration < 3 ? 4 : 5);
}

int main(void)
{
	double p;
	short n;

	cout << "Enter investment and duration: ";
	cin >> p >> n;

	cout << "Income in fixed-deposit: "
		 << Income(p, n, 6)
		 << endl;

	cout << "Income in savings-account: "
		 << Income(p, n) //Income(p, n, n < 3 ? 4 : 5)
		 << endl;
}

