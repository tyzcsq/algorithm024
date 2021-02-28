class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        if not bills:
            return False

        changes = []
        for num in bills:
            if num == 5:
                changes.append(num)
            else:
                rest = num - 5
                changes.sort(reverse = True)
                index = []
                for i, change in enumerate(changes):
                    if rest >= change:
                        rest -= change
                        index.append(i)
                        if rest == 0:
                            break
                if rest == 0:
                    for j in reversed(index):
                        changes.pop(j)
                    changes.append(num)
                else:
                    return False
        return True