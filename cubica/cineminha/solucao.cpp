#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[]){

    int v[4], maior=0, p, r, i;

    for (int i = 0; i < 4; i++)
    {
       cin>>v[i];
       if(maior < v[i]) maior = v[i];
    }

    return 0;
}