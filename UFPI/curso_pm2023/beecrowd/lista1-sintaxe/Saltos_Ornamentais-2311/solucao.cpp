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

class Competidor {
    private:
        string nome;
        double difi;
        double notas[7];

    public:
    Competidor(string nome, double dif){
        this->nome = nome;
        this->difi = dif;
        // this->notas = new double[7];
        // memcpy(this->notas, pontos, 7 * sizeof(double));
    }
    void addNota(double nota){
        int size = sizeof(this->notas) / sizeof(double);
    }

    ~Competidor() {
        delete[] notas; 
    }

    void apresentar(){
        sort(this->notas, this->notas + 7);

        double soma = 0;
        for (int i = 1; i < (7 - 1); i++)
        {
           soma += this->notas[i];
        }
        
        double pontos = soma * this->difi;

        cout << this->nome << " " << fixed << setprecision(2) << pontos << endl;
    }
    
};

int main(int argc, char const *argv[]){
    optimize;

    int N;
    cin >> N;
    cin.ignore();
    vector<Competidor> competidores;

    while(N--){
        string nome;
        double difi;
        // double notas[7];
        double minima = 11, maxima = -1, total = 0;

        // cin >> nome;
        getline(cin, nome);

        cin >> difi;

        for (int i = 0; i < 7; i++)
        {
            double nota;
            cin >> nota;

            minima = min(nota, minima);
            maxima = max(nota, maxima);
            total += nota;
        //    cin >> notas[i];
        }
        cin.ignore();

        cout << nome << " " << fixed << setprecision(2) << (total - (minima + maxima)) * difi << endl;

        // Competidor competidor(nome, difi, notas);
        // competidores.push_back(competidor);
    }

    // for(Competidor competidor : competidores)
    //     competidor.apresentar();

    return 0;
}