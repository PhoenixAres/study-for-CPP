#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
char name[30];
    int age;
    int id;
    int ave[5];
public:
    void input()
    {
        int k = 0;
        char ch = getchar();
        while (ch != ',')
        {
            name[k++] = ch;
            ch = getchar();
        }
        name[k++] = '\0';
        scanf("%d,%d", &age, &id);
        for (int i = 0; i < 4; ++i)
            scanf(",%d", ave+i);
    }
    void calculate()
    {
        ave[4] = 0;
        for (int i = 0; i < 4; ++i)
            ave[4] += ave[i];
    }
    void output()
    {
        cout << name << "," << age << "," << id << "," << 1.0*ave[4]/4 << endl;
    }
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}