class Solution {
    public:
        int balancedString(string s) {
            int n = (int)s.size();
            int target = n / 4;
            auto idx = [&](char c)->int{
                if (c=='Q') return 0;
                if (c=='W') return 1;
                if (c=='E') return 2;
                return 3; // 'R'
            };
            
            array<int,4> cnt = {0,0,0,0};
            for (char c : s) cnt[idx(c)]++;
            auto ok = [&](){
                for (int k=0;k<4;k++) if (cnt[k] > target) return false;
                return true;
            };
            if (ok()) return 0;
            
            int ans = n;
            int l = 0;
            for (int r=0;r<n;r++){
                cnt[idx(s[r])]--; // lấy s[r] khỏi phần ngoài
                while (l<=r && ok()){
                    ans = min(ans, r - l + 1);
                    cnt[idx(s[l])]++; // trả lại s[l] ra ngoài
                    l++;
                }
            }
            return ans;
        }
    };
    