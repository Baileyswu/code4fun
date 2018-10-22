#include<stdio.h>
#include<string.h>
int order(char command[10])
{
    if(strcmp(command,"VISIT")==0)
	return 1;
    if(strcmp(command,"BACK")==0)
	return 2;
    if(strcmp(command,"FORWARD")==0)
	return 3;
    if(strcmp(command,"QUIT")==0)
	return 4;
    return 0;
}
int main()
{  
    char url[101][71]={"http://www.acm.org/"},command[10];
    int top=0,view=0;
    while(~scanf("%s",command))
    {
	int n=order(command);
	switch(n)
	{
	    case 1:view++;
		   top=view;
		   scanf("%s",url[top]);
		   printf("%s\n",url[top]);
		   break;
	    case 2:view--;
		   if(view>=0)
		       printf("%s\n",url[view]);
		   else
		       printf("Ignored\n"),view++;
		   break;
	    case 3:view++;
		   if(view>top)
			printf("Ignored\n"),view--;
		   else
			printf("%s\n",url[view]);
		   break;
	    case 4:return 0;
	}
    }
    return 0;
}

