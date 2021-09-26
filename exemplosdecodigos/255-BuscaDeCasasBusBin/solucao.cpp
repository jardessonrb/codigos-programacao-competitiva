#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define modulo(x) (x < 0 ? (x * (-1)) : x)
#define MAXN 100010
#define MAXV 1010
#define ll long long

using namespace std;

int nums[1000010];
int N, K;


//Complexidade => O log(N)

//OBS: Fazer o exercicio 261 - Ogros do Neps
bool busca(int x)
{   
    // jeito lento de fazer
    // for (int i = 1; i <= N; i++)
    //     if(nums[i] == x) return true;
    
    // return false;

    //Jeito rapido e mais correto
    int l = 1, r = N, m, ans;

    while(l <= r)
    {
        m = (l + r) / 2;

        if(nums[m] == x) return true;

        else if(nums[m] == x)
            l = m + 1;
        else
            r = m - 1;
        
        return false;
    }
}

int main(int argc, char const * argv[]){
    
    cin >>N; 

    for (int i = 1; i <= N; i++)
    {
        cin>> nums[i];
    }

    cin >>K;

    for (int i = 1; i <= N; i++)
    {
        if(busca(K - nums[i]))
        {
            int A = nums[i], B = K - nums[i];
            if(A > B) swap(A, B);

            cout<< A << " "<< B <<endl;
            break;
        }
    }
    
    
    return 0;
}