#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

/* Node structure */
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

/* Insert node into BST */
struct Node* insert(struct Node* root, int value) {
if (root == NULL)
return createNode(value);
if (value &lt; root-&gt;data)
root-&gt;left = insert(root-&gt;left, value);
else if (value &gt; root-&gt;data)
root-&gt;right = insert(root-&gt;right, value);
return root;
}

/* Search element in BST */

int search(struct Node* root, int key) {
if (root == NULL) return 0;
if (root-&gt;data == key) return 1;
else if (key &lt; root-&gt;data)
return search(root-&gt;left, key);
else
return search(root-&gt;right, key);
}

/* Find height of tree */
int height(struct Node* root) {
if (root == NULL) return -1; // height of empty tree = -1
int leftHeight = height(root-&gt;left);
int rightHeight = height(root-&gt;right);
return (leftHeight &gt; rightHeight ? leftHeight : rightHeight) + 1;
}

/* Count total nodes */
int countNodes(struct Node* root) {
if (root == NULL) return 0;
return 1 + countNodes(root-&gt;left) + countNodes(root-&gt;right);
}

/* Count leaf nodes */
int countLeafNodes(struct Node* root) {
if (root == NULL) return 0;
if (root-&gt;left == NULL &amp;&amp; root-&gt;right == NULL) return 1;
return countLeafNodes(root-&gt;left) + countLeafNodes(root-&gt;right);
}

/* Main Menu */
int main() {
struct Node* root = NULL;
int choice, value;

while (1) {
printf(&quot;\n\n--- TREE OPERATIONS ---&quot;);
printf(&quot;\n1. Insert Node&quot;);
printf(&quot;\n2. Search Element&quot;);
printf(&quot;\n3. Find Height of Tree&quot;);
printf(&quot;\n4. Count Total Nodes&quot;);
printf(&quot;\n5. Count Leaf Nodes&quot;);
printf(&quot;\n6. Exit&quot;);
printf(&quot;\nEnter your choice: &quot;);
scanf(&quot;%d&quot;, &amp;choice);

switch(choice) {
case 1:
printf(&quot;Enter value to insert: &quot;);
scanf(&quot;%d&quot;, &amp;value);
root = insert(root, value);
break;
case 2:
printf(&quot;Enter element to search: &quot;);
scanf(&quot;%d&quot;, &amp;value);
if (search(root, value))
printf(&quot;Element FOUND&quot;);
else

printf(&quot;Element NOT FOUND&quot;);
break;
case 3:
printf(&quot;Height of tree: %d&quot;, height(root));
break;
case 4:
printf(&quot;Total nodes: %d&quot;, countNodes(root));
break;
case 5:
printf(&quot;Leaf nodes: %d&quot;, countLeafNodes(root));
break;
case 6:
exit(0);
default:
printf(&quot;Invalid choice!&quot;);
}
}

return 0;
}
