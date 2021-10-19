#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 101
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL

using namespace std;

vector<int> rotas[10001];
int A,V, n = 1, ans = 1, trafego[101], maior = -100;

void dfs(int u)
{
    if(ans > A) return;
    for(auto it : rotas[u])
    {
        trafego[u]++;
    }

    if(maior < trafego[u]) maior = trafego[u];
    ans++;
    dfs(ans);
}

int main(int argc, char const * argv[]){
    optimize;

    while((cin>>A>>V) && (A != 0 && V != 0))
    {
        int x, y;
        for (int i = 1; i <= V; i++)
        {
            cin>>x >>y;
            rotas[x].push_back(y);
            rotas[y].push_back(x);
        }
        
        for (int i = 1; i <= A; i++)
        {
            trafego[i] = 0;
        }

        dfs(ans);

        for (int i = 1; i <= A; i++)
        {
            rotas[i].clear();
        }

        cout<<"Teste "<<n<<endl;
        for (int i = 1, s = 0; i <= A; i++)
        {
            if(trafego[i] == maior)
            {
                cout<<i<<" "[s > 0];
            }
        }
        cout<<"\n"<<endl;
        maior = - 100;
        ans = 1;
        n++;
    }

    return 0;
}