#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 100010
#define MAXV 1010
#define ll long long

using namespace std;

map<int, int> saloes;
vector<pair<int, int>> rotas;
int S, T, P;

int dfs(int partida)
{

    for(auto x : rotas)
    {
        if(x.first == partida)
        {
            if(saloes[partida] > saloes[x.second])
            {
                dfs((int)x.second);
            }
        }
    }
}

int main(int argc, char const * argv[]){
    cin>>S>>T>>P;
    int x, p, c;
    for (int i = 1; i <= S; i++)
    {
        cin>>x;
        saloes[i] = x;
    }

    for (int i = 0; i < T; i++)
    {
        cin>>p>>c;

        rotas.emplace_back(p, c);
    }
    
    dfs(P);
    

    return 0;
}