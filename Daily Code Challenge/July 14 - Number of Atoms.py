class Solution:
    def countOfAtoms(self, formula: str) -> str:
        stack = [defaultdict(int)]
        i = 0
        while i<len(formula):
            if formula[i] == "(":
                stack.append(defaultdict(int))
            elif formula[i] == ")":
                curr_map = stack.pop()
                prev_map = stack[-1]
                count = ""
                while i+1<len(formula) and formula[i+1].isdigit():
                    count += formula[i+1]
                    i += 1
                count = 1 if not count else int(count)
                for ele in curr_map:
                    prev_map[ele]  += curr_map[ele] * count
            else:
                element = formula[i]
                count = ""
                if i+1<len(formula) and formula[i+1].islower():
                    element += formula[i+1]
                    i += 1
                while i+1<len(formula) and formula[i+1].isdigit():
                    count += formula[i+1]
                    i += 1
                count = 1 if not count else int(count)
                curr_map = stack[-1]
                curr_map[element] += count
            i += 1
        curr_map = stack[-1]
        res= ""
        for ele in sorted(curr_map.keys()):
            count = "" if curr_map[ele] == 1 else curr_map[ele]
            res += ele + str(count)
        
        return res