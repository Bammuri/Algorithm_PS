N, S = int(input()), input()
"""
answer = 0
bonus = 0
for i in range(N):
    if S[i] == 'O':
        answer += (i+1) + bonus;
        bonus += 1
    else:
        bonus = 0
print(answer)
"""
score, bonus = 0, 0

for idx, OX in enumerate(S):
    if OX =='O':
        score = score+idx+1+bonus, bonus+1
    else:
        bonus = 0

print(score)
