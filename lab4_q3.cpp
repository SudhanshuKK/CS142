//stack from queue
//including libraries
#include <iostream>
#include "queue.cpp"
using namespace std;

//class  
class stack{
	public:
	int top;
	queue q1;
	//constructer
	stack(){
		top=q1.end;
	}
	//push fn
	void push(int value){
		q1.enqueue(value);
	}
	//pop fn
	void pop(){
		q1.end=q1.end-1;
	}
	//to print size
	void size(){
		q1.size();
	}
	//check is empty or not
	bool isempty(){
		q1.isempty();
	}
		//to display
	void display(){
		q1.display();
	}
	//to show top element
	void topelement(){
		q1.topelement();
	}

};

//driver fn
int main(){
	stack s1;
	s1.push(45);
	s1.push(78);
	s1.push(16);
	s1.push(89);
	s1.topelement();
	s1.size();
	s1.display();
	s1.pop();
	s1.display();
	//return statement
	return 0;
}
