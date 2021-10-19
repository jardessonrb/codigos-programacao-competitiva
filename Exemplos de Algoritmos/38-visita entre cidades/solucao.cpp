#include <bits/stdc++.h>
#define max 1000000

using namespace std;

vector<pair<int, int>> grafos[max];

int N, A, B, pai[max], peso[max];

void dfs(int u, int p)
{   
    for(auto x : grafos[u])
    {
        int v = x.first;
        int c = x.second;

        if(p != v)
        {
            pai[v]  = u;
            peso[v] = c;

            dfs(v, u);

        }
    }


}

int main(int argc, char const *argv[]){

    cin>>N>>A>>B;

    int u, v, c;

    for (int i = 1; i < N; i++)
    {
        cin>>u>>v>>c;
        grafos[u].push_back({v, c});
        grafos[v].push_back({u, c});
    }

    dfs(A, 0);

    int ans = 0;

    while (B != A)
    {  
        ans += peso[B];
        B    = pai[B];

    }
    

    cout<<ans<<endl;
    

    return 0;
}