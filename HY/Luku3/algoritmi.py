
# ---------- MISSION --------------
# n customers visited the restaurant during the day. 
# For each customer, you know when they entered 
# the restaurant and when they left the restaurant. 
# Your task is to find out how many customers were 
# in the restaurant at most at the same time.

how_many_customers = int(input("Amount of customers: "))
times = []

for i in range(how_many_customers):
    start_and_leave = input().split(" ")
    times.append((int(start_and_leave[0]), int(start_and_leave[1])))

for word in times:
    print(word)
    print(type(word))
