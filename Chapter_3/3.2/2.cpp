#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <functional>

class SafeQueue
{
private:
    std::queue<int> queue;
    std::mutex mutex;

public:
    void Push(int value)
    {
        std::lock_guard<std::mutex> lock(mutex);
        queue.push(value);
    }

    bool Pop(int& value)
    {
        std::lock_guard<std::mutex> lock(mutex);

        if (queue.empty())
        {
            return false;
        }

        value = queue.front();
        queue.pop();

        return true;
    }

    size_t Size()
    {
        std::lock_guard<std::mutex> lock(mutex);
        return queue.size();
    }
};


void Producer(SafeQueue& queue, int start, int end)
{
    for (int i = start; i <= end; ++i)
    {
        queue.Push(i);
    }
}


void Consumer(SafeQueue& queue)
{
    int value;

    while (queue.Pop(value))
    {
        std::cout << "Consumed: " << value << '\n';
    }
}


int main()
{
    SafeQueue queue;

    std::thread producer1(Producer, std::ref(queue), 1, 5);
    std::thread producer2(Producer, std::ref(queue), 6, 10);

    producer1.join();
    producer2.join();

    std::thread consumer(Consumer, std::ref(queue));

    consumer.join();

    std::cout << "Queue size: " << queue.Size() << '\n';

    return 0;
}