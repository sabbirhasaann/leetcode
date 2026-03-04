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



#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

/**
 * Generates an m x n binary matrix.
 * @param rows Number of rows
 * @param cols Number of columns
 * @param density A value between 0 and 100 (percentage of 1s)
 */
vector<vector<int>> generateMatrix(int rows, int cols, int density) {
    vector<vector<int>> mat(rows, vector<int>(cols, 0));
    
    // Use a random device and mt19937 for better randomness than rand()
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (dis(gen) <= density) {
                mat[i][j] = 1;
            }
        }
    }
    return mat;
}

void printMatrix(const vector<vector<int>>& mat) {
    cout << "{" << endl;
    for (int i = 0; i < mat.size(); ++i) {
        cout << "  {";
        for (int j = 0; j < mat[i].size(); ++j) {
            cout << mat[i][j] << (j == mat[i].size() - 1 ? "" : ",");
        }
        cout << "}" << (i == mat.size() - 1 ? "" : ",") << endl;
    }
    cout << "}" << endl;
}




int main()
{
    // string alphabet = "abcdefghijklmnopqrstuvwxyz";
    // integerGenerator(10000);

    // cout << generate_random_string(1000, alphabet) << endl;
    // cout << generateRandomBinaryString(500000); 

    int m = 5, n = 5;
    int density = 15; // 15% chance for any cell to be 1

    cout << "Generated Matrix (" << m << "x" << n << "):" << endl;
    vector<vector<int>> myMat = generateMatrix(m, n, density);
    printMatrix(myMat);


    return 0;
}