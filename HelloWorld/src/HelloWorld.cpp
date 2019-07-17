#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char cred_username[] = "root";
char cred_password[] = "toor";

int main() {
    char isLoggedin = false;
    char username[20];
    char password[20];

    if(((void*)&isLoggedin < (void*)&username) && ((void*)&isLoggedin <(void*)&password)) {
        printf("Not Exploitable!\n");
        printf("isLoggedin   @0x%p\n", &isLoggedin);
        printf("username[20] @0x%p\n", &username);
        printf("password[20] @0x%p\n", &password);
//        exit(0);
    }
    while(1) {
        if(isLoggedin == false) {
            printf("username:");
            fflush(stdout);
            scanf("%s", username);
            printf("password:");
            fflush(stdout);
            scanf("%s", password);
            if(strcmp(username, cred_username) == 0) {
                if(strcmp(password, cred_password) == 0) {
                    isLoggedin = true;
                }
            }
        } else {
            if(strcmp(username, cred_username) == 0 && strcmp(password, cred_password) == 0) {
                printf("Welcome User: %s\n", username);
            } else {
                printf("Congratulations\n"\
                       "\n"\
                       " (\\___/) \n"\
                       " (=^.^=) \n"\
                       " (\")_(\") \n\n");

            }
            exit(0);
        }
    }
}
