#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int getDecimalValue(ListNode* head) {
            int result = 0;
            while (head) {
                result = result * 2 + head -> val; // This is double-dable technique, check for proof here: https://math.stackexchange.com/questions/2501253/algebraic-proof-of-the-double-dabble-method-algorithms-binary-numbers-to-deci
                head = head->next;
            }
            return result;
        }

}