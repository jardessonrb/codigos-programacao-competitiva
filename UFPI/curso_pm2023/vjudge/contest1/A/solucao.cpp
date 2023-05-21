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

int main(int argc, char const *argv[]){
    optimize;

    int N;

    queue<ll> fila;

    cin >> N;
    
    while(N--)
    {
        int opc;
        ll value;

        cin >> opc;

        if(opc == 1){
            cin >> value;

            fila.push(value);
        }else if(opc == 2){
            if(!fila.empty()){
                fila.pop();
            }
        }else {
            if(fila.empty()){
                cout << "Empty!" << endl;
            }else {
                cout << fila.front() << endl;
            }
        }

    }

    return 0;
}