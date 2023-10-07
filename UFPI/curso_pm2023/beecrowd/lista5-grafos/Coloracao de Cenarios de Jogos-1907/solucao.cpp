#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 101010
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define CASAS_PRECISAO 0.0000001
#define endl '\n'
#define check_in_matriz(l, c, minl, maxc) (l >= 0 && l < minl) && (c < maxc && c >= 0) && (!imagem[l][c])
//g++ -std=c++17 -O2 --static solucao.cpp

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int N, M;
vector<vector<int>> matriz;

void dfs(int linha, int coluna){
    if(matriz[linha][coluna] == 1) return;

    matriz[linha][coluna] = 1;

    for (int i = 0; i < 4; i++)
    {
        int mlinha = linha + dx[i];
        int mcoluna = coluna + dy[i];

        if((mlinha >= 0 && mlinha < N) && (mcoluna < M && mcoluna >= 0)){
            if(matriz[mlinha][mcoluna] == 0){
                dfs(mlinha, mcoluna);
            }
        }
    }

}

int main(int argc, char const *argv[]){
    optimize;

    cin >> N >> M;

    char pixel;
    matriz.resize(N + 1, vector<int>(M + 1));
    for (int i = 0; i < N; i++)
    {
        for (int l = 0; l < M; l++)
        {
            cin >> pixel;
            matriz[i][l] = (pixel == '.' ? 0 : 1);
        }
        
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int l = 0; l < M; l++)
        {
            if(matriz[i][l] == 0){
                ans++;
                dfs(i, l);
            }
        }
        
    }

    cout << ans << endl;
    
    return 0;
}