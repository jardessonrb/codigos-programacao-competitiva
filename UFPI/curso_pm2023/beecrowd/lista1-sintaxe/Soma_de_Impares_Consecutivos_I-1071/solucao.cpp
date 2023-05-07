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

bool isPar(int valor) {
    return (valor % 2) == 0;
}

int main(int argc, char const *argv[]){
    optimize;

    int x, y;
    int soma = 0;

    cin >> x >> y;

    for (int i = (min(x, y) + 1); i < max(x, y); i++)
        if(!isPar(i)) soma += i;

    cout << soma  << endl;

    return 0;
}