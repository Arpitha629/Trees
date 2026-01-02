#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

#define RED 1
#define BLACK 0

struct Node {
int data;
int color;
struct Node *left, *right, *parent;
};

struct Node *root = NULL;

// Create new node
struct Node* newNode(int data) {
struct Node* node = (struct Node*)malloc(sizeof(struct Node));
node-&gt;data = data;
node-&gt;color = RED; // New node is always RED
node-&gt;left = node-&gt;right = node-&gt;parent = NULL;
return node;
}

// Left Rotate
void leftRotate(struct Node *x) {
struct Node *y = x-&gt;right;
x-&gt;right = y-&gt;left;

if (y-&gt;left != NULL)

y-&gt;left-&gt;parent = x;

y-&gt;parent = x-&gt;parent;

if (x-&gt;parent == NULL)
root = y;
else if (x == x-&gt;parent-&gt;left)
x-&gt;parent-&gt;left = y;
else
x-&gt;parent-&gt;right = y;

y-&gt;left = x;
x-&gt;parent = y;
}

// Right Rotate
void rightRotate(struct Node *y) {
struct Node *x = y-&gt;left;
y-&gt;left = x-&gt;right;

if (x-&gt;right != NULL)
x-&gt;right-&gt;parent = y;

x-&gt;parent = y-&gt;parent;

if (y-&gt;parent == NULL)
root = x;
else if (y == y-&gt;parent-&gt;left)
y-&gt;parent-&gt;left = x;

else
y-&gt;parent-&gt;right = x;

x-&gt;right = y;
y-&gt;parent = x;
}

// Fix Red-Black Tree violations
void fixViolation(struct Node *z) {
while (z != root &amp;&amp; z-&gt;parent-&gt;color == RED) {
if (z-&gt;parent == z-&gt;parent-&gt;parent-&gt;left) {
struct Node *uncle = z-&gt;parent-&gt;parent-&gt;right;

// Case 1: Uncle is RED
if (uncle != NULL &amp;&amp; uncle-&gt;color == RED) {
z-&gt;parent-&gt;color = BLACK;
uncle-&gt;color = BLACK;
z-&gt;parent-&gt;parent-&gt;color = RED;
z = z-&gt;parent-&gt;parent;
}
// Case 2 &amp; 3
else {
if (z == z-&gt;parent-&gt;right) {
z = z-&gt;parent;
leftRotate(z);
}
z-&gt;parent-&gt;color = BLACK;
z-&gt;parent-&gt;parent-&gt;color = RED;
rightRotate(z-&gt;parent-&gt;parent);

}
}
// Mirror cases
else {
struct Node *uncle = z-&gt;parent-&gt;parent-&gt;left;

if (uncle != NULL &amp;&amp; uncle-&gt;color == RED) {
z-&gt;parent-&gt;color = BLACK;
uncle-&gt;color = BLACK;
z-&gt;parent-&gt;parent-&gt;color = RED;
z = z-&gt;parent-&gt;parent;
}
else {
if (z == z-&gt;parent-&gt;left) {
z = z-&gt;parent;
rightRotate(z);
}
z-&gt;parent-&gt;color = BLACK;
z-&gt;parent-&gt;parent-&gt;color = RED;
leftRotate(z-&gt;parent-&gt;parent);
}
}
}
root-&gt;color = BLACK;
}

// Insert into Red-Black Tree
void insert(int data) {
struct Node *z = newNode(data);

struct Node *y = NULL;
struct Node *x = root;

while (x != NULL) {
y = x;
if (z-&gt;data &lt; x-&gt;data)
x = x-&gt;left;
else
x = x-&gt;right;
}

z-&gt;parent = y;

if (y == NULL)
root = z;
else if (z-&gt;data &lt; y-&gt;data)
y-&gt;left = z;
else
y-&gt;right = z;

fixViolation(z);
}

// Inorder traversal with colors
void inorder(struct Node *root) {
if (root != NULL) {
inorder(root-&gt;left);
printf(&quot;%d(%s) &quot;, root-&gt;data,
root-&gt;color == RED ? &quot;R&quot; : &quot;B&quot;);

inorder(root-&gt;right);
}
}

// Main function
int main() {
int n, val;

printf(&quot;Enter number of nodes: &quot;);
scanf(&quot;%d&quot;, &amp;n);

printf(&quot;Enter values:\n&quot;);
for (int i = 0; i &lt; n; i++) {
scanf(&quot;%d&quot;, &amp;val);
insert(val);
}

printf(&quot;Inorder traversal (with colors):\n&quot;);
inorder(root);

return 0;
}
