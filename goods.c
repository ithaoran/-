#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "link_list.h"
#include "goods.h"

list gs;    //全局变量，存放商品信息

//商品信息初始化
void init_gl(void)
{
   gs = creat_l();
}

//商品信息的添加 
void goods_add(void)  
{
    goods g;
    char c;     //用于判断是否继续循环

    while (1)
    {
        printf("请按以下信息依次输入商品信息:\n");
        printf("请输入商品分区:(商品类型)  ");
        fscanf(stdin, "%s", g.goodstype);
        printf("请输入商品号:(69条型码,长度应为13位)  ");
        fscanf(stdin, "%s", g.id);
        printf("请输入商品名称:(合法即可)  ");
        fscanf(stdin, "%s", g.name);
        printf("请输入商品价格:(保留两位小数)  ");
        fscanf(stdin, "%f", &g.price);
        printf("请输入商品折扣:(数字1-10表示,10表示没有折扣)  ");
        fscanf(stdin, "%d", &g.discont);
        printf("请输入商品进货数量:");
        fscanf(stdin, "%d", &g.start_num);
        g.time = time(NULL);

        push_back_l(gs, (void*)&g);     //尾插，不加（void*）会报警告

        printf("\n录入信息成功!\n");
        printf("是否需要继续输入商品信息:(Y/N)\n");

         // 清空标准输入缓冲区中的所有数据，否则会导致下次调用 scanf 立即失败返回。一直到读到‘\n’，虽然不满足循环条件，但是先读取再循环，也相当于清除了。
        while(c = getchar() != '\n');
        c = getchar();    

        if(c == 'n' || c == 'N') break;
    }
}