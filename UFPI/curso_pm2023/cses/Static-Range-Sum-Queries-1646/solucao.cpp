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
//g++ -std=c++17 -O2 --static solucao.cpp

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void calcularPrefixo(vector<ll> &prefixo_sum, int* numeros){
    prefixo_sum[0] = 0;
    for (int i = 1; i < prefixo_sum.size(); i++)
    {
        prefixo_sum[i] = prefixo_sum[i - 1] + numeros[i];
    }
    
} 

int main(int argc, char const *argv[]){
    optimize;

    int N, Q;

    cin >> N >> Q;

    int numeros[N + 1];

    for (int i = 1; i <= N; i++)
        cin >> numeros[i];
    
    vector<ll> prefix_sum(N + 1);

    calcularPrefixo(prefix_sum, numeros);

    while(Q--){
        int a, b;

        cin >> a >> b;

        ll soma = prefix_sum[b] - prefix_sum[a - 1];

        cout << soma << endl;
    }

    return 0;
}