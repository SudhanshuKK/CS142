#include<iostream>
//using namespace
using namespace std;

//constructing node
class Node{
	public:
		//store data
		int data;
		//children
		Node *parent;
		Node *left;
		Node *right;
		Node(int value){
			data = value;
			parent = NULL;
			left = NULL;
			right = NULL;	
	}
};

class BiST{
	public:
	        Node *root;
		BiST(){
			root = NULL;
		        }
		void insert(int value){
			insertHelper(root,value);
		                        }
		void insertHelper(Node * current, int value){
			//Base case if current is NULL, insert there.
			if(current == NULL){
				        current = new Node(value); 
				        if (root == NULL) root = current;	
				        return;
			                }
			//Else compare the current data with value
			else if(value <  current->data){
				//If value <current data  ->move left and call insert
				//if left is NULL,insert it.
				if(current->left == NULL){
					current->left = new Node(value);
					current->left->parent = current;
				                           }
				//else move left and call insert
				else insertHelper(current->left , value);
			                                }
			else{
				//else move right and call insert
				if (current->right == NULL) {
					current->right = new Node(value);
					current->right->parent = current;
				}
				else insertHelper(current->right,value);
			     }			
}
 //display function			
	void display(){
			display2(root);
			cout<<endl;
		        }
		
	void display2(Node *current){
			//Base condition
			if (current == NULL) return;
			//Display left
			display2(current->left);
			//display current
			cout<<current->data<<" , ";
			//display right
			display2(current->right);
		}
		//searching the node with the given value
		Node * search1(Node * current,int value){
			//if not present or present return current
			if (current == NULL || current->data == value) return current;
			//searching left and right node
			else if(value<current->data){
				return search1(current->left,value);
			}
			else return search1(current->right,value);
		}
		//not found or found
		bool search(int value){
			//if found the node with the given value
			if(search1(root,value)!=NULL) {
				cout<<"found"<<endl;
				return 1;
			}
			//if not
			else {
				cout<<"Not found"<<endl;return 0;	
			}
		}
	//find min
	int find_min(int value){
		//search for a branch
			Node *current = search1(root,value);
		//take the min of that branch
		    Node *min = find_min1(current);
		    cout<<endl;
		    return min->data;
		}
		Node *find_min1(Node *current){
		//find min the recursion
		if(current->left == NULL ){
		return current;	
		}
		else if(current == NULL){
        	    return NULL;
			}
		//recursion carried to left
		else return find_min1(current->left);
		}		
	//delete function	
	void deleteNode(int value){
		//search deleting nodee
		Node *current = search1(root,value);
		//element to be deleted is null
		if(current == NULL){
			return;
		}
		else{
		//replacing the values
			if(current->left == NULL){ 
				replace_at_parent1(current->right,current);
			                        }
			else if(current->right == NULL){ 
				replace_at_parent1(current->left,current);
				}
			else{ 
				Node *temp = find_min1(current->right);
				//if to be deleted is root
				if(current == root){
					current->data = temp->data;
					replace_at_parent1(NULL,temp);
					delete temp;
				}
				else{	//if delete element is not root
					//replace min and current
					replace_at_parent1(temp,current);
					//temp parent is current parent
					temp->parent = current->parent;
					//temp left is current left
					temp->left = current->left;
					delete temp;
					}
			}
			}
			
		}
	//replace at parent function	
		void replace_at_parent(int value1,int value2){
			Node *rep = search1(root,value2);
			Node *current = search1(root,value1);
			replace_at_parent1(current,rep);
		}
		void replace_at_parent1(Node *current,Node *rep){
			//the replacing nodeis root
			if(rep == root){
				root = current;	
			}
			//the one to be replaced is root
			else if(current == root){
				return;
			}
			else{	//finding position of node that current will replace
				if(rep->data > rep->parent->data){
					if(current == NULL){
						rep->parent->right = NULL;
					}
			        	else{	//the step of replacing
						//rep parent right will be current
			            		rep->parent->right = current;
    						if(current->data > current->parent->data){
    							current->parent->right = NULL;
    						}
						//current parent child will be null
    						else current->parent->left = NULL;
						//current parent will be reps parent
    						current->parent = rep->parent;
			        	}
					
				}
				else{
					if(current == NULL){
						rep->parent->left = NULL;
					}
					else{	//the step of replacing
						//rep parent right will be current
						rep->parent->left = current;
						if(current->data>current->parent->data){
							current->parent->right = NULL;
						}
						//current parent child will be null
						else current->parent->left = NULL;
						//current parent will be reps parent
						current->parent = rep->parent;       
					}
				
				}
			}
			print_to_do_till(root,0);
		}     
		void print_to_do_till(Node *root, int space){
			// Base case  
			if (root == NULL)  
			    return;  
			// Increase distance between levels  
			space += 5;  
			// Process right child first  
			print_to_do_till(root->right, space);  

			// Print current node after space  
			// count  
			cout<<endl;  
			for (int i = 5; i < space; i++)  
			    	cout<<" ";  
				cout<<root->data<<"\n";  

			// Process left child  
			print_to_do_till(root->left, space);  
			}  

			// Wrapper over print_to_do_till()  
			void print2D(){  
                cout << "******************************" << endl;
                // Pass initial space count as 0  
                print_to_do_till(root, 0);  
                cout << "******************************" << endl;
             }
             //count function
		int count(){
			return count2(root);			
		}
		int count2(Node *current){
			//current is null it has to return 0
			if(current == NULL){
				return 0;
			}
			else{	//adding the elements the function reached
				return count2(current->left) + 1 + count2(current->right);
			}
		}
		//rangesearch
		int rangeSearch(int k1,int k2){
			return rangeSearch1(root,k1,k2);
		}
		int rangeSearch1(Node*current,int k1,int k2){
			//if current is NULL
			if (current==NULL) return 0; 
			//current data is the highest value
			if (current->data == k2 && current->data == k1){ 
				cout<<current->data<<","<<endl;
				return 1;
			}
			//current data within the range
			if (current->data <= k2 && current->data >= k1){ 
				//print the data
				cout<<current->data<<",";
				//count the nodes
				return 1 + rangeSearch1(current->left, k1, k2) + rangeSearch1(current->right, k1, k2); 
			} 
			//is current data is less than k2 and k1
			else if (current->data < k2){ 
				return rangeSearch1(current->right, k1, k2); 
			} 
			//if current data is greater than k2
			else {
				cout<<"\n"<<"The range of the given interval is ";
				return rangeSearch1(current->left, k1, k2); 
			}
			
		}
		//heright function for hieght of the tree
		int height(){
		    return height1(root);
		}
		int height1(Node* current){  
            if (current == NULL)  
                return 0;  
            else
            {  
                /* compute the depth of each subtree */
                int leftheight = height1(current->left);  
                int rightheight = height1(current->right);  
              
                /* use the larger one */
                if (leftheight > rightheight)  
                    return(leftheight + 1);  
                else return(rightheight + 1);  
            } 
        }  
};
//main function
int main(){
	BiST t1;
	t1.insert(3);
	t1.insert(5);
	t1.insert(4);
	t1.insert(7);
	t1.insert(1);
	t1.insert(6);
	t1.insert(8);
	t1.insert(4);
	t1.insert(2);
	t1.insert(0);	
	t1.print2D();
	cout<<"No of nodes in the binary tree are "<<t1.count()<<endl;
	cout<<t1.rangeSearch(2,7)<<endl;
}
