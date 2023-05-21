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

vector<int> ciclos;

ll buscarQuantidadeDias(ll inicio, ll fim, ll quantidadeMoedas){
    ll dias = 0;

    while (inicio <= fim)
    {
        ll meio =  inicio + (fim - inicio) / 2;

        ll soma = 0;
        for(auto x : ciclos){
            int moedas = meio / x;

            soma += moedas;
        }

        if(soma >= quantidadeMoedas){
            dias = meio;
        }

        if(soma >= quantidadeMoedas){
            fim = meio - 1;
        }else{
            inicio = meio + 1;
        }
        
    }

    return dias;
}

int main(int argc, char const *argv[]){
    optimize;

    ll N, Q;

    cin >> N >> Q;

    ciclos.resize(N);

    for(auto &x : ciclos){
        cin >> x;
    }

    ll quantidadeDias = buscarQuantidadeDias(0, 1e9, Q);

    cout << quantidadeDias << endl;

    return 0;
}