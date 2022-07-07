#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/landlock.h>
#include <sys/types.h>
#include "ll_wrapper.h"

int add_read_access_rule(int rset_fd,int allowed_fd) {
	int result;
	struct landlock_path_beneath_attr target;
	target.parent_fd = allowed_fd;
	target.allowed_access = LANDLOCK_ACCESS_FS_READ_FILE | LANDLOCK_ACCESS_FS_READ_DIR;
	result = landlock_add_rule(rset_fd,LANDLOCK_RULE_PATH_BENEATH,&target,0);
	return result;
}

int add_write_access_rule(int rset_fd,int allowed_fd,int restricted) {
	int result;
	struct landlock_path_beneath_attr target;
	target.parent_fd = allowed_fd;
	if (restricted==0) target.allowed_access = LANDLOCK_ACCESS_FS_WRITE_FILE | LANDLOCK_ACCESS_FS_REMOVE_FILE | LANDLOCK_ACCESS_FS_REMOVE_DIR | LANDLOCK_ACCESS_FS_MAKE_CHAR | LANDLOCK_ACCESS_FS_MAKE_DIR | LANDLOCK_ACCESS_FS_MAKE_REG | LANDLOCK_ACCESS_FS_MAKE_SOCK | LANDLOCK_ACCESS_FS_MAKE_FIFO | LANDLOCK_ACCESS_FS_MAKE_BLOCK | LANDLOCK_ACCESS_FS_MAKE_SYM;
	else if (restricted==1) target.allowed_access = LANDLOCK_ACCESS_FS_WRITE_FILE | LANDLOCK_ACCESS_FS_REMOVE_FILE | LANDLOCK_ACCESS_FS_REMOVE_DIR | LANDLOCK_ACCESS_FS_MAKE_CHAR | LANDLOCK_ACCESS_FS_MAKE_DIR | LANDLOCK_ACCESS_FS_MAKE_REG | LANDLOCK_ACCESS_FS_MAKE_SYM;
	result = landlock_add_rule(rset_fd,LANDLOCK_RULE_PATH_BENEATH,&target,0);
	return result;
}

int add_execute_rule(int rset_fd,int allowed_fd) {
	int result;
	struct landlock_path_beneath_attr target;
	target.parent_fd = allowed_fd;
	target.allowed_access = LANDLOCK_ACCESS_FS_EXECUTE;
	result = landlock_add_rule(rset_fd,LANDLOCK_RULE_PATH_BENEATH,&target,0);
	return result;
}
