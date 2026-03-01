/*
 * ============================================================
 *                   BIT MANIPULATION NOTES
 * ============================================================
 *
 *  KEY CONCEPTS:
 *  -------------
 *  - Computers store numbers in binary (base 2).
 *  - Bit operators work directly on the binary representation.
 *
 *  OPERATORS:
 *  ----------
 *  &   (AND)  – 1 only when both bits are 1
 *  |   (OR)   – 1 when at least one bit is 1
 *  ^   (XOR)  – 1 when bits are different
 *  ~   (NOT)  – flips every bit (1→0, 0→1)
 *  <<  (Left Shift)  – shifts bits left, fills 0s from right  (×2)
 *  >>  (Right Shift) – shifts bits right, fills 0s from left  (÷2)
 *
 *  USEFUL IDENTITIES:
 *  -------------------
 *  a ^ a  = 0          (any number XOR itself is 0)
 *  a ^ 0  = a          (XOR with 0 is identity)
 *  a & 0  = 0
 *  a | 0  = a
 *  a & 1  = last bit   (used to check odd/even)
 *  1 << i = 2^i        (only the ith bit is set)
 *
 *  TWO'S COMPLEMENT (negative numbers):
 *  ------------------------------------
 *  -x  =  ~x + 1
 *
 * ============================================================
 */

#include <iostream>
using namespace std;

// ============================================================
//  1. CHECK EVEN OR ODD
// ============================================================
// Idea: The last bit (bit 0) of every odd number is 1.
//       n & 1 isolates the last bit.
//       If last bit = 1 → odd, else → even.
//
//  Example:  5 = 101  →  101 & 001 = 001 = 1  → Odd
//            6 = 110  →  110 & 001 = 000 = 0  → Even

bool isOdd(int n)
{
    return (n & 1); // returns true if odd
}

// ============================================================
//  2. GET ith BIT
// ============================================================
// Idea: Create a mask with only the ith bit set  →  (1 << i)
//       AND the number with the mask.
//       If result != 0 → ith bit is 1, else 0.
//
//  Example: n = 13 (1101), i = 2
//           mask = 1 << 2 = 0100
//           1101 & 0100  = 0100 (≠ 0)  → bit is 1

int getIthBit(int n, int i)
{
    int mask = (1 << i);
    return (n & mask) ? 1 : 0;
}

// ============================================================
//  3. SET ith BIT  (make it 1)
// ============================================================
// Idea: OR the number with a mask that has only ith bit set.
//       OR never turns OFF a bit, it only turns ON.
//
//  Example: n = 9 (1001), i = 2
//           mask = 1 << 2 = 0100
//           1001 | 0100  = 1101 = 13

int setIthBit(int n, int i)
{
    int mask = (1 << i);
    return (n | mask);
}

// ============================================================
//  4. CLEAR ith BIT  (make it 0)
// ============================================================
// Idea: Create mask (1 << i), then flip it with NOT (~).
//       AND with n. The AND with 0 at ith position clears it.
//
//  Example: n = 13 (1101), i = 2
//           mask   = 0100
//           ~mask  = 1011
//           1101 & 1011 = 1001 = 9

int clearIthBit(int n, int i)
{
    int mask = ~(1 << i);
    return (n & mask);
}

// ============================================================
//  5. UPDATE ith BIT  (set it to a given value 0 or 1)
// ============================================================
// Idea: First CLEAR the ith bit, then OR with (val << i).
//       This places the desired value at position i.
//
//  Example: n = 13 (1101), i = 1, val = 1
//           After clear bit 1:  1101 & 1101 = 1101 (already 0)
//           → wait, let's redo: 13 = 1101
//           clear bit 1: mask=~(0010)=1101 → 1101 & 1101 = 1101
//           set val:  1101 | (1<<1) = 1101 | 0010 = 1111 = 15

int updateIthBit(int n, int i, int val)
{
    n = clearIthBit(n, i); // first clear
    int mask = (val << i); // place val at ith position
    return (n | mask);
}

// ============================================================
//  6. CLEAR i BITS FROM THE RIGHT (LSB side)
// ============================================================
// Idea: We want to clear bits from position 0 to i-1.
//       Mask = all 1s shifted left by i  →  (~0 << i)
//       or equivalently (-1 << i).
//       AND with n zeros out the last i bits.
//
//  Example: n = 59 (111011), i = 4
//           mask = ~0 << 4 = ...110000
//           111011 & 110000 = 110000 = 48

int clearLastIBits(int n, int i)
{
    int mask = (-1 << i); // same as ~0 << i
    return (n & mask);
}

// ============================================================
//  7. CHECK IF NUMBER IS A POWER OF TWO
// ============================================================
// Idea: Powers of 2 have exactly ONE set bit.
//       e.g., 8 = 1000, 16 = 10000
//       n - 1 flips all bits from the rightmost set bit onward.
//       So  n & (n-1) = 0  for powers of 2.
//
//  Example: n = 16 (10000),  n-1 = 15 (01111)
//           10000 & 01111 = 00000 → Power of 2!
//
//  Edge case: n must be > 0 (0 is not a power of 2).

bool isPowerOfTwo(int n)
{
    return (n > 0) && ((n & (n - 1)) == 0);
}

