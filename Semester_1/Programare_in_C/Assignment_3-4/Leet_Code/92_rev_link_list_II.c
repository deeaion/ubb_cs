/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    int v[501];
    int i=0;
    struct ListNode *p;
    if(left==right)
        return head;
    //retinem toate valoriile
    p=head;
    while(p!=NULL)
    {
        i++;
        v[i]=p->val;
        p=p->next;
    }//1,2,3,4,5
    //   |   |r=3,l=1
   
    //when indexing in C when referencing to a number from a position x we actually index
    //x-1. So when accessing the x position in a vector we actually need to access v[x-1]
    //for example: we need the second element of the array v[]={0,1} we will reference it as v[1]
    //we need to move into the list till we get to  the left position
    int j=0,nr;
     p=head;
    while(j<left-1)
        {
            p=p->next;
            j++;
        }
    //now we need to interchange the values
    left--;//left=1
    nr=right-left;//how many numbers we have to interchange 4-1=3
    while(nr)
    {
        p->val=v[right];
        right--;
        nr--;
        p=p->next;
    }
    return head;
}