/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(!head){
            return nullptr;
        }
        Node* result = new Node(head->val);
        Node* reshead = result;
        Node* cur = head->next;
        unordered_map<Node*,Node*> map;
        map[head] = reshead;
        while(cur){
            Node *temp = new Node(cur->val);
            reshead -> next = temp;
            map[cur] = temp;
            reshead = reshead -> next;
            cur = cur -> next;
        }
        
        reshead = result; cur = head;
        while(cur){
            auto it = map.find(cur->random);
            if( it == map.end()){
                reshead -> random = NULL;
            }else{
                reshead -> random = it->second;    
            }
            cur = cur -> next;
            reshead = reshead -> next;
        }
        return result;
        
        /*
        if (!head) return nullptr;
        Node *res = new Node(head->val);
        Node *node = res, *cur = head->next;
        unordered_map<Node*, Node*> m;
        m[head] = res;
        while (cur) {
            Node *t = new Node(cur->val);
            node->next = t;
            m[cur] = t;
            node = node->next;
            cur = cur->next;
        }
        node = res; cur = head;
        while (cur) {
            node->random = m[cur->random];
            node = node->next;
            cur = cur->next;
        }
        return res;
        */
    }
};
