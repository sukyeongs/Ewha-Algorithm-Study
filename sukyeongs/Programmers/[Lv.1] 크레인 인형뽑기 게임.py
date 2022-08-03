# 64061 - Lv.1 크레인 인형뽑기 게임

# moves -> 열
def solution(board, moves):
    # 뽑힌 인형을 저장하는 stack
    stack = []
    answer = 0
    
    for move in moves:
        # 가장 마지막 줄에도 인형이 없을 때, 아무런 일도 일어나지 않음
        if board[-1][move-1] == 0:
            continue
            
        # 해당 열(move)에 인형이 있는 행이 있는 경우
        else:
            # 위부터 내려옴
            for top in range(len(board)):
                # 인형이 없으면 넘어감
                if board[top][move-1] == 0:
                    continue
                # 인형이 있는 행을 찾은 경우
                else:
                    # 스택이 채워져 있고, 스택의 가장 마지막 요소가 해당 인형과 같은 경우
                    if len(stack) > 0 and board[top][move-1] == stack[-1]:
                        stack.pop()
                        answer += 2
                        board[top][move-1] = 0  # 인형 뽑기
                        break
                    
                    # 스택이 비워져 있거나, 스택의 가장 마지막 요소가 해당 인형과 다른 경우
                    else:
                        # 스택에 추가
                        stack.append(board[top][move-1])
                        # 인형 뽑기
                        board[top][move-1] = 0
                        break
                        
    return answer
