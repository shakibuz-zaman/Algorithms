#include<bits/stdc++.h>
using namespace std;
int mat[33][33]={{1,0,0,1,1,1},
                 {1,0,1,1,0,1},
                 {0,1,1,1,1,1},
                 {0,0,1,1,1,1}
                };
int getPar(int hist[], int m,int n){
    stack<int> s;

    int max_area = 0; /// Initalize max area
    int tp;  /// To store top of stack
    int area_with_top; /// To store area with top bar as the smallest bar

    int i = m;
    while (i <= n){
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
        else
        {
            tp = s.top();  /// store the top index
            s.pop();  ///pop the top
            area_with_top = hist[tp] * (s.empty() ? i-m : i - s.top() - 1);

            /// update max area, if needed
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
    while (s.empty() == false){
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i-m : i - s.top() - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }

    return max_area;
}
int getMax(int a[],int n){
    int mxx=-1,i=0;
    //for(int i=0;i<n;i++)cout<<a[i]<<" ";
    //cout<<endl;
    while(i<n){
        //cout<<i<<endl;
        if(a[i]){
            int j=i;
            while(a[i]){
                if(i==n)break;
                i++;
            }
            //cout<<j<<" "<<i-1<<endl;
            mxx=max(mxx,getPar(a,j,i-1));
        }
        i++;
    }
    //cout<<endl;
    return mxx;
}
int maxarea(int m,int n){
    int hist[n+2];
    memset(hist,0,sizeof(hist));
    int maxa=-1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            //hist[j]+=mat[i][j];
            hist[j]=(mat[i][j]==1)?hist[j]+1:0;
        }
        maxa=max(maxa,getMax(hist,n));
        //cout<<getMax(hist,n)<<endl;
        //cout<<getMaxArea(hist,n)<<endl;
    }
    return maxa;
}
int main(){
    cout<<maxarea(4,6);
}
