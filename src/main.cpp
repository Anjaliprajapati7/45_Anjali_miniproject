#include "circularqueue.h"
#include <iostream>
#include<istream>
#include<ostream>

using namespace std;

int main()
{	
	int Queue[MAX];
	string name;
    BankingQueue Q1;

	start_app:
	int c_manager, c_customer, start;
	cout<<"**********Bank Queue Management System**********\n\n"<<endl;
	cout<<"Are you a Customer (1) or a Manager (2)? : "<<endl;
	cin>>start;
 	
	 //customer
	if (start==1)
 	{
		cout<<"Enter your name:"<<endl;
		cin>>name;
		cout<<endl;
		
		//generate a token number
		Q1.tokennumber(name);
		cout<<"\n\t******Have a Good day," <<name<<"******"<<endl;
		cout<<endl;
	
		
		goto start_app;	
	}
	
	//manager
	else if (start==2)	
	{	bool isComplete=false;

		while(!isComplete)
		{
			cout<<"1.View Waiting Line\n2.View 'Now Serving' customer and waiting line \n3.Quit\n\n"<<endl;
			cout<<"what would you like to do? : "<<endl;
			cin>>c_manager;
		
			switch(c_manager)
			{
				case 1:
				{
					//view the elements on the queue
					Q1.traverse(name);
					break;
				}
				case 2:
				{
					//remove the topmost element on the queue
					Q1.dequeue();
					Q1.traverse(name);
					break;
				}
				case 3:
				{
					//to exit the 'manager' account
					cout<<"\n"<<endl;
					isComplete=true;
					goto start_app;
				}
				default:
				{
					cout<<"Invalid input."<<endl;
				}
			}
		}
	}
	else
	{
		cout<<"Invalid input. Plese Try again."<<endl;

		goto start_app;
	}
}
