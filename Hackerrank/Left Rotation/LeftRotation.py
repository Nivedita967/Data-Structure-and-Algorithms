def rotateLeft(d, elements):
    for i in range(d):
        elements.append(elements[0])
        elements.remove(elements[0])

    return elements

inputs = input("Enter number of elements, and no. of rotations: ")
inputs = inputs.split()
elNum = int(inputs[0])
rotations = int(inputs[1])
elements = list(map(int, input("Enter array elements: ").split()))

result = rotateLeft(rotations, list(set(elements)))

print(result)