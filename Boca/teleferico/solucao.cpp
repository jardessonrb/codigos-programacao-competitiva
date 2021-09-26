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

int C, A;

int main(int argc, char const * argv[]){
    optimize;

    cin>>C>>A;

    int q = A / (C-1);

    int r = A % (C-1);

    int res = q;

    if( res > 0 )
    {   
        res++;
    }    

    cout << res <<endl;

    return 0;
}