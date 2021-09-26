#include <bits/stdc++.h>

using namespace std;

int T, N, K, t, z;

vector<pair<int, int>> val;


int main(int argc, char const *argv[]){
    cin>>T; //casos
    cin>>N>>K;

    for (int i = 0; i < N; i++)
    {
        cin>>t>>z;

        val.push_back(pair(t, z));
    }

    for(auto a : val)
        cout<<a.first<<a.second<<endl;
    




    return 0;
}    