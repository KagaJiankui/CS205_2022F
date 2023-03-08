#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20

typedef struct node
{
  int type;
  union
  {
    int    ival;
    double dval;
  } dat;
} NodeType;

typedef struct Stack
{
  NodeType data[N];
  int      top;   // 记录栈顶的位置
} Stack;          // 用来控制栈的顺序存储

int SearchPoint(char* pi)
{
  while (*pi) {
    if (*pi == '.')   // 找到小数点返回1，为浮点型
      return 1;
    pi++;
  }
  return 0;
}

void Push(Stack* stack, NodeType data)                         // 压栈函数
{
  memcpy(&stack->data[stack->top], &data, sizeof(NodeType));   // 将data中的数据拷贝到栈区存放
  stack->top = stack->top + 1;                                 // 栈顶位置+1
}

NodeType PopOut(Stack* stack)   // 出栈函数
{
  stack->top = stack->top - 1;
  return stack->data[stack->top];   // 出栈一个数据
}

double double_OP(double d1, double d2, char op)
{
  switch (op) {
  case '+': return d1 + d2;
  case '-': return d1 - d2;
  case '*': return d1 * d2;
  case '/': return d1 / d2;
  default: printf("error\n"); break;
  }
}

int int_OP(int d1, int d2, char op)
{
  switch (op) {
  case '+': return d1 + d2;
  case '-': return d1 - d2;
  case '*': return d1 * d2;
  case '/': return d1 / d2;
  default: break;
  }
}

NodeType OpData(NodeType* d1, NodeType* d2, char op)
{
  NodeType d3;
  if (d1->type == sizeof(double) || d2->type == sizeof(double))   // 判断是否含有浮点数
  {
    d3.type = sizeof(double);
    if (d1->type == sizeof(double) && d2->type == sizeof(double)) {
      d3.dat.dval = double_OP(d1->dat.dval, d2->dat.dval, op);
    }
    else if (d1->type == sizeof(double)) {
      d3.dat.dval = double_OP(d1->dat.dval, (double)d2->dat.ival, op);
    }
    else {
      d3.dat.dval = double_OP((double)d1->dat.ival, d2->dat.dval, op);
    }
  }
  else {
    d3.type     = sizeof(int);
    d3.dat.ival = int_OP(d1->dat.ival, d2->dat.ival, op);
  }
  return d3;
}

int main()
{
  NodeType d1, d2, d3, d_top;
  char     input[N] = {0};
  Stack    stack    = {0};
  while (scanf("%s", input) == 1 && input[0] != '#')   // 用#作为输入的结束标志，空格作为每个操作数/操作符的分隔符
  {
    if (isdigit(input[0]))                             // 如果输入的字符串为操作数
    {
      if (SearchPoint(input))                          // 判断是否为浮点数
      {
        d1.type     = sizeof(double);
        d1.dat.dval = strtod(input, NULL);   // 字符串转为浮点数函数，转换成功则返回浮点数，失败返回0.0
        if (d1.dat.dval == 0.0) {
          printf("转为浮点数失败\n");
        }
        Push(&stack, d1);
      }
      else   // 否则为整型操作数
      {
        d1.type     = sizeof(int);
        d1.dat.ival = atoi(input);
        Push(&stack, d1);
      }
    }
    else                     // 如果输入的字符串为操作符，则弹出两个操作数，将结果压栈
    {
      d2 = PopOut(&stack);   // ！！！ps：注意输出顺序，先输出d2，再输出d1，在操作符运算中，后输出的数d1在运算符左边进行运算
      d1 = PopOut(&stack);
      d3 = OpData(&d1, &d2, input[0]);
      Push(&stack, d3);
    }
    d_top = PopOut(&stack);   // 打印栈顶的数
    stack.top++;
    if (d_top.type == sizeof(double)) {
      printf("当前栈顶为double:%lf\n", d_top.dat.dval);
    }
    else {
      printf("当前栈顶为int:%d\n", d_top.dat.ival);
    }
  }
  d_top = PopOut(&stack);   // 打印结果
  if (d_top.type == sizeof(double)) {
    printf("结果为double:%lf\n", d_top.dat.dval);
  }
  else {
    printf("结果为int:%d\n", d_top.dat.ival);
  }
  return 0;
}
