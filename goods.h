#ifndef GOODS_H
#define GOODS_H

typedef struct 
{
    char id[20];         //商品ID
    char name[41];      //商品名
    char is_delete;     //商品现存状态（1表示存在，0表示被删除）
    char goodstype[20]; //商品类型
//char类型的数据放在一起定义，节省内存空间

    float price;        //商品价格
    int time;           //商品进货时间
    int start_num;      //商品进货数量
    int new_num;        //商品现存数量
    int discont;        //商品折扣
}goods;


void init_gl(void);     //商品信息初始化
void goods_add(void);       //商品信息的添加 

#endif