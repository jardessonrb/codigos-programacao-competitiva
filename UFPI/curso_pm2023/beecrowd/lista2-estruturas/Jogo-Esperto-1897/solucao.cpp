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
int N, M, cont = 0, vezes = 0;
set<string> operacoes({"mult2", "mult3", "div2", "div3", "sum7", "sub7"});
map<int, bool> mapa;
set<int> valores;

int mult2(int num) {return num * 2;}
int mult3(int num) {return num * 3;}
int div2(int num) {return num / 2;}
int div3(int num) {return num / 3;}
int sum7(int num) {return num + 7;}
int sub7(int num) {return num - 7;}

int calcular(string expre, int num){
    if(expre == "mult2") return mult2(num);
    if(expre == "mult3") return mult3(num);
    if(expre == "div2") return div2(num);
    if(expre == "div3") return div3(num);
    if(expre == "sum7") return sum7(num);
    else return sub7(num);
}

int calc(int origem , int destino){
    if(origem == destino) return 0;

    map<int, bool> visitados;
    map<int, int> profundidade;
    queue<int> valores;
    valores.push(origem);
    profundidade[origem] = 0;
    visitados[origem] = true;
    int valorCalc;
    int ans = 0;
    while(!valores.empty()){
        valorCalc = valores.front();
        valores.pop();
        for(auto exp : operacoes){
            int valor = calcular(exp, valorCalc);
            if(!visitados[valor]){
                visitados[valor] = true;
                profundidade[valor] = profundidade[valorCalc] + 1;
                valores.push(valor);
            }
            
            if(valor == destino){
                return profundidade[valor];
            }
        }
        ans++;
    }  

    return ans;
}

int main(int argc, char const *argv[]){
    optimize; 

    cin >> N >> M;

    cout << calc(N, M) << endl;
    for(auto x : valores)
        cout << x << " ";

    return 0;
}