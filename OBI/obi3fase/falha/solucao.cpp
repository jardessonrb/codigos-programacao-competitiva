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

int isContido(string s1, string s2){
    int res = 0;
    bool flag = true;
    for (int i = 0; i < s1.size(); i++)
    {
        if(s1[i] == s2[0]){
            res = 1;
            int p = i;
            for (int j = 0; j < s2.size(); j++)
            {
                if((s1[p] != s2[j]) and (p < s1.size())){
                    // cout << p << s1[p] << " - " << s2[j] << endl;
                    return -1;
                }
                p++;
            }
            if(flag) break;
            
        }
    }

    return res;
    
}

int main(int argc, char const *argv[]){
    optimize;
    int N;
    vector<string> senhas;
    queue<string> fila;
    int cont = 0;
    cin >> N;

    while(N--){
        string senha;
        cin >> senha;
        senhas.push_back(senha);
        fila.push(senha);
    }

    while(!fila.empty()){
        bool passo = true;
        for (int i = 0; i < senhas.size(); i++)
        {
            if(fila.front() == senhas[i] and passo){
                passo = false;
                continue;
            }else if(fila.front() == senhas[i] and !passo){
                if(isContido(fila.front(), senhas[i]) == 1){
                    cont++;
                }
            }else if(fila.front() != senhas[i] && fila.front().size() >= senhas[i].size()){
                // cout << fila.front() << "  " << senhas[i] << endl;
                if(isContido(fila.front(), senhas[i]) == 1){
                    cont++;
                }
            }
            
        }
        fila.pop();         
    }

    cout << cont << endl;
    

    return 0;
}