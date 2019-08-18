#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#define MAX 10000 // for strings

using namespace std;
class BigInteger {
private:
    string _number;
    bool _sign;
public:
    BigInteger(); // empty constructor initializes zero
    BigInteger(string s); // "string" constructor
    BigInteger(string s, bool sin); // "string" constructor
    BigInteger(int n); // "int" constructor
    void setNumber(string s);
    void setSignedNumber(string value,char sign);
    const string& getNumber(); // retrieves the _number
    string getSignedNumber();
    void setSign(bool s);
    const bool& getSign();
    BigInteger absolute(); // returns the absolute value
    void operator = (BigInteger b);
    bool operator == (BigInteger b);
    bool operator != (BigInteger b);
    bool operator > (BigInteger b);
    bool operator < (BigInteger b);
    bool operator >= (BigInteger b);
    bool operator <= (BigInteger b);
    BigInteger& operator ++(); // prefix
    BigInteger  operator ++(int); // postfix
    BigInteger& operator --(); // prefix
    BigInteger  operator --(int); // postfix
    BigInteger operator + (BigInteger b);
    BigInteger operator - (BigInteger b);
    BigInteger operator * (BigInteger b);
    BigInteger operator / (BigInteger b);
    BigInteger operator % (BigInteger b);
    BigInteger& operator += (BigInteger b);
    BigInteger& operator -= (BigInteger b);
    BigInteger& operator *= (BigInteger b);
    BigInteger& operator /= (BigInteger b);
    BigInteger& operator %= (BigInteger b);
    BigInteger& operator [] (int n);
    BigInteger operator -(); // unary minus _sign
    operator string(); // for conversion from BigInteger to string
private:
    bool equals(BigInteger n1, BigInteger n2);
    bool less(BigInteger n1, BigInteger n2);
    bool greater(BigInteger n1, BigInteger n2);
    string add(string _number1, string _number2);
    string subtract(string _number1, string _number2);
    string multiply(string n1, string n2);
    pair<string, long long> divide(string n, long long den);
    string toString(long long n);
    long long toInt(string s);
};

int main(){
    BigInteger x(-5000), y(4000);
    BigInteger z = x+y;
    cout<<z.getSignedNumber()<<endl;
}

//------------------------------------------------------------------------------

BigInteger::BigInteger() { // empty constructor initializes zero
    _number = "0";
    _sign = false;
}

BigInteger::BigInteger(string s) { // "string" constructor
    if( isdigit(s[0]) ) { // if not _signed
        setNumber(s);
        _sign = false; // +ve
    } else {
        setNumber( s.substr(1) );
        _sign = (s[0] == '-');
    }
}

BigInteger::BigInteger(string s, bool sin) { // "string" constructor
    setNumber( s );
    setSign( sin );
}

BigInteger::BigInteger(int n) { // "int" constructor
    stringstream ss;
    string s;
    ss << n;
    ss >> s;


    if( isdigit(s[0]) ) { // if not _signed
        setNumber( s );
        setSign( false ); // +ve
    } else {
        setNumber( s.substr(1) );
        setSign( s[0] == '-' );
    }
}

void BigInteger::setNumber(string s) {
    _number = s;
}
void BigInteger::setSignedNumber(string value, char sign) {
    _number = value;
    _sign = (sign=='+')?false:true;
}
const string& BigInteger::getNumber() { // retrieves the _number
    return _number;
}
string BigInteger:: getSignedNumber(){
    string num="";
    if(_sign)num+="-";
    num+=_number;
    return num;
}
void BigInteger::setSign(bool s) {
    _sign = s;
}

const bool& BigInteger::getSign() {
    return _sign;
}

BigInteger BigInteger::absolute() {
    return BigInteger( getNumber() ); // +ve by default
}

void BigInteger::operator = (BigInteger b) {
    setNumber( b.getNumber() );
    setSign( b.getSign() );
}

bool BigInteger::operator == (BigInteger b) {
    return equals((*this) , b);
}

bool BigInteger::operator != (BigInteger b) {
    return ! equals((*this) , b);
}

bool BigInteger::operator > (BigInteger b) {
    return greater((*this) , b);
}

bool BigInteger::operator < (BigInteger b) {
    return less((*this) , b);
}

