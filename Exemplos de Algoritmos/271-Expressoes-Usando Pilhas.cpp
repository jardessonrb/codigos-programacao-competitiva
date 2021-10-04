#include <bits/stdc++.h>

using namespace std;

bool abre(char x)
{
	return (x== '(') || (x=='[') || (x == '{');
	
}

bool match(char a, char b)
{
	if(a == '(') return b == ')';
	if(a == '[') return b == ']';
	if(a == '{') return b == '}';
	
	return false;
	
}
int main(int argc, char const *argv[]){
	int N;
	cin>> N;
	
	while(N--)
	{
		string S;
		
		cin>>S;
		
		stack<char> pilha;
		bool ok = true;
		
		for(int i = 0; i<(int)S.size(); i++)
		{
			if(abre(S[i]))
			{
				pilha.push(S[i]);
				
			}
			else
			{
				if(pilha.empty())
				{
					ok = false;
					break;
				}
				
				if(match(pilha.top(), S[i]) == false)
				{
					ok = false;
					break;
				}
				
				pilha.pop();
				
			}
			
		}
		
		if(ok == false)
		{
			cout<< "N"<< endl;
		}
		else if(!pilha.empty())
		{
			cout<<"N"<<endl;
		}else
		{
			cout<<"S"<<endl;
		}
	}

	return 0;
}

