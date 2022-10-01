#include <iostream>

using namespace std;

template <typename type>

class LinkedList{
    struct Node{
        type data;
        Node* next;
    };

    Node* begin = NULL;
public:

    void insertBeg(type val){
        Node *tmp = new Node;
        tmp->data = val;
        tmp->next = begin;
        begin = tmp;
    }

    void insertEnd(type val){
        Node *tmp = new Node;
        tmp->data = val;
        tmp->next = NULL;
        if (begin == NULL){
            begin = tmp;
        }
        else{
            Node *ptr = begin;
            while(ptr->next!=NULL){
                ptr = ptr->next;
            }
            ptr->next = tmp;
        }
    }


    void traverse(){
        if(begin == NULL){
            cout<<"Empty.."<<endl;
        }
        else{
            Node *ptr = begin;
            cout<<"\nLinked List : \n";
            while(ptr!=NULL){
                cout<<"\t"<<ptr->data;
                ptr = ptr->next;
            }

        }
    }

    void search(type val){
        if(begin == NULL){
            cout<<"List is empty "<<endl;
        }

        else{
            int flag=0,pos=0;
            Node *ptr = begin;

            while(ptr!=NULL){
                ptr++;
                if (ptr->data==val){
                    cout<<val<<" is present at "<<pos<<endl;
                    flag = 1;
                }
                ptr=ptr->next;
            }

            if(flag==0){
                cout<<"Element is not present in the list";
            }
        }
    }
};


int main(){
    LinkedList<int> obj;
    obj.insertBeg(10);
    obj.insertBeg(20);
    obj.insertBeg(30);
    obj.insertEnd(40);
    obj.search(30);
    obj.traverse();
    return 0;

}
