/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Magdalena Sobrino-Almanzar
 */

/*/Can we declare a non-reference function argument const (e.g., void f(const int);)? 
What might that mean? Why might we want to do that? Why don’t people do that often? 
Try it; write a couple of small programs to see what works./*/

#include <stdio.h>
#include "../std_lib_facilities.h"


vector<int> get_sizes(const vector<string>& vs)
{
	vector<int> res(vs.size());
	for (int i =0; i<vs.size(); ++i)
		res[i] = vs[i].size();
	return res;
}

// returns longest string in a vector of strings//
int longest_string(const vector<string>& v)
{
	if (v.size()==0) error("longest_string(): empty vector");	

	int m = v[0].size();	
	int max_index = 0;
	for (int i=0; i<v.size(); ++i)
		if (m<v[i].size()) {
			max_index = i;
			m = v[i].size();
		}
	return max_index;
}

// returns shortest string in a vector of strings
string shortest_string(vector<string>& v)
{
    if (v.size() == 0) error("shortest_string: empty vector");


    int m = v[0].size();
    int min_index = 0;
    for (int i = 0; i<v.size(); ++i) 
        if (v[i].size() < m) {
            min_index = i;
            m = v[i].size;
        }
    return v[min_index];
}
// returns lexicographically first string in a vector of strings
string first_string(const vector<string>& v)
{
    if (v.size() == 0) error("alpha_first_string: argument is empty vector");
    
    int first_index = 0;
	for (int i=0; i<v.size(); ++i)
		if (v[i]<v[first_index])
			first_index = i;
	return v[first_index];
}

// returns lexicographically last string in a vector of strings
string last_string(const vector<string>& v)
{
    if (v.size() == 0) error("alpha_last_string: argument is empty vector");
   last = -1;	// -1 indicates "the empty vector"
		return;
	}

	int last_index = 0;
	for (int i=0; i<v.size(); ++i)
		if (v[last_index]<v[i])
			last_index = i;
	last = last_index;
}


int main()
try
{
	vector<string> vs;
	vs.push_back("Technicalities");
	vs.push_back("a");
	vs.push_back("A");
	vs.push_back("hellohellohell");	// same length as "Technicalities"
	vs.push_back("Hellohellohell");	// lexicographically 'H' < 'h'
//	vs.push_back("");	// the empty string
	vs.push_back("!");	// same length as "a"

	cout << "sizes: ";
	vector<int> lengths = get_sizes(vs);
	for (int i=0; i<lengths.size(); ++i) cout << lengths[i] << ' ';
	cout << '\n';

	int i = longest_string(vs);
	cout << "longest_string(): index==" << i << "; string=='" << vs[i] << "'\n";	

	cout << "shortest_string(): '" << shortest_string(vs) << "'\n";	

	cout << "first_string(): '" << first_string(vs) << "'\n";
	
	last_string(vs,i);	// pass 'i' for last_string() to return into
	cout << "last_string(): index==" << i << "; string=='" << vs[i] << "'\n";	

	
}
catch (runtime_error e) {	// To produce error message
	cout << e.what() << '\n';
	
}
