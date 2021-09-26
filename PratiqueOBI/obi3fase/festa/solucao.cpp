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
int N, M, turno;
vector<int> suditos(1);

void remove(int t){
    int c = 1;
    int mult = c * t;
    queue<int> mt;
    for (int i = 1; i < suditos.size(); i++)
    {
        if(i*t > suditos.size()){
            break;
        }else{
            mt.push(i*t);
        }
    }

    while(!mt.empty()){
        suditos.erase(suditos.begin(), (suditos.begin() + mt.front()) - 1);
        mt.pop();
    }
    
}

int main(int argc, char const *argv[]){
    optimize;
    cin >> N;
    cin >> M;
    for (int i = 1; i <= N; i++)
    {
        suditos.push_back(i);
    }
    

    while(M--){
        cin >> turno;
        remove(turno);
    } 

    for(int i = 1; i < suditos.size(); i ++){
        cout << suditos[i] << " ";
    }

    return 0;
}