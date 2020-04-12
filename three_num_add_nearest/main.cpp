#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int threeSumClosest(vector<int>& nums, int target) {

	if (nums.size() == 1) {
		return nums[0];
	}else if (nums.size() == 2) {
		return nums[0] + nums[1];
	}else if (nums.size() == 3) {
		return nums[0] + nums[1] + nums[2];
	}

	// sort array
	sort(nums.begin(), nums.end());
	
	// output
	for (int i=0; i<nums.size(); ++i) {
		cout << nums[i] << " ";
	}
	cout << endl;


	// find closest nums
	int closest_num = nums[0]+nums[1]+nums[2], closest_diff = abs(closest_num-target);
	for (int i=0; i<nums.size()-2; ++i) {
		if (i > 0 && nums[i] == nums[i-1]) {
			continue;
		}	

		for (int L=i+1, R=nums.size()-1; L<R; ) {
			if (L > i+1 && nums[L] == nums[L-1]) {
				++L;
				continue ;
			}

			int sum = nums[L] + nums[i] + nums[R];
			if (sum - target == 0) {
				return sum;
			}
		
			if (sum - target > 0) {
				if (abs(sum - target) < closest_diff) {
					closest_diff = abs(sum - target);
					closest_num  = sum;
				}

				--R;
			}else{
				if (abs(sum - target) < closest_diff) {
					closest_diff = abs(sum - target);
					closest_num  = sum;
				}
				++L;
			}
		}			
	}

	return closest_num;
}

int main(int argc, char* argv[]) {

	int a[] = {0,1,1,1};
 	vector<int> input_num(a, a+sizeof(a)/sizeof(int));

	cout << "output: " << threeSumClosest(input_num, 100) << endl;	

	return 0;
}