bool BigInteger::operator >= (BigInteger b) {
    return equals((*this) , b)
           || greater((*this), b);
}

bool BigInteger::operator <= (BigInteger b) {
    return equals((*this) , b)
           || less((*this) , b);
}

BigInteger& BigInteger::operator ++() { // prefix
    (*this) = (*this) + 1;
    return (*this);
}

BigInteger BigInteger::operator ++(int) { // postfix
    BigInteger before = (*this);

    (*this) = (*this) + 1;

    return before;
}

BigInteger& BigInteger::operator --() { // prefix
    (*this) = (*this) - 1;
    return (*this);

}

BigInteger BigInteger::operator --(int) { // postfix
    BigInteger before = (*this);

    (*this) = (*this) - 1;

    return before;
}

BigInteger BigInteger::operator + (BigInteger b) {
    BigInteger addition;
    if( getSign() == b.getSign() ) { // both +ve or -ve
        addition.setNumber( add(getNumber(), b.getNumber() ) );
        addition.setSign( getSign() );
    } else { // _sign different
        if( absolute() > b.absolute() ) {
            addition.setNumber( subtract(getNumber(), b.getNumber() ) );
            addition.setSign( getSign() );
        } else {
            addition.setNumber( subtract(b.getNumber(), getNumber() ) );
            addition.setSign( b.getSign() );
        }
    }
    if(addition.getNumber() == "0") // avoid (-0) problem
        addition.setSign(false);

    return addition;
}

BigInteger BigInteger::operator - (BigInteger b) {
    b.setSign( ! b.getSign() ); // x - y = x + (-y)
    return (*this) + b;
}

BigInteger BigInteger::operator * (BigInteger b) {
    BigInteger mul;

    mul.setNumber( multiply(getNumber(), b.getNumber() ) );
    mul.setSign( getSign() != b.getSign() );

    if(mul.getNumber() == "0") // avoid (-0) problem
        mul.setSign(false);

    return mul;
}

// Warning: Denomerator must be within "long long" size not "BigInteger"
BigInteger BigInteger::operator / (BigInteger b) {
    long long den = toInt( b.getNumber() );
    BigInteger div;

    div.setNumber( divide(getNumber(), den).first );
    div.setSign( getSign() != b.getSign() );

    if(div.getNumber() == "0") // avoid (-0) problem
        div.setSign(false);

    return div;
}

// Warning: Denomerator must be within "long long" size not "BigInteger"
BigInteger BigInteger::operator % (BigInteger b) {
    long long den = toInt( b.getNumber() );

    BigInteger rem;
    long long rem_int = divide(_number, den).second;
    rem.setNumber( toString(rem_int) );
    rem.setSign( getSign() != b.getSign() );

    if(rem.getNumber() == "0") // avoid (-0) problem
        rem.setSign(false);

    return rem;
}

BigInteger& BigInteger::operator += (BigInteger b) {
    (*this) = (*this) + b;
    return (*this);
}

BigInteger& BigInteger::operator -= (BigInteger b) {
    (*this) = (*this) - b;
    return (*this);
}

BigInteger& BigInteger::operator *= (BigInteger b) {
    (*this) = (*this) * b;
    return (*this);
}

BigInteger& BigInteger::operator /= (BigInteger b) {
    (*this) = (*this) / b;
    return (*this);
}

BigInteger& BigInteger::operator %= (BigInteger b) {
    (*this) = (*this) % b;
    return (*this);
}

BigInteger& BigInteger::operator [] (int n) {
    return *(this + (n*sizeof(BigInteger)));
}

BigInteger BigInteger::operator -() { // unary minus _sign
    return (*this) * -1;
}

BigInteger::operator string() { // for conversion from BigInteger to string
    string _signedString = ( getSign() ) ? "-" : ""; // if +ve, don't print + _sign
    _signedString += _number;
    return _signedString;
}

bool BigInteger::equals(BigInteger n1, BigInteger n2) {
    return n1.getNumber() == n2.getNumber()
           && n1.getSign() == n2.getSign();
}

