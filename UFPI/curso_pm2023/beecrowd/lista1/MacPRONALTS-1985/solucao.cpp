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

int main(int argc, char const *argv[]){
    optimize;

    double precos[1010];
    precos[1001] = 1.5;
    precos[1002] = 2.5;
    precos[1003] = 3.5;
    precos[1004] = 4.5;
    precos[1005] = 5.5;

    int N;
    cin >> N;

    double soma = 0;
    while(N--){
        int produto;
        int qnt; 

        cin >> produto >> qnt;

        soma += (precos[produto] * qnt);
    }

    cout << fixed << setprecision(2) << soma << endl;

    return 0;
}