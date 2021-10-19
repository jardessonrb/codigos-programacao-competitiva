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

int a, b, s;
bool verify(string val){
    int cont = 0;
    for (int i = 0; i < val.size(); i++)
    {
        cont += val[i] - '0';
    }
    
    return cont == s;
}


int main(int argc, char const *argv[]){
    optimize;

    cin >> s >> a >> b;

    vector<string> vals;
    vector<int> valsInt;
    for (int i = a; i <= b; i++)
    {
        vals.push_back(to_string(i));
    }

    for (int i = 0; i < vals.size(); i++)
    {
        if(verify(vals[i])){
           valsInt.push_back(stoi(vals[i]));
        }
    }

    sort(ALL(valsInt));

    cout << valsInt[0] << endl;  
    cout << valsInt[valsInt.size() - 1] << endl;
    

    return 0;
}