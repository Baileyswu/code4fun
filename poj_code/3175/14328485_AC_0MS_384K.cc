#include <stdio.h>  
#include <math.h>  
double A, P, B;  
int L;  
 __inline double sqr(double i){  
    return i * i;  
}  
double pow_1[] = { 1, 1e-1, 1e-2, 1e-3, 1e-4, 1e-5, 1e-6, 1e-7, 1e-8, 1e-9, 1e-10 };  
int main(){  
    double i, j;  
    int d;  
    scanf("%d%d", &L, &d);  
    P = pow_1[L];  
    B = P * d;  
    for (A = 1; ; A++) {  
        i = (__int64)sqr(A + B) + 1;  
        j = sqr(A + B + P);  
        if (j > i)  
            break;  
    }  
    printf("%I64d\n", (__int64)i);  
	return 0;  
}  