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
int p;
string base;
map<char, int> contagem;
unordered_set<char> letras;
int main(int argc, char const *argv[]){
    optimize;
    cin >> p;
    cin >> base;
    
    for (int i = 0; i < base.size(); i++)
    {
        contagem[base[i]]++;
        letras.insert(base[i]);
    }
    
    bool flag = true;
    int max = - INF, min = INF;

    for(auto x : letras){
        if(contagem[x] > max){
            max = contagem[x];
        }

        if(contagem[x] < min){
            min = contagem[x];
        }
    }
    int div = p / min;
    if(max <= 1){
        flag = false;
    }else{
        for(auto x : letras){
            if(contagem[x] % min != 0){
            flag = false;
            break;
            }
        }
    }
    
    string raiz = "";
    if(letras.size() > 1){
        for (int i = 0; i < div; i++)
        {
            raiz += base[i];
        }
    }else{
        raiz += base[0];
    }
    
    cout << (flag ? (raiz) : "*") << endl;
    
    

    return 0;
}