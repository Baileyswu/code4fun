#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;
int nCaseNum = 0, nNum;
queue <long>nQue[1001];
queue <int>nS;
int nM[1000000];
bool nFlag[1001];

int init()
{
	for(int i = 0;i < nNum;i++)
	{
		nFlag[i] = false;
		while(!nQue[i].empty())
			nQue[i].pop();
	}
	while(!nS.empty())
		nS.pop();
	return 0;
}
int input()
{
	int nElem,elemNum;
	for(int i = 0;i < nNum;i++)
	{
		cin >> nElem;
		for(int j = 0;j < nElem;j++)
		{
			cin >> elemNum;
			nM[elemNum] = i;
		}
	}
	return 0;
}
int solve()
{
	cout << "Scenario #" << ++nCaseNum << endl;
	string command;
	long element;
	while(cin >> command, command != "STOP")
	{
		if(command == "ENQUEUE")
		{
			cin >> element;
			if(!nFlag[nM[element]])
			{
				nFlag[nM[element]] = true;
				nS.push(nM[element]);
			}
			nQue[nM[element]].push(element);
		}
		else if(command == "DEQUEUE")
		{
			int nId = nS.front();
			cout << nQue[nId].front() << endl;
			nQue[nId].pop();
			if(nQue[nId].empty())
			{
				nFlag[nId] = false;
				nS.pop();
			}
		}
	}
	cout << endl;
	return 0;
}
int main()
{
	while(cin >> nNum, nNum)
	{
		init();
		input();
		solve();
	}
	return 0;
}