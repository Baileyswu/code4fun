#include <bits/stdc++.h>
#include "big.h"
using namespace std;
const int SUFF = (int)1e5;
struct Float
{
	Big value;
	string str;
	int expo;
	bool sign;
	Float(){}
	Float(string &s) {
		sign = true;
		int len = (int) s.length();
		int dot = (int) s.find(".");
		int e = (int) s.find("e");
		// printf(". %d e %d\n", dot, e);
		if(e == -1)
			e = (int) s.find("E");
		if(dot != -1 && e != -1) {  // xx.xxexx
			str = s.substr(0, dot) + s.substr(dot+1, e-dot-1);
			expo = s_to_n(s.substr(e+1))-(e-dot-1);
		} else if(dot == -1 && e == -1){  // xx
			str = s;
			expo = 0;
		} else if(dot != -1) { // xx.xx
			str = s.substr(0, dot) + s.substr(dot+1);
			expo = -(len-dot-1);
		} else {  // xxexx
			str = s.substr(0, e);
			expo = s_to_n(s.substr(e+1));
		}
		int i = 0;
		// cout << str << "====" << endl;
		while(str[i] == '0' && i != (int)str.length()-1) i++;
		str = str.substr(i);  // 000x
		remove_tailzero();
	}
	void remove_tailzero() {
		int len = (int) str.length();
		int i = len-1;
		while(str[i] == '0' && i != 0) i--;
		str = str.substr(0, i + 1);
		expo += len-i-1;
		value = from_str(str);
	}
	void add_tailzero(int r) {
		expo -= r;
		if(str != "0")
			for(int i = 0;i < r;i++)
				str += "0";
		value = from_str(str);
	}
	int len() {
		if(str == "0")
			return 0;
		return str.length() + expo;
	}
	void simplify() {
		str = to_str(value);
		remove_tailzero();
		if(str.length() > SUFF) {
			string temp = str.substr(0, SUFF);
			expo += str.length() - SUFF;
			value = from_str(temp);
			if(str[SUFF] > '4') {
				Big a{1};
				value = value + a;
			}
			str = to_str(value);
			remove_tailzero();
		}
	}
	int scilen() {
		int len = str.length(), ep = expo;
		if(str.length() > 1) { // add dot
			len++;
			ep += str.length() - 1;
		}
		if(ep == 0) return len;
		if(ep < 0) {
			len++;
			ep = -ep;  // add -
		}
		while(ep) {
			len++;
			ep /= 10;
		}
		return len + 1; // add e
	}
	int orilen() {
		if(expo >= 0) return str.length() + expo;  // x000
		if(expo > -(int)str.length()) return str.length() + 1; // xx.xx
		return -expo + 2; // 0.00xx
	}
	void compare_len() {
		// cout << "compare len: " << scilen() << " " << orilen() << endl;
		if(scilen() <= orilen()) {
			if(str.length() > 1) {
				expo += str.length() - 1;
				str = str.substr(0, 1) + "." + str.substr(1);
			}
		} else {
			if(expo >= 0) {
				for(int i = 0;i < expo;i++)
					str += "0";
			} else if (expo > -(int)str.length()) {
				str = str.substr(0, str.length() + expo) + "." + str.substr(str.length() + expo);
			} else {
				string front = "0.";
				for(int i = 0;i < -expo-str.length();i++)
					front += "0";
				str = front + str;
			}
			expo = 0;
		}
	}
};
ostream& operator<<(ostream &out, const Float &f) {
	if(!f.sign)
		cout << "-";
	// cout << f.value << "e" << f.expo;
	cout << f.str;
	if(f.str == "0")
		return out;
	if(f.expo)
		cout << "e" << f.expo;
	return out;
}
int align(Float &a, Float &b) {
	cout << "=(" << a << ")-(" << b << ")" << endl;
	int delta = a.len() - b.len();
	// cout << "delta = " << delta << endl;
	if(abs(delta) > SUFF+10)
		return delta > 0 ? 1 : -1;
	int move = a.expo - b.expo;
	if(move == 0) return 0;
	move > 0 ? a.add_tailzero(move) : b.add_tailzero(-move);
	cout << "=(" << a << ")-(" << b << ")" << endl;
	return 0;
}
Float operator - (Float &a, Float &b) {
	Float c;
	int flag = align(a, b);
	if(flag) {
		c = flag > 0 ? a : b;
		c.sign = flag > 0 ? true : false;
		return c;
	}
	if(a.value < b.value) {
		c.expo = b.expo;
		c.value = b.value - a.value;
		c.sign = false;
	} else {
		c.expo = a.expo;
		c.value = a.value - b.value;
		c.sign = true;
	}
	cout << "=" << c << endl;
	c.simplify();
	return c;
}
int main() {
	string s1, s2;
	while(cin >> s1 >> s2) {
		Float f1(s1), f2(s2);
		Float ans = f2 - f1;
		cout << "=" << ans << endl;
		ans.compare_len();
		cout << "=" << ans << endl;
	}
	return 0;
}
