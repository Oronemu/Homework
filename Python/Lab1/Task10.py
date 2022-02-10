operand = None

while operand != "x":
    num1 = int(input())
    operand = input()
    if operand == "+":
        print(num1 + int(input()))
    elif operand == "-":
        print(num1 - int(input()))
    elif operand == "*":
        print(num1 * int(input()))
    elif operand == "/":
        num2 = int(input())
        if num2 != 0:
            print(num1 // num2)
    elif operand == "%":
        num2 = int(input())
        if num2 != 0:
            print(num1 % num2)
    elif operand == "!":
        if num1 >= 0:
            factorial = 1
            for i in range(2, num1 + 1):
                factorial *= i
            print(factorial)
    elif operand == "x":
        print("Пока!")