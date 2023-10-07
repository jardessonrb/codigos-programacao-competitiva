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

const int MAXN = 2e5 + 100;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

ll segtre[4 * MAXN];
ll valores[MAXN];

void update(int pos, int i, int j, int x, ll valor){
    int esquerda = 2 * pos;
    int direita  = (2 * pos) + 1;
    int meio     = (i + j) / 2;

    segtre[pos] += valor;

    if(i == j) return;

    if(x <= meio){
        update(esquerda, i, meio, x, valor);
    }else{
        update(direita, meio + 1, j, x, valor);
    }
}

ll query(int pos, int i, int j, int l, int r){
    int esquerda = 2 * pos;
    int direita  = 2 * pos + 1;
    int meio         = (i + j) / 2;

    if(i > r || j < l) {
        return 0;
    }else if(i >= l && j <= r) {
        return segtre[pos];
    }else {
        return query(esquerda, i, meio, l, r) + query(direita, meio + 1, j, l, r);
    }

}


int main(int argc, char const *argv[]){
    optimize;

    int N, Q;

    cin >> N >> Q;

    ll valor;
    for (int i = 0; i < N; i++)
    {
        cin >> valor;
        update(1, 0, N - 1, i, valor);
        valores[i] = valor;
    }

    int opc;
    while(Q--){
        cin >> opc;

        if(opc == 1){
            int k;

            cin >> k >> valor;

            k--;
            update(1, 0, N - 1, k, -valores[k]);
            update(1, 0, N - 1, k, valor);
            valores[k] = valor;
        }else {
            int l, r;

            cin >> l >> r;

            l--;
            r--;
            cout << query(1, 0, N - 1, l, r) << endl;
        }
    }
    

    return 0;
}