import os
import random

currentFolder = os.getcwd() + '/'
inputFolder = os.listdir(currentFolder + "inputs/")
outputFolder = os.listdir(currentFolder + "outputs/")
existing = {"permutation1": 0, "permutation2": 0, "permutation3": 0}

q1Cases = 50
q1MinLen = 20
q1MaxLen = 100
q1MinVal = -1000
q1MaxVal = 1000

q2Cases = 50
q2MinLen = 300
q2MaxLen = 1000

q3Cases = 50
q3MinN = 300
q3MaxN = 1000
q3MinK = 50
q3MaxK = 300


for file in inputFolder:
    try:
        parts = file.split(".")
        if existing[parts[0]] < int(parts[1]):
            existing[parts[0]] = int(parts[1])
    except KeyError:
        continue


for i in range(existing["permutation1"] + 1, q1Cases):
    newInput = open(currentFolder + "inputs/permutation1." + str(i) + ".in", "w")
    newOutput = open(currentFolder + "outputs/permutation1." + str(i) + ".out", "w")
    count = random.randint(q1MinLen,q1MaxLen)
    if random.random() > 0.5:
        newOutput.write("YES")
        newOutput.close()
        newInput.write(str(count) + "\n")
        valueList = []
        for j in range(count):
            newVal = random.randint(q1MinVal,q1MaxVal)
            newInput.write(str(newVal) + " ")
            valueList.append(newVal)
        newInput.write("\n")
        for k in range(count):
            nextIndex = random.randint(0, len(valueList) - 1)
            newInput.write(str(valueList.pop(nextIndex)) + " ")
        newInput.close()
    else:
        newOutput.write("NO")
        newOutput.close()
        newInput.write(str(count + 1) + "\n")
        for j in range(count):
            newInput.write(str(random.randint(q1MinVal,q1MaxVal)) + " ")
        newInput.write(str(q1MaxVal + 1) + "\n")
        for k in range(count):
            newInput.write(str(random.randint(q1MinVal,q1MaxVal)) + " ")
        newInput.write(str(q1MinVal + 1))
        newInput.close()


for i in range(existing["permutation2"] + 1, q2Cases):
    newInput = open(currentFolder + "inputs/permutation2." + str(i) + ".in", "w")
    newOutput = open(currentFolder + "outputs/permutation2." + str(i) + ".out", "w")
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    count = random.randint(q2MinLen,q2MaxLen)
    string1 = ""
    string2 = ""
    if random.random() > 0.5:
        newOutput.write("YES")
        newOutput.close()
        valueList = []
        for j in range(count):
            newVal = alphabet[random.randint(0,25)]
            string1 += newVal
            valueList.append(newVal)
        newInput.write(string1 + "\n")
        for l in range(count):
            nextIndex = random.randint(0, len(valueList) - 1)
            string2 += valueList.pop(nextIndex)
        newInput.write(string2)
        newInput.close()
    else:
        newOutput.write("NO")
        newOutput.close()
        for j in range(count):
            string1 += alphabet[random.randint(0,25)]
        newInput.write(string1 + "\n")
        for l in range(count):
            string2 += alphabet[random.randint(0,25)]
        newInput.write(string2)
        newInput.close()


for i in range(existing["permutation3"] + 1, q3Cases):
    newInput = open(currentFolder + "inputs/permutation3." + str(i) + ".in", "w")
    newOutput = open(currentFolder + "outputs/permutation3." + str(i) + ".out", "w")
    n = random.randint(q3MinN,q3MaxN)
    #q3MaxK = n #uncomment this line to let k range all the way to n
    k = random.randint(q3MinK, q3MaxK)
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    string1 = ""
    string2 = ""
    if random.random() > 0.5:
        newOutput.write("YES")
        newOutput.close()
        start = random.randint(1, n - k)
        valueList = []
        for j in range(k):
            newVal = alphabet[random.randint(0,25)]
            string1 += newVal
            valueList.append(newVal)
        newInput.write(string1 + "\n")
        for l in range(start):
            string2 += alphabet[random.randint(0,25)]
        for m in range(start, start + k):
            nextVal = random.randint(0, len(valueList) - 1)
            string2 += valueList.pop(nextVal)
        for o in range(start + k, n):
            string2 += alphabet[random.randint(0,25)]
        newInput.write(string2 + "\n")
        #newInput.write(str(start)) #uncomment this line to print the start
        #of the target substring at the bottom of the input files, making
        #debugging easier
        newInput.close()
    else:
        newOutput.write("NO")
        newOutput.close()
        for j in range(k):
            string1 += alphabet[random.randint(0,25)]
        newInput.write(string1 + "\n")
        for l in range(n):
            string2 += alphabet[random.randint(0,25)]
        newInput.write(string2)
        newInput.close()
