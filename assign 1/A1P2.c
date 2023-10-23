#include<stdio.h>
#include<math.h>
int ceilvalue(double x){
    int result=(int )x;
    if(x>result){ //x is positive decimal number
        result=x+1;
    }
    return result;
}
int AvlMaxHeight(int nodes){
     int prev1 = 0, prev2 = 1, current = 1;
    int height = 0;
    while (current < nodes) {
        current = prev1 + prev2 + 1;
        prev1 = prev2;
        prev2 = current;
        height++;
    }

    return height;
}
int AvlMinHeight(int nodes){
    double height= log((nodes+1)*1.0)/(log (2.0))-1;
    return ceilvalue(height);
}

int main(){
    int nodes;
    printf("enter number of nodes in avl tree\n");
    scanf("%d",&nodes);
    int maxheight=AvlMaxHeight(nodes);
    printf("max height of avl tree with %d nodes is %d \n ",nodes,maxheight);
    int minheight=AvlMinHeight(nodes);
    printf("min height of avl tree with %d nodes is %d ",nodes,minheight);

}