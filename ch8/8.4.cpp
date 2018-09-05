class Solution {
public:
    void helper(vector<int> &nums, vector<vector<int>> &sol, vector<int> &tmp, int start){
        sol.push_back(tmp);
        for(int i = start; i < nums.size(); i++){
            tmp.push_back(nums[i]);
            helper(nums, sol, tmp, i+1);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> tmp;
        helper(nums, sol, tmp, 0);
        return sol;
    }
}; 
