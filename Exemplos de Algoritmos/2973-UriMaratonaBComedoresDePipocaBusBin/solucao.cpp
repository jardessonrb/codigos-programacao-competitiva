#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 100010
#define MAXV 1010
#define ll long long
#define INF 100000000000000

using namespace std;
int N, C, T, nums[100010];

bool F(ll x)
{
    ll maxima = T * x, atual = 0;

    int qtd = 1;

    for(int i = 1; i <= N; i++)
    {
        if(nums[i] > maxima) return false;


        if(atual + nums[i] > maxima)
        {
            qtd++;
            atual = 0;
        }

        atual += nums[i];
    }

    return (qtd <= C);

}


int main(int argc, char const * argv[])
{
    cin>> N >> C >> T;


    for (int i = 1; i <= N; i++)
        cin>> nums[i];

    ll l = 0, r = 10000000000000, m, ans;
    
    while(l <= r)
    {
        m = (l + r) / 2;

        if(F(m) == true)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    cout<< ans << endl;
    return 0;
}