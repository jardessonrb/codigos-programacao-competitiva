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

/*
Problema
Resumo: Tenho n retangulos de tamanhos iguais, e quero encontrar um quadrado, com menor tamanho, 
que possa coloca-los dentro. 
Restrição: Não posso rodar os retangulos.
Solução: 
Buscar um valor para R que satisfaça (x / width) * (x / legth) que seja >= n;
Depois verificar, caso m, m sendo (l + r) / 2, for bom(good) r = m, se não, l = m;
Assim, enquanto r > l + 1, r vai diminuindo e l aumentado, quando parar o valor de r é o tamanho do lado
necessario para armazenar os retangulos
*/

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

ll x, y, n;

bool isGood(ll m){
    return (m / x) * (m / y) > n;
}

int main(int argc, char const *argv[]){
    optimize;

    cin >> n >> x >> y;

    ll l = 0; // l is bad
    ll r = 1; // r is good
    while(!isGood(r)){
        r *= 2;
    }

    while(r > l + 1){
        ll m = (r + l) / 2;
        if(isGood(m)){
            r = m;
        }else {
            l = m;
        }

    }

    cout << r << endl;

    return 0;
}