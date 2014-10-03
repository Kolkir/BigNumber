BigNumber
=========

# -- Project is under development -- #

C++ library for working with unbounded unsigned integers. 

Now supports:  
- **Individual bits** operations: set, get, reset, toggle
- **Shift** operations: <<, >>, <<=, >>=
- **Bits counting** operations: total bits number
- Initialization **from string**: decimal number string, binary number string
- Converting **to string**: decimal number string, binary number string
- **Binary operations**: ~, &, |, ^, &=, |=, ^=
- **Comparison opeartions**: <, >, <=, >=, ==, !=
- **Arithmetic opeartions**: +, -, +=, -=, *, /, %, *=, /=, %=
- **Increment operations**(post and pre): ++, --

Planned:
- compact representation for serializing
- Cross platfrom support
- Make performace comparable to [gmplib](https://gmplib.org/)
