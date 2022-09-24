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

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int calc(ll c){
    if(c % 2 == 0){
        ll r = c / 2 ;
        ll pares = r / 2;

        return pares;

    }else {
        int r = c / 2 ;
        return r + 1;
    }
}

int main(int argc, char const *argv[]){
    optimize;

    int T;

    cin >> T;

    while(T--){
        ll C;
        cin >> C;

        cout << calc(C) << endl;
    }
    

    return 0;
}