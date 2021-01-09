#include <stdio.h>
#include <stdlib.h>
#define MAXN 7


struct tnode {
	char chr;
	struct tnode *left;
	struct tnode *right;
};

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
