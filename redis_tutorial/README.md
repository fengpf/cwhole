
## 多文件编译链接
参考：http://c.biancheng.net/view/2384.html

### 选项-O
用法：gcc -O1 main.c
作用：使用编译优化级别1编译程序。级别为1~3，级别越大优化效果越好，但编译时间越长。

### 使用-c选项指示 GCC 只编译不链接
gcc -O1 -g -c main.c

### 一旦所有当前源文件都被编译为目标文件，就可以使用 GCC 来链接它们
gcc main.o sds.o zmalloc.o -o sds -lm