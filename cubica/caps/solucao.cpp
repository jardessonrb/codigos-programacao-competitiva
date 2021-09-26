#include <bits/stdc++.h>

using namespace std;

int reint(char x){

    return x ;
}

char rechar(int x){

    return x;
}

int c=0;

int main(int argc, char const *argv[]){

    string s;

    cin>>s;

    int max = (int)s.size();

    int v[max];

    for (int i = 0; i < max; i++)
    {
        int z = reint(s[i]);
        if(z < 91){
            c++;
            v[i] = (z + 32);

        }else{

            v[i] = z;
        }
        
    }

    string t="";

    for (int i = 0; i < (int)s.size(); i++)
    {

        if(reint(s[0]) > 96 && c == (max-1)){
            c=max;
            t += rechar(v[i] - 32);
        }else
        {
            t += rechar(v[i]);
        }
        

    }


    if(c == 0){
        cout<<s<<endl;
    }else{
        cout<<t<<endl;
    }

    

    return 0;
}
