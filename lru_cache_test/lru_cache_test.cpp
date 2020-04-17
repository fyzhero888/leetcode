class LRUCache {
	
private:
	list<pair<int,int>> _list_kv;
	int cap;
	unordered_map<int, list<pair<int,int>>::iterator> _map_kv;
	
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
		if (_map_kv.find(key) == _map_kv.end()) {
			return -1;
		}else {
			list<pair<int,int>>::iterator itr = _map_kv[key];
			int value = (*itr).second;
			
            _list_kv.erase(itr);
			_list_kv.push_front(pair<int,int>(key, value));
			
			
			_map_kv[key] = _list_kv.begin();
			
			return value;
		}
    }
    
    void put(int key, int value) {
		
		// find key
		if (_map_kv.find(key) != _map_kv.end()) {
			list<pair<int,int>>::iterator itr = _map_kv[key];
			
			_list_kv.push_front(pair<int,int>(key, value));
			_list_kv.erase(itr);
			
			_map_kv[key] = _list_kv.begin();
		}
		// not find
		else {
			if (_list_kv.size() >= cap) {
				
				_map_kv.erase(_list_kv.back().first);
				
				_list_kv.pop_back();
				_list_kv.push_front(pair<int,int>(key, value));
				_map_kv[key] = _list_kv.begin();
                
				
			}else {
				_list_kv.push_front(pair<int,int>(key, value));
				_map_kv[key] = _list_kv.begin();
			}
		}

    }
};