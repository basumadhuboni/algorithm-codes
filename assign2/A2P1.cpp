#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,max,min,i;
   cout << "enter max number of elements in the array";
   cin >> n;
   int arr[n];
   cout << "enter the earray elements" << endl;
   for(i=0;i<n;i++){
    cin >> arr[i];
   }
   std :: sort(arr,arr+n);
   for(i=0;i<n;i++){
    cout << arr[i] << " ";
   }
   if(arr[0]>arr[1]){//descending 
       min=arr[n-1];
       max=arr[0];
   }
   else{//ascending
     min=arr[0];
     max=arr[n-1];
   }
   cout << "max is" << max;
   cout << "min is " << min;
}