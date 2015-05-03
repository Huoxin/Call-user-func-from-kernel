# call_usermodehelper

Linux  Kernel提供了call_usermodehelper函数，让我们能够异常方便地在内核中直接新建和运行用户空间程序，并且该程序具有root权限。所调用的用户态程序目前我测试的仅仅是一种后台程序，如果调用的比如是在控制台打印一行文字或者执行一个OpenGL程序绘制图形，则不会成功执行！（暂时未找到原因）

2015-5-3
引用： http://www.cnblogs.com/hoys/archive/2012/03/13/2395232.html

