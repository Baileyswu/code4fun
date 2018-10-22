#include <stdio.h>
#include <string.h>
int main()
{
	int k;
	while(scanf("%d", &k), k)
	{
		char cipher[310], plain[310];
		int cico[310], plco[310];
		scanf("%s", cipher);
		int len = strlen(cipher), i;
		for(i = 0;i < len;i++)
		{
			int x = cipher[i]-'a'+1;
			switch(x)
			{
				case '.'-'a'+1:cico[i] = 27;break;
				case '_'-'a'+1:cico[i] = 0;break;
				default:cico[i] = x;break;
			}
		}
		for(i = 0;i < len;i++)
			plco[k*i%len] = (cico[i]+i+28)%28;
		for(i = 0;i < len;i++)
			switch(plco[i])
			{
				case 27:plain[i] = '.';break;
				case 0:plain[i] = '_';break;
				default:plain[i] = 'a'-1+plco[i];break;
			}
		plain[len] = '\0';
		printf("%s\n", plain);
	}
	return 0;
}