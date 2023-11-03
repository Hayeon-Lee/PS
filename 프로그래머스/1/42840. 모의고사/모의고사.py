def solution(answers):
    counts = [0 for _ in range(3)]
    supojas = [[1,2,3,4,5], [2,1,2,3,2,4,2,5], [3,3,1,1,2,2,4,4,5,5]]

    for repeat in range(3):
        supoja = supojas[repeat]

        for index in range(len(answers)):
            if answers[index] == supoja[index%len(supoja)] : counts[repeat] += 1
    
    max_count = max(counts)
    max_person = []

    for i in range(3):
        if counts[i] == max_count:
            max_person.append(i+1)

    answer = sorted(max_person)
    return answer