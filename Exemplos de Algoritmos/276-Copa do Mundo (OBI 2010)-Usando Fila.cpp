#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
	
	queue<char> fila;
	
	for(char c='A'; c<= 'P'; c++)
	{
		fila.push(c);
		//fila.pop(); remove um elemento da fila, o primeiro
		//fila.front() retorna o primeiro elemento da lista
	}
	
	int a, b;
	
	for(int i=0; i<15; i++)
	{
		cin >>a >> b;
		
		if(a > b)
		{
			fila.push(fila.front());
			fila.pop();
			fila.pop();
			
		}
		else
		{
			fila.pop();
			fila.push(fila.front());
			fila.pop();
		}
		
	}
	
	cout<<fila.front()<<endl;

	return 0;
}

