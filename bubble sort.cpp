#include<iostream>
using namespace std;
class BubbleSort{
    private:
        int no_of_elements;
        int elements[10];
    public:
        void getarray();
        void sortit();
        void display();
};
void BubbleSort::getarray(){
    cout<<"How many elements?: ";
    cin>>no_of_elements;
    cout<<"Insert array of element to sort: ";
    for(int i=0;i<no_of_elements;i++){
        cin>>elements[i];
    }
}
void BubbleSort::sortit(){
    int temp;
    for(int i = 0; i < no_of_elements; i++){
        for(int j =0; j < no_of_elements - 1 - i; j++){
            if(elements[j] > elements[j+1]){
                temp = elements[j];
                elements[j] = elements[j+1];
                elements[j+1] = temp;
            }
        }
    }
}
void BubbleSort::display(){
    cout<<"The sorted element is\n";
    for(int i = 0 ; i < no_of_elements; i++){
        cout<<elements[i]<<" ";
    }
}
int main(){
    BubbleSort BS;
    BS.getarray();
    BS.sortit();
    BS.display();
    return 0;
}
