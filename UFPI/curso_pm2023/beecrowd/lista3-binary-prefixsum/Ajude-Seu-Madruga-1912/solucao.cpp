#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 200020
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

int N, A;
vector<ll> alturas;

ld calcularArea(ld alturaCorte){
    ld area = 0.0;

    for (int i = 0; i < N; i++)
    {
        if(alturas[i] > alturaCorte) {
            area += (alturas[i] - alturaCorte);
            continue;
        }
        // if(alturas[i] < alturaCorte) break;
    }

    return area;
}

ld calcular(ld inicio, ld fim){
    ld alturaCorte = 0.0;

    while(abs(fim - inicio) > CASAS_PRECISAO){
        ld meio = (fim + inicio) / 2.0;

        ld area = calcularArea(meio);

        if(area >= A){
            inicio = meio;
            alturaCorte = fim;
        }else {
            fim = meio;
            alturaCorte = inicio;
        }
    }

    return alturaCorte;
}

int main(int argc, char const *argv[]){
    optimize;

    while((cin >> N >> A) && (N != 0 || A != 0)){
        alturas.resize(N);

        ld soma = 0.0;
        for (int i = 0; i < N; i++)
        {
            cin >> alturas[i];
            soma += alturas[i];
        }
        
        // sort(ALL(alturas));
        // reverse(ALL(alturas));

        if(soma == A){
            cout << ":D" << endl;
        }else if(soma < A){
            cout << "-.-" << endl;
        }else {

            ld inicio = 0, fim = 1e9, alturaCorte;

            alturaCorte = calcular(inicio, fim);

            cout << setprecision(4) << fixed << alturaCorte << endl;
        }

        alturas.clear();

    }

    return 0;
}