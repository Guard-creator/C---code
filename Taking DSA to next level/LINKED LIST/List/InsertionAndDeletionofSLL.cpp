#include <iostream>

// we will implement insert and deletion from both head and tails 
// in singly linked list

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class SingleyLinkedList {

    Node* head;
    
    public:

        // at the start where no value insert yet
        // head will be NULL
        SingleyLinkedList() : head(NULL) {};

        void insertAtHead(int val) {
            Node* newNode = new Node(val); // create a new node
            newNode->next = head; // new node will point to it's previous head
            head = newNode; // then make the current node to the new node.
        }

        void insertAtTails(int val) {
            Node* newNode = new Node(val); // create a new node 
            // if there is no head we simply add the new node to the head 
            if(!head) {head = newNode; return;}
            // we store current head into 
            // a different Node then we loop to go the 
            // last element then at the last element 
            // we will point to it new node
            Node* temp = head;
            while(temp->next) temp = temp->next;
            temp->next = newNode;
        }

        void insertAtSpecificPlace(int pos, int val) {
            // create New Node
            Node* newNode = new Node(val);

            // simply insert at head if pos is 1
            if(pos == 1) {
                newNode->next = head;
                head = newNode;
                return;
            }

            // loop through the pos in list 
            // but we will loop just before the pos
            // so if we want to insert at 3 index
            // it will stop at index 2 
            // so we can also point previous node to the 
            // newNode
            Node* temp = head;
            for(int i = 1; temp && i < pos - 1; i++) {
                temp = temp->next;
            }

            // check before if the pos
            // is value is exist or nah
            if(!temp) {
                std::cout << "Postion out of Range!\n";
                delete newNode;
                return;
            }

            // newNode will now Point the current node
            // where it want to insert 
            // then set the previous node pointer to the new Node
            newNode->next = temp->next; // 99 > 3
            temp->next = newNode; // 2 > 99 > 3
        }

        void deleteAtHead() {
            if(!head) return; // return cuz nothing to del
            Node* temp = head; // take the current head
            head = head->next; // then point the head to the next head so we can delete previous head
            delete temp; // then free the memory
            // if we dont store head in different Node for deleting
            // and just point to the next directly 
            // the previous head will wonder like a lost soul in heap 
        }

        void deleteAtTails() {
            if(!head) return; // return cuz nothing to del
            // if there is an single element then we simply 
            // delete the head then set the head to NULL (because there is no tails) 
            if(!head->next) { delete head; head = NULL; return;}
            Node* temp = head;
            // then we will loop
            // We don’t go all the way to the last node.
            // Instead, we stop at the second last node (temp->next->next == NULL means temp->next is the last node).
            // This way, we have access to the last node and can cut its link.
            while(temp->next->next) temp = temp->next;
            delete temp->next; // free memory
            // Update the next pointer of the second last node to NULL, making it the new tail.
            temp->next = NULL; 
        }

        void deleteAtSpecificPlace(int pos) {
            // return if empty
            if(!head) return;

            // simply delete the head if pos is pointing to head
            if(pos == 1) {
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }

            // looping just before the value to delete
            // we also check temp if the value is out of range
            Node* temp = head;
            for(int i = 1; temp && i < pos - 1; i++) {
                temp = temp->next;
            }

            // if that value is empty is or the
            // value which is the actual value to delete is empty 
            // then return
            if(!temp || !temp->next) {
                std::cout << "Postion out of Range.\n";
                return;
            }

            // storing the node to delete later 
            // then pointing that node after the node 
            // to correct the sequence 
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;

        }

        // replace or update the element in list
        void replaceWith(int pos, int val) {

            Node* temp = head;

            // simply update head if pos is 1
            if(pos == 1) {
                temp->data = val;
                return;
            }

            // loop until reaches element
            for(int i = 1; temp && i < pos; i++) {
                temp = temp->next;
            }

            // check if that value is not empty?
            if(!temp) {
                std::cout << "Out of Range!\n";
                return;
            }

            // then simply updated
            temp->data = val;
        }

        // to count list
        // simple no need to add comments here huh?
        int count() {

            int count = 0;
            Node* temp = head;
            while(temp) {
                temp = temp->next;
                count++;
            }

            return count;
        }

        // for display
        void display() {
            Node* temp = head;
            while(temp) {
                std::cout << temp->data << " -> ";
                temp = temp->next;    
            }
            std::cout << "NULL";
        }

}; 

int main() {

    SingleyLinkedList list;

    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtTails(53);
    list.insertAtTails(543);

    std::cout << "Count: " << list.count() << '\n';
    
    std::cout << "After Inserting: ";
    list.display();
    std::cout << '\n';

    list.deleteAtHead();
    list.deleteAtTails();

    list.insertAtSpecificPlace(2, 105);

    list.deleteAtSpecificPlace(2);

    std::cout << "After Deleting: ";
    list.display();   
    std::cout << '\n';
    std::cout << "Count: " << list.count() << '\n';

    list.insertAtHead(453);
    list.insertAtTails(645);

    list.replaceWith(3, 69);

    std::cout << "After Replacing: ";
    list.display();

    return 0;
}