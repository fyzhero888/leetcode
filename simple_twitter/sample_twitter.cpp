struct twitter_context {
	int tweetId;
	int time;
};

bool cmp(const twitter_context& a, const twitter_context b) {
	return a.time > b.time;
}
	
class Twitter {

private:
	int _timestamp;
	
	unordered_map<int, vector<twitter_context>> _tweet_list;
	unordered_map<int, unordered_set<int>> _follow_list;
	
public:
    /** Initialize your data structure here. */
    Twitter() {
		_timestamp = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
		++_timestamp;
		twitter_context tc;
		tc.tweetId = tweetId;
		tc.time = _timestamp;
		
		unordered_map<int, vector<twitter_context>>::iterator itr = _tweet_list.find(userId);
		
		if (itr == _tweet_list.end()) {	
			vector<twitter_context> vt;
			vt.push_back(tc);
			
			_tweet_list[userId] = vt;
		}
		else {
			itr->second.push_back(tc);
		}
		
    }
    

	
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
		++_timestamp;
		
		vector<int> output;
		
		vector<twitter_context> tc_list;
		
		// find self tweet context
		unordered_map<int, vector<twitter_context>>::iterator itr = _tweet_list.find(userId);
		if (itr != _tweet_list.end()) {	
			tc_list = itr->second;
		}
		
		// find followed user tweet context
		unordered_map<int, unordered_set<int>>::iterator itr_f = _follow_list.find(userId);
		if (itr_f != _follow_list.end()) {
			
			for (unordered_set<int>::iterator itr_tmp = itr_f->second.begin();
				itr_tmp != itr_f->second.end(); ++itr_tmp) {
					
					unordered_map<int, vector<twitter_context>>::iterator itr_tc = _tweet_list.find(*itr_tmp);
					if (itr_tc != _tweet_list.end()) {
						tc_list.insert(tc_list.end(), itr_tc->second.begin(), itr_tc->second.end());
					}
				}
		}
		
		sort(tc_list.begin(), tc_list.end(), cmp);
		
		for (int i=0; i<tc_list.size() && i < 10; ++i) {
			output.push_back(tc_list[i].tweetId);
		}

		return output;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
		++_timestamp;
		
		if (followerId == followeeId)
			return ;
		
		unordered_map<int, unordered_set<int>>::iterator itr = _follow_list.find(followerId);
		
		if (itr == _follow_list.end()) {
			unordered_set<int> fled;
			fled.insert(followeeId);
			
			_follow_list[followerId] = fled;
		}
		else {
			itr->second.insert(followeeId);
		}
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
		++_timestamp;
		
		if (followerId == followeeId)
			return ;
		
		unordered_map<int, unordered_set<int>>::iterator itr = _follow_list.find(followerId);
		
		if (itr == _follow_list.end()) {
			return ;
		}
		else {
			itr->second.erase(followeeId);
		}
    }
};