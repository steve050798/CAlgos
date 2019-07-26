#include <stdio.h>
void extended_euclid(int a,int b)
{
    int s=0,old_s=1,t=1,old_t=0,r=b,old_r=a,quotient,temp;
    while(r!=0)
    {
        quotient=old_r/r;
        temp=old_r;
        old_r=r;
        r=temp-quotient*r;
        temp=old_s;
        old_s=s;
        s=temp-quotient*s;
        temp=old_t;
        old_t=t;
        t=temp-quotient*t;
    }
    printf("Bezout Coeficients: %d %d",old_s,old_t);
    printf("\nGCD: %d",old_r);
}
int main()
{
  int a,b;
  printf("Enter two numbers to find the GCD of: ");
  scanf("%d%d",&a,&b);
  extended_euclid(a,b);
  return 0;
}
