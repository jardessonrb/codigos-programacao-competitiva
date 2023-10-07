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

    vector<int> cartas(N);
    for(auto &carta : cartas)
        cin >> carta;
    
    int inicio = 0, fim = N - 1, contSereja = 0, contDima = 0;
    bool vez = true;
    while(inicio <= fim){
        if(vez){
            if(cartas[inicio] > cartas[fim]){
                contSereja += cartas[inicio++];
            }else {
                contSereja += cartas[fim--];
            }

            vez = !vez;
        }else {
            if(cartas[inicio] > cartas[fim]){
                contDima += cartas[inicio++];
            }else {
                contDima += cartas[fim--];
            }
            vez = !vez;
        }
    }

    cout << contSereja << " " << contDima << endl;

    return 0;
}