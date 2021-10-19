#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 100010
#define MAXV 1010
#define ll long long
#define ld long double
#define INF 2000000020LL
#define endl '\n'

using namespace std;

string entrada;
int gl = 0,pl = 0, gr = 0, pr = 0;
char vez = 'E';
void result()
{
    if(pl >= 5 or pr >= 5)
    {
        if(pl - 2 >= pr or pl == 10)
        {
            gl++;
        }
        if(pr - 2 >= pl or pr == 10)
        {
            gr++;
        }
    }
    if(vez == 'E')
    {
        cout<<gl<<" ("<<pl<<"*) - "<<gr<<" ("<<pr<<")"<<endl;
    }
    else
    {
        cout<<gl<<" ("<<pl<<") - "<<gr<<" ("<<pr<<"*)"<<endl;
    }
}

int main(int argc, char const *argv[]){
    optimize;

    cin>> entrada;
    for(int i = 0; i < (int)entrada.size(); i++)
    {
        if(entrada[i] != 'Q')
        {
            
        }
        else{

            result();
        }

        //(esc == true) ? esc = false : esc = true;
    }

    return 0;
}