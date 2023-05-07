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
    // multiset<int> valuesset;
    map<int, int> contagem;
    stack<int> pilha;

    int N;

    cin >> N;

    while(N--){
        string opc;
        int value;

        cin >> opc;
        if(!strcmp(opc.c_str(), "PUSH")){
            cin >> value;
            // valuesset.emplace(value);
            pilha.push(value);
            contagem[value]++;
        }
        else if(!strcmp(opc.c_str(), "MIN")){
            if(pilha.empty()){
                cout << "EMPTY" << endl;
            }else {
                // auto min = valuesset.begin();
                auto minc = contagem.begin();
                // cout << (*min) << endl;
                cout << (*minc).first << endl;
            }
        }else if(!strcmp(opc.c_str(), "POP")){
            if(pilha.empty()){
                cout << "EMPTY" << endl;
            }else {
                int valuePop = pilha.top();
                pilha.pop();
                // valuesset.erase(valuePop);
                if(contagem[valuePop] <= 1){
                    contagem.erase(valuePop);
                }else {
                    contagem[valuePop]--;
                }
            }
        }
    }

    return 0;
}