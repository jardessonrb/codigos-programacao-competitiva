#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 200020
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define endl '\n'

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

struct Piloto{
    int numero;
    ll total;
    vector<ll> tempos;

    Piloto(int x): numero(x){}

    bool operator < (const auto &a){
        return total < a.total;
    }
};

void split(string str){
    char *ptr; // declare a ptr pointer
    ptr = strtok(str, ":"); // use strtok() function to separate string using comma (,) delimiter
    while (ptr != NULL)
    {
        cout << ptr  << endl; // print the string token
        // ptr = strtok (NULL, ":");
    }
}

int main(int argc, char const *argv[]){
    optimize;

    int T, V;
    string teste;
    cin >> teste;

    split(teste);

    // cin >> T >> V;

    // while(T--){

    // }
    

    return 0;
}