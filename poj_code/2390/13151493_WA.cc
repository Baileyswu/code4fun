#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double r, m;
	int y;
	cin >> r >> m >> y;
	r = 1 + r / 100;
	m = pow(r, y) * m;
	cout << floor(m) << endl;
	return 0;
}