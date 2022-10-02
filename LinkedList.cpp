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
                pos++;
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

    type findMax(){
        Node *ptr = begin;
        int maxval = ptr->data;
        Node *tmp = begin;
        while(tmp!=NULL){
            if(tmp->data > maxval){
                maxval = tmp->data;
            }
            tmp = tmp->next;
        }
        cout<<"\n\n"<<maxval;

    }
};


int main(){
    LinkedList<int> obj;
    int ch,val;
    while(true){
        cout<<"\n\n\tStack Operations : (1.InsertBeg 2.InsertEnd 3.Traverse 4.Search Max value 5.Exit)";
        cin>>ch;

        switch(ch){
        case 1:
            cout<<"\n\tEnter value to add : ";
            cin>>val;
            obj.insertBeg(val);
            break;
        case 2:
            cout<<"\n\tEnter value to add : ";
            cin>>val;
            obj.insertEnd(val);
            break;
        case 3:
            obj.traverse();
            break;
        case 4:
            obj.findMax();
            break;
        case 5:
            exit(0);
        }
    }

    return 0;

}


