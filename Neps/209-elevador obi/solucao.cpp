#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define MODULO(x) ((x)>=0?(x):-(x)) 

using namespace std;
int N;

vector<pair<int, bool>> boxes;


bool descer(int peso)
{
    for(auto x : boxes)
    {
        if(x.second == true)
        {
            if(MODULO(x.first - peso) <= 8)
            {
                x.second = false;

                return  true;
            }
        }
    }
    return false;
}

int main(int argc, char const * argv[]){

    int x, mn = 1000000;
    cin>>N;

    for (int i = 0; i < N; i++)
    {
        cin>>x;

        boxes.emplace_back(x, false);
    }
    bool flag = true;
    while(flag)
    {
        for(auto x : boxes)
        {
           if(x.second == false)
           {
               if(x.first - 8 > 8)
               {
                   if(descer(x.first)) x.second = true;
               }
           }
        }
        
    }

    return 0;
}