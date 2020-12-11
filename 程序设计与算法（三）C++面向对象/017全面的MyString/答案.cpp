#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s) 
{	int i = 0;
	for(; s[i]; ++i);
	return i;
}
void strcpy(char * d,const char * s)
{
	int i = 0;
	for( i = 0; s[i]; ++i)
		d[i] = s[i];
	d[i] = 0;
		
}
int strcmp(const char * s1,const char * s2)
{
	for(int i = 0; s1[i] && s2[i] ; ++i) {
		if( s1[i] < s2[i] )
			return -1;
		else if( s1[i] > s2[i])
			return 1;
	}
	return 0;
}
void strcat(char * d,const char * s)
{
	int len = strlen(d);
	strcpy(d+len,s);
}
class MyString
{
char *s;
public:
    MyString(){s=NULL;}
    MyString(const char *p)
    {
        if (p)
        {
            int len = strlen(p);
            s = new char[len+1];
            strcpy(s, p);
        }
        else s = NULL;
    }
    ~MyString()
    {
        if (s) delete [] s;
    }
    MyString(const MyString & a)
    {
        if (a.s)
        {
            int len = strlen(a.s);
            s = new char[len+1];
            strcpy(s, a.s);
        }
        else s = NULL;
    }
    MyString & operator = (const MyString & a)
    {
        if (s) delete [] s;
        if (a.s)
        {
            int len = strlen(a.s);
            s = new char[len+1];
            strcpy(s, a.s);
        }
        else s = NULL;
        return *this;
    }
    MyString operator + (const MyString & a)
    {
        MyString t;
        int len = strlen(s) + strlen(a.s);
        t.s = new char[len+1];
        strcpy(t.s, s);
        strcat(t.s, a.s);
        return t;
    }
    friend ostream & operator << (ostream & o, const MyString & a)
    {
        if (a.s) o << a.s;
        return o;
    }
    char & operator [] (int i)
    {
        return *(s+i);
    }
    friend MyString operator + (const char *p, const MyString & a)
    {
        MyString t(p);
        return t + a;
    }
    MyString & operator += (const char *a)
    {
        *this = *this + a;
        return *this;
    }
    bool operator < (const MyString & a)
    {
        if (strcmp(s, a.s) < 0)
            return true;
        return false;
    }
    bool operator == (const MyString & a)
    {
        if (strcmp(s, a.s) == 0)
            return true;
        return false;
    }
    bool operator > (const MyString & a)
    {
        if (strcmp(s, a.s) > 0)
            return true;
        return false;
    }
    MyString operator () (int i, int j)
    {
        MyString t;
        t.s = new char[j+1];
        char ch = s[i+j];
        s[i+j] = '\0';
        strcpy(t.s, s+i);
        s[i+j] = ch;
        return t;
    }
};


int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
	return -1;
	else if( *s1 == *s2)
	return 0;
	else if( *s1 > *s2 )
	return 1;
}
int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}