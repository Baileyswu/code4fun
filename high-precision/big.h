using namespace std;

const int D = (int) 1e8;
const int Dn = 8;
typedef vector<int> Big;
ostream& operator<<(ostream &out, const Big &a) {
	string s;
	if (a.empty()) {
		cout << "0";
		return out;
	}
	cout << a.back();
	for (int i = (int) a.size() - 2; i >= 0; -- i) {
		cout << setw(Dn) << setfill('0') << a[i];
	}
	return out;
}
Big operator + (const Big &a, const Big &b) {
	Big c (max(a.size(), b.size()) + 1, 0);
	for (int i = 0; i < (int) c.size(); ++ i) {
		if (i < (int) a.size()) c[i] += a[i];
		if (i < (int) b.size()) c[i] += b[i];
		if (c[i] >= D) {
			c[i + 1] ++;
			c[i] -= D;
		}
	}
	if (c.back() == 0) c.pop_back();
	return c;
}
Big operator * (const Big &a, const Big &b) {
	Big c (a.size() + b.size(), 0);
	for (int i = 0; i < (int) a.size(); ++ i) {
		for (int j = 0; j < (int) b.size(); ++ j) {
			long long tmp = c[i + j] + 1LL * a[i] * b[j];
			c[i + j] = tmp % D;
			c[i + j + 1] += tmp / D;
		}
	}
	while (!c.empty() && c.back() == 0) c.pop_back();
	return c;
}
Big operator - (const Big &a, const Big &b) {
	// cout << "op=" << a << "-" << b << endl;
	Big c (max(a.size(), b.size()), 0);
	for (int i = 0; i < (int) c.size(); ++ i) {
		if (i < (int) a.size()) c[i] += a[i];
		if (i < (int) b.size()) c[i] -= b[i];
		if (c[i] < 0) {
			c[i + 1] --;
			c[i] += D;
		}
	}
	while (!c.empty() && c.back() == 0) c.pop_back();
	return c;
}
bool operator < (const Big &a, const Big &b) {
	if(a.size() != b.size()) return a.size() < b.size();
	for (int i = (int) a.size() - 1; i >= 0; -- i) {
		if (a[i] != b[i]) return a[i] < b[i];
	}
	return false;
}
Big operator % (const Big &a, const Big &b) { // only for binary mod
	Big c{0}, t(1);
	for(int i = (int)a.size()-1;i >= 0;i--) {
		if(a[i] == 0)
			c.insert(c.begin(), 1, 0);
		else
			c.insert(c.begin(), 1, 1);
		if (!c.empty() && c.back() == 0) c.pop_back();
		if(c < b) continue;
		c = c - b;
	}
	return c;
}
Big from_str(const string s) {
	int n = (int) s.length();
	Big a;
	for (int i = n - 1; i >= 0; i -= Dn) {
		int num = 0;
		for (int j = min(Dn-1, i); j >= 0; -- j) {
			num = num * 10 + (s[i - j] - '0');
		}
		a.push_back(num);
	}
	while (!a.empty() && a.back() == 0) a.pop_back();
	return a;
}
string to_str(const Big &a) {
	string s = "";
	if(a.empty()) {
		s = "0";
		return s;
	}
	for(int i = 0;i < (int)a.size();i++) {
		int t = a[i];
		for(int j = 0;j < Dn;j++) {
			char c = '0' + t % 10;
			s = c + s;
			t /= 10;
		}
	}
	int i = 0;
	while(s[i] == '0' && i != (int)s.length()-1) i++;
	return s.substr(i);
}
int s_to_n(const string &s) {
	int ret = 0, len = (int) s.length();
	for(int i = 0;i < len;i++) {
		ret *= 10;
		ret += s[i]-'0';
	}
	return ret;
}
