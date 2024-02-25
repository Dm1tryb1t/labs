#include <iostream>
#include <chrono>
#include <mutex>
#include <random>
#include <future>

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
    // std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << std::endl
		  				<< thread_name << ' '
							<< std::endl;
		// std::this_thread::sleep_for(std::chrono::milliseconds(10));
		std::cout << arr[i] << " ";
    cout_guard.unlock();
  }
}

const int ARR_SIZE = 20;

void Working() {
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
	std::future<void> thread1 = std::async(sort_from_l_to_r,
										 	array, first_half.first, first_half.second, thread_name1);
	// Sorting the second half of array
  std::future<void> thread2 = std::async(sort_from_l_to_r,
											array, second_half.first, second_half.second, thread_name2);
	thread1.wait();
	thread2.wait();
  // Sorting the full array
  std::future<void> thread3 = std::async(sort_from_l_to_r,
											array, first_half.first, second_half.second, thread_name3);
}

int main()
{
	const auto start_time = std::chrono::steady_clock::now();

	Working();

	const auto end_time = std::chrono::steady_clock::now();

	const auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

  // std::cout << std::endl
	// 					<< "The array in main thread is "
	// 					<< std::endl;
	// for (int i = 0; i < ARR_SIZE; ++i) {
	// 	std::cout << array[i] << ' ';
	// }

	std::cout << "Main thread has stopped working" << std::endl;
	std::cout << "It took " << elapsed_time.count() << " milliseconds" << std::endl;
	return 0;
}