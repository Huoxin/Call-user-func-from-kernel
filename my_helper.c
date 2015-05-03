#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");

static __init int helper_init(void)
{
        int ret = 0;
#if 0
        char cmd_path[] = "/bin/touch";
        char *cmd_argv[] = {cmd_path, "/touchX.txt", NULL};
        char *cmd_envp[] = {"HOME=/", "PATH=/sbin:/bin:/usr/bin", NULL};
#else
        char cmd_path[] = "/bin/sh";
        char *cmd_argv[] = {cmd_path, "/home/xhz/Project/UserHelper/sh/xhz-test-start",  NULL};
        char *cmd_envp[] = {"HOME=/", "PATH=/sbin:/bin:/usr/bin", NULL};
#endif
        printk(KERN_INFO "my helper init!\n");
        ret = call_usermodehelper(cmd_path, cmd_argv, cmd_envp, UMH_WAIT_EXEC);
        printk(KERN_INFO "call userhelper! ret=%d\n", ret);
        printk(KERN_INFO "the process \"%s\", pid is %d\n", current->comm, current->pid);
        return ret;
}

static __exit void helper_exit(void)
{
        int ret = 0;
#if 0
        char cmd_path[] = "/bin/rm";
        char *cmd_argv[] = {cmd_path, "/touchX.txt", NULL};
        char *cmd_envp[] = {"HOME=/", "PATH=/sbin:/bin:/usr/bin", NULL};
#else
        char cmd_path[] = "/bin/sh";
        char *cmd_argv[] = {cmd_path, "/home/xhz/Project/UserHelper/sh/xhz-test-end",  NULL};
        char *cmd_envp[] = {"HOME=/", "PATH=/sbin:/bin:/usr/bin", NULL};

        ret = call_usermodehelper(cmd_path, cmd_argv, cmd_envp, UMH_WAIT_EXEC);

#endif
        printk(KERN_INFO "my_helper exit! ret = %d\n", ret);
        printk(KERN_INFO "my_helper exit, process is \"%s\", pid is %d\n", current->comm, current->pid);
}


module_init(helper_init);
module_exit(helper_exit);
