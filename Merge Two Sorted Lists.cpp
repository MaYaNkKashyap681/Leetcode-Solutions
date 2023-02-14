class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *nextnode = NULL;
        
        while(list1 and list2) {
            if(list1 <= list2) {
               nextnode = list1->next;
               list1->next = list2;
               list1 = nextnode;
            }
            else{
                nextnode = list2->next;
                list2->next = list2;
                list2 = nextnode;
            }
        }
        
        return list1;
    }
};
