#include <iostream>
#include <vector>

using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int data){
            this->data = data;
            next = NULL;
        }
};

void display(Node *p){
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    
    cout << endl;
}

Node *selection_sort(Node *head){
    Node *i = head;

    while(i->next){
        Node *j = i->next;
        Node *k = i;
        int x = 1;

        while(j){
            if(j->data < k->data)
                k = j;

            j = j->next;
        }

        int temp = k->data;
        k->data = i->data;
        i->data = temp;

        i = i->next;
    }

    return head;
}

int main(){
    vector<int> numbers = { 8, 6, 3, 2, 7, 1, 5, 4 };

    Node *head = new Node(numbers[0]);
    Node *t = head;

    for(int i = 1; i < numbers.size(); i++){
        Node *p = new Node(numbers[i]);
        t->next = p;
        t = p;
    }

    cout << "Beofre selection sort: ";
    display(head);
    cout << endl;
    
    head = selection_sort(head);

    cout << "After selection sort: ";
    display(head);
    cout << endl;

    return 0;
}