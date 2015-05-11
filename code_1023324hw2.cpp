#include<stdlib.h>
#include<iostream>
#include<sys/wait.h>
#include<time.h>
#include<unistd.h>
#include<string>
#include<vector>
using namespace std;

struct Ipt
{
    string Ipt;
    Ipt *nt;
};
int  printPrompt(void)
{    
     cout<<endl;
     cout<<"1023324@Shell >~$ ";
     return 0;   
}
string readCmdLine()
{    
     string input;
     vector<string>Data
     getline(cin,input);
     return input;    
}
int main (void)
{
	int Control=1;
	while(Control)
	{	
		int childPid;
		string cmdLine;
		printPrompt();
                cmdLine=readCmdLine();
                
                
        }	
}
