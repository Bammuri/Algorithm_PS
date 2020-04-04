def solution(S, C):
    ANS=""
    dic = {}
    start = 1;
    for name in S.split("; "):
     if start == 0:
         ANS +="; "
     if start == 1:
         start = 0;
     ANS += name+" <"
     size = len(name.split())
     if dic.get(name.split()[size-1].lower().replace("-","") + "_" + name.split()[0].lower(),0)== 0:
      dic[name.split()[size-1].lower().replace("-","") + "_" + name.split()[0].lower()] = 1;
      ANS += name.split()[size-1].lower().replace("-","") + "_" + name.split()[0].lower()
     else:
      ANS += name.split()[size-1].lower().replace("-","") + "_" + name.split()[0].lower()+str(dic.get(name.split()[size-1].lower().replace("-","") + "_" + name.split()[0].lower())+1)
      dic[name.split()[size-1].lower().replace("-","") + "_" + name.split()[0].lower()] = dic.get(name.split()[size-1].lower().replace("-","") + "_" + name.split()[0].lower())+1;
     ANS += "@" + C.lower() + ".com" + ">"

    return ANS
