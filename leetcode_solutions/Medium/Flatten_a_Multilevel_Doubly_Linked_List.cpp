/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
    
        Node* temp = head;

        while(temp != nullptr){
            // Check if there are any child nodes for this current nodes
            // If yes then we have to add them after current and before current->next
            // Node for a child pointer
            
            if(temp->child){
                Node* nextNode = temp->next; // store the next element
                temp->next = temp->child;
                temp->next->prev = temp;
                temp->child = nullptr;

                Node* findLastNodeForChild = temp->next; // This is temp's children
                // which has become next now just few moments ago

                // Traverse until you find end of this node-next
                // Make sure we are checking while(node->next) in loop
                // Otherwise we will cross and we will be standing at nullptr
                while(findLastNodeForChild->next) 
                findLastNodeForChild = findLastNodeForChild->next;

                findLastNodeForChild->next = nextNode; // Connect this to next node
                // Which we have saved at our first step

                if(nextNode) nextNode->prev = findLastNodeForChild; 
                // Since this is a doubly linked list we need to take care of prev Node

            }

            temp = temp->next;
        }
        return head;
    }
};