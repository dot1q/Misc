struct node { 
 int val; 
 struct node *next; 
}; 
 
//Implemented in Lab #9 
int length(struct node *); 
void push(struct node ** head, int); 
void print(struct node *, int); 
 
void append(struct node ** head, int); 
void clear(struct node **); 
void sort_ascending(struct node **); //Assign 5 stuff 
void sort_descending(struct node **); //Assign 5 stuff

