#include <math.h>   // sqrt, floor, log10
#include <vector>   // vector
#include <iostream> // cout
#include <fstream>  // ofstream
using namespace std;

// Functions
void printTitle(string title);
bool isPrimeB(int n);
vector<int> testPrimalityBasic(int limit);
void primes2txt(vector<int> primes);
void primes2terminal(vector<int> primes);

int main(){
    printTitle("PRIMALITY TEST with basic algorithm");
    int limit = 1e8;
    cout << "Limit is 1e" << log10(limit) << endl;
    vector<int> primes = testPrimalityBasic(limit);
    cout << "Number of primes obtained is " << primes.size() << endl;
    cout << "Last prime number obtained is " << primes.back() << endl;
    //primes2terminal(primes);
    return 0;
}

void printTitle(string title){
    for(int i=0; i<title.size(); i++){ cout << "-"; } cout << endl;
    cout << title << endl;
    for(int i=0; i<title.size(); i++){ cout << "-"; } cout << endl;
}

bool isPrimeB(int n){
    int k = n+1;
    for(int i=3; i*i<k; i+=2){
        if(n%i == 0){ return false; }
    }
    return true;
}

vector<int> testPrimalityBasic(int limit){
    vector<int> primes;
    for(int n=1; n<limit; n+=2){
        if(isPrimeB(n)){ primes.push_back(n); }
    }
    return primes;
}

void primes2txt(vector<int> primes){
    ofstream outFile("primes.txt");
    for (const auto &e : primes) outFile << e << "\n";
}

void primes2terminal(vector<int> primes){
    for (const auto &e : primes) cout << e << " ";
}
