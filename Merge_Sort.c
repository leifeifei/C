/*
File name:Heap_Sort
Author:雷飞飞
Date:2016-8-12
Description:递归实现归并排序
归并排序：基本的操作是合并两个已经排序的表，因为两个表是已经排序好的，将其输入第三个表时，
          只需一趟排序即可。
          对于N个数，进行归并排序用时等于完成两个大小N/2的递归排序的时间加上合并的时间。
程序思路：1.对于输入的未排序的数组A，将其从中间不断分割，假如一数组的标号为
                       [0],[1],[2],[3],[4],[5],[6],[7]
            第一次分割:以[3]( (0 + 7)/2 )为中心点分割.即为A [0,3], B [4,7]
            第二次分割:A以[1]( (0 + 3)/2)为中心点分割.即为A1 [0,1],A2 [2,3]
                       B以[5]( (4 + 7)/2)为中心点分割,即为B1 [4,5], B2 [6,7]
            第三次分割:A1以[0]( (0 + 1)/2)为分割点，即为A11 [0],A12 [1]
                       A2,B1,B2分割均同上
            注：分割后的两个表中，每个表的元素均不可小于1
          2.分割后自然是合并，在合并的同时排序。
            1，因为是递归，最后一层递归，先合并并排序，回到上一层递归时，两个数组即已排序
               也即满足了归并排序的性质，始终排序两个已排序的数组。
            2.在合并排序中，定义一个临时数组，始终将比较小的数放在前面，
              如 1.若[0] > [1] 在临时数组中，他们将是这样摆放[1],[0].
                   注：经过这一步，要么两个表中都无数据，要么只剩一个表还有数据。
                 2.若排序完，两个表中，其中有一个表还有数据，即将剩下的数据拷贝进临时数组
                 3.再将临时数组里面的数，拷贝到原始数组中。
                   注：他们拷贝回的是对应原始数组的位置。

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//合并并排序
void Merge(int a[],int t[],int left,int right,int end)
{
  int leftend = right;
  int tmpos = left;
  int MemberCount = end - left + 1;

  //1.若[0] > [1] 在临时数组中，他们将是这样摆放[1],[0].
  //  注：经过这一步，要么两个表中都无数据，要么只剩一个表还有数据。
  while (left < leftend && right <= end)
  {
    if (a[left] < a[right])
    {
       t[tmpos++] = a[left++];
    }
    else
    {
      t[tmpos++] = a[right++];
    }
  }

  //2.其中若有一个表还有数据，即将剩下的数据拷贝进临时数组
  while (left < leftend)
  {
    t[tmpos++] = a[left++];
  }
  while (right <= end)
  {
    t[tmpos++] = a[right++];
  }

  //3.再将临时数组里面的数，拷贝到原始数组中。
  //  注：他们拷贝回的是对应原始数组的位置。
  while (MemberCount--)
  {
    a[end] = t[end--];
  }
}

//分离后再合并
void Splite(int a[],int t[],int left,int right)
{
   int pos;
   if (left < right)
   {
     pos = (left + right)/2;
     Splite(a,t,left,pos);
     Splite(a,t,pos+1,right);
     Merge(a,t,left,pos+1,right); 
   }
}

//归并排序的主函数
void Merge_Sort(int a[],int MemberCount)
{
   //给临时数组分配空间
   int * t = (int *)malloc(MemberCount*sizeof(int) );
   if (t != NULL)
   {
     Splite(a,t,0,MemberCount-1); 
     free(t);
   }
   else
   {
    printf("malloc was wrong!!!");
   }
}

int main(int argc, char const *argv[])
{
  int a[] = {24,13,26,1,2,27,38,15};
  Merge_Sort(a,8);
  int i;
  for (i = 0; i < 8; i++)
  {
    printf("%d\t",a[i] );
  }
  printf("\n");
  return 0;
}