symbolTable = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000,
    'IV': 4,
    'IX': 9,
    'XL': 40,
    'XC': 90,
    'CD': 400,
    'CM': 900
}
def romanToInt(s: str) -> int:
    n = 0
    max = len(s)
    i = 0
    while i < max :
        print(s[i:i+2])
        if s[i:i+2] in symbolTable.keys():
            n += symbolTable[s[i:i+2]]
            i+=1
        else:
            n += symbolTable[s[i]]
        i+=1
    return n

print(romanToInt("III"))