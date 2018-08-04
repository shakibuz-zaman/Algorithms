#include<bits/stdc++.h>
using namespace std;

template < typename T > std::string to_string( const T& n ){
    ostringstream stm ;
    stm << n ;
    return stm.str() ;
}
string addition(string num1,string num2){
    int l1=num1.length(),l2=num2.length();
    int len=max(l1,l2);
    int c=0;
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());
    string res="";
    for(int i=0;i<len;i++){
        int x,y,z,r;
        x=(i<l1)?( (int)(num1[i]-'0') ):0;
        y=(i<l2)?( (int)(num2[i]-'0') ):0;
        //cout<<x<<" "<<y<<endl;
        if(i<l1&&i<l2){
            z=x+y+c;
            r=z%10;c=z/10;
            res=res+(char)(r+'0');
        }
        else if(i>=num1.length()){
            z=y+c;
            r=z%10;c=z/10;
            res=res+(char)(r+'0');
        }
        else if(i>=num2.length()){
            z=x+c;
            r=z%10;c=z/10;
            res=res+(char)(r+'0');
        }
    }
    if(c)res=res+(char)(c+'0');
    reverse(res.begin(),res.end());
    return res;
}
bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
       return true;
    if (n2 < n1)
       return false;

    for (int i=0; i<n1; i++)
       if (str1[i] < str2[i])
          return true;
       else if (str1[i] > str2[i])
          return false;

    return false;
}

// Function for find difference of larger numbers
string findDiff(string str1, string str2)
{
    // Before proceeding further, make sure str1
    // is not smaller
    if (isSmaller(str1, str2))
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();

    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;

    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i=0; i<n2; i++)
    {
        // Do school mathematics, compute difference of
        // current digits
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry);

        // If subtraction is less then zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // subtract remaining digits of larger number
    for (int i=n2; i<n1; i++)
    {
        int sub = ((str1[i]-'0') - carry);
        carry = 0;
        str.push_back(sub + '0');
    }

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}
//--------------End of subtraction---------------------

string division(string number, int divisor)
{
    // As result can be very large store it in string
    string ans;

    // Find prefix of number that is larger
    // than divisor.
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
       temp = temp * 10 + (number[++idx] - '0');

    // Repeatedly divide divisor with temp. After
    // every division, update temp to include one
    // more digit.
    while (number.size() > idx)
    {
        // Store result in answer i.e. temp / divisor
        ans += (temp / divisor) + '0';

        // Take next digit of number
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }

    // If divisor is greater than number
    if (ans.length() == 0)
        return "0";

    // else return ans
    return ans;
}
//-----
bool divwrem(string number, int divisor)
{
    string ans;

    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
       temp = temp * 10 + (number[++idx] - '0');

    while (number.size() > idx)
    {
        // Store result in answer i.e. temp / divisor
        ans += (temp / divisor) + '0';
        if(idx==number.size()-1)break;
        // Take next digit of number
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
    if(temp>=divisor)temp=temp%divisor;

    if (ans.length() == 0)
        ans="0",temp=atoi(number.c_str());
    cout<<endl<<ans<<"  "<<temp<<endl; /// ans=qutiont temp=reminder
    return temp==0?true:false;
}

//vector<int> result;
string multiply(string num1, string num2)
{
    int n1 = num1.size();
    int n2 = num2.size();
    if (n1 == 0 || n2 == 0)
       return "0";

    // will keep the result number in vector
    // in reverse order
    //result.clear();
    vector<int>result(n1 + n2, 0);

    // Below two indexes are used to find positions
    // in result.
    int i_n1 = 0;
    int i_n2 = 0;

    // Go from right to left in num1
    for (int i=n1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0;

        // Go from right to left in num2
        for (int j=n2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';

            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position.
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;

            // Carry for next iteration
            carry = sum/10;

            // Store result
            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }

    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
       i--;

    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
       return "0";

    // generate the result string
    string s = "";
    while (i >= 0)
        s += to_string(result[i--]);

    return s;
}

string fact[302];
void c_fact(){
    fact[0]=fact[1]="1";
    for(int i=1;i<=301;i++){
        string n=to_string(i);
        fact[i]=multiply(fact[i-1],n);
    }
}
int main(){
    cout<<addition("12","12")<<endl;
    cout<<division("144",12)<<endl;
    cout<<findDiff("20","12")<<endl;
    cout<<multiply("12","12");
    return 0;
}
