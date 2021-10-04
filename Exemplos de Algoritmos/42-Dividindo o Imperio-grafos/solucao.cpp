#include <bits/stdc++.h>


using namespace std;


vector<int> grafos[1000];
int N, ans=1000000000;

int dfs(int u, int pai){

    int sz = 1;

    for(int v: grafos[u])
    {
        if(v != pai)
        {
            int para_baixo = dfs(v, u);  

            int filho1 = para_baixo;
            
            int filho2 = N - para_baixo;

            ans = min(ans, abs(filho1 - filho2));

            sz += para_baixo;
        }

    }

    return sz;
}

int main(int argc, char const *argv[]){
    int u, v;
    cin>>N;

    for (int i = 1; i < N; i++)
    {
        cin>>u>>v;

        grafos[u].push_back(v);
        grafos[v].push_back(u);
    }

    dfs(1, -1);

    cout<< ans <<endl;
    

    return 0;
}