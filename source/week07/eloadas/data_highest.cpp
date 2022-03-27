/*
	g++ data_highest.cpp -o data_highest.out -std=c++11 && ./data_highest.out 
*/

#include <iostream>
#include <vector>

double* get_from_jack(int* count){
	double* jack_array = new double[6];

	for(int i = 0; i < 6; ++i){
		jack_array[i] = i*3;
	}

	*count = 6;

	return jack_array;
}

std::vector<double>* get_from_jill(){
	std::vector<double>* jill_vector = new std::vector<double>;

	*jill_vector = {100, 200, 300, 420, 100, 50};

	return jill_vector;
}

/*double* high(double* first, double* last){
	double h = -1;
	double* high;

	for (double* p = first; p != last; ++p)
	{
		if(*p > h){
			high = p;
			h = *p;
		}
	}
	return high;
}*/

template<typename Iterator>
Iterator high(Iterator first, Iterator last){
	Iterator high = first;

	for (Iterator p = first; p != last; ++p)
	{
		if(*p > *high){
			high = p;
		}
	}
	return high;
}

int main(){

	int jack_count = 0;
	double* jack_data = get_from_jack(&jack_count);

	std::cout << "Jack_data: ";

	for(int i = 0; i < jack_count; ++i){
		std::cout << jack_data[i] << ' ';
	}
	std::cout << std::endl;

	std::vector<double>* jill_data = get_from_jill();

	std::cout << "Jill_data: ";
	for(auto elemenet: *jill_data){
		std::cout << elemenet << ' ';
	}

	double h = -1;
	double* jack_high;
	double* jill_high;

	for (int i = 0; i < jack_count; ++i)
	{
		if(jack_data[i] > h){
			h = jack_data[i];
			jack_high = &jack_data[i];
		}
	}

	h = -1;

	for (int i = 0; i < jill_data->size(); ++i)
	{
		if((*jill_data)[i] > h){
			jill_high = &(*jill_data)[i];
			h = (*jill_data)[i];
		}
	}

	std::cout << "Jill high: " << *jill_high << std::endl;
	std::cout << "Jack high: " << *jack_high << std::endl;


	std::vector<double>& jill_vector_ref = *jill_data;

	h = -1;

	for (int i = 0; i < jill_vector_ref.size(); ++i)
	{
		if(jill_vector_ref[i] > h){
			jill_high = &jill_vector_ref[i];
			h = jill_vector_ref[i];
		}
	}

	jack_high = high(jack_data, jack_data+jack_count);
	jill_high = high(&jill_vector_ref[0], &jill_vector_ref[0]+jill_vector_ref.size());

	std::cout << "Jill high: " << *jill_high << std::endl;
	std::cout << "Jack high: " << *jack_high << std::endl;

	double* jack_middle = jack_data+jack_count/2;

	double* jack_first_half = high(jack_data, jack_middle);
	double* jack_second_half = high(jack_middle, jack_data+jack_count);

	std::cout << "Jill first half: " << *jack_first_half << std::endl;
	std::cout << "Jack second half: " << *jack_second_half << std::endl;

	delete[] jack_data;
	delete jill_data;

	return 0;
}