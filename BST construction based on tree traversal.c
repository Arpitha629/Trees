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

/* Find index of value in array */
int search(int arr[], int start, int end, int value) {
for(int i = start; i &lt;= end; i++) {
if(arr[i] == value) return i;
}
return -1;
}

/* Construct tree from Preorder + Inorder */
struct Node* buildTreePreIn(int inorder[], int preorder[], int inStart, int inEnd, int
*preIndex) {
if(inStart &gt; inEnd) return NULL;

int curr = preorder[*preIndex];
(*preIndex)++;
struct Node* node = createNode(curr);

if(inStart == inEnd) return node;

int inIndex = search(inorder, inStart, inEnd, curr);

node-&gt;left = buildTreePreIn(inorder, preorder, inStart, inIndex - 1, preIndex);
node-&gt;right = buildTreePreIn(inorder, preorder, inIndex + 1, inEnd, preIndex);

return node;
}

/* Construct tree from Postorder + Inorder */
struct Node* buildTreePostIn(int inorder[], int postorder[], int inStart, int inEnd, int
*postIndex) {
if(inStart &gt; inEnd) return NULL;

int curr = postorder[*postIndex];
(*postIndex)--;
struct Node* node = createNode(curr);

if(inStart == inEnd) return node;

int inIndex = search(inorder, inStart, inEnd, curr);

// Important: construct right subtree first for postorder

node-&gt;right = buildTreePostIn(inorder, postorder, inIndex + 1, inEnd, postIndex);
node-&gt;left = buildTreePostIn(inorder, postorder, inStart, inIndex - 1, postIndex);

return node;
}

/* Traversals */
void inorderTraversal(struct Node* root) {
if(root != NULL) {
inorderTraversal(root-&gt;left);
printf(&quot;%d &quot;, root-&gt;data);
inorderTraversal(root-&gt;right);
}
}

void preorderTraversal(struct Node* root) {
if(root != NULL) {
printf(&quot;%d &quot;, root-&gt;data);
preorderTraversal(root-&gt;left);
preorderTraversal(root-&gt;right);
}
}

void postorderTraversal(struct Node* root) {
if(root != NULL) {
postorderTraversal(root-&gt;left);
postorderTraversal(root-&gt;right);
printf(&quot;%d &quot;, root-&gt;data);
}

}

int main() {
int n, choice;
printf(&quot;Enter number of nodes: &quot;);
scanf(&quot;%d&quot;, &amp;n);

int inorder[n], preorder[n], postorder[n];

printf(&quot;\nChoose type of input to construct BST:\n&quot;);
printf(&quot;1. Preorder + Inorder\n&quot;);
printf(&quot;2. Postorder + Inorder\n&quot;);
printf(&quot;Enter choice: &quot;);
scanf(&quot;%d&quot;, &amp;choice);

if(choice == 1) {
printf(&quot;Enter Inorder traversal: &quot;);
for(int i=0;i&lt;n;i++) scanf(&quot;%d&quot;,&amp;inorder[i]);
printf(&quot;Enter Preorder traversal: &quot;);
for(int i=0;i&lt;n;i++) scanf(&quot;%d&quot;,&amp;preorder[i]);

int preIndex = 0;
struct Node* root = buildTreePreIn(inorder, preorder, 0, n-1, &amp;preIndex);

printf(&quot;\nConstructed Tree Traversals:\n&quot;);
printf(&quot;Inorder : &quot;); inorderTraversal(root); printf(&quot;\n&quot;);
printf(&quot;Preorder : &quot;); preorderTraversal(root); printf(&quot;\n&quot;);
printf(&quot;Postorder: &quot;); postorderTraversal(root); printf(&quot;\n&quot;);
}

else if(choice == 2) {
printf(&quot;Enter Inorder traversal: &quot;);
for(int i=0;i&lt;n;i++) scanf(&quot;%d&quot;,&amp;inorder[i]);
printf(&quot;Enter Postorder traversal: &quot;);
for(int i=0;i&lt;n;i++) scanf(&quot;%d&quot;,&amp;postorder[i]);

int postIndex = n-1;
struct Node* root = buildTreePostIn(inorder, postorder, 0, n-1, &amp;postIndex);

printf(&quot;\nConstructed Tree Traversals:\n&quot;);
printf(&quot;Inorder : &quot;); inorderTraversal(root); printf(&quot;\n&quot;);
printf(&quot;Preorder : &quot;); preorderTraversal(root); printf(&quot;\n&quot;);
printf(&quot;Postorder: &quot;); postorderTraversal(root); printf(&quot;\n&quot;);
}
else {
printf(&quot;Invalid choice!&quot;);
}

return 0;
}
