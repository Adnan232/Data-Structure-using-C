// #include<stdio.h>

// int main()
// {
//     int ch;

//     do
//     {
//         printf("\nEnter your Choice : ");
//         scanf("%d",&ch);

//         switch(ch)
//         {
//             case 1:
//                 printf("\nYou have selected choice 1...\n ");
//                 break;
//             case 2:
//                 printf("\nYou have selected choice 2...\n ");
//                 break;
//             case 3:
//                 printf("\nYou have selected choice 3...So Exiting...\n ");
//                 break;
//             default:
//                 printf("\n\aYou Have selected invalid choice...\n");
//                 break;
//         }
//     } while(ch!=3);
//     return 0;
// }


#include<stdio.h>

int main()
{
    int ch;
    printf("\nEnter Your Name : ");
    scanf("%d",&ch);
    printf("\nYour choice : %d",ch);
    return 0;
}



