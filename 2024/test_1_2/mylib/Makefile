mathlib.a:add.o sub.o # 生成mathlib.a文件，依赖于add.o 和 sub.o
	ar -rc $@ $^
# 但是这里add.o和sub.o文件不是凭空产生的，所以需要为他们提供一个依赖关系
add.o:add.c
	gcc -c -o $@ $^
sub.o:sub.c
	gcc -c -o $@ $^

.PHONY:output
output: # 打包生成的文件，成为一个库
	mkdir -p mylib/include
	mkdir -p mylib/lib 
	cp -f *.a mylib/lib 
	cp -f *.h mylib/include

.PHONY:clean # 清理产生的所有文件
clean:
	rm -rf mylib *.o *.a 
