#include <iostream>
#include <vector>
#include <string>
#include <array>

// template function
template <typename T>
void swap(T &x, T &y)
{
  T temp = x;
  x = y;
  y = temp;
}
// overloading a templatised function
// templatised for types of arrays [using std::array to avoid 3rd parameter of size]
template<typename T>
void swap(T a[], T b[])
{
  for (int i = 0; i < a.size(); i++)
  {
    T temp = a[i];
    a[i] = b[i];
    b[i] = temp;
  }
}

/* Linked List */

struct Node {
  int value;
  Node* next = NULL;
};

typedef struct {
  Node* head = NULL;
  Node* tail = NULL;
  void insert(Node* node) {
    if (head == NULL){
      head = node;
      tail = node;
    }
    else {
      tail->next = node;
      tail = tail->next;
    }
  }
  //void remove(Node node);
} LinkedList;

std::ostream& operator <<(std::ostream& input, LinkedList list) {
  Node* temp = list.head;
  input << "HEAD -> ";
  while(temp != NULL)
  {
    input << temp->value << " -> ";
    temp = temp->next;
  }
  input << "TAIL";
  return input;
}

int main() {
  Node* temp = new Node();
  temp->value = 10;
  Node* temp1 = new Node();
  temp1->value = 20;

  LinkedList list;
  list.insert(temp);
  list.insert(temp1);
  
  std::cout << list << std::endl;

 // LinkedList list;
//  list.insert(temp);
//  list.insert(temp);
//  list.insert(temp);
  //std::cout << list << std::endl;
  //list.head->value = 10;
  //list.tail->value = 5;
  //Node node;
  //node.value = 10;
  //node.next = nullptr;
  //list.head = &node;
  /*
  // template swap
  int a = 10;
  int b = 20;
  swap(a, b);
  std::cout << a << " " << b << std::endl;
  std::string s = "hello";
  std::string t = "world";
  swap(s, t);
  std::cout << s << " " << t << std::endl;

  std::array<int,5> nines = {9,9,9,9,9};
  std::array<int,5> ones = {1,1,1,1,1};

  for (int i = 0; i < 5; i++)
  {
    std::cout << nines[i] << " " << ones[i] << "\t";
  }
  std::cout << "\n";
  swap(nines, ones);
  for (int i = 0; i < 5; i++)
  {
    std::cout << nines[i] << " " << ones[i] << "\t";
  }
  std::cout << "\n";
*/

  /* List: Arrays */
  int array[10];
  // write
  array[0] = 12;
  // read
//  std::cout << array[0] << std::endl;
  // count
//  std::cout << sizeof(array)/sizeof(*array) << std::endl;
//
  /* List: Vector */
  //std::vector<int> vec;



  return 0;
}

