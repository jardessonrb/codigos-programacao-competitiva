#include <bits/stdc++.h>


using namespace std;

int N, A, B, ans=0;

vector<pair<int, int>> cidades[1000000];

int caminhar(int x, int y)[
    int con = 1;

    return con;    
}

int main(int argc, char const *argv[]){
    int P, Q, D;
    cin>>N>>A>>B;

    for (int i = 1; i < N; i++)
    {
        cin>>P>>Q>>D;

        cidades[P].push_back({Q, D});
        cidades[Q].push_back({P, D});
       
    }

    // for(auto x : cidades[2])
    // {
    //     cout<<x.first<<" ===== "<<x.second<<endl;
    // }

    caminhar(A, B);


    cout<<ans<<endl;


    return 0;
}