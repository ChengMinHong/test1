#include<unistd.h>
#include<sys/wait.h>
#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int div(string A,vector<string>&Cmd)
{        
	string tmp;
        A+=' ';
	for(int i = 0 ; i <A.length();i++)
	{         
		if(A[i]!=' '&&A[i]!='|'){tmp+=A[i];}
		else if(tmp.length()!=0){Cmd.push_back(tmp);tmp.erase();}     
	}
	if(!Cmd[0].compare("cd")&&Cmd.size()==1){Cmd.push_back("/");}
	if(!Cmd[0].compare("cd..")){Cmd[0]="cd";Cmd.push_back("..");}
	return 0;
}
int P(vector<string>&C)
{
	char **agv=new char*[C.size()+1];
	agv[C.size()]=NULL;
	for(int i = 0 ;i<C.size();i++)
	{
		agv[i]=new char [C[i].length()];
		for(int j = 0 ; j<C[i].length();j++){agv[i][j]=C[i][j];}
	}
	if(!C[0].compare("cd"))
	{
	        chdir(C[1].c_str());
                return 0;
	}
        else if(!C[0].compare("exit")){cout<<"ByeBye!!";exit(0);}
	else
	{
		int pid=fork();
		if(pid!=0)
		{
			int st;
			wait(&st);
		}
		else
		{
			execvp(agv[0],agv);
			exit(0);
		}	
	}
}
int main()
{       
	string input;
	vector<string>Cmd;
        char Buff[80];
	while(true)
	{
		printf("\33\[1;32m[s1023324shell]@%s ~$ \33\[0m",getcwd(Buff , 80));
		getline(cin,input);
		if(cin.eof())
		{
			cin.clear();
			continue;
		}
		div(input,Cmd);
		P(Cmd);
		Cmd.clear();               
	}
}
