// trie_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

struct trie_node {
    
    string word;
    trie_node* next_node[26]; // 'a' ~ 'z'

public:
    trie_node() {
        
        memset(next_node, 0, sizeof(trie_node*) * 26);
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        _root = new trie_node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {

        trie_node* pcur_node = _root;

        for (size_t i = 0; i < word.length(); ++i) {
            int idx = word[i] - 'a';
            if (pcur_node->next_node[idx] == NULL) {
                pcur_node->next_node[idx] = new trie_node();
                //pcur_node->next_node[idx]->cr = word[i];
            }
            pcur_node = pcur_node->next_node[idx];
        }

        pcur_node->word = word;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {

        trie_node* pcur_node = _root;

        for (size_t i = 0; i < word.length(); ++i) {
            int idx = word[i] - 'a';
            if (pcur_node->next_node[idx] == NULL) { 
                return false;
            }
            else {
                pcur_node = pcur_node->next_node[idx];
            }
        }

        
    
        return (pcur_node->word == word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        trie_node* pcur_node = _root;

        for (size_t i = 0; i < prefix.length(); ++i) {
            int idx = prefix[i] - 'a';
            if (pcur_node->next_node[idx] == NULL) {
                return false;
            }
            else {
                pcur_node = pcur_node->next_node[idx];
            }
        }

        return true;
    }

private:
    trie_node* _root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{

    Trie* obj = new Trie();
    obj->insert("apple");

    bool rs = obj->search("apple");
    rs = obj->startsWith("app");
    obj->insert("app");
    rs = obj->search("app");
    std::cout << "Hello World!\n";
}

