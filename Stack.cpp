#include <iostream>
#include <stdlib.h>

using namespace std;

template <class type>

class Stack{
private:
    int Max,Top;
    type *List;

public:
    Stack(int stacksize){
        if (stacksize <= 0){
            cout<<"Stack size cannot be negative , default size is 10";
            stacksize = 10;
        }

        Max = stacksize;
        Top = -1;
        List = new type[Max];
        for (int i=0;i<Max;i++){
            List[i] = NULL;
        }
    }

    ~Stack(){
        delete []List;
    }

    bool isFull(){
        return Top == Max-1;
    }
    bool isEmpty(){
        return Top == -1;
    }

    void push(type newitem){
        if(isFull()){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            List[++Top] = newitem;
        }
    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            Top--;
        }
    }

    type peek(){
        if(isEmpty()){
            cout<<"Stack Underflow";
            return NULL;
        }
        else{
            return List[Top];
        }
    }

    void display(){
        cout<<"\nTop : "<<Top;
        cout<<"\nStack : ";
        for (int i = 0; i<= Top; i++){
            cout<<List[i]<<"\t";
        }
    }
};



int main(){
    Stack<int> obj(5);
    int ch,val;
    while(true){
        cout<<"\n\n\tStack Operations : (1.Push 2.Pop 3.Peek 4.Exit)";
        cin>>ch;

        switch(ch){
        case 1:
            cout<<"\n\tEnter integer to push : ";
            cin>>val;
            obj.push(val);
            break;
        case 2:
            obj.pop();
            break;
        case 3:
            val = obj.peek();
            if(val!=NULL){
                cout<<val;
            }
            break;
        case 4:
            exit(0);
        }
        obj.display();
    }
    return 0;
}
