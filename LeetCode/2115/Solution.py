from collections import deque, defaultdict
class Solution:
    def findAllRecipes(self, recipes: list[str], ingredients: list[list[str]],
                   supplies: list[str]) -> list[str]:
        graph = defaultdict(list)
        indeg = {}

        for recipe, needed in zip(recipes, ingredients):
            indeg[recipe] = len(needed)
            for ing in needed:
                graph[ing].append(recipe)

        queue = deque(supplies)
        result = []

        while queue:
            item = queue.popleft()
            for recipe in graph[item]:
                indeg[recipe] -= 1
                if indeg[recipe] == 0:
                    result.append(recipe)
                    queue.append(recipe)

        return result