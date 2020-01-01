### list comprehension
list_arr = [i for i in range (100000) if i%2==0]
print(list_arr)

### sort 와 sorted 구분하기
list =[3,2,7,3,9]
print(sorted(list))
print(list)
list.sort()
print(list)

### len,sum,max,min 활용하기
print(sum(list))
print(max(list))
print(min(list))
print(len(list))

### slicing ,음수 인덱스 활용하기
list = [1] +list
print(list)
list[:0] = [1]
print(list)
print(list[-1])

### reduce, filter  활용하면 좋음


### Tuple 가장큰 장점 표현을 간결하게 할 수 있음
a, b, c = 0, 0, 0
### map과 함께 사용하여 입력 받기
a, b = map(int, input().split())
print(a)
print(b)
### 동시에 변해야하는 객체에 효율적 표현가능
a, b = b, a
print(a)
print(b)

### dictionary

dict_test = {1: 2, 2: 3, 'abc': 7}
print(dict_test)
print(dict_test.values())
print(dict_test.keys())
### set 중복제거
st = set([1, 2, 5, 3, 5, 7, 3, 4, 2, 4, 7, 7, 3, 5])
print(st)
## 중복이 있는지 확인하는 함수
def isCheck(lst):
    return len(lst) == len(set(lst))

