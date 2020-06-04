a ="hobby"
print(a.count("b"))
print(a.find("b"))
print(a.find("a"))
print(",".join(a))
a=a.upper()
print(a)
a=a.lower()
print(a)
a ="      hobby    "
print(a.rstrip())
print(a.lstrip())
a ="      hobby    "
print(a.strip())
a = "Life is too short"
print(a.replace("Life", "Your leg"))
###'Your leg is too short'
###replace(바뀌게 될 문자열, 바꿀 문자열)처럼 사용해서 문자열 안의 특정한 값을 다른 값으로 치환해 준다.

a = "Life is too short"
print(a.split())
###['Life', 'is', 'too', 'short']
b = "a:b:c:d"
print(b.split(':'))
###['a', 'b', 'c', 'd']

##문자열

##[] 리스트
##( ) 튜플
##{ } 딕셔너리
