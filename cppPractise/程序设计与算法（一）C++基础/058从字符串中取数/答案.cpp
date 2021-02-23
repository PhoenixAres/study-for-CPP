#include <iostream>
#include <iomanip>
using namespace std;
double GetDoubleFromString(char * str)
{
static char *start;
    if (str) start=str;
    for (;*start && !isdigit(*start);++start);
    if (*start == 0)
        return 0;
    char *q=start;
    for (;*start && (isdigit(*start) || *start == '.');++start);
    if (*start)
    {
        *start = 0;
        ++start;
    }
    return atof(q);
}

int main()
{
	char line[300];
	while(cin.getline(line,280)) {
		double n;
		n = GetDoubleFromString(line);
		while( n > 0) {
			cout << fixed << setprecision(6) << n << endl;
			n = GetDoubleFromString(NULL);
		}
	}
	return 0;
}