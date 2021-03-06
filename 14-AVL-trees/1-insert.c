#include <stdio.h>
#include <stdlib.h>

/* AVL Trees: highly balanced binary search trees.
Balance factor: height of left subtree - height of right subtree: bf = hl - hr = {-1, 0, 1}
bf = | hl - hr | <= 1, if: bf = | hl - hr | > 1, it's unbalanced. It's calculated for every
node in the tree. Balancing is performed by rotations.
Rotations: always done on three nodes, starting from the topmost that became unbalanced and
going two nodes down.
Single rotations:
LL-Rotation/Clock-wise rotation when the tree is unbalanced with too many nodes on the left.
RR-Rotation/Counterclockwise rotation "    "     "     "     "     "      "     "    right.
Double (two-step) rotations:
LR-Rotation: when there are many nodes on the left with some going to the right.
Firstly, a left rotation is performed, then, a right one
RL-Rotation: when there are many nodes on the right with some going to the left.
Firstly, a right rotation is performed, then, a left one

*/

// The node is similar to the one used in the previous trees, but it must have height
struct Node
{
    int data;
    int height; // Necessary to calculate the balance factor
    struct Node *left;
    struct Node *right;
}*root = NULL;

int node_height(struct Node *p)
{
    int hleft, hright;
    hleft = p && p->left ? p->left->height : 0;
    hright = p && p->right ? p->right->height : 0;

    return hleft > hright ? hleft + 1 : hright + 1;
}

int balance_factor(struct Node *p)
{
    int hleft, hright;
    hleft = p && p->left ? p->left->height : 0;
    hright = p && p->right ? p->right->height : 0;

    return hleft - hright;
}

struct Node * LL_rotation(struct Node *p)
{
    struct Node *pl = p->left;
    struct Node *plr = pl->right;

    pl->right = p;
    p->left = plr;

    p->height = node_height(p);
    pl->height = node_height(pl);

    if (root == p)
        root = pl;

    return pl;
}

struct Node * LR_rotation(struct Node *p)
{
    struct Node *pl = p->left;
    struct Node *plr = pl->right;

    pl->right = plr->left;
    p->left = plr->right;

    plr->left = pl;
    plr->right = p;

    pl->height = node_height(pl);
    plr->height = node_height(plr);
    p->height = node_height(p);

    if (root == p)
        root = plr;

    return plr;
}

struct Node * RR_rotation(struct Node *p)
{
    struct Node *pr = p->right;
    struct Node *prl = pr->left;

    pr->left = p;
    p->right = prl;

    p->height = node_height(p);
    pr->height = node_height(pr);

    if (root == p)
        root = pr;

    return pr;
}

struct Node * RL_rotation(struct Node *p)
{
    struct Node *pr = p->right;
    struct Node *prl = pr->left;

    pr->left = prl->right;
    p->right = prl->left;

    prl->right = pr;
    prl->left = p;

    p->height = node_height(p);
    pr->height = node_height(pr);
    prl->height = node_height(prl);

    if (root == p)
        root = prl;

    return prl;
}

// Similar to the recursive insert used in a binary search tree
struct Node * rec_insert(struct Node *root, int key)
{
    struct Node *p = NULL;

    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->height = 1; // Considering this is the first, single, node in the tree
        p->left = p->right = NULL;
        return p;
    }
    if (key < root->data)
    {
        root->left = rec_insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = rec_insert(root->right, key);
    }
    // Update the height for every node at returning time
    root->height = node_height(root); // Should be equal to the maximum height of left or right subtree (the greatest one)

    if (balance_factor(root) == 2 && balance_factor(root->left) == 1)
        return LL_rotation(root);
    if (balance_factor(root) == 2 && balance_factor(root->left) == -1)
        return LR_rotation(root);
    if (balance_factor(root) == -2 && balance_factor(root->right) == -1)
        return RR_rotation(root);
    if (balance_factor(root) == -2 && balance_factor(root->right) == 1)
        return RL_rotation(root);

    return root;
}

void inorder(struct Node *p)
{
    if (p)
    {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}

int main(void)
{

    // Forcing a LL-Rotation
    //root = rec_insert(root, 20);
    //rec_insert(root, 15);
    //rec_insert(root, 10);

    //inorder(root); // 10 15 20

    // Forcing a RR-Rotation
    //root = rec_insert(root, 20);
    //rec_insert(root, 25);
    //rec_insert(root, 30);

    //inorder(root); // 20 25 30

    // Forcing a LR-Rotation
    //root = rec_insert(root, 20);
    //rec_insert(root, 25);
    //rec_insert(root, 10);
    //rec_insert(root, 11);
    //rec_insert(root, 5);
    //rec_insert(root, 12);

    //inorder(root); // 5 10 11 12 20 25

    // Forcing a RL-Rotation
    root = rec_insert(root, 20);
    rec_insert(root, 15);
    rec_insert(root, 25);
    rec_insert(root, 24);
    rec_insert(root, 30);
    rec_insert(root, 23);

    inorder(root); // 15 20 23 24 25 30

    return 0;
}
