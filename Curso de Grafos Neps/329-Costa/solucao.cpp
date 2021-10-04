#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 1010
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define endl '\n'

using namespace std;
int M, N;


int main(int argc, char const * argv[]){
    optimize;

    cin>>M>>N;
    char mapa[MAXN][MAXN];
    char qua;
    for(int l = 1; l <= M; l++)
    {
        for(int c = 1; c <= N; c++)
        {
            cin>>qua;
            mapa[l][c] = qua;
        }
    }

    int ans = 0;
    for(int l = 1; l <= M; l++)
    {
        for(int c = 1; c <= N; c++)
        {
            if(mapa[l][c] == '#')
            {   
                if(l == 1 || l == M || c == 1 || c == N) ans++;

                else if(mapa[l - 1][c] == '.' || mapa[l + 1][c] == '.' || mapa[l][c + 1] == '.' || mapa[l][c - 1] == '.')
                {
                    ans++;
                }
            }
        }
    }
    
    cout<<ans<<endl;

    return 0;
}