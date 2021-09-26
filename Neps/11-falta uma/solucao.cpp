#include <bits/stdc++.h>

using namespace std;
int N;
map<int, int> teste;


int fatorial(int num){

    if(num == 1 || num == 0) return 1;

   return num * fatorial(num - 1);
}

int main(int argc, char const *argv[]){
    cin>>N;
    int res = fatorial(N) - 1;

    int matriz[res][N];
    int num;
    for (int i = 0; i < res; i++)
    {
        for(int j=0; j < N; j++){
            cin>>num;
            matriz[i][j] = num;
            teste[num] = 0;
        }

    }

    int t = 0, chave;
    vector<int> seque;
    while (t < N)
    {   int c = 0, valor, ans = 100000000;
        while(c != res)
        {
            chave = matriz[c][t];
            teste[chave]++;
            c++;
        }
        for (int i = 1; i <= N; i++)
        {
            if(ans > teste[i])
            {
                ans = teste[i];
                valor = i;
            } 
            teste[i] = 0;
        }
        seque.push_back(valor);
        t++;

    }

    for (int i = 0; i < (int)seque.size(); i++)
    {
       cout<<seque[i]<<" ";
    }

    cout<<endl;
    
    return 0;
}