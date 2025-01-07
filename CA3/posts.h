#include <malloc.h>
post *SearchPost(int id, post *head)
{
    while (head->next != NULL)
    {
        post *nextpost = head->next;
        if (nextpost->post_id >= id)
        {
            return head;
        }
        head = nextpost;
    }
    return head;
    /*search post that find a post with post_id*/
}

int insertPost(char *text, char *owner, int id, post *head, user *headuser)
{
    post *newpost = (post *)malloc(sizeof(post)); /*allocation of a new post*/
    if (newpost == NULL)
        return 1;
    strcpy(newpost->owner, owner);
    strcpy(newpost->text, text);
    newpost->post_id = id;
    newpost->like = 0;
    newpost->next = NULL;
    /*copying data of a post into structure*/

    user *selected;
    while (headuser->next != NULL)
    {
        if (!strcmp(headuser->next->username, owner))
        {
            selected = headuser->next;
        }
        headuser = headuser->next;
    }
    selected->posts_num++;
    /*find the owner of post*/

    post *tempPost = SearchPost(id, head);
    if (tempPost->next == NULL)
    {
        tempPost->next = newpost;
        return 0;
    }
    if (tempPost->next->post_id == id)
    {
        return 0;
    }
    newpost->next = tempPost->next;
    tempPost->next = newpost;
    return 0;
    /*return 0 when post is added */
}
void printpost(post *tempPost)
{
    FILE *posts = fopen("posts.txt", "w"); /*open a file to print data into it*/
    do
    {
        fprintf(posts, "text: %s\towner: %s\tlikes: %d\n", tempPost->text, tempPost->owner, tempPost->like);
        tempPost = tempPost->next;
    } while (tempPost != NULL);
    fclose(posts); /*closing an opened file*/
}

int Remove(post *head, int id)
{
    post *tempPost = SearchPost(id, head); /*find the post which is going to get deleted*/
    post *ptr = tempPost->next;

    if (ptr == NULL)
        return 1;
    if (ptr->post_id != id)
        return 1;

    tempPost->next = ptr->next;
    free(ptr); /*free the memory of a deleted user*/
    return 1;
}
int show_a_user_posts(post *head, char *owner)
{
    while (head->next != NULL)
    {
        head = head->next;
        if (!strcmp(head->owner, owner))
        {
            printf("owner: %s , post %d: %s   likes: %d\n", owner, head->post_id, head->text, head->like);
            return 0;
            continue;
        }
        return 1;
    }
/*find user function that print data of a username*/}
