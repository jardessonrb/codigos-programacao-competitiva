#include <bits/stdc++.h>
#define max 1000

using namespace std;

int main(){
    int T, N[max], index = 0;
    cin >> T;

    while(index < max){
        for (int i = 0; i < T; i++)
        {
            N[index] = i;
            index++;
        }
    }

   for (int i = 0; i < max; i++)
    {
        cout << "N["<<i<<"] = "<<N[i]<<endl;
    }
    

    return 0;
}