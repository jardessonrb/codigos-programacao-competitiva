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

int passos(char num1, char num2){
    int ans = 0;

    int val1 = num1 - '0';
    int val2 = num2 - '0';

    if(val1 == val2) return 0;

    int somaPraFrente = 0, valor = val1;
    while(valor != val2){
        valor += 1;
        somaPraFrente++;

        if(valor > 9){
            valor = 0;
        }
    }

    int somaPraTras = 0;
    valor = val1;
    while(valor != val2){
        valor -= 1;
        somaPraTras++;

        if(valor < 0){
            valor = 9;
        }
    }

    return min(somaPraFrente, somaPraTras);
}

int main(int argc, char const *argv[]){
    optimize;

    int N;
    cin >> N;

    string senha, atual;

    cin >> senha >> atual;

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += passos(senha[i], atual[i]);
    }
    
    cout << ans << endl;

    return 0;
}