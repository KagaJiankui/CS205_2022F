#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define MARK 65535

/**
 * RPN Calculator created by [完整的逆波兰表达式计算](https://blog.csdn.net/wyzworld/article/details/83151891). This RPN calculator implements nested
expression and limited special function evaluation.
 *
 */

typedef struct
{
  char data[MAX];
  int  top;
} SqStack;

typedef struct
{
  int  prior[MAX];
  char opera[MAX];
  int  top;
} Mark;

typedef struct
{
  double data[MAX];
  char   opera[MAX];
  int    top;
  int    otop;
} RPN;

SqStack* initStack(void);
void     creatStack(SqStack* S);
void     destroyStack(SqStack* S);
void     printStack(SqStack* S);
void     rpnStack(SqStack* S, RPN* rpn, Mark* mark);
void     dealMark(RPN* rpn, Mark* mark, char ch, int pri);
void     conduct(RPN* rpn);

void conduct(RPN* rpn)
{
  int    i = 0;
  int    j = 0;
  double temp[MAX];
  int    p = 0;
  for (int i = 0; i <= rpn->top; i++) {
    if (rpn->data[i] == MARK) {
      switch (rpn->opera[p]) {
      case '+':
      {
        double a  = temp[--j];
        double b  = temp[--j];
        temp[j++] = a + b;
        break;
      }
      case '-':
      {
        double a  = temp[--j];
        double b  = temp[--j];
        temp[j++] = b - a;
        break;
      }
      case '*':
      {
        double a  = temp[--j];
        double b  = temp[--j];
        temp[j++] = a * b;
        break;
      }
      case '/':
      {
        double a  = temp[--j];
        double b  = temp[--j];
        temp[j++] = b / a;
        break;
      }
      case 'c':
      {
        double a  = temp[--j];
        temp[j++] = cos(a);
        break;
      }
      case 's':
      {
        double a  = temp[--j];
        temp[j++] = sin(a);
        break;
      }
      case 'o':
      {
        double a  = temp[--j];
        temp[j++] = log10(a);
        break;
      }
      case 'n':
      {
        double a  = temp[--j];
        temp[j++] = log(a);
        break;
      }
      case '^':
      {
        double a  = temp[--j];
        double b  = temp[--j];
        temp[j++] = pow(b, a);
        break;
      }
      }
      p++;
    }
    else {
      temp[j++] = rpn->data[i];
    }
  }
  printf("result = %.2f\n", temp[0]);
  // return temp[0];
}

void dealMark(RPN* rpn, Mark* mark, char ch, int pri)
{
  if (ch != '(' && ch != ')' && ch != ' ') {
    while (pri <= mark->prior[mark->top] && mark->opera[mark->top] != '(' && mark->top != -1) {
      rpn->data[++rpn->top]   = MARK;
      rpn->opera[++rpn->otop] = mark->opera[mark->top];
      mark->top--;
    }

    mark->opera[++mark->top] = ch;
    mark->prior[mark->top]   = pri;
  }
  else if (ch == '(')
    mark->opera[++mark->top] = ch;
  else if (ch == ')') {
    while (mark->opera[mark->top] != '(') {
      rpn->data[++rpn->top]   = MARK;
      rpn->opera[++rpn->otop] = mark->opera[mark->top];
      mark->top--;
    }
    mark->top--;
  }
}

void rpnStack(SqStack* S, RPN* rpn, Mark* mark)
{
  int t = 0;
  while (t <= S->top) {
    if (isdigit(S->data[t])) {
      char a[MAX];
      memset(a, 0, sizeof(a));
      int ap = -1;

      int i = t;
      for (; isdigit(S->data[i]); i++)
        ;

      if (S->data[i] == '.') {
        i++;
        while (isdigit(S->data[i])) {
          i++;
        }
        for (int j = t; j < i; j++) {
          a[++ap] = S->data[j];
        }

        rpn->data[++rpn->top] = atof(a);
        t                     = i - 1;
      }
      else {
        for (int j = t; j < i; j++) a[++ap] = S->data[j];

        rpn->data[++rpn->top] = atof(a);
        t                     = i - 1;
      }
    }
    else if (S->data[t] == '+' || S->data[t] == '-')
      dealMark(rpn, mark, S->data[t], 1);
    else if (S->data[t] == '*' || S->data[t] == '/')
      dealMark(rpn, mark, S->data[t], 2);
    else if (S->data[t] == 'c' || S->data[t] == 's') {
      dealMark(rpn, mark, S->data[t], 3);
      t = t + 2;
    }
    else if (S->data[t] == 'l') {
      if (S->data[t + 1] == 'o') {
        dealMark(rpn, mark, S->data[t + 1], 3);
        t = t + 2;
      }
      else {
        dealMark(rpn, mark, S->data[t + 1], 3);
        t = t + 1;
      }
    }
    else if (S->data[t] == '^')
      dealMark(rpn, mark, S->data[t], 4);
    else if (S->data[t] == '(')
      dealMark(rpn, mark, S->data[t], 5);
    else if (S->data[t] == ')')
      dealMark(rpn, mark, S->data[t], 5);
    else
      continue;

    t++;
  }

  while (mark->top >= 0) {

    rpn->opera[++rpn->otop] = mark->opera[mark->top--];
    rpn->data[++rpn->top]   = MARK;
  }

  conduct(rpn);
}

void creatStack(SqStack* S)
{
  char ch;
  while (scanf("%c", &ch) == 1 && ch != '=') S->data[++S->top] = ch;
}

void printStack(SqStack* S)
{
  int t = 0;
  while (t <= S->top) printf("%c", S->data[t++]);
  printf("\n");
}

void destroyStack(SqStack* S)
{
  free(S->data);
  free(S);
}

SqStack* initStack(void)
{
  SqStack* S = (SqStack*)malloc(sizeof(SqStack));
  if (!S) exit(0);

  S->top = -1;

  return S;
}


int main(void)
{
  freopen("逆波兰式.txt", "r", stdin);

  SqStack* S = initStack();
  creatStack(S);
  printStack(S);

  Mark* mark = (Mark*)malloc(sizeof(Mark));
  for (int i = 0; i < MAX; i++) mark->prior[i] = -2;
  mark->top = -1;

  RPN* rpn  = (RPN*)malloc(sizeof(RPN));
  rpn->otop = rpn->top = -1;

  rpnStack(S, rpn, mark);

  destroyStack(S);
  free(rpn->data);
  free(rpn->opera);
  free(rpn);
  free(mark->opera);
  free(mark->prior);
  free(mark);

  return 0;
}



// 测试数据
// 9.4+(3.27-1.05)*3.44+10/2.1+cos(0.52)+ln(ln(3))/log(5)+3^2=