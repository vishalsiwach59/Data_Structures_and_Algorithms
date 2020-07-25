// https://leetcode.com/problems/merge-two-sorted-lists/submissions/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head1=l1,*head2=l2,*ans=NULL,*start;
        if(head1==NULL&&head2==NULL){
            return NULL;
        }
        if(head1!=NULL&&head2==NULL){
            return head1;
        }
        if(head1==NULL&&head2!=NULL){
            return head2;
        }
        if(head1&&head2){
            if(head1->val<=head2->val){
                ans=head1;
                head1=head1->next;
            }
            else{
                ans=head2;
                head2=head2->next;
            }
        }
        start=ans;
        while(head1!=NULL&&head2!=NULL){
            if(head1->val<=head2->val){
                start->next=head1;
                head1=head1->next;
                start=start->next;
            }
            else{
                start->next=head2;
                head2=head2->next;
                start=start->next;
            }
        }
        if(head1==NULL&&head2!=NULL){
            start->next=head2;
            return ans;
        }
        if(head2==NULL&&head1!=NULL){
            start->next=head1;
            return ans;
        }
        start->next=NULL;
        return ans;
    }
};
