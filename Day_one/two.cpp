#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    string input;
    getline(cin, input);
    long long L[100007] = {0};
    long long R[100007] = {0};
    vector<pair<long long, long long>> duplas;

    while(!input.empty())
    {
        string l = "", r = "";
        int direction = -1;
        for(int i = 0; i < input.size(); i++)
        {
            if(input[i] != ' ')
            {
                if(direction == -1)
                {
                    l += input[i];
                }
                else if(direction == 1)
                {
                    r += input[i];
                }
            }
            else
            {
                direction = 1;
            }
        }

        L[stoi(l)]+=stoi(l);
        R[stoi(r)]+=stoi(r);

        duplas.push_back({stoi(l),stoi(r)});

        getline(cin, input);
    }

    long long ans = 0;
    for(long long i = 0; i < duplas.size(); i++){
        ans += L[duplas[i].second];
    }
   
    cout << ans << endl;
   
}