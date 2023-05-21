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

    int N, T;

    cin >> N >> T;

    vector<pair<int, int>> cartas(N + 1);

    for (int i = 1; i <= N; i++)
       cin >> cartas[i].first;

    for (int i = 1; i <= N; i++)
       cin >> cartas[i].second;
    
    vector<int> prefix_sum(N + 1, 0), qnt(N + 1, 0);

    while(T--){

        int i, j;

        cin >> i >> j;

        qnt[i] += 1;
        qnt[j + 1] -= 1;        
    }

    for (int i = i; i <= N; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + qnt[i];
    }

    for (int i = 1; i <= N; i++)
    {
        if(prefix_sum[i] % 2 == 0){
            cout << cartas[i].first << " ";
        } else {
            cout << cartas[i].second << " ";
        }
    }
    
    return 0;
}