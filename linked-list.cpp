#include <iostream>
using namespace std;

struct Node
{
    int data;   // value
    Node *next; // pointer to next node
};
Node *head = NULL; // head doesn't point at anything (yet)

void insertNode(int value);

void display();

void deleteNode(int value); // delete by value

void insert_begging(int value);

void delete_first_node();

void delete_last_node();
int main()
{

    insertNode(2);

    insertNode(23);

    insert_begging(44);
    insertNode(24);

    insert_begging(15151);

    insertNode(25);

    delete_first_node();
    delete_last_node();
    display();

    return 0;
}

void insertNode(int value)
{
    Node *last;
    Node *newNode = new Node; // createing a new node with no name but have address in memory

    newNode->data = value; // give it a value

    if (head == NULL)
    { // if it's  the first node

        head = newNode;

        newNode->next = NULL;
    }
    else
    { // it's not  the first node
        last = head;
        // last equal the first node and last->next points at the node after it so if last is not the last node
        //  we reassign  it to be the node after it by last = last->next and do that over and over until we find that
        //  last->next == NULL that mean last is the last node so we insert the newNode after the last node
        while (last->next != NULL)
        {

            last = last->next;
        }
        last->next = newNode;

        newNode->next = NULL;
    }
}
//// second part

void display()
{
    Node *temp = head;
    int count = 0;
    if (temp == NULL)
    {
        cout << "there is no Elements";
    }
    else
    {
        cout << "The Elements are: " << endl;
        while (temp != NULL)
        {
            count++;
            cout << count << "- ";
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    cout << endl;
};
/// therid part (delete Node )
// first : make two pointers to the (temp , prev) and make them both points at the head (first node)

// second : check if the value you want to delete in the first node if Yes >> make the head point at the second node by head = temp->next;

// Third : if not at the first one >> we loop until we find that temp->data == the value we want to delete
// to make that happen every time the temp->data is not the value we want to delete we make the prev point at the temp node then make the temp node point at the node after it by temp = tem->next

// forth : when we find it we make the  prev->next = temp->next then free the temp

// Ex: for forth one we found the node we want ot delete in node number 4
// so now the (temp in fourth node) and (temp->next in the fifth node) and ( prev in node number 3) and (prev->next in fourth same as  temp)
// what we want to do is to delete the temp(fourth node) and link the third node with the fifth
// so  we link the third node with the fifth node  by makeing  prev->next == temp->next (the fifth node)
// now prev is the third node and prev->next point at the fifth node now we free the temp(fourth Node)

void deleteNode(int value)
{
    Node *temp = head;
    Node *prev = head;

    if (temp->data == value)
    {
        head = temp->next;
        delete (temp);
        return;
    }
    else
    {

        while (temp->data != value)
        {

            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        delete (temp);
    }
}
// forth part add at the beginning

// first : make new node and give it a value
// second : make newNode point at head (head was pointing at the first node so now the newNode point at the old first node that make newNode the new first node and the old first will be the second node )
// third : make the head point at the the new node(new first node )

void insert_begging(int value)
{
    Node *newNode = new Node; // 1
    newNode->data = value;    // 1
    newNode->next = head;     // 2
    head = newNode;           // 3
}

// fifth part delete_first_node

// first :check if list is empty first
// second :make newNode that points at the head
// third : make the head point at the the second node by newNode->next
// then delete the newNode
void delete_first_node()
{

    if (head == NULL)
    {
        cout << "The list is empty!" << endl;
        return;
    }
    else
    {
        Node *FirstNode = head;
        head = FirstNode->next;
        delete (FirstNode);
    }
}

void delete_last_node()
{
    if (head == NULL)
    {
        cout << "There is nothing to delete!" << endl;
    }
    else if(head->next == NULL)
    {
        delete (head->next);
        head= NULL;
    }else {
        Node *ptr = head ;
        while(ptr->next->next != NULL) {
            ptr = ptr->next;
        }
        delete (ptr->next->next);
        ptr->next = NULL ;
    }
}