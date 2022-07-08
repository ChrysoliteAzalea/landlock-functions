These files contain wrappers for Landlock-related syscalls and functions that populate the Landlock ruleset.

# ll_wrapper.c

This is a source code for Landlock-related syscall wrapper. It can be compiled with gcc:

gcc ll_wrapper.c -c -fpic -o ll_wrapper.o

gcc ll_wrapper.o -shared -o libllwrapper.so

# add_rule.c

This is a source code for functions that add rules to the Landlock ruleset. It can be compiled with gcc:

gcc add_rule.c -c -fpic -o add_rule.o

gcc add_rule.o -shared -o libaddrule.so
