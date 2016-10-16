#define M 100000
int pre[M], n, m;
void set(string p)
{
	memset(pre, 0, sizeof(pre));
	pre[0] = -1;
	int m = p.length();
	for(int i = 1;i < m;i++)
	{
		int j = pre[i-1];
		while(j >= 0 && p[j+1] != p[i])
			j = pre[j];
		pre[i] = p[j+1] == p[i] ? j+1:-1;
	}
}
int KMP(string s, string p)
{
	set(p);
	int j = -1, r = 0;
	int n = s.length(), m = p.length();
	for(int i = 0;i < n;i++)
	{
		while(j >= 0 && s[i] != p[j+1])
			j = pre[j];
		if(s[i] == p[j+1])
			j++;
		if(j == m-1)
		{
			r++;
			j = pre[j];
		}
	}
	return r;
}
