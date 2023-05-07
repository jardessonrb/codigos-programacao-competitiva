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

bool isTagAbertura(char tag) {
    return tag == '(' || tag == '{' || tag == '[';
}

bool isMatch(char top, char tag) {
    return (top == '(' && tag == ')') || (top == '{' && tag == '}') || (top == '[' && tag == ']');

}

int main(int argc, char const *argv[]){
    optimize;

    int N;

    cin >> N;

    // cout << N << endl;

    while(N--){
        string cadeia;
        stack<char> tags_abertura, tags_fechamento;
        cin >> cadeia;

        // cout << "Cadeia: "<< cadeia << endl;

        for (int i = 0; i < cadeia.size(); i++)
        {
            if(isTagAbertura(cadeia[i])){
                tags_abertura.push(cadeia[i]);
            }else{

                if(!tags_abertura.empty() && isMatch(tags_abertura.top(), cadeia[i])){
                    tags_abertura.pop();
                }else{
                    tags_fechamento.push(cadeia[i]);
                }
            }
        }

        // cerr << tags_abertura.size() << " " << tags_fechamento.size() << endl;

        cout << ((tags_abertura.size() == 0 && tags_fechamento.size() == 0) ? "S" : "N") << endl;
        
    }

    return 0;
}