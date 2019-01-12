//including libraries
#include <iostream>
//using namespace
using namespace std;

//making the rooms of linked list named "skk"
class skk{
	public:
//declaring components of room
	int a;
//pointer pointing/linking to another room
	skk* ptr;
//default constructer
	skk(){
		a=0; ptr = NULL;
}
//normal constructer
	skk(int p){
		a = p; ptr = NULL;
}
};
//making the linked list
class linkedlist{
	public:
		skk* head = NULL;
//function to insert a room(skk)
	void insert(int data){
//first create skk
	skk* temp = new skk(data);
//if the linked list is empty then we point the head to temp
	if(head == NULL) head = temp;
	else {skk* current=head;
	for(current;current->ptr!=NULL;){
					current = current->ptr;
}
// we insert the newly created linked list "skk"
	current->ptr = temp;
}
}

//function to display the linked list
void Display(){
//go to the head and print the data one by one
	skk* current = head;
	for(current; current!= NULL;){
	cout<<current->a<<"->";
	current=current->ptr;
}
	cout<<"null"<<endl;
}

//function to insert "skk" at a desired position
void Insertat(int data, int pos){
	//create a new "skk" in heap
		skk* temp = new skk(data);
	//create a variable pointer that move along the linked list
		skk* current = head;
	for (int i= 1; i< pos-1; i++){
		if (current -> ptr!= NULL){
	current = current->ptr;}
		else {cout<<"Such question does not exist"<<endl;
	break;}
	}
//temp is connected to next "skk"
	temp ->ptr = current->ptr;
//current points to temp
	current->ptr = temp;}

//function for deleting a "skk"
	void Delete(){
//first go to the second last position 
	if(head == NULL){
		cout<<"The linked list is already empty. Why delete it ?";
	}
		else{skk* current;
			for(current = head;current->ptr->ptr!= NULL;){current = current->ptr;}
				current->ptr = NULL;
	}
}

//function for deleting the linked list at a desired position
	void Deleteat(int pos){
//variable pointer that moves along the linked list
	skk* current = head;
	for (int i= 1; i< pos-1; i++){
		if (current -> ptr!= NULL){
	current = current->ptr;}
	else {cout<<"Linked list is too small"<<endl;
	break;
	}
	current -> ptr = current->ptr->ptr;
}
} 

//function for counting the number of "skk"
	int countit(){
//variable pointer
	skk* current = head;
//i= number of times this loop is executed
	int i = 0;
	for(;current!=NULL;i++){
//this loop runs till where is the last "skk"
	current=current->ptr;
}
	return i;
}
};

//main/driver function
	int main(){
//linked list creating
	linkedlist l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.Display();
	l1.Insertat(202000, 2);
	l1.Display();
	l1.Delete();
	l1.Display();
	l1.insert(34);
	l1.insert(13);
	l1.insert(162);
	l1.Display();
	cout<<"No of elements: "<<l1.countit()<<endl;
	//return statementts: 	
	return 0;
}
