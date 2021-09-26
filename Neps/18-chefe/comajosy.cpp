#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 100010
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define endl '\n'

using namespace std;
int N, M, I, idades[501];
int idadeGlobal = 1000;
bool visitados[501];
vector<int> relacoes[1000001];

void dfs(int x, int pai)
{
 
    visitados[x] = true;

    for(auto it : relacoes[x])
    {
        if(it != pai && visitados[it] == false)
        { 
            visitados[it] = true;

            if(idades[it] < idadeGlobal)
            {
                idadeGlobal = idades[it];
            }

            dfs(it, x);
        }
        
    }
}

void troca(int x, int y)
{
    vector<int> copyX[M], copyY[M];
    for(auto it : relacoes[x])
    {
        copyX[x].push_back(it);
        //cout<<x<<" = "<<it<<endl;
        relacoes[x].pop_back();
    }

    for(auto it : relacoes[y])
    {
        relacoes[x].push_back(it);
        // cout<<x<<" = "<<it<<endl;
        relacoes[y].pop_back();
    }

    for(auto it : copyX[x])
    {
        relacoes[y].push_back(it);
    }

    // for(int i = 0; i < (int)relacoes[x].size(); i++)
    // {
    //     cout<<x<<" = "<<relacoes[x][i]<<endl;
    //     cout<<y<<" = "<<relacoes[y][i]<<endl;
    // }
    
}

int main(int argc, char const * argv[]){
    optimize;
    cin>>N>>M>>I;

    for (int i = 1; i <= N; i++)
    {
        cin>>idades[i];
        visitados[i] = false;
    }

    int x, y;
    for (int i = 0; i < M; i++)
    {
       cin>>x>>y;
       relacoes[x].push_back(y);
       relacoes[y].push_back(x);
    }

    char amor;
    for (int i = 0; i < 3; i++)
    {
        cin>>amor;
        int val1, val2;
        if(amor == 'P')
        {
            cin>>val1;
            dfs(val1, 0);

            //cout<<idadeGlobal<< "  "<<idades[val1]<<endl;
            if(idadeGlobal != 1000) cout<<idadeGlobal<<endl;
            
            else cout<<'*'<<endl;

        }
        else
        {
            cin>>val1>>val2;
            troca(val1, val2);
        }
        
    }
    
    
    
    return 0;
}