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

map<int, vector<string>> teclado;

bool verifica(int chave, char letra){
    string nome = "";
    for(auto x : teclado[chave]){
        nome += x;
    }

    for (int i = 0; i < nome.size(); i++)
    {
        if(nome[i] == letra){
            return true;
        }
    }
    

    return false;
}

int main(int argc, char const *argv[]){
    optimize;
    int M;
    string N, palavra;

    teclado[2].push_back("abc");
    teclado[3].push_back("def");
    teclado[4].push_back("ghi");
    teclado[5].push_back("jkl");
    teclado[6].push_back("mno");
    teclado[7].push_back("pqrs");
    teclado[8].push_back("tuv");
    teclado[9].push_back("wxyz");
    cin >> N;
    cin >> M;

    int cont = 0;
    while(M--){
        cin >> palavra;

        // if(palavra.size() != N.size()){
        //     continue;
        // }
        int ver = 0;
        for(int i = 0; i < palavra.size(); i++){
            if(verifica(N[i] - '0', palavra[i])){
                ver++;
            }else{
                break;
            }
        }

        if(ver >= N.size()){
            cont++;
        }
    }

    cout << cont << endl;

    return 0;
}