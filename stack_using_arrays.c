#include<stdio.h>
#define max 100
int stack[max];
int top=-1;

void push(int x){
    if(top>=max-1){
        printf("Stack Overflow.\n");
    }
    else{
        top=top+1;
        stack[top]=x;
    }
}

int pop(){
    if(top==-1){
        printf("Stack Underflow.\n");
    }
    else{
        top=top-1;
        stack[top];
    }
}
int peek(){
    if(top==-1){
        printf("Stack is empty.\n");
    }
    else{
        printf("%d",stack[top]);
    }
    printf("\n");
}
int display(){
    int i;
    if(top==-1){
        printf("Stack is empty.\n");
    }
    for(i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
}
int main(){
    int i,ch,x,n;
    printf("Enter the number of operations: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the operation:");
        scanf("%d",&ch);
        if(ch==1){
            printf("Enter a value to be pushed: ");
            scanf("%d",&x);
            push(x);
        }
        else if(ch==2){
            pop();
        }
        else if(ch==3){
            peek();
        }
        
    }
    printf("The stack after all operations is :\n");
    display();
}
