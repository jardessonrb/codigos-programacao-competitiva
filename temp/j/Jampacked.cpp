#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXV 1010
#define ll long long
#define ld long double
#define pii pair<int, int>
#define INF 2000000020LL
#define CASAS_PRECISAO 0.0000001
#define endl '\n'
#define check_in_matriz(l, c, minl, maxc) (l >= 0 && l < minl) && (c < maxc && c >= 0) && (!visitados[l][c])
//g++ -std=c++17 -O2 --static solucao.cpp

using namespace std;

const int MOD = 1e4 + 3;
const int base = 101;
const int MAXN = 2e5 + 100;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

ll calc(ll k, ll resto){
    return resto + k / 2;
}

int main(int argc, char const *argv[]){
    optimize;

    ll  N, K;

    cin >> N >> K;

    if(N <= K){
        cout << N << endl;
    }else {
        ll resto = N % K;
        if(resto == 0){
            cout << K << endl;
        }else {
            cout << calc(K, resto) << endl;
        }
    }

    return 0;
}