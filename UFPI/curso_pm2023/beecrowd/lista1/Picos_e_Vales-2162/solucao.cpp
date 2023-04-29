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
    int alturas[N];

    for (int i = 0; i < N; i++)
    {
        cin >> alturas[i];
    }

    if(N < 2){
        cout << 1 << endl;
    }else {
        bool isPico = alturas[0] > alturas[1];
        bool valido = true;
        for (int i = 1; i < N; i++)
        {
           if(!isPico){
                if(alturas[i] <= alturas[i-1]){
                    valido = false;
                    break;
                }
           }else {
                if(alturas[i] >= alturas[i-1]){
                    valido = false;
                    break;
                }
           }

           isPico = !isPico;
        }
        
        cout << (valido ? 1 : 0) << endl;

    }

    return 0;
}