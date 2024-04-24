#include<iostream>
using namespace std;
#include <fstream> // For file I/O
#include <cstdlib> // for atexit()
#include <iomanip> // Include the <iomanip> header for setw





class Node{
public:
    int key;
    string first_name;
    string last_name;
    char gender;
    int age;
    int marks_FEE3132;
    int marks_FEE3162;
    int marks_FMM3152;
    int marks_SMA3112;
    int marks_SMA3122;
    int marks_SPH3108;
    int marks_FEE3131;
    int marks_FEE3161;
    int marks_SPH3107;
    int marks_SMA3113;
    int marks_SMA3121;
    float totalMarks;
    char grade;
    float average;


    Node* next;
    
    Node(){
        key = 0;
        first_name = "name";
        last_name = "last name";
        gender = ' ';
        age = 0;
        marks_FEE3132 = 0;
        marks_FEE3162 = 0;
        marks_FMM3152 = 0;
        marks_SMA3112 = 0;
        marks_SMA3122 = 0;
        marks_SPH3108 = 0;
        marks_FEE3131 = 0;
        marks_FEE3161 = 0;
        marks_SMA3113 = 0;
        marks_SMA3121 = 0;
        marks_SPH3107 = 0;

        next = NULL;
    }
    
    Node(int k, string d, string l, char g, int a, int m_FEE3132, int m_FEE3162, int m_FMM3152, int m_SMA3112, int m_SMA3122, int m_SPH3108,int m_FEE3131, int m_FEE3161,  int m_SMA3113, int m_SMA3121, int m_SPH3107){
        key = k;
        first_name = d;
        last_name = l;
        gender = g;
        age = a;
        marks_FEE3132 = m_FEE3132;
        marks_FEE3162 = m_FEE3162;
        marks_FMM3152 = m_FMM3152;
        marks_SMA3112 = m_SMA3112;
        marks_SMA3122 = m_SMA3122;
        marks_SPH3108 = m_SPH3108;
        marks_FEE3131 = m_FEE3131;
        marks_FEE3161 = m_FEE3161;
        marks_SMA3113 = m_SMA3113;
        marks_SMA3121 = m_SMA3112;
        marks_SPH3107 = m_SPH3107;
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


void display() {
    // Define the column headers
    cout << "========================================================================" << endl;
    cout << "| Key | Age | Gender | Name     | FEE3132 | FEE3162 | FMM3152 | SMA3112 | SMA3122 | SPH3108 | FEE3131| FEE3161 |  SMA3113 | SMA3121 | SPH3107 |" << endl;
    cout << "========================================================================" << endl;

    Node* temp = top;
    while (temp != nullptr) {
        // Limit the length of the name to fit within 15 characters
        string truncated_name = temp->first_name + " " + temp->last_name;
        if (truncated_name.length() > 15) {
            truncated_name = truncated_name.substr(0, 12) + "...";
        }

        // Output the student information with adjusted formatting
        cout << "| " << setw(3) << temp->key << " | " << setw(1) << temp->age << " | " << setw(1) << temp->gender << " | "
             << setw(10) << left << truncated_name << " | "
             << setw(1) << temp->marks_FEE3132 << " | "
             << setw(1) << temp->marks_FEE3162 << " | "
             << setw(1) << temp->marks_FMM3152 << " | "
             << setw(1) << temp->marks_SMA3112 << " | "
             << setw(1) << temp->marks_SMA3122 << " | "
             << setw(1) << temp->marks_SPH3108 << " | " 
             << setw(1) << temp->marks_FEE3131 << " | "
             << setw(1) << temp->marks_FEE3161 << " | "
             << setw(1) << temp->marks_SMA3113 << " | "
             << setw(1) << temp->marks_SMA3121 << " | "
             << setw(1) << temp->marks_SPH3107 << " | " << endl;

        temp = temp->next;
    }
    cout << "========================================================================" << endl;
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
        outfile << temp->key << " " << temp->first_name << " " << temp->last_name << " "
                << temp->gender << " " << temp->age << " "
                << temp->marks_FEE3132 << " " << temp->marks_FEE3162 << " "
                << temp->marks_FMM3152 << " " << temp->marks_SMA3112 << " "
                << temp->marks_SMA3122 << " " << temp->marks_SPH3108 << " "
                << temp->marks_FEE3131 << " " << temp->marks_FEE3161 << " "
                << temp->marks_SMA3113 << " "
                << temp->marks_SMA3121 << " " << temp->marks_SPH3107 << endl;
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
    char gender;
    int age;
    int marks_FEE3132, marks_FEE3162, marks_FMM3152, marks_SMA3112, marks_SMA3122, marks_SPH3108;
    int marks_FEE3131, marks_FEE3161,  marks_SMA3113, marks_SMA3121, marks_SPH3107;
    while (infile >> key >> first_name >> last_name >> gender >> age
                 >> marks_FEE3132 >> marks_FEE3162 >> marks_FMM3152
                 >> marks_SMA3112 >> marks_SMA3122 >> marks_SPH3108
                 >> marks_FEE3131 >> marks_FEE3161 
                 >> marks_SMA3113 >> marks_SMA3121 >> marks_SPH3107) {
       Node* new_node = new Node(key, first_name, last_name, gender, age,
                              marks_FEE3132, marks_FEE3162, marks_FMM3152,
                              marks_SMA3112, marks_SMA3122, marks_SPH3108,marks_FEE3131, marks_FEE3161, 
                              marks_SMA3113, marks_SMA3121, marks_SPH3107);
        new_node->marks_FEE3132 = marks_FEE3132;
        new_node->marks_FEE3162 = marks_FEE3162;
        new_node->marks_FMM3152 = marks_FMM3152;
        new_node->marks_SMA3112 = marks_SMA3112;
        new_node->marks_SMA3122 = marks_SMA3122;
        new_node->marks_SPH3108 = marks_SPH3108;
        new_node->marks_FEE3131 = marks_FEE3131;
        new_node->marks_FEE3161 = marks_FEE3161;
        new_node->marks_SMA3113 = marks_SMA3113;
        new_node->marks_SMA3121 = marks_SMA3121;
        new_node->marks_SPH3107 = marks_SPH3107;
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

    int option, key ,age;
    string first_name;
    string last_name;
    char gender;

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
                cout << "Enter registration number of the student to add in the list" << endl;
                cin >> key;
                cout << "Enter name of the student to add in the list" << endl;
                cin >> first_name;
                cin >> last_name;
                cout << "Enter the gender of the student to add in the list('M' or 'F')" << endl;
                cin >> gender;
                cout << "Enter the age of the student to add in the list" << endl;
                cin >> age;
                cout << "Enter marks for FEE3132: ";
                int marks_FEE3132;
                cin >> marks_FEE3132;
                cout << "Enter marks for FEE3162: ";
                int marks_FEE3162;
                cin >> marks_FEE3162;
                cout << "Enter marks for FMM3152: ";
                int marks_FMM3152;
                cin >> marks_FMM3152;
                cout << "Enter marks for SMA3112: ";
                int marks_SMA3112;
                cin >> marks_SMA3112;
                cout << "Enter marks for SMA3122: ";
                int marks_SMA3122;
                cin >> marks_SMA3122;
                cout << "Enter marks for SPH3108: ";
                int marks_SPH3108;
                cin >> marks_SPH3108;
                cout << "Enter marks for FEE3131: ";
                int marks_FEE3131;
                cin >> marks_FEE3131;
                cout << "Enter marks for FEE3161: ";
                int marks_FEE3161;
                cin >> marks_FEE3161;
                
                cout << "Enter marks for SMA3113: ";
                int marks_SMA3113;
                cin >> marks_SMA3113;
                cout << "Enter marks for SMA3121: ";
                int marks_SMA3121;
                cin >> marks_SMA3121;
                cout << "Enter marks for SPH3107: ";
                int marks_SPH3107;
                cin >> marks_SPH3107;

                new_node->key = key;
                new_node->first_name = first_name;
                new_node->last_name = last_name;
                new_node->gender = gender;
                new_node->age = age;
                new_node->marks_FEE3132 = marks_FEE3132;
                new_node->marks_FEE3162 = marks_FEE3162;
                new_node->marks_FMM3152 = marks_FMM3152;
                new_node->marks_SMA3112 = marks_SMA3112;
                new_node->marks_SMA3122 = marks_SMA3122;
                new_node->marks_SPH3108 = marks_SPH3108;
                new_node->marks_FEE3131 = marks_FEE3131;
                new_node->marks_FEE3161 = marks_FEE3161;
                new_node->marks_SMA3113 = marks_SMA3113;
                new_node->marks_SMA3121 = marks_SMA3121;
                new_node->marks_SPH3107 = marks_SPH3107;

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