
//NAIVE STRING MATCHING
#include <stdio.h>
void naive(char s[],char pat[],int m,int n)
{
	int c,i,j;
	for(i=0;i<m-n+1;++i)
	{
		c=0;
		for(j=0;j<n;++j)
		{
			if(pat[j]==s[i+j])
				c++;
		}
		if(c==n)
		{
			printf("Pattern Found at %d\n",i+1);
		}
	}
}
int main()
{
	char s[100],pat[100];
	int m,n;
	printf("Enter the paragraph: ");
	fgets(s,100,stdin);
	printf("Enter the pattern: ");
	fgets(pat,100,stdin);
	for(m=0;s[m]!='\0';++m);
	for(n=0;pat[n]!='\0';++n);
	s[--m]='\0';
	pat[--n]='\0';
	naive(s,pat,m,n);
	return 0;
}
