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

int N, bit[MAXN];

void add(int pos, int val)
{
    for( ; pos < MAXN; pos += (pos & -pos))
    {
        bit[pos]+=val;
    }
}

int query(int pos)
{
    int ans = 0;
    for( ; pos > 0; pos -= (pos & -pos))
    {
        ans += bit[pos];
    }

    return ans;
}

int main(int argc, char const * argv[]){
    optimize;
    while((cin>>N) && N != 0)
    {
        for (int i = 0; i <= N; i++) bit[i] = 0;

        int ans = 0;
        for (int i = 0, x; i < N; i++)
        {
            cin>>x;

            ans += (query(N) - query(x - 1));
            add(x, 1);
        }

        cout<<((ans % 2) ? "Marcelo" : "Carlos")<<endl;
        
    }

    return 0;
}