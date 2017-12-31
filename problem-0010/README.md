# Problem

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

# Solution
A naive solution would be to have a function that determines whether or not a number is prime and apply that function to every number from 1 to N. If the number is prime, the value is added to a sum. 

We can immediately decrease the quantity of numbers we need to check if we skip multiples of small prime numbers like 2, 3, 5, 7, 11, etc. We want to skip them without a conditional if possible.


