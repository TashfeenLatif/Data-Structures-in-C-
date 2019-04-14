#include<iostream>
using namespace std;

struct node{
	int info;
	node *right,*left;
};

class BST{
	private:
		node *temp,*current,*temp1,*temp3;
	public:
		int number,temp2,l_count,count_leaf,count,h,ph;
		node *root;
		int num;
		BST(){
			temp = root = current = NULL;
			l_count  = count = h = count_leaf = ph = 0;
		}
		void binary(node *temp){
			if(root == NULL){
     			temp = new node;
     			temp->info = number;
    			temp->left = NULL;
     			temp->right = NULL;
     			root = temp;
     			return;
   			}
 			if(temp->info==number){
      			cout<<" Given number is already present in tree."<<endl;
      			return;
    		}
    		if(temp->info > number){
      			if(temp->left!=NULL){
					binary(temp->left);
		 			return;
      			}
      			else{
	 				temp->left=new node;
	 				temp->left->info = number;
	 				temp->left->left=NULL;
	 				temp->left->right=NULL;
	 				return;
       			}
   			}
   			if(temp->info < number){
      			if(temp->right!=NULL){
					binary(temp->right);
		 			return;
       			}
     			else{
	 			temp->right=new node;
	 			temp->right->info = number;
	 			temp->right->left=NULL;
	 			temp->right->right=NULL;
	 			return;
       			}
   			}
		}
		
		void in_order(node *temp){
  			if( temp->left!=NULL ){
    			in_order(temp->left);
    		}
    		if(temp->left == NULL && temp->right == NULL){
    			count_leaf++;  //count leaf nodes;
    		}
    		count++;
    		cout<<temp->info<<"  ";
  			if( temp->right!=NULL ){
		 		in_order(temp->right);
  			}
  			if(root==NULL){
				cout<<" Tree is empty.\n";
				return;
    		}
    	}
    	
		int pow(int n){
			int a = 2 * n;
			return a - 1;
		}
		void str(){
			int n = count_leaf;
			if(count == pow(n)){
				cout<<"strictly binary tree :"<<endl;
			}
			else{
				cout<<"NOT strictly binary tree :"<<endl;
			}
		}
};


int main(){
	BST b;
	for(int i = 0;i < 7; i++){
		cout<<"Enter number to insert in tree :"<<endl;
		cin>>b.number;
		b.binary(b.root);
	}
	b.in_order(b.root);
	cout<<endl;
	cout<<" no's of leaf = "<<b.count_leaf<<endl;
	cout<<"no's of nodes = "<<b.count<<endl;
	b.str();
}
