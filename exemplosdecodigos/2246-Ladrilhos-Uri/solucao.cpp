#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 220
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000000
#define endl '\n'

using namespace std;

int N, M, mapa[MAXN][MAXN];
bool visitado[MAXN][MAXN];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dfs(int i, int j)
{
    visitado[i][j] = true;
    int sz = 1;

    for (int i = 0; i < 4; i++)
    {
        int x = i + dx[i];
        int y = j + dy[i];

        if(x < 1 or x > N or y < 1 or y > M or mapa[i][j] != mapa[x][y] or visitado[x][y]) continue;

        sz += dfs(x, y);

    }


    return sz;
}

int main(int argc, char const * argv[]){
    optimize;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
       for(int j = 1; j <= M; j++)
       {
           cin>> mapa[i][j];
       }
    }

    int ans = INF;

    for (int i = 1; i <= N; i++)
    {
       for(int j = 1; j <= M; j++)
       {
           if(!visitado[i][j])
           {
               ans = min(ans, dfs(i, j));
           }
       }
    }


    cout << ans << endl;

    
    

    return 0;
}