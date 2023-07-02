#include <bits/stdc++.h>


using namespace std;

string init = "FACEECFAACFEACEF", repare = "FACE";
stack<char> face;
int N;

int verifica(vector<char> faces)
{
    bool yes = true;
    queue<char> res;
    int cont = 0;
    for (int i = 0; i < 4; i++)
    {
        if(face.top() != faces[i])
        {
            yes = false;
        }
        res.push(face.top());
        face.pop();       
    }

    if(yes == false)
    {
        for (int i = 0; i < 4; i++)
        {
            face.push(res.front());
            res.pop();
        }
        for (int i = 0; i < 4; i++)
        {
            face.push(faces[i]);
            
        }
    }else{
        cont += 1;
        if((int)face.size() == 0)
        {
            for (int i = 0; i < 4; i++)
            {
                face.push(repare[i]);

            }          

        }
    }
    

    return cont;
}

int main(int argc, char const *argv[]){
    int cont = 0;
    for (int i = 0; i < (int)init.size(); i++)
    {
        face.push(init[i]);
        
    }
        
    cin>>N;
    while(N--){
        char caracter;
        vector<char> faces;
        for (int i = 0; i < 4; i++)
        {  
            cin>>caracter;
            faces.push_back(caracter);
            
        }

        //cout<<faces[0]<<faces[1]<<faces[2]<<faces[3]<<endl;

        cont += verifica(faces);
    }
    

    cout<<cont<<endl;

    return 0;
}