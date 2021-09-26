#include <bits/stdc++.h>

using namespace std;

int T, N,  K;

struct loja{
    float peso;
    float valor;
    int qnt;
};

int main(int argc, char const *argv[]){
    float a, b;
    int c;
    cin>>T;
    cin>>N>>K;

    while(T--){

        float valor = 0, mc=0;
        int s;
        loja pro[N];

        for (int i = 0; i < N; i++)
        {
            cin>>a>>b>>c;

            if(mc < c) s = i;

            pro[i].peso  = a;
            pro[i].valor = b;
            pro[i].qnt   = c;
        }

        float peso = 0;
        bool ok=true; 
        int t=0;   

        for(auto p : pro)
        {
        }

    cout<<valor<<endl;
    }
    

    return 0;
}