#include <stdio.h>
#include <string.h>
int main(){
	char com[20];
	while(~scanf("%s", com)){
		int len = strlen(com);
		if(len > 10){
			printf("-1\n");
		}
		int i, p, sum = 0, v = 0;
		for(i = 0;i < 10;i++){
			if(com[i] == '?')
				p = 10-i;
			else if(com[i] == 'X'){
				if(i == 9)
					sum += 10;
				else
					printf("-1\n");
			}
			else
				sum += (com[i]-'0')*(10-i);
		}
		for(i = 0;i < 11;i++)
			if((sum+p*i)%11==0){
				v = 1;
				break;
			}
		if(!v){
			printf("-1\n");
			continue;
		}
		if(i < 10){
			printf("%d\n", i);
			continue;
		}
		if(p==1)
			printf("X\n");
		else
			printf("-1\n");

	}
	return 0;
}