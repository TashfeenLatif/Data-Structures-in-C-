#include<iostream>
#include<stdio.h>
using namespace std;

struct node{
	int info;
	node * left;
	node *right;

	
};
class BST{
	private:
		node * temp;
		node * ptr;
		node *current;
		node *ptr2;
		bool flag;
		
	public:
		node * root;
		int value;
		int number;
		BST(){
			temp = NULL;
			ptr = NULL;
			ptr2 = NULL;
			root = NULL;
			flag = false;
		}
		~BST(){
			delete temp,ptr,ptr2,current;
		}
		void insertion_in_binary_tree(node*temp){
			if(root == NULL)
			{
				temp = new node;
				temp->info = number;
				temp->right = NULL;
				temp->left  = NULL;
				root = temp;
				
				return;
			}
			if(temp->info == number)
			{
				cout <<"Its Duplicate So Give Me a Another Number:"<<endl;
				return;
			}
			if(temp->info < number)
			{
				if(temp->right !=NULL)
				{
					insertion_in_binary_tree(temp->right);
					return;
				}
				else
				{
					temp->right =  new node;
					temp->right->info= number;
					temp->right->left = NULL;
					temp->right->right = NULL;
					return;
				}
			}
			if(temp->info > number)
			{
				if(temp->left != NULL)
				{
					insertion_in_binary_tree(temp->left);
					return;
				}
				else
				{
					temp->left =  new node;
					temp->left->info = number;
					temp->left->left = NULL;
					temp->left->right = NULL;
					return;
				}
			}
			
	
		}
		
		void checkSBT(){
			flag = false;
			
			orderPPP(root);
			
			if(flag == false){
				cout << "it is SBT: " << endl;
			}
			else{
				cout << "It is not SBT:"<<endl;
			}
			
		}
		
		void orderPPP(node*temp)
		{
	
		
		if(root == NULL)
		{	
			cout <<"TREE IS EMPTY:"<<endl;
			return;
		}
		if(temp->left!=NULL)
			orderPPP(temp->left);
			
			
		if((temp->left == NULL && temp->right != NULL) ||(temp->left != NULL && temp->right == NULL))
		{	
			
			flag = true;
				
		}
			
		if(temp->right != NULL)
			orderPPP(temp->right);
			
	}
		
