// linkedlistdeletef.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdlib.h>

using namespace std;
class node
{
public:
    int data;
    node* next;
};
void input(node** head)
{
    node* newnode = NULL;
    node* temp = NULL;
    int choice = 1;

    cout << "to create a linkelist we need nodes" << endl;

    while (choice)
    {
        cout << "enter the node" << endl;
        newnode = new node();
        //temp = newnode;
        cin >> newnode->data;
        newnode->next = NULL;
        if (*head == NULL)
        {
            *head = newnode;
            // head and temp point towards newnode
        }
        else
        {
            temp->next = newnode;

        }
        temp = newnode;
        cout << "enter 1 to enter other node, else 0" << endl;
        cin >> choice;
    }
}
void output(node* head)
{

    while (head != NULL)
    {
        cout << (head)->data << endl;
        head = (head)->next;
    }
}

void addbeg(node** head, int dat1)
{
    node* newnode = NULL;

    newnode = new node();
    //cout << "enter the new node to add at begining " << endl;

    //cin >> dat1;
    newnode->data = dat1;
    newnode->next = *head;
    *head = newnode;
    cout << "after entering the first node, the output is" << endl;
    output(*head);

}

void addend(node** head, int dat2)
{
    node* newnode = new node();
    node* temp = NULL;
    temp = *head;
    newnode->data = dat2;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
    cout << "after entering the last node, the output is" << endl;
    output(*head);


}

void addpos(node** head, int pos1, int dat3)
{
    node* newnode = new node();
    int i = 2;
    node* temp = NULL;
    temp = *head;
    newnode->data = dat3;
    if (pos1 == 1)
    {
        newnode->next = *head;
        *head = newnode;
    }
    else
    {
        while (i < pos1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;

    }
    cout << "after entering the node at specific position, the output is" << endl;
    output(*head);

}

void delbeg(node** head)
{
    node* temp = *head;
    *head = (*head)->next;
    cout << "after deleting the first node i.e." << (temp)->data << ", the output is" << endl;
    free(temp);
    output(*head);

}

void delend(node** head)
{
    node* temp = *head;
    node* prevnode = NULL;
    while (temp->next != NULL)
    {
        prevnode = temp;
        temp = temp->next;
    }
    cout << "after deleting the last node i.e." << (temp)->data << ", the output is" << endl;
    prevnode->next = NULL;
    free(temp);
    output(*head);

}
void delpos(node** head, int pos2)
{
    int i = 1;
    node* temp = *head;
    node* nextnode = NULL;
    if (pos2 == 1)
    {
        delbeg(&(*head));

    }
    else
    {

        while (i < (pos2 - 1))
        {
            temp = temp->next;
            i++;
        }
        nextnode = temp->next;
        cout << "after deleting the node at spcific position i.e." << (nextnode)->data << ", the output is" << endl;
        temp->next = nextnode->next;
        free(nextnode);
        output(*head);
    }



}
void reverse(node** head)
{
    node* currentnode;
    node* prevnode = NULL;
    node* nextnode;
    currentnode = *head;
    nextnode = *head;
    while (nextnode != NULL)
    {
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    *head = prevnode;
    cout << "after reversing the linkedlist" << endl;
    output(*head);




}

int main()
{
    node* head = NULL;

    int ch, choice = 1, dat, pos;
    //input elements
    input(&head);

    //output elements
    cout << "the nodes after entering are" << endl;
    output(head);
    while (choice)
    {

        cout << endl;
        cout << "****OPERATION MENU****" << endl;
        cout << endl;
        cout << "enter 1 to add node at beginning" << endl;
        cout << "enter 2 to add node at end" << endl;
        cout << "enter 3 to add node any position" << endl;
        cout << "enter 4 to delete node at beginning" << endl;
        cout << "enter 5 to delete node at end" << endl;
        cout << "enter 6 to delete node at any position" << endl;
        cout << "enter 7 to reverse the Linked List" << endl;
        cin >> ch;
        system("cls");
        if (ch == 1)
        {
            //cout << "Let us add a node at beginning now" << endl;
            cout << "enter the node to add at beginning" << endl;
            cin >> dat;
            addbeg(&head, dat);
        }
        else if (ch == 2)
        {
            cout << "enter the node to enter at the end" << endl;
            cin >> dat;
            addend(&head, dat);
        }
        else if (ch == 3)
        {
            cout << "enter the position where the node has to be added" << endl;
            cin >> pos;
            cout << "enter the node value" << endl;
            cin >> dat;
            addpos(&head, pos, dat);
        }
        else if (ch == 4)
        {

            delbeg(&head);
        }
        else if (ch == 5)
        {

            delend(&head);
        }
        else if (ch == 6)
        {
            cout << "enter the position where the node has to be deleted" << endl;
            cin >> pos;
            delpos(&head, pos);
        }
        else
        {
            reverse(&head);
        }

        cout << "do you want to go to operations menu again ? if yes enter 1, else enter 0" << endl;
        cin >> choice;
        system("cls");
    }
    if (choice == 0)
    {
        cout << "OVER" << endl;
    }

}