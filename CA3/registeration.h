void registeration(user *head, post *headPost)
{
    char a;
    do
    {
        int userNumber;
        char input[100];
        char username[100];
        char password[100];
        scanf("%s %s %s %d", input, username, password, &userNumber);

        if ((strcmp(input, "signup") == 0) || (strcmp(input, "SignUp") == 0) || (strcmp(input, "signUp") == 0)) /*signup to make an account*/
        {
            insertUser(username, password, userNumber, head);
        }
        else if ((strcmp(input, "login") == 0) || (strcmp(input, "Login") == 0) || (strcmp(input, "LogIn") == 0)) /*logging in and other options*/
        {
            int check = 0;
            for (int i = 0; i < 100000; i++)
            {
                user *searchOutput = Search(i, head);
                if ((strcmp(searchOutput->username, username) == 0) && (strcmp(searchOutput->password, password) == 0))
                {
                    printf("you have logged in to your account\n\n");
                    check = 1;
                    break;
                }
            } /*checking for a user*/
            if (check == 1)
            {
                char b;
                char text[100];
                int id;
                char input2[100];
                char liked_user[100];
                while ((b = getchar()) != EOF)
                {
                    int command;
                    scanf("%s ", input2);
                    fgets(text, 100, stdin);
                    /*get input and post*/
                    if ((strcmp(input2, "Post") == 0) || (strcmp(input2, "post") == 0))
                    {
                        command = 1;
                        printf("enter post id: ");
                        scanf("%d", &id);
                    }
                    else if ((strcmp(input2, "like") == 0) || (strcmp(input2, "Like") == 0))
                    {
                        command = 2;
                        printf("enter post id: ");
                        scanf("%d", &id);
                    }
                    else if ((strcmp(input2, "delete") == 0) || (strcmp(input2, "Delete") == 0))
                    {
                        command = 3;
                        printf("enter post id: ");
                        scanf("%d", &id);
                    }
                    else if ((strcmp(input2, "log") == 0) || (strcmp(input2, "Log") == 0))
                    {
                        command = 4;
                        printf("enter a number to confirm : ");
                        scanf("%d", &id);
                    }
                    else
                    {
                        printf("invalid input try again\n");
                        continue;
                    }
                    strcpy(liked_user, text);
                    if (command == 1)
                    {
                        printf("Your post is ready\n");
                        insertPost(text, username, id, headPost, head);
                        continue;
                        /*post command*/
                    }
                    else if (command == 2)
                    {
                        printf("You liked post %d\n", id);
                        post *likedPost = SearchPost(id, headPost);
                        (likedPost->next->like)++;
                        continue;
                        /*like command*/
                    }
                    else if (command == 3)
                    {
                        printf("you deleted post %d\n", id);
                        Remove(headPost, id);
                        /*delete command*/
                    }
                    else if (command == 4)
                    {
                        printf("You have logged out of your account\n\n");
                        break;
                        /*log out command*/
                    }
                    else
                    {
                        printf("invalid input try again\n");
                        strcpy(input2, """");
                        strcpy(text, """");
                        id = -1;
                        continue;
                    }
                }
                continue;
            }
            if (check == 0)
            {
                printf("username or password is incorrect , try again\n");
                continue;
                /*when user entered incorrect data*/
            }
        }
        else if ((strcmp(input, "close") == 0) && (strcmp(username, "this") == 0) && (strcmp(password, "app") == 0))
        {
            printf("\n\n\nGOODBYE");
            Sleep(5000);
            break;
            /*closing app command*/
        }
        else if ((strcmp(input, "find") == 0) && (strcmp(username, "user") == 0))
        {
            int result = show_a_user_posts(headPost, password);
            if (result == 1)
            {
                printf("user not found\n");
                strcpy(input, """");
                strcpy(username, """");
                strcpy(password, """");
                continue;
            }
            else
            {
                strcpy(input, """");
                strcpy(username, """");
                strcpy(password, """");
                continue;
            }
            /*find user command that show data of a user*/
        }
        else
        {
            printf("invalid input try agin\n");
            strcpy(input, """");
            strcpy(username, """");
            strcpy(password, """");
            userNumber = -1;
            continue;
            /*the situation that inputs are incorrect*/
        }
        continue;
    } while ((a = getchar()) != EOF);
}
