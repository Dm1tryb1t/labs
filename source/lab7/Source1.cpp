#include <algorithm>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <random>

std::mutex cout_guard;

void sort_from_l_to_r(double* arr, int l, int r, char* thread_name) {
	for (int i = l - 1; i < r; ++i) {
		for (int j = i + 1; j < r; ++j) {
      if (arr[j] < arr[j - 1]) {
        std::swap(arr[j], arr[j - 1]);
      }
    }
	}
	// std::sort(arr + l - 1, arr + r);
	std::cout << std::endl;
	for (int i = l - 1; i < r; ++i) {
		cout_guard.lock();
		std::cout << std::endl
		  				<< thread_name << ' '
							<< std::endl;
		// std::this_thread::sleep_for(std::chrono::milliseconds(10));
		std::cout << arr[i] << " ";
		cout_guard.unlock();
  }
}

const int ARR_SIZE = 20;

int main() {
	char* thread_name1 = "thread1";
	char* thread_name2 = "thread2";
	char* thread_name3 = "thread3";
	srand(time(NULL));
	double array[ARR_SIZE];
	for (int i = 0; i < ARR_SIZE; i++) {
		array[i] = static_cast<double>(1 + rand() % 2002) / 100.0;
	}

	std::pair<int, int> first_half = std::make_pair(1, ARR_SIZE / 2);
	std::pair<int, int> second_half = std::make_pair(ARR_SIZE / 2 + 1, ARR_SIZE);

	// Sorting the first half of array
	std::thread thread1(sort_from_l_to_r,
										 	array, first_half.first, first_half.second, thread_name1);
	// Sorting the second half of array
	std::thread thread2(sort_from_l_to_r,
											array, second_half.first, second_half.second, thread_name2);
	thread1.join();
	thread2.join();
	
	// Sorting the full array
	std::thread thread3(sort_from_l_to_r,
											array, first_half.first, second_half.second, thread_name3);
	thread3.join();

	// std::cout << std::endl
	// 					<< "The array in main thread is "
	// 					<< std::endl;
	// for (int i = 0; i < ARR_SIZE; ++i) {
	// 	std::cout << array[i] << ' ';
	// }

	std::cout << std::endl
						<< "Main thread has stopped working"
						<< std::endl;
	return 0;
}