/*
File name:Reverse_Sentense
Author:雷飞飞
Date:2016-8_3
Description:输入一个英文句子，翻转句子中的单词顺序。
            要求单词内字符顺序不变，句子中单词以空格隔开。
            如输入 " I am a student."
              输出 " student. a am I"
程序思路：
         将输入的每个单词分别翻转，然后在全部翻转。
*/

#include <stdio.h>
#include <string.h>

//翻转函数，翻转数组a中[from,to]之间的字符
void reverse_fun(char a[],int from,int to)
{
   char tmp;
   while(from < to)
   {
       tmp = a[from];
       a[from++] = a[to];
       a[to--] = tmp;
   }
}

int main(int argc, char const *argv[])
{
  char a[100];
  gets(a);
  int n = strlen(a);
  int i;
  int count = 0;

  //分割每个单词，找到每个单词的起点坐标和终点坐标
  for(i = 0; i < n; i++)
  {
     if(a[i] == ' ')  //默认单词间用空格隔开
     {
       reverse_fun(a,count,i-1);
       count = i+1;       
     }
     if(a[i] == '.')  //以'.'作为结束符号
     {
      reverse_fun(a,count,i);
     }
     if(i == n-1)
     {
      reverse_fun(a,count,i);  //无结束符号
     }
  }
  reverse_fun(a,0,n-1);
  for(i = 0; i < n; i++)
  {
    printf("%c",a[i]);
  }
  printf("\n");
  return 0;
}