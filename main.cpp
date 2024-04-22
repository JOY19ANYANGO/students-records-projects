#include<iostream>
using namespace std;
#include <fstream> // For file I/O
#include <cstdlib> // for atexit()

class Node{
    public:
    int key;
    string first_name;
    string last_name;
    Node*next;
    Node(){
        key = 0;
        first_name = "name";
        last_name ="last name";
        next=NULL;
    }
    Node(int k, string d,string l){
        key = k;
        first_name = d;
        last_name=l;
        next = NULL;
    }
};
class Stack{
    public:
    Node*top;
    Stack(){
        top=NULL;
    }
    bool isEmpty(){
        if(top==NULL){
            return true;
        }else{
            return false;
        }
    }
    bool checkIfNodeExist(Node* n){
        Node*temp=top;
        bool exists=false;
        while(temp!=NULL){
            if(temp->key==n->key){
                exists=true;
                break;
            }
            temp=temp->next;
        }
        return exists;
    }
    void push(Node * n) {
        if (top == NULL) {
        top = n;
        cout << "Student added successfully" << endl;
        } else if (checkIfNodeExist(n)) {
        cout << "Student with this registration already exist in the list " <<
        "Enter different registration  number" << endl;
        } else {
        Node * temp = top;
        top = n;
        n -> next = temp;
        cout << "Student added successfully" << endl;
        
        }
    }
    Node * pop() {
        Node * temp = NULL;
        if (isEmpty()) {
        cout << "no student in list" << endl;
        return temp;
        } else {
        temp = top;
        top = top -> next;
        return temp;
        }
    }
    Node * peek() {
        //Node *temp = NULL;
        if (isEmpty()) {
        cout << "no student in list" << endl;
        return NULL;
        } else {
        return top;
        }
    }
    int count() {
        int count = 0;
        Node * temp = top;
        while (temp != NULL) {
        count++;
        temp = temp -> next;
        }
        return count;
        }

void display(){
    
        cout << "All values in the Stack are :" << endl;
        Node * temp = top;
        while (temp != NULL) {
        cout << "(FEE3/" << temp->key << "/2023" ":" << temp->first_name << " " << temp->last_name << ")" << endl;
        temp = temp -> next;
        }
}

void sort() {
    if (isEmpty()) {
        cout << "Stack is empty, nothing to sort." << endl;
        return;
    }
    
    bool sorted = false;
    while (!sorted) {
        Node* current = top;
        Node* prev = nullptr;
        sorted = true; // Assume the stack is sorted

        while (current->next != nullptr) {
            // If current node's key is greater than the next node's key, swap
            if (current->key > current->next->key) {
                sorted = false; // Set sorted to false as swapping is needed

                // Swap the nodes
                Node* temp = current->next;
                current->next = temp->next;
                temp->next = current;
                if (prev == nullptr) {
                    top = temp;
                } else {
                    prev->next = temp;
                }
                prev = temp;
            } else {
                prev = current;
                current = current->next;
            }
        }
    }

    cout << "Stack sorted successfully using bubble sort." << endl;
    display();
}
void binarySearchByKey(int key) {
    sort(); // Assuming this sorts the stack

    int count = 0;
    Node* temp = top;

    // Count the number of nodes in the stack
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    // Initialize search range
    int left = 0;
    int right = count - 1;

    // Binary search
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Traverse mid nodes to find the key
        temp = top;
        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }

        // If key is found, print its position
        if (temp->key == key) {
            cout << "Student found at position " << mid +1<< endl;
            return; // Exit the function once the key is found
        } else if (temp->key < key) {
            // Move the left boundary to the right
            left = mid + 1;
        } else {
            // Move the right boundary to the left
            right = mid - 1;
        }
    }

    // Key not found
    cout << "Student not found" << endl;
}



};

void saveToFile(Stack &s) {
    ofstream outfile("stack_data.txt", ios::out);

    if (!outfile) {
        cerr << "Error: File could not be opened for writing!" << endl;
        return;
    }

    Node *temp = s.top;
    while (temp != nullptr) {
        outfile << temp->key << " " << temp->first_name << " " << temp->last_name << endl;
        temp = temp->next;
    }

    outfile.close();
}

void loadFromFile(Stack &s) {
    ifstream infile("stack_data.txt", ios::in);

    if (!infile) {
        cerr << "Error: File could not be opened for reading!" << endl;
        return;
    }

    int key;
    string first_name, last_name;
    while (infile >> key >> first_name >> last_name) {
        Node *new_node = new Node(key, first_name, last_name);
        s.push(new_node);
    }

    infile.close();
}
static Stack s1; // Declare s1 as static variable

void saveOnExit() {
    saveToFile(s1);
}





    

int main() {
   
    loadFromFile(s1); // Load previously saved data

    int option, key ;
    string first_name;
    string last_name;
    do {
    cout << "What operation do you want to perform?" <<
    "Select Option number. Enter 0 to exit." << endl;
    cout << "1.Add student to the list : Push()" << endl;
    cout << "2.Remove top student from the list : Pop()" << endl;
    cout << "3.Check if the list is empty : isEmpty()" << endl;
    cout << "4.Check the top stundent from the list: peek()" << endl;
    cout << "5.See the total number of students : count()" << endl;
    cout << "6.Display all the students in the list : display()" << endl;
    cout<< "7.Sort the names of the students according to registration number(ascending order)"<<endl;
    cout<<"8.Search for a student using registration number..."<<endl;
    cout << "9. Clear Screen" << endl << endl;
    cin >> option;
    //Node n1 = new Node();
    Node * new_node = new Node();
    switch (option) {
    case 0:
    break;
    case 1:
    cout << "Enter registration number of the student to add in the list" <<
    endl;
    cin >> key;
    cout << "Enter name of the student to add in the list" <<
    endl;
    cin>>first_name ;
    cin >> last_name;
    new_node -> key = key;
    new_node -> first_name= first_name;
    new_node -> last_name= last_name;
    s1.push(new_node);
    break;
    case 2:
    cout << "Pop Function Called - Poped Value: " << endl;
        new_node = s1.pop();
    cout << "Student at the top of the list is: (""FEE3/"<< new_node -> key <<"/2023" ":" <<
    new_node -> first_name<<" "<< new_node -> last_name<<")";
    delete new_node;
    cout << endl;
    break;
    case 3:
    if (s1.isEmpty())
    cout << "Student list is Empty" << endl;
    else
    cout << "Student list is not Empty" << endl;
    break;
    case 4:
    if (s1.isEmpty()) {
    cout << "Student list is Empty" << endl;
    } else {
    cout << "PEEK Function Called : " << endl;
    new_node = s1.peek();
    cout << "Student at the top of the list: (""FEE3/"<< new_node -> key <<"/2023" ":" << new_node -> first_name<<" " <<new_node -> last_name<<")" <<endl;
    }
    break;
    case 5:
    cout << "Count Function Called: " << endl;
    cout << "No if the student in the list: " << s1.count() << endl;
    break;
    case 6:
    cout << "Display Function Called - " << endl;
    s1.display();
    cout << endl;
    break;
    case 7:
    cout << "Sorting the stack..." << endl;
    s1.sort();
    cout << "Sorting completed." << endl;
    break;
   case 8:
    cout << "Enter the registration number to search: ";
    cin >> key;
     s1.binarySearchByKey(key);
    
    break;

    case 9:
    system("cls");
    break;
    default:
    cout << "Enter Proper Option number " << endl;
    }
     atexit(saveOnExit); // Save data before exiting
    } while (option != 0);
    return 0;
}