// ============================================================
//  8. COUNT NUMBER OF SET BITS (1s)  — Brian Kernighan's Algo
// ============================================================
// Idea: n & (n-1) removes the LOWEST set bit each time.
//       Keep doing it until n becomes 0.
//       Count how many times we did it → that's the answer.
//
//  Example: n = 13 (1101)
//           13 & 12 = 1101 & 1100 = 1100 (12) → count=1
//           12 & 11 = 1100 & 1011 = 1000 (8)  → count=2
//            8 &  7 = 1000 & 0111 = 0000 (0)  → count=3
//           Answer = 3
//
//  Time: O(number of set bits) — faster than checking all 32 bits

int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1); // remove lowest set bit
        count++;
    }
    return count;
}

// ============================================================
//  9. FAST EXPONENTIATION  (a^b in O(log b))
// ============================================================
// Idea: Express b in binary. For each bit of b:
//       - If bit is 1 → multiply result by current 'a'
//       - Square 'a' each step, shift b right.
//
//  Example: 3^5,  5 = 101 in binary
//       bit 0 = 1 → ans *= 3  → ans=3,    a=3²=9
//       bit 1 = 0 →            → ans=3,    a=9²=81
//       bit 2 = 1 → ans *= 81 → ans=243,  a=81²=6561
//       Answer = 243 ✓
//
//  Time: O(log b)

long long fastExpo(int a, int b)
{
    long long ans = 1;
    while (b > 0)
    {
        if (b & 1)
        { // if current bit is 1
            ans = ans * a;
        }
        a = a * a; // square the base
        b >>= 1;   // shift to next bit
    }
    return ans;
}

// ============================================================
// 10. CLEAR BITS IN RANGE [i, j]  (inclusive, 0-indexed)
// ============================================================
// Idea: Build a mask that has 0s from bit i to bit j, and 1s
//       everywhere else.
//       → Left part : all 1s above bit j  →  (~0 << (j+1))
//       → Right part: all 1s below bit i  →  (1 << i) - 1
//       Combine: mask = leftPart | rightPart
//       AND with n to clear the range.
//
//  Example: n = 59 (111011), i = 1, j = 3
//       left  = ~0 << 4 = ...110000
//       right = (1<<1)-1 = 000001
//       mask  = 110001
//       111011 & 110001 = 110001 = 49

int clearBitsInRange(int n, int i, int j)
{
    int left = ~(-1 << j);
    int right = -1 << (i + 1);
    int mask = left | right;
    return (n & mask);
}

// ============================================================
//                         DRIVER / MAIN
// ============================================================

int main()
{

    cout << "===== BIT MANIPULATION =====" << endl
         << endl;

    // 1. Even / Odd
    cout << "1. Even/Odd Check" << endl;
    cout << "   7 is " << (isOdd(7) ? "Odd" : "Even") << endl;
    cout << "   12 is " << (isOdd(12) ? "Odd" : "Even") << endl;
    cout << endl;

    // 2. Get ith Bit
    cout << "2. Get ith Bit" << endl;
    cout << "   13 (1101) → bit 2 = " << getIthBit(13, 2) << endl;
    cout << "   13 (1101) → bit 1 = " << getIthBit(13, 1) << endl;
    cout << endl;

    // 3. Set ith Bit
    cout << "3. Set ith Bit" << endl;
    cout << "   9 (1001) → set bit 2 = " << setIthBit(9, 2) << " (1101 = 13)" << endl;
    cout << endl;

    // 4. Clear ith Bit
    cout << "4. Clear ith Bit" << endl;
    cout << "   13 (1101) → clear bit 2 = " << clearIthBit(13, 2) << " (1001 = 9)" << endl;
    cout << endl;

    // 5. Update ith Bit
    cout << "5. Update ith Bit" << endl;
    cout << "   13 (1101) → update bit 1 to 1 = " << updateIthBit(13, 1, 1) << " (1111 = 15)" << endl;
    cout << "   13 (1101) → update bit 2 to 0 = " << updateIthBit(13, 2, 0) << " (1001 = 9)" << endl;
    cout << endl;

    // 6. Clear last i bits
    cout << "6. Clear Last i Bits (from right)" << endl;
    cout << "   59 (111011) → clear last 4 = " << clearLastIBits(59, 4) << " (110000 = 48)" << endl;
    cout << endl;

    // 7. Power of Two
    cout << "7. Power of Two Check" << endl;
    cout << "   16 → " << (isPowerOfTwo(16) ? "Yes" : "No") << endl;
    cout << "   18 → " << (isPowerOfTwo(18) ? "Yes" : "No") << endl;
    cout << endl;

    // 8. Count Set Bits
    cout << "8. Count Set Bits" << endl;
    cout << "   13 (1101) → " << countSetBits(13) << " set bits" << endl;
    cout << "   255 (11111111) → " << countSetBits(255) << " set bits" << endl;
    cout << endl;

    // 9. Fast Exponentiation
    cout << "9. Fast Exponentiation" << endl;
    cout << "   3^5 = " << fastExpo(3, 5) << endl;
    cout << "   2^10 = " << fastExpo(2, 10) << endl;
    cout << endl;

    // 10. Clear Bits in Range [i, j]
    cout << "10. Clear Bits in Range [i, j]" << endl;
    cout << "   59 (111011) → clear [1,3] = " << clearBitsInRange(59, 1, 3) << " (110001 = 49)" << endl;
    cout << endl;

    return 0;
}
