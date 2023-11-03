def solution(sizes):
    max_width = 0
    max_height = 0

    for size in sizes:
        if size[0] > size[1]:
            size[0], size[1] = size[1], size[0]

        max_width = max(size[0], max_width)
        max_height = max(size[1], max_height)
    
    return (max_width*max_height)