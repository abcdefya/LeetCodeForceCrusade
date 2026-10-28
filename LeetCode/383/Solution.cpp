class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_set<char> letters(ransomNote.begin(), ransomNote.end());
        for (char c : letters) {
            if (count(ransomNote.begin(), ransomNote.end(), c) >
                count(magazine.begin(), magazine.end(), c))
                return false;
        }
        return true;
    }
};