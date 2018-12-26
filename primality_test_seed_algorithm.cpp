#include <math.h>   // sqrt, floor, log10
#include <vector>   // vector
#include <iostream> // cout
#include <fstream>  // ofstream
using namespace std;

// Functions
void printTitle(string title);
bool isPrimeS(int n, vector<int> primes);
vector<int> testPrimalitySeed(int limit);
void primes2txt(vector<int> vector_primes);
void primes2terminal(vector<int> vector_primes);

int main(){
    printTitle("PRIMALITY TEST with seed algorithm");
    int limit = 1e7;
    cout << "Limit is 1e" << log10(limit) << endl;
    vector<int> primes = testPrimalitySeed(limit);
    cout << "Number of primes obtained is " << primes.size() << endl;
    cout << "Last prime number obtained is " << primes.back() << endl;
    primes2txt(primes);
    return 0;
}

void printTitle(string title){
    int siz = title.size();
    for(int i=0; i<siz; i++){ cout << "-"; } cout << endl;
    cout << title << endl;
    for(int i=0; i<siz; i++){ cout << "-"; } cout << endl;
}

bool isPrimeS(int n, vector<int> primes){
    int a = floor(sqrt(n));
    for (const auto &e : primes){
        if(e<=a){if(n%e == 0){ return false; } }
    }
    return true;
}

vector<int> testPrimalitySeed(int limit){
    vector<int> primes;
    primes.push_back(3); // 3 is the seed
    for(int n=5; n<limit; n+=2){
        if(isPrimeS(n, primes)){ primes.push_back(n); }
    }
    primes.insert(primes.begin(),2);
    return primes;
}

void primes2txt(vector<int> primes){
    ofstream outFile("primes.txt");
    for (const auto &e : primes) outFile << e << "\n";
}

void primes2terminal(vector<int> primes){
    for (const auto &e : primes) cout << e << " ";
}
