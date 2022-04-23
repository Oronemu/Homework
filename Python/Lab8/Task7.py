dictionary = {
"й": "j", "ц": "c", "у": "u", "к": "k", "е": "e", "н": "n",
"г": "g", "ш": "sh", "щ": "shh", "з": "z", "х": "h", "ъ": "#",
"ф": "f", "ы": "y", "в": "v", "а": "a", "п": "p", "р": "r",
"о": "o", "л": "l", "д": "d", "ж": "zh", "э": "je", "я": "ya",
"ч": "ch", "с": "s", "м": "m", "и": "i", "т": "t", "ь": "'",
"б": "b", "ю": "ju", "ё": "jo"
}

file = open('/Users/ivanrovkov/Desktop/Homework/Python/Lab8/res/cyrillic.txt', encoding='utf8')
lines = file.readlines()
result = ''

for line in lines:
    for symbol in line:
        isUpper = symbol.isupper()
        temp = dictionary.get(symbol.lower(), symbol)
        if isUpper:
            temp = temp.capitalize()
        result = result + temp

file.close()
new_file = open('/Users/ivanrovkov/Desktop/Homework/Python/Lab8/res/transliteration.txt', 'w', encoding='utf8')
new_file.write(result)
new_file.close()