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

void adv_tokenizer(string s, char del)
{
    stringstream ss(s);
    string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        cout << word << endl;
    }
}
 

int main(int argc, char const *argv[]){
    optimize;
    vector<string> palavras;
    int N;

    while(N--){
        string palavra;
        string alunos;

        cin >> palavra;
        cin >> alunos;
        string p;
        
        adv_tokenizer(alunos, ' ');
        
    }
    

    return 0;
}