class Solution {
public:
static bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
	return a.second > b.second;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
	
	unordered_map<int, int> map;
	vector<pair<int, int>> vsort;
	vector<int> ans;
	
	for (auto i : nums) {
		if (map.find(i) == map.end()) {
			map[i] = 1;
		}
		else {
			++map[i];
		}
	}
	
	for (unordered_map<int, int>::iterator itr = map.begin(); itr != map.end(); ++itr) {
		pair<int, int> tmp;
		tmp.first = itr->first;
		tmp.second = itr->second;
		
		vsort.push_back(tmp);
	}
	
	sort(vsort.begin(), vsort.end(), cmp);
	
	for (int i=0; i<k; ++i) {
		ans.push_back(vsort[i].first);
	}
	
	return ans;
}
};
