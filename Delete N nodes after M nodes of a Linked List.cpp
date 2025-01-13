class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        Node* prev=head;
        Node* curr;
        int currM=1;
        int currN=0;
        while(prev!=NULL){
            while(currM!=m){
                prev=prev->next;
                currM++;
                if(prev==NULL){
                    return head;
                }
            }
            currM=1;
            curr=prev->next;
            while(currN!=n){
                if(curr==NULL){
                    prev->next=curr;
                    return head;
                }
                curr=curr->next;
                currN++;
            }
            prev->next=curr;
            prev=curr;
            currN=0;
        }
        return head;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(1)
