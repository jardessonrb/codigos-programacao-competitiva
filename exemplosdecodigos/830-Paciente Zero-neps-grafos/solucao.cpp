#include <bits/stdc++.h>

using namespace std;

int pai[1000000], N, C, Q, I, x;

//vector<pair<int, int>> grafos[1000000];


int main(int argc, char const *argv[]){
    
    cin>>N>>C;

    //int u == vertice de ida/volta,v == vertice de ida/volta, c == peso da aresta;
    //grafos[u].push_back({v, c}); ou push_back(pair(v, c));
    //grafos[v].push_back({u, c});

    // for(auto x : grafos[u])
    // {
    //     int v = x.first;
    //     int c = x.second;
    // }

    for (int i = 1; i <= N; i++)
    {
        pai[i] = -1;
    }

    for (int i = 0; i < C; i++)
    {
        cin >> I >> Q;

        for (int j = 0; j < Q; j++)
        {
            cin>>x;

            pai[x] = I;
        }
        
    }

    for (int i = 0; i < N; i++)
    {
        if(pai[i] == -1)
        {
            cout<< i <<endl;

        }
    }
    
    
    
    
    
    return 0;
}