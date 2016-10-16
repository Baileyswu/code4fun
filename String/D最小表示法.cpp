char str[N];
int solve()
{
	int len = strlen(str), i, j, k;
	for(int i = len;i < len*2;i++)
		str[i] = str[i-len];
	for(i = 0, j = 1;j < len;)
	{
		for(k = 0;k < len;k++)
			if(str[i+k] != str[j+k])
				break;
		if(k >= len)
			return i+1;
		if(str[i+k] < str[j+k])
			j += k+1;
		else if(str[i+k] > str[j+k])
		{
			int t = j;
			j = max(i+k, j)+1;
			i = t;
		}
	}
	return i+1;
}
