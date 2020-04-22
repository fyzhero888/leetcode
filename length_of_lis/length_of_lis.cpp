class Solution {
public:
int lengthOfLIS(vector<int>& nums) {
	vector<int> dp;
	
	if (nums.size() <= 1) {
		return nums.size();
	}
	
	dp.push_back(nums[0]);
	for (int i=0; i < nums.size(); ++i) {
		if (nums[i] > dp.back()) {
			dp.push_back(nums[i]);
			//cout << "push: " << nums[i] << endl;
		}
		else {
			
			int left = 0, right = dp.size()-1;
			//cout << "dp size=" << dp.size() << endl;
			
			while (left < right) {
				int mid = left + (right - left) / 2;
				if (mid == left) {
					if (dp[mid] < nums[i]) {
						left = right;
					}
					break;
				}
				else {
					if (dp[mid] > nums[i]) {
						right = mid;
					}else {
						left = mid;
					}
				}
				
			}
			
			dp[left] = nums[i];
			//cout << "left: " << left << " ,nums[i]=" << nums[i] << endl;
		}
	}
	
	return dp.size();
}

};