#main
DeBug = 1

obj = neroDateShow

ifeq ($(DeBug),1)
cc = gcc -Wall -g
else
cc = gcc 
endif

$(obj) :$(obj).c
	$(cc) $(obj).c   -o $(obj) 
#	./$(obj)


c :
	rm $(obj) *.o

r :
	./$(obj)
d :
	gdb $(obj)


