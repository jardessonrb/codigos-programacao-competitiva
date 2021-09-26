#include <bits/stdc++.h>

using namespace std;

int N, p=0;

int main(int argc, char const *argv[]){

    cin>>N;
    
    int v[N];
    
    int ma = -999999, se = - 999999;
    
    for(int i=0; i<N;i++){
        cin>>v[i];
        
        if(ma < v[i]){
            p = i;
            ma = v[i];
        }   

    }

    for(int j=0; j<N;j++){
        
        if(se < v[j] && p != j){

            se = min(v[j], ma);
        }
         
    }
    
    
    cout<<(se*ma)<<endl;
    


    return 0;
}