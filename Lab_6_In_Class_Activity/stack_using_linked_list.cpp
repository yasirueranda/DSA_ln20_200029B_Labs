#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
struct Node {
   int data;
   struct Node *next;
};
struct Node* top = NULL;
void push(int val) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->data = val;
   newnode->next = top;
   top = newnode;
}
void pop() {
   if(top==NULL)
   cout<<"Stack Underflow"<<endl;
   else {
      cout<<"popped "<< top->data <<endl;
      top = top->next;
   }
}
void display() {
   struct Node* ptr;
   if(top==NULL)
   cout<<"stack is empty";
   else {
      ptr = top;
      while (ptr != NULL) {
         cout<< ptr->data <<" ";
         ptr = ptr->next;
      }
   }
   cout<<endl;
}
int main() {

   auto start=high_resolution_clock::now();
   push(8);
   push(10);
   push(5);
   push(11);
   push(15);
   push(23);
   push(6);
   push(18);
   push(20);
   push(17);
   display();
   pop();
   pop();
   pop();
   pop();
   pop();
   display();
   push(4);
   push(30);
   push(3);
   push(1);
   display();
   auto stop=high_resolution_clock::now();
   auto duration=duration_cast<microseconds>(stop - start);
   cout << "Time taken to perform is "<< duration.count() << " in microseconds" << endl;

   return 0;
}
