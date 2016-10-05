int find_min_max(bool ifmin){//1：min 0：max s开始下标=1 返回字符串下标
	int i,j,k;
	i=1;j=2;k=0;
	while (j<=l&&i<=l&&k<l){
		if (s[i+k]==s[j+k]){ // 注意这里可以自身扩展，或者用mod
			k++;
			if (k==l)break;
		}
		else if (s[i+k]<s[j+k]){
			if (ifmin)
				j+=k+1;
			else i+=k+1;
			k=0;
		}
		else {
			if (ifmin)
				i+=k+1;
			else j+=k+1;
			k=0;
		}
		if (i==j){
			j++;
		}
	}
	return min (i,j);
}
