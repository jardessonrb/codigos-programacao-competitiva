#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 200020
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define endl '\n'

using namespace std;

int N;
vector<int> grafo[MAXN];
bool ans = true;

int dfs(int u, int p = -1)
{
    int sz = 1, tam = -1;

    for(int v : grafo[u]) //if(v != p)
    {
        if(v != p)
        {
            int x = dfs(v, u);
            sz += x;

            if(tam == -1) tam = x;

            if(tam != x)
            {
                ans = false;
            }

        }
    }


    return sz;
}

int main(int argc, char const *argv[]){
    optimize;

    cin >> N;

    for (int i = 1, u, v; i <= N; i++)
    {
        cin>>u>>v;

        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }
    
    dfs(0);

    cout << ( ans ? "bem" : "mal") << endl;

    return 0;
}