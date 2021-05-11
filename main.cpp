#include <chrono>
#include <ctime>
#include <thread>
#include <iostream>
#include <vector>

#include "MergeSort.cpp"

int main()
{
    std::cout << "The available number of threads: " << std::thread::hardware_concurrency() << std::endl;

    std::vector<std::vector<int>> pre_result;

    // инициализация
    std::vector<int> vec(100);
    std::srand(std::time(nullptr));
    for (int& i : vec)
        i = std::rand();

    for (int i : vec)
        std::cout << i << ' ';
    std::cout << std::endl;

    for (int i : vec)
        std::cout << i << ' ';
    std::cout << std::endl;

    // работа с потоками
    int num_threads = 2;
    std::vector<std::thread*> threads(num_threads);
    pre_result.resize(num_threads);

    int parts = vec.size() / num_threads;
    int start = 0;
    int finish = vec.size() / num_threads;
    for (size_t i = 0; i < num_threads; i++)
    {
        if (vec.size() - start > parts)
            finish += vec.size() - start;
        else
            finish += parts;

        threads[i] = new std::thread(merge_sort<1, 2, int>, std::ref(vec), start, finish, std::ref(pre_result));
    }



    return 0;
}
