//copy this function in leetcode problem 83 to see the results 




    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp =head;
        while(temp->next!=NULL)
        {
            if(temp->val==temp->next->val)
                temp->next=temp->next->next;
            else
            temp=temp->next;
        }
        
        return head;
        
    }
