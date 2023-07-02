#include <bits/stdc++.h>
#define max 10000000

using namespace std;

int p = -1, city = 1;


void ordenar(int mvet[], int cvet[], int pos){
    int tempM, tempC, pos2 = pos+1;

    for (int i = 0; i < pos2; i++)
    {
        for (int j = i+1; j < pos2; j++)
        {
            if(mvet[i] > mvet[j]){
                tempM   = mvet[i];
                tempC  = cvet[i];
                mvet[i] = mvet[j];
                cvet[i] = cvet[j];
                mvet[j] = tempM;
                cvet[j] = tempC;
            }
            
        }
        
        
    }
}

int main(int argc, char const *argv[]){

    while(p != 0)
    {
        int N, m, c, mtotal = 0, ctotal = 0;
        cin>>N;
        if(N != 0)
        {
            int mvet[N], cvet[N];
        
            for (int i = 0; i < N; i++)
            {
                cin>>m>>c;
                mvet[i] = m;
                cvet[i] = c;            
            
            }

            ordenar(mvet, cvet, N);

            cout<<"Cidade# "<<city<<":"<<endl;

            for (int i = 0; i < N; i++)
            {
                mtotal += mvet[i];
                ctotal += cvet[i];
                cout<<mvet[i]<<"-"<<(cvet[i] / mvet[i])<<" ";
            }

            cout<<endl;

            float div = ((float)ctotal / mtotal);
            cout<<fixed;
            cout<<"Consumo medio: "<<setprecision(3)<<div<<"\b m3.\n\n";

            city++;

        }else{

            p = 0;
            break;
        }
        

    }
    return 0;
}