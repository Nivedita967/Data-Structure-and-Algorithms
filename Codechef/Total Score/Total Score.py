#Approach:-
#	As per the question, either the student solves the problem or he doesn't

#Each index of input represents whether the student is able to solve problem or not

#if the student is able to solve the problem then he/she should get full score

#all i am doing is multiplying the index of student string, to the point index. If the student was able to solve the problem,
#this implies index of string have value 1 and multiplying it with the points of the question gives the full marks to student


t=int(input())
for _ in range(t):
	n,k=map(int,input().split())
	points=list(map(int,input().split())) # taking the input as list and converting it to an integer
	for i in range(n):
		student=input()
		final_score=0
		for j in range(len(student)):
			final_score+=int(student[j])*points[j] #multiplying index of student string with corresponding index of point
		print(final_score)
