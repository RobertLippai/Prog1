/*
	g++ text_editor.cpp -std=c++11 -o text_editor.out && ./text_editor.out teszt.txt
*/

#include <iostream>
#include <vector>
#include <list>
#include <fstream>

using Line = std::vector<char>; // this is a whole line

class Text_iterator {
	std::list<Line>::iterator ln;

	Line::iterator pos;

public:
	Text_iterator(std::list<Line>::iterator ll, Line::iterator pp) : ln(ll), pos(pp) {}

	std::list<Line>::iterator get_line() const { return ln; }
	Line::iterator get_pos() const { return pos; }

	char& operator*() { return *pos; }
	Text_iterator& operator++();

	bool operator==(const Text_iterator& other) const {
		return ln == other.ln && pos == other.pos;
	}

	bool operator!=(const Text_iterator& other) const {
		return !(*this == other);
	}
};

Text_iterator& Text_iterator::operator++(){
	++pos;
	if(pos == (*ln).end() ){
		++ln;
		pos = (*ln).begin();
	}

	return *this;
}

struct Document {
	std::list<Line> line;
	Document() { line.push_back(Line{}); }

	Text_iterator begin(){
		return Text_iterator(line.begin(), (*line.begin()).begin());
	}

	Text_iterator end(){
		auto last = line.end();
		--last;
		return Text_iterator(last, (*last).end());
	}
};

std::istream& operator>>(std::istream& is, Document& doc){
	for(char ch; is.get(ch);){ // won't skip spaces
		doc.line.back().push_back(ch);

		if(ch == '\n'){
			doc.line.push_back(Line{});
		}
	}

	if(doc.line.back().size()){ //not empty
		doc.line.push_back(Line{});
	}

	return is;
}

void print(Document& doc){
	for(const auto& e : doc){
		std::cout << e;
	}
	std::cout << std::endl;
}

int main(int argc, char** argv){

	std::fstream ifs(argv[1]);

	if(!ifs){
		std::cout << "File not found\n";
		return 1;
	}

	Document d;

	ifs >> d;

	print(d);

	return 0;
}