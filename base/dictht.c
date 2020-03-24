#include<stdio.h>
#include<stdint.h>
// 哈希桶
typedef struct dictEntry
{
	void *key;//键定义
	//值定义
	union {
		void *val; //自定义类型
		uint64_t u64; //无符号整型
		int64_t s64;//有符号整型
		double d; //浮点型
	}v;

	struct dictEntry *next; //指向下一个哈希表节点
}dictEntry;

//hash 表结构定义
typedef struct dictht 
{
	dictEntry **table;//哈希表数组
	unsigned long size; //哈希表的大小
	unsigned long sizemask;//哈希表大小掩码
	unsigned long used; //哈希表现有节点的数量
}dictht;

typedef struct dictType {
    unsigned int (*hashFunction)(const void *key);
    void *(*keyDup)(void *privdata, const void *key);
    void *(*valDup)(void *privdata, const void *obj);
    int (*keyCompare)(void *privdata, const void *key1, const void *key2);
    void (*keyDestructor)(void *privdata, void *key);
    void (*valDestructor)(void *privdata, void *obj);
} dictType;

typedef struct dict
{
	dictType *type;//字典类型
	void *privdata;//私有数据
	dictht ht[2];//哈希表【两个】
	long rehashidx;//记录rehash进度的标志，值为-1表示rehash未进行
	int iterators;//当前正在迭代的迭代器数目
}dict;


int main(int argc, char *argv[])
{

}
