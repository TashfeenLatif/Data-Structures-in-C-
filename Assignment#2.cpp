//							NAME  		----    TASHFEEN LATIF
//							ROLL NO  	----- 17P - 6035(A)	
//							Course 		----DATA STRUCTURES
//										Assignmnet# 2 			
#include<iostream>
#include <string>
#include<fstream>
using namespace std;

struct cellNode
{
	int number;
	string network;
	cellNode *CDown;
};

struct personNode
{
	int CNIC;
	string name;
	string fatherName;
	char gender;
	string address;
	personNode *next;
	cellNode *PersDown;
};

class personType{
private:
	personNode *personHead;
	personNode *personTemp;
	personNode *personTemp2;
	personNode * personTemp1;
	personNode *temp;
	cellNode *cellHead , *cell2, *celltemp , *celltemp2 ,*cell, *ptr;
	int sim;
public:
	personType(){
		personHead = NULL;
		personTemp = NULL;
		personTemp2 = NULL;
		personTemp1 = NULL;
		cellHead = celltemp = celltemp2 = cell = cell2 = ptr =  NULL;
  }

	void setPersonData(){

		cellHead = NULL;
		if(personHead == NULL){
			personHead = new personNode;
			cout << "Enter CNIC FOR head:"<<endl;
			cin >> personHead->CNIC;
			cout << "Enter name FOR head:"<<endl;
			cin >> personHead->name;
			cout << "Enter father name FOR head:"<<endl;
			cin >> personHead->fatherName ;
			cout << "Enter gender FOR head:"<<endl;
			cin >>  personHead->gender;
			cout << "Enter address FOR head:"<<endl;
			cin >> personHead->address;
			personHead->next = NULL;
			personHead->PersDown = NULL;
			personTemp = personHead;
		 	personTemp2 = personHead;
			int i = 0;
			cout << "Enter number of sim:"<<endl;
			cin >> sim;
			if(sim >4){
				cout << "Not select maximum than 4:"<<endl;
				sim  = 4;
			}
			while(i < sim){
				if (cellHead == NULL){
					cellHead = new cellNode;
					cout << "Cell CellNumber for head:"<<endl;
					cin >> cellHead->number;
					cout << "Enter network:"<<endl;
					cin >> cellHead->network ;
					cellHead->CDown = NULL;
					personTemp->PersDown = cellHead;
				}
				else{
					celltemp = new cellNode;
					cout << "Enter CellNumber:"<<endl;
					cin >> celltemp->number;
					cout << "Enter network:"<<endl;
					cin >>celltemp->network;
					celltemp->CDown = cellHead;
					cellHead = celltemp;
					personTemp->PersDown = cellHead;

				}
				i++;
				}
			}
		else{
			while(personTemp->next != NULL){
				personTemp = personTemp -> next;

			}
			personTemp->next = new personNode;
			cout <<"Enter CNIC for next node:"<<endl;
			cin >> personTemp->next->CNIC;
			cout <<"Enter name for next node:"<<endl;
			cin >> personTemp->next->name;
			cout <<"Enter father name for next node:"<<endl;
			cin >> personTemp->next->fatherName;
			cout <<"Enter gender for next node:"<<endl;
			cin >> personTemp -> next-> gender;
			cout <<"Enter address for next node:"<<endl;
			cin >> personTemp -> next-> address;
			cout <<"Enter CNIC for next node:"<<endl;
			personTemp -> next -> next = NULL;
			cout <<"Enter CNIC for next node:"<<endl;
			personTemp -> next -> PersDown = NULL;
	
			int i = 0;
			cout << "Enter number of sim:"<<endl;
			cin >> sim;
			if(sim > 4){
				cout << "not select maximum than 4:"<<endl;
				sim = 4;
			}
			while(i < sim){
				if (cellHead == NULL){
					cellHead = new cellNode;
					cout << "Enter cellNumber:"<<endl;
					cin >> cellHead->number;
					cout << "Enter network:"<<endl;
					cin >> cellHead->network;
					cellHead->CDown = NULL;
					personTemp->next->PersDown = cellHead;
				}
				else{
					celltemp = new cellNode;
					cout << "Enter CellNumber:"<<endl;
					cin >> celltemp->number ;
					cout << "Enter network:"<<endl;
					cin >> celltemp->network;
					celltemp->CDown = cellHead;
					cellHead = celltemp;
					personTemp->next->PersDown = cellHead;

				}
				i++;
			}

		}
		return;
	}
	void deletion_with_person(){
		int cnic;
		cout << "Enter value of CNIC who you want to delete:"<<endl;
		cin >> cnic;
		if(personHead == NULL){
			cout << "List is empty so we can't del it:"<<endl;
		}
		if(personHead->CNIC == cnic){
			personTemp = personHead;
			personHead = personHead->next;
			delete personTemp;
			personTemp = NULL;
			return;
		}
		else{
			for(personTemp2 = personHead; personTemp2->next != NULL; personTemp2  = personTemp2->next){
				if(personTemp2->next->CNIC == cnic){
					personTemp = personTemp2->next;
					personTemp2->next = personTemp->next;
					delete personTemp;
					personTemp = NULL; 
					return;
				}
				else{
					cout << "Cnic is not found:"<<endl;
					break;
				}
			}					
		}
	}
		
