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
    string vazia;
    cin >> N;
    fflush(stdin);
    getline(cin, vazia);
    while(N--){
        map<string, int> arvores;
        string nome;
        double ans = 0;
        int maxPermitido = 1, cont = 0;
        bool isVazio = false;
        while(getline(cin, nome)){
            if(nome.empty() && !arvores.empty()){
                break;
            }

            if(nome.empty()){
                cont++;
                if(cont > maxPermitido){
                    isVazio = true;
                    break;
                }
            }

            if(!nome.empty()){
                arvores[nome]++;
                ans++;
            }
        }

        if(isVazio){
            cout << endl;
        }else {
            for(auto x : arvores){
                double valor = (x.second * 100) / ans;
                cout << x.first << " ";
                cout << fixed << setprecision(4) << valor << endl;
            }
            if(N != 0) {
                cout << "" << endl;
            }
        }

    }
    return 0;
}