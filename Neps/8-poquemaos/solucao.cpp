#include <bits/stdc++.h>
#define max 3

using namespace std;
int N, X, Y, Z, val[max];

void ordenar(int val[]){
    int temp;

    for (int i = 0; i < max; i++)
    {
        for (int j = i+1; j < max; j++)
        {
            if(val[i] > val[j]){
                temp   = val[i];
                val[i] = val[j];
                val[j] = temp;
            }
            
        }
        
        
    }
}

int main(int argc, char const *argv[]){
    int som = 0, num;

    cin>>N>>X>>Y>>Z;

    val[0] = X;
    val[1] = Y;
    val[2] = Z;
    

    ordenar(val);

    for (int i = 0; i < max; i++)
    {
        if(val[i] <= N){
            N = N - val[i];
            som++;
        }
    }

    cout<<som<<endl;
    
    return 0;
}