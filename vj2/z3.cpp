#include <iostream>
using namespace std;



template<typename T>
inline bool ascending(T a, T b) {
    return a < b;
}
template<typename T>
inline bool descending(T a, T b) {
    return a > b;
}
template<typename T>
void my_sort(T arr[], int n, bool (*cmp)(T, T)){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(!(cmp(arr[j],arr[j+1]))){
                T temp=arr[j];
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
    cout<<endl;

    
    double niz3[]={1.2,3.2,4.0,0.2,1.1};
    int n3=sizeof(niz3)/sizeof(niz3[0]);
    cout<<"Descending: ";
    my_sort(niz3,n3,descending);
    for(int i=0; i<n3;i++){
        cout<<niz3[i]<<" ";
    }
    cout<<endl;
    double niz4[]={1.0,2.3,2.1,2.2,4.6};
    int n4=sizeof(niz4)/sizeof(niz4[0]);
    cout<<"Ascending: ";
    my_sort(niz4,n4,ascending);
    for(int i=0; i<n4;i++){
        cout<<niz4[i]<<" ";
    }

    cout<<endl;
    
    char niz5[]={'a','z','g','b'};
    int n5=sizeof(niz5)/sizeof(niz5[0]);
    cout<<"Descending: ";
    my_sort(niz5,n5,descending);
    for(int i=0; i<n5;i++){
        cout<<niz5[i]<<" ";
    }
    cout<<endl;
    char niz6[]={'c','s','a','b'};
    int n6=sizeof(niz6)/sizeof(niz6[0]);
    cout<<"Ascending: ";
    my_sort(niz6,n6,ascending);
    for(int i=0; i<n6;i++){
        cout<<niz6[i]<<" ";
    }
    return 0;
}
