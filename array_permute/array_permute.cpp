class Solution {
public:
void get_next(vector<int>& nums, vector<int>& out, unordered_set<int>& exist_set, vector<vector<int>>& ans) {
	
	for (int i=0; i<nums.size(); ++i) {
		if (exist_set.find(nums[i]) == exist_set.end()) {
			out.push_back(nums[i]);
			exist_set.insert(nums[i]);
			
			if (out.size() == nums.size()) {
				ans.push_back(out);
				out.pop_back();
				exist_set.erase(nums[i]);
				
				return ;
			}
			
			get_next(nums, out, exist_set, ans);
			
			out.pop_back();
			exist_set.erase(nums[i]);
		}
	}
	
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> ans;
	vector<int> out;
	unordered_set<int> exist_set;
	
	get_next(nums, out, exist_set, ans);
	
	return ans;
}
};
