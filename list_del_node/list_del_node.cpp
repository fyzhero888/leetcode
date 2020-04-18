#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
	while(node) {
		if (node->next != NULL) {
			node->val = node->next->val;
			if (node->next->next == NULL) {
				node->next = NULL;	
			}
			node = node->next;
		}
	}
}

int main(int argc, char* argv[]) {
	return 0;
}
