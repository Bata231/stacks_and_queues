#include <iostream>
#include <cassert>
#include "stack.h"
#include "queue.h"

void testStack() {
    Stack<int> stack;
    stack += 2;
    stack += 4;
    stack += 4;
    stack.push(5);
    stack.push(6);
    stack -=5;
    stack -=4;
    assert(stack.size() == 3);

    assert(!stack.isEmpty());
    stack.clear();
    std::cout << stack.size() << std::endl;
    assert(stack.isEmpty());

    stack += 7;
    assert(!stack.isEmpty());
    stack.clear();
    stack.push(4);
    stack.push(3);
    stack += 5;
    stack.pop();
    stack.pop();
    assert(stack.size() == 1);

    stack.clear();
    stack.push(2);
    assert(stack.size() == 1);

    stack.clear();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    assert(stack.peek() == 3);
    stack -=1;
    //assert(stack.peek() == 2);
}
void testQueue() {
    Queue<int> queue;
    queue += 2;
    queue += 4;
    queue += 4;
    queue.enqueue(5);
    queue.enqueue(6);
    queue.dequeue();
    assert(queue.peek() == 4);
    assert(queue.size() == 4);


    queue -= 4;
    queue -= 4;
    assert(!queue.isEmpty());
    queue.clear();
    assert(queue.isEmpty());

    queue += 7;
    assert(!queue.isEmpty());
    queue.clear();
    queue.enqueue(4);
    queue.enqueue(3);
    queue += 5;
    queue.dequeue();
    queue.dequeue();
    assert(queue.size() == 1);

    queue.clear();
    queue.enqueue(2);
    assert(queue.size() == 1);
}
int main() {

    //testStack();
    testQueue();
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.