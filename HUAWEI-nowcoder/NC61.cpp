class Solution {
public:
    /**
     * 
     * @param numbers int整型vector 
     * @param target int整型 
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        unordered_map<int, int> hash;
        vector<int> res;
        for (int i = 0; i < numbers.size(); ++i) {
            if (hash.find(target - numbers[i]) != hash.end()) {
                res = {hash[target - numbers[i]], i + 1};
                break;
            } else {
                hash.emplace(numbers[i], i + 1);
            }
        }
        return res;
    }
};