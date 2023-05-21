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

    cin >> N;
    map<string, bool> banco;
    map<string, int> freq;

    while(N--){
        string nome;

        cin >> nome;

        if(!banco[nome]){
            banco[nome] = true;
            freq[nome]  = 1;
            cout << "OK" << endl;
        }else {
            stringstream novoNome;
             
            novoNome << nome << freq[nome]++;

            banco[novoNome.str()] = true;
            freq[novoNome.str()] = 1;

            cout << novoNome.str() << endl;
        }
    }

    return 0;
}