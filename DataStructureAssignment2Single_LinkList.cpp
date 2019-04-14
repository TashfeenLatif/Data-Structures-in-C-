#include <iostream>
using namespace std;

struct node{
	int info;
	node *next;
};

class Link_List{
	private:
		node *start, *ptr, *temp, *temp1;
	public:
		Link_List(){
			start = NULL;
			ptr = NULL;
			temp = NULL;
			temp1 = NULL;
		}
		~Link_List(){
			delete start, ptr, temp, temp1;
		}
		
		void Insert_start(){
			if(start == NULL){
				start = new node;
				cin >> start->info;
				start->next = NULL;
			}
			else{
				ptr = new node;
				cin >> ptr->info;
				ptr->next = start;
				start = ptr;
				
			}
		}
		
		void Insert_mid_end(){
			ptr = start;
			cout << "After the num " << endl;
			int key;
			cin >> key;
			while(ptr != NULL){
				if(ptr->info == key){
					temp = ptr;
					ptr = new node;
					cin >> ptr->info;
					ptr->next = temp->next;
					temp->next = ptr;
				}
				ptr = ptr->next;
			}
		}
		
		void Deletion_one(){
			cout << "Enter the Delete Number " << endl;
			int key;
			cin >> key;
			if(start == NULL){
				cout << "No value in Link list" << endl;
				return;
			}
			ptr = start;
				while(ptr->next != NULL){
					if(ptr->next->info == key){
						cout << "value deleted: " << ptr->next->info << endl;
						temp = ptr->next;
						ptr->next = temp->next;
						delete temp;
						temp = NULL;
						continue;
					}
					cout << "while" << endl;
					ptr = ptr->next;
				}
			if(key == start->info){
				temp = start;
				start = temp->next;
				delete temp;
				temp = NULL;
			}
			
		}
		
		void Deletion_Max_Min(){
			cout << "Enter the MAx Min " << endl;
			int key_Max, key_Min;
			key_Max = start->info;
			key_Min = start->info;
			ptr = start;
			if(start == NULL){
				cout << "No value in Link list" << endl;
				return;
			}
			while(ptr != NULL){
				if(ptr->info > key_Max){
					key_Max = ptr->info;
				}
				if(ptr->info < key_Min){
					key_Min = ptr->info;
				}
				ptr = ptr->next;
			}
					
			ptr = start;
			while(ptr->next != NULL){
				if(ptr->next->info == key_Max){
					temp = ptr->next;
					ptr->next = temp->next;
					delete temp;
					temp = NULL;
					continue;
				}
				
				if(ptr->next->info == key_Min){
					temp = ptr->next;
					ptr->next = temp->next;
					delete temp;
					temp = NULL;
					continue;
				}
				ptr = ptr->next;
			}
			
			if(start->info == key_Max){
				temp = start;
				start = start->next;
				delete temp;
				temp = NULL;
			}
			if(start->info == key_Min){
				temp = start;
				start = start->next;
				delete temp;
				temp = NULL;
			}
		
		}
		
		void delelteMaxMin(){
			node *max;
			node *min;
			max = start;
			min = start;
			ptr = start;
			while(ptr != NULL){
				if(ptr->info > max->info){
					max = ptr;
				}
				
				if(ptr->info < min->info){
					min = ptr;
				}
				ptr = ptr->next;
			}
			cout << "max " << max->info << " min " <<  min->info << endl;
			ptr = start;
			
			while(ptr->next != NULL){
				if(ptr->next->info == max->info){
					temp = max;
					ptr->next = temp->next;
					delete temp;
					temp = NULL;
					continue;
				}
				
				if(ptr->next->info == min->info){
					temp = min;
					ptr->next = min->next;
					delete temp;
					temp = NULL;
					continue;
				}	
				ptr = ptr->next;
			}
			
			
			
		}
		
		void Search(){
			cout << "Enter the search Number" << endl;
			int key;
			cin >> key;
			ptr = start;
			while(ptr != NULL){
				if(ptr->info == key){
					cout << "It is search value" << endl;
					return;
				}
				ptr = ptr->next;
			}
			if(ptr == NULL){
				cout << "It is not search value" << endl;
			}
		}
		
		void Bubble_sort(){
			
			
		}
		
		void Print(){
			ptr = start;
			cout << "Start " << ptr->info << endl;
			while(ptr != NULL){
				if(ptr->next == NULL){
					cout << ptr->info << endl;
				}
				else{
					cout << ptr->info << " --> ";
				}
				ptr = ptr->next;
			}	
		}
	
};


int main(){
	Link_List LL;
	LL.Insert_start();
	LL.Insert_start();
	LL.Insert_start();
	LL.Insert_start();
	LL.Insert_start();
	LL.Insert_start();
	LL.Insert_start();
	LL.Insert_start();
	LL.Insert_start();
	LL.Insert_start();
	LL.Print();
	LL.delelteMaxMin();
	LL.Print();
}
