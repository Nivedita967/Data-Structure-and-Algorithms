#Working of rotateLeft: We append the first element to the list, and then remove it form the beginning
# thus, left rotating the array
def rotateLeft(d, elements):
    for i in range(d):
        elements.append(elements[0])
        elements.remove(elements[0])

    return elements

inputs = input("Enter number of elements, and no. of rotations: ")
inputs = inputs.split()
elNum = int(inputs[0])
rotations = int(inputs[1])

#we use map to split the input string and convert each split numeric character to integer simultaneously
#we need to use list, to store each int as list input as without it map just returns a map object
elements = list(map(int, input("Enter array elements: ").split()))

result = rotateLeft(rotations, elements)

print(result)