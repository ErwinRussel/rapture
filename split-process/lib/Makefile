all: rapture_hook_library.so

rapture_hook_library.so: gl_hook_lib.o glx_hook_lib.o hook_decl.o
	gcc -g -shared gl_hook_lib.o glx_hook_lib.o hook_decl.o -o rapture_hook_libary.so

hook_decl.o: hook_decl.c
	gcc hook_decl.c -o hook_decl.o

gl_hook_lib.o: gl_hook_lib.c
	gcc gl_hook_lib.c -o gl_hook_lib.o

glx_hook_lib.o: glx_hook_lib.c
	gcc glx_hook_lib.c -o glx_hook_lib.o


