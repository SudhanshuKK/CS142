#include<iostream>
using namespace std;


class gskk{
	public :
	int pspsh;
	//defining two pointers pointing next and previous gskk resp.
	gskk* next;
	gskk* prev;
	//defining constructor of class
	gskk(int a){
	pspsh = a;
	next = prev = NULL;
	}
	//defining a default constructor
	gskk(){
	pspsh = 0;
	next = prev = NULL;
	}
};
//deffining a class for various operations for our gskk
class ee{
        public :
        gskk* ptr = NULL;
       
//function for inserting element(gskk)
void insert(int data){
        if (ptr = NULL){
        //make a new gskk which stores data in pspsh and is pointed by ptr
                gskk*temp=new gskk(data);
                ptr=temp;
                cout<<ptr->pspsh;
                return;
        }
        else{
        //we go to the last place
                gskk* current = ptr; //the variable pointer that moves along ee
                //moving along ee
                while(current -> next != NULL){
                        current = current -> next;
                }
                //inserting a new gskk
                current -> next = new gskk(data);
                //new skk now points back to current
                current -> next -> prev = current;
        }
}

//insertAt function
void insertAt(int pos, int data){
//we are going to that gskk that is before pos
//variable pointer moving along ee
                           gskk* current = ptr;
for(int i=1; i<pos-1; i++){
                        
                           current = current -> next;
                          }
                  // creating new skk to be inserted and storing its address in temp
                  gskk* temp = new gskk(data);
                  temp -> next = current -> next;
                  current -> next -> prev = temp;
                  current -> next = temp;
                  temp -> prev = current;
}

//delete function
void Delete(){
//we will go to the last place
 gskk* current = ptr; //the variable pointer that moves along ee
                //moving along ee
                while(current -> next != NULL){
                        current = current -> next;
                }
                        current = current -> prev; 
                        delete current -> next;
                        current -> next = NULL;
}

//deleteAt function
        void deleteAt(int pos){
                //we are going to that gskk that is before pos 
                //variable pointer moving along ee
                           gskk* current = ptr;
        for(int i=1; i<pos-1; i++){
                       
                           current = current -> next;
                          }
                          // establishing limnk between current and the gskk after pos
                          current -> next = current -> next -> next;
                          //deleting the gskk at pos
                          delete current -> next -> prev;
                          //current's next now points back to current
                          current -> next -> prev = current; 
}

//countItem function
int countItem(){
gskk* current = ptr; //the variable pointer that moves along ee
                //moving along ee
                int i = 1;
                //we are counting the number of gskk in this ee and i keeps the count of it
                while(current != NULL){
                i++;
                        current = current -> next;
                }
                return i;
}
//function for display
void Display(){
         if(ptr!=NULL){gskk* current = ptr; //the variable pointer that moves along ee
                //moving along ee
                while(current != NULL){
                cout<<current -> pspsh<<" -> ";
                        current = current -> next;
                }
                cout<<"NULL"<<endl;
                }
}


};

//main function
int main(){
 ee s1;
 for(int i = 1; i<=15; i++){
 s1.insert(i);}
 s1.insertAt (2, 5000);
 s1.Delete();
 s1.deleteAt(2);
 s1.countItem();
 s1.Display();
 return 0;
 }
