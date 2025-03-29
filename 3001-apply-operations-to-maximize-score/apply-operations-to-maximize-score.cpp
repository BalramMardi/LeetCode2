class Solution {
public:
    const int MOD = 1e9 + 7;

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> primeScores(n);

        // Calculate the prime score for each number in nums
        for (int index = 0; index < n; index++) {
            int num = nums[index];

            // Check for prime factors from 2 to sqrt(n)
            for (int factor = 2; factor <= sqrt(num); factor++) {
                if (num % factor == 0) {
                    // Increment prime score for each prime factor
                    primeScores[index]++;

                    // Remove all occurrences of the prime factor from num
                    while (num % factor == 0) num /= factor;
                }
            }

            // If num is still greater than or equal to 2, it's a prime factor
            if (num >= 2) primeScores[index]++;
        }

        // Initialize next and previous dominant index arrays
        vector<int> nextDominant(n, n);
        vector<int> prevDominant(n, -1);

        // Stack to store indices for monotonic decreasing prime score
        stack<int> decreasingPrimeScoreStack;

        // Calculate the next and previous dominant indices for each number
        for (int index = 0; index < n; index++) {
            // While the stack is not empty and the current prime score is
            // greater than the stack's top
            while (!decreasingPrimeScoreStack.empty() &&
                   primeScores[decreasingPrimeScoreStack.top()] <
                       primeScores[index]) {
                int topIndex = decreasingPrimeScoreStack.top();
                decreasingPrimeScoreStack.pop();

                // Set the next dominant element for the popped index
                nextDominant[topIndex] = index;
            }

            // If the stack is not empty, set the previous dominant element for
            // the current index
            if (!decreasingPrimeScoreStack.empty())
                prevDominant[index] = decreasingPrimeScoreStack.top();

            // Push the current index onto the stack
            decreasingPrimeScoreStack.push(index);
        }

        // Calculate the number of subarrays in which each element is dominant
        vector<long long> numOfSubarrays(n);
        for (int index = 0; index < n; index++) {
            numOfSubarrays[index] = (long long)(nextDominant[index] - index) *
                                    (index - prevDominant[index]);
        }

        // Priority queue to process elements in decreasing order of their value
        priority_queue<pair<int, int>> processingQueue;

        // Push each number and its index onto the priority queue
        for (int index = 0; index < n; index++)
            processingQueue.push({nums[index], index});

        long long score = 1;

        // Process elements while there are operations left
        while (k > 0) {
            // Get the element with the maximum value from the queue
            auto [num, index] = processingQueue.top();
            processingQueue.pop();

            // Calculate the number of operations to apply on the current
            // element
            long long operations = min((long long)k, numOfSubarrays[index]);

            // Update the score by raising the element to the power of
            // operations
            score = (score * power(num, operations)) % MOD;

            // Reduce the remaining operations count
            k -= operations;
        }

        return score;
    }

private:
    // Helper function to compute the power of a number modulo MOD
    long long power(long long base, long long exponent) {
        long long res = 1;

        // Calculate the exponentiation using binary exponentiation
        while (exponent > 0) {
            // If the exponent is odd, multiply the result by the base
            if (exponent % 2 == 1) {
                res = ((res * base) % MOD);
            }

            // Square the base and halve the exponent
            base = (base * base) % MOD;
            exponent /= 2;
        }

        return res;
    }
};


/* class Solution {
public:
    const int MOD = 1e9 + 7;

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> primeScores(n, 0);

        //range ke liye
        int maxElement = 0;
        for (int index = 0; index < n; index++) {
            maxElement = max(maxElement, nums[index]);
        }

        //saare prime nikal le
        vector<int> primes = getPrimes(maxElement);

        //prime score 
        for (int index = 0; index < n; index++) {
            int num = nums[index];

            //unique prime factors khojo
            for (int prime : primes) {
                if (prime * prime > num)
                    break;  
                if (num % prime != 0)
                    continue;  // agar prime is not a factor then skip

                primeScores[index]++;  // Increment prime score for the factor
                while (num % prime == 0)
                    num /= prime;  // Remove all occurrences of this factor
            }
            //agar num>1 tab wo khud prime number hai
            if (num > 1) primeScores[index]++;
        }

        // Initialize next and previous dominant index arrays
        vector<int> nextDominant(n, n);
        vector<int> prevDominant(n, -1);

        // Stack to store indices for a monotonic decreasing prime score
        stack<int> decreasingPrimeScoreStack;

        // Calculate the next and previous dominant indices for each number
        for (int index = 0; index < n; index++) {
            // While the stack is not empty and the current prime score is
            // greater than the stack's top, update nextDominant
            while (!decreasingPrimeScoreStack.empty() &&
                   primeScores[decreasingPrimeScoreStack.top()] <
                       primeScores[index]) {
                int topIndex = decreasingPrimeScoreStack.top();
                decreasingPrimeScoreStack.pop();

                // Set the next dominant element for the popped index
                nextDominant[topIndex] = index;
            }

            // If the stack is not empty, set the previous dominant element for
            // the current index
            if (!decreasingPrimeScoreStack.empty())
                prevDominant[index] = decreasingPrimeScoreStack.top();

            // Push the current index onto the stack
            decreasingPrimeScoreStack.push(index);
        }

        // Calculate the number of subarrays in which each element is dominant
        vector<long long> numOfSubarrays(n);
        for (int index = 0; index < n; index++) {
            numOfSubarrays[index] = (long long)(nextDominant[index] - index) *
                                    (index - prevDominant[index]);
        }

        // Sort elements in decreasing order based on their values
        vector<pair<int, int>> sortedArray(n);
        for (int index = 0; index < n; index++) {
            sortedArray[index] = {nums[index], index};
        }

        sort(sortedArray.begin(), sortedArray.end(), greater<>());

        long long score = 1;
        int processingIndex = 0;

        // Process elements while there are operations left
        while (k > 0) {
            // Get the element with the maximum value
            auto [num, index] = sortedArray[processingIndex++];

            // Calculate the number of operations to apply on the current
            // element
            long long operations = min((long long)k, numOfSubarrays[index]);

            // Update the score by raising the element to the power of
            // operations
            score = (score * power(num, operations)) % MOD;

            // Reduce the remaining operations count
            k -= operations;
        }

        return score;
    }

private:
    // Helper function to compute the power of a number modulo MOD
    long long power(long long base, long long exponent) {
        long long res = 1;

        // Calculate the exponentiation using binary exponentiation
        while (exponent > 0) {
            // If the exponent is odd, multiply the result by the base
            if (exponent % 2 == 1) {
                res = ((res * base) % MOD);
            }

            // Square the base and halve the exponent
            base = (base * base) % MOD;
            exponent /= 2;
        }

        return res;
    }

    vector<int> getPrimes(int limit) {
        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;

      
        for (int number = 2; number <= limit; number++) {
            if (!isPrime[number]) continue;
            primes.push_back(number);
            for (long long multiple = (long long)number * number;
                 multiple <= limit; multiple += number) {
                isPrime[multiple] = false;
            }
        }

        return primes;
    }
}; */