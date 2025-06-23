class Solution {
public:
    // Checks if a number is a palindrome in the given base
    bool isPalindromeInBaseK(long long number, int base) {
        // Store the original number for comparison
        long long originalNumber = number;
        // Initialize the reversed number
        long long reversedNumber = 0;

        // Extract digits in the given base and build the reversed number
        while (number > 0) {
            long long digit = number % base; // Get the least significant digit
            reversedNumber = reversedNumber * base + digit; // Shift and add digit
            number /= base; // Remove the processed digit
        }

        // Return true if the reversed number equals the original
        return reversedNumber == originalNumber;
    }

    // Generates a palindrome number in base-10 from a given half
    long long generatePalindrome(long long half, bool isOddLength) {
        // Start with the input number as the half
        long long result = half;
        // If odd length, remove the last digit to avoid duplicating the middle
        if (isOddLength) {
            result /= 10;
        }

        // Build the palindrome by appending reversed digits
        while (result > 0) {
            long long digit = result % 10; // Get the last digit
            half = half * 10 + digit; // Append digit to the right
            result /= 10; // Remove the processed digit
        }

        // Return the generated palindrome
        return half;
    }

    // Finds the sum of the first n palindrome numbers in both base-10 and base-k
    long long kMirror(int k, int n) {
        // Initialize counters and sum
        int palindromeCount = 0; // Count of valid palindromes found
        long long oddHalf = 1; // Half for generating odd-length palindromes
        long long evenHalf = 1; // Half for generating even-length palindromes
        long long totalSum = 0; // Total sum of valid palindromes

        // Generate initial palindromes
        long long oddPalindrome = generatePalindrome(oddHalf, true);
        long long evenPalindrome = generatePalindrome(evenHalf, false);

        // Find n palindrome palindromes that are palindromes in both bases
        while (palindromeCount < n) {
            if (oddPalindrome <= evenPalindrome) {
                // Check if odd palindrome is a palindrome in base k
                if (isPalindromeInBaseK(oddPalindrome, k)) {
                    totalSum += oddPalindrome; // Add to sum
                    palindromeCount++; // Increment counter
                }
                // Generate next odd palindrome
                oddHalf++;
                oddPalindrome = generatePalindrome(oddHalf, true);
            } else {
                // Check if even palindrome is palindrome in base k
                if (isPalindromeInBaseK(evenPalindrome, k)) {
                    totalSum += evenPalindrome; // Add to sum
                    palindromeCount++; // Increment counter
                }
                // Generate next even palindrome
                evenHalf++;
                evenPalindrome = generatePalindrome(evenHalf, false);
            }
        }

        // Return the total sum
        return totalSum;
    }
};