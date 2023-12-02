#include <stdio.h>
#include <unistd.h>

int global_value = 100;
int main()
{
    printf("global_value=%d\n", global_value);
    printf("--------------创建子进程-------------------\n");
    pid_t id = fork();
    //while(1)
    {
        if(id > 0) 
        {
            //parent 
            sleep(3);//父进程首先等待3秒
            printf("parent->pid:%d, global_value=%d, &global_value=%p\n", getpid(), global_value, &global_value); 
        } 
        else if(id == 0) 
        {
            //child  
            global_value = 200;
            printf(" child->pid:%d, global_value=%d, &global_value=%p\n", getpid(), global_value, &global_value); 
        } 
    } 
}
