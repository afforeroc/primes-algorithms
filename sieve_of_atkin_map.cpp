#include <iostream> 	// cout
#include <vector>   	// vector
#include <string.h> 	// memset
#include <time.h>		// clock, clock_t
#include <stdio.h>		// printf
#include <cmath>		// log10
#include <fstream>		// ofstream
#include <regex>		// regex
using namespace std;

// Functions
int naturalNumber();
vector<int> SieveOfAtkin(int limit);
void primes2txt(vector<int> vector_primes);
void primes2terminal(vector<int> vector_primes);

int main(){
	cout << "-----------------------" << endl;
	cout << "SIEVE OF ATKIN with map" << endl;
	cout << "-----------------------" << endl;
	int limit = 1e6;
	vector<int> primes = SieveOfAtkin(limit);
	int siz = primes.size();
	cout << "Number of primes obtained is " << siz << endl;
    cout << "Last prime number obtained is " << primes.at(siz-1) << endl;
    //random_shuffle(vector_primes.begin(), vector_primes.end());
	//primes2txt(primes);
    return 0;
}

int naturalNumber(){
    string line;
	regex positive_integer("([0-9]+)", regex::extended);
	while(true){
		cout<<"Input integer [1 < n < 1e10]: "; cin >> line;
		if(!cin) break;
		if(line == "q") break;
		if(regex_match(line, positive_integer) && stoll(line)>1 && stoll(line)<1e10) break;
		else cout<<"Invalid input"<<endl;
	}
	int limit = stoi(line);
	return limit;
}

vector<int> SieveOfAtkin(int limit){
    map<int,bool> sieve;
    sieve[2] = true;
    sieve[3] = true;

    int n;
    for (int x = 1; x*x < limit; x++){
        for (int y = 1; y*y < limit; y++){
            n = (4*x*x)+(y*y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5)){ sieve[n] ^= true; }

            n = (3*x*x)+(y*y);
            if (n <= limit && n % 12 == 7){ sieve[n] ^= true; }

            n = (3*x*x)-(y*y);
            if (x > y && n <= limit && n % 12 == 11){ sieve[n] ^= true; }
        }
    }

    // Mark all multiples of squares as non-prime
    for (int r = 5; r*r < limit; r++){
        if (sieve[r]){
            for (int i = r*r; i < limit; i += r*r){ sieve[i]=false; }
         }
    }

    // Construct vector of primes
    vector<int> primes;
    for(auto elem:sieve)
    if(elem.second){ primes.push_back(elem.first); }

    return primes;
}

void primes2txt(vector<int> vector_primes){
    ofstream outFile("primes.txt");
    for (const auto &e : vector_primes) outFile << e << "\n";
}

void primes2terminal(vector<int> vector_primes){
    for (const auto &e : vector_primes) cout << e << " ";
}
