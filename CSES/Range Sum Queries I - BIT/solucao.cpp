#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 201010
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define CASAS_PRECISAO 0.0000001
#define endl '\n'
//g++ -std=c++17 -O2 --static solucao.cpp

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

vector<ll> valores;

void update(int x, int valor){
    for (; x < MAXN; x +=  (x & -x))
        valores[x] += valor;
    
}

ll query(int x){
    ll sum = 0;
    for (; x > 0; x -=  (x & -x))
    {
        sum += valores[x];
    }

    return sum;
    
}

int main(int argc, char const *argv[]){
    optimize;

    int N, Q;

    cin >> N >> Q;

    valores.resize(MAXN, 0);

    for (int i = 1; i <= N; i++)
    {
        ll x;

        cin >> x;

        update(i, x);

    }


    while(Q--){
        int opt;

        cin >> opt;

        if(opt == 2){
            int a, b;

            cin >> a >> b;

            cout << query(b) - query(a - 1) << endl;
        }else {
            int a;
            ll b;
            cin >> a >> b;

            update(a - 1, b);
        }

    }
    



    return 0;
}