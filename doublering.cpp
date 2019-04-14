#include<iostream>
#include<stdio.h>
using namespace std;


struct node{
	int info;
	node *next;
	node *prev;
};
class doublering{
	private:
		node *temp;
		node *head;
		node *current;
	public:
		doublering(){
			head = NULL;
			temp = NULL;
		}
		
		
		void insert(){
			if(head == NULL){
				head = new node;
				cout << "Enter value:" << endl;
				cin >> head->info;
				head->next = head;
				head->prev = head;
				return;
			}
			
			temp = head;
			int key;
			cout << "Enter key:"<<endl;
			cin >> key;
			do{
				if(temp->info == key) {
					current = temp;
					current = new node;
					cout << "Enter Value:"<<endl;
					cin >>current->info;
					current->next = temp->next;
					current->prev  = temp;
					current->next->prev  = current;
					temp->next= current;
				}
			
			temp = temp->next;
			} while(temp != head);
		}
		void print(){
			temp = head;
		
			do{
				cout << temp->info << " <-----> ";
				temp = temp->next;
			}
			while(temp != head);
			cout << endl;
		}
		void search(){
			int key;
			cout <<"ENTER KEY TO SEARCH:"<<endl;
			cin >> key;
		do{
				if(temp->info == key){
				cout << "KEY IS FOUND:"<<endl;
				return;
				}
				temp = temp->next;
			
				
				}
				while(temp!= head);
				cout << "KEY IS NOT FOUND:"<<endl;
				}
				
		void deletekro(){
			int key;
			cout <<"Enter value of key which you want to delete:"<<endl;
			cin >> key;
			while(temp!=head){
				if(temp->info == key){
					current = temp;
					current->next = temp->next;
					current->prev  = temp;
					current->next->prev  = current;
					temp->next= current;
					delete temp;
					temp = NULL;
				}
				temp = temp->next;
				
			}			
		}
				
	
};
int main(){
	doublering dbl;
	for(int i = 0; i<5; i++){
		dbl.insert();
		
	}
	dbl.print();
	dbl.search();
	dbl.deletekro();
	return 0;
	
}



