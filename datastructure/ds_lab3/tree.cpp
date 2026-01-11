#include <iostream>
using namespace std;

/*
    Node structure
*/
struct node {
    int id;
    node* left;
    node* right;
};

/*
    Binary Search Tree Class
*/
class BST {
private:
    node* root;

    //insert recursive
    void insertR(node*& r, node* t) {
        if (r == NULL)
            r = t;
        else if (t->id < r->id)
            insertR(r->left, t);
        else
            insertR(r->right, t);
    }

   //search recursive
    node* searchR(node* r, int id) {
        if (r == NULL || r->id == id)
            return r;

        if (id < r->id)
            return searchR(r->left, id);
        else
            return searchR(r->right, id);
    }

    //find min value node
    node* findMin(node* r) {
        while (r && r->left != NULL)
            r = r->left;
        return r;
    }
    //find max value node
    node* findMax(node* r) {
    while (r && r->right != NULL)
        r = r->right;
    return r;
    }

    //delete recursive
    node* deleteR(node* r, int id) {
        if (r == NULL)
            return r;

        if (id < r->id)
            r->left = deleteR(r->left, id);
        else if (id > r->id)
            r->right = deleteR(r->right, id);
        else {
            // Case 1 & 2: node has one or no child
            if (r->left == NULL) {
                node* temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL) {
                node* temp = r->left;
                delete r;
                return temp;
            }

            // Case 3: node has two children
            node* temp = findMin(r->right);
            r->id = temp->id;
            r->right = deleteR(r->right, temp->id);
        }
        return r;
    }

    //traversals
    void inorderR(node* r) {
        if (r) {
            inorderR(r->left);
            cout << r->id << " ";
            inorderR(r->right);
        }
    }

    void preorderR(node* r) {
        if (r) {
            cout << r->id << " ";
            preorderR(r->left);
            preorderR(r->right);
        }
    }

    void postorderR(node* r) {
        if (r) {
            postorderR(r->left);
            postorderR(r->right);
            cout << r->id << " ";
        }
    }

    //hight of node
    int heightR(node* r) {
        if (r == NULL)
            return -1;

        int leftHeight = heightR(r->left);
        int rightHeight = heightR(r->right);

        return 1 + max(leftHeight, rightHeight);
    }

    //depth of node
    int depthR(node* r, int id, int level) {
        if (r == NULL)
            return -1;

        if (r->id == id)
            return level;

        if (id < r->id)
            return depthR(r->left, id, level + 1);
        else
            return depthR(r->right, id, level + 1);
    }

public:
    //constructor
    BST() {
        root = NULL;
    }

    //public interface
    void insert(int id) {
        node* temp = new node{ id, NULL, NULL };
        insertR(root, temp);
    }

    bool search(int id) {
        return searchR(root, id) != NULL;
    }

    void deleteById(int id) {
        root = deleteR(root, id);
    }

    void inorder() {
        inorderR(root);
        cout << endl;
    }

    void preorder() {
        preorderR(root);
        cout << endl;
    }

    void postorder() {
        postorderR(root);
        cout << endl;
    }

    int height(int id) {
        node* n = searchR(root, id);
        if (n == NULL)
            return -1;
        return heightR(n);
    }

    int depth(int id) {
        return depthR(root, id, 0);
    }

    int minValue() {
    node* n = findMin(root);
    if (n == NULL)
        return -1;
    return n->id;
    }

    int maxValue() {
    node* n = findMax(root);
    if (n == NULL)
        return -1;   // tree is empty
    return n->id;
    }


};


int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);

    /*
                 50
               /  \
             30    70
            /  \
          20   40
    */

    cout << "Inorder Traversal: ";
    tree.inorder();
    cout<<"------------------------------------------";
    cout<<endl;
    cout << "Preorder Traversal: ";
    tree.preorder();
    cout<<"------------------------------------------";
    cout<<endl;
    cout << "Postorder Traversal: ";
    tree.postorder();
    cout<<"------------------------------------------";
    cout<<endl;
    cout << "Minimum value: " << tree.minValue() << endl;
    cout << "Maximum value: " << tree.maxValue() << endl;   
    cout<<"------------------------------------------";
    cout<<endl;
    cout << "Searching for 40: "
         << (tree.search(40) ? "Found" : "Not Found") << endl;

    cout << "Searching for 1000: "
         << (tree.search(1000) ? "Found" : "Not Found") << endl;
    cout<<"------------------------------------------";
    cout<<endl;
    cout << "Height of node 50: " << tree.height(50) << endl;
    cout << "Depth of node 20: " << tree.depth(20) << endl;
    cout<<"------------------------------------------";
    cout<<endl;

    tree.deleteById(30);
    cout << "After deletion (Inorder): ";
    tree.inorder();
        /*
                50
               /  \                 <--//before deletion of 30
             30    70
            /  \
          20   40
    */                                /*
                                                50
                                               /  \
          after ->>                          40    70
                                            /
                                          20
                                    */

    return 0;
}
