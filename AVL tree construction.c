#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

/* Node structure */
struct Node {
int data;
struct Node *left;
struct Node *right;
int height;
};

/* Max of two integers */
int max(int a, int b) {
return (a &gt; b) ? a : b;
}

/* Height of node */
int height(struct Node *N) {
if (N == NULL) return 0;
return N-&gt;height;
}

/* Create new node */
struct Node* createNode(int value) {
struct Node* node = (struct Node*)malloc(sizeof(struct Node));
node-&gt;data = value;
node-&gt;left = node-&gt;right = NULL;
node-&gt;height = 1;
return node;

}

/* Right rotate */
struct Node* rightRotate(struct Node *y) {
struct Node *x = y-&gt;left;
struct Node *T2 = x-&gt;right;

x-&gt;right = y;
y-&gt;left = T2;

y-&gt;height = max(height(y-&gt;left), height(y-&gt;right)) + 1;
x-&gt;height = max(height(x-&gt;left), height(x-&gt;right)) + 1;

return x;
}

/* Left rotate */
struct Node* leftRotate(struct Node *x) {
struct Node *y = x-&gt;right;
struct Node *T2 = y-&gt;left;

y-&gt;left = x;
x-&gt;right = T2;

x-&gt;height = max(height(x-&gt;left), height(x-&gt;right)) + 1;
y-&gt;height = max(height(y-&gt;left), height(y-&gt;right)) + 1;

return y;
}

/* Get balance factor */
int getBalance(struct Node *N) {
if (N == NULL) return 0;
return height(N-&gt;left) - height(N-&gt;right);
}

/* Insert node in AVL tree */
struct Node* insertAVL(struct Node* node, int value) {
if (node == NULL) return createNode(value);

if (value &lt; node-&gt;data)
node-&gt;left = insertAVL(node-&gt;left, value);
else if (value &gt; node-&gt;data)
node-&gt;right = insertAVL(node-&gt;right, value);
else
return node; // Duplicate values not allowed

node-&gt;height = 1 + max(height(node-&gt;left), height(node-&gt;right));

int balance = getBalance(node);

// Left Left Case
if (balance &gt; 1 &amp;&amp; value &lt; node-&gt;left-&gt;data)
return rightRotate(node);

// Right Right Case
if (balance &lt; -1 &amp;&amp; value &gt; node-&gt;right-&gt;data)
return leftRotate(node);

// Left Right Case
if (balance &gt; 1 &amp;&amp; value &gt; node-&gt;left-&gt;data) {
node-&gt;left = leftRotate(node-&gt;left);
return rightRotate(node);
}

// Right Left Case
if (balance &lt; -1 &amp;&amp; value &lt; node-&gt;right-&gt;data) {
node-&gt;right = rightRotate(node-&gt;right);
return leftRotate(node);
}

return node;
}

/* Inorder Traversal */
void inorder(struct Node* root) {
if (root != NULL) {
inorder(root-&gt;left);
printf(&quot;%d &quot;, root-&gt;data);
inorder(root-&gt;right);
}
}

/* Main Program */
int main() {
struct Node* root = NULL;
int n, value;

printf(&quot;Enter number of nodes: &quot;);
scanf(&quot;%d&quot;, &amp;n);

for(int i = 0; i &lt; n; i++) {
printf(&quot;Enter node %d: &quot;, i+1);
scanf(&quot;%d&quot;, &amp;value);
root = insertAVL(root, value);
}

printf(&quot;\nInorder Traversal of AVL Tree: &quot;);
inorder(root);
printf(&quot;\n&quot;);

return 0;
}
