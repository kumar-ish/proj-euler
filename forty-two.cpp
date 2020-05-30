#include <fstream>
#include <iostream>
#include <chrono> 
#include <vector>

using namespace std;
using namespace std::chrono;

int tri_num(string file_name) {
    auto start = high_resolution_clock::now(); 	
    ifstream inFile;
    inFile.open(file_name);

    if (!inFile) {
        cerr << "Unable to open file datafile.txt";
        exit(1);
    }
    string s;
    getline(inFile,s);
    std::string delimiter = "\",\"";

    std:vector<int> word_vals;
    size_t last = 0; 
    size_t next = 0;
    int max_size = 0;
    int val;
    while ((next = s.find(delimiter, last)) != string::npos) {
        //cout << s.substr(last, next-last) << endl;
	val = 0;
	for (int i = 0; i < s.substr(last, next-last).length(); i++) {
	    //cout << (int)s.substr(last, next-last).at(i) - 64 << " ";
	    if (s.substr(last, next-last).at(i) != '\"')
		val += (int)s.substr(last, next-last).at(i) - 64;
	}
	word_vals.push_back(val);
	max_size = max(max_size, val);
       	last = next + delimiter.length();
	//cout << val << endl;
    } 
    //cout << s.substr(last) << endl;
    val = 0;
    for (int i = 0; i < s.substr(last).length(); i++) {
	//cout << (int)s.substr(last, next-last).at(i) - 64 << " ";
	if (s.substr(last, next-last).at(i) != '\"') {
	    val += (int)s.substr(last).at(i) - 64;
	    //cout << (int)s.substr(last).at(i) - 64 << " ";
	}	    
    }
    word_vals.push_back(val);

    std::vector<int> tri_n;
    int tri_nmax = 0;
    int count = 0;

    while (tri_nmax < max_size) {
        count++;
	tri_nmax = count*(count - 1) / 2;
	tri_n.push_back(tri_nmax);
	//cout << tri_nmax << endl;
    }
    count++;
    tri_nmax = count*(count - 1) / 2;
    tri_n.push_back(tri_nmax);

    int num_tri_words = 0;

    for (int i = 0; i < word_vals.size(); i++) {
        //cout << word_vals.at(i) << endl;
	if (std::find(tri_n.begin(), tri_n.end(), word_vals.at(i)) != tri_n.end())
            //cout << word_vals.at(i) << endl;
	    num_tri_words++; 
	
    }
    
    inFile.close();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); 
    //cout << duration.count() << " microseconds taken" << endl;
    return num_tri_words;
}

int main() {
    //cout << tri_num("data/try.txt") << endl;
    cout << tri_num("data/p042_words.txt") << endl;
    return 0;
}
