#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	vector<int> ans;
	set<int> s1(nums1.begin(), nums1.end());
	set<int> s2(nums2.begin(), nums2.end());
	set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), insert_iterator< vector<int> > (ans, ans.begin()));
	return ans; 

}

int main(int argc, char* argv[]) {
	
	int a[] = {1,2,2,1};
	int b[] = {2,2};	
	vector<int> output;

	vector<int> nums1(a, a+sizeof(a)/sizeof(int));
	vector<int> nums2(b, b+sizeof(b)/sizeof(int));

	output = intersection(nums1, nums2);	

	for (int i=0; i<output.size(); ++i) {
		cout << output[i] << "" << endl;
	}

	return 0;
}
