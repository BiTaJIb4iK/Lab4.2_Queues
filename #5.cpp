class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.size(), n = target.size();
        vector<bool> stamped(n, false);
        vector<int> result;

        auto canStamp = [&](int index) -> bool {
            bool stampedOnce = false;
            for (int i = 0; i < m; ++i) {
                if (target[index + i] == '?' || target[index + i] == stamp[i]) {
                    if (target[index + i] != '?') {
                        stampedOnce = true;
                    }
                } else {
                    return false;
                }
            }
            return stampedOnce;
        };

        auto doStamp = [&](int index) {
            for (int i = 0; i < m; ++i) {
                if (target[index + i] != '?') {
                    target[index + i] = '?';
                    stamped[index + i] = true;
                }
            }
        };

        int totalStamps = 0;
        while (totalStamps < n) {
            bool stampedOnce = false;
            for (int i = 0; i <= n - m; ++i) {
                if (canStamp(i)) {
                    doStamp(i);
                    result.push_back(i);
                    stampedOnce = true;
                }
            }

            if (!stampedOnce) {
                return {};
            }

            totalStamps += m;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
