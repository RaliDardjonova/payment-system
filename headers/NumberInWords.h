#ifndef _NUMBER_IN_WORDS
#define _NUMBER_IN_WORDS
#include<vector>
#include<string>

class NumberInWords{
public:
    NumberInWords();
    NumberInWords(const NumberInWords&);
    NumberInWords(long long, int);
    ~NumberInWords();
    void setWholePart(long long);
    void setDecimalPart(int);

    long long getWholePart() const;
    int getDecimalPart() const;
    std::string getWholePartInWords();
    std::string getDecimalPartInWords();
private:
    long long wholePart;
    int decimalPart;
    static std::vector<std::string> ones;
    static std::vector<std::string> teens;
    static std::vector<std::string> tens;
    static std::string nameForNumber(long long);
};

#endif // _NUMBER_IN_WORDS
