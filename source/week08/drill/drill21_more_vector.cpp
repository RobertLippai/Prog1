/*
	g++ drill21_more_vector.cpp -o drill21_more_vector.out -std=c++11 && ./drill21_more_vector.out 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list> 
#include <array> 
#include <fstream>
#include <numeric>

class Less_than {
    double value;
public:
    Less_than(double v) : value{v} { }

    bool operator()(const double v) { return v < value; }
};

int main(){
	
	// Task 1

	std::vector<double> vd;

	std::ifstream fs("./floating.txt");
	
	if(!fs){
		std::cout << "File not found" << std::endl;
		return 1;
	}

	double temp;

	while(fs >> temp){
		vd.push_back(temp);
	}

	fs.close();
	
	// Task 2
	std::cout << "Outputing Double Vector: " << std::endl;


	auto first = std::begin(vd);
	auto last = std::end(vd);

	while(first != last){
		std::cout << *first;

		first++;

		if(first != last){
			std::cout << ", ";
		}
	}

	std::cout << std::endl;

	// Task 3
	std::vector<int> vi(vd.size());

	std::copy(std::begin(vd), std::end(vd), std::begin(vi));

	// Task 4
	for(int i = 0; i < vi.size(); ++i){
		std::cout << vd[i] << "\t" << vi[i] << std::endl;
	}

	// Task 5
	auto sum_vd = std::accumulate(std::begin(vd), std::end(vd), 0.0);
	std::cout << "Sum of VD elements: " << sum_vd << std::endl;

	// Task 6
	auto sum_vi = std::accumulate(std::begin(vd), std::end(vd), 0);
	std::cout << "Sum of VI elements: " << sum_vi << std::endl;

	std::cout << "Difference between VD and VI sum: " << 
	(std::max(sum_vd, (double) sum_vi) - std::min(sum_vd, (double) sum_vi)) << std::endl;
	
	// Task 7

	std::reverse(std::begin(vd), std::end(vd));
	std::cout << "VD after reverse: " << std::endl;
	for(int i = 0; i < vd.size(); ++i){
		std::cout << vd[i] << std::endl;
	}

	// Task 8

	double mean_vd = sum_vd / vd.size();

    std::cout << "Mean of VD: " << mean_vd << std::endl;

	// Task 9

	std::vector<double> vd2(vd.size());
 	auto it = std::copy_if(std::begin(vd), std::end(vd), std::begin(vd2), Less_than(mean_vd));

	// Task 10
	std::sort(std::begin(vd), std::end(vd));
	std::cout << "VD after sort: " << std::endl;
	for(int i = 0; i < vd.size(); ++i){
		std::cout << vd[i] << std::endl;
	}

	return 0;
}
