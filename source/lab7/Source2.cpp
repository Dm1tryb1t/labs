#include <condition_variable>
#include <iostream>
#include <chrono>
#include <mutex>
#include <random>
#include <future>
#include <algorithm>

// g++ source/lab7/Source2.cpp -o build/lab7_future -w

std::mutex cout_guard;

void sort_from_l_to_r(double* arr, int l, int r, const char* thread_name) {
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
			std::cout << std::endl << thread_name << ' ' << arr[i] << ' ';
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

const int ARR_SIZE = 20;

void Working() {
    const char* thread_name1 = "thread1";
    const char* thread_name2 = "thread2";
    const char* thread_name3 = "thread3";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1.0, 20.0);

    double array[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; ++i) {
        array[i] = dis(gen);
    }

    std::pair<int, int> first_half = std::make_pair(1, ARR_SIZE / 2);
    std::pair<int, int> second_half = std::make_pair(ARR_SIZE / 2 + 1, ARR_SIZE);

    // Sorting the first half of array
    auto thread1 = std::async(std::launch::async, sort_from_l_to_r, array, first_half.first, first_half.second, thread_name1);
    // Sorting the second half of array
    auto thread2 = std::async(std::launch::async, sort_from_l_to_r, array, second_half.first, second_half.second, thread_name2);

    thread1.wait();
    thread2.wait();

    // Sorting the full array
    auto thread3 = std::async(std::launch::async, sort_from_l_to_r, array, first_half.first, second_half.second, thread_name3);
    thread3.wait();

    std::cout << std::endl << "All threads have completed their tasks";
}

int main() {
    const auto start_time = std::chrono::steady_clock::now();

    Working();

    const auto end_time = std::chrono::steady_clock::now();

    const auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    std::cout << std::endl << "Main thread has stopped working" << std::endl;
    std::cout << "It took " << elapsed_time.count() << " milliseconds" << std::endl;

    return 0;
}

