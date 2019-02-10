#include<iostream>
#include "lab2_q1.cpp"

class StackArr{
   public:
	//variable that stores index value of starting element
	int top;
	int arr[30];

	//initialize top as NULL
	StackArr()
	{
		top = NULL;
	}

	//pushes new element into stack
	void push(int value)
	{
		//increment top
		top++;
		//add value to array
		arr[top] = value;
	}

	//pops element from stack
	void pop()
	{
		//decrement top
		top--;
	}

	//returns the size of the stack
	int size()
	{
		if(top == NULL)
			return 0;
		//stores the no. of elements
		int count = 0;
		for(int i=0;arr[i]!=arr[top];i++)
		{
			count++;
		}

		return count;
	}

	//checks if the stack is empty
	bool isEmpty()
	{
		if(top == NULL)
		   return true;

		return false;
	}

	//displays the contents of the stack
	void display()
	{
		for(int i=0;arr[i]!=arr[top];i++)
		{
			cout<<arr[i]<<"->";
		}

		cout<<arr[top]<<endl;
	}

};

class QueueArr
{
   public:
	//variables that store indices for first and last element of the array
	int front,end;
	int arr[30];

	//initialize both front and end as NULL
	QueueArr()
	{
		front = NULL;
		end = NULL;
	}

	//inserts element at the end
	void enqueue(int value)
	{
		//increment end
		end++;
		//insert element
		arr[end] = value;
	}

	//deletes element from the front
	void dequeue()
	{
		if(front == end)
		{
			front = NULL;
			end = NULL;
		}

			//increment front
			front++;

	}

	//returns size of the queue
	int size()
	{
		if(end == NULL)
			return 0;

		int count = 0;                        //stores the number of elements
		for(int i=0;arr[i]!=arr[end];i++)
			count++;

		return count;
	}

	//checks if the queue is empty
	bool isEmpty()
	{
		if(end == NULL)
			return true;

		return false;
	}

	//displays the contents of the queue
	void display()
	{
		//has to display contents between front and end
		int i=front+1;
		while(i>front && i<end)
   		{
			cout<<arr[i]<<"->";
			i++;
		}
		cout<<arr[end]<<endl;
	}
};

//driver function
int main()
{
	//Implementation of stack using linked list
	cout<<"Stack using LL: "<<endl;
	StackLL s1;
	for(int i=1;i<5;i++)
	{
		s1.push(i);
	}
	s1.display();
	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	cout<<endl<<endl;

	//Implementation of queue using linked list
	cout<<"Queue using LL: "<<endl;
	QueueLL q1;
	for(int j=1;j<5;j++)
	{
		q1.enqueue(j);
	}
	q1.display();
	q1.dequeue();
	q1.display();
	q1.dequeue();
	q1.display();
	cout<<endl;

	//Implementation of stack using arrays
	cout<<"Stack using array: "<<endl;
	StackArr s2;
	for(int k=1;k<5;k++)
		s2.push(k);

	s2.display();
	s2.pop();
	s2.display();
	s2.pop();
	s2.display();

	//Implementation of queue using arrays
	cout<<"Queue using array: "<<endl;
	QueueArr q2;
	for(int l=1;l<5;l++)
		q2.enqueue(l);

	q2.display();
	q2.dequeue();
	q2.display();
	q2.dequeue();
	q2.display();

	//return statement
	return 0;
}
