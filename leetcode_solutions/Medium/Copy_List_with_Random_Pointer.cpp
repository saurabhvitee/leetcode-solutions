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
    // If node is not present create new node with findNode->val and insert in
    // Map

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

    void printClonedLinkedList(Node* head) {
        while (head != nullptr) {
            cout << "Data: " << head->val;
            if (head->random != nullptr) {
                cout << ", Random: " << head->random->val;
            } else {
                cout << ", Random: nullptr";
            }
            cout << endl;
            // Move to the next node
            head = head->next;
        }
    }

    Node* copyRandomList(Node* head) {

        if (head == nullptr)
            return head;

        //     Version = 1 - HashMap and Space complexity O(N)

        //     Node* temp = head;
        //     Node* newNode = new Node(temp->val);

        //     visited[temp] = newNode;

        //     while (temp) {
        //         newNode->random = getClonedNode(temp->random);
        //         newNode->next = getClonedNode(temp->next);

        //         temp = temp->next;
        //         newNode = newNode->next;
        //     }

        //     return visited[head];

        // Version 2 - Inplace with O(1) space complexity

        // Insert copies in between of Nodes
        Node* temp = head;
        while (temp) {
            Node* newNode = new Node(temp->val);
            Node* next = temp->next;
            temp->next = newNode;
            newNode->next = next;

            temp = temp->next->next;
        }

        // Insert random pointers for newly created copies
        temp = head;
        while(temp){
            if(temp->random){
                temp->next->random = temp->random->next;
            }
            else{
                temp->next->random = nullptr;
            }

            temp = temp->next->next;
        }

        // Now last step is to separate these two LL's 
        temp = head;
        // Create a dummy node
        Node* dummyNode = new Node(-1);   
        // Initialize a result pointer
        Node* res = dummyNode;             

        while(temp != NULL){
            // Creating a new List by
            // pointing to copied nodes
            res->next = temp->next;
            res = res->next;

            // Disconnect and revert back to the
            // initial state of the original linked list
            temp->next = temp->next->next;
            temp = temp->next;
        }
        
        // Return the deep copy of the
        // list starting from the dummy node
        return dummyNode->next;   
    }
};