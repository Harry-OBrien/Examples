#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include <cassert>
#include <thread>

int const NUM_OF_THREADS = 8;

//std::vector<int> add_vectors(std::vector<int> first_vec, std::vector<int> second_vec) {
//	/* Parallel addition of vectors */
//	std::vector<std::thread> threads;
//	std::vector<int> parallel_result(first_vec.size());
//
//	// Make sure vectors are same size
//	if(first_vec.size() != second_vec.size())
//		return  parallel_result;
//
//	auto range = std::size(first_vec) / NUM_OF_THREADS;
//	for (int i = 0; i < NUM_OF_THREADS; i++)
//	{
//		auto start = i * range;
//		auto firstBegin = std::begin(first_vec) + start;
//		auto secondBegin = std::begin(second_vec) + start;
//		auto resultBegin = std::begin(parallel_result) + start;
//
//		auto firstEnd = firstBegin + range;
//		threads.emplace_back([firstBegin, firstEnd, secondBegin, resultBegin]() {
//			std::transform(firstBegin,
//						   firstEnd,
//						   secondBegin,
//						   resultBegin,
//						   [](int lhs, int rhs) -> int {
//								 return lhs + rhs;
//						   });
//		});
//	}
//
//	for (auto &thread : threads)
//	{
//		thread.join();
//	}
//
//	return parallel_result;
//}

template<typename T>
std::vector<T> operator+(std::vector<T> const& first, std::vector<T> const& second)
{
	assert(first.size() == second.size());

	std::vector<T> result;
	result.reserve(first.size());

	std::transform(first.begin(), first.end(), second.begin(), std::back_inserter(result), std::plus<T>());
	return result;
}

int main(int argc, char *argv[])
{
	std::vector<int> first_vec, second_vec;
	
	first_vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	second_vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
//	/* Filling up the vectors with dummy values */
//	for (int i = 1; i <= VECTOR_SIZE; i++)
//	{
//		first_vec.push_back(i);
//		second_vec.push_back(i);
//	}
	
//	std::vector<int> parallel_result = add_vectors(first_vec, second_vec);
	std::vector<int> parallel_result = first_vec + second_vec;
	
	for(auto val : parallel_result) {
		std::cout << val << " ";
	}
	
	return 0;
}
