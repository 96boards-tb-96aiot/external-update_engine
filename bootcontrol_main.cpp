#include <stdio.h>
#include "rkboot_control.h"
#include <string.h>
int main(int argc, char *argv[]){
    //1. bootsucceed
    //2. bootactivity
    //3. wipe_userdata reboot/ wipe_userdata
    if(argc == 1){
        printf("Error: bootcontrol parameter error.\n");
        struct rk_ab info;
        readMisc(&info);
        display(info);
        return -1;
    }

    if(strcmp(argv[1], "bootsucceed") == 0){
        printf("set now slot to succeed.\n");
        return setSlotSucceed();
    }else if(strcmp(argv[1], "bootactivity") == 0){
        printf("set other slot to activity.\n");
        return setSlotActivity();
    }else if(strcmp(argv[1], "wipe_userdata") == 0){
        printf("wipe_userdata.\n");
        if(argc == 3 && strcmp(argv[2], "reboot") == 0){
            return wipe_userdata(true);
        }else{
            return wipe_userdata(false);
        }
    }
    
    return 0;
}
