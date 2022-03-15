def palindrome(data):
    data = data.replace(' ','').lower()
    if data == data[::-1]:
        print('Палиндром') 
    else: 
         print('Не палиндром')

palindrome(input())