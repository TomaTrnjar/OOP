#include <iostream>
using namespace std;


inline bool ascending(int a, int b) {
    return a < b;
}

inline bool descending(int a, int b) {
    return a > b;
}

void my_sort(int arr[], int n, bool (*cmp)(int, int)){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(!(cmp(arr[j],arr[j+1]))){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main() {
    int niz1[] = {1,4,2,3,8};
    int n1=sizeof(niz1)/sizeof(niz1[0]);
    cout<<"Ascending: ";
    my_sort(niz1,n1,ascending);
    for(int i=0; i<n1;i++){
        cout<<niz1[i]<<" ";
    }
    cout<<endl;
    int niz2[]={5,32,12,0,4,6};
    int n2=sizeof(niz2)/sizeof(niz2[0]);
    cout<<"Descending: ";
    my_sort(niz2,n2,descending);
    for(int i=0; i<n2;i++){
        cout<<niz2[i]<<" ";
    }
    

    
    return 0;
}
