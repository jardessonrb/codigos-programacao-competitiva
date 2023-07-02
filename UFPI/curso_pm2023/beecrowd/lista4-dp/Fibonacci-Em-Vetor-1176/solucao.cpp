#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 101010
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

ll fibonacci[MAXN];
bool calculado[MAXN];

ll calc(int valor){
    if(valor < 2) return valor;

    if(calculado[valor]) return fibonacci[valor];

    calculado[valor] = true;

    fibonacci[valor] =  calc(valor - 1) + calc(valor - 2);

    return fibonacci[valor];
}

int main(int argc, char const *argv[]){
    optimize;

    fibonacci[0] = 0;
    fibonacci[1] = 1;
    calculado[0] = calculado[1] = true;

    int N;

    cin >> N;

    while(N--){
        int valor;

        cin >> valor;

        cout << "Fib("<< valor << ") = " << calc(valor) << endl;
    }

    return 0;
}