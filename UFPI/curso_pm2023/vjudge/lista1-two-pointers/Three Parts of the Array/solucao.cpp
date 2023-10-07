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

    vector<int> valores(N);
    for (int i = 0; i < N; i++)
        cin >> valores[i];
    
    int inicio = 0, fim = N - 1;
    ll somai = 0, somaj = 0;
    vector<ll> vetori(N);
    vector<ll> vetorj(N);

    while(inicio <= N && fim >= 0){
        somai += valores[inicio];
        vetori[inicio] = somai;

        somaj += valores[fim];
        vetorj[fim] = somaj;

        inicio++;
        fim--;
    }

    ll ans = 0;
    int limit =  N / 2 + 1;
    inicio = 0;
    fim    = N - 1;
    while (inicio < fim)
    {
        if(vetori[inicio] < vetorj[fim]){
            inicio++;
        }else if(vetori[inicio] > vetorj[fim]){
            fim--;
        }else{
            ans = max(ans, vetori[inicio]);
            inicio++;
            fim--;
        }

    }
    

    // for(auto x : vetori)
    //     cout << x << " ";

    // cout << endl;
    // for(auto x : vetorj)
    //     cout << x << " ";
    // cout << endl;
    

    cout << ans  << endl;
    

    return 0;
}