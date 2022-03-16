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

int maxVertices = 6;
vector<int> vertices[1000000]; //todos os vertices do grafo
// map<int, vector<int>> conjDom; 
vector<int> conjDom[100]; 
vector<int> conjuntoDominante;
vector<bool> visitados(MAXN, false), dominados(MAXN, false), dominantes(MAXN, false);
int indexConjDom = 1;

int preProcessar(int vertice){
    int ans = 0;
    for(auto x : vertices[vertice]){
        if(!dominados[x] && !dominantes[x]){
            ans++;
        }   
    }
    return ans;
}

void dfs(int v){
    if(visitados[v] && (dominados[v] || dominantes[v])){
        return;
    }
    
    if(!visitados[v] && !dominados[v]){
        dominantes[v] = true;
        visitados[v] = true;
        conjuntoDominante.push_back(v);

        for(auto vertice : vertices[v]){
            dominados[vertice] = true;
        }

        for(auto vertice : vertices[v]){
            if((vertices[v].size() - 1) == preProcessar(vertice)){
                cout << "Vertice " << vertices[v].size() - 1 << " == " << v << " ANS = " << preProcessar(vertice) << endl;
                dominantes[vertice] = true;
                dominados[vertice] = false;
                visitados[vertice] = true;
                conjuntoDominante.push_back(vertice);
            }
        }

        for(auto vertice : vertices[v]){
            dfs(vertice);
        }
    }

    if(dominados[v]){
        visitados[v] = true;
        for(auto vertice : vertices[v]){
            if(!visitados[vertice] && !dominados[vertice]){
                dfs(vertice);
            }
        }
    }
    
}

int main(int argc, char const *argv[]){
    optimize;
    int a, b, opc;
    cin >> opc;
    for (int i = 0; i < maxVertices; i++)
    {
        cin >> a >> b;
        vertices[a].push_back(b);
        vertices[b].push_back(a);
    }

    dfs(opc);

    cout << "conjunto dominante com " << opc << endl;
    for(const auto x : conjuntoDominante){
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}