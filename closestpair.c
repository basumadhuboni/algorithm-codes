#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Point {
    int x, y;
}points[2000];

//sorting according to x co ordinate
void mergex(struct Point points[], int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int k = lb;
    struct Point a[ub + 1];
    while (i <= mid && j <= ub) {
     if (points[i].x <= points[j].x) {
            a[k] = points[i];
            i++;
        } else {
            a[k] = points[j];
            j++;
        }
        k++;
    }
    if (i > mid) {
        while (j <= ub) {
            a[k] = points[j];
            j++;
            k++;
        }
    } else {
        while (i <= mid) {
            a[k] = points[i];
            i++;
            k++;
        }
    }
    for (int i = lb; i<= ub; i++) {
        points[i] = a[i];
    }
}

void merge_sortx(struct Point points[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        merge_sortx(points, lb, mid);
        merge_sortx(points, mid + 1, ub);
        mergex(points, lb, mid, ub);
    }
}
   //sorting according to y co-ordinte 
void mergey(struct Point points[], int lb, int mid, int ub) { 
    int i = lb;
    int j = mid + 1;
    int k = lb;
    struct Point a[ub + 1];
    while (i <= mid && j <= ub) {
     if (points[i].y <= points[j].y) {
            a[k] = points[i];
            i++;
        } else {
            a[k] = points[j];
            j++;
        }
        k++;
    }
    if (i > mid) {
        while (j <= ub) {
            a[k] = points[j];
            j++;
            k++;
        }
    } else {
        while (i <= mid) {
            a[k] = points[i];
            i++;
            k++;
        }
    }
    for (int i = lb; i<= ub; i++) {
        points[i] = a[i];
    }
}
void merge_sorty(struct Point points[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        merge_sorty(points, lb, mid);
        merge_sorty(points, mid + 1, ub);
        mergey(points, lb, mid, ub);
    }
}
// finding distance between two points
float distance(struct Point p1, struct Point p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

// when no of points are 3 or less we find closest pair using bruteforce method that uses n2 time complexity

float bruteForce(struct Point points[], int n) {
    float min = 20000.0;
    for (int i = 0; i < n; ++i)     // comparing every point with one another
        for (int j = i + 1; j < n; ++j)
            if (distance(points[i], points[j]) < min)
                min = distance(points[i], points[j]);
    return min;
}

float stripClosest(struct Point strip[], int size, float d) {
    float min = d;
    merge_sorty(strip,0,(size-1));
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j <= 7; ++j)// this loop runs just 7 times
            if (distance(strip[i], strip[j]) < min)
                min = distance(strip[i], strip[j]);
    return min;
}
float closestpair(struct Point points[], int left, int right){ 
    if (right - left <= 3) // number of elements less than 3
        return bruteForce(points + left, right - left);
    
    int mid = (left + right) / 2; 
    struct Point midPoint = points[mid];

    float dl = closestpair(points, left, mid);
    float dr = closestpair(points, mid + 1, right);
    float d = fmin(dl, dr); //d stores minimum dist between two points among both left & right subarray
     //strip stores the elemnts whose x co-ordinates are less than d dist away from the midpoint 
    struct Point strip[right - left + 1]; 
    int j = 0;
    for (int i = left; i <= right; i++)
        if (abs(points[i].x - midPoint.x) < d)
            strip[j++] = points[i];
    //stripclosest returns the min distance between two points on the strip
    return fmin(d, stripClosest(strip, j, d));
}

int main() {
    char ch='y';
    int n=-1, i;
    while(ch=='y'){
        n = n + 1;
        printf("Enter x coordinate: ");
        scanf("%d", &points[n].x);
        printf("Enter y coordinate: ");
        scanf("%d", &points[n].y);
        printf("Do you want to enter more points? (y/n): ");
        scanf(" %c", &ch);
    }
    merge_sortx(points,0,n); // we first sort the array based on x co-ordinates
    float minDistance=closestpair(points, 0, n);
     printf("The minimum distance between two points is %.6f\n", minDistance);
      return 0;
}