def from_string_to_list(string, container):
    container += string.split()

a = [77, "abc"]
from_string_to_list("", a)
print(*a)