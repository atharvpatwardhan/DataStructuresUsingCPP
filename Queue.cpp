#include <iostream>
#include <stdlib.h>

using namespace std;

template <class type>

class Queue{
private:
    int Max, Front, Rear;
    type *List;
public:
    Queue(int queuesize){
        if(queuesize <= 0){
            cout<<"Queue size cannot be -ve. Default size is 10";
            queuesize = 10;
        }
        Max = queuesize;
        Front = -1;
        Rear = -1;
        List = new type[Max];
        for (int i = 0; i<Max; i++){
            List[i] = NULL;
        }
    }

    ~Queue(){
        delete []List;
    }

    bool isEmpty(){
        return (Front == -1 || Front>Rear);
    }
    bool isFull(){
        return (Rear == Max-1);
    }

    void EnQueue(type newitem)  {
        if (isFull()){
            cout<<"Queue Overflow";
        }
        else{
            if (Front == -1){
                Front = 0;
            }
            List[++Rear] = newitem;
        }
    }

    int DeQueue(){
        if(isEmpty()){
            cout<<"Queue Underflow";
        }
        else{
            Front++;
        }
    }

    type getFront(){
        if(isEmpty()){
            cout<<"Queue Underflow";
        }

        else{
            return List[Front];
        }
    }

    void display(){
        cout<<"\nFront : "<<Front;
        cout<<"\nRear : "<<Rear;
        cout<<endl;
        if(!isEmpty()){
            for(int i = Front; i<=Rear;i++){
                cout<<List[i]<<"\t";
            }
        }
    }
};



int main(){
    Queue<int> obj(5);
    int ch,val;

    while(true){
        cout<<"\n\n\t Queue Operations (1.Enqueue 2.Dequeue 3.getFront 4.Exit)";
        cin>>ch;

        switch(ch){
        case 1:
            cout<<"\n\t Enter a value : ";
            cin>>val;
            obj.EnQueue(val);
            break;
        case 2:
            obj.DeQueue();
            break;
        case 3:
            val = obj.getFront();
            if(val!=NULL){
                cout<<val;
            }
            break;
        case 4:
            exit(0);
            break;
        }
        obj.display();
    }
    return 0;
}
