#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 101010
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

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
bool matriz[101][101];

int N, Q;

int main(int argc, char const *argv[]){
    optimize;

    cin >> N >> Q;

    vector<int> valx, valy;

    for (int i = 0, a, b; i < Q; i++)
    {
        cin >> a >> b;
        valx.push_back(a);
        valy.push_back(b);

    }

    sort(ALL(valx));
    sort(ALL(valy));

    int point1 = 0, point2 = 1;
    int ans = 0;
    int ult = 0;
    while(point1 < Q){
        if(valx[point1] - ult <= 3){
            ans++;
        }

        point1++;
    }
    


    return 0;
}