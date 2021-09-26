#include <bits/stdc++.h>

using namespace std;

bool abre(char x)
{
  return (x == '<');
  
  return false;
  
}


int main(int argc, char const *argv[]){
	int N, c;
	cin>>N;
	while(N--)
	{
	  string s, r="";
	 	stack<char> pilha;
	 	
	 	cin>>s;

	 	for(int i=0; i<(int)s.size(); i++)
	 	{
	 	  if(s[i] != '.')
	 	  {
	 	    pilha.push(s[i]);
	 	    r += s[i];
      }
	  }
	  int t = (int)pilha.size();
    for(int i=0; i<t; i++)
    {
      if(abre(pilha.top()))
      {
       
      }
    }
	}
	

	return 0;
}

