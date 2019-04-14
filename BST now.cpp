#include<iostream>
#include<stdio.h>
using namespace std;

struct TreeNode{
	int value;
	TreeNode *left;
	TreeNode *right;
};

class BST{
	private:
		TreeNode *temp;
		TreeNode * ptr;
		TreeNode * ptr2;
		TreeNode * current;
		int swap;
		int h;
		int count , count1;

	public:
		bool flag;
	BST(){
		root  = temp = ptr = current =  NULL;
		count  = count1 =  0;
		h = 0;
		flag = false;
	}
		TreeNode *root;
		int number;
	
	void insertion_in_bst(TreeNode *temp){
		if(root == NULL){
			temp = new TreeNode;
			cout << "Enter Value for root:"<<endl;
			temp->value = number;
			temp->left = NULL;
			temp->right = NULL;
			root  = temp;
			return;
		}
		if(temp->value == number){
			cout << "Its duplicate so select another one:"<<endl;
			return;
		}
		else if(number > temp->value){
			if(temp->right != NULL){
				insertion_in_bst(temp->right);
				return;
			}
			else{
				temp->right = new TreeNode;
				cout << "Enter Value for right:"<<endl;
				temp->right->value = number;
				temp->right->right = NULL;
				temp->right->left = NULL;
				return;
			}
		}
		else if(number < temp->value){
			if(temp->left != NULL){
				insertion_in_bst(temp->left);
				return;
				
			}
			else{
				temp->left = new TreeNode;
				cout << "Enter Value for left:"<<endl;
				temp->left->value = number;
				temp->left->right = NULL;
				temp->left->left = NULL;
				return;
			}
		}
	}
	void inorder(TreeNode *root){
		if (root != NULL)
		{
			inorder(root->left);
			cout << root->value << " ";
			inorder(root->right);
		}
		
	}
	
	
	void preorder(TreeNode *root){
		if (root != NULL)
		{
			cout << root->value << " ";
			preorder(root->left);
			preorder(root->right);
		}
	}
	
	void postorder(TreeNode *root){
		if (root != NULL)
		{
			postorder(root->left);
			postorder(root->right);
			cout << root->value << " ";
		}
	}
	
