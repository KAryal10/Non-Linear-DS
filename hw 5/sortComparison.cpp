#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void insertionSort(vector<int>& numbers) {
    for (int i = 1; i < numbers.size(); ++i) {
    int j = i;
    
    while (j > 0 && numbers[j] < numbers[j - 1]) {
        int temp = numbers[j];
        numbers[j] = numbers[j - 1];
        numbers[j - 1] = temp;
        --j;
    }
    }
}

void bucketSort(vector<int>& numbers, int numBuckets) {
     if (numbers.size() < 1) {
        return;
    }

    vector<vector<int> > buckets(numBuckets);

    
    int maxValue = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] > maxValue) {
            maxValue = numbers[i];
        }
    }

    
    for (int i = 0; i < numbers.size(); i++) {
        int number = numbers[i];
        int index = int(floor(double(number) * numBuckets / (maxValue + 1)));
        buckets[index].push_back(number);
    }

    for (int i = 0; i < numBuckets; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    numbers.clear();
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            numbers.push_back(buckets[i][j]);
        }
    }
}
void radixSort(vector<int>& numbers) {
    int max = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    for (int exp = 1; max / exp > 0; exp *= 10) {
        vector<int> output(numbers.size());
        vector<int> count(10, 0);
        for (int i = 0; i < numbers.size(); i++) {
            count[(numbers[i] / exp) % 10]++;
        }
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (int i = numbers.size() - 1; i >= 0; i--) {
            output[count[(numbers[i] / exp) % 10] - 1] = numbers[i];
            count[(numbers[i] / exp) % 10]--;
        }
        for (int i = 0; i < numbers.size(); i++) {
            numbers[i] = output[i];
        }
    }
}


void generateRandomVector(vector<int>& numbers, int N) {
    numbers.clear();
    for (int i = 0; i < N; ++i) {
        numbers.push_back(rand() % 1000);
    }
}

double measureTime(vector<int>& numbers, void (*sortFunction)(vector<int>&)) {
    auto start = chrono::high_resolution_clock::now();
    sortFunction(numbers);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
}
double measureTime(void (*sortFunction)(vector<int>&, int), vector<int>& numbers, int numBuckets) {
    auto start = chrono::high_resolution_clock::now();
    sortFunction(numbers, numBuckets);  
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
}

int main() {
    srand(time(nullptr));

    vector<int> insertionNumbers;
    vector<int> bucketNumbers;
    vector<int> radixNumbers;
    int bucketCount = 10;

    int sizes[] = {10, 100, 1000, 10000};
    for (int i = 0; i < 4; ++i) {
        int N = sizes[i];
        double totalInsertionTime = 0.0;
        double totalBucketTime = 0.0;
        double totalRadixTime = 0.0;

        for (int iteration = 0; iteration < 10; ++iteration) {
            
            generateRandomVector(insertionNumbers, N);
            generateRandomVector(bucketNumbers, N);
            generateRandomVector(radixNumbers, N);

            
            totalInsertionTime += measureTime(insertionNumbers, insertionSort);
            totalBucketTime += measureTime(bucketSort, bucketNumbers, 10);
            totalRadixTime += measureTime(radixNumbers, radixSort);
        }

        
        double avgInsertionTime = totalInsertionTime / 10.0;
        double avgBucketTime = totalBucketTime / 10.0;
        double avgRadixTime = totalRadixTime / 10.0;

        cout << "For N = " << N << ":\n";
        cout << "Average Insertion Sort Time: " << avgInsertionTime << " milliseconds\n";
        cout << "Average Bucket Sort Time: " << avgBucketTime << " milliseconds\n";
        cout << "Average Radix Sort Time: " << avgRadixTime << " milliseconds\n\n";
    }

    return 0;
}