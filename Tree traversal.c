#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

/* Structure of a tree node */
struct Node {
int data;
struct Node *left, *right;
};

/* Create a new node */
struct Node* createNode(int value) {
struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
temp-&gt;data = value;
temp-&gt;left = temp-&gt;right = NULL;
return temp;
}

/* Inorder Traversal (Left → Root → Right) */
void inorder(struct Node* root) {
if (root != NULL) {
inorder(root-&gt;left);
printf(&quot;%d &quot;, root-&gt;data);
inorder(root-&gt;right);
}
}

/* Preorder Traversal (Root → Left → Right) */
void preorder(struct Node* root) {
if (root != NULL) {

printf(&quot;%d &quot;, root-&gt;data);
preorder(root-&gt;left);
preorder(root-&gt;right);
}
}

/* Postorder Traversal (Left → Right → Root) */
void postorder(struct Node* root) {
if (root != NULL) {
postorder(root-&gt;left);
postorder(root-&gt;right);
printf(&quot;%d &quot;, root-&gt;data);
}
}

/* Main Function */
int main() {
/*
1
/ \
2 3
/ \
4 5
*/

struct Node* root = createNode(1);
root-&gt;left = createNode(2);
root-&gt;right = createNode(3);
root-&gt;left-&gt;left = createNode(4);

root-&gt;left-&gt;right = createNode(5);

printf(&quot;Inorder Traversal : &quot;);
inorder(root);

printf(&quot;\nPreorder Traversal : &quot;);
preorder(root);

printf(&quot;\nPostorder Traversal : &quot;);
postorder(root);

return 0;
}
