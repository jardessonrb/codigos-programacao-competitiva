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

struct Vendedor {
    int num;
    int duracao;
    int somatorio;

    Vendedor(int x, int y, int z): num(x), duracao(y), somatorio(z){}

    bool operator > (const Vendedor &vendedor) const
    {
       if(duracao == 0 && vendedor.duracao == 0){
            return num > vendedor.num;
       }

       if(duracao != 0 && vendedor.duracao == 0 || vendedor.duracao != 0 && duracao == 0){
            return duracao > vendedor.duracao;
       }

       if(duracao != 0 && vendedor.duracao != 0){
            if(somatorio == vendedor.somatorio){
                return num > vendedor.num;
            }else {
                return somatorio > vendedor.somatorio;
            }
       }

       return false;
    }

    void soma(int soma){
        somatorio += soma;
    }
};

int main(int argc, char const *argv[]){
    optimize;

    int N, M;

    priority_queue<Vendedor, vector<Vendedor>, greater<Vendedor>> vendedores;
    queue<int> chamadas;
    map<int, int> registros;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        Vendedor vendedor({i, 0, 0});
        vendedores.push(vendedor);
        registros[i] = 0;
    }

    while(M--){
        int x;
        cin >> x;
        chamadas.push(x);
    }

    while(!chamadas.empty()){
        int valor =  chamadas.front();
        chamadas.pop();

        Vendedor vendedor = vendedores.top();
        vendedores.pop();

        vendedor.duracao = valor;
        vendedor.soma(valor);

        vendedores.push(vendedor);
        registros[vendedor.num]++;
    }

    for(auto x : registros){
        cout << x.first << " " << x.second << endl;
    }


    return 0;
}