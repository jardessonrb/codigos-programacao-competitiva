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

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

vector<int> arvore[1000];
int distancia[1000];

int dfs(int x, int pai){

    if(arvore[x].size() == 1){
        distancia[arvore[x][0]] = 0;
        return 0;
    } 

    vector<int> dis;
    for(auto vertice : arvore[x]){
        if(vertice == pai) continue;

        dis.push_back(dfs(vertice, x) + 1);
    }

    sort(ALL(dis));

    distancia[x] = dis[dis.size() - 1];
    return distancia[x];
}

int main(int argc, char const *argv[]){
    optimize;

    int vertices, arestas;

    cin >> vertices >> arestas;

    while (arestas--) {
       int a, b;
       cin >> a >> b;
       arvore[a].push_back(b);
       arvore[b].push_back(a);
    }

    dfs(1, 0);

    cout << " Distancia maxima ate a folha " << endl;
    for (int i = 1; i <= vertices; i++)
    {
        cout <<"[ " << i << " ] " << " " << distancia[i] << endl;
    }
    
    
    return 0;
}