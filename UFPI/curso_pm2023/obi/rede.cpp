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


int main(int argc, char const *argv[]){
    optimize;

    int N;
    cin >> N;

    vector<int> valores(N);

    for (int i = 0; i < N; i++)
    {   
        cin >> valores[i];
    }

    sort(ALL(valores));

    int inicio = 0, fim = N - 1;
    int busca = valores[0];
    int ans = -1;
    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        if(valores[meio] <= busca){
            inicio = meio + 1;
        }else {
            ans = valores[meio];
            fim = meio - 1;
        }
    }

    // cout << "ANS: " << ans << endl;
    
    ans = (ans == -1 ? busca : ans);

    cout << (ans == busca ? ans : busca + 1) << endl;
    
    return 0;
}   