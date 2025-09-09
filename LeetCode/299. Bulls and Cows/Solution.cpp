#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // Method 1
        // std::string getHint(std::string secret, std::string guess) {
        //     int n = secret.length();
        //     int bulls = 0, cows = 0;
        //     std::vector<int> count(10, 0);

        //     for(int i = 0; i < n; ++i) {
        //         int s = secret[i] - '0';
        //         int g = guess[i] - '0';

        //         if(s == g) {
        //             bulls++;
        //         } else {
        //             if(count[s] < 0) cows++;
        //             ++count[s];
        //             if(count[g] > 0) cows++;
        //             --count[g];
        //         }
        //     }

        //     return std::to_string(bulls) + "A" + std::to_string(cows) + "B";
        // }

        // Method 2 
        string getHint(string secret, string guess) {
            int n = secret.length();
            int bulls = 0, cows = 0;
            int total_matches = 0;

            vector<int> freq_s(10, 0);
            vector<int> freq_g(10, 0);

            for(int i = 0; i < n; ++i) {
                char s = secret[i];
                char g = guess[i];

                if(s == g) {
                    bulls++;
                }

                ++freq_s[s - '0'];
                ++freq_g[g - '0'];
            }

            for (int d = 0; d < 10; ++d) {
                total_matches += min(freq_s[d], freq_g[d]);
            }

            int cows = total_matches - bulls;
            return to_string(bulls) + "A" + to_string(cows) + "B";
        }


}


