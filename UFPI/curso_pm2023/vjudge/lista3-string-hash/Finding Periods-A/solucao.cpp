#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXV 1010
#define ll long long
#define ld long double
#define pii pair<int, int>
#define INF 2000000020LL
#define CASAS_PRECISAO 0.0000001
#define endl '\n'
#define check_in_matriz(l, c, minl, maxc) (l >= 0 && l < minl) && (c < maxc && c >= 0) && (!visitados[l][c])
//g++ -std=c++17 -O2 --static solucao.cpp

using namespace std;

const ll MOD = 1e9 + 9;
const ll base = 153;
const ll MAXN = 2e6 + 10;
ll expoents[MAXN];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

/*
input: abcabca
       abc-abc-abc : tamanho 3
       abcabc-abcabc : tamanho 6 por que completa
       abcabca : tamanho n(input.size()) por que ele sempre vai ser um prefixo dela mesma
Ideia do hash:
input e cada letra é Si i = 0 -> S.size()
S1.P^4 + S2.P^3+ S3.P^2 + S4.P^1 + S5

array[0] = "" = 0
array[1] = S1 = S1
array[2] = S1.S2 = S1.P^1 + S2
array[3] = S1.S2.S3 = S1.P^2 + S2.P^1+S3
array[4] = S1.S2.S3.S4 = S1.P^3 + S2.P^2+ S3.P^1 + S4
array[5] = S1.S2.S3.S4.S5 = S1.P^4 + S2.P^3 + S3.P^2 + S4.P^1 + S5

O(1) na busca por -> S[2, 4] = array[4] - array[1].P^3
-  S1.P^3 |+ S2.P^2+ S3.P^1 + S4| Só que array[1] = S1 e falta P^3 por isso fica - array[1].P^3
   S1

   O Exponte vem do tamanho do intervalo ou seja, -arra[i] . P^(4 - 1)
*/

int N;

void precalc(){
    expoents[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        expoents[i] = (expoents[i - 1] * base) % MOD;
    }
}

struct StringHash {
    vector<ll> hashs;

    StringHash(string& input){
        hashs = vector<ll>(input.length() + 1, 0);
        for (int i = 0; i < input.length(); i++)
        {
            hashs[i + 1] = ((hashs[i] * base) % MOD + input[i]) % MOD;
        }
    }

    ll get_hash(int a, int b) {
        return (MOD + hashs[b + 1] - (hashs[a] * expoents[b - a + 1]) %MOD)%MOD;
    }
};


bool check(StringHash& hash, int index){
    ll prefixoHash = hash.get_hash(0, index - 1);

    for (int i = 0; i < N; i += index)
    {
        if(i + index - 1 >= N){
            ll falta = N - i;

            if(hash.get_hash(0, falta - 1) !=  hash.get_hash(i, i + falta - 1)) return false;

        }else if (prefixoHash != hash.get_hash(i, (i + index - 1))){
            return false;
        }

    }
    
    return true;
}

signed main(int argc, char const *argv[]){
    optimize;

    precalc();
    string input;

    cin >> input;

    N = input.length();


    StringHash hash(input);

    vector<int> outputs;
    for (int i = 1; i <= input.length(); i++)
    {
        if(check(hash, i)) outputs.push_back(i);
    }

    // cerr << " qnt " << outputs.size() << endl;
    
    for (int i = 0; i < outputs.size(); i++)
    {
       cout << outputs[i];
       if(i + 1 < outputs.size()){
            cout << " ";
       }
    }
    cout << endl;
    

    return 0;
}