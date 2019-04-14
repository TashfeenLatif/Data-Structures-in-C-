
//						NAME					TASHFEEN LATIF
//						ROLL NO					17P-6035
//						SECTION					CS_A
//						COURSE					DATA STRUCTURES
//								ASSIGNMENT # 4
//								20 Recursion Function:-


#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;


int power(int base , int pow){
	if(pow == 1){
		return base;
	}
	else{
		return base *power(base,pow-1);
	}
}


int factorial(int fact){
	if(fact == 1){
		return 1;
	}
	else{
		return fact* factorial(fact-1);
	}
}


int table_with_recursion(int num, int lim){
	if(lim == 0){
		return 0;
	}
	else{
		table_with_recursion(num,lim-1);
		cout << num  << " * " << lim  << " =  " << num * lim <<endl;
			if(lim == 1){
				return num * lim;
			}
	}

}


int even_series(int val , int end){
	
	cout << "even series are:"<<endl;
	if(val % 2 == 0){
		cout << val <<" " << endl;
		if(val != end)
			even_series (val+2,end);
		else
			return end;
		}
	else{
		even_series(val+1,end);
	}
}

int odd_series(int val , int end){
	cout << "odd series :"<<endl;
	if(val % 2 != 0){
		cout << val <<" " << endl;
		if(val >= end)
			return end;
		else{
			
			odd_series (val+2,end);
		}
	}
	else{
		odd_series(val+1,end);
			}
		
}

int sum_of_natural_no(int num){
	cout << "Sum of natural no:"<<endl;
	if(num == 1)
		return 1;
		return num + sum_of_natural_no(num-1);
	
}

int natural_no(int num){
	cout << "series of natural upto :"<<endl;
	if(num == 1){
		cout << num << endl;
		return 1;
		}
	else{
		
		natural_no(num-1);
		cout << num << endl;
		}
	}

int digits_count(int num){
	cout << "how many digits are:"<<endl;
	static int count  = 0;
	if(num != 0)
	{
		count++;
		digits_count(num / 10);
	}
	return count;
	
}

int digits_sum(int num){
	cout << "Digits sum:"<<endl;
	if(num != 0){
		return (num % 10) + digits_sum(num / 10);
		 
	}
	else{
		return 0;
	}

}
int gcd(int num,int num1){
    if(num != num1)
    {
        if(num > num1)
            return gcd(num-num1,num1);
        else
           return gcd(num,num1-num);
    }
    return num;
}	

int fibonacci(int num) {
   if((num == 1) || (num == 0)) {
		return num;	
	}
	else{
      return fibonacci(num - 1) + fibonacci( num - 2);
   }
}


struct tree{
	int value;
	tree *fchild;
	tree *nsib;
};
tree *root;
tree *temp = NULL;
void insertion(tree *temp){
	int num;
	
	if(root == NULL){
		temp = new tree;
		cout << "Enter value of num for root: "<<endl;
		cin  >> num;
		temp->value = num;
		temp->fchild = NULL;
		temp->nsib  = NULL;
		root = temp;
		return;
	}
	
		if(temp->fchild == NULL)
			{
				temp->fchild  = new tree;
				cout << "Enter value for fchild:"<<endl;
				cin >> num;
				temp->fchild->value = num;
				temp->fchild->fchild = NULL;
				temp->fchild->nsib = NULL;
				return;
			}
	temp = temp->fchild;
	while(temp->nsib != NULL){
		temp = temp->nsib;
	}
	temp->nsib = new tree;
	cout << "Enter value for nsib:"<<endl;
	cin >> temp->nsib->value;
	temp->nsib->fchild = NULL;
	temp->nsib->nsib = NULL;
	return;

}

void Traverse(tree *t){
	if (t->fchild != NULL)
		Traverse(t->fchild);
		
	if (t->nsib != NULL)
		Traverse(t->nsib);

	cout << t->value << " -- ";
}
void Traverse1(tree *t){
	
	if (t->fchild != NULL)
		Traverse(t->fchild);
		
	cout << t->value << " -- ";
		
	if (t->nsib != NULL)
		Traverse(t->nsib);
	
}
void Traverse2(tree *t){
	
	
	cout << t->value << " -- ";
	
	if (t->fchild != NULL)
		Traverse(t->fchild);
		
	if (t->nsib != NULL)
		Traverse(t->nsib);
	
}


int FindLcm(int a, int b){
    static int lcm = 0;
	lcm += b;

    if(lcm % a == 0 && lcm % b == 0)
    {
        return lcm;
    }
    else
    {
        FindLcm(a, b);
    }
}

void checkPalindrome(char pal[], int index){
    int len = strlen(pal) - (index + 1);
    if (pal[index] == pal[len])
    {
        if (index + 1 == len || index == len)
        {
            cout << " The entered word is a palindrome " << endl;
            return;
        }
        checkPalindrome(pal, index + 1);
    }
    else
    {
        cout << " The entered word is not a palindrome"<<endl;
    }

}

void copyString(char stng1[] , char stng2[] , int ctr){
    stng2[ctr] = stng1[ctr];
    if (stng1[ctr] == '\0')
        return;
    copyString(stng1, stng2, ctr + 1);
}


