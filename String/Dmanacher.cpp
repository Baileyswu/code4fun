
int id, m, ans;id = m = ans = 0;for(int i = 1;i < len;i++){	if(i < id) p[i] = 1;	else p[i] = min(p[2*id-i], m-i);	while(a[i+p[i]] == a[i-p[i]])		p[i]++;	ans = max(ans, p[i]);	if(i > id){		id = i;		m = p[i] + i;	}}
