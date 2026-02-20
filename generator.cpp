#include <bits/stdc++.h>
using namespace std;

void integerGenerator(int n){
    srand(time(NULL));

    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << (rand() % 1000000) << ","; // Random array elements
    }
    cout << endl;
}

// High-precision random number generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string generate_random_string(int length, string charset) {
    string res = "";
    for (int i = 0; i < length; i++) {
        // Pick a random index from the charset
        res += charset[rng() % charset.length()];
    }
    return res;
}


// Function to generate a random binary string of a given length
string generateRandomBinaryString(size_t length) {
    // Use the current time to seed the random number engine for varied results on each run
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed); // Mersenne Twister engine for high quality pseudo-random numbers

    // Define a uniform integer distribution for the range 0 to 1
    std::uniform_int_distribution<int> distribution(0, 1);

    std::string binaryString;
    binaryString.reserve(length); // Reserve memory for efficiency

    // Generate random 0s or 1s and append them to the string
    for (size_t i = 0; i < length; ++i) {
        // Get a random 0 or 1 from the distribution and convert to character '0' or '1'
        binaryString.push_back(distribution(generator) ? '1' : '0');
    }

    return binaryString;
}



int main()
{
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    integerGenerator(10000);

    // cout << generate_random_string(1000, alphabet) << endl;
    // cout << generateRandomBinaryString(100000); 


    return 0;
}