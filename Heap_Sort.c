/*
File name:Heap_Sort
Author:雷飞飞
Date:2016-8-12
Description:堆排序
堆的性质：结构性和堆序性
          1.结构性：堆是一颗被完全填满的二叉树，因为完全二叉树很有规律，所以可以用数组来表示
                    对于数组中的任一位置i上的元素，其左儿子在位置2i上，右儿子在2i+1中，则他们的
                    父亲在在位置[i/2]上。
                    注：以上描述是指在二叉堆中，从数组的1位置开始。在实际的堆排序中，是从0开始的，
                        所以小小变动一下上面的描述。对于数组中任一位置i+1 上的元素，其左儿子在2i+1
                        的位置上，右儿子在2i+2的位置上
          2.堆序性：对于一个结点X，X的父亲中的关键值小于或等于X中关键值，根结点除外
程序思路：一般在排序中，我们默认输出的都是升序，
          1.若为升序，则堆中根结点的值大于所在子树的所有值，
            1.首先让已知数组呈现堆的性质，按照跟结点的值，大于或等于其子树中的结点，父结点的值，也
              均大于孩子结点。按照这个思想去构建堆。
            2.当数组满足堆性质后，因为根结点，也即是[0]位置的元素，将是最大值，采用依次删除最大值的
              思想排序。若当前堆中有六个元素，删除一个最大值M时，可以M放在六的为位置，再次删除一个最
              大值M1，可以放在五的位置。
              注：在删除后，也始终需要满足堆的性质，才可正确排序     
*/

#include <stdio.h>
#include <string.h>
#define CHILD(i) (2 * (i) + 1)

//此函数用于让堆始终满足性质
void Fix_Heap(int a[],int i,int len)
{
    int tmp = a[i];
    int child;
    for ( ; CHILD(i) < len; i = child )
    {
      child = CHILD(i);
      if (child < len - 1 && a[child] < a[child + 1])
      {
        child++;
      }
       if (tmp < a[child])
      {
        a[i] = a[child];
      }
      else
      {
        break;
      }
    }
    a[i] = tmp;
}

//堆排序
void Sort_Heap(int a[],int len)
{
    int i;
    int val;
    for (i = len/2; i >= 0; i--)    //Build_Heap
    {
        Fix_Heap(a,i,len);
    }
    for (i = len - 1; i > 0; i--)   //Detele_Max_Of_Heap
    {
        val = a[i];
        a[i] = a[0];
        a[0] = val; 
        Fix_Heap(a,0,i);
    }
}

int main(int argc, char const *argv[])
{
  int a[] = {61,41,59,26,58,58,64};
  Sort_Heap(a,7);
  int i;
  for (i = 0;i < 7; i++)
  {
    printf("%d\t", a[i]);
  }
  printf("\n");
  return 0;
}