#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


using namespace std;


int main(){


    string input;
    getline(cin, input);
    vector<long long> L, R;


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
       
        L.push_back(stoi(l));
        R.push_back(stoi(r));


        getline(cin, input);
    }
   
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());


    int ans = 0;
    for(int i = 0; i < L.size(); i++){
        ans += abs(L[i] - R[i]);
    }
   
    cout << ans << endl;
   
}
