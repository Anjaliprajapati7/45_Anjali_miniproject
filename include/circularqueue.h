#pragma once
#include <iostream>
#include<ostream>
#define MAX 20
using namespace std;


class BankingQueue
{
private:
    int front=-1, rear=-1;

public:
    int token = 0, Queue[MAX]; 
    string name[MAX];
    void enqueue(int token)
    {
        if (rear == -1) //for enqueuing first element
        {
            front = rear = 0;
            Queue[rear] = token;

        }
        else if (rear == MAX - 1) //if queue is full
        {
            cout<<"\nWaiting Line is full.\n"<<endl;
            return;
        }
        else //adding an element to a queue that already contains an element
        {
            rear++;
            Queue[rear] = token;

        }
        cout<<"Please wait until your token number is called. Thank you."<<endl;

    }

    void tokennumber(string customer_name) //generate a number and add to queue
    {
        name[token]=customer_name;
        cout<<name[token];
        token = token + 1;
        cout<<",your customer number is "<< token<<endl;
        enqueue(token);
    }

    void traverse(string customer_name) //to traverse the queue
    {
        if (rear == -1) //the queue is empty
        {
            cout<<"\nWaiting Line is Empty."<<endl;
            return;
        }

        //if the queue contains an element
        cout<<"\nWaiting Line:\n"<<endl;
        for (int i = front; i <= rear; i++)
        {
            cout<< "Token:"<<Queue[i]<<" name:"<<name[i]<<endl;
        }
        cout<<endl;

    }

    void dequeue() //to remove top element
    {
        
        if (front == -1)//if the queue is empty
        {
            cout<<"\nWaiting Line is Empty."<<endl;
            return;
        }
        else if (front == rear) //if removing the topmost element before the queue gets empty
        {
            token = Queue[front];

            front = rear = -1;
        }
        else //to remove the topmost element and adjust the queue
        {
            token = Queue[front];
            front++;
        }
        cout<<"\nNow Serving Customer Number: "<<token<<endl;
    }
};