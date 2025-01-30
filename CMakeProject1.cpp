// CMakeProject1.cpp: определяет точку входа для приложения.
//

#include "CMakeProject1.h"

using namespace std;

// 
float pow(float base, unsigned int exp) {
	float result = base;
	for (unsigned i = 0; i < exp; i++)
	{
		result *= base;       // ymnojaem 
	}

	return result;
}

// funkzui proveraet blizki li dva chisla
bool is_close(float a, float b) {
	if (isinf(a) && isinf(b))
	{
		return true;
	}
	if (isnan(a) && isnan(b))
	{
		return true;
	}
	return abs(a - b) < numeric_limits<float>::epsilon(); // modul dvyh chisel nahodidca ochen mal
}
// test
bool test_pow(float base, unsigned exp) {
	cout << "testing pow :" << base << " " << "|" << " " << exp << "\t";

	float expected = pow(base, exp);
	float actval = pow(base, exp);

	if (is_close(expected,actval))
	{
		cout << "ok\n";
		return true;
	}
	else
	{
		cout << "fail\n";
		cout << "expendet:" << expected << "actval:" << actval << "\t";
		
		return false;
	}
}



int main()
{
	bool all_success = true;

	all_success &= test_pow(2.0, 3);
	all_success &= test_pow(1.0, 1);
	all_success &= test_pow(5.0, 0);
	all_success &= test_pow(-5.0, 2);
	all_success &= test_pow(-5.0, 3);
	all_success &= test_pow(0.0, 2);
	all_success &= test_pow(1.1e+5, 10);
	all_success &= test_pow(1e-5, 10);
	all_success &= test_pow(INFINITY, 2);
	all_success &= test_pow(NAN, 2);

	return all_success;

}
 