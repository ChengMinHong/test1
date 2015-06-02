#include<pthread.h>
#include <stdio.h> 
#include <stdlib.h>
#include<iostream>
using namespace std;
//-------------define------------------------------------------------------------------
#define L 1000 
#define N L / 4 + 1 
// L 為位數，N是array長度

//-------------globle------------------------------------------------------------------
int Ac_Z = (int)(L / 1.39793 + 1);
//-------------Data_struct-------------------------------------------------------------
struct data
{
	int start;
	int limit;
	int a[251];
	int b[251];
	int c[251];
	int d[251];
};
//-----------Function-------------------------------------------------------------------
int add(int *a, int *b, int *c)
{
	int  carry = 0;
	for (int i = 250; i >= 0; i--)
	{
		c[i] = a[i] + b[i] + carry;
		if(c[i] >= 10000) 
		{
		  	c[i]-= 10000;
			carry = 1;
		}
		else carry=0;
	}
	return 0;
}
int subtract(int *a, int *b, int *c)
{
	int  borrow = 0;
	for (int i = 250; i >= 0; i--)
	{
		c[i] = a[i] - b[i] - borrow;
		if(c[i] >= 0)	borrow = 0;
		else
		{	
			c[i]+= 10000; 
			borrow = 1;
		}
	}
	return 0;
}
int divide(int	*a, int b)
{
	int  temp = 0, num = 0;
	for (int i = 0; i < 250; i++) {
		temp = a[i] + num;
		a[i] = temp / b;
		num = (temp % b) * 10000;
	}
	return 0;
}
int Machin(data &P)
{
	for (int i = 1; i <Ac_Z; i++)
	{
		divide(P.a, 25);
		divide(P.b, 57121); // 239 * 239 = 57121
		subtract(P.a, P.b,P.c);
		divide(P.c, 2*i-1);
		i % 2!=0? add(P.d, P.c,P.d):subtract(P.d, P.c, P.d);
	}
	return 0;
}
int main(int argc,char*argv[]) 
{	
	data p;
	for(int i=0; i<251;i++){p.a[i]=0;p.b[i]=0;p.c[i]=0;p.d[i]=0;}
	/*int *input=new int [argc];
	for(int i = 0 ; i<argc;i++){	input[i]=atoi(argv[i]);	}*/
	p.a[0]=16*5;
	p.b[0]=4*239;
	Machin(p);
	cout<<p.c[0]<<'.';
	for(int i=1;i<251;i++){cout<<p.c[i];}
	return 0;
}

