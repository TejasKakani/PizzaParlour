#define MAX 10
#include <iostream>
#include <string>
using namespace std;

class Orders{

    private:
    int order_id;
    string order_name; 

    Orders(){
        order_id = 0;
        order_name = "";
    }
    public:
    Orders(int order_id, string order_name){
        this->order_id = order_id;
        this->order_name = order_name;
    }

    void display(){
        if(this->order_id == 0 && this->order_name == ""){
            cout<<"No order"<<endl;
        }
        else{
            cout<<this->order_id<<" "<<this->order_name<<endl;
        }
    }

friend class Queue;
};

class Queue{

    int front, rear, it;
    Orders order[MAX];

    public:
    Queue(){
        front = rear = -1;
    }

    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true;
        }
        return false;
    }

    bool isFull(){
        if((rear+1)%MAX == front){
            return true;
        }
        return false;
    }

    void enqueue(int order_id, string order_name){
        Orders o(order_id, order_name);
        if(isFull()){
            cout<<"Queue is full"<<endl;
            return;
        }
        else if(isEmpty()){
            front = rear = 0;
        }
        else{
            rear = (rear+1)%MAX;
        }
        order[rear] = o;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        else if(front == rear){
            front = rear = -1;
        }
        else{
            front = (front+1)%MAX;
        }
    }

    Orders getFront(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
        }
        return order[front];
    }

    Orders getRear(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
        }
        return order[rear];
    }

    void displayAll(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        int i = front;
        while(i != rear){
            cout<<order[i].order_id<<" "<<order[i].order_name<<endl;
            i = (i+1)%MAX;
        }
        cout<<order[i].order_id<<" "<<order[i].order_name<<endl;
    }

};

int main(){

    Queue* q = new Queue();      //creating object
    q->enqueue(1,"Pizza");       //listing 1st order
    q->enqueue(2,"Burger");      //listing 2nd order
    q->enqueue(3,"Sandwich");    //listing 3rd order
    q->enqueue(4,"Kachori");     //listing 4th order
    q->dequeue();                //completing priority order
    q->dequeue();                //completing priority order
    Orders ord = q->getFront();  //getting priority order
    ord.display();               
    Orders ord1 = q->getRear();  //getting last order
    ord1.display();            
    q->displayAll();             //displaying all orders

    return 0;
}