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

To adopt the `atoll` and `atod` functions and the large integer multiplication function, the types of the input arguments must be determined prior to the conversion from the string. The implementation of such data type parsing and data retrieval is a regex(regular expression) word segmentation mechanism.

``` cpp
std::string integerRegExp = "([+-]?\\d+)";
std::string floatingPointRegExp = integerRegExp + "\\.(\\d+)";
std::string ieee754indexRegExp = integerRegExp;
```
