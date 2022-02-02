#include"bits/stdc++.h"
using namespace std;

class TreeNode{
  public:
     int value;
     TreeNode* left;
     TreeNode* right;

     TreeNode(){
       value=0;
       left=NULL;
       right=NULL;
     }
     TreeNode(int v){
       value=v;
       left=NULL;
       right=NULL;
     }

};



class AVLTree {
  public:
    TreeNode * root;
  AVLTree() {
    root = NULL;
  }
  bool isTreeEmpty() {
    if (root == NULL) {
      return true;
    } else {
      return false;
    }
  }
  // Get Height
  int height(TreeNode * r) {
    if (r == NULL)
      return -1;
    else {
      /* compute the height of each subtree */
      int lheight = height(r -> left);
      int rheight = height(r -> right);

      /* use the larger one */
      if (lheight > rheight)
        return (lheight + 1);
      else return (rheight + 1);
    }
  }

  // Get Balance factor of node N
  int getBalanceFactor(TreeNode * n) {
    if (n == NULL)
      return -1;
    return height(n -> left) - height(n -> right);
  }

  TreeNode * rightRotate(TreeNode * y) {
    TreeNode * x = y -> left;
    TreeNode * T2 = x -> right;

    // Perform rotation
    x -> right = y;
    y -> left = T2;

    return x;
  }

  TreeNode * leftRotate(TreeNode * x) {
    TreeNode * y = x -> right;
    TreeNode * T2 = y -> left;

    // Perform rotation
    y -> left = x;
    x -> right = T2;

    return y;
  }

  TreeNode * insert(TreeNode * r, TreeNode * new_node) {
    if (r == NULL) {
      r = new_node;
      cout << "Value inserted successfully" << endl;
      return r;
    }

    if (new_node -> value < r -> value) {
      r -> left = insert(r -> left, new_node);
    } else if (new_node -> value > r -> value) {
      r -> right = insert(r -> right, new_node);
    } else {
      cout << "No duplicate values allowed!" << endl;
      return r;
    }

    int bf = getBalanceFactor(r);
    // Left Left Case
    if (bf > 1 && new_node -> value < r -> left -> value)
      return rightRotate(r);

    // Right Right Case
    if (bf < -1 && new_node -> value > r -> right -> value)
      return leftRotate(r);

    // Left Right Case
    if (bf > 1 && new_node -> value > r -> left -> value) {
      r -> left = leftRotate(r -> left);
      return rightRotate(r);
    }

    // Right Left Case
    if (bf < -1 && new_node -> value < r -> right -> value) {
      r -> right = rightRotate(r -> right);
      return leftRotate(r);
    }

    /* return the (unchanged) node pointer */
    return r;

  }
  TreeNode* minValueNode(TreeNode* node)
  {
      TreeNode* current=node;
      while(current->left!=NULL)
      {
          current=current->left;
      }
      return current;
  }

    void print(TreeNode* r,int space)
    {
        if(r==NULL)
            return;
        print(r->right,space);
        cout<<endl;
        cout<<r->value<<"\n";
        cout<<endl;
        print(r->left,space);
    }

    TreeNode* RecursiveSearch(TreeNode* r,int val)
    {
        if(r==NULL || r->value==val)
            return r;
        else if(val < r->value)
        {
            return  RecursiveSearch(r->left,val);
        }
        else
        {
            return  RecursiveSearch(r->right,val);
        }
    }

};

int main()
{
    AVLTree obj;
    int option,val;

    do{
        cout<<"What option do you perform"<<endl;
        cout<<"Insert Node"<<endl;
        cout<<"Search Node"<<endl;
        cout<<"Delete Node"<<endl;
        cout<<"Print AVL Tree"<<endl;
        cout<<"Hight of the Tree"<<endl;
        cout<<"Clear Screen"<<endl;
        cout<<"Exit Program....."<<endl;

        cin>>option;

        TreeNode* new_node=new TreeNode();

        switch(option)
        {
            case 0:
            break;

            case 1:
                cout<<"AVL insert"<<endl;
                cout<<"enter the node to insert in the AVL Tree: ";
                cin>>val;

                new_node->value=val;
                obj.root=obj.insert(obj.root,new_node);
                cout<<endl;
            break;

            case 2:
                cout<<"Search"<<endl;
                cout<<"Enter the node do you want to search in this node: ";
                cin>>val;
                new_node = obj.RecursiveSearch(obj.root,val);
                if(new_node!=NULL)
                {
                    cout<<"value Found"<<endl;
                }
                else
                {
                    cout<<"value is not found "<<endl;
                }
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
            break;

            case 6:
            break;


        }
    }

    while(option);
}
