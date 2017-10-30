'''hello = "hello"
world = "world"
helloworld = hello + world
print(helloworld)
'''

'''mylist = []
mylist.append(1)
mylist.append(2)
mylist.append(3)

for x in mylist:
    print(x)'''

#####################################################


'''numbers = []
strings = []
numbers.append(1)
numbers.append(2)
numbers.append(3)
strings.append("Hello")
strings.append(" world!")
names = ["John", "Erik", "Jessica"]
second_name = names[0]
print("The second name on list is %s" % second_name)
print(numbers)
print(strings)
print(second_name)'''
#####################################################

#mylsit = [1, 2, 3]
#print("A list: %s" % mylsit)

'''name = "John"
age = 23
print("%s is %d years old." % (name, age))'''


#####################################################

'''print("Hello {}th world".format(7))

print("Hello," + str(7) + "th world")'''

#####################################################

'''astring = "Hello world!"
print(len(astring))'''

'''astring = "Hello world!"
print(astring[3:7])
print(astring[3:7:1])'''

#####################################################

'''number = 16
second_number = 0
first_array = [True, True, True]
second_array = [1, 2]

if number > 15:
    print("1")

if first_array: #проверка пустой ли список
    print("2")

if len(second_array) == 2:
    print("3")

if len(first_array) + len(second_array) == 5:
    print("4")

if first_array and first_array[0] == 1:
    print("5")

if not second_number:
    print("6")'''

#####################################################
'''
count = 0
while count < 5:
    print(count)
    count += 0.0001'''

'''numbers = [
    951, 402, 984, 651, 360, 69, 408, 319, 601, 485, 980, 507, 725, 547, 544,
    615, 83, 165, 141, 501, 263, 617, 865, 575, 219, 390, 984, 592, 236, 105, 942, 941,
    386, 462, 47, 418, 907, 344, 236, 375, 823, 566, 597, 978, 328, 615, 953, 345,
    399, 162, 758, 219, 918, 237, 412, 566, 826, 248, 866, 950, 626, 949, 687, 217,
    815, 67, 104, 58, 512, 24, 892, 894, 767, 553, 81, 379, 843, 831, 445, 742, 717,
    958, 609, 842, 451, 688, 753, 854, 685, 93, 857, 440, 380, 126, 721, 328, 753, 470,
    743, 527]
index = numbers.index(237)
for x in range(len(numbers)):   #чисто си подход лол
    if(x == index):
        break
    if(numbers[x] % 2 == 0):
        print(numbers[x])'''

numbers = [
    951, 402, 984, 651, 360, 69, 408, 319, 601, 485, 980, 507, 725, 547, 544,
    615, 83, 165, 141, 501, 263, 617, 865, 575, 219, 390, 984, 592, 236, 105, 942, 941,
    386, 462, 47, 418, 907, 344, 236, 375, 823, 566, 597, 978, 328, 615, 953, 345,
    399, 162, 758, 219, 918, 237, 412, 566, 826, 248, 866, 950, 626, 949, 687, 217,
    815, 67, 104, 58, 512, 24, 892, 894, 767, 553, 81, 379, 843, 831, 445, 742, 717,
    958, 609, 842, 451, 688, 753, 854, 685, 93, 857, 440, 380, 126, 721, 328, 753, 470,
    743, 527]
numbers.sort()
for x in numbers:
    if x == 237:
        break
    if x % 2 == 1:
        continue
    print(x)
