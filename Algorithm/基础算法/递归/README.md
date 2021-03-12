# 目录

[1. 逻辑表达式求值](#1-逻辑表达式求值)

[2. 简易计算器](#2-简易计算器)

[3. 题目指南](#3-题目指南)



# 递归

## 1. 逻辑表达式求值

原题链接：[Boolean Expressions](http://poj.org/problem?id=2106)

分析：使用递归实现，逻辑表达式求值（仅包含逻辑与、逻辑或、逻辑非），仿照四则运算定义如下概念：

表达式：由若干个项的逻辑或组成

项：由若干个因子的逻辑与组成

因子：可以是 'F'(true) 或 'V'(false) ，也可以是某个因子的逻辑非，也可以是由小括号括起来的表达式

要求的是表达式的值，我们进行递归求解：

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 1000 + 10;
string p, s;
int n;

bool expression_value();
bool term_value();
bool factor_value();

// 求因子的值
bool factor_value()
{
    bool result;
    char op = s[n];
    if (op == '(') ++n, result = expression_value(), ++n;
    else if (op == '!') ++n, result = !factor_value();
    else if (op == 'F') ++n, result = false;
    else if (op == 'V') ++n, result = true;
    return result;
}

// 求项的值
bool term_value()
{
    bool result = factor_value();
    while (true)
    {
        char op = s[n];
        if (op == '&') ++n, result &= factor_value();
        else break;
    }
    return result;
}

// 将表达式的值
bool expression_value()
{
    bool result = term_value();
    while (true)
    {
        char op = s[n];
        if (op == '|') ++n, result |= term_value();
        else break;
    }
    return result;
}

int main()
{
    int cnt = 1;
    while (getline(cin, p))
    {
        s.clear();
        for (int i = 0; i < p.size(); ++i)
            if (p[i] != ' ') s += p[i];
        n = 0;
        bool f = expression_value();
        printf("Expression %d: ", cnt++);
        if (f) printf("V\n");
        else printf("F\n");
    }
    return 0;
}
```

## 2. 简易计算器

分析：使用递归实现，算术表达式求值（仅包含+ - * ()），依据四则运算有如下概念：

表达式：由若干个项的和或差组成

项：由若干个因子的积组成

因子：可以是一个十进制数，也可以是由小括号括起来的表达式

要求的是表达式的值，我们进行递归求解：

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 5e5 + 10;
string p, s;
int n;

int expression_value();
int term_value();
int factor_value();

// 求因子的值
int factor_value()
{
    int result;
    char op = s[n];
    if (op == '(') ++n, result = expression_value(), ++n;
    else if (isdigit(op))
    {
        char d[10];
        d[0] = op;
        int i = n + 1;
        while (i < s.size() && isdigit(s[i])) d[i - n] = s[i++];
        d[i - n] = '\0';
        result = atoi(d);
        n = i;
    }
    return result;
}

// 求项的值
int term_value()
{
    int result = factor_value();
    while (true)
    {
        char op = s[n];
        if (op == '*')
            ++n, result *= factor_value();
        else break;
    }
    return result;
}

// 求表达式的值
int expression_value()
{
    int result = term_value();
    while (true)
    {
        char op = s[n];
        if (op == '+')
            ++n, result += term_value();
        else if (op == '-')
            ++n, result -= term_value();
        else break;
    }
    return result;
}

int main() {
    while (getline(cin, p))
    {
        s.clear();
        for (int i = 0; i < p.size(); ++i)
            if (p[i] != ' ') s += p[i];
        n = 0;
        int result = expression_value();
        printf("result = %d\n", result);
    }
    return 0;
}
```



## 3. 题目指南 

[Boolean Expressions](#1-逻辑表达式求值)



