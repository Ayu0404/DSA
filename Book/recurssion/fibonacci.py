# display nth fibonacci num
def fibonacci(num):
    if num == 1:
        return 1
    elif num == 2:
        return 1
    else:
        return fibonacci(num - 1) +  fibonacci(num - 2)
    
print(fibonacci(4))

# Print n fibonacci numbers
def printFib(num):
    if num == 1:
        return 1
    elif num == 2:
        return 1
    else:
        n = fibonacci(num - 1) +  fibonacci(num - 2)
        return n

print(printFib(5))
