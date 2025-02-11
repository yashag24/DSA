def can_two_candidates_win(votes, candidates):
    
    votes_count = [0] * (candidates + 1)  
    for vote in votes:
        votes_count[vote] += 1
    
    max_votes = max(votes_count[1:])
    max_votes_candidates = [i for i in range(1, candidates+1) if votes_count[i] == max_votes]

    
    remaining_candidates = [i for i in range(1, candidates+1) if votes_count[i] < max_votes]

    if len(remaining_candidates) >= 2:
        
        
        for i in range(len(remaining_candidates)):
            for j in range(i + 1, len(remaining_candidates)):
                if votes_count[remaining_candidates[i]] + votes_count[remaining_candidates[j]] > max_votes:
                    return "True"
    return "False"


N = int(input())
votes = [int(input()) for _ in range(N)]
candidates = int(input())


result = can_two_candidates_win(votes, candidates)
print(result)
