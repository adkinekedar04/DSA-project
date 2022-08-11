

// Custom stack like data structure to store nearest neighbours
typedef struct node_in
{
    int *point;
}node_in;


typedef struct node_s
{
    node_in *info; 
    struct node_s *next;
}node_s;

node_s *top;
node_s *top1;
node_s *temp;

int k;


struct node_in *create_data(int arr[]);

void push(int arr[]);

void pop();

void display();

void push_to_array(int data);

void count_1();

void display_array();