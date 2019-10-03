import random
import string

def writeToFile(str, fileName):
    f = open(fileName, "w+")    
    f.write(str)

def genRandomString(stringLength=1):
    """Generate a random string of fixed length """
    letters = string.ascii_lowercase
    return ''.join(random.choice(letters) for i in range(stringLength))

def generateOneLetterFiles():
    array = []
    for i in range(5):
        fileName = "test-data-one-letter-%d.txt" % i
        randomLetter = genRandomString()
        if randomLetter in array:
            pass
            i-=1
        else:
            writeToFile(randomLetter, fileName)
            array.append(randomLetter)
            pass

def generate10KLetterFiles():
    array = []
    for i in range(3):
        fileName = "test-data-10K-%d.txt" % i
        randomString = genRandomString(10000)
        if randomString in array:
            pass
            i-=1
        else:
            writeToFile(randomString, fileName)
            array.append(randomString)
            pass

def generateOneLetterChangingFiles():
    array = []
    with open('./ted-talk.txt', 'r') as base_file:
        base = base_file.read()
    for i in range(10):
        fileName = "test-data-one-diff-%d.txt" % i
        randomLetter = genRandomString()
        if randomLetter in array:
            pass
            i-=1
        else:
            newString = base[0:1000] + randomLetter + base[1000:]
            writeToFile(newString, fileName)
            array.append(randomLetter)
            pass

def main():
    print("Generating one letter files...", end=" ")
    generateOneLetterFiles()
    print("DONE")

    print("Generating 10 000 letter files...", end=" ")
    generate10KLetterFiles()
    print("DONE")
    
    print("Generating files where only one letter changes...", end=" ")
    generateOneLetterChangingFiles()
    print("DONE")
  
main()