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

int main(int argc, char const *argv[]){
    optimize;

    int N;

    cin >> N;

    vector<int> teams(N);

    for (int i = 0; i < N; i++)
        cin  >> teams[i];
    
    sort(ALL(teams));

    set<int> sizes;

    int inicial = 0, fim = 0;
    int valor = teams[0];
    int ans = -1;
    while (inicial < N && fim < N)
    {
        if(teams[fim] - valor > 5){
            ans = max(ans, (fim - inicial));
            while(inicial < fim){
                if(teams[fim] - teams[inicial] <= 5){
                    valor = teams[inicial];
                    break;
                }

                inicial++;
            }
        }

        fim++;

        if(fim == N){
            ans = max(ans, (fim - inicial));
        }
    }

    cout << ans << endl;

    return 0;
}