		void deletion_with_cellnode(){
			int cnic;
			int cell;
			cout << "Enter value for cnic:"<<endl;
			cin >> cnic;
			cout << "Enter Value for cell who you want to delete:"<<endl;
			cin >> cell;
				for(personTemp2 = personHead; personTemp2!= NULL; personTemp2  = personTemp2->next){
					for(celltemp2 = personTemp2->PersDown; celltemp2 != NULL; celltemp2 = celltemp2->CDown){
						cout << "ffffd" << endl;
						if(celltemp2->CDown != NULL && celltemp2->CDown->number == cell){
							cell2 = celltemp2->CDown;
							celltemp2->CDown  = cell2->CDown;
							delete cell2;
							cell2 = NULL;
							return;
							}
						else if(celltemp2->number == cell && celltemp2->CDown != NULL){
							personTemp2->PersDown = celltemp2->CDown;
							delete celltemp2;
							celltemp2 = NULL;
							return;
							}
						
					}
				
				}
		
		}
		void only_cell_person_head(){
			int cnic;
			int cell;
			cout << "Enter value for cnic:"<<endl;
			cin >> cnic;
			cout << "Enter Value for cell who you want to delete:"<<endl;
			cin >> cell;
		
			cellHead = personHead->PersDown;
			if(personHead->CNIC == cnic){
				if(cellHead->number == cell){
					delete cellHead;
					cellHead = NULL;
					personHead->PersDown = NULL;
					return;
				}
				else{
					for(celltemp = cellHead; celltemp != NULL; celltemp = celltemp->CDown){
						if(celltemp->CDown->number == cell){
							cell2 = celltemp->CDown;
							celltemp->CDown  = cell2->CDown;
							delete cell2;
							cell2 = NULL;
							return;
							}
						else if(celltemp->number == cell){
							delete celltemp;
							celltemp = NULL;
							}
						}
					}	
			}
		}
			
				
		
		void total_networks(){
	
			int totalcount = 0;
			for(personTemp2 = personHead; personTemp2 != NULL; personTemp2 = personTemp2->next) {
				
				for(cell = personTemp2->PersDown ; cell != NULL ; cell = cell->CDown){
					if(cell->network == "jazz" || cell->network == "ufone" || cell->network == "zong" ||cell->network == "telenor" ){
						
						totalcount++;
					}
				}
			}
			cout <<"Total : " << totalcount;
		}
		void change_networks(){
			int cnic;
			string net;
			cout << "Enter value for cnic:"<<endl;
			cin >> cnic;
			cout << "Enter Value for net:"<<endl;
			cin >> net;
			for(personTemp2 = personHead; personTemp2!= NULL; personTemp2  = personTemp2->next){
				for(celltemp = personTemp2->PersDown ; celltemp!= NULL ; celltemp = celltemp->CDown){
					if(personTemp2->CNIC == cnic){
						if(celltemp->network == net){
							cout << "NOw changing the network of person:"<<endl;
							cin >> celltemp->network;
						}
					}
				}
			}
		}
	void changeOwnership(){
		int pers1 , pers2 , cell;
		cout << "Enter  person CNIC: ";
		cin >> pers1;
		cout << "Enter 2nd person CNIC: ";
		cin >> pers2;
		cout << "Enter Cell Number: ";
		cin >> cell;
		personNode * ptr;
		personTemp = personHead;
		while(personTemp != NULL){
			if(pers1 == personTemp->CNIC){
				ptr = personTemp;
			}
			if(pers2 == personTemp->CNIC){
				temp = personTemp;
			}
			personTemp = personTemp->next;
		}
		cellNode *current;
		if(ptr->PersDown != NULL && ptr->PersDown->number == cell){
			current = ptr->PersDown;
			ptr->PersDown = current->CDown;
			current->CDown = temp->PersDown;
		}
		else{
			celltemp = ptr->PersDown;
			while(celltemp != NULL){
				if(celltemp->CDown != NULL && cell == celltemp->CDown->number){
					current = celltemp->CDown;
					celltemp->CDown = current->CDown;
					current->CDown = temp->PersDown;
					continue;
				}
				celltemp = celltemp->CDown;
			}
		}
		temp->PersDown = current; 
	}
	

	
		
