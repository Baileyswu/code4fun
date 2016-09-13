int gauss() {
    int i, j, k, id;
    for(i = 0, j = 0; i < m,j < n;) {
        id = i;
        for(k = i+1; k < m; k++)
            if(abs(a[k][j]) > abs(a[id][j]))
                id = k;
        if(id != i) {
            for(k = j; k < n; k++)
                swap(a[i][k],a[id][k]);
        }//使a[id][k](i<=k<=n)是最 大的,并把这行移到第i行
        if(a[i][j] == 0) { j++; continue; }//最大的a[id][k]=0
        for(k = i+1; k < m; k++) {//线性变换化0
            if(a[k][j] == 0) continue;
            for(int l = j; l < n; l++)
                a[k][l] = a[k][l] ^ a[i][l];
        }
        i++,j++;
    }
    for(int k = i; k < m; k++) if(a[k][n] != 0) {
           return -1; //根据前面说的，无解
    }
    return n-i;
}
