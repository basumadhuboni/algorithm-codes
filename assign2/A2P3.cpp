#include<iostream>
using namespace std;
int n;
int search(int s,int lb,int ub,int arr[]){
    int p;
    while(lb<ub){
        int mid1=lb+((ub-lb)/3);
        int mid2=ub-((ub-lb)/3);
        int c1=arr[mid1];
        int c2=arr[mid2];
       if(c1==s){
        p=mid1;
        break;
    }
    else if(c2==s){
        p=mid2;
        break;
    }
    else if(s<c1){
       ub=mid1-1;
    }
    else if(s>c1 and s<c2){
        lb=mid1+1;
        ub=mid2-1;
    }
    else if(s>c2){
        lb=mid2+1;
    }    
    }
    return p;
}
int main(){
    int max,min,i,s1,u,l;
   cout << "enter max number of elements in the array";
   cin >> n;
   int arr[n];
   cout << "enter the earray elements" << endl;
   for(i=0;i<n;i++){
    cin >> arr[i];
   }
   l=0;
   u=n-1;
   cout << "ener the elemnt to be serched";
   cin >> s1;
   int j=search(s1,l,u,arr);
    cout << "the elemnt to be serched is present at index: " << j;
}