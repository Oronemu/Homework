persones = {}

def add_friends(name_of_person, list_of_friends):
    old_friends = persones.get(name_of_person)
    if old_friends:
        persones[name_of_person] = old_friends + list_of_friends
    else:
        persones[name_of_person] = list_of_friends

def are_friends(name_of_person1, name_of_person2):
    if name_of_person2 in persones[name_of_person1]:
        return True
    else:
        return False

def print_friends(name_of_person):
    friends = reversed(persones[name_of_person])
    for friend in friends:
        print(friend, end=' ')
    print()

add_friends('Алла', ['Марина', 'Иван'])
print(are_friends('Алла', 'Мария'))
add_friends('Алла', ['Мария'])
print(are_friends('Алла', 'Мария'))