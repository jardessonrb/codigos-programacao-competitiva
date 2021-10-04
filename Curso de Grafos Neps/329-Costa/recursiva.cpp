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
int M, N,  ans = 0;
char costa[1001][1001];
bool visitado[1001][1001];

void verifica(int x, int y)
{
    //if(x == 1 || x == M || y == 1 || y == N) ans++;

    //else{
        for(int i = x-1; i < x+2; i+=2)
        {
            for(int c = y - 1; c < y+2; c+=2)
            {
                cout<<costa[x][y]<<"  "<<costa[i][c]<<endl;
                // if(costa[i][c] == '.'){
                //     ans++;
                //     return;
                // } 
            }
        }
   // }

}


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
            costa[l][c] = qua;
            visitado[l][c] = false;
        }
    }

    for(int l = 1; l <= M; l++)
    {
        for(int c = 1; c <= N; c++)
        {
            if(mapa[l][c] == '#')
            {  
                verifica(l, c);
            }
        }
    }
    
    cout<<ans<<endl;

    return 0;
}