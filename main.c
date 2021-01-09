#include <stdio.h>
#include <stdlib.h>
#define MAXN 7

// STACK FOR HOLD CHARS

// A structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};
 
// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}
 
// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
 
// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
 
// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}
 
// Function to remove an item from stack.  It decreases top by 1
char pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}
 
// Function to return the top from stack without removing it
char peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top];
}

struct tnode {
	char chr;
	struct tnode *left;
	struct tnode *right;
};


// A structure to represent a stack
struct StackNode {
    int top;
    unsigned capacity;
    char* array;
};
 
// function to create a stack of given capacity. It initializes size of
// stack as 0
struct StackNode* createStackNode(unsigned capacity)
{
    struct StackNode* stack = (struct StackNode*)malloc(sizeof(struct StackNode));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (struct tnode*)malloc(stack->capacity * sizeof(struct tnode));
    return stack;
}
 
// Stack is full when top is equal to the last index
int isFullStackNode(struct StackNode* stack)
{
    return stack->top == stack->capacity - 1;
}
 
// Stack is empty when top is equal to -1
int isEmptyStackNode(struct StackNode* stack)
{
    return stack->top == -1;
}
 
// Function to add an item to stack.  It increases top by 1
void pushStackNode(struct StackNode* stack, char item)
{
    if (isFullStackNode(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}
 
// Function to remove an item from stack.  It decreases top by 1
struct tnode *popStackNode(struct StackNode* stack)
{
    if (isEmptyStackNode(stack))
        return NULL;
    return stack->array[stack->top--];
}
 
// Function to return the top from stack without removing it
struct tnode *peekStackNode(struct StackNode* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}


char s[MAXN];
int p = 0;

int is_operator(char chr) {
	if (chr == '+' || chr == '-' || chr == '/' || chr == '*') {
		return 1;
	} else {
		return 0;
	}
}

struct tnode *newnode(char chr) {
	struct tnode *candidate_node;
	candidate_node->left = NULL;
	candidate_node->right = NULL;
	candidate_node->chr = chr;
	
	return candidate_node;
}

void f(struct tnode *curr) {
	
	if (is_operator(s[p])) {
		
		p++;
		curr->left = newnode(s[p]);
		f(curr->left);
		
		p++;
		curr->right = newnode(s[p]);
		f(curr->right);
	}
}

void prefix(struct tnode *curr) {
	
	printf("%c", curr->chr);
	
	if (curr->left != 0) {
		prefix(curr->left);
	}
	
	if (curr->right != 0) {
		prefix(curr->right);
	}
}


void postfix(struct tnode *curr) {
	
	if (curr->left != 0) {
		postfix(curr->left);
	}
	
	if (curr->right != 0) {
		postfix(curr->right);
	}
	
	printf("%c", curr->chr);
}

void infix(struct tnode *curr) {
	if (is_operator(curr->chr)) {
		putchar('(');
	} 
	
	if (curr->left != 0) {
		infix(curr->left);
	}
	
	printf("%c", curr->chr);
	
	if (curr->right != 0) {
		infix(curr->right);
	}
	
	if (is_operator(curr->chr)) {
		putchar(')');
	}
}

int main(int argc, char *argv[]) {
	
	char arr_char[7]= {'*','A', 'B', '*', 'C' , '/' , 'D'};
	
	int i;
	for (i = 0; i < 7; i++) {
		s[i] = arr_char[i];
//		printf("%c", s[i]);
	}
	
	struct tnode *root = newnode(s[0]);
	f(root);
	prefix(root);
	return 0;
}
