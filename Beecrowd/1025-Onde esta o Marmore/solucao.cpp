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


int N, Q;
vector<int> valores;

int verifica(int chute){
    for (int i = 0; i < valores.size(); i++)
    {
        if(chute == valores[i]){
            return i + 1;
        }
    }

    return -1;
}

int main(int argc, char const *argv[]){
    optimize;
    int valor, caso = 1;

    while(true){
        cin >> N >> Q;

        if(N == 0 && Q == 0){
            break;
        }

        for (int i = 0; i < N; i++)
        {
            cin >> valor;
            valores.push_back(valor);
        }

        sort(ALL(valores));

        cout << "CASE# "<< caso << ":" << endl;

        for (int i = 0; i < Q; i++)
        {   
            int chute;
            cin >> chute;

            int res = verifica(chute);
            if(res == -1)
            {
                cout << chute <<" not found" << endl;

            }else{
                cout << chute <<" found at "<< res << endl;
            }
        }

        valores.clear();
        caso++;
    }

    return 0;
}