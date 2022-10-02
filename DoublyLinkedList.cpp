#include <iostream>

using namespace std;

template <typename type>

class DLinkedList{
    struct Node{
        type data;
        Node *next;
        Node *prev;
    };
    Node *begin = NULL,*end = NULL;
public:
    void forward_traverse(){
        if(begin == NULL){
            cout<<"List is Empty";
        }
        else{
            Node *ptr = begin;
            cout<<"\nForward List : ";
            while(ptr != NULL){
                cout<<"\t"<<ptr->data;
                ptr = ptr->next;
            }
        }
    }

    void backward_traverse(){
        if(end == NULL){
            cout<<"List is Empty";
        }
        else{
            Node *ptr = end;
            cout<<"\nBackward List : ";
            while(ptr != NULL){
                cout<<"\t"<<ptr->data;
                ptr = ptr->prev;
            }
        }
    }


    void InsertBeg(type val){
        Node *tmp = new Node;
        tmp->prev = NULL;
        tmp->data = val;
        if(begin == NULL){
            tmp->next = NULL;
            end = tmp;
        }
        else{
            tmp->next = begin;
            begin->prev = tmp;
        }
        begin = tmp;
    }

    void InsertEnd(type val){
        Node *tmp = new Node;
        tmp->data = val;
        tmp->next = NULL;
        if(end == NULL){
            tmp->prev = NULL;
            begin = end = tmp;
        }
        else{
            tmp->prev = end;
            end->next = tmp;
        }
        end = tmp;
    }

    void SortList(){
        Node *i = begin,*j = NULL;
        type tmp;
        while(i != NULL){
            j = i->next;
            while(j!=NULL){
                if(i->data > j->data){
                    tmp = i->data;
                    i->data = j->data;
                    j->data = tmp;
                }
                j = j->next;
            }
            i = i->next;
        }
    }
};


int main(){
    DLinkedList<int> obj;
    int ch,val;

    while(true){
        cout<<"\nDoubly Linked List (1.InsertBeg 2.InsertEnd 3.Sort 4.End)";
        cin>>ch;

        switch(ch){
        case 1:
            cout<<"\n\tEnter a value : ";
            cin>>val;
            obj.InsertBeg(val);
            break;
        case 2:
            cout<<"\n\tEnter a value : ";
            cin>>val;
            obj.InsertEnd(val);
            break;
        case 3:
            obj.SortList();
            break;
        case 4:
            exit(0);
            break;
        }
        obj.forward_traverse();
        obj.backward_traverse();
    }
    return 0;
}
