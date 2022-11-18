#include "LinkedList.h"

LinkedList::~LinkedList()
{
    auto Cur = Head;

    while (Cur)
    {
        auto Temp = Cur->NextNode;
        delete Cur->Data;
        delete Cur;
        Cur = Temp;
    }
}

Node* LinkedList::Add(int Data)
{
    Node* Temp = new Node{nullptr, nullptr, new int(Data)};

    if (Size == 0)
    {
        Head = Tail = Temp;
        Size++;
    }
    else
    {
        AddTail(Temp);
    }

    return Temp;
}

bool LinkedList::DeleteNode(const Node* NodeToDelete)
{
    if (!HasNode(NodeToDelete))
    {
        return false;
    }

    if (Size == 1)
    {
        delete Head;
        Tail = nullptr;
        Head = nullptr;
        Size = 0;
    }
    else if (NodeToDelete == Head)
    {
        DeleteHead();
    }
    else if (NodeToDelete == Tail)
    {
        DeleteTail();
    }
    else
    {
        DeleteInside(NodeToDelete);
    }

    return true;
}

void LinkedList::DeleteHead()
{
    auto Temp = Head->NextNode;
    delete Head;
    Head = Temp;
    Head->PrevNode = nullptr;
    Size--;
}

void LinkedList::DeleteTail()
{
    auto Temp = Tail->PrevNode;
    delete Tail;
    Tail = Temp;
    Tail->NextNode = nullptr;
    Size--;
}

void LinkedList::DeleteInside(const Node* NodeToDelete)
{
    const auto Prev = NodeToDelete->PrevNode;
    const auto Next = NodeToDelete->NextNode;

    Size--;
    delete NodeToDelete->Data;
    delete NodeToDelete;

    Prev->NextNode = Next;
    Next->PrevNode = Prev;
}

Node* LinkedList::EmplaceNode(Node* PreviousNode, int Data)
{
    if (!HasNode(PreviousNode))
    {
        throw std::exception("There is no such node in list");
    }

    Node* Temp = new Node{nullptr, nullptr, new int(Data)};

    InsertNode(PreviousNode, Temp);

    return Temp;
}

bool LinkedList::HasNode(const Node* PreviousNode) const
{
    auto Cur = Head;
    while (Cur)
    {
        if (Cur == PreviousNode) return true;

        Cur = Cur->NextNode;
    }

    return false;
}

Node* LinkedList::InsertNode(Node* PreviousNode, Node* CurrentNode)
{
    if (!PreviousNode->NextNode)
    {
        return AddTail(CurrentNode);
    }
    else
    {
        return AddInside(PreviousNode, CurrentNode);
    }
}

Node* LinkedList::AddTail(Node* CurrentNode)
{
    Tail->NextNode = CurrentNode;
    CurrentNode->PrevNode = Tail;
    Tail = CurrentNode;
    Size++;
    return CurrentNode;
}

Node* LinkedList::AddHead(Node* CurrentNode)
{
    CurrentNode->NextNode = Head;

    Head->PrevNode = CurrentNode;
    Head = CurrentNode;
    Size++;
    return CurrentNode;
}

Node* LinkedList::AddInside(Node* PreviousNode, Node* CurrentNode)
{
    CurrentNode->PrevNode = PreviousNode;
    CurrentNode->NextNode = PreviousNode->NextNode;
    PreviousNode->NextNode->PrevNode = CurrentNode;
    PreviousNode->NextNode = CurrentNode;
    Size++;
    return CurrentNode;
}
