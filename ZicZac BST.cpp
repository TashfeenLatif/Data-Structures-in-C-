#include<iostream>
using namespace std;

struct node
{
	int info;
	node *left , *right;
};
class zig
{
private:
	node *temp , *ptr ,*temp1;
	int key;
	int count;
public:
	node *root;
	zig(){
		temp1 = temp = ptr = root = NULL;
		count = 0;
	}
	~zig(){
		delete root;
		delete temp;
	}
	void insert()
	{
		if(root == NULL)
		{
			cout << "Enter value "<<endl;
			root = new node;
			cout << "Ente Value for root:"<<endl;
			cin >> root->info;
			root->left = NULL;
			root->right = NULL;
			temp = root;
			return;
		}
		if(temp->left == NULL && temp->right == NULL){
			if(count % 2  == 0)
			{
				temp->right = new node;
				cout << "Enter value for right:"<<endl;
				cin >> temp->right->info;
				temp->right->right = NULL;
				temp->right->left = NULL;
				count++;
				temp = temp->right; 
//				ptr = temp;
				return;
			}
			if(count % 2 != 0)
			{
				temp->left = new node;
				cout << "Enter info for left:"<< endl;
				cin >> temp->left->info;
				temp->left->left = NULL;
				temp->left->right = NULL;
				count++;
				temp = temp->left;
//				temp1 = temp;
				return;
			}
		}
	}
	
	void print(node *temp){
		if(temp->left != NULL)
			print(temp->left);
		
		cout << " /// "  << temp->info;
		
		if(temp->right != NULL)
			print(temp->right);
			
	}
};
int main()
{
	zig z;
	for (int i = 0; i < 10; ++i)
	{
		
		z.insert();
		cout << endl;
		z.print(z.root);
		cout << endl;
	}
	z.print(z.root);
}
