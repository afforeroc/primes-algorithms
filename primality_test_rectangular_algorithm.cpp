#include <math.h>   // sqrt, floor, log10
#include <vector>   // vector
#include <iostream> // cout
#include <fstream>  // ofstream
using namespace std;

// Functions
void printTitle(string title);
bool isPrimeR(int n);
vector<int> testPrimalityRectangular(int limit);
void primes2txt(vector<int> primes);
void primes2terminal(vector<int> primes);

int main(){
    printTitle("PRIMALITY TEST with rectangular algorithm");
    int limit = 1e6;
    cout << "Limit is 1e" << log10(limit) << endl;
    vector<int> primes = testPrimalityRectangular(limit);
    cout << "Number of primes obtained is " << primes.size() << endl;
    cout << "Last prime number obtained is " << primes.back() << endl;
    primes2txt(primes);
    return 0;
}

void printTitle(string title){
    for(int i=0; i<title.size(); i++){ cout << "-"; } cout << endl;
    cout << title << endl;
    for(int i=0; i<title.size(); i++){ cout << "-"; } cout << endl;
}

bool isPrimeR(int n){
    bool resp = true;
    int a = floor(sqrt(n)); //raiz inicial
    int h;
    for(int i=3; i*i<n; i+=2){
        h = n-i*i; //residuo
        if (h%i == 0){ return false; }
    }
    return resp;
}

vector<int> testPrimalityRectangular(int limit){
    vector<int> primes; primes.push_back(2);
    for(int n=3; n<limit; n+=2){
        if(isPrimeR(n)){ primes.push_back(n); }
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
