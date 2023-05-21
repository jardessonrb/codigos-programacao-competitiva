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

int busca(vector<int> &valores, int busca){
    int ans = -1;

    int inicio = 0, fim = valores.size() - 1;

    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        if(busca >= valores[meio]){
            ans = meio;
            inicio = meio + 1;
        }else {
            fim = meio - 1;
        }
    }
    return ans == -1 ? 0 : ans+1;
}

int main(int argc, char const *argv[]){
    optimize;

    int N;

    cin >> N;
    vector<int> shops;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        shops.push_back(x);
    }

    sort(ALL(shops));

    int Q;
    cin >> Q;

    while(Q--){
        ll opc;

        cin >> opc;

        int qnt = busca(shops, opc);

        cout << qnt << endl;
    }
    

    return 0;
}