#include <iostream>
using namespace std;

class Node{
        public:
        int data;
        Node* left;
        Node* right;
        
        Node(int val){
             left = NULL;
             right = NULL;
             data = val;
                       }
           };

class BiST{
        public:
           Node* root;
           BiST(){
                root = NULL;
                  }
        void insert(int value){
                insertHelper(root, value);
                                }
        //&root = **curr                        
        void insertHelper(Node* curr, int value){
                          //base case if curr is NULL, insert there.
                          if (curr == NULL){
                                            curr = new Node(value);
                                            if (root == NULL) root = curr;
                                            return;
                                             }
                          //else compare the curr data with value.
                          else if (value < curr->data){
                          //if (curr data < value) ==>
                          //if left is null, insert it.
                          if(curr->left == NULL) curr->left = new Node(value);
                          //else move left and call insertH.
                          else insertHelper(curr->left, value);
                                                        }
                          else{
                          //else move right and call insertH.
                                if (curr->right == NULL) curr->right = new Node(value);
                                else insertHelper(curr->right, value);
                                } 
                                                 }
        void display(){display2(root); cout << endl;}
        
        void display2(Node* curr){
                //base condition
                if (curr == NULL) return;
                //display left.
                display2(curr->left);
                //display current
                cout << curr->data<< ", ";
                //display right
                display2(curr->right);
                                    }
        //2d display of tree 
        Node displayFancy(int spaces){
                //Increase number of spaces
                //display right
                //print required spaces
                //display curr
                //display left
                /*
                sample output
                */
                                        }
        //bool search();
       Node* search(Node* curr, int value){
                     //if value found or reached end of tree
                     if (curr == NULL || curr->data == value) return curr;
                     else if (value < curr->data) search (curr->left, value);
                     else return search (curr->right, value);
                                            }                         
       // height();
       // deleteNode();



           };
           
 int main(){
        BiST b1;
        b1.insert(6);
        b1.insert(4);
        b1.insert(1);
        b1.insert(2);
        b1.insert(3);
        b1.insert(5);
        b1.display();
 
 
 
 }
