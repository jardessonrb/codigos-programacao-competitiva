#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()

using namespace std;

struct Lampadas{
    vector<int> interruptor;
    bool ligada;
};

Lampadas lampadas[1000];

bool verificar(int inter, int max)
{
    int contV = 0;

    for(int j = 1; j <= max; j++)
    {
        for (int i = 0; i < lampadas[j].interruptor.size(); i++)
        {
            if(lampadas[j].interruptor[i] == inter)
            {
                lampadas[j].ligada == false ? lampadas[j].ligada = true : lampadas[j].ligada = false;

                if(lampadas[j].ligada == false) contV++;
                
                break;
            }
        }        
    }

    if(max == contV) return true;

    return false;

    
}
int cont = 0;
int main(int argc, char const * argv[]){

    int N, M, L, x;
    cin>> N >> M;
    cin>> L;

    
    //inicia as lampdas
    for (int i = 1; i <= M; i++)
    {
        lampadas[i].ligada = false;
    }
    
    //liga as primeiras lampadas
    for (int i = 0; i < L; i++)
    {
        cin>>x;
        lampadas[x].ligada = true;
    }
    //associa os interruptores
    int k, l;
    for (int i = 1; i <= N; i++)
    {
        cin>>k;
        for(int j = 0; j < k; j++){
            cin>>l;
            lampadas[l].interruptor.push_back(i);                
        }
    }

    // for(int j = 1; j <= M; j++)
    // {
    //     cout<<"LIgada: "<<lampadas[j].ligada<<"+===+";
    //     for (int i = 0; i < lampadas[j].interruptor.size(); i++)
    //     {
    //         cout<<"Inter: "<<lampadas[j].interruptor[i]<<" ";
    //     }        
    //     cout<<endl;  
    // }


    int loop = 3;
    while(loop --)
    {
        bool flag = false;
        for (int i = 1; i <= N; i++)
        {
            cont++;
            if(verificar(i, M) == true) break;
        }
        
        if(flag == true) break;
    }

    cout<<(loop == 0 ? -1 : cont)<<endl;

    return 0;
}