		void update_addressss(){
			string addr;
			cout << "Enter jis ko change krna wo addresss do:"<<endl;
			cin >> addr;
			for(personTemp2 = personHead; personTemp2->next != NULL; personTemp2 = personTemp2->next){
				if(personTemp2->next->address == addr){
					cout << "ab ayai ga new address:"<<endl;
					cin >> personTemp2->next->address;
				}
			}
			
		}
		void delete_Store(){
		
		ofstream out;
		out.open("out.txt");
		if(out.is_open()){
			out << "CNIC |" <<"  "<<"Name |" << "FatherName |" << " " << "Gender| " <<" " << "Address"<< endl;
			personTemp = personHead;
			personTemp1 = personHead->next;
			while(personTemp1!=NULL){
				out << personTemp->CNIC <<"	" << personTemp->name << "	" << personTemp->fatherName << "		"<<personTemp->gender << "	" << personTemp->address<< endl;
				if (personTemp->PersDown != NULL) {
					celltemp = personTemp->PersDown;
					celltemp2 = celltemp->CDown;
					while(celltemp2!=NULL){
						out << celltemp->network << " " << celltemp->number <<endl;
						delete celltemp;
						celltemp = celltemp2;
						celltemp2 = celltemp2->CDown;
					}
					out << celltemp->network << " " << celltemp->number <<endl;
					delete celltemp;
				}
				out << endl;
				delete personTemp;
				personTemp = personTemp1;
				personTemp1 = personTemp1->next;
			}
			out << personTemp->CNIC <<"	" << personTemp->name << "	" << personTemp->fatherName << "		"<<personTemp->gender << "	" << personTemp->address<< endl;
			delete personTemp;
			personTemp = NULL;
			personHead = NULL;
		}
	}

	void print(){
		
		temp = personHead;
		while(temp != NULL){
			
			cout << "CNIC of person  is : " << temp -> CNIC << endl;
			cout << "Name of person is: " << temp -> name << endl;
			cout << "FatherName of person is  : " << temp -> fatherName << endl;
			cout << "Gender of person is : " << temp->gender << endl;
			cout << "Address of person is : " << temp->address << endl;

			ptr = temp->PersDown;
			cout << endl;
			while(ptr != NULL){
				cout << "CellNo" << "     "  << " Sim " << endl;
				cout << ptr->number << "             " <<ptr->network << endl;
				ptr = ptr->CDown;
			}
			temp = temp -> next;
			cout << " -----------------PERSON END----------------------" << endl;
		}
		return;
	}

};

int main(){
//	
	personType p1;
	p1.setPersonData();
	p1.print();
	p1.delete_Store();

	p1.print();
		for(int i = 0; i < 10; i++ ){
			p1.setPersonData();
			p1.print();	
			
		}
	p1.deletion_with_person();
	cout << "DEletion with Person NOde:"<<endl;
	p1.print();
	
	cout << endl;
	
	p1.deletion_with_cellnode();
	cout  << "DEletion with Cell NOde:"<<endl;
	p1.print();
	
	cout << endl;
	
	p1.changeOwnership();
	cout <<"karo ownership change:"<<endl;
	p1.print();
	
	cout << endl;
	
	p1.change_networks();
	cout << "Now change network:"<<endl;
	p1.print();
	
	cout << endl;
	p1.update_addressss();
	cout << "Now address update which you can:"<<endl;
	p1.print();
	
	cout << endl;
	cout << "now total sim  =:"<<endl;
	p1.total_networks();
	p1.print();
	cout << endl;

	
	return 0;
}

