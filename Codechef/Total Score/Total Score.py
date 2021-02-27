t=int(input())
for _ in range(t):
	n,k=map(int,input().split())
	points=list(map(int,input().split()))
	for i in range(n):
		student=input()
		final_score=0
		for j in range(len(student)):
			final_score+=int(student[j])*points[j]
		print(final_score)
