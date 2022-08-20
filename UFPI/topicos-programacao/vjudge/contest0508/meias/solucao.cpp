#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    int L = 2 * N;
    long long meias[L];
    int sobre = 0;
    int maior = -1;
    map<int, bool> vistos;
    for (int i = 0; i < L; i++)
    {
        cin >> meias[i];
    }

    for (int i = 0; i < L; i++)
    {
        if(!vistos[meias[i]]){
            vistos[meias[i]] = true;
            sobre++;
            maior = max(maior, sobre);
        }else {
            sobre--;
        }
    }
    
    
    cout << maior << endl;
    return 0;
}
