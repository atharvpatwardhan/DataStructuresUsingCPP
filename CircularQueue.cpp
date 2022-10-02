#include <iostream>

using namespace std;

template <class type>

class CQueue{
private:
    int Max;
    int Front,Rear;
    type *List;
public:
    CQueue(int queuesize){
        if (queuesize <= 0){
            cout<<"Queue size cannot be -ve. Default size is 10";
            queuesize = 10;
        }
        Max = queuesize;
        Front = -1;
        Rear = -1;
        List = new type[Max];
        for (int i=0;i<Max;i++){
            List[i] = NULL;
        }
    }

    ~CQueue(){
        delete []List;
    }

    bool isEmpty(){
        return (Front == -1 && Rear == -1);
    }

    bool isFull(){
        return ((Rear + 1)%Max == Front);
    }

    void EnQueue(type newitem){
        if(isFull()){
            cout<<"Queue Overflow"<<endl;
        }

        else{
            if(Front == -1){
                Front = 0;
            }
            Rear = (Rear+1)%Max;
            List[Rear] = newitem;
        }
    }

    void DeQueue(){
        if(isEmpty()){
            cout<<"Queue Underflow";
        }
        else{
            List[Front] = NULL;
            if(Front == Rear){
                Front = Rear = -1;
            }
            else{
                Front = (Front+1)%Max;
            }
        }
    }

    type getFront(){
        if(isEmpty()){
            cout<<"Queue Underflow";
            return NULL;
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
            cout<<"Circular Queue : ";
            for(int i=0;i<Max;i++){
                cout<<List[i]<<"\t";
            }
        }
    }

};

int main(){
    CQueue<int> obj(5);
    int ch,val;

    while(true){
        cout<<"Circular Queue Operations (1.EnQueue 2.DeQueue 3.getFront 4.Exit)";
        cin>>ch;

        switch(ch){
        case 1:
            cout<<"\n\tEnter a value : ";
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
