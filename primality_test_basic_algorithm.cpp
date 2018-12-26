#include <math.h>   // sqrt, floor, log10
#include <vector>   // vector
#include <iostream> // cout
#include <fstream>  // ofstream
using namespace std;

// Functions
void printTitle(string title);
bool isPrime(int n);
vector<int> testPrimalityBasic(int limit);
void primes2txt(vector<int> vector_primes);
void primes2terminal(vector<int> vector_primes);

int main(){
    printTitle("PRIMALITY TEST with basic algorithm");
    int limit = 1e7;
    cout << "The limit is 1e" << log10(limit) << endl;
    vector<int> primes = testPrimalityBasic(limit);
    int siz = primes.size();
    cout << "Number of primes obtained is " << siz << endl;
    cout << "Last prime number obtained is " << primes.at(siz-1) << endl;
    return 0;
}

void printTitle(string title){
    int siz = title.size();
    for(int i=0; i<siz; i++){ cout << "-"; } cout << endl;
    cout << title << endl;
    for(int i=0; i<siz; i++){ cout << "-"; } cout << endl;
}

bool isPrime(int n){
    bool resp = true;
    int a = floor(sqrt(n));
    for(int i=3; i<=a; i+=2){
        if(n%i == 0){ return false; }
    }
}

vector<int> testPrimalityBasic(int limit){
    vector<int> primes; primes.push_back(2);
    for(int n=3; n<limit; n+=2){
        if(isPrime(n)){ primes.push_back(n); }
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
