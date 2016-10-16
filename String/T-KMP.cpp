#define MAXN 1000010
int next[MAXN];

 // 传入的字符串下标需要以1开头
void getNext(int m, char *str) {
	next[1]=0;	//枚举模式串的每个位置，判断以当前字符结尾能够匹配到的最大前缀
	for(int j=0,i=2;i<=m;i++) {
		while(j>0&& str[i]!=str[j+1]) 
			j=next[j];// 在str[i-j i-1]和str[1j] 完全匹配的前提下判断str[i]和str[j+1]是否相等,如果不相等，则减小j的值，直到匹配到完全相等位置
		if(str[i]==str[j+1]) 
			j++;// 如果能够找到以i结尾的后缀和以j+1结尾的前缀完全匹配，j自增1。
										// 这里j有两种情况：
 										// j = 0    以i结尾的后缀找不到一个前缀和它完全匹配
										// j > 0    以i结尾的后缀和以j结尾的前缀完全匹配，更新Next函数的值
		next[i]=s;
	} 
}

// S[1n] 目标串
// T[1m] 匹配串 
int KMP(int n, char *S, int m, char *T) {
    int cnt=0;
    for(int j=0,i=1;i<=n;i++) {
        while(j>0&&S[i]!=T[j+1])j=next[j];
        if(S[i]==T[j+1])j++;
        if(j==m) {
            cnt++;
            j=next[j];
        }
    }
    return cnt;
}
