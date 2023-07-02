#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 200020
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 1000000
#define endl '\n'

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

vector<pair<int, int >> listaAdj[MAXN];
int vertices, arestas;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> filaDePrioridade;  
map<int, int> valores;
int dijkstra(int origem, int destino){
    int vetorDistancia[vertices];
    int visitados[vertices];

    for (int i = 0; i < vertices; i++)
    {
        vetorDistancia[i] = INF;
        visitados[i] = false;
    }

    vetorDistancia[origem] = 0;
    filaDePrioridade.push(make_pair(vetorDistancia[origem], origem));

    while(!filaDePrioridade.empty()){
        pair<int, int> verticeTopo = filaDePrioridade.top();
        int vertice = verticeTopo.second;
        filaDePrioridade.pop();

        if(visitados[vertice] == false){
            visitados[vertice] = true;

            vector<pair<int, int>>::iterator iterador;
            for(iterador = listaAdj[vertice].begin(); iterador != listaAdj[vertice].end(); iterador++){
                int vertice2 = iterador->first;
                int custoAresta = iterador->second;

                if(vetorDistancia[vertice2] > (vetorDistancia[vertice] + custoAresta)){
                    vetorDistancia[vertice2] = vetorDistancia[vertice] + custoAresta;
                    filaDePrioridade.push(make_pair(vetorDistancia[vertice2], vertice2));
                }
            }
        }
    }

    return vetorDistancia[destino];
}


int main(int argc, char const *argv[]){
    optimize;
    
    cin >> vertices >> arestas;

    for (int i = 0; i < arestas; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;

        listaAdj[a].push_back(make_pair(b, c));
    }

    int servidor, minimo = INF, maximo = -INF;
    cin >> servidor;

    for (int i = 0; i <= vertices; i++)
    {
        valores[i] = dijkstra(servidor, i);
    }

    for(auto x : valores){
        cout << "key: " << x.first << " valor " << x.second << endl;
    }
    // cout << maximo - minimo << endl;    

    return 0;
}