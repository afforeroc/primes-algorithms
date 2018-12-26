#include <math.h>   // sqrt, floor, log10
#include <vector>   // vector
#include <iostream> // cout
#include <fstream>  // ofstream
using namespace std;

// Functions
void printTitle(string title);
bool isPrimeR(int n);
vector<int> testPrimalityR(int limit);
void primes2txt(vector<int> vector_primes);
void primes2terminal(vector<int> vector_primes);

int main(){
    printTitle("PRIMALITY TEST with rectangular algorithm");
    int limit = 1e7;
    cout << "The limit is 1e" << log10(limit) << endl;
    vector<int> primes = testPrimalityR(limit);
    int siz = primes.size();
    cout << "Number of primes obtained is " << siz << endl;
    cout << "Last prime number obtained is " << primes.at(siz-1) << endl;
    primes2txt(primes);
    return 0;
}

void printTitle(string title){
    int siz = title.size();
    for(int i=0; i<siz; i++){ cout << "-"; } cout << endl;
    cout << title << endl;
    for(int i=0; i<siz; i++){ cout << "-"; } cout << endl;
}

bool isPrimeR(int n){
    bool resp = true;
    int a = floor(sqrt(n)); //raiz inicial
    int h;
    for(int i=3; i<=a; i+=2){
        h = n-i*i; //residuo
        if (h%i == 0){ return false; }
    }
    return resp;
}

vector<int> testPrimalityR(int limit){
    vector<int> primes; primes.push_back(2);
    for(int n=3; n<limit; n+=2){
        if(isPrimeR(n)){ primes.push_back(n); }
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
