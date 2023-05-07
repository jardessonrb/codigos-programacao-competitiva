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
#define split(str) vector<string> split(string str){vector<string> strs; istringstream(str); string substr; while(getline(iss, strspli, ':')){strs.push_back(strspli)}return strs;}

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int main(int argc, char const *argv[]){
    optimize;

    // string myString = "Hello, World! This is a sample string.";
    string myString;

    getline(cin, myString);
    
    istringstream iss(myString);
    vector<string> words;
    // char operador;

    // cin >> operador;

    // Split the string by space
    string word;
    while (getline(iss, word, ':')) {
        words.push_back(word);
    }

    // Print the resulting words
    for (const auto& w : words) {
        cout << w << endl;
    }
    
    return 0;
}