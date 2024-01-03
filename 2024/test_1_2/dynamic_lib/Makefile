libmath.so:add.o sub.o # 使用gcc的-shared选项将所有目标文件打包为动态库
	gcc -shared -o $@ $^
# 但是这里add.o和sub.o文件不是凭空产生的，所以需要为他们提供一个依赖关系
add.o:add.c # 编译的时候带上-fPIC选项，产生位置无关码
	gcc -fPIC -c -o $@ $^ 
sub.o:sub.c # 编译的时候带上-fPIC选项，产生位置无关码
	gcc -fPIC -c -o $@ $^

.PHONY:output
output: # 打包生成的文件，成为一个库
	mkdir -p mylib/include
	mkdir -p mylib/lib 
	cp -f *.so mylib/lib 
	cp -f *.h mylib/include

.PHONY:clean # 清理产生的所有文件
clean:
	rm -rf mylib *.o *.so
