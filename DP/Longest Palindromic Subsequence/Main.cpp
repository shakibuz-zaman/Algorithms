#include<bits/stdc++.h>
using namespace std;
string lps(string str){
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

    string ps="";
    for(int i=0;i<mat[0][len-1];i++)ps+='o';
    //cout<<ps<<endl;
    int i=0,j=len-1;
    bool un=false;
    while(1){
        if(i>j){
            un=true;
            break;
        }
        else{
            if(str[i]==str[j]){
                ps[i]=ps[j]=str[i];
                i++;
                j--;
            }
            else if(mat[i][j]==mat[i][j-1]) j--;
            else i++;
        }

    }
    //cout<<ps<<endl;
    return ps;
}
int main(){
    string str="abduudba";
    cout<<lps(str);
}
