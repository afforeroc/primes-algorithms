#include <math.h>       // sqrt, floor
#include <vector>   	// vector
#include <fstream>		// ofstream
#include <iostream> 	// cout
#include <vector>   	// vector
#include <string.h> 	// memset
#include <time.h>		// clock, clock_t
#include <stdio.h>		// printf
#include <cmath>		// log10
#include <fstream>		// ofstream
using namespace std;

// Functions
bool isPrime(int n);
vector<int> testPrimalityBasic(int limit);
void primes2txt(vector<int> vector_primes);
void primes2terminal(vector<int> vector_primes);

int main(){
    cout << "-----------------------------------" << endl;
	cout << "PRIMALITY TEST with basic algorithm" << endl;
	cout << "-----------------------------------" << endl;
    int limit = 1e6;
    vector<int> primes = testPrimalityBasic(limit);
    int siz = primes.size();
    cout << "Number of primes obtained is " << siz << endl;
    cout << "Last prime number obtained is " << primes.at(siz-1) << endl;
    //random_shuffle(vector_primes.begin(), vector_primes.end());
    //primes2txt(primes);
    return 0;
}

bool isPrime(int n){
    bool resp = true;
    int a = floor(sqrt(n));
    for(int i=3; i<=a; i+=2){
        if(n%i==0){
            resp = false;
            break;
        }
    }
}

vector<int> testPrimalityBasic(int limit){
    vector<int> primes;
    primes.push_back(2);
    for(int n=3; n<limit; n+=2){
        if(isPrime(n)){
            primes.push_back(n);
        }
    }
    return primes;
}

void primes2txt(vector<int> vector_primes){
    ofstream outFile("primes.txt");
    for (const auto &e : vector_primes) outFile << e << "\n";
}

void primes2terminal(vector<int> vector_primes){
    for (const auto &e : vector_primes) cout << e << " ";
}
