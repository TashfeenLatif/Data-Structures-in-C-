////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

struct node{
	int info;
	node *right,*left;
};

class BST{
	private:
		bool flag,flag1;
		node *temp,*current,*temp1,*temp3;
	public:
		int number,temp2,l_count,count_leaf,count,h,ph;
		node *root;
		int num;
		BST(){
			flag = flag1 = false;
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
		int height(node *temp){
			int lh = 0;
			int rh = 0;
			int h = 0;
			if(temp->left!=NULL){
				lh++;
				lh+=height(temp->left);
			}
			if(temp->right!=NULL){
				rh++;
				rh+=height(temp->right);
			}
			if(lh>rh){
				h = lh;
			}
			else if(rh>lh){
				h = rh;
			}
			else{
				h = rh;
			}
			return h;
		}
		int bf(node *temp){
			int lb = 0;
			int rb = 0;
			if(temp->left!=NULL){
				lb = height(temp->left)+1;
			}
			if(temp->right!=NULL){
				rb = height(temp->right)+1;
			}
			int bf = lb-rb;
			return bf;
		}
		void bst(node *temp){
			if(bf(temp) == 1){
				flag = true;
			}
			else if(bf(temp)>1 || bf(temp)<=-1){
				flag1 = true;
			}
		}
		void cheack(node *temp){
			
			if(temp->left!=NULL){
				cheack(temp->left);
			}
			cout<<"bf = "<<bf(temp)<<endl;
			bst(temp);
			if(temp->right!=NULL){
				cheack(temp->right);
			}
		}
		void cbt(){
			if (flag1 == true){
				cout<<"not cbt :"<<endl;
			}
			else if(flag == true && flag1 == false){
				cout<<"cbt :"<<endl;	
			}
		}
		void in(node *temp){
			if(temp->left != NULL){
				in(temp->left);
			}
			cout<<temp->info<<" ";
			
			if(temp->right != NULL){
				in(temp->right);
			}
		}
};
int main(){
	BST b;
	for(int i = 0; i < 5; i++){
		cout<<"Enter number to insert in tree :"<<endl;
		cin>>b.number;
		b.binary(b.root);
	}
	b.in(b.root);
	cout<<endl;
	b.cheack(b.root);
	b.cbt();
}
