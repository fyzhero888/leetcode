/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
	ListNode* odd_head = NULL, *odd_tmp = NULL, *even_tmp = NULL, *even_head = NULL;
	int idx = 1;
	
	if (!head) 
		return head;
	
	for (ListNode* cur = head; cur != NULL; cur = cur->next, ++idx) {
		
		if (idx % 2 == 1) {
			if (odd_head) {
				odd_tmp->next = cur;
			}else {
				odd_head = cur;
			}
			odd_tmp = cur;
		}
		else {
			if (even_head) {
				even_tmp->next = cur;
			}else {
				even_head = cur;
			}
			even_tmp = cur;
		}
	}
	if (even_tmp)
	    even_tmp->next = NULL;
	odd_tmp->next = even_head;
	
	return odd_head;
    }
};
