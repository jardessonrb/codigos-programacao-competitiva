#include <bits/stdc++.h>

using namespace std;

bool ok = false;
queue<char> fila;

bool abre(char x){

    return (x == '(');

    return false;
}

int main(int argc, char const *argv[]){
    

    string S;

    cin>>S;

    for (int i = 0; i < (int)S.size(); i++)
    {
       if(abre(S[i]) == true){
           fila.push(S[i]);
       }
    }
    


    return 0;

}