#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

bool is_number(char t) {
	if (t >= '0' && t <= '9')
		return true;

	return false;
}

string _decode_substr(string& input, int& idx) {
	string txt;

	while (idx < input.length()) {
		if (is_number(input[idx])) {
			string strrep;
			int irep = 0;
			
			strrep += input[idx];
			++idx;

			while (input[idx] != '[') {
				strrep += input[idx];	
				++idx;
			}
			
			irep = atoi(strrep.c_str());
			cout << "irep: " << irep << endl;	
			
			++idx;
			string sub = _decode_substr(input, idx);
			cout << "sub: " << sub << endl;
	
			for (int i=0; i<irep; ++i) {
				txt += sub;
			}

		}else {
			if (input[idx] == ']') {
				++idx;
				break;
			}else {
				txt += input[idx];
				++idx;
			}
		}
	}

	return txt;
}

string decodeString(string s) {
	string ans;

	int idx = 0;
	ans = _decode_substr(s, idx);
	cout << ans << endl;
	
	return ans;
}

int main(int argc, char *argv[]) {
	
	decodeString("2[abc]3[cd]ef");
	return 0;
}
