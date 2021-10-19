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

int N, M;
char mapa[1010][1010];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool ok(int i, int j)
{
    int qnt = 0;

    for(int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];

        qnt += (mapa[x][y] == '#');
    }

    return qnt < 4;
}

int main(int argc, char const * argv[]){
    optimize;
    
    cin>>N>>M;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            cin>> mapa[i][j];
    
    int ans = 0;

    for(int i = 1; i <= N; i++)
	    for(int j = 1; j <= M; j++)
            if(mapa[i][j] == '#')
		        ans += ok(i, j);

    cout << ans <<endl;

    return 0;
}