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
int Ac_Z =800;
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
void Add(int* a, int* b, int* c) {
	int i, carry = 0;
	for (i = N - 1; i >= 0; i--) {
		c[i] = a[i] + b[i] + carry;
		if (c[i] < 10000) carry = 0;
		else
		{
			carry = 1;  
			c[i] -= 10000;
		}
			
	}
}

void Sub(int* a, int* b, int* c) {
	int i, borrow = 0;
	for (i = N - 1; i >= 0; i--) {
		c[i] = a[i] - b[i] - borrow;
		if (c[i] < 0)
		{
			c[i] += 10000; 
			borrow = 1;
		} 
		else borrow = 0;
		
	}
}
int Div(int	*a, int b)
{
	int  temp = 0, num = 0;
	for (int i = 0; i < 250; i++) {
		temp = a[i] + num;
		a[i] = temp / b;
		num = (temp % b) * 10000;
	}
	return 0;
}
void* Machin(void* n)
{
	data *P = (data*)n;
	for (int i = 1; i <Ac_Z; i++)
	{
		Div(P->a, 25);
		Div(P->b, 57121); // 239 * 239 = 57121
		Sub(P->a, P->b, P->c);
		Div(P->c, 2 * i - 1);
		i % 2 != 0 ? Add(P->d, P->c, P->d) : Sub(P->d, P->c, P->d);
	}
	return 0;
}
int main(int argc, char*argv[])
{
	data p;
	for (int i = 0; i<251; i++){ p.a[i] =p.b[i] = p.c[i] = p.d[i] = 0; }
	int *input=new int [argc];
	for(int i = 0 ; i<argc;i++){input[i]=atoi(argv[i]);	}
	p.a[0] = 16 * 5;p.b[0] = 4 * 239;
	pthread_t *T=new pthread_t[input[2]];
	pthread_create(&T[0],NULL,Machin,&p);
	cout << p.d[0] << '.';
	for (int i = 1; i < 251; i++)
	{
		cout << p.d[i];
	}
	system("pause");
	return 0;
}
