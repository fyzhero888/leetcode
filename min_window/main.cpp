#include <iostream>
#include <string>
#include <unordered_map>
#include <math.h>

using namespace std;

string minWindow(string s, string t) {
	string ans;
	unordered_map<char, int> map;
	unordered_map<char, int> cmap;
	
	// create map
	for (int i=0; i<t.length(); ++i) {
		map[t[i]]++;
	}	
	
	cmap = map;
	
	for (int i=0; i<t.length(); ++i) {
		map[t[i]]--;
	}	
	

	int l_idx = 0, r_idx = 0;	
	int t_total = cmap.size();
	int t_count = 0; 
	int min_len = s.length();
	bool move_r = true;

	while (1) {
	
		if (move_r) {

			if (r_idx >= s.length())
				break ;
			
			if (t_count < t_total) {
				if (map.find(s[r_idx]) != map.end()) {
					map[s[r_idx]]++;	
					if (map[s[r_idx]] == cmap[s[r_idx]]) {
						
						cout << "t_count++" << endl;
						t_count++;
					}
				}
				r_idx++;
			}

			if (t_count == t_total)
			{
				int new_min = r_idx - l_idx;
				cout << "r: " << r_idx << " " << l_idx << endl;
				if (new_min <= min_len) {
					ans = s.substr(l_idx, new_min);
					min_len = new_min;
				}
				move_r = false;
			}
		}
		else {
			if (map.find(s[l_idx]) != map.end()) {
				map[s[l_idx]]--;

				cout << "l_idx: " << l_idx  << " " << map[s[l_idx]]<< endl;
				if (map[s[l_idx]] < cmap[s[l_idx]]) {
					move_r = true;
					//r_idx++;
					t_count--;

					int new_min = r_idx - l_idx;
					
					if (new_min <= min_len) {
						
						cout << "l: " << r_idx << " " << l_idx << " min_len: " << new_min << endl;
						ans = s.substr(l_idx, new_min);
						min_len = new_min;
					}
				}
				
			}

			l_idx++;	
		}
	}

	return ans;
}

int main(int argc, char* argv[]) {

	cout << "result: " << minWindow("ADOBECODEBANC", "ABC") << endl;	
	//cout << "result: " << minWindow("AA", "AA") << endl;	
	return 0;
}
