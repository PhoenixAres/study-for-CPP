#include <bits/stdc++.h>
using namespace std;

struct Ath
{
    int ID;
    int grade;
};

struct Rule
{
    bool operator()(const Ath & a1, const Ath & a2)
    {
        if (a1.grade == a2.grade) return a1.ID < a2.ID;
        return a1.grade > a2.grade;
    }
};

int main()
{
    set<Ath, Rule> st;
    set<Ath, Rule>::iterator i, j, k;
    Ath a;
    a.ID = 1;
    a.grade = 1000000000;
    st.insert(a);
    int n;
    scanf("%d", &n);
    while (n --)
    {
        scanf("%d%d", &a.ID, &a.grade);
        st.insert(a);
        i = st.find(a);
        i ++;
        if (i == st.end())
        {
            i --;
            printf("%d ", i->ID);
            i --;
            printf("%d\n", i->ID);
        }
        else
        {
            i --;
            if (i == st.begin())
            {
                printf("%d ", i->ID);
                i ++;
                printf("%d\n", i->ID);
            }
            else
            {
                j = ++ i;
                i --;
                k = -- i;
                i ++;
                if (k->grade - i->grade < i->grade - j->grade)
                    printf("%d %d\n", i->ID, k->ID);
                else
                    printf("%d %d\n", i->ID, j->ID);
            }
        }
    }
	return 0;
}