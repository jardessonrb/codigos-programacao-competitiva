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

vector<int> grafo[1000000];
bool visitado[1000000];

//lista de adjacencia;
//grafo[u].push_back(v);

int dfs(int u)
{
    visitado[u] = true;

    int ans = 0;
    for (auto v : grafo[u])
    {
        if(visitado[v] == false)
        {
            ans += 2 + dfs(v);
        }
    }
   

    return ans;
}

int main(int argc, char const * argv[]){
    optimize;

    int T;

    cin>> T;
    while(T--)
    {
        int N, V, A;

        cin>>N>>V>>A;

        for (int i = 0; i <= V; i++)
        {
            grafo[i].clear();
            visitado[i] = false;
        }
        

        int u, v;
        for(int i = 0; i < A; i++)
        {
            cin>>u >>v;
            grafo[u].push_back(v);
            grafo[v].push_back(u);
        }

        cout<< dfs(N) <<endl;
    }

    return 0;
}