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

string sequencia, subsequencia;

bool isSequenciaValida(string &sub){
    int j = 0;

    for (int i = 0; i < sequencia.size() && j < sub.size(); i++)
    {
       if(sequencia[i] == sub[j]){
            j++;
       }
    }
    

    return j == sub.size();
}

bool validarSequencia(int tamanho){
    string aux = "";

    for(auto &x : subsequencia)
        for (int i = 0; i < tamanho; i++)
           aux += x;
    
    return isSequenciaValida(aux);
}

int main(int argc, char const *argv[]){
    optimize;

    int N;

    cin >> N;

    while(N--){

        cin >> sequencia >> subsequencia;

        int inicio = 0, fim = sequencia.size() / subsequencia.size(), ans = 0;

        while (inicio <= fim)
        {
           int meio = (fim + inicio) / 2;

           if(validarSequencia(meio)){
                ans = meio;
                inicio = meio + 1;
           }else {
                fim = meio - 1;
           }

        }
        
        cout << ans << endl;

    }


    return 0;
}