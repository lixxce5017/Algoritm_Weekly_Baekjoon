import heapq
def solution(book_time):
    answer = 0
    for i in range(len(book_time)):
        a,b= book_time[i][0].split(':')
        book_time[i][0]= 60*int(a)+int(b)
        c,d= book_time[i][1].split(':')
        book_time[i][1]= 60*int(c)+int(d)+10
    book_time.sort()
    que=[]
    answer=1
    heapq.heappush(que,book_time[0][1])
    for i in range(1,len(book_time)):
        if que[0]<=book_time[i][0]:
            heapq.heappop(que)
            heapq.heappush(que,book_time[i][1])
        else:
            heapq.heappush(que,book_time[i][1])
        answer=max(answer,len(que))

    return answer