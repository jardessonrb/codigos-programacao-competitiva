#include <bits/stdc++.h>

using namespace std;

vector<int> mesas;
int N, res;
int main(int argc, char const *argv[]){
    cin>>N;

    for (int i = 1; i <= N; i++)
    {
       mesas.push_back(i);
    }

    if(N%2 == 1){

        res = N/2 + 1;
    }
    else{

        res = N-1;
    }

    cout<<res<<endl;

    return 0;

}