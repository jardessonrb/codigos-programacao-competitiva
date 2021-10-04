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

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
ll N; 

int moduloT(int valor){

    return valor < 0 ? (valor * (-1)) : valor;
}

int main(int argc, char const *argv[]){
    optimize;
    cin >> N; 
    int casas[N+1], R, D;

    cin >> R >> D;

    for (int i = 0; i < N; i++)
    {
        cin >> casas[i];


    }
    
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if(moduloT(R - casas[i]) <= D){
            ans++;
        }
    }
    
    
    cout << ans << endl;    

    return 0;
}