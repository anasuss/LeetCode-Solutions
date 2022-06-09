class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> u;
        int result = 0;
        for (const auto& x : nums)
        {
            u[x]++;
        }
        for (const auto& x : nums)
        {
            if (!u[x - 1])
            {
                int i = 0;
                while (u[x + i])
                {
                    i++;
                }
                result = max(result, i);
            }
        }
        return result;
    }
};