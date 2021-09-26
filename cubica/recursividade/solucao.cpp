#include <bits/stdc++.h>

using namespace std;


int fatorial(int valor){
    if(valor == 1 || valor == 0)
        return 1;
    else{
        return valor * fatorial(valor - 1);
    }
}

int multiplica(int num1, int num2){
    if(num1 == 0 || num2 == 0) return 0;

    else if(num2 == 1) return num1;

    else{
        return (num1 + multiplica(num1, num2 - 1));
    }
}

int main(int argc, char const *argv[]){
    int valor, num1, num2;

    cin>>valor>>num1>>num2;

    int fat = fatorial(valor);
    cout<<"Fatorial de "<<valor<<"=="<<fat<<endl;

    int mult = multiplica(num1, num2);

    cout<<"Multiplica("<<num1<<","<<num2<<") == "<<mult<<endl;
    
    return 0;
}