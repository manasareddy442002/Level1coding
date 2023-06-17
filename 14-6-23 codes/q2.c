#include<stdio.h>
int main(void)
{
    int num;
    printf("Enter your mark ");
    scanf("%d",&num);
    if(num >=90){
        printf("Grade A ");
    }
    else if (num >=75){
        printf("Grade B ");
    }
    else if (num >=60){
        printf("Grade C");
    }
    else if (num >=50){
        printf("Grade D ");
    }
    else if (num>=0){
        printf("Grade F ");
    }
return 0;
}