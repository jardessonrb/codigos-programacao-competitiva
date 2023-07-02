#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 200020
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
//#define endl '\n'

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};




int main(int argc, char const *argv[]){
    optimize;

    int L, C;
    cin >> L >> C;

    int quantidadeDeQuadradinhosInteiros = (L * C) + ((L - 1) * (C - 1));
    int quantidadeDeQuadradinhosPartidos = (2 * (L -1)) + (2 * (C - 1));

    cout << quantidadeDeQuadradinhosInteiros << endl;
    cout << quantidadeDeQuadradinhosPartidos << endl;

    return 0;
}