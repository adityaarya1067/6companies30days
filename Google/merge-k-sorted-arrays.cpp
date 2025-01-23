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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int,int> mpp;
        ListNode* head = new ListNode();
        ListNode* temp = head;
        for(ListNode* node:lists){
          while(node!=NULL){  mpp[node->val]++;
           node= node->next;
          }
        }
        vector<pair<int,int>> v(mpp.begin(),mpp.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq(v.begin(),v.end());
        
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            int a = p.first;
            int b = p.second;
            while(b>0){
                ListNode* newNode = new ListNode(a);
                temp->next = newNode;
                temp=temp->next;
                b--;
            }

        }
        return head->next;
    }
};