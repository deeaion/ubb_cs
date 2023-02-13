/**
 * Definition for singly-linked list.
 *struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    int a[5001],i=0;
    struct ListNode *p;
    p=head;
    while(p!=NULL)
    {i++;//avem deja un element
        a[i]=p->val;//retinem valoriile intr-un vector.
        //i reprezinta atat un indice cat si numarul de elemente
        p=p->next;//parcurgem toata lista

    }
    p=head;//ne mutam din nou la inceput de lista
    while(i)
    {
        p->val=a[i];
        i--;
        p=p->next;
    }
    return head;


}