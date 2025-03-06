#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------





int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    string input;
    
    while (true) {
        cout << "Enter a command \n   1: test llpivot \n   2: test llfilter \n   q: quit " << endl;
        cin >> input;

        if (input == "q") 
        {
            cout << "Quiting" << endl;
            break;
        } 
        else if (input == "1") 
        {
            cout << "------------------------------------------------------------------------" << endl;
            cout << "RUNNING PIVOT" << endl;
            Node* smaller = nullptr;
            Node* larger = nullptr;

            cout << "Enter a number to pivot" << endl;
            int pivot;
            cin >> pivot;

            llpivot(head, smaller, larger, pivot);
            cout << "   Small after running llpivot: ";
            print(smaller);
            cout << "   Large after running llpivot: ";
            print(larger);
            cout << "   Head after running llpivot:";
            print(head); 
            cout << "------------------------------------------------------------------------" << endl;
        } 
        else if (input == "2") 
        {
            cout << "------------------------------------------------------------------------" << endl;
            std::cout << "RUNNING FILTER" << endl;

            head = llfilter(head, [](int val) { return val == 0; }); // even test
            cout << "   Head after running llfilter: ";
            print(head);

            cout << "------------------------------------------------------------------------" << endl;
        } 
        else 
        {
            std::cout << "Invalid input.\n";
        }
        
        // resets head
        head = readList(argv[1]);
    }




    
    return 0;

}
