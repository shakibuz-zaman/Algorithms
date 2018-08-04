#include<bits/stdc++.h>
using namespace std;
int lps(string str){
    int len = str.length();
    int mat[len+2][len+2];
    memset(mat,0,sizeof(mat));
    for(int i=0;i<len;i++)
        mat[i][i]=1;
    for(int j=1;j<len;j++){
        for(int i=0;i<len;i++){
            mat[i][i+j]=(str[i]==str[i+j])?2+mat[i+1][i+j-1]:max(mat[i+1][i+j],mat[i][i+j-1]);
        }
    }
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++)
            cout<<mat[i][j]<<"  ";
        cout<<endl<<endl;
    }
    string ps="";
    int i=0,j=len-1;
    bool un=false;
    while(1){
        //cout<<i<<" "<<j<<endl;
        if(i>j){
            un=true;
            break;
        }
        else if(i==j){
            ps+=str[i];

            //cout<<str[i]<<" ";
            break;
        }
        else{
            if(str[i]==str[j]){
                ps+=str[i];
                //cout<<str[i]<<" ";
                i++;
                j--;
            }
            else if(mat[i][j]==mat[i][j-1]) j--;
            else i++;
        }

    }
    int l=un?ps.length():ps.length()-1;
    for(int i=l-1;i>=0;i--)ps+=ps[i];
    cout<<ps<<endl;
}
int main(){
    string str="abdudba";
    lps(str);
}
