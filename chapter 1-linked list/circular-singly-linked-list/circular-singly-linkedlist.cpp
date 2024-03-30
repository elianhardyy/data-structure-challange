#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Mahasiswa
{
    string name, nrp, jurusan; //the data inside node
    Mahasiswa *next; //this next of the node
};
Mahasiswa *head, *tail ,*current, *newNode ;
// Circular Linked List work
struct Mahasiswa* addEmpty(string data[3])
{
    // initialize node as head
    head = new Mahasiswa();
    head->name = data[0];
    head->nrp = data[1];
    head->jurusan = data[2];
    head->next = head;
    // declare tail for link to head again 
    tail = head;
    tail->next = head;
}
// print circular singly linked list
void printCircularSinglyLinkedList()
{
    current = head;//new place for print node;
    while(current->next != head){ // when it encounter tail
        cout << current->name << "\t";
        cout << current->nrp << "\t";
        cout << current->jurusan << endl;
        current = current->next;
    }
    cout << current->name << "\t";
    cout << current->nrp << "\t";
    cout << current->jurusan << endl;
}
// add first in node based on image is before letter "L"
struct Mahasiswa* addFirst(string data[3])
{
    // new Node
    newNode = new Mahasiswa();
    newNode->name = data[0];
    newNode->nrp = data[1];
    newNode->jurusan = data[2];
    //newNode link to next node
    newNode->next = head;
    //if node has more than one 
    tail->next = newNode;
    head = newNode; // newNode will link to head or replace head
}
// add last in node based on image is after letter "T"
struct Mahasiswa* addLast(string data[3])
{
    newNode = new Mahasiswa();
    newNode->name = data[0];
    newNode->nrp = data[1];
    newNode->jurusan = data[2];
    tail->next = newNode;
    newNode->next = head;
    tail = newNode; // replace tail
}
struct Mahasiswa* addIndex(int index, string data[3])
{
    newNode = new Mahasiswa();
    newNode->name = data[0];
    newNode->nrp = data[1];
    newNode->jurusan = data[2];
    newNode->next = NULL;
    current = head;
    while(index > 1){
        current = current->next;
        index--;
    }
    newNode->next = current->next;
    current->next = newNode;
    if(current == tail)
    {
        tail = tail->next;
    }
    current = newNode;
}

int main()
{
    string data1[3] = {"Elian","1020040033","PL"};
    addEmpty(data1);
    string data2[3] = {"John","1020040022","OO"};
    addFirst(data2);
    string data3[3] = {"Nana","1020040022","OO"};
    addLast(data3);
    string data4[3] = {"Hala","1020040022","OO"};
    addLast(data4);
    string data5[3] = {"Lala","1020040044","11"};
    addIndex(1,data5);
    printCircularSinglyLinkedList();

    
    return 0;
}