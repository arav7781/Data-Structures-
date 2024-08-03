#include<stdio.h>
#define N 5
int stack1[N],stack2[N];
int top1 = -1;
int top2 = -1;
int count = 0;
void push1(int x){
    if(top1 == N-1){
        printf("overflow condition");
    }
    else{
        top1++;
        stack1[top1] = x;
    }
}
void push2(int x){
    if(top2 == N-1){
        printf("overflow condition");
    }
    else{
        top2++;
        stack2[top2] = x;
    }
}
void enqueue(){
    int x;
    printf("Enter Data:");
    scanf("%d",&x);
    push1(x);
    count++;
}
int pop1(){
    return stack1[top1--];
}
int  pop2(){
    return stack2[top2--];
}
void dequeue(){
    if(top1 == -1 && top2 == -1){
        printf("Queue is empty");
    }
    else{
        for(int i = 0;i<count;i++){
            //stack1 ke elements ko 2 mai dalne ke liye
            int a;
            a = pop1();
            push2(a);
        }
        int b;
        b = pop2();//stack1 ka bottom wala nikal diya.as wo stck 2 ke top pe tha
        printf("The delted element from the Queue is:%d",b);
        count--;//as ek element delete kiya hai
        for(int i = 0;i<count;i++){
            int a;//baaki data wapas same order mai push stack1 mai.
            a = pop2();
            push1(a);
        }
    }
}
void display(){
    for(int i = 0;i<=top1;i++){
        printf("%d",stack1[i]);
    }
}
int main(){
    int ch;
    do {
        printf("Enter the choice 1:enqueue 2:dequeue 3:display 0:exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("The entered choice is invalid.\n");
        }
    } while (ch != 0);
    return 0;
}