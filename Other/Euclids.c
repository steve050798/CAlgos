//EUCLID'S ALGORITHM
#include <stdio.h>
int euclids_gcd(int m,int n)
{
	if(m==0)
		return n;
	else if(n==0)
		return m;
	else
		return euclids_gcd(n,m%n);
}
int main()
{
	int m,n,gcd;
	printf("Enter two numbers: ");
	scanf("%d%d",&m,&n);
	gcd=euclids_gcd(m,n);
	printf("GCD: %d",gcd);
	return 0;
}
