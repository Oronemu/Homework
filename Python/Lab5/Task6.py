messages = []

def print_without_duplicates(message):
    if message not in messages:
        print(message)
        messages.append(message)

print_without_duplicates("Привет")
print_without_duplicates("Как дела?")
print_without_duplicates("Как дела?")
print_without_duplicates("Как дела?")
print_without_duplicates("Норм")
print_without_duplicates("Ну ок")
print_without_duplicates("Ну ок")