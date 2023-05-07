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

    while((cin >> N) && !cin.eof()){
        
        queue<int> fila;
        stack<int> pilha;
        priority_queue<int> prio;

        map<string, bool> estruturas;
        estruturas["stack"] = true;
        estruturas["queue"] = true;
        estruturas["priority queue"] = true;


        for (int i = 0; i < N; i++)
        {
            int opc, x;

            cin >> opc >> x;
            if(opc == 1){
                fila.push(x);
                pilha.push(x);
                prio.push(x);

            }else {
                int valorFila = fila.front();
                fila.pop();
                if(valorFila != x){
                    estruturas["queue"] = false;
                }

                int valorPilha = pilha.top();
                pilha.pop();
                if(valorPilha != x){
                    estruturas["stack"] = false;
                }

                int valorPrio = prio.top();
                prio.pop();
                if(valorPrio != x){
                    estruturas["priority queue"] = false;
                }
            }
        }

        vector<string> cont;
        for(auto x : estruturas){
            if(x.second){
                cont.push_back(x.first);
            }
        }

        if(cont.size() == 0){
            cout << "impossible" << endl;
        }else if(cont.size() > 1){
            cout << "not sure" << endl;
        }else {
            cout << cont[0] << endl;
        }
        
    }

    return 0;
}