bool BigInteger::less(BigInteger n1, BigInteger n2) {
    bool _sign1 = n1.getSign();
    bool _sign2 = n2.getSign();

    if(_sign1 && ! _sign2) // if n1 is -ve and n2 is +ve
        return true;

    else if(! _sign1 && _sign2)
        return false;

    else if(! _sign1) { // both +ve
        if(n1.getNumber().length() < n2.getNumber().length() )
            return true;
        if(n1.getNumber().length() > n2.getNumber().length() )
            return false;
        return n1.getNumber() < n2.getNumber();
    } else { // both -ve
        if(n1.getNumber().length() > n2.getNumber().length())
            return true;
        if(n1.getNumber().length() < n2.getNumber().length())
            return false;
        return n1.getNumber().compare( n2.getNumber() ) > 0; // greater with -ve _sign is LESS
    }
}

bool BigInteger::greater(BigInteger n1, BigInteger n2) {
    return ! equals(n1, n2) && ! less(n1, n2);
}

string BigInteger::add(string _number1, string _number2) {
    string add = (_number1.length() > _number2.length()) ?  _number1 : _number2;
    char carry = '0';
    int differenceInLength = abs( (int) (_number1.size() - _number2.size()) );

    if(_number1.size() > _number2.size())
        _number2.insert(0, differenceInLength, '0'); // put zeros from left

    else// if(_number1.size() < _number2.size())
        _number1.insert(0, differenceInLength, '0');

    for(int i=_number1.size()-1; i>=0; --i) {
        add[i] = ((carry-'0')+(_number1[i]-'0')+(_number2[i]-'0')) + '0';

        if(i != 0) {
            if(add[i] > '9') {
                add[i] -= 10;
                carry = '1';
            } else
                carry = '0';
        }
    }
    if(add[0] > '9') {
        add[0]-= 10;
        add.insert(0,1,'1');
    }
    return add;
}

string BigInteger::subtract(string _number1, string _number2) {
    string sub = (_number1.length()>_number2.length())? _number1 : _number2;
    int differenceInLength = abs( (int)(_number1.size() - _number2.size()) );

    if(_number1.size() > _number2.size())
        _number2.insert(0, differenceInLength, '0');

    else
        _number1.insert(0, differenceInLength, '0');

    for(int i=_number1.length()-1; i>=0; --i) {
        if(_number1[i] < _number2[i]) {
            _number1[i] += 10;
            _number1[i-1]--;
        }
        sub[i] = ((_number1[i]-'0')-(_number2[i]-'0')) + '0';
    }

    while(sub[0]=='0' && sub.length()!=1) // erase leading zeros
        sub.erase(0,1);

    return sub;
}

string BigInteger::multiply(string n1, string n2) {
    if(n1.length() > n2.length())
        n1.swap(n2);

    string res = "0";
    for(int i=n1.length()-1; i>=0; --i) {
        string temp = n2;
        int currentDigit = n1[i]-'0';
        int carry = 0;

        for(int j=temp.length()-1; j>=0; --j) {
            temp[j] = ((temp[j]-'0') * currentDigit) + carry;

            if(temp[j] > 9) {
                carry = (temp[j]/10);
                temp[j] -= (carry*10);
            } else
                carry = 0;

            temp[j] += '0'; // back to string mood
        }

        if(carry > 0)
            temp.insert(0, 1, (carry+'0'));

        temp.append((n1.length()-i-1), '0'); // as like mult by 10, 100, 1000, 10000 and so on

        res = add(res, temp); // O(n)
    }

    while(res[0] == '0' && res.length()!=1) // erase leading zeros
        res.erase(0,1);

    return res;
}

pair<string, long long> BigInteger::divide(string n, long long den) {
    long long rem = 0;
    string result;
    result.resize(MAX);

    for(int indx=0, len = n.length(); indx<len; ++indx) {
        rem = (rem * 10) + (n[indx] - '0');
        result[indx] = rem / den + '0';
        rem %= den;
    }
    result.resize( n.length() );

    while( result[0] == '0' && result.length() != 1)
        result.erase(0,1);

    if(result.length() == 0)
        result = "0";

    return make_pair(result, rem);
}

string BigInteger::toString(long long n) {
    stringstream ss;
    string temp;

    ss << n;
    ss >> temp;

    return temp;
}

long long BigInteger::toInt(string s) {
    long long sum = 0;

    for(int i=0; i<s.length(); i++)
        sum = (sum*10) + (s[i] - '0');

    return sum;
}

