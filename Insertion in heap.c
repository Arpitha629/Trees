#include &lt;stdio.h&gt;

#define MAX 100

int heap[MAX];
int size = 0;

/* Function to swap two integers */
void swap(int *a, int *b) {
int temp = *a;
*a = *b;
*b = temp;
}

/* Heapify up (maintain max heap property) */
void heapifyUp(int index) {
int parent = (index - 1) / 2;
if(index &gt; 0 &amp;&amp; heap[index] &gt; heap[parent]) {
swap(&amp;heap[index], &amp;heap[parent]);
heapifyUp(parent);
}
}

/* Insert node into Max Heap */
void insertHeap(int value) {
if(size &gt;= MAX) {
printf(&quot;Heap is full! Cannot insert.\n&quot;);
return;
}

printf(&quot;Inserting %d into the heap...\n&quot;, value);
heap[size] = value; // insert at the end
heapifyUp(size); // maintain heap property
size++;
}

/* Display Heap as array */
void displayHeap() {
if(size == 0) {
printf(&quot;Heap is empty!\n&quot;);
return;
}
printf(&quot;Heap elements: &quot;);
for(int i = 0; i &lt; size; i++)
printf(&quot;%d &quot;, heap[i]);
printf(&quot;\n&quot;);
}

/* Main program */
int main() {
int choice, value;

while(1) {
printf(&quot;\n--- MAX HEAP OPERATIONS ---\n&quot;);
printf(&quot;1. Insert Node\n&quot;);
printf(&quot;2. Display Heap\n&quot;);
printf(&quot;3. Exit\n&quot;);
printf(&quot;Enter choice: &quot;);

scanf(&quot;%d&quot;, &amp;choice);

switch(choice) {
case 1:
printf(&quot;Enter value to insert: &quot;);
scanf(&quot;%d&quot;, &amp;value);
insertHeap(value);
break;
case 2:
displayHeap();
break;
case 3:
return 0;
default:
printf(&quot;Invalid choice!\n&quot;);
}
}

return 0;
}
