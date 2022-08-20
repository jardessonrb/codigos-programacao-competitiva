#include <bits/stdc++.h>

using namespace std;

bool abertura(char x){
    return x == '{' || x == '[' || x == '(';
}

bool match(char topo, char x){
    if(topo == '{' & x == '}') return true;
    if(topo == '[' & x == ']') return true;
    if(topo == '(' & x == ')') return true;

    return false;
}

int main(int argc, char const *argv[])
{
    int N;
    string letras;

    cin >> N;

    while(N > 0){
        cin >> letras;
        int size = letras.length();
        stack<char> chars;
        int fecha = 0;

        for (int i = 0; i < size; i++)
        {   
           if(abertura(letras[i])){
                chars.push(letras[i]);
           }else {
                if(!chars.empty()){
                    char topo = chars.top();
                    if(match(topo, letras[i])){
                        chars.pop();
                    }else {
                        fecha++;
                    }
                }else {
                    fecha++;
                    break;
                }
           }
        }
        cout << ((chars.size() == 0 & fecha == 0) ? "YES" : "NO") << endl;
        N--;
    }


    return 0;
}
