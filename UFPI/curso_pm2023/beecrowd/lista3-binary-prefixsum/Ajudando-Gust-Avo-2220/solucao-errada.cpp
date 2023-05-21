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

map<char, vector<int>> mapa;
vector<bool>  vistos;

int buscaBinaria(int index, vector<int> &indexs){
    int pos = INT_MAX;

    int fim = indexs.size() - 1, inicio = 0;
    while(inicio <= fim){
        int meio = (inicio + (fim - inicio) / 2);

        if(!vistos[indexs[meio]] && indexs[meio] >= index){
            pos = indexs[meio];
        }

        if(indexs[meio] >= pos){
            fim = meio - 1;
        }else {
            inicio = meio + 1;
        }
    }

    return pos;
}

int main() {

    int N;

    cin >> N;

    while (N--)
    {
        string A, B;

        cin >> A;
        cin >> B;

        vistos.resize(A.size(), false);

        for (int i = 0; i < A.size(); i++)
            mapa[A[i]].push_back(i);
        
        int maximo = A.size() / B.size() + 1;
        int ans = 0;

        while(ans < maximo){
            bool isSequenciaValida = true;
            int posAnterior = -1;
            for (int i = 0; i < B.size(); i++)
            {
                char letra = B[i];

                int pos = buscaBinaria(posAnterior + 1, mapa[letra]);
                if(pos != INT_MAX){
                    vistos[pos] = true;
                    posAnterior = pos;
                }else {
                    isSequenciaValida = false;
                }
            }

            if(isSequenciaValida){
                ans++;
            }else {
                break;
            }
        }

        mapa.clear();
        vistos.clear();
        cout << ans << endl;
    }
    
    return 0;

}