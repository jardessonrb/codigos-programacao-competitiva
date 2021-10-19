#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()


using namespace std;
int L, C;
int main(int argc, char const * argv[]){
    
    cin>>L>>C;

    int matriz[L][C], x;
    for (int l = 1; l <= L; l++)
    {
        for (int c = 1; c <= C; c++)
        {
            cin>>x;
            matriz[l][c] = x;
        }
    }
    

    return 0;
}