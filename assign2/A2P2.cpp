#include<iostream>
using namespace std;
int n;
int alphasearch(int s,int lb,int ub,int arr[]){ // lpha search
   int p;
    while(lb<ub){
        int mid=lb+((ub-lb)/4);
        int c1=arr[mid];
       if(c1==s){
        p=mid;
        break;
    }
    else if(s<c1){
       ub=mid-1;
    }
    else if(s>c1){
        lb=mid+1;
    }    
    }
    return p;
}

int betasearch(int s,int lb,int ub,int arr[]){ // beta search
    int p;
    while(lb<ub){
        int mid=lb+((2*(ub-lb))/3);
        int c1=arr[mid];
       if(c1==s){
        p=mid;
        break;
    }
    else if(s<c1){
       ub=mid-1;
    }
    else if(s>c1){
        lb=mid+1;
    }    
    }
    return p;
}
int binarysearch(int s,int lb,int ub,int arr[]){
    int p;
    while(lb<ub){
        int mid=lb+((ub-lb)/2);
        int c1=arr[mid];
       if(c1==s){
        p=mid;
        break;
    }
    else if(s<c1){
       ub=mid-1;
    }
    else if(s>c1){
        lb=mid+1;
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
   int j_b=binarysearch(s1,l,u,arr);
    cout << "binary search:the elemnt to be serched is present at index: " << j_b << endl;
   int j_alpha=alphasearch(s1,l,u,arr);
   cout << "alpha search:the elemnt to be serched is present at index: " << j_alpha << endl;
   int j_beta=betasearch(s1,l,u,arr);
    cout << "beta search:the elemnt to be serched is present at index: " << j_beta;
}