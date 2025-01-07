typedef struct user user;
struct user
{
    char username[100];
    char password[100];
    int uNum;
    int posts_num;
    user *next;
};
/*defining the users structure*/

typedef struct post post;
struct post
{
    char text[100];
    char owner[100];
    int post_id;
    int like;
    post *next;
};
/*defining the posts structure*/
