#include <bits/stdc++.h>


using namespace std;
int pai[100000], N;

vector<int> conjuntos[1000000];

int find(int x){

    if(x == pai[x]) return x;


    return pai[x] = find(pai[x]);

}

void join(int u, int v){


    u = find(u);
    v = find(v);

    if(u == v) return;

    if(conjuntos[u].size() > conjuntos[v].size())
        swap(u, v);


    pai[u] = v;

    for(int x : conjuntos[u]){
        conjuntos[v].push_back(x);
    }

    conjuntos[u].clear();
}

int main(int argc, char const *argv[]){
    int M;

    cin >>N >> M;

    for(int i = 1; i <= N; i++)
    {
        pai[i] = i;
        conjuntos[i].push_back(i);
    }
    string op;


    while(M--)
    {
        int u, v;

        cin>> op >> u >> v;

        if(op == "union") join(u, v);

        else cout<< (find(u) == find(v) ? "YES" : "NO") << endl;

        // join(u, v);

        // for(int i = 1; i <= N; i++)
        // {
        //     //cout << find(i) << " \n"[i == N];
        //     if(conjuntos[i].empty()) continue;

        //     for(int x : conjuntos[i])
        //     {
        //         cout << x << " ";
        //     }

        //     cout << endl;
        // }
    }


    return 0;
}