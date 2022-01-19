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

/*
Problema
Nós temos n cordas, o comprimento da i-ésima corda é ai. Queremos cortar k pedaços do mesmo
comprimento deles. De todos os métodos de corte, você precisa escolher aquele em 
que o comprimento das peças cortadas é máximo.
Solução: 
Pegar o valor de m e passar para a função que divide todos os tamanho das cordas pelo m
e vai somando, se o valor das cordas for maior que K o numero de pedaços, retorna 1/true
ou 0/false. Caso seja verdadeiro, l = m, caso não r = m. No final print l, que é o comprimento 
máximo de pedaços que podem ser cortados.
OBS: É um bom método, mas não o mais eficiente, pois toda vez que chamar isGoor(passando m)
ela vai testar n vezes, e isso vezes 100 que o maximo de interações.


*/

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int n, k;
vector<int> a;
const int maxInterations = 100;

bool isGood(double x){
   int s = 0;
   for (int i = 0; i < n; i++)
   {
       s += floor(a[i] / x);
   }

   return s >= k;
}

int main(int argc, char const *argv[]){
    optimize;

    cin >> n >> k;
    a.resize(n);

    for (int i = 0; i < n; i++)
    {
       cin >> a[i];
    }
    
    double l = 0; // is good
    double r = 1e9; // is bad
    
    for (int i = 0; i < maxInterations; i++)
    {
        double m = (r + l) / 2;
        if(isGood(m)){
            l = m;
        }else{
            r = m;
        }
    }

    cout << setprecision(20) << l << endl;
    
    return 0;
}