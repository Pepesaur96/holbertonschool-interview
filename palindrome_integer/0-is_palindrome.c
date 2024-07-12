#include "palindrome.h"

/**
 * is_palindrome - Check if a given number is a palindrome
 *
 * @n: Number to check
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
    unsigned long reversed = 0, remainder, original = n;

    while (n != 0)
    {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    return (original == reversed);
}
