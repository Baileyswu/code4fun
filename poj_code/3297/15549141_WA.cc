#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#define N 10010
using namespace std;
map <string, int> stu;
map <string, set<int> > pro;
vector< pair <int, string> >ans;
int a[N], n, m;
string str, book;
void init(){
	stu.clear();
	book.clear();
	pro.clear();
	n = m = 0;
	memset(a, 0, sizeof(a));
}
// pair <int, string>
bool cmp(const pair<int, string> &lhs, const pair<int, string> &rhs)
{
	if(rhs.first == lhs.first) return lhs.second < rhs.second;
    return lhs.first > rhs.first;
}
void solve(){
	std::map<string, set<int> >::iterator it;
	std::set<int>::iterator q;
	for(it = pro.begin(); it != pro.end();it++){
		// cout << it->first << " ";
		int cnt = 0;
		for(q = it->second.begin(); q != it->second.end();q++)
			if(a[*q] == 1) cnt++;
		// cout << cnt << endl;
		ans.push_back(make_pair(cnt, it->first));
	}
	sort(ans.begin(), ans.end(), cmp);
	// sort(ans.begin(), ans.end(), greater<pair <int, string> >());
	vector< pair <int, string> >::iterator ak;
	for(ak = ans.begin();ak != ans.end();ak++)
		cout << ak->second << " " << ak->first << endl;
}
int main()
{
	init();
	while(getline(cin, str)){
		if(str == "0") break;
		if(str == "1") {
			solve();
			init();
			continue;
		}
		if(str[0] >= 'A' && str[0] <= 'Z'){
			book = str;
			pro[book].insert(-1);
		}
		else{
			map <string, int >::iterator iter = stu.find(str);
			if(iter == stu.end())
				stu[str] = m++;
			std::set<int>::iterator q = pro[book].find(stu[str]);
			if(q == pro[book].end()){
				a[stu[str]]++;
				pro[book].insert(stu[str]);
			}
		}
	}
	return 0;
}