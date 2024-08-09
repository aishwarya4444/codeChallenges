def solve(A,N):
	if N<3:
		return 0
	B=list(A)
	diff=0
	index=0
	_diff=0
	sum=0
	for i in range(N):
		if i==0:
			diff=abs(B[i+1]-B[i])
		elif i==N-1:
			diff=abs(B[i]-B[i-1])
		else:
			diff=abs(B[i]-B[i-1]) + abs(B[i+1]-B[i]) - abs(B[i+1]-B[i-1])
		if diff>_diff:
			_diff=diff
			index=i

	del B[index]
	for i in range(N-2):
		sum = sum+abs(B[i]-B[i+1])
	return sum


T=int(input())
for _ in range(T):
	N=int(input())
	A=map(int, input().split())
	out_=solve(A,N)
	print(out_)
