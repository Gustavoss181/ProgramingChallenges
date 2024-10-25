def isPalindrome(x: int):
    if x < 0:
        return False
    if x < 10:
        return True
    xStr = x.__str__()
    i = 0
    j = len(xStr) - 1
    while i < j:
        if xStr[i] != xStr[j]:
            return False
        i+=1
        j-=1
    return True

print(isPalindrome(1231))