user *Search(int num, user *head)
{
    while (head->next != NULL)
    {
        user *nextUser = head->next;
        if (nextUser->uNum >= num)
        {
            return head;
        }
        head = nextUser;
    }
    return head;
    /*search user function that find a user with user number*/
}

int insertUser(char *username, char *password, int num, user *head)
{
    user *check;
    for (int i = -1; i < 1000; i++)
    {
        check = Search(i, head)->next;
        if (check && !strcmp(check->username, username))
        {
            printf("\aWe have such username , please try another one\n");
            return 0;
        }
        /*validation of program for existing accounts*/
    }
    user *newUser = (user *)malloc(sizeof(user)); /*allocation of a new user*/
    if (newUser == NULL)
        return 1;
    newUser->posts_num = 0;
    newUser->uNum = num;
    strcpy(newUser->username, username);
    strcpy(newUser->password, password);
    newUser->next = NULL;
    /*copying data of a user into structure*/
    user *tempUser = Search(num, head);
    if (tempUser->next == NULL)
    {
        tempUser->next = newUser;
        printf("Your account is ready\n");
        return 0;
    }
    if (tempUser->next->uNum == num)
    {
        printf("Your account is ready\n");
        return 0;
    }
    newUser->next = tempUser->next;
    tempUser->next = newUser;
    printf("Your account is ready\n");
    return 0;
    /*return 0 when user is made */
}

void printUsers(user *tempUser)
{
    FILE *users = fopen("users.txt", "w"); /*open a file to print data into it*/
    do
    {
        fprintf(users, "Username: %s\tPassword: %s\tPosts: %d", tempUser->username, tempUser->password, tempUser->posts_num);
        fprintf(users,"\n");
        tempUser = tempUser->next;
    } while (tempUser != NULL);
    fclose(users); /*closing an opened file*/
}


