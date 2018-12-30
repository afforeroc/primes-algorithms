#define WINVER 0x0500
#include <iostream> // cout
#include <vector>   // vector
#include <cmath>    // log10
#include <fstream>  // ofstream
#include <regex>    // regex
#include <windows.h>
#define DIV (1024*1024*1014) // Use to convert bytes to GB
using namespace std;

// Functions
void printTitle(string title);
long long naturalNumber();
double bool2Memory(long long limit);
double freeMemory();
vector<long long> sieveOfAtkin(long long limit);
void primes2txt(vector<long long> vector_primes);
void primes2terminal(vector<long long> vector_primes);

int main(){
	printTitle("SIEVE OF ATKIN with array");
	cout << "LLONG_MAX is\t" << LLONG_MAX << endl;
	long long limit = 1e10; // LONG_MAX, ULONG_MAX
    cout << "Limit is\t" << limit << endl;
    double requiredMemory = bool2Memory(limit);
    double availableMemory = freeMemory();
    printf ("Required memory is %.2f GB\n", requiredMemory);
    printf ("Available memory is %.2f GB\n", availableMemory);
    if(requiredMemory  >= availableMemory){ cout << "There is not enough memory" << endl; }
    vector<long long> primes = sieveOfAtkin(limit);
    cout << "Number of primes obtained is " << primes.size() << endl;
    cout << "Last prime number obtained is " << primes.back() << endl;
    //random_shuffle(vector_primes.begin(), vector_primes.end());
    //primes2txt(primes);
    return 0;
}

void printTitle(string title){
    for(long i=0; i<title.size(); i++){ cout << "-"; } cout << endl;
    cout << title << endl;
    for(long long i=0; i<title.size(); i++){ cout << "-"; } cout << endl;
}

long long naturalNumber(){
    string line;
	regex positive_integer("([0-9]+)", regex::extended);
	while(true){
		cout<<"Input integer [1 < n < 1e10]: "; cin >> line;
		if(!cin) break;
		if(line == "q") break;
		if(regex_match(line, positive_integer) && stoll(line)>1 && stoll(line)<1e10) break;
		else cout<<"Invalid input"<<endl;
	}
	long long limit = stoi(line);
	return limit;
}

double bool2Memory(long long limit){
    return limit*sizeof(bool)*1.0/DIV;
}

double freeMemory(){
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof (statex);
    GlobalMemoryStatusEx (&statex);
    return statex.ullAvailPhys*1.0/DIV;
}

vector<long long> sieveOfAtkin(long long limit){
    bool *sieve = new bool [limit]; 		// Create the sieve array
    memset(sieve, 0, limit*sizeof(bool)); 	// Initialize the sieve array with false values
    sieve[2] = true;
    sieve[3] = true;

    long long n;
    for (long long x = 1; x*x < limit; x++){
        for (long long y = 1; y*y < limit; y++){
            n = (4*x*x)+(y*y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5)){ sieve[n] ^= true; }

            n = (3*x*x)+(y*y);
            if (n <= limit && n % 12 == 7){ sieve[n] ^= true; }

            n = (3*x*x)-(y*y);
            if (x > y && n <= limit && n % 12 == 11){ sieve[n] ^= true; }
        }
    }

    cout << "Corte I" << endl;

    // Mark all multiples of squares as non-prime
    for (long long r = 5; r*r < limit; r++){
        if (sieve[r]){
            //i>0, if r*r or i += r*r overflow the max value of type data
            for (long long i = r*r; i> 0 && i < limit && i; i += r*r){ sieve[i] = false; }
         }
    }
    cout << "Corte II" << endl;

    // Construct vector of primes
    vector<long long> primes;
    for (long long a = 0; a < limit; a++){
        if (sieve[a]){ primes.push_back(a); }
    }
    cout << "Corte III" << endl;

    // Deallocate memory block
    delete [] sieve;
    return primes;
}

void primes2txt(vector<long long> primes){
    ofstream outFile("primes.txt");
    for (const auto &e : primes) outFile << e << "\n";
}

void primes2terminal(vector<long long> primes){
    for (const auto &e : primes) cout << e << " ";
}
