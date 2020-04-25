#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool find_next(vector<vector<char> >& board, vector<vector<int> >& flags, int m, int n, string& word, int idx) {

	if (idx == word.length()) {
		return true;
	}


	if (m < 0 || m >= board[0].size() || n < 0 || n >= board.size()) {
		return false;
	}

	if (flags[n][m] == 1) {
		return false;
	} 


	if (board[n][m] == word[idx]) {
		flags[n][m] = 1;

		// top
		if (find_next(board, flags, m, n-1, word, idx+1)) {
			return true;
		}

		// left	
		if (find_next(board, flags, m-1, n, word, idx+1)) {
			return true;
		}

		// right	
		if (find_next(board, flags, m+1, n, word, idx+1)) {
			return true;
		}
		
		// bottom
		if (find_next(board, flags, m, n+1, word, idx+1)) {
			return true;
		}
	}

	flags[n][m] = 0;
	return false;
}

bool exist(vector< vector<char> >& board, string word) {
	int m = board[0].size();
	int n = board.size();

	vector<vector<int> > flags(n, vector<int>(m, 0));
	

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			
			// this line is fucking fuck...
			//flags.clear();

			if (find_next(board, flags, j, i, word, 0)) {
				return true;	
			}
		}
	}


	return false;
}

int main(int argc, char* argv[]) {
	
	vector<vector<char> > board;
	string word = "ABCESEEEFS";

	board.push_back({'A', 'B', 'C', 'E'});
	board.push_back({'S', 'F', 'E', 'S'});
	board.push_back({'A', 'D', 'E', 'E'});

	cout << exist(board, word) << endl;

	return 0;
}
