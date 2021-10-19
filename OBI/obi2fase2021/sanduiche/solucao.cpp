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
int N, M;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};


bool ver(string n1, string n2){
    if(n1.size() < n2.size()) return false;

    int tamanho = n2.size(), p = 0;


    for (int i = 0; i < n1.size(); i++)
    {
        if(n1[i] == n2[p]){
            tamanho--;
            p++;
        }
    }

    return tamanho <= 0 ? true : false;
    
}


int main(int argc, char const *argv[]){
    optimize;

    cin >> N >> M;
    vector<string> possi, sabo;

    for (int i = 0, u, v; i < M; i++)
    {
        cin >> u >> v;
        possi.push_back(to_string(u) + to_string(v));
    }

    int pos = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < (N - i); j++)
        {
           pos++;
        }
    }
    
    int v = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 1 + i; j <= N; j++)
        {
            if(v < 1){
                sabo.push_back(to_string(j));
            }else{
                sabo.push_back(to_string(v) + to_string(j));
            }
        }
        v++;
    }

    if(pos > 1){
        pos += N - 2;
        string inicio = "12";
        for (int i = 3; i <= N; i++)
        {
            sabo.push_back(inicio + to_string(i));
        }
    } 

    for (int i = 0; i < possi.size(); i++)
    {
        for (int j = 0; j < sabo.size(); j++)
        {

            // cout << sabo[j] << " <- " << possi[i] << ((ver(sabo[j], possi[i])) ? " = true" : " = false") << endl;
            if(ver(sabo[j], possi[i])){
                sabo[j].erase();
                pos--;
            }
        }
        
    }
    
    cout << pos << endl;

    return 0;
}