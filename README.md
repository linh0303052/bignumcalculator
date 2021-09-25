# About
This is the implementation of 128-bit integer and 128-bit float. The calculator provides fundmental operations such as: addition, subtraction, multiplication, division and comparison like less than, more than, equal, less than or equal, more than or equal.
Number convertion between Binary, Decimal and Hexadecimal systems are also supported.
For interative calculations, a windows form is available while file handling is used for testing.
# Usage
To open an interactive calculator type:
```
thktmt.exe
```
For testing by file, you need to prepare a text file and ensure each line have the format as follow:
```
1. Convertion:
<original base> <new base> <number in original base>
2. Operation, comparison:
<base> <first operand> <operator> <second operand (if any)>
3. Shift, rotatation:
<base> <operand> <operator> <number of bits>
```
For example:
```
10 2 13470234203402134234234
16 AB45F98A * 2354F33AD
2 10110100001010101000 ror 5
```
Then execute the command
```
thktmt.exe <input file path> <output file path> <type>
```
**type** is 1 for integer mode and 2 for float mode.
