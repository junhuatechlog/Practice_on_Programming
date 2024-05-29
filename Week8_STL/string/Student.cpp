#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

#define CMD_LENGTH 10

using namespace std;

bool isNumber(string &str)//是否为0-99,999间整数
{
	if(str.length()>5)
		return false;
	for(int i=0; i<str.length(); ++i)
	{
		if(('0' > str[i])||(str[i] > '9'))
			return false;
	}
	return true;
}
int main()
{
	int nCount; cin >> nCount;
	string *pStrArray = new string[nCount];
	for(int i=0; i<nCount; ++i)
		cin >> pStrArray[i];	

	string cmd;
	for(;;)
	{
		string str;
		getline(cin,str);
		istringstream ss(str);
		stack<string> stack1,stack2;
		while(ss >> cmd)
			stack1.push(cmd);
		while(!stack1.empty())
		{
			cmd = stack1.top();
			stack1.pop();

			if(strcmp(cmd.c_str(),"copy")==0)
			{
				string N,X,L,R;
				N = stack2.top();stack2.pop();
				X = stack2.top();stack2.pop();
				L = stack2.top();stack2.pop();
				R = pStrArray[atoi(N.c_str())-1].substr(atoi(X.c_str()), atoi(L.c_str()));
				stack2.push(R);
			}
			else if(strcmp(cmd.c_str(),"add")==0)
			{
				string S1,S2;
				S1 = stack2.top();stack2.pop();
				S2 = stack2.top();stack2.pop();
				if(isNumber(S1) && isNumber(S2))
				{
					char temp[10];sprintf(temp, "%d", atoi(S1.c_str())+atoi(S2.c_str()));
					stack2.push(temp);
				}
				else
					stack2.push(S1+S2);
			}
			else if(strcmp(cmd.c_str(),"find")==0)
			{
				string S,N;int n;
				S = stack2.top();stack2.pop();
				N = stack2.top();stack2.pop();
				if((n = pStrArray[atoi(N.c_str())-1].find(S))==string::npos)
					n = pStrArray[atoi(N.c_str())-1].length();
				char temp[10];sprintf(temp, "%d", n);
					stack2.push(temp);
			}
			else if(strcmp(cmd.c_str(),"rfind")==0)
			{
				string S,N;int n;
				S = stack2.top();stack2.pop();
				N = stack2.top();stack2.pop();
				if((n = pStrArray[atoi(N.c_str())-1].rfind(S))==string::npos)
					n = pStrArray[atoi(N.c_str())-1].length();
				char temp[10];sprintf(temp, "%d", n);
					stack2.push(temp);		
			}
			else if(strcmp(cmd.c_str(),"insert")==0)
			{
				string S,N,X;
				S = stack2.top();stack2.pop();
				N = stack2.top();stack2.pop();
				X = stack2.top();stack2.pop();
				pStrArray[atoi(N.c_str())-1].insert(atoi(X.c_str()),S);
			}
			else if(strcmp(cmd.c_str(),"reset")==0)
			{
				string S,N;
				S = stack2.top();stack2.pop();
				N = stack2.top();stack2.pop();
				pStrArray[atoi(N.c_str())-1] = S;
			}
			else if(strcmp(cmd.c_str(),"print")==0)
			{
				string N;
				N = stack2.top();stack2.pop();
				cout << pStrArray[atoi(N.c_str())-1] << endl;
			}
			else if(strcmp(cmd.c_str(),"printall")==0)
			{
				for(int i=0; i<nCount; ++i)
					cout << pStrArray[i] << endl;				
			}
			else if(strcmp(cmd.c_str(),"over")==0)
				return false;
			else
			{
				stack2.push(cmd);//如果不是cmd就是操作数，压入备用栈中
			}
		}
	}
	return false;
}