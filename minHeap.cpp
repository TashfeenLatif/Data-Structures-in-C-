#include <iostream>
#include<cmath>
using namespace std;

struct node
{
	int info;
	node *left;
	node *right;
	int index;
};

class minHeap
{
private:
	node *temp , *temp1 , *ptr;
	int height , count , h , nodes , swap;
	bool flage;
public:
	node *root;
	int value ,entries;
	minHeap(){
		temp = temp1 = root = ptr = NULL;
		entries = height = count = h = nodes = value = 0;
	}
	~minHeap(){
		delete root;
		delete temp;
	}
void set(node *temp)
	{
		if(temp->left != NULL && h < height)
		{
			h++;
			set(temp->left);
			h--;
		}
		if(temp->right != NULL && h < height)
		{
			h++;
			set(temp->right);
			h--;
		}
		if((temp->left == NULL && h == height-1)||(temp->right == NULL && h == height-1))
		{
			if(flage == false)
			{
				ptr = temp;
				flage = true;
				return;
			}
		}
	}
	void insert(node *temp)
	{
		flage = false;
		if(root == NULL)
		{
			root = new node;
			root->info = value;
			root->left = NULL;
			root->right = NULL;
			temp = root;
			nodes++;
			count++;
			entries++;
			root->index = entries;
			return;
		}
		if(count == nodes)   //if height is at it's max
		{
			count = 0;
			nodes = pow(2,height+1);
			height++;
			cout << "Nodes are :" <<nodes <<endl;
				cout << "height is :" << height <<endl;
			while(temp->left != NULL)
				temp = temp->left;
			temp->left = new node;
			temp->left->info = value;
			temp->left->left = NULL;
			temp->left->right = NULL;
			entries++;
			temp->left->index = entries++;
			count++;
			return;
		}
		if(count != nodes)
		{
			// sort(temp);
			set(temp);
			if(ptr->left == NULL && ptr->right == NULL)
			{
				ptr->left = new node;
				ptr->left->info = value;
				ptr->left->left = NULL;
				ptr->left->right = NULL;
				count++;
				entries++;
				ptr->left->index = entries;
				return;
			}
			if(ptr->left != NULL && ptr->right == NULL)
			{
				// sort(ptr);
				ptr->right = new node;
				ptr->right->info = value;
				ptr->right->left = NULL;
				ptr->right->right = NULL;
				count++;
				entries++;
				ptr->right->index = entries;
				return;
			}
		}
	}
// void sort(node *temp)
// {
// 	if(entries != 0)
// 		{
// 			if(temp->left != NULL)
// 			}
// 			if(temp->right != NULL)
			
// 		}
// }
	void check(node *temp)
	{
		if(temp->left != NULL)
		{
			if(temp->left->info < temp->info)
			{
				cout <<"Temp -> info :"<< temp->info <<" "<<endl;
				swap = temp->info;
				temp->info = temp->left->info;
				temp->left->info = swap;
				cout <<"Temp -> info after swaping:"<< temp->info <<" "<<endl;
			}
			check(temp->left);
		}
		cout << temp->info <<" ";
		if(temp->right != NULL)
		{	
			if(temp->right->info < temp->info)
			{
				cout <<"Temp -> info :"<< temp->info <<" "<<endl;
				swap = temp->info;
				temp->info = temp->right->info;
				temp->right->info = swap;
				cout <<"Temp -> info after swaping:"<< temp->info <<" "<<endl;
			}
			check(temp->right);
		}
		return;
	}
	void print(node *temp)
	{
		if(root == NULL)
		{
			cout << "Tree is empty "<<endl;
			return;
		}
		if(temp->left != NULL)
			print(temp->left);
		cout << temp->info <<" ";
		if(temp->right != NULL)
			print(temp->right);
		return;
	}
	// void delet(node *temp)
	// {
	// 	if(root->left->info > root->right->info)
	// 	{
	// 		swap = root->right->info;
	// 		root->info = root->right->info;
	// 		root->right->info = swap;
			
	// 	}
	// 	delete root;

	// }
};

int main()
{
	minHeap m;
	int i;
	for (int i = 0; i < 9; i++)
	{
	cout << "Enter value for new node" <<endl;
	cin >> m.value;
 	m.insert(m.root);
 	m.entries++;
	}
	m.print(m.root);
	cout << endl;
	for(int i = 0 ; i < 3 ; i++)
	{
	m.check(m.root);
	}
	cout << endl;
	m.print(m.root);
//	delet(m.root);
	
}


// void set(node *temp)
// {
// 	nodes = pow(2,height+1);
// 	for(int i = 0 ; i = entries /2 ; i--)
// 	{
// 		if(i == temp->info);
// 	}
// 	if(temp->left != NULL && temp->right != NULL)
// 	{
// 		temp1 = temp;
// 	}
// 	while(temp->left != NULL)
// 	{
// 		temp1 = temp;
// 		if(temp1->left == NULL ||)
// 	}
// }
