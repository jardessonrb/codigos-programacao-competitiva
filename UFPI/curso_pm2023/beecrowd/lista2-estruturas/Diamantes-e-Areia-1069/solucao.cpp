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

int isTagDiamente(char tag){
    if(tag == '<') return 1;
    else if(tag == '>') return -1;
    else return 0;
}

bool isMatch(char top, char tag){
    return top == '<' && tag == '>';
}

int main(int argc, char const *argv[]){
    optimize;

    int N;

    cin >> N;

    while(N--){
        string diamantes;
        int ans = 0;
        stack<char> tags_abertura;
        cin >> diamantes;

        for (int i = 0; i < diamantes.size(); i++)
        {
           if(isTagDiamente(diamantes[i]) == 1){
                tags_abertura.push(diamantes[i]);
           }else {
                if(isTagDiamente(diamantes[i]) == -1){
                    if(!tags_abertura.empty() && isMatch(tags_abertura.top(), diamantes[i])){
                        tags_abertura.pop();
                        ans++;
                    }
                }
           }
        }

        cout << ans << endl;
        
    }

    return 0;
}