/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> res;
        ListNode *curr = head;
        while(curr!=NULL) {
            res.push_back(curr->val);
            curr=curr->next;
        }
        int n=res.size();
        int low=0,high=n-1,max_sum=0;
        while(low < high){
            max_sum = max(res[low]+res[high], max_sum);
            low++;
            high--;
        }
        return max_sum;
    }
};