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
            
            int pos = 0, neg = 0, sum = 0;
            for(int i = 1; i < values.size(); i++)
            {
                int sign = values[i - 1] - values[i];
                if (sign >= -3 && sign <= 3)
                {
                    if(sign > 0)
                        pos++;
                    else if(sign < 0)
                        neg++;
                    else if(sign == 0)
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }

            if(pos == values.size() - 1 || neg == values.size() - 1)
            {
                sum++;
            }

            ans += sum;
            getline(cin, input);
    }

    cout << ans;
    return 0;
}