	int FindMax(TreeNode *temp){
		if (temp == NULL)
		{
			cout << "There is no tree so no max:"<<endl;
	
		}
		else if (temp->right == NULL)
		{
			cout << temp->value;
		}
		else
			FindMax(temp->right);
}
	int FindMin(TreeNode *temp){
		if (temp == NULL)
		{
			cout << "There is no tree so no max:"<<endl;
		}
		else if (temp->left == NULL)
		{
			cout << temp->value;
		}
		else
			FindMin(temp->left);
		}

	
		void deletion_in_binary_tree(TreeNode*temp){
			if(root == NULL){
				cout << "Tree is empty:"<<endl;
			}
			if(root->value == number){
				if(root->left!=NULL && root->right!=NULL){
					temp = root;
					current = temp;
 					ptr = current->right;
					if(ptr->left == NULL){
						swap = ptr->value;
						ptr->value = current->value;
						current->value = swap;
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
							swap = ptr->left->value; 
							ptr->left->value = current->value;
							current->value = swap;
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
							swap = ptr->left->value; 
							ptr->left->value = current->value;
							current->value = swap;
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
			
			if(temp->value > number){
				if(temp->left->value!= number){
					deletion_in_binary_tree(temp->left);
					return;
					
				}
				else if(temp->left->value == number && temp->left->left == NULL &&temp->left->right == NULL){
					delete temp->left;
					temp->left = NULL;
					return;
				}
				else if(temp->left->value == number && temp->left->left == NULL &&temp->left->right != NULL ||temp->left->left != NULL &&temp->left->right == NULL ){
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
			
				else if(temp->left->value == number && temp->left->left!=NULL && temp->left->right!=NULL)
				{
					current = temp;
					current = current->left;
					ptr = current->left;
					if(ptr->right == NULL){
						swap = ptr->value;
						ptr->value = current->value;
						current->value = swap;
						
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
							swap = ptr->right->value; 
							ptr->right->value = current->value;
							current->value = swap;
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
								
							swap = ptr->right->value; 
							ptr->right->value = current->value;
							current->value = swap;
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

		
				if(temp->value < number){
					if(temp->right->value!= number){
						deletion_in_binary_tree(temp->right);
						return;
					
				}
					else if(temp->right->value == number && temp->right->left == NULL &&temp->right->right == NULL){
						delete temp->right;
						temp->right = NULL;
						return;
					}
					else if(temp->right->value == number && temp->right->left == NULL &&temp->right->right != NULL ||temp->right->left != NULL &&temp->right->right == NULL ){
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
							
					else if(temp->right->value == number && temp->right->left!=NULL && temp->right->right!=NULL)
				{
					
					current = temp;
					current = current->right;
					ptr = current->right;
					if(ptr->left == NULL){
						swap = ptr->value;
						ptr->value = current->value;
						current->value = swap;
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
							swap = ptr->left->value; 
							ptr->left->value = current->value;
							current->value = swap;
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
							swap = ptr->left->value; 
							ptr->left->value = current->value;
							current->value = swap;
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
//			<----------	Write a function which will return the number of nodes in Binary Tree. (There
//				must not be any counter in insertion and deletion)-------->
	
	int TotalNode(TreeNode *temp){
		int count = 1;
		if(temp == NULL){
			cout << "No tree is found:"<<endl;
			return 0;
		}
		if(temp->left != NULL){
			count = count + TotalNode(temp->left);
		}	
		if(temp->right != NULL){
			count = count + TotalNode(temp->right);
			}
			
		
		return count;	

	}
	void delete_whole_tree(TreeNode *temp){
		if (temp != NULL)
		{
			delete_whole_tree(temp->left);
			delete_whole_tree(temp->right);
			delete temp;
		}
		
	}
	
		void Find(TreeNode *temp){			
			
			if(temp != NULL){
				Find(temp->left);
				if(temp->value == number){
					flag = true;
				}
				Find(temp->right);
			}
		
				
		}
	
	
	
	int height(TreeNode*temp){  
    	if (temp == NULL)  
    	    return 0;  
    	else{  
			int lDepth = height(temp->left);  
        	int rDepth = height(temp->right);  
        	
        	if (lDepth > rDepth)  
        	    return(lDepth + 1);  
        	else return(rDepth + 1);  
 	   }	  
	}
//					<----------Write a function which will print nodes in breadth-first traversal. For Example:
//					the output for Tree-1 is 1-3-2-5-4 and for Tree-2 is 1-2-3-4-5-6-7------->

	void check_height(TreeNode * temp, int gh){
		if(temp->left!=NULL){
			h++;
			check_height(temp->left, gh);
			h--;
		}
		if(temp->right!=NULL){
			h++;
			check_height(temp->right, gh);
			h--;
		}
		if( h == gh){
			cout << temp->value << " ";
		}
	}
	void breadth_first(TreeNode * temp){
		int h2 ,heightval;
		heightval = 0;
		heightval = height(temp);
		for(int i = 0; i< heightval; i++){
			h = 0;
			h2 = i;
			check_height(temp,h2);
		}
	}	 
//						<------------ Write a function for printing data in reverse order. For example, the output for
//						the Tree-1 is 5-4-3-2-1 and Tree-2 should be: 4-5-6-7-2-3-1.-------------->	
	
	void Reverseorder(TreeNode *root){
		if (root != NULL)
		{
			Reverseorder(root->right);
			Reverseorder(root->left);
			cout << root->value << " ";
			
		}
		
	}	
//	
//	<----------------------Give an algorithm for finding the sum of all elements in BST----------------->
	
	int sum_of_tree(TreeNode *root){
		if (root != NULL)
		{
			return root->value + sum_of_tree(root->left) + sum_of_tree(root->right);
		}
		else{
			return 0;
		}
		
	}
						
};
int main(){
	BST bst;
//	<-------------- Changing loop value to get how many nodes in tree-------------->
	for(int i= 0; i < 10; i++){
		cout << "Enter value :"<<endl;
		cin >> bst.number;	
		bst.insertion_in_bst(bst.root);
	
	}
	cout << "InOrder is:"<<endl;
	bst.inorder(bst.root);
	cout <<endl;
	
	
	cout << "PostOrder is:"<<endl;
	bst.postorder(bst.root);
	cout <<endl;
	
	cout << "PreOrder is:"<<endl;
	bst.preorder(bst.root);
	cout <<endl;
	
	cout << "Maximum Value in tree is:  ";
	bst.FindMax(bst.root);
	cout << endl;
	cout << "Minimum Value in tree is:  ";
	bst.FindMin(bst.root);
	cout << endl;
	 
	cout << "Enter Value for searching either it is in tree or not:"<<endl;
	cin >> bst.number;
	bst.Find(bst.root);
	if(bst.flag == true){
			cout << "It is in tree:"<<endl;
	}
	else if(bst.flag == false){
		cout << "It is not in tree:"<<endl;
	}
	cout << endl;
	
	cout << "Total Nodes are: " << bst.TotalNode(bst.root);
	cout << endl;
	
	
	cout << "Breadth first tree is:"<<endl;
	bst.breadth_first(bst.root);
	cout << endl;
	
	cout << "Reverse Order of tree is:"<<endl;
	bst.Reverseorder(bst.root);
	cout << endl;
	
	
	cout << "Sum of  whole tree is:"<<endl;
	cout << bst.sum_of_tree(bst.root);
	cout << endl;
	
	cout << "Enter Value for deletion:"<<endl;
	cin >> bst.number;
	bst.deletion_in_binary_tree(bst.root);
	bst.inorder(bst.root);
	cout << endl;
	cout << "Deleting whole tree:"<<endl;
	bst.delete_whole_tree(bst.root);
	bst.inorder(bst.root);
	
	return 0;
	}

