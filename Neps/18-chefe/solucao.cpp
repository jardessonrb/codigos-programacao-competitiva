#include <bits/stdc++.h>


using namespace std;


int N, M, I;
map<int, int> idades;
vector<pair<int, int>> gere[1000000];

int pergunta(int empregado)
{
    int idade = 1000000;
    for (int i = 0; i < M; i++)
    {
        for(auto x : gere[i])
        {
            if(empregado == x.second)
            {
                if(idade > idades[empregado]){
                    idade = idades[empregado];
                }
            }
        }
    }

    return (idade == 1000000 ? -1 : idade);
}

void troca(int gerente, int empregado)
{
    bool pause = false;
    for (int i = 0; i < M; i++)
    {
        for(auto x : gere[i])
        {
            if(x.first == gerente) x.first = empregado;

            if(x.second == gerente) x.second = empregado;

            if(x.first == empregado) x.first = gerente;
            
            if(x.second == empregado) x.second = gerente;
            
        }

        if(pause) break; 
    }
    
    
}

int main(int argc, char const *argv[]){

    cin>>N>>M>>I;
    int idade;
    for (int i = 1; i <= N; i++)
    {
        cin>>idade;
        idades[i] = idade;
    }
    int g, e;
    for (int i = 0; i < M; i++)
    {   
        cin>>g>>e;
        gere[i].push_back({g, e});
    }
    char ide;
    int per, a , b;
    for (int i = 0; i < I; i++)
    {
        cin>>ide;
        if(ide == 'T')
        {
            cin>>a>>b;
            troca(a, b);
        } 
        if(ide == 'P')
        { 
            cin>>per;
            int res = pergunta(per);
            if(res == -1)
            {
                cout<<"*"<<endl;
            }else{
                cout<<res<<endl;
            }
        }
        
    }

    return 0;    
}