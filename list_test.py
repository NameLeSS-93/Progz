phonebook = {}
phonebook["Jhon"] = 123, 124, 135
phonebook["Jack"] = 321
phonebook["Rachel"] = 589

for name, number in phonebook.items():
    print(name, number)

del phonebook["Jack"]
for name, number in phonebook.items():
    print(name, number)
print(phonebook)