int findMaxRec(int array2[], int n) {   
    if (n == 1) 
        return array2[0]; 
    return max(array2[n-1], findMaxRec(array2, n-1)); 
} 
  
char checkCapital(char *str2){
        static int i = 0;
        if (i < strlen(str2))
        {
            if (isupper(str2[i]))
            {
                return str2[i];
            }
            else
            {
                i = i + 1;
                return checkCapital(str2);
            }
        }
        else return 0;
    }
int findMinRec(int array[], int n) {  
    if (n == 1) 
        return array[0]; 
    return min(array[n-1], findMinRec(array, n-1)); 
} 
  
 
 
int main(){
	
	cout << "First Function:"<<endl;
	cout << "Power of num is:"<< power(3,4) <<endl;
	cout <<endl;
	cout << "Second Function:"<<endl;
	cout <<"Factorial of num is: " << factorial(6) << endl ;
	cout <<endl;
	
	cout << "Third Function:"<<endl;
	int number;
	int limi;
	cout<<"Please enter Number for which you want to print table : ";
	cin>>number; 
	cout << "Enter where to go:"<<endl;
	cin >> limi;
	table_with_recursion(number, limi);
	cout <<endl;
	
	cout << "Four Function:"<<endl;
	cout << sum_of_natural_no(7);
	cout <<endl;
	
	cout << "Five Function:"<<endl;
	even_series(3,180);
	cout <<endl;
	
	cout << "Six Function:"<<endl;
	odd_series(2,184);
	cout <<endl;
	
	cout << "Seven Function:"<<endl;
	natural_no(70);
	cout <<endl;
	
	cout << "Eight Function:"<<endl;
	cout << digits_count(123456789)<<endl;
	cout <<endl;
	
	cout << "Nine Function:"<<endl;
	cout << digits_sum(25)<<endl;
	cout <<endl;
	
	cout << "Ten Function:"<<endl;
	cout << gcd(10,50) << endl;
	cout <<endl;
	
	cout << "Eleven Function:"<<endl;
	cout << "Now tree with third recursion functon:"<<endl;
	for(int i = 0; i < 10; i++){
		insertion(root);
		
		Traverse2(root);
		cout << " " << endl;
	}
	cout <<endl;
	
	cout << "Twelve Function:"<<endl;
	int num; 
	cout << "Enter the number that how many terms of series : " <<endl;
	cin >> num;
	cout << "Fibonnaci Series of num is : "<<endl;;
   	for(int i = 0; i < num; i++)
	   {
   			cout << " " << fibonacci(i)<<endl;
	   }
	cout <<endl;	   
	
	cout << "Thirteen Function:"<<endl;
	
	int num1, num2, lcm;
	cout << "Enter first number for lcm:"<<endl;
	cin  >> num1;
	cout << "Enter second number from lcm:"<<endl;
	cin  >> num2;
	if(num1 >  num2)
        lcm = FindLcm(num2, num1);
    else
        lcm = FindLcm(num1, num2);
	cout << num1 <<"   " <<  num2  <<endl;
	cout << lcm << endl;
 	cout <<endl;

    cout << "Fourteen Function:"<<endl;
	int array1[] = {1, 4, 1050, 6, -50, 10, 2}; 
    int val1 = sizeof(array1[0]); 
    cout << "Maximum element from  array is:"<<endl;
    cout <<  findMaxRec(array1, val1)<<endl; 
    cout <<endl;
		 
    cout << "Fifteen Function:"<<endl;	 
	int array2[] = {1, 4, 45, 6, -50, 10, 2}; 
	cout << "Minimum element from array is:"<<endl;
    int val2 = sizeof(array2) / sizeof(array2[0]); 
    cout <<  findMinRec(array2, val2)<<endl; 
    cout <<endl;
				
    cout << "Sixteen Function:"<<endl;
	char pall[25];
    cout << " Enter a word to check for palindrome : " << endl;
    cin >>  pall;
    checkPalindrome(pall, 0);
	cout <<endl;
 	cout <<endl;
 	
	cout << "Seventeen Function:"<<endl;	
	char str1[20], letter;
    cout << "Enter string  plz with some captal letters:"<<endl;
    cin >> str1;
	letter = checkCapital(str1);
    if (letter == 0)
        cout <<" There is no capital letter in the string :"<< str1;
    else
		cout <<" The first capital letter in the string is:"<< letter<< endl;   	 

	cout <<endl;

    cout << "Eighteen Function:"<<endl;  
    
	char stng1[20], stng2[20];
    cout << "Enter string who you want to copy in other:"<<endl;
	cin >> stng1;
    copyString(stng1, stng2, 0);
    cout << " The first string is : "<< stng1 << endl; ;
    cout << " now copied in second is : "<< stng2 << endl;
    cout <<endl;
    
    cout << "Nineteen Function:"<<endl;
	cout << "Now tree with first recursion functon:"<<endl;
	for(int i = 0; i < 10; i++){
		insertion(root);
		Traverse(root);
		cout << " " << endl;
	}

	cout << endl;
	
	cout << "Twenty Function:"<<endl;
	cout << "Now tree with second recursion functon:"<<endl;
	for(int i = 0; i < 10; i++){
		insertion(root);
		Traverse1(root);
		cout << " " << endl;
	}
	cout << endl;

	
	return 0;

}
