#include <regex.h>        
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/inotify.h>
#include <sys/types.h>

#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )

void reg_test(){
    regex_t regex;
    int reti;
    char msgbuf[100];

    /* Compile regular expression */
    reti = regcomp(&regex, "[a]{3,4}", REG_EXTENDED|REG_NEWLINE);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }

    /* Execute regular expression */
    reti = regexec(&regex, "aaaa", 0, NULL, 0);
    if (!reti) {
        puts("Match");
    }
    else if (reti == REG_NOMATCH) {
        puts("No match");
    }
    else {
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        exit(1);
    }

    /* Free compiled regular expression if you want to use the regex_t again */
    regfree(&regex);
}

void inotify_test(){
    int length, i = 0;
    int fd;
    int wd;
    char buffer[BUF_LEN];

    fd = inotify_init();

    if(fd < 0)
        perror("inotify_init");

    wd = inotify_add_watch( fd, "/ws/dzhang2-sjc", IN_MODIFY | IN_CREATE | IN_DELETE );
    length = read( fd, buffer, BUF_LEN );  

    if(length < 0)
        perror("read");

    while(i < length){
        struct inotify_event *event = (struct inotify_event*) &buffer[i];
        if(event->len){
            if(event->mask & IN_CREATE){
                if(event->mask & IN_ISDIR){
                    printf("The directory %s was created.\n", event->name);       
                }else{
                    printf( "The file %s was created.\n", event->name );
                }
            }else if(event->mask & IN_DELETE){
                if(event->mask & IN_ISDIR){
                    printf( "The directory %s was deleted.\n", event->name );       
                }else{
                    printf( "The file %s was deleted.\n", event->name );
                }
            }else if(event->mask & IN_MODIFY){
                if(event->mask & IN_ISDIR){
                    printf( "The directory %s was modified.\n", event->name );
                }else{
                    printf( "The file %s was modified.\n", event->name );
                }
            }
        }
        i += EVENT_SIZE + event->len;
    }

    inotify_rm_watch( fd, wd );
    close( fd );
}

int main(){
    reg_test();
    int i = 0;
    while(i++ < 10)
        inotify_test();
    return 0;
}