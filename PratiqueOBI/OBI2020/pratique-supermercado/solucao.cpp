#include <bits/stdc++.h>

using namespace std;

int N;

int main(int argc, char const *argv[]){
    float preco, menorValor = 100000.00, div = 1000.0;
    int gramas;
    cin>>N;

    for (int i = 0; i < N; i++)
    {
        cin>>preco>>gramas;

        if(menorValor > (preco / gramas))
        {
            menorValor = (preco / gramas);
        }

        
    }
    
    cout<<setprecision(4)<<(float)(menorValor * div)<<endl;
    

    return 0;
}