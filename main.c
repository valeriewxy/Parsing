#include <stdio.h>
#include <stdbool.h>

int main() {
int stack[20];
int top = -1;
void push(int tree) {
	if (top < 19)
    	stack[++top] = tree;
}

int peek() {
	return stack[top];
}

int pop() {
    if (top >= 0) {
        int temp = stack[top];
        stack[top--] = 0;
        return temp;
    }
    return 0;
}

bool isEmpty() {
	for(int i=0; i<=19; i++){
	    if (stack[i] != 0) {
	      return false;
	    }
	}
	return true;
}

push(5);
push(4);
push(3);
push(2);
push(1);

printf("stack top %d\n", peek() );
printf("stack pop %d\n", pop() );
printf("stack top %d\n", peek() );

for (int i = 0; i<19; i++) {
	if (stack[i] != 0)
		printf("%d\n", stack[i]);
}
printf("%d\n", isEmpty());


}