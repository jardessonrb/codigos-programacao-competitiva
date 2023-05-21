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

int buscaBinaria(vector<int> &valores, int busca){
    int ans = -1;

    int inicio = 0, fim = valores.size() - 1;
    while(inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        if(valores[meio] == busca){
            ans = meio;
        }

        if(valores[meio] >= busca){
            fim = meio - 1;
        }else {
            inicio = meio + 1;
        }


    }

    return ans;
}

int main(int argc, char const *argv[]){
    optimize;

    int N, Q;


    int caso = 1;
    while(true)
    {
        cin >> N >> Q;
        if(N == 0 && Q == 0) break;

        vector<int> valores(N);
        for (int i = 0; i < N; i++)
        {
            cin >> valores[i];
        }

        sort(ALL(valores));

        // for(auto x : valores)
        //     cerr << x << " ";

        cout << "CASE# "<< caso << ":" << endl;
        while(Q--){
            int x;

            cin >> x;

            int pos = buscaBinaria(valores, x);

            if(pos == -1){
                cout << x << " not found" << endl;
            }else {
                cout << x << " found at " << pos + 1 << endl;
            }

        }
        caso++;
        
    }



    return 0;
}