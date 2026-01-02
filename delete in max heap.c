#include &lt;stdio.h&gt;

#define MAX 100

int heap[MAX];
int size = 0;

/* Swap two elements */
void swap(int *a, int *b) {
int temp = *a;
*a = *b;
*b = temp;
}

/* Heapify down (maintain max heap) */
void heapifyDown(int index) {
int largest = index;
int left = 2*index + 1;
int right = 2*index + 2;

if(left &lt; size &amp;&amp; heap[left] &gt; heap[largest])
largest = left;
if(right &lt; size &amp;&amp; heap[right] &gt; heap[largest])
largest = right;

if(largest != index) {
swap(&amp;heap[index], &amp;heap[largest]);
heapifyDown(largest);
}

}

/* Insert node into Max Heap */
void insertHeap(int value) {
if(size &gt;= MAX) {
printf(&quot;Heap is full!\n&quot;);
return;
}
int i = size;
heap[size++] = value;

/* Heapify up */
while(i != 0 &amp;&amp; heap[i] &gt; heap[(i-1)/2]) {
swap(&amp;heap[i], &amp;heap[(i-1)/2]);
i = (i-1)/2;
}
}

/* Delete max element */
void deleteMax() {
if(size &lt;= 0) {
printf(&quot;Heap is empty!\n&quot;);
return;
}

printf(&quot;Deleting max element: %d\n&quot;, heap[0]);
heap[0] = heap[size-1]; // Move last element to root
size--; // Reduce heap size
heapifyDown(0); // Restore max heap property

}

/* Display Heap */
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
printf(&quot;2. Delete Max\n&quot;);
printf(&quot;3. Display Heap\n&quot;);
printf(&quot;4. Exit\n&quot;);
printf(&quot;Enter choice: &quot;);
scanf(&quot;%d&quot;, &amp;choice);

switch(choice) {
case 1:

printf(&quot;Enter value to insert: &quot;);
scanf(&quot;%d&quot;, &amp;value);
insertHeap(value);
break;
case 2:
deleteMax();
break;
case 3:
displayHeap();
break;
case 4:
return 0;
default:
printf(&quot;Invalid choice!\n&quot;);
}
}
}
