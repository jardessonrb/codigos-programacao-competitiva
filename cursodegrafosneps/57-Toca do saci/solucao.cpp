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

int N, M, toca[1001][1001], ans = 0;
bool visitado[1001][1001];

void fingeDfs(int x, int y)
{

    if(toca[x][y] == 2) return;

    for(int i = x-1; i < x+2; i++)
    {
        for(int c = y - 1; c < y+2; c++)
        {
            if(toca[i][c] == 1 && (x != i || y != c) && visitado[i][c] == false)
            {
                //cout<<"i == "<<i<<" c == "<<c<<" valor == "<<toca[i][c]<<endl;
                visitado[i][c] = true;
                ans++;
                fingeDfs(i, c);
            }
        }
    }
}
int main(int argc, char const * argv[]){
    optimize;

    cin>>N>>M;
    int x = -1, y = -1, v;
    for (int i = 1; i <= N; i++)
    {
        for(int c = 1; c <= M; c++)
        {
            cin>>v;
            toca[i][c] = v;
            visitado[i][c] = false;
            if(v == 3) x = i, y = c;
        }
    }
    //cout<<x<<" "<<y<<endl;
    fingeDfs(x, y);

    cout<< (ans+2) <<endl;

    return 0;
}