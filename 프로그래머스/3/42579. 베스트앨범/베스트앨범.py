def solution(genres, plays):
    answer = []
    index_genres_plays_dic = {}
    play_amount_dic = {}

    for i, (g, p) in enumerate(zip(genres, plays)):
        if g not in index_genres_plays_dic:
            index_genres_plays_dic[g] = [(i, p)]
        else:
            index_genres_plays_dic[g].append((i,p))
    
        if g not in play_amount_dic:
            play_amount_dic[g] = p

        else:
            play_amount_dic[g] += p

    for (key, value) in sorted(play_amount_dic.items(), key=lambda x:x[1], reverse=True):
        for (index, play) in sorted(index_genres_plays_dic[key], key=lambda x:x[1], reverse=True)[:2]:
            answer.append(index)

    return answer
