#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(){

    string input;
    getline(cin, input);
    int ans = 0; 

    while(!input.empty())
    {
            vector<int> values;
            istringstream str(input);
            int value;

            while(str >> value)
            {
                values.push_back(value);
            }

            vector<int> update_values;
            int checkSum[100007] = {0};

            for(int i = 1; i < values.size(); i++)
            {
                update_values.push_back(abs(values[i] - values[i - 1]));
                checkSum[abs(values[i] - values[i - 1])]++;
            }
            int sum = 1;
            for(int i = 0; i < update_values.size(); i++)
            {
                if(checkSum[update_values[i]] == 1)
                {
                    sum = 0;
                }
            }  
            ans += sum;
            getline(cin, input);
    }

    cout << ans;
    // Incorrect/Low
    return 0;
}