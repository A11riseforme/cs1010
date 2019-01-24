import random
import string


def generate_random_str(randomlength=16):
    str_list = [random.choice(string.ascii_lowercase) for i in range(randomlength)]
    random_str = ''.join(str_list)
    return random_str


string1 = generate_random_str(10000000)
tmp = string1[2500000:7500000]
string2 = ''.join(random.sample(tmp,len(tmp)))
print(string2)
print(string1)
