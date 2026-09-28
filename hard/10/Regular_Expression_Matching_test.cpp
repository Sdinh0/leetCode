#include <string>
#include <iostream>
#include <cassert>
#include "Regular_Expression_Matching.cpp"
using namespace std;

int main() {
    Solution solution;

    // ============ Given Examples ============
    cout << "Testing given examples..." << endl;
    
    // Example 1: "aa" does not match "a"
    assert(solution.isMatch("aa", "a") == false);
    cout << "✓ Example 1: isMatch(\"aa\", \"a\") = false" << endl;

    // Example 2: "aa" matches "a*"
    assert(solution.isMatch("aa", "a*") == true);
    cout << "✓ Example 2: isMatch(\"aa\", \"a*\") = true" << endl;

    // Example 3: "ab" matches ".*"
    assert(solution.isMatch("ab", ".*") == true);
    cout << "✓ Example 3: isMatch(\"ab\", \".*\") = true" << endl;

    // ============ Edge Cases ============
    cout << "\nTesting edge cases..." << endl;

    // Empty string with empty pattern
    assert(solution.isMatch("", "") == true);
    cout << "✓ Empty string and empty pattern match" << endl;

    // Empty string with non-empty pattern (pattern with * only)
    assert(solution.isMatch("", "a*") == true);
    cout << "✓ Empty string matches \"a*\"" << endl;

    // Empty string with non-empty pattern (without *)
    assert(solution.isMatch("", "a") == false);
    cout << "✓ Empty string doesn't match \"a\"" << endl;

    // Non-empty string with empty pattern
    assert(solution.isMatch("a", "") == false);
    cout << "✓ String \"a\" doesn't match empty pattern" << endl;

    // Single character match
    assert(solution.isMatch("a", "a") == true);
    cout << "✓ \"a\" matches \"a\"" << endl;

    // Dot matches any single character
    assert(solution.isMatch("a", ".") == true);
    cout << "✓ \"a\" matches \".\"" << endl;

    // Dot doesn't match empty
    assert(solution.isMatch("", ".") == false);
    cout << "✓ Empty string doesn't match \".\"" << endl;

    // ============ Star Pattern Cases ============
    cout << "\nTesting star patterns..." << endl;

    // Star matching zero occurrences
    assert(solution.isMatch("b", "a*b") == true);
    cout << "✓ \"b\" matches \"a*b\" (zero a's)" << endl;

    // Star matching multiple occurrences
    assert(solution.isMatch("aaa", "a*") == true);
    cout << "✓ \"aaa\" matches \"a*\" (multiple a's)" << endl;

    // Multiple stars
    assert(solution.isMatch("aa", "a*a*") == true);
    cout << "✓ \"aa\" matches \"a*a*\"" << endl;

    // Multiple different stars
    assert(solution.isMatch("mississippi", "mis*is*p*.") == false);
    cout << "✓ \"mississippi\" matches \"mis*is*p*.\"" << endl;

    // Star with dot
    assert(solution.isMatch("abc", "a.*") == true);
    cout << "✓ \"abc\" matches \"a.*\"" << endl;

    // Dot star (match zero or more of any character)
    assert(solution.isMatch("", ".*") == true);
    cout << "✓ Empty string matches \".*\"" << endl;

    assert(solution.isMatch("abc", ".*") == true);
    cout << "✓ \"abc\" matches \".*\"" << endl;

    // ============ Complex Patterns ============
    cout << "\nTesting complex patterns..." << endl;

    // Pattern with dot and specific characters
    assert(solution.isMatch("abc", "a.c") == true);
    cout << "✓ \"abc\" matches \"a.c\"" << endl;

    assert(solution.isMatch("axc", "a.c") == true);
    cout << "✓ \"axc\" matches \"a.c\"" << endl;

    assert(solution.isMatch("ac", "a.c") == false);
    cout << "✓ \"ac\" doesn't match \"a.c\"" << endl;

    // Multiple characters followed by star
    assert(solution.isMatch("ab", "ab*") == true);
    cout << "✓ \"ab\" matches \"ab*\"" << endl;

    assert(solution.isMatch("abbb", "ab*") == true);
    cout << "✓ \"abbb\" matches \"ab*\"" << endl;

    // ============ Mismatch Cases ============
    cout << "\nTesting mismatch cases..." << endl;

    // Partial match not allowed
    assert(solution.isMatch("aa", "aaa") == false);
    cout << "✓ \"aa\" doesn't match \"aaa\"" << endl;

    // Pattern doesn't cover entire string
    assert(solution.isMatch("abc", "ab") == false);
    cout << "✓ \"abc\" doesn't match \"ab\"" << endl;

    // Wrong character
    assert(solution.isMatch("ab", "ac") == false);
    cout << "✓ \"ab\" doesn't match \"ac\"" << endl;

    // Star for wrong character prefix
    assert(solution.isMatch("aa", "b*a") == false);
    cout << "✓ \"aa\" doesn't match \"b*a\" (needs two a's, pattern has one)" << endl;

        // Star for wrong character prefix
    assert(solution.isMatch("aa", "b*aa") == true);
    cout << "✓ \"aa\" doesn't match \"b*aa\" (needs two a's, pattern has two)" << endl;
    // ============ Backtracking Cases ============
    cout << "\nTesting backtracking scenarios..." << endl;

    // Needs backtracking
    assert(solution.isMatch("aab", "c*a*b") == true);
    cout << "✓ \"aab\" matches \"c*a*b\" (backtracking needed)" << endl;

    assert(solution.isMatch("aa", "a*aa") == true);
    cout << "✓ \"aa\" doesn't match \"a*aa\" (needs proper backtracking)" << endl;

    // Long string with star
    assert(solution.isMatch("aaaaaaaaaaaaaaaaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*a*a*a*b") == true);
    cout << "✓ Long string with multiple a's and stars matches" << endl;

    cout << "\n✅ All tests passed!" << endl;
    return 0;
}
