#include<bits/stdc++.h>
using namespace std;
int getMaxArea(int hist[], int n){
    stack<int> s;

    int max_area = 0; /// Initalize max area
    int tp;  /// To store top of stack
    int area_with_top; /// To store area with top bar as the smallest bar

    int i = 0;
    while (i < n){
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
        else
        {
            tp = s.top();  /// store the top index
            s.pop();  ///pop the top
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

            /// update max area, if needed
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
    while (s.empty() == false){
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }

    return max_area;
}
int main(){
    //int hist[11]={0,2,1,2,3,1};
    //int hist[]={0,3,2,4,6,4,4,6,1,6,6,6,6,3};
    //int hist[11]={0,6,2,5,4,5,1,6};
    int hist[44]={0,2,4,6,8,8};
    cout<<getMaxArea(hist,6);
}
