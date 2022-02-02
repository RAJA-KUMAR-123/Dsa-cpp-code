#include<bits/stdc++.h>
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

class Bst{
public:
    TreeNode *root;
    Bst()
    {
        root=NULL;
    }

    bool isTreeEmpty()
    {
        if(root==NULL){
            return true;

        }
        else {
            return false;
        }
    }

 void insertNode(TreeNode* new_node){

  if(root==NULL){
    root=new_node;
    cout<<"value inserted as root node."<<endl;
  }
  else{
     TreeNode *temp=root;
     while(temp!=NULL){
        if(new_node->value==temp->value)
        {
            cout<<"value already exits,Insert the another value!"<<endl;
            return ;
        }
        else if((new_node->value < temp->value)&&(temp->left==NULL))
        {
            temp->left=new_node;
            cout<<"value inserted to the left..."<<endl;
            break;
        }
        else if(new_node->value < temp->value)
        {
            temp=temp->left;
        }
        else if((new_node->value > temp->value)&&(temp->right==NULL))
        {
            temp->right=new_node;
            cout<<"value inserted to the right...."<<endl;
            break;
        }
        else{
            temp=temp->right;
        }
     }
  }
}

TreeNode* iterativeSearch(int val)
{
    if(root==NULL)
    {
        return root;
    }
    else
    {
        TreeNode *temp=root;
        while(temp!=NULL)
        {
            if(val==temp->value)
            {
                return temp;
            }
            else if(val < temp->value)
            {
                temp=temp->left;
            }
            else
            {
                temp=temp->right;
            }
        }
        return NULL;
    }
}

void print2D(TreeNode* r,int space){
    // int SPACE =5;
     if(r==NULL)                    // Base case
      return ;
      //space +=SPACE;
                    // Increase distance between level
     print2D(r->right,space);      // Process right child first
      cout<<" " ;
    // for(int i=SPACE;i<=space;i++)
    /// {
       cout<<" ";
       cout<<r->value<<"\n";
       print2D(r->left,space);     // process left child
     //}
    }

    void printPreorder(TreeNode* r){
    // int SPACE =5;
     if(r==NULL)                    // Base case
      return ;

     cout<<r->value<<" ";
     printPreorder(r->left);
     printPreorder(r->right);
     //}
    }
    void printInorder(TreeNode* r){
    // int SPACE =5;
     if(r==NULL)                    // Base case
      return ;


    printInorder(r->left);
    cout<<r->value<<" ";
    printInorder(r->right);

     //}
    }
    void printpostorder(TreeNode* r){
    // int SPACE =5;
     if(r==NULL)                    // Base case
      return ;


    printpostorder(r->left);
    printpostorder(r->right);
    cout<<r->value<<" ";

     //}
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

    TreeNode* deleteNode(TreeNode* r,int v)
    {
        if(r==NULL)
        {
            return NULL;
        }
        // if the key to be deleted is the smaller than the root key,then it lies in the left subtree
        else if(v < r->value)
        {
            r->left=deleteNode(r->left,v);
        }
         // if the key to be deleted is the smaller than the root key,then it lies in the right subtree
        else if (v>r->value)
        {
            r->right=deleteNode(r->right,v);
        }
        // if the key is same root's key then node to be
        else
        {
            // if node have only one child or no child
            if(r->left==NULL)
            {
                TreeNode* temp=r->right;
                delete r;
                return temp;
            }
            else if(r->right==NULL)
            {
                TreeNode* temp=r->left;
                delete r;
                return temp;
            }
            else
            {
                // node with two children: get the inorder sucessor
                TreeNode* temp=minValueNode(r->right);
                // copy the inorder the successor to this node
                r->value=temp->value;
                // delete the inorder successor
                r->right=deleteNode(r->right,temp->value);
            }

        }
        return  r;
    }

    int hight(TreeNode* r)
    {
        if(r==NULL)
        {
            return -1;
        }
        else
        {
            int lhight=hight(r->left);
            int rhight=hight(r->right);

            if(lhight > rhight){
                return (lhight+1);
            }
            else{
                return (rhight+1);
            }
        }
    }

};



int main()
{
    Bst obj;
    int option,val;
    do{
        cout<< "choose the option"<<endl;
        cout<< "when enter the 0 program exit."<<endl;
        cout<< "1.Insert Node"<<endl;
        cout<< "2.Search the Node"<<endl;
        cout<< "3.Delete the Node"<<endl;
        cout<< "4.Print BST value"<<endl;
        cout<< "5.Hight of Binary Search Tree"<<endl;
        cout<< "6.Clear Screen"<<endl;
        cout<< "0. Exit Program..."<<endl;

         cin>>option;
         // node n1
         TreeNode *new_node=new TreeNode();

         switch(option){
        case 0:
            break;
        case 1:
        cout<<"Insert"<<endl;
        cout<<"insert the value of the tree node to insert in Bst:";
        cin>>val;
        new_node->value=val;
        obj.insertNode(new_node);
        cout<<endl;

        break;

        case 2:
        cout<<"Search"<<endl;
        cout<<"enter the search number...  ";
        cin>>val;
        new_node = obj. iterativeSearch(val);
        if(new_node!=NULL)
        {
            cout<<"value found"<<endl;
        }
        else
        {
            cout<<"value not found"<<endl;
        }
        break;

        case 3:
        cout<<"Delete"<<endl;
        cout<<"enter the value of tree node to delete in Bst:";
        cin>>val;
        new_node=obj.iterativeSearch(val);
        if(new_node!=NULL)
        {
            obj.deleteNode(obj.root,val);
            cout<<"value is deleted"<<endl;
        }
        else{
            cout<<"value is not found"<<endl;
        }
        break;

       case 4:
       cout << "PRINT : " << endl;
       obj.print2D(obj.root, 5);
       cout << endl;
    //   cout << "PRINT PRE-ORDER: " << endl;
     //  obj.printPreorder(obj.root);
    //   cout << endl;
   //    cout << "PRINT IN-ORDER: " << endl;
    //   obj.printInorder(obj.root);
        cout << endl;
   //    cout << "PRINT POST-ORDER: " << endl;
   //    obj.printpostorder(obj.root);
   //    cout << endl;
      // cout << "Print Level Order BFS: \n";
     // obj.printLevelOrderBFS(obj.root);

      break;

        case 5:
        cout<<"Hight of Tree ->"<<endl;
        cout<<"HIGHT :-"<<obj.hight(obj.root)<<endl;
        break;

         case 6:
        system("cls");
        break;


       default:
        cout<<"Please enter the proper option"<<endl;

    }
  }

    while(option!=0);

}
