#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include <windows.h>
#include "structs.h"
#include "users.h"
#include "posts.h"
#include "registeration.h"

int main(void)
{
    printf("Welcome to UTITUTI\n");
    printf("1.if you want to signup use 'signup <username> <password> <user number>' command\n2.if you want to login to an existing account use 'login <username> <password> <user number> '\n3.if you want to find a user data use 'find user <username> .' command\n4.if you want to close app use 'close this app .'command\n\n");
    printf("After logging in :\n1.if you want to post use 'post <text> command'\n2.if you want to like use 'like <username> command\n3.if you want to delete a post use 'delete <your username> command\n4.if you want to logout of your account use 'Log out'command\n\n");
    /*showing options of app at first & after login*/
    user *head = NULL;
    head = (user *)malloc(sizeof(user));
    if (!head)
        return 1;
    head->next = NULL;
    strcpy(head->username, "-1");
    strcpy(head->password, "-1");
    head->uNum = -1;
    head->posts_num = -1;
    /*define and initialize the heead or dummy of users*/

    post *headPost = NULL;
    headPost = (post *)malloc(sizeof(post));
    if (!headPost)
        return 1;
    headPost->next = NULL;
    strcpy(headPost->owner, "-1");
    strcpy(headPost->text, "-1");
    headPost->post_id = -1;
    headPost->like = -1;
    /*define and initialize the heead or dummy of posts*/

    registeration(head, headPost); /*calling the function of signup & login */
    printpost(headPost);           /*print posts in a file*/
    printUsers(head);              /*print users in a file*/
    free(head);
    free(headPost);
    /*making memory of structures free*/
}
