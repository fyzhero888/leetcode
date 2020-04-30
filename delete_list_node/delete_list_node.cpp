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
		ListNode* remove_item(ListNode* item, int& total, int n) {

			int count = total;

			// last one
			if (!item) {
				return NULL;
			}
			else {
				++total;
				ListNode* del_item = remove_item(item->next, total, n);
				if (del_item) {
					item->next = del_item->next;
					return NULL;
				}

				if (count == (total - n)) {
					return item;
				}
			}

			return NULL;
		}

		ListNode* removeNthFromEnd(ListNode* head, int n) {

			int total = 0;

			ListNode* first = remove_item(head, total, n);
			if (first) {
				return first->next;
			}

			return head;
		}

};
