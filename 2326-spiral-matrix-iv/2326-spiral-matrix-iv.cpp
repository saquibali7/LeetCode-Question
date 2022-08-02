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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int> (n,-2));
        int x=0,y=0,p=0;
        while(x<m && y<n){
            for(p=y;p<n;p++){
                if(head!=NULL){
                    res[x][p]=head->val;
                    head=head->next;
                } else {
                    res[x][p]=-1;
                }
            }
            x++;
            for(p=x;p<m;p++){
                if(head!=NULL){
                    res[p][n-1]=head->val;
                    head=head->next;
                } else {
                    res[p][n-1]=-1;
                }
            }
            n--;
            if(x < m){
              for(p=n-1;p>=y;p--){
                if(head!=NULL){
                    res[m-1][p]=head->val;
                    head=head->next;
                } else {
                    res[m-1][p]=-1;
                }
                }
              m--;
            }
            if(y < n){
                for(p=m-1;p>=x;p--){
                    if(head!=NULL){
                        res[p][y]=head->val;
                        head=head->next;
                    } else {
                        res[p][y]=-1;
                    }
                }
                y++;
            }
        }
        return res;
        
    }
};