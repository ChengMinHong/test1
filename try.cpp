#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
using namespace std;
struct data
{
	string number;
	int count;//count 10^n 	
};
int ProStr(string &n, int L,int Sign)
{	
	if(Sign>0)//After
	{
		for(int i= 0 ; i <L ; i++)
		{	
			n+='0';
		}
	}
	else
	{	
		for(int i= 0 ; i <L ; i++)
		{
			n='0'+n;
		}
		n="0."+n;
	}		
}
int cal(string F1,string F2,int Sign)
{
	int L,L2;
	int temp=0;//Carry
	int num=0;
	vector<char>Sol;	
	if(Sign>0)
	{	
		L=(F1.length()-F2.length())>0?ProStr(F2,L,1):ProStr(F1,(-1*L),1);
		cout<<F1<<endl<<F2<<endl;
/*
		for(int i=F1.length()-1 ;i>=0;i--)
		{	
			if(i==1&&F1[i]=='.')
			{
						Sol.push_back('.');
						continue;
			}
			num+=temp;
			num=(F1[i]-0x30)+(F2[i]-0x30);
			num>9?temp=num/10,Sol.push_back((num%10)+0x30):Sol.push_back(num+0x30),temp=0;
			if(i==0&&temp!=0){Sol.push_back(temp+0x30);}	
		}*/		
	}
/*
	for(int i = Sol.size()-1 ; i>=0;i--)
	{
		cout<<Sol[i];
	}
*/	
	return 0;
}

int main()
{
	cal("1.234","5.678",1);
	return 0;				
}
