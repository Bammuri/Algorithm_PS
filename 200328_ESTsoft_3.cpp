bool check_aesthetic(int t, vector<int> &A) {
	int upflag = -1;
	int size = A.size();
	int be = 0;
	int af = 0;
	for (int i = 0; i < size - 1; i++) {

		if (i != t)
			be = i;
		else
			be = i++ + 1;
		if (be + 1 != t)
			af = be + 1;
		else
			af = be + 2;

		//cout<<"i: "<<i<<" "<<t<<" "<<be<<" "<<af<<"\n";

		if (A[be] < A[af]) {
			if (upflag != 0 && upflag != -1) return 0;
			upflag = 1;
		}
		else if (A[be] > A[af]) {
			if (upflag != 1 && upflag != -1) return 0;
			upflag = 0;
		}
		else {
			return 0;
		}
	}

	return 1;
}

int solution(vector<int> &A) {
	int answer = 0;
	int Asize = A.size();
	//check aesthetic
	if (check_aesthetic(-1, A) == 1)
		return 0;

	for (int i = 0; i<Asize; i++) {
		if (check_aesthetic(i, A) == 1)
			answer++;
	}
	if (answer == 0)
		return -1;
	return answer;
}
