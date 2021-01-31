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
    set<Ath, Rule>::iterator i, j, k, p;
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
        i = st.lower_bound(a);
        i ++;
        if (i == st.end())
        {
            i --;
            k = -- i;
            i ++;
            if (k == st.begin()) printf("%d %d\n", i->ID, k->ID);
            else
            {
                p = -- k;
                k ++;
                while (p->grade == k->grade && p != st.begin()) -- p;
                if (p->grade != k->grade) ++ p;
                printf("%d %d\n", i->ID, p->ID);
            }
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
                {
                    if (k == st.begin()) printf("%d %d\n", i->ID, k->ID);
                    else
                    {
                        p = -- k;
                        k ++;
                        while (p->grade == k->grade && p != st.begin()) -- p;
                        if (p->grade == k->grade) printf("%d %d\n", i->ID, p->ID);
                        else
                        {
                            ++ p;
                            printf("%d %d\n", i->ID, p->ID);
                        }
                    }
                }
                else if (k->grade - i->grade == i->grade - j->grade)
                {
                    if (k->grade == i->grade && i->grade == j->grade)
                    {
                        if (k == st.begin()) printf("%d %d\n", i->ID, k->ID);
                        else
                        {
                            p = -- k;
                            k ++;
                            while (p->grade == k->grade && p != st.begin()) -- p;
                            if (p->grade == k->grade) printf("%d %d\n", i->ID, p->ID);
                            else
                            {
                                ++ p;
                                printf("%d %d\n", i->ID, p->ID);
                            }
                        }
                    }
                    else
                    {
                        if (k == st.begin())
                        {
                            if (k->ID < j->ID)
                                printf("%d %d\n", i->ID, k->ID);
                            else
                                printf("%d %d\n", i->ID, j->ID);
                        }
                        else
                        {
                            p = -- k;
                            k ++;
                            while (p->grade == k->grade && p!=st.begin()) -- p;
                            if (p->grade != k->grade) ++ p;
                            if (p->ID < j->ID)
                                printf("%d %d\n", i->ID, p->ID);
                            else
                                printf("%d %d\n", i->ID, j->ID);
                        }
                    }
                }
                else printf("%d %d\n", i->ID, j->ID);
            }
        }
    }
	return 0;
}