def triangle(a, b, c):
    if a + b > c and a + c > b and b + c > a:
        print('Это треугольник')
    else:
        print('Это не треугольник')

triangle(1,2,3)
triangle(7,6,10)