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
int N; // Quantidade de elementos
vector<int> pilha; //Para pegar o valor mais facilmente

int main(int argc, char const *argv[]){
    optimize;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
       int value;
       cin >> value;

       vector<int>::iterator left = lower_bound(pilha.begin(), pilha.end(), value);

       if(left == pilha.end()){
           pilha.push_back(value);
       }else {
           *left = value;
       }

    }

    cout << "MSC de tamanho " << pilha.size() << endl;
    for(auto x : pilha){
        cout << x << " ";
    }
    

    return 0;
}