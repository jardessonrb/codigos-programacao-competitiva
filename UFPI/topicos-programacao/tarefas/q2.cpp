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

struct Filho {
    int ver, dis;
    Filho(int x = 0, int y = 0): ver(x), dis(y){}

    bool operator < (const auto &a){
        return dis < a.dis;
    }
};

vector<int> arvore[1000];
int distancia[1000];
int ans = 0;

vector<Filho> filhos;
vector<int> folhas;

int dfs(int x, int pai){

    if(arvore[x].size() == 1){
        distancia[arvore[x][0]] = 0;

        filhos.push_back({arvore[x][0], 0});
        folhas.push_back(arvore[x][0]);

        return 0;
    } 

    vector<int> dis;
    for(auto vertice : arvore[x]){
        if(vertice == pai) continue;

        int distVerice = dfs(vertice, x) + 1;
        filhos.push_back({vertice, distVerice});
        dis.push_back(distVerice);
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
    memset(distancia, 0, 1000);
    cout << "distancia : " << dfs(folhas[0], arvore[folhas[0]][0]) << endl;

    return 0;
}