#include<iostream>
#include<exception>
using namespace std;

class QueueOverflowException : public exception{};
class QueueUnderflowException : public exception{};

template <typename T>
class Queue{
private:
    T* data;
    int capacity;
    int front;
    int rear;
    int size;

public:
    Queue(int cap) : capacity(cap),front(0),rear(0),size(0){
        data=new T[capacity];
    }

    ~Queue(){
        delete[] data;
    }

    void enqueue(T value){
        if(size==capacity)
            throw QueueOverflowException();

        data[rear]=value;
        rear=(rear+1)%capacity;
        size++;
    }

    T dequeue(){
        if(size==0)
            throw QueueUnderflowException();

        T value=data[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    bool isEmpty() const{
        return size==0;
    }

    bool isFull() const{
        return size==capacity;
    }
};

int main(){
    Queue<int> q(3);

    try{
        cout<<"Attempting to enqueue to a full queue ..."<<endl;
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
    }
    catch(const QueueOverflowException& e){
        cerr<<"Caught QueueOverflowException - what(): "<<e.what()<<endl;
    }

    try{
        Queue<int> q2(2);
        cout<<"\nAttempting to dequeue from an empty queue ..."<<endl;
        q2.dequeue();
    }
    catch(const QueueUnderflowException& e){
        cerr<<"Caught QueueUnderflowException - what(): "<<e.what()<<endl;
    }

    return 0;
}
