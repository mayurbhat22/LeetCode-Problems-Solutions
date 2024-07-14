class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        position_dict = []

        for i, position in enumerate(positions):
            position_dict.append((position, i+1))
        
        position_dict.sort()

        stack = []

        for position, i in position_dict:
            while len(stack)>0 and directions[i-1] == "L" and stack[-1][1] == "R":
                if healths[i-1] == stack[-1][0]:
                    stack.pop()
                    break
                elif healths[i-1] > stack[-1][0]:
                    stack.pop()
                    healths[i-1] -= 1
                else:
                    stack[-1][0] -= 1
                    break
            else:
                stack.append([healths[i-1], directions[i-1], i])
        stack = sorted(stack, key=lambda x: x[2])

        res = []
        for i in range(len(stack)):
            res.append(stack[i][0])
        return res