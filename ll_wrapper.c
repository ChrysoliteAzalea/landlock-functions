#include <sys/types.h>
#include <linux/landlock.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>

int landlock_create_ruleset(struct landlock_ruleset_attr *rsattr,size_t size,__u32 flags) {
	return syscall(__NR_landlock_create_ruleset,rsattr,size,flags);
}

int landlock_add_rule(int fd,enum landlock_rule_type t,void *attr,__u32 flags) {
	return syscall(__NR_landlock_add_rule,fd,t,attr,flags);
}

int landlock_restrict_self(int fd,__u32 flags) {
	return syscall(__NR_landlock_restrict_self,fd,flags);
}
