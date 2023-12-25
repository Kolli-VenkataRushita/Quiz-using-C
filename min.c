#include <stdio.h>
#include <string.h>
#include<time.h>
#include<stdlib.h>
struct node {
    int qn;
    char q[200];
    char o1[50];
    char o2[50];
    char o3[50];
    char o4[50];
    int ans;
};
struct type{
    int choice;
};

int main() {
    FILE *fp = fopen("data.txt", "wb");
    struct node num;
    int x,n,count;
    char c;

    while (n) {
        printf("Enter question number: ");
        scanf("%d", &num.qn);

        printf("Enter Question (multiple lines, terminate with a line containing only '`'): \n");
        scanf("%*c"); // Consume the newline character left in the buffer
        char line[200];
        strcpy(num.q, "");
        while (1) {

            fgets(line, sizeof(line), stdin);
            if (strcmp(line, "`\n") == 0) // Terminate on a line with only '`'
                break;
            strcat(num.q, line);
        }

        printf("Enter options(for yes/no options enter 3 and 4 options 0:\n");
        fgets(num.o1, sizeof(num.o1), stdin);
        fgets(num.o2, sizeof(num.o2), stdin);
        fgets(num.o3, sizeof(num.o3), stdin);
        fgets(num.o4, sizeof(num.o4), stdin);
        printf("Enter correct answer: ");
        scanf("%d",&num.ans);

        fwrite(&num, sizeof(struct node), 1, fp);
        printf("Do you want to add another question ? \nif yes enter 1 else 0: ");
        scanf("%d",&n);
    }
    FILE *fp1=fopen("data1.txt","wb");
    struct type t1;
    printf("Enter \n1.Random Questions\n2.Ordered Questions\n");
    scanf("%d",&t1.choice);
    fwrite(&t1, sizeof(struct type), 1, fp1);
    fclose(fp1);
    fclose(fp);
}
