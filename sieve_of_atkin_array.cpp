#include <iostream> // cout
#include <vector>   // vector
#include <cmath>    // log10
#include <fstream>  // ofstream
#include <regex>    // regex

#define WINVER 0x0500
#include <windows.h>

#define DIV (1024*1024*1014) // Use to convert bytes to GB

using namespace std;

// Functions
void printTitle(string title);
int naturalNumber();
double bool2Memory(unsigned long limit);
double freeMemory();
vector<int> SieveOfAtkin(int limit);
void primes2txt(vector<int> vector_primes);
void primes2terminal(vector<int> vector_primes);


int main(){
	printTitle("SIEVE OF ATKIN with array");
	unsigned long limit = ULONG_MAX; // INT_MAX, ULONG_MAX
    cout << "Limit is " << limit << endl;
    double requiredMemory = bool2Memory(limit);
    double availableMemory = freeMemory();

    printf ("Required memory is %.2f GB\n", requiredMemory);
    printf ("Available memory is %.2f GB\n", availableMemory);

    if(requiredMemory  >= availableMemory){
        cout << "There is not enough memory" << endl;

    }

    vector<int> primes = SieveOfAtkin(limit);
    cout << "Number of primes obtained is " << primes.size() << endl;
    cout << "Last prime number obtained is " << primes.back() << endl;
    //random_shuffle(vector_primes.begin(), vector_primes.end());
    primes2txt(primes);
    return 0;
}

void printTitle(string title){
    for(int i=0; i<title.size(); i++){ cout << "-"; } cout << endl;
    cout << title << endl;
    for(int i=0; i<title.size(); i++){ cout << "-"; } cout << endl;
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

double bool2Memory(unsigned long limit){
    return limit*sizeof(bool)*1.0/DIV;
}
double freeMemory(){
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof (statex);
    GlobalMemoryStatusEx (&statex);
    return statex.ullAvailPhys*1.0/DIV;
}


vector<int> SieveOfAtkin(int limit){
    bool *sieve = new bool [limit]; 		// Create the sieve array
    memset(sieve, 0, limit*sizeof(bool)); 	// Initialize the sieve array with false values
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
            for (int i = r*r; i < limit; i += r*r){ sieve[i] = false; }
         }
    }

    // Construct vector of primes
    vector<int> primes;
    for (int a = 0; a < limit; a++){
        if (sieve[a]){ primes.push_back(a); }
    }

    // Deallocate memory block
    delete [] sieve;

    return primes;
}

void primes2txt(vector<int> primes){
    ofstream outFile("primes.txt");
    for (const auto &e : primes) outFile << e << "\n";
}

void primes2terminal(vector<int> primes){
    for (const auto &e : primes) cout << e << " ";
}
