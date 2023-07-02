#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 100010
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 100010
#define CASAS_PRECISAO 0.0000001
#define endl '\n'
//g++ -std=c++17 -O2 --static solucao.cpp

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int N;
vector<int> pedras;
int dp[MAXN];
int ans = 0;

int solve(int index){
    if(index <= 0) return 0;

    if(dp[index] != -1) return dp[index];

    int pi = solve(index - 1) + abs(pedras[index] - pedras[index - 1]);
    int pii = INF;
    if(index - 2 >= 0) pii = solve(index - 2) + abs(pedras[index] - pedras[index - 2]);

    return dp[index] = min(pi, pii);
   
}

int main(int argc, char const *argv[]){
    optimize;

    cin >> N;
    pedras.resize(N);

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < N; i++)
        cin >> pedras[i];

    cout << solve(N - 1) << endl;

    return 0;
}