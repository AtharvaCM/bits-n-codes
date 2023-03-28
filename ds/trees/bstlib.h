// A binary search tree, also called an ordered or sorted binary tree, is a rooted binary tree data
// structure with the key of each internal node being greater than all the keys in the respective
// node’s left subtree and less than the ones in its right subtree.

#include <iostream>

struct BSTNode
{
  int data;
  struct BSTNode *left;
  struct BSTNode *right;
};

/**
 * Allocate a new BST node on the Heap, initialize the data with passed and return the address of the new node.
 * @param data Data to store in the node.
 * @returns *BSTNode address of the newly created node.
 */
struct BSTNode *getnode(int data)
{
  struct BSTNode *temp = (struct BSTNode *)malloc(sizeof(struct BSTNode));

  temp->left = NULL;
  temp->right = NULL;
  temp->data = data;

  return temp;
}

/**
 * Insert a new node in the BST. The node will be inserted according to the value of the data.
 * @param root The pointer to pointer of the root node of the BST.
 * @param data Data to store in the node.
 */
void insert(struct BSTNode **root, int data)
{
  // If root(node) is empty then allocate new node as root.
  if (*root == NULL)
  {
    *root = getnode(data);
    return;
  }

  // std::cout << "(*root)->data : " << (*root)->data << std::endl;

  if (data <= (*root)->data)
  {
    insert(&(*root)->left, data);
  }
  else if (data > (*root)->data)
  {
    insert(&(*root)->right, data);
  }
}

/**
 * Display nodes in Inorder traversal format.
 * @param root The pointer to pointer of the root node of the BST.
 */
void inorder_display(struct BSTNode **root)
{
  // Check if the tree is empty.
  if (*root == NULL)
  {
    std::cout << "[+] The BST is empty." << std::endl;
    return;
  }

  // Traverse left.
  if ((*root)->left != NULL)
  {
    inorder_display(&(*root)->left);
  }
  // Print the node.
  std::cout << (*root)->data << " | ";
  // Traverse right.
  if ((*root)->right != NULL)
  {
    inorder_display(&(*root)->right);
  }
}

/**
 * Search if a value is present in the BST.
 * @param root The pointer to pointer of the root node of the BST.
 * @param value The value to search.
 *
 * @returns {bool} true if the value is present, false otherwise.
 */
bool search(struct BSTNode **root, int value)
{
  // Check if the root(current) is NULL
  if (*root == NULL)
  {
    return false;
  }

  if ((*root)->data == value)
  {
    return true;
  }
  if (value <= (*root)->data)
  {
    search(&(*root)->left, value);
  }
  else
  {
    search(&(*root)->right, value);
  }
}