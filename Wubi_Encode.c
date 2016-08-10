/*
File name:Wubi_Encode
Author:雷飞飞
Date:2016-8-4
Description:五笔的编码范围是a到y的25个字母，从1位到4位的编码，
            如果将五笔的编码按字典序排序，形成数组如下：a, aa, aaa, aaaa, aaab, aaac, ..., 
            b, ba, baa, baaa, baab...yyyx, yyyy
            其中a的索引是0，aa的索引是1，aaa的索引是2，aaaa的索引是3，以此类推：
            1）、编写一个函数，输入是任意一个合法的字符串，输出这个字符串对应的索引；
            2）、编写一个函数，输入是任意一个合法的索引，输出这个索引对应的字符串。
程序思路：
         1.aaaa->aaab  aaab = aaaa索引 + 1；
         2.aaa->aab    aab = aaa索引 + 25 + 1；
         3.aa->ab      ab = aa索引 + 25*25 + 25 +1；
         4.a->b        b = a索引 + 25*25*25 + 25*25 + 25 + 1;
*/

#include <stdio.h>
#include <string.h>

//输入是任意一个合法的字符串，输出这个字符串对应的索引；
int Find_Index(char * str)
{
  int len = 0;
  int index = 0;
  int index_jg[] = {25 * 25 * 25 + 25 * 25 + 25 + 1, 25 * 25 + 25 +1, 25 + 1, 1};
  while(*str)
  {
    index += index_jg[len++] * (*str++ - 'a');
  }
  index += (len - 1);
  printf("%d\n", index );
} 

//输入是任意一个合法的索引，输出这个索引对应的字符串
char * Find_Char(int index)
{
  int index_jg[] = {25 * 25 * 25 + 25 * 25 + 25 + 1, 25 * 25 + 25 +1, 25 + 1, 1};
  char str[5] = {0};
  int i = 0;
  while(index >= 0)
  {
      str[i] = index / (index_jg[i]) + 'a';
      index %= index_jg[i];
      i++;
      index -= 1;      
  }
  for(i = 0; i < strlen(str); i++)
  {
    printf("%c",str[i] );
  }
  printf("\n");
}

int main(int argc, char const *argv[])
{
  int index = 12345;
  char str[5] = {0};
  //Find_Char(index);
  Find_Index("asya");
  return 0;
}
