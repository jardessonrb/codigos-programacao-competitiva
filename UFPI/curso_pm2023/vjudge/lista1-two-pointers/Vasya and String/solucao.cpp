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

    int N, V;
    string palavra;
    cin >> N >> V;
    cin >> palavra;

    int inicio = 0, fim = N - 1;
    int trocai = V, trocaj = V;
    int ca = 0, cb = 0;
    for(int i = 0; i < N; i++){
        if(palavra[i] == 'a'){
            ca++;
        }else {
            cb++;
        }
    }
    char letrai = ca >= cb ? 'a' : 'b';
    char letraj = letrai;
    int somai = 0, ansi = 0, somaj = 0, ansj = 0;
    int ultimoi = 0, ultimoj = N - 1;
    while(inicio < N && fim >= 0){
        if(letrai == palavra[inicio]){
            somai++;
            ansi = max(ansi, somai);
        }else {
            if(trocai > 0){
                somai++;
                trocai--;
                ansi = max(ansi, somai);
                // ultimoi = max(ultimoi, inicio);
            }else {
                somai = 0;
                trocai = V;
                // inicio = ultimoi;
            }
        }

        if(letraj == palavra[fim]){
            somaj++;
            ansj = max(ansj, somaj);
        }else {
            if(trocaj > 0){
                somaj++;
                trocaj--;
                ansj = max(ansj, somaj);
                // ultimoj = max(fim, ultimoj);
            }else {
                somaj = 0;
                trocaj = V;
                // fim = ultimoj;
            }
        }

        inicio++;
        fim--;
    }

    cout << max(ansi, ansj) << endl;
    return 0;
}