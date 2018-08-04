#include<bits/stdc++.h>
#define pb push_back
#define lli long long int
#define f first
#define s second
using namespace std;
int step;
int LCP[50005];
int P[30][50001];

void print2d(int n){
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<P[i][j]<<" ";
        cout<<endl;
    }
}
struct dd{
    char ch;
    int pos;
    bool operator < (const dd &d)const{
        return ch>d.ch;
    }
};
struct node{
    int pos,f,s;
}frmt[50005];

int cmp(const struct node &a, const struct node &b)
{
    return a.f == b.f ? (a.s < b.s ? 1 : 0) : (a.f < b.f ? 1 : 0);
}

int comp2(const int& a, const int& b)
{
	return P[step-1][a] < P[step-1][b];
}

vector<int> inisort(string str){
    dd f[50001];
    int len=str.length(),in=0;
    vector<char> stc[130];
    for(int i=0;i<len;i++){
        stc[ (int)(str[i]-'a') ].pb(str[i]);
    }
    string s="";
    for(int i=0;i<27;i++){
        for(int j=0;j<stc[i].size();j++)s=s+stc[i][j];
    }
    vector<int> irnk;
    irnk.pb(0);
    for(int i=1;i<len;i++){
        if(s[i]==s[i-1]){
            irnk.pb(in);
        }
        else in++,irnk.pb(in);
    }

    map<char,int> mp;
    for(int i=0;i<len;i++){
        mp[ s[i] ]=irnk[i];
    }
    for(int i=0;i<len;i++){
        irnk[i]=mp[ str[i] ];
    }

    return irnk;

}
node srt[50001];
vector<int> rad1[50001];
vector<int> rad[50001];
int rnnk[50005];
vector<int>trank(50005);
vector<int> radix(int len){
    //cout<<"Radix\n";
    int ind=0;

    for(int i=len-1;frmt[i].s<0;i--)rnnk[ind++]=i;
    for(int i=0;frmt[i].s>=0;i++)rnnk[ind++]=i;
    //cout<<"PAss1\n";
    //---------for b in-----------(a,b)

    for(int i=0;i<len;i++){
        if(!rad[i].empty()) rad[i].clear();
        if(!rad1[i].empty()) rad1[i].clear();
    }
    for(int i=0;i<len;i++){
        //cout<<"PAss1\n";
        if(frmt[ rnnk[i] ].s<0)rad[0].pb( rnnk[i] );
        else rad[ frmt[ rnnk[i] ].s ].pb( rnnk[i] );
    }
    //cout<<"PAss1\n";
    int id=0;
    for(int i=0;i<len;i++)
        for(int j=0;j<rad[i].size();j++)rnnk[id++]=rad[i][j];
    //cout<<"PAss1\n";
    //------------for a in----------(a,b)-----------

    for(int i=0;i<len;i++){
        rad1[ frmt[ rnnk[i] ].f ].pb( rnnk[i] );
    }
    id=0;
    for(int i=0;i<len;i++)
        for(int j=0;j<rad1[i].size();j++)rnnk[id++]=rad1[i][j];
    //-----------------
    //cout<<"PAss\n";
    for(int i=0;i<len;i++){
        srt[i]=frmt[ rnnk[i] ];
    }

    int in=0;
    frmt[ rnnk[0] ].pos=0;

    for(int i=1;i<len;i++){
        if( (srt[i].f==srt[i-1].f) &&(srt[i].s==srt[i-1].s) ){
            frmt[ rnnk[i] ].pos=in;
            continue;
        }
        else in++,frmt[ rnnk[i] ].pos=in;

    }

    for(int i=0;i<len;i++)trank[i]=frmt[i].pos;
    return trank;
}


vector<int> suffix(string str){
    int len=str.length(),i,count;
    //for(i=0;i<len;i++)P[0][i]=irnk[i];
    for (i = 0; i < len; i ++)
        P[0][i] = str[i] - 'a';
    vector<int> irn;
    bool loop=true;
    for(step=1;loop;step++){
    //for (step = 1, count = 1; count>>1 < len; step++, count <<= 1){
        if( (1<<step)>=len ) loop=false;
        bool flag=true;
        for(int j=0;j<len;j++){

            int half=(1<<step)/2;
            int sec=j+half;
            frmt[j].f=P[step-1][j],frmt[j].pos=j;

            if( sec>len-1  ){
                frmt[j].s=-1;
                flag=false;
                continue;
            }
            else frmt[j].s=P[step-1][ sec ];
        }
        vector<int> irn=radix(len);
        irn=radix(len);
        for(int j=0;j<len;j++)P[step][j]=irn[j];
    }
    vector<int>B(len,0);
    for(int j=0;j<len;j++){
        B[ P[step-1][j] ]=j;
    }
    return B;
}

vector<int> kasai(vector<int> sa,string s)
{
    int n=s.size(),k=0;
    vector<int> lcp(n+1,0);
    vector<int> rank(n+1,0);

    for(int i=0; i<n; i++) rank[sa[i]]=i;

    for(int i=0; i<n; i++, k?k--:0)
    {
        if(rank[i]==n-1) {k=0; continue;}
        int j=sa[rank[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[rank[i]]=k;
    }
    return lcp;
}
int Z[100002];
void setZ(string s){
    Z[0]=0;
    int left=0,right=0,i,j,k,len=s.length();
    for(i=0;i<len;i++){
        if(i>right){
            left=right=i;
            while(right<len&&s[right]==s[right-left]){right++;}
            Z[i]=right-left;
            right--;
        }
        else{
            int k=i-left;
            if(Z[k]<right-i+1)
                Z[i]=Z[k];
            else{
                left=i;
                while(right<len&&s[right]==s[right-left]){right++;}
                Z[i]=right-left;
                right--;
            }
        }
    }
}

int res(string st, string str){
    int len=st.length(),q[50001],len2=str.length();
    if(len2>len)return (len*(len+1))/2;
    string fst=""+str+'$'+st;

    setZ(fst);
    vector<int> sa=suffix(st);
    vector<int> lcp=kasai(sa,st);
    int pos=len;
    for(int i=len-1;i>=0;i--){
        if(Z[i+str.length()+1]==str.length()){
            pos=i;
        }
        q[i]=pos;

    }

    int sum=0;
    for(int i=0;i<len;i++){
        int f=sa[i] + lcp[i],last=(q[ sa[i] ]==len)?len-1:q[ sa[i] ] + len2 - 2;
        int no=last-f+1;
        if(no>0){
            sum+=no;
        }
    }
    return sum;
}

int main(){
    int t;
    scanf("%d",&t);
    char cs[50001],css[50001];

    for(int i=1;i<=t;i++){
        scanf("%s %s",cs,css);
        string st(cs),str(css);

        int r=res(st,str);
        printf("Case %d: %d\n",i,r);

    }
    return 0;
}


