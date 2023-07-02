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

int grafo[1001][1001];
bool visitados[1001][1001];
int ans = 0;
int L, C;

void dfs(int linha, int coluna){
    if(grafo[linha][coluna] == 2) return;

    visitados[linha][coluna] =  true;

    for (int i = 0; i < 4; i++)
    {
        int vlinha  = linha + dx[i];
        int vcoluna = coluna + dy[i];

        if((vlinha >= 0 && vlinha < L) && (vcoluna < C && vcoluna >= 0) && (!visitados[vlinha][vcoluna])){
            if(grafo[vlinha][vcoluna] == 1){
                ans++;
                dfs(vlinha, vcoluna);
            }
        }
    }
}

int main(int argc, char const *argv[]){
    optimize;


    cin >> L >> C;

    int valor;
    int vlinha, vcoluna;
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> valor;

            grafo[i][j] = valor;
            visitados[i][j] = false;

            if(valor == 3){
                vlinha = i;
                vcoluna = j;
            }
        }
        
    }

    dfs(vlinha, vcoluna);

    cout << (ans + 2) << endl;
    

    return 0;
}