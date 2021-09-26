#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){

    string s, n, v="";
    int t=0;

    cin>>s;
    fflush(stdin);
    cin>>n;


    for (int i = 0; i < (int)s.size(); i++)
    {
        for (int j = t; j < (int)n.size(); j++)
        {
           if(s[i] == n[j]){
               v += n[j];
               if(t < (int)n.size()) 
               {
                   t = j+1;
                   break;
               }
               
           }
        }       
    }

    if(s == v){
        cout<<"SIM"<<endl;
    }
    else{

        cout<<"NAO"<<endl;
    }

    

    return 0;
}