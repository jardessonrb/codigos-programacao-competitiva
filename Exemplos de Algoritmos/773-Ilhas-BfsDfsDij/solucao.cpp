#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 10010
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define endl '\n'

using namespace std;

int N, M, dist[MAXN][MAXN];
char mapa[MAXN][MAXN];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Estado
{
    int x, y, d;

    Estado(int x = 0, int y = 0, int d = 0) : x(x), y(y), d(d) {}

    bool operator < (const Estado &a) const
    {
        return d < a.d;
    }
};

void dfs(int i, int j, priority_queue<Estado> &fila)
{
    if(mapa[i][j] != '#') return;

    mapa[i][j] = '.';

    fila.push({i, j, 0});

    dist[i][j] = 0;

    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        
        dfs(x, y, fila);
    }
    
}


int bfs(int x, int y)
{
    priority_queue<Estado> fila;

    mapa[x][y] = '#';
    //fila.push({x, y});

    dfs(x, y, fila);


    while(!fila.empty())
    {
        auto atual = fila.top();
        fila.pop();

        for (int k = 0; k < 4; k++)
        {
            int x = atual.x + dx[k];
            int y = atual.y + dy[k];
            
            if(x < 1 or x > N or y < 1 or y > M) continue;

            if(dist[x][y] > dist[atual.x][atual.y] + 1)
            {
                dist[x][y] = dist[atual.x][atual.y] + 1;

                fila.push({x, y, dist[x][y]});
            }
        }
    }

    int ans = INF;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            if(mapa[i][j] == '#')
            {
                ans = min(ans, dist[i][j]);
            }

        }
    }

    return ans == INF ? -1 : ans - 1;
}


int main(int argc, char const * argv[]){
    optimize;

    cin >> N >> M;

    int x, y;

    for (int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            cin >> mapa[i][j];

            if(mapa[i][j] == 'X') x = i, y = j;

            dist[i][j] = INF;
        }
    }

    cout << bfs(x, y) << endl;
        
    return 0;
}