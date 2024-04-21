
using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int data) : data(data), next(nullptr) {}

} int main() {

  Node a = new Node(4);
  cout << a.next << endl;
  return 0;
}