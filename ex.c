#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include<conio.h>
struct node
{
    int qn;
    char q[200];
    char o1[50];
    char o2[50];
    char o3[50];
    char o4[50];
    int ans;
};

struct type
{
    int choice;
};

int main() {

    int qcount = 0, i = 0, k = 0, flag = 0, j, qstore, ans1, count, x;
    int b[20],value[20];

    struct node ques;
    struct type t1;

    FILE *fp= fopen("data.txt", "rb");
    FILE *fp1=fopen("data1.txt","rb");

    while (fread(&ques, sizeof(struct node), 1, fp) == 1)
    {
        qcount += 1;
    }


    fread(&t1,sizeof(struct type),1,fp1);
    x=t1.choice;
    fclose(fp1);


    printf("                                         Welcome to the Simple Quiz!\n\n");
    printf("  Test your knowledge with a set of interesting questions.\n");
    printf("  There will be multiple-choice options for each question.\n");
    printf("  Choose the correct option by entering the corresponding number.\n\n");
    printf("\n");


    //will give random questions
    if (x == 1) {
        rewind(fp);
        qstore = qcount;

        int upper_bound = qcount;
        int lower_bound = 1;
        srand((unsigned int)time(NULL));

        while (qcount > 0) {
            value[i++] = rand() % (upper_bound - lower_bound + 1) + lower_bound;
            qcount -= 1;
        }

        int qnew = qstore;

        for (i = 0; i < qstore; i++)
            {
            for (j = i + 1; j < qstore; j++)
             {
                if (value[i] == value[j])
                 {
                    for (k = j; k < qstore - 1; k++)
                    {
                        value[k] = value[k + 1];
                    }
                    qstore--;
                    j--;
                }
            }
        }

        for (j = 0; j < qstore; j++)
        {
            b[j] = value[j];
        }

        int size = j;

        for (i = 1; i <= upper_bound; i++)
            {
            for (j = 0; j < qstore; j++)
            {
                if (value[j] == i)
                    flag = 1;
            }

            if (flag == 0)
                b[size++] = i;
            flag = 0;
        }

        k = -1;
        i = 1;

        while (size >= 0)
        {
            while (fread(&ques, sizeof(struct node), 1, fp) == 1)
            {
                if (ques.qn == b[k])
                {
                    printf("%d) ", i++);
                    printf("%s", ques.q);
                    printf("%s%s", ques.o1, ques.o2);
                    if (ques.o3[0] != '0')
                    {
                        printf("%s", ques.o3);
                    }
                    if (ques.o4[0] != '0')
                    {
                        printf("%s", ques.o4);
                    }
                    printf("\n");
                    printf("Enter your option : ");
                    scanf("%d", &ans1);

                    if (ans1 == ques.ans)
                        count++;
                }
            }

            rewind(fp);
            size--;
            k += 1;
        }
    }
    else    //will give ordered questions
        {
        rewind(fp);
        while (fread(&ques, sizeof(struct node), 1, fp) == 1)
        {
            printf("%d) ", ques.qn);
            printf("%s", ques.q);
            printf("%s%s", ques.o1, ques.o2);
                    if (ques.o3[0] != '0')
                    {
                        printf("%s", ques.o3);
                    }
                    if (ques.o4[0] != '0')
                    {
                        printf("%s", ques.o4);
                    }
            printf("\n");
            printf("Enter your option : ");
            scanf("%d", &ans1);
            if (ans1 == ques.ans)
                count++;
        }
    }

    system("cls");
    printf("\n\n                                  Congratulations on completing the quiz!\n\n");
    printf("                             We hope you enjoyed the challenge. Check your score below.\n\n");
    scanf("%*c");
    printf("                                            Your score is %d\n\n", count);
    fclose(fp);
    return 0;
}
