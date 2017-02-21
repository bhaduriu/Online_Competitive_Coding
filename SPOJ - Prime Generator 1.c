/*
Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!

Input

The input begins with the number t of test cases in a single line (t<=10). In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

Output

For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.

Example

Input:
2
1 10
3 5

Output:
2
3
5
7

3
5
*/
#include <stdio.h>
#include <math.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
	    unsigned int low,high,i=0,j=2,k,x=0,y=0,z;
	    unsigned long int a[200000],b[200000];
	    scanf("%d",&low);
	    scanf("%d",&high);
	    for(i=low;i<=high;i++)
	        a[x++]=i;
	    for(i=2;i<=32000;i++)
	        b[y++]=i;
    	i=0;
    	while(b[i]*b[i]<=high)
        {
	        if(b[i]!=0)
	        {
	            k=i;
	            for(;k<y;k+=j)
	            {
	                if(k!=i)
	                {
	                    b[k]=0;
	                }
	            }
	        }
	        i+=1;j+=1;
	    }
	        for(i=0;i<y;i++)
	        {
	            if(b[i]!=0 && (b[i]>=low && b[i]<=sqrt(high)))
	                printf("%d\n",b[i]);
	        }
	        int c=0;
    	    for(i=0;i<y;i++)
    	    {
    	        if(b[i]!=0 && (b[i]>=1 && b[i]<=sqrt(high)))
    	            b[c++]=b[i];
    	    }
    	    int m=a[0];
    	    for(i=0;i<c;i++)
    	    {
    	        z=(m/b[i])*b[i];k=z-m;
    	        if(k!=0)
    	            k += b[i];
    	        for(;k<x;)
    	        {
    	            if(a[k]!=0)
    	            {
    	                a[k]=0;
    	            }
    	            k+=b[i];
    	        }
    	    }
       	    for(i=0;i<x;i++)
       	    {
       	        if(a[i]!=0 && (a[i]>=2 && a[i]<=(high)))
       	            printf("%d\n",a[i]);
       	    }
	    printf("\n");
	}
	return 0;
}
