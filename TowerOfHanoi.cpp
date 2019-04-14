#include<iostream>
#include<stdio.h>
using namespace std;

int solvetovers(int disc, char source , char destination ,  char spare){
	if(disc == 1 ){
		cout << " move disc " << disc << " from " << source << " to " << destination << endl;
			
	}
	else{
		solvetovers(disc-1 , source  , spare , destination);
		cout << " move disc " << disc << " from " << source << " to " << destination << endl;
		solvetovers(disc-1 , spare  , destination , source);
	}
		
}

int main(){
	solvetovers(6,'A','C','B');
	return 0;
}
