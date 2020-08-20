#include <iostream>
using namespace std;
class vectors{
    int *head;
    int capacity;
    int e_count;
public:
    vectors(){
        head = new int[2];
        capacity = 2;
        e_count = 0;
    }
    void insert_element(int data);
    void delete_element();
    void get_element(int index);
    void print();
};
void vectors::insert_element(int data){
    if(e_count == capacity){
        int *temp = new int[(e_count/2)*2];
        for(int i=0;i<capacity;i++){
            temp[i] = head[i];
        }
        delete[] head;
        capacity *= 2;
        head = temp;
    }
    head[e_count]=data;
    e_count++;
}
void vectors::delete_element(){
    e_count--;
}
void vectors::get_element(int index){
    if(index<capacity){
        cout<<"Element at index "<<index<<" : "<< head[index]<<'\n';
    }
}
void vectors::print(){
    cout<<capacity<<'\n'<<e_count<<'\n'<<head<<'\n';
}
int main()
{
    vectors v;
    int val;
    int stop;
    while(1)
    {
        cout<<"Enter the value to be inserted : ";
        cin>>val;
        v.insert_element(val);
        cout<<"Enter 0 to stop entering values to the array : ";
        cin>>stop;
        if(stop==0)
        {
            break;
        }
    }

    int index;
    cout<<"Enter the index to view the value at that position : ";
    cin>>index;
    v.get_element(index);

    v.delete_element();
}
