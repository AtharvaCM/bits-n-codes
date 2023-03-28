#include "./bstlib.h"

int main()
{
  // Initialize empty tree
  BSTNode *root = NULL;
  bool search_result;

  insert(&root, 33);
  insert(&root, 23);
  insert(&root, 15);
  insert(&root, 45);

  inorder_display(&root);
  std::cout << std::endl;

  search_result = search(&root, 55);
  std::cout << "[+] search_result: " << search_result;

  if (search_result)
  {
    std::cout << "\n[+] Found" << std::endl;
  }
  else
  {
    std::cout << "\n[+] Not Found" << std::endl;
  }
}