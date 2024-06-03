#include <algorithm>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <random>

//  g++ source/lab7/Source1.cpp -o build/lab7_thread -w


std::condition_variable condition_variable;
std::mutex cout_guard;
std::atomic<int> completed_threads{0};

void sort_from_l_to_r(double* arr, int l, int r, const char* thread_name) {
    // Sort the sub-array
		for (int i = l - 1; i < r; ++i) {
			for (int j = i + 1; j < r; ++j) {
      	if (arr[j] < arr[j - 1]) {
        	std::swap(arr[j], arr[j - 1]);
      	}
    	}
		}
	// std::sort(arr + l - 1, arr + r);

		for (int i = l - 1; i < r; ++i) {
			{
				std::lock_guard<std::mutex> lock(cout_guard);
				std::cout << std::endl << thread_name << ' ' << arr[i];
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
    
    // Notify main thread that sorting is done
    completed_threads++;
    condition_variable.notify_one();
}

const int ARR_SIZE = 20;

int main() {
    const char* thread_name1 = "thread1";
    const char* thread_name2 = "thread2";
    const char* thread_name3 = "thread3";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1.0, 20.0);

    double array[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++) {
        array[i] = dis(gen);
    }

    std::pair<int, int> first_half = std::make_pair(1, ARR_SIZE / 2);
    std::pair<int, int> second_half = std::make_pair(ARR_SIZE / 2 + 1, ARR_SIZE);

    // Sorting the first half of the array
    std::thread thread1(sort_from_l_to_r, array, first_half.first, first_half.second, thread_name1);

    // Sorting the second half of the array
    std::thread thread2(sort_from_l_to_r, array, second_half.first, second_half.second, thread_name2);
    
    // Wait for both halves to be sorted
    {
        std::unique_lock<std::mutex> lock(cout_guard);
        condition_variable.wait(lock, [] { return completed_threads.load() >= 2; });
    }

    // Sorting the full array
    std::thread thread3(sort_from_l_to_r, array, first_half.first, second_half.second, thread_name3);
    
    {
        std::unique_lock<std::mutex> lock(cout_guard);
        condition_variable.wait(lock, [] { return completed_threads.load() >= 3; });
        std::cout << std::endl << "The threads have finished working";
    }

    thread1.join();
    thread2.join();
    thread3.join();

    std::cout << std::endl << "Main thread has stopped working" << std::endl;
    return 0;
}
