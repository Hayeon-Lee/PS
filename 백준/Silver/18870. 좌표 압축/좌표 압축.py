import sys
input = sys.stdin.readline

N = int(input())
inputs= list(map(int, input().split()))
sorted_numbers = sorted(set(inputs))
sorted_dictionary = {}

for i in range(0, len(sorted_numbers), 1):
    sorted_dictionary[sorted_numbers[i]] = i

for i in inputs:
    print(sorted_dictionary[i], end = ' ')