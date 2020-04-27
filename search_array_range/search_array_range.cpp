ass Solution {
public:
    int binary_search(vector<int>& nums, int target, int left, int right, bool bleft) {
	int mid = 0;
	bool flag = false;
	int ans = -1; 

	while (left <= right) {
		mid = left + (right - left) / 2;
		
		if (nums[mid] < target) {
			left = mid+1;
		}
		else if(nums[mid] > target) {			
			right = mid-1;
		}
		else {
			flag = true;
			break;
		}
	}

	if (flag) {
		int rs; 
		if (bleft)
			rs = binary_search(nums, target, 0, mid-1, bleft);
		else 
			rs = binary_search(nums, target, mid+1, nums.size()-1, bleft);
		
		if (rs == -1) {
			ans = mid;
		}
		else {
			ans = rs;
		}
	}
	
	return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
	int left = 0, right = nums.size()-1, mid = 0;
	vector<int> ans = {-1,-1};
	bool flag = false;
	
	while (left <= right) {
		
		mid = left + (right - left) / 2;

		if (nums[mid] < target) {
			left = mid+1;
		}
		else if(nums[mid] > target) {			
			right = mid-1;
		}
		else {
			flag = true;
			break;
		}
		
	}
	
	int l = -1, r = -1;
	if (flag) {
		l = binary_search(nums, target, 0, mid-1, true);
		ans[0] = (l == -1 ? mid : l);		
		r = binary_search(nums, target, mid+1, nums.size()-1, false);		
		ans[1] = (r == -1 ? mid : r);
	}
	
	return ans;	
}

};
