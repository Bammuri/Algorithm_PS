name = ""
domain = ""
topdo = ""
cando = {"com", "net", "org"}

def checkname(name):
    if name == "":
        return False
    for c in name:
        if c.islower() or c == ".":
            continue
        else:
            return False
    return True

def is_valid(email):
    spilt = email.split("@")
    if len(spilt) != 2:
        return False
    name = spilt[0]

    docan = spilt[1].split(".")
    if len(docan) != 2:
        return False
    domain = docan[0]
    topdo = docan[1]

    if topdo not in cando:
        return False
    if not domain.islower():
        return False
    if not checkname(name):
        return False
    return True


def solution(emails):
    ans = 0;
    for e in emails:
        if not is_valid(e):
            continue
        ans += 1

    return ans


emails = ["d@co@m.com", "a@abc.com", "b@def.com", "c@ghi.net"]
emails1 =["a@a.net", "@", "abc@defx", "abc@defx.xyz"]
print(solution(emails))
print(solution(emails1))

print(checkname(""))
print("".islower())