#include<iostream>
#include<string>
using namespace std;
struct node{
	char value;
	node *next;
};

class stackfix{
	private:
		node *top , *temp  ;
		int *current  , *currentNext , *intArray;
		bool plus , mul , divide, minus;
		int capacity;
		int count;
		bool check;
		char out;
		char postfix[100];
	public:
		stackfix(){
			top = NULL;
			temp = NULL;
			for(int i = 0; i < 100; i++){
				postfix[i] = NULL;
			}
		
			count = 0;
			capacity = 100;

			
		}
		
		~stackfix(){
			delete top , temp;
		}
		
		bool precedence(char op1 , char op2){
			if(op1 == '*' && (op2 == '*' || op2 == '-' || op2 == '+')){
				
				return true;
			}
			else if(op1 == '*' && (op2 == '*' || op2 == '-' || op2 == '+')){
			
				return true;
			}
			else if(op1 == '/' && (op2 == '*' || op2 == '-' || op2 == '+'|| op2 == '/')){
				
				return true;
			}
			else if(op1 == '+' && ( op2 == '-' || op2 == '+')){
				
				return true;
			}
			else if(op1 == '-' && ( op2 == '-' || op2 == '+')){
				
				return true;
			}
			else{
				
				return false;
			}
		}
		void push(char input){
	
			if(count < capacity){
				if(top == NULL){
					top = new node;
					top->value = input;
					top->next = NULL;
					count++;
				}
				else{
					temp = new node;
					temp->value = input;
					temp->next = top;
					top = temp;
					count++;
				}
			}
			else{
				cout << "stack is overflow: ";
				return;
			}
		}
		void pop(){
			if(top == NULL){
				return;
			}
			else{
				temp= top;
				top = top->next; 
				delete temp;
				temp = NULL;
				count--;
				return;
			}
		}

		void scaning(string input){
			int j = 0;
			for(int i = 0; i < input.length(); i++){
				if(input[i] >= 48 && input[i] <=57){
					postfix[j] = input[i];
					j++;
				}
				else if(input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*' ){
					if(count >= 1){
						check = precedence(input[i] , top->value);
						if(check == false){
							push(input[i]);
							check = precedence(top->value , top->next->value);
							out = top->value;
							pop();
							postfix[j] = out;
							j++;
								
						}
						else{
							out = top->value;
							pop();
							postfix[j] = out;
							j++;
							push(input[i]);
						}
					}
					else{
						push(input[i]);	
					}
				}
				
				out  = top->value;
				pop();
				postfix[j] = out;
				
				for(int i = 0; i < input.length(); i++){
					cout << postfix[i];
				}
				cout << endl;
			}
				
	}
			
};

int main(){
	
	stackfix stf;
	string input;
	cout << "Enter Expression plz: " ;
	getline(cin , input);
	stf.scaning(input);
}
