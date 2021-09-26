#include <bits/stdc++.h>


using namespace std;
int pai[100000], N;

int find(int x){

    if(x == pai[x]) return x;


    return pai[x] = find(pai[x]);

}

void join(int u, int v){


    u = find(u);
    v = find(v);

    if(u == v) return;

    pai[u] = v;
}

int main(int argc, char const *argv[]){

    cin>>N;

    for(int i = 1; i <= N; i++)
        pai[i] = i;
    
    while(true)
    {
        int u, v;

        cin>> u >> v;

        join(u, v);

        for(int i = 1; i <= N; i++)
            cout << find(i) << " \n"[i == N];
    }


    return 0;
}