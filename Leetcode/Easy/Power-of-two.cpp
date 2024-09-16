#include <iostream>
using namespace std;

/* Understanding the logic:
For powers of 2:
In binary representation, powers of 2 have only one bit set to 1 (all other bits are 0).
When you subtract 1 from a power of 2, you flip the rightmost 1 to 0 and turn all trailing 0s to 1s.
Performing a bitwise AND between these two numbers will result in all bits being 0, because only the rightmost bits will differ.
Therefore, (n & (n-1)) == 0 will be true for powers of 2.

For other numbers:
If n is not a power of 2, it will have multiple 1s in its binary representation.
Subtracting 1 will flip one of the 1s to 0 but leave at least one other 1 in its place.
The bitwise AND between n and n-1 will therefore not be all zeros, and (n & (n-1)) == 0 will be false.

Eg:n=16(10000) , n-1=15(01111)
 (10000)&(01111) = 00000  true

 n=15(1111),n-1=14(1110)
 (1111)&(1110) = (1110)  (all bits are not zero) false
*/

/* Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x.

Example 1:
Input: n = 1
Output: true
Explanation: 2^0 = 1

Example 2:
Input: n = 16
Output: true
Explanation: 2^4 = 16

Example 3:
Input: n = 3
Output: false

Constraints:
-231 <= n <= 231 - 1    */

bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;

    return (n & (n - 1)) == 0;
}

int main()
{
    cout << isPowerOfTwo(4) << endl;
    cout << isPowerOfTwo(7) << endl;
    cout << isPowerOfTwo(100) << endl;
    cout << isPowerOfTwo(64) << endl;
    return 0;
}