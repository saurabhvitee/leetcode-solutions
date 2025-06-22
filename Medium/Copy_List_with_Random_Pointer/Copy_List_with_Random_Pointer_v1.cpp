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
    unordered_map<Node*, Node*> visited;
    
    // If node is present return that from Map 
    // If node is not present create new node with findNode->val and insert in Map

    Node* getClonedNode(Node* findNode) {

        if (visited.find(findNode) != visited.end()) {
            return visited[findNode];
        }

        if (findNode) {
            Node* newNode = new Node(findNode->val);
            visited[findNode] = newNode;
            return visited[findNode];
        }
        return nullptr;
    }

    Node* copyRandomList(Node* head) {
        
        if(head == nullptr) return head;

        Node* temp = head;
        Node* newNode = new Node(temp->val);

        visited[temp] = newNode;

        while (temp) {
            newNode->random = getClonedNode(temp->random);
            newNode->next = getClonedNode(temp->next);

            temp = temp->next;
            newNode = newNode->next;
        }

        return visited[head];
    }
};