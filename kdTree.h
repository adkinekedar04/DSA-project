
// KD- tree structure
typedef struct node
{
    int *point; //  Array To store k dimensional points
    struct node *left, *right;
}node;


node *create(int arr[]);

node *insert(node *root, int point[], int depth);

node *insert_main(node *root, int point[]);

bool equal(int arr1[], int arr2[]);

bool search(node *root, int point[], int depth);

bool search_main(node *root, int point[]);
