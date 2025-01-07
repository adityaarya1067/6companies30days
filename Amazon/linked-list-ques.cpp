class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) { 
        // code here
      Node* current = head;
      Node* prev = nullptr;
      
      while(current!=nullptr){
          int p = m;
          while(p>0 && current!=nullptr){
              prev =current;
              current=current->next;
              p--;
          }
          int l = n;
          while(l>0 && current!=nullptr){
              Node*temp =current;
              current=current->next;
              l--;
              delete temp;
          }
          if(prev!=nullptr){
              prev->next =current;
          }
      }
      return head;
          }
};