#include <iostream>
#include "LinkedList.h"
#include "Node.h"

int main()
{
    try
    {
        LinkedList list;
        list.Add(5);
        auto n = list.Add(4);
        list.Add(10);
        list.EmplaceNode(n, 19);
        list.EmplaceNode(n, 20);
        list.DeleteNode(n);
        list.DeleteNode(n);
        std::cout << list.GetSize();
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what();
    }

    return 0;
}
