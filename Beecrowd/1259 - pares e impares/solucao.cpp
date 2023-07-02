#include <bits/stdc++.h>

using namespace std;

vector<int> pa, im, td;
int N;

int main(int argc, char const *argv[]){
    cin>>N;

    for (int i = 0; i < N; i++)
    {
        int n;
        cin>>n;

        if(n%2 == 0) 
        {
            pa.push_back(n);
        }
        else{
            im.push_back(n);
        }
    }

    sort(pa.begin(), pa.end());

    for (int i = 0; i < pa.size(); i++)
    {
        td.push_back(pa[i]);
    }

    sort(im.begin(), im.end());

    for (int i = 0; i < pa.size(); i++)
    {
        td.push_back(im[i]);
    }
    

    for (int i = 0; i < N; i++)
    {
        cout<<td[i]<<endl;
    }
    
    
    return 0;

}