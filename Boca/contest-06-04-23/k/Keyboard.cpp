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
vector<int> palavra;
map<int, vector<int>> regs;
int cont = 1;
int neg = -2;

void marcarPar(int n, int m){
    while(n <= m){
        if(palavra[n] < 0){
            palavra[n] = neg;
            regs[neg].push_back(n);
        }

        if(palavra[m] < 0){
            palavra[m] = neg;
            regs[neg].push_back(m);
        }

        neg--;
        n++;
        m--;
    }
}

void marcarImpa(int n, int m){
    while(n <= m){

        if(n == m){
            if(palavra[n] < 0){
                palavra[n] = neg;
                regs[neg].push_back(n);
            }
            neg--;
        }else{
            if(palavra[n] < 0){
                palavra[n] = neg;
                regs[neg].push_back(n);
            }

            if(palavra[m] < 0){
                palavra[m] = neg;
                regs[neg].push_back(m);
            }
            neg--;
            n++;
            m--;
        }
    }
}

void marcarVisinho(int inicio, int valor, int valorAntigo){
    for(auto x : regs[valorAntigo]){
       palavra[x] = valor;
    }

    regs.erase(valorAntigo);
}

void isPalindron(int l, int r){
   if(palavra[l] == -1 && palavra[r] == -1){
        palavra[l] = cont;
        palavra[r] = cont;
        cont++;

        if((r - l) -1 % 2 == 0){
            marcarPar(l + 1, r - 1);
        }else {
            marcarPar(l + 1, r - 1);
        }
   }else {
        if(palavra[l] > 0){
            marcarVisinho(r, palavra[l], palavra[r]);
            palavra[r] = palavra[l];
        }else {
            palavra[l] =  palavra[r];
            marcarVisinho(l, palavra[r], palavra[r]);
        }
   }

}

void pergunta(int a, int b, int c, int d){
    if(b - a != d - c){
        cout << "Not equal" << endl;
        return;
    }


    while (a <= b && c <= d){
        if(palavra[a] < 0 && palavra[c] < 0){
            if(palavra[a] == -1 && palavra[c] == -1){
                cout << "Unknown" << endl;
                return;
            }
        }

        if(palavra[a] > 0 && palavra[c] < 0 || palavra[a] < 0 && palavra[c] > 0){
            cout << "Unknown" << endl;
            return;
        }

        if(palavra[a] != palavra[c]){
            cout << "Not equal" << endl;
            return;
        }
        a++;
        c++;
    }

    cout << "Equal" << endl;
    return;
}

int main(int argc, char const *argv[]){
    optimize;

    int N, M;
    cin >> N >> M;

    palavra.resize(N, -1);

    while(M--){
        int opc;
        cin >> opc;

        if(opc == 1){
            int l, r;
            cin >> l >> r;
            isPalindron(l - 1, r - 1);
            // for(auto x : palavra)
            //     cout << x << " ";
            // cout << endl;

        }else {
            int a, b, c, d;

            cin >> a >> b >> c >> d;

            pergunta(a - 1, b -1, c - 1, d - 1);
        }
    }

    return 0;
}