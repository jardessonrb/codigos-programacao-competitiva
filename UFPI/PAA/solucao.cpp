#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 8
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define endl '\n'

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int maxVertices = 8; //Quantidade de pares de vertices ou arestas
vector<int> vertices[1000000]; //todos os vertices do grafo com seus filhos adjacentes
vector<int> conjuntoDominante;
vector<bool> visitados(MAXN, false), dominados(MAXN, false), dominantes(MAXN, false);

//Essa é a função DFS - Busca em profundidade, que percorre o grafo
void dfs(int v){
    if(visitados[v] && (dominados[v] || dominantes[v])){ //Condição de parada - se o vertice já foi visitado 
        return;                                           // e marcado ele já não serve
    }
    
    if(!visitados[v] && !dominados[v]){//Verifica se ele já foi dominado, caso não, ele pode ser um dominante
        dominantes[v] = true; //marco como dominante
        visitados[v] = true; //marco como visitado
        conjuntoDominante.push_back(v); //Adiciono no conjunto

        for(auto vertice : vertices[v]){ //Como ele dominante marco todos os filhos como dominados
            dominados[vertice] = true;
        }
        
        for(auto vertice : vertices[v]){//Jogo para cada filho dele percorrer na função recursiva e aqueles que
            dfs(vertice);               //Que não foram vistos passaram do primeiro IF lá em cima
        }
    }

    if(dominados[v]){ //Se ele já foi dominado, então eu só preciso dele para percorrer para os próximos
        visitados[v] = true;
        for(auto vertice : vertices[v]){
            if(!visitados[vertice] && !dominados[vertice]){ //Basicamente eu só garanto a condição do IF de cima
                dfs(vertice);
            }
        }
    }
}

int main(int argc, char const *argv[]){
    optimize;
    int a, b, opc;
    cin >> opc; //Leio o vertice de partida

    for (int i = 0; i < maxVertices; i++)
    {
        cin >> a >> b; //Leio os pares de vertices
        vertices[a].push_back(b);
        vertices[b].push_back(a);
    }

    dfs(opc); //Chamdo a dfs para o vertice de partida

    cout << "conjunto dominante com " << opc << endl; //Mostro o conjunto dominante
    for(const auto x : conjuntoDominante){
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}