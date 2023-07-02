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
//g++ -std=c++17 -O2 --static solucao.cpp

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int h(int x, int M){

    int mod = x % M; 

    return mod;
}

int main(int argc, char const *argv[]){
    optimize;

    int N;

    cin >> N;

    while (N--)
    {
        int M, C, valor;

        cin >> M >> C;

        vector<int> tabela[M];
        set<int> mods;

        // memset(dp, -1, sizeof(dp));

        for (int i = 0; i < C; i++)
        {
            cin >> valor;

            int mod = h(valor, M);

            mods.insert(mod);
            tabela[mod].push_back(valor);

        }

        for (int x = 0; x < M; x++)
        {
            cout << x << " -> ";
            if(tabela[x].size() == 0){
                cout << "\\" << endl;
                continue;
            }else {
                for (int i = 0; i < tabela[x].size(); i++)
                {
                    cout << tabela[x][i] << " -> ";
                    if(i + 1 == tabela[x].size()){
                        cout << "\\" << endl;
                    }
                }
            }
        }

        if(N > 0){
            cout << endl;
        } 
    }
    

    return 0;
}