//including libraries
#include<iostream>
using namespace std;

//function to swap the elements
void swap(int *a, int *b){
int t= *a;
*a = *b;
*b = t;
}

//function for partition
        int partition(int arr[],int low , int  high){
//pivot
        int pivot = arr[high];
//indexing the smaller element
        int i = (low-1);
	for(int j=low;j<= high-1;j++){
	        //when the current element is less than or equal to the pivot element using the swap fn
		if(arr[j]<= pivot){
		i++;
		swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return i+1;
}
//quicksort function
void quicksort(int arr[],int low,int high){
	if(low < high){
	int pi = partition(arr,low,high);	
	quicksort(arr,low,pi-1);
	quicksort(arr,pi+1,high);
	}
}
// print array function
void printarray(int arr[],int size){
	int i;
	for(i=0;i< size;i++){
	cout<<"->"<<arr[i];
	}
}
//driver function
int main(){
	int arr[] = {3, 4, 7, 6 , 5 , 1, 2, 8, 10, 9};
	int n = sizeof(arr)/sizeof(arr[0]);  
	quicksort(arr,0,n-1);	
	cout<<"quicksort of sorted array"<<endl;	
	printarray(arr,n);
	cout<<endl;
return 0;
}
