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

template<typename Iterator>
void printout(Iterator first, Iterator last){
	while(first != last){

		std::cout << *first << std::endl;
		first++;
	}
	std::cout << std::endl;
}

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
	std::cout << "Task 2" << std::endl;
	std::cout << "Printing Double Vector: " << std::endl;


	auto first = std::begin(vd);
	auto last = std::end(vd);

	while(first != last){
		std::cout << *first;

		first++;

		if(first != last){
			std::cout << ", ";
		}
	}

	std::cout << std::endl << std::endl;

	// Task 3
	std::vector<int> vi(vd.size());

	std::copy(std::begin(vd), std::end(vd), std::begin(vi));

	// Task 4
	std::cout << "Task 4" << std::endl;
	std::cout << "Printing Double&Int Vector pairs: " << std::endl;

	for(int i = 0; i < vi.size(); ++i){
		std::cout << vd[i] << "\t" << vi[i] << std::endl;
	}
	std::cout << std::endl;

	// Task 5
	std::cout << "Task 5-6" << std::endl;

	auto sum_vd = std::accumulate(std::begin(vd), std::end(vd), 0.0);
	std::cout << "Sum of VD elements: " << sum_vd << std::endl;

	// Task 6
	auto sum_vi = std::accumulate(std::begin(vi), std::end(vi), 0);
	std::cout << "Sum of VI elements: " << sum_vi << std::endl;

	std::cout << "Difference between VD and VI sum: " << (sum_vd - sum_vi) << std::endl;
	std::cout << std::endl;

	// Task 7
	std::cout << "Task 7" << std::endl;

	std::reverse(std::begin(vd), std::end(vd));

	std::cout << "VD after reverse: " << std::endl;

	printout(std::begin(vd), std::end(vd));
	std::cout << std::endl;

	// Task 8
	std::cout << "Task 8" << std::endl;

	double mean_vd = sum_vd / vd.size();

	std::cout << "Mean of VD: " << mean_vd << std::endl;
	std::cout << std::endl;

	// Task 9

	std::vector<double> vd2(vd.size());
 	auto it = std::copy_if(std::begin(vd), std::end(vd), std::begin(vd2), Less_than(mean_vd));

	vd2.resize(std::distance(vd2.begin(), it));

	std::cout << "VD2 after copy-if: " << std::endl;
	printout(std::begin(vd2), std::end(vd2));

	std::cout << std::endl;

	// Task 10
	std::cout << "Task 10" << std::endl;

	std::sort(std::begin(vd), std::end(vd));

	std::cout << "VD after sort: " << std::endl;
	printout(std::begin(vd), std::end(vd));

	return 0;
}