		void print_in_order(node*temp)
		{
	
		
		if(root == NULL)
			{	
				cout <<"TREE IS EMPTY:"<<endl;
				return;
			}
		if(temp->left!=NULL)
			print_in_order(temp->left);
		cout << temp->info << "  ";
			
			
		if(temp->right != NULL)
			print_in_order(temp->right);
			
	}
	
	
		void deletion_in_binary_tree(node*temp){
			if(root == NULL){
				cout << "Tree is empty:"<<endl;
			}
			if(root->info == number){
				if(root->left!=NULL && root->right!=NULL){
					temp = root;
					current = temp;
 					ptr = current->right;
					if(ptr->left == NULL){
						value = ptr->info;
						ptr->info = current->info;
						current->info = value;
						if(ptr->right!=NULL){
							current->right  = ptr->right;
							delete ptr;
							ptr  = NULL;
							return;	
						}
						else{
							current->right = NULL;
							delete ptr; 
							ptr  = NULL;
							return;
						}
					}
				
					else if(ptr->left!=NULL){
						if(ptr->left->left == NULL){
							value = ptr->left->info; 
							ptr->left->info = current->info;
							current->info = value;
							ptr2 = ptr->left;
							
							if(ptr2->right!=NULL){
								ptr->left = ptr2->right;
								delete ptr;
								ptr  = NULL;
								return;
							}
							else{
								ptr->left = NULL;
								delete ptr2;
								ptr2 = NULL;
								return;
								
							}
					
						}
					}
					else if(ptr->left->left != NULL){
						while(ptr->left->left!=NULL)
							{
								ptr = ptr->left;
						}
							value = ptr->left->info; 
							ptr->left->info = current->info;
							current->info = value;
							ptr2 = ptr->left;
							
							
							
							if(ptr2->right!=NULL){
								ptr->left = ptr2->right;
								delete ptr;
								ptr  = NULL;
								return;
							}
							else{
								ptr->left = NULL;
								delete ptr2;
								ptr2 = NULL;
								return;
								
						}																	
					}
				
			}
		
		}
			
			if(temp->info > number){
				if(temp->left->info!= number){
					deletion_in_binary_tree(temp->left);
					return;
					
				}
				else if(temp->left->info == number && temp->left->left == NULL &&temp->left->right == NULL){
					delete temp->left;
					temp->left = NULL;
					return;
				}
				else if(temp->left->info == number && temp->left->left == NULL &&temp->left->right != NULL ||temp->left->left != NULL &&temp->left->right == NULL ){
					if(temp->left->left == NULL &&temp->left->right != NULL){
						ptr = temp->left;
						temp->left = ptr->right;
						delete ptr;
						ptr = NULL;
						return;
					}
					else{
						ptr = temp->right;
						temp->left = ptr->left;
						delete ptr;
						ptr = NULL;
						return;
					}
			}
			
				else if(temp->left->info == number && temp->left->left!=NULL && temp->left->right!=NULL)
				{
					current = temp;
					current = current->left;
					ptr = current->left;
					if(ptr->right == NULL){
						value = ptr->info;
						ptr->info = current->info;
						current->info = value;
						
						if(ptr->left!=NULL){
							current->left  = ptr->left;
							delete ptr;
							ptr  = NULL;
							return;	
						}
						else{
							current->left = NULL;
							delete ptr; 
							ptr  = NULL;
							return;
						
							}
						}
					
					else if(ptr->right!=NULL){
						if(ptr->right->right == NULL){
							value = ptr->right->info; 
							ptr->right->info = current->info;
							current->info = value;
							ptr2 = ptr->right;
							
							
							if(ptr2->left!=NULL){
								ptr->left = ptr2->left;
								delete ptr;
								ptr  = NULL;
								return;
							}
							else{
								ptr->left = NULL;
								delete ptr2;
								ptr2 = NULL;
								return;
								
							
							}
							
				}
						}
					else if(ptr->right->right!= NULL){
							while(ptr->right->right!=NULL)
							{
								ptr = ptr->right;
								}
								
							value = ptr->right->info; 
							ptr->right->info = current->info;
							current->info = value;
							ptr2 = ptr->right;
							
							
							if(ptr2->left!=NULL){
								ptr->right = ptr2->left;
								delete ptr;
								ptr  = NULL;
								return;
							}
							else{
								ptr->right = NULL;
								delete ptr2;
								ptr2 = NULL;
								return;
								
							}
							
						}
					}
				}

		
				if(temp->info < number){
					if(temp->right->info!= number){
						deletion_in_binary_tree(temp->right);
						return;
					
				}
					else if(temp->right->info == number && temp->right->left == NULL &&temp->right->right == NULL){
						delete temp->right;
						temp->right = NULL;
						return;
					}
					else if(temp->right->info == number && temp->right->left == NULL &&temp->right->right != NULL ||temp->right->left != NULL &&temp->right->right == NULL ){
						if(temp->right->left == NULL &&temp->right->right != NULL){
							ptr = temp->right;
							temp->right = ptr->right;
							delete ptr;
							ptr = NULL;
							return;
						}
						else{
							ptr = temp->left;
							temp->right = ptr->left;
							delete ptr;
							ptr = NULL;
							return;
						}
					
					}
							
					else if(temp->right->info == number && temp->right->left!=NULL && temp->right->right!=NULL)
				{
					
					current = temp;
					current = current->right;
					ptr = current->right;
					if(ptr->left == NULL){
						value = ptr->info;
						ptr->info = current->info;
						current->info = value;
						if(ptr->right!=NULL){
							current->right  = ptr->right;
							delete ptr;
							ptr  = NULL;
							return;	
						}
						else{
							current->right = NULL;
							delete ptr; 
							ptr  = NULL;
							return;
						}
					}
				
					else if(ptr->left!=NULL){
						if(ptr->left->left == NULL){
							value = ptr->left->info; 
							ptr->left->info = current->info;
							current->info = value;
							ptr2 = ptr->left;
							
							if(ptr2->right!=NULL){
								ptr->left = ptr2->right;
								delete ptr;
								ptr  = NULL;
								return;
							}
							else{
								ptr->left = NULL;
								delete ptr2;
								ptr2 = NULL;
								return;
								
							}
					
						}
					}
					else if(ptr->left->left != NULL){
						while(ptr->left->left!=NULL)
							{
								ptr = ptr->left;
							}
							value = ptr->left->info; 
							ptr->left->info = current->info;
							current->info = value;
							ptr2 = ptr->left;
							
							if(ptr2->right != NULL){
								ptr->left = ptr2->right;
								delete ptr;
								ptr  = NULL;
								return;
							}
							
							else{
								ptr->left = NULL;
								delete ptr2;
								ptr2 = NULL;
								return;
								
						}																	
					}
				
			}
		
		}
		
	}
								
};


int main(){
	BST balti;
	for(int i = 0; i < 10; i++){
		cout <<"ENTER VALUE PLZ:"<<endl;
		cin >> balti.number;
		balti.insertion_in_binary_tree(balti.root);
		
	}
	balti.print_in_order(balti.root);
	cout << endl;
	balti.checkSBT();
	
	cout << endl<<"Enter value for deletion:"<<endl;
	cin >>balti.number;
	balti.deletion_in_binary_tree(balti.root);
	balti.print_in_order(balti.root);
	balti.print_in_order(balti.root);
	
}
