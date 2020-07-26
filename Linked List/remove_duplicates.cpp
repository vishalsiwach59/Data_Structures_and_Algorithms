// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/submissions/
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode *ans=NULL,*start=NULL,*x=head;
        while(head){
            if(ans==NULL){
                int x=head->val;
                int y=0;
                ListNode *z=head;
                while(z&&z->val==x){
                    y++;
                    z=z->next;
                }
                if(y<2){
                    ans=head;
                    start=ans;
                }
                head=z;
            }
            else{
                int x=head->val;
                int y=0;
                ListNode *z=head;
                while(z&&z->val==x){
                    y++;
                    z=z->next;
                }
                if(y<2){
                    ans->next=head;
                    ans=ans->next;
                }
                head=z;
            }
        }
        if(start==NULL){
            return NULL;
        }
        ans->next=NULL;
        return start;

    }
};
