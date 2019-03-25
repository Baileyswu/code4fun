#include <bits/stdc++.h>
using namespace std;
#define N 9
int fact[N+1] = {1,1};
int cantor(string s) {
	int ret = 0;
	for(int i = 0;i < N;i++) {
		int ai = s[i] - '0' - 1;
		for(int j = 0;j < i;j++)
			if(s[j] < s[i])
				ai--;
		ret += ai * fact[N-1-i];
	}
	return ret;
}
string reverse_cantor(int p) {
	string ret = "";
	for(int i = 0;i < N;i++) {
		int u = p / fact[N-1-i] + 1;
		p = p % fact[N-1-i];
		for(int j = 0;j < i;j++)
			if(ret[j] <= '0'+u)
				u++;
		ret += '0'+u;
	}
	cout << ret << endl;
	return ret;
}
int main() {
	for(int i = 2;i <= N;i++)
		fact[i] = fact[i-1] * i;
	assert(cantor("123456789") == 0);
	assert(cantor("987654321") == fact[9]-1);
	assert(reverse_cantor(1) == "123456798");
	assert(reverse_cantor(fact[9]-2) == "987654312");
}