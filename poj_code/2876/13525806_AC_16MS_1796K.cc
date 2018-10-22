#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, i;
	string p, s;
	while(cin >> N)
	{
		p = '-';
		for(i = 0; i < N; ++i)
		{
			s.assign(p.size(), ' ');
			p += s + p;
		}
		cout << p << endl;
	}
	return 0;
}