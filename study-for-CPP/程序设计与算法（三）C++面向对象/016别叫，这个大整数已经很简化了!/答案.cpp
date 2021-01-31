#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
char p[210];
public:
    void rev(char *s)
    {
        int len = strlen(s);
        for (int i = 0; i < len/2; ++i)
            swap(s[i], s[len-1-i]);
    }
    CHugeInt(int n)
    {
        memset(p, 0, sizeof(p));
        sprintf(p, "%d", n);
        rev(p);
    }
    CHugeInt(const char *s)
    {
        memset(p, 0, sizeof(p));
        strcpy(p, s);
        rev(p);
    }
    CHugeInt operator + (const CHugeInt & a)
    {
        CHugeInt t(a);
        int x = 0;
        int sum;
        for (int i = 0; i < 210; ++i)
        {
            char ch1 = t.p[i];
            char ch2 = p[i];
            if (ch1 == 0 && ch2 == 0 && x == 0)
                break;
            if (ch1 == 0)
                ch1 = '0';
            if (ch2 == 0)
                ch2 = '0';
            sum = ch1-'0' + ch2-'0' + x;
            t.p[i] = sum%10+'0';
            x = sum/10;
        }
        return t;
    }
    friend CHugeInt operator + (int n, const CHugeInt & a)
    {
        CHugeInt t(n);
        return t + a;
    }
    CHugeInt & operator += (int n)
    {
        *this = *this + n;
        return *this;
    }
    CHugeInt & operator ++ ()
    {
        *this += 1;
        return *this;
    }
    CHugeInt operator ++ (int)
    {
        CHugeInt t(*this);
        *this += 1;
        return t;
    }
    friend ostream & operator << (ostream & o, const CHugeInt & a)
    {
        int len = strlen(a.p);
        for (int i = len-1; i >= 0; --i)
            o << a.p[i];
        return o;
    }
};
int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}