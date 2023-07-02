#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 1000010
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 1000020
#define CASAS_PRECISAO 0.0000001
#define endl '\n'
//g++ -std=c++17 -O2 --static solucao.cpp

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int N, M, T;

vector<int> blocos;
int dp[MAXN];

int calc(int comprimento){
    if(comprimento == 0) return 0;

    if(comprimento < 0) return INF;

    if(dp[comprimento] != -1) return dp[comprimento];

    int ans = INF;

    for(auto bloco : blocos)
    {
        ans = min(ans, calc(comprimento - bloco) + 1);
    }

    return dp[comprimento] = ans;
}


int main(int argc, char const *argv[]){
    optimize;

    cin >> T;

    while(T--){

        cin >> N >> M;

        blocos.resize(N);

        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < N; i++)
        {
            cin >> blocos[i];
        }

        for (int i = 0; i < M; i++)
            dp[i] = -1;
        
        cout << calc(M) << endl;
        
    }

    return 0;
}