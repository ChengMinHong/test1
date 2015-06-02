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
int add(int* a, int* b, int* c)
{
	int  carry = 0;
	for (int i = 250; i >= 0; i--)
	{
		c[i] = a[i] + b[i] + carry;
		c[i] < 10000 ? carry = 0 : c[i] = c[i] - 10000, carry = 1;
	}
	return 0;
}
int subtract(int* a, int* b, int* c)
{
	int i, borrow = 0;
	for (i = 250; i >= 0; i--)
	{
		c[i] = a[i] - b[i] - borrow;
		c[i] >= 0 ? borrow = 0 : c[i] = c[i] + 10000, borrow = 1;
	}
	return 0;
}
int divide(int* a, int b)
{
	int  temp = 0, num = 0;
	for (int i = 0; i < 250; i++) {
		temp = a[i] + num;
		a[i] = temp / b;
		num = (temp % b) * 10000;
	}
	return 0;
}
void *Machin(void*n)
{
	data *P = (data*)(n);
	for (int i = P->start; i < P->limit; i++)
	{
		divide(P->a, 25);
		divide(P->b, 57121); // 239 * 239 = 57121
		subtract(P->a, P->b,P->c);
		divide(P->c, 2 * i - 1);
		i % 2? add(P->d, P->c,P->d):subtract(P->d, P->c, P->d);
	}
}
int main(int argc,char*argv[]) 
{	
	data p;
	p.start=1;
	p.limit=770;
	for(int i=0; i<251;i++){p.a[i]=p.b[i]=p.c[i]=p.d[i]=0;}
	int *input=new int [argc];
	pthread_t *thread;
	for(int i = 0 ; i<argc;i++){	input[i]=atoi(argv[i]);	}
	thread=new pthread[data[2]];
	pthread_create(&thread[0],NULL,Machin,&p);
	cout<<p.c[0]<<'.';
	for(int i=1;i<251;i++){cout<<p.c[i];}
	return 0;
}

