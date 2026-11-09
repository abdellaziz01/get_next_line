#include<stdio.h>
#include <fcntl.h>
 #include <unistd.h>
 #include <stdlib.h>
ssize_t ft_strlen(char *str)
 {
    ssize_t i = 0;
    while(str[i])
        i++;
    return i;
 }
char *read_file(int fd)
{ 
    char buffer[7] = {0};
    ssize_t y;
    y = read(fd , buffer , 7); 
   
    if (y <= 0)
        return (NULL);
    char *res = malloc(y + 1);
    if(!res)
        return NULL;
    ssize_t i;
    i  = 0 ;
    while(i < y)
    {
        res[i] = buffer[i];
        i++;
    }
    res[i] = '\0';
    return res;
}
int check(char *str)
{
    if(!str)
        return -1;
    int  j = 0;
    while(str[j] && str[j] != '\n')
        j++;
    if(str[j] == '\n')
        return j;
    return  -1;
}
char *ft_strjoin(char *s1 , char *s2)
{
    if(!s1)
        s1 = "";
    if(!s2)
        return NULL;
    int l1 = ft_strlen(s1);
    int l2 = ft_strlen(s2);
    char *res = malloc(l1 + l2 + 1);
    if(!res)
        return NULL;
    int i;
    int j;
    j = 0;
    i = 0;
    while(s1[i])
        res[j++] = s1[i++];
    i = 0;
    while(s2[i])
        res[j++] = s2[i++];
    res[j] = '\0';
    return res;
}
char *get_next_line(int fd)
{
    static char *temp = NULL;
    char *str;
    char *s1;
    char *res;
    int start;
    char *new_temp;
    int i;
    int end;
    s1 = read_file(fd);
    if (!s1)
        return NULL;
    str = ft_strjoin(temp , s1);
    if(!str)
    {
        free(temp);
        free(s1);
        return NULL;
    }
    free(temp);
    free(s1);
    while(check(str) == -1)
    {
        s1 = read_file(fd);
        if(!s1)
            break;
        temp = ft_strjoin(str , s1);
        free(s1);
        if(!temp)
        {
            free(str);
            return NULL;
        }
        free(str);
        str = temp;
    }
    end = ft_strlen(str);
    if (check(str) == -1)
        start = end;
    else
        start = check(str) + 1;
    res = malloc(start + 1);
    if(!res)
    {
        free(str);
        return NULL;
    }
    i = 0;
    while(i < start){
        res[i] = str[i];
        i++;
    }
    res[i] ='\0';
    new_temp = malloc(end - start + 1);
    if(!new_temp)
    { 
        free(res);
        free(str);
        return NULL;
    }
    i = 0;
    while(i < (end - start))
    {
        new_temp[i] = str[start + i];
        i++;
    }
    new_temp[i] = '\0';
    free(str);
    temp = new_temp;
    return res;
    
}
 
int main()
{ 
 
    int fd = open("test.txt", O_RDONLY);
    //get_next_line(fd);
     printf("%s",get_next_line(fd));
     printf("%s",get_next_line(fd));
     printf("%s",get_next_line(fd));
     printf("%s",get_next_line(fd));
      printf("%s",get_next_line(fd));
       printf("%s",get_next_line(fd));
    return 0;
 
}

 