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
//g++ -std=c++17 -O2 --static solucao.cpp

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

vector<string> split(string frase){
    vector<string> palavras;
    stringstream iss(frase);
    string palavra;

    while(iss >> palavra){
        palavras.push_back(palavra);
    }

    return palavras;
}

int main(int argc, char const *argv[]){
    optimize;

    int M, N;
    cin >> M >> N;

    map<string, int> dic;
    while(M--){
        string palavra;
        int valor;
        cin >> palavra >> valor;
        dic[palavra] = valor;
    }

    while(N--){
        string frase;
        ll soma = 0;

        while(getline(cin, frase) && frase != "."){
        //    cout << frase << endl;
            vector<string> palavras = split(frase);
            for(string palavra : palavras){
                // cout << palavra << "=" << endl;
                if(dic.find(palavra) != dic.end()){
                    // cout << palavra << endl;
                    soma += dic[palavra];
                }
            }
        }

        cout << soma << endl;
    }

    return 0;
}