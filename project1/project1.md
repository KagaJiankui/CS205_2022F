# CS205 Project 1

## Analysis

### Data Type Parsing

The possible valid inputs of the program can be limited to these following terms:

1. Pure integers
   1. normal integers ($<2^{32}\approx 2.14e9$)
   2. large integers ($<2^{64}$)
   3. exceeding/arbitrary accuracy integers($>2^{64}$)
2. Dot decimals
   1. normal decimals ($<3.4e38$)
   2. arbitrary decimals ($>3.4e38$)
   3. IEEE 754 floats
   4. arbitrary IEEE 754 floats

Otherwise, the inputs are invalid, such as

```bash
./mul 狗 猫 鼠
./mul 11.4e51.4 19.19e8.10
./mul +E12 -E-0.45
```

To adopt the `atoll` and `atod` functions, the types of the input arguments must be determined prior to the conversion from the string. Examining the current word and the next word in the input string effectively determines the validity of the string and the type of the numerical value in it.

``` bash
       ∇ NEXT WORD
-----------
| w0 | w1 |
-----------
  ∆ CURRENT WORD
```

For the valid inputs listed above, the possible combinations of the two adjacent words can be listed in an checkerboard below, where the return values is listed.

|   w0/w1   | digit | +,- | .  | E  | other |
|-----------|-------|-----|----|----|-------|
| **digit** |   u   | -1  | u  | u  |  -1   |
|  **+,-**  |   u   | -1  | -1 | -1 |  -1   |
|   **.**   |   1   | -1  | -1 | -1 |  -1   |
|   **E**   |   u   |  u  | -1 | -1 |  -1   |
| **other** |  -1   | -1  | -1 | -1 |  -1   |

**Return Values**

- -1:Invalid input
- 0:Integer(longlong,arbitrary)
- 1:double(double,IEEE 754,arbitrary)
- u:uncertain with current words

With the truth table above, the data type of the input argument can be roughly determined with a if-else tree, even though the fine decision between different types of integers or doubles needs a finer discrimination.

```cpp
flag_u=0;
flag_other=(!isdigit(*str))&&(*str!='+')&&(*str!='-')&&(*str!='.')&&(*str!='E')&&(*str!='e');
if(flag_other) return -1;
if(*str=="."){
    if(isdigit(*(str+1))) flag_u+=1;
    return -1;
}
if((*str=='E')||(*(str+1)=='e')){
    if((isdigit(*(str+1)))||(*(str+1)=='+')||(*(str+1)=='-')) flag_u+=1;
    return -1;
}
if((*str=='+')||*(str=='-')){
    if(isdigit(*(str+1))) flag_u+=1;
    return -1;
}
if(isdigit(*str)){
    if((*(str+1)=='+')||(*(str+1)=='-')||flag_other) return -1;
    flag_u+=1;
}
return flag_u;
```
