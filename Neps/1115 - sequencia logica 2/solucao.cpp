#include <bits/stdc++.h>

using namespace std;
int p=1;

int main(int argc, char const *argv[]){
    int X, Y;

    cin>>X>>Y;

    for (int i = 1; i <= Y; i++)
    {

        if(p < X){
            cout<<i<<" ";
            p++;
        }else
        {
            cout<<i<<"\n";
            p = 1;
        }
        
        
        
    }

    cout<<""<<endl;
    
    return 0;
}