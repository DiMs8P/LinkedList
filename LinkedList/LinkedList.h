#pragma once
#include "Node.h"
#include <exception>

class LinkedList
{
public:
    LinkedList()
    {
        Tail = Head = nullptr;
        Size = 0;
    }

    ~LinkedList();

    auto GetSize() const -> int { return Size; }

    Node* Add(int Data);

    Node* EmplaceNode(Node* PreviousNode, int Data);
    auto DeleteNode(const Node* NodeToDelete) -> bool;  // return true if node was deleted

private:
    Node* Head;
    Node* Tail;
    int Size;

    auto HasNode(const Node* PreviousNode) const -> bool;

    Node* InsertNode(Node* PreviousNode, Node* CurrentNode);
    Node* AddTail(Node* CurrentNode);
    Node* AddInside(Node* PreviousNode, Node* CurrentNode);
    Node* AddHead(Node* CurrentNode);

    void DeleteHead();
    void DeleteTail();
    void DeleteInside(const Node* NodeToDelete);
};
