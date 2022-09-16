# CS205 Project 1

## Analysis

### Data Type Classification
The possible valid inputs of the program can be limited to these following terms:

1. Pure integers
   1. normal integers ($<2^{32}\approx 2.14e9$)
   2. large integers ($<2^{64}$)
   3. exceeding/arbitrary accuracy integers($>2^{64}$)
2. Dot decimals
   1. normal decimals ($<1.7e308$)
   2. arbitrary decimals ($>1.7e308$)
   3. IEEE 754 floats
   4. arbitrary IEEE 754 floats ($>1.7e308$)

Otherwise, the inputs are invalid, such as

```bash
./mul 狗 猫 鼠
./mul 11.4e51.4 19.19e8.10
./mul +E12 -E-0.45
```

### Parsing Mechanism Design

To adopt the `atoll` and `atod` functions, the types of the input arguments must be determined prior to the conversion from the string. Examining the current word and the next word in the input string effectively determines the validity of the string and the type of the numerical value in it.

``` bash
       ∇ NEXT WORD
-----------
| w0 | w1 |
-----------
  ∆ CURRENT WORD
```

#### Truth Table

For the valid inputs listed above, the possible combinations of the two adjacent words can be listed in an **truth table** below, where the return values is listed.

|   w0/w1   | digit | +,- | .  | E  | other |
|-----------|-------|-----|----|----|-------|
| **digit** |   0   | -1  | 1  | 2  |  -1   |
|  **+,-**  |   3   | -1  | -1 | -1 |  -1   |
|   **.**   |   4   | -1  | -1 | -1 |  -1   |
|   **E**   |   5   |  6  | -1 | -1 |  -1   |
| **other** |  -1   | -1  | -1 | -1 |  -1   |

**Return Values**

- -1:Invalid input
- 0\~6:uncertain with current words

With the truth table above, the most common invalid input can be filtered out, however the fine discrimination of the type of input still requires more accurate check over the whole string.

#### Int/Double Discrimination

To avoid the illegal input in the cases below,

```bash
./mul 123.456.78 12e345e678
./mul 123e45.678 12.345e678
```

the number and order of the occurrence of the character `"."` and `"E","e"` are recorded.

```bash
OK:
NUM: +123456.78e-90
RES: 30000014026300

ERR:
NUM: 123.456.78
RES: 001400140

ERR:
NUM: 12e345e+678
RES: 0250026300

ERR:
NUM: 123e456.789
RES: 0025001400

ERR:
NUM: 123456e-7.8
RES: 0000026314
```

The possible errors listed above shows that the discrimination of invalid inputs can be simplified to detect duplicating "1" and "2" and "1" after "2" in the examination result array.

## Code Implementation

### Parser

```cpp
void two_word_parser(char* str,int* examine){
    char *str_tbe=str;
    int *result=examine;
    int flag_dot=0,flag_exp=0,len=strlen(str);
    for(int i=0;i<len-1;i++){
    str_tbe=str+i;
    result=examine+i;
    if(flag_NaN(*str_tbe)) return -1;
    if(*str_tbe=="."){
        if(isdigit(*(str_tbe+1))){flag_u+=1;}
        else{return -1;}
    }
    if((*str_tbe=='E')||(*(str_tbe+1)=='e')){
        if((isdigit(*(str_tbe+1)))||(*(str_tbe+1)=='+')||(*(str_tbe+1)=='-')){flag_u+=1};
        else{return -1};
    }
    if((*str_tbe=='+')||*(str_tbe=='-')){
        if(isdigit(*(str_tbe+1))){flag_u+=1};
        else{return -1};
    }
    if(isdigit(*str_tbe)){
        if((*(str_tbe+1)=='+')||(*(str_tbe+1)=='-')||flag_NaN(*str_tbe)){return -1};
        else{flag_u+=1};
    }
    return flag_u;
    }
}

inline int flag_NaN(char c){
    return (!isdigit(c))&&(c!='+')&&(c!='-')&&(c!='.')&&(c!='E')&&(c!='e');
}
inline int flag_Ee(char c){
    return (c='E')||(c=='e')
}

inline int flag_pm(char c){
    return (c='+')||(c=='-')
}
```
