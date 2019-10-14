#Makefile
# 目标:依赖
#	命令
#三要素组成一条规则

CC=gcc
Cflag=-I ../

all:
	@echo "指定编译目标"

#获取目录下所有的.c文件
src=$(wildcard ./*.c)

#将所有的.c计算成.o
obj=$(patsubst ./%.c, ./%.o, $(src))

target=app

$(target):$(obj)
	$(CC) $(obj) -o $(target) $(Cflag)

#将.c文件编译成.o文件
%.o:%.c
	@$(CC)  -c $< -o  $@ $(Cflag)

ftw:ftw.o exception.o path_alloc.o
	@$(CC) $^ -o out/$@ 
getcwd:getcwd.o exception.o path_alloc.o
	@$(CC) $^ -o out/$@ 
#指定编译单个文件
%:%.o exception.o
	@$(CC) $^ -o out/$@ 

clean:
	@# -command 忽略错误直接向下执行
	@-rm $(obj) $(target) -f
	@#-find . -perm -u=x -type f | xargs rm
#声明伪目标
.PHONY:clean
