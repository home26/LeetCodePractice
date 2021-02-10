class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        
        heap = []
        for index, item in enumerate(points):
            distance = sqrt(item[0]*item[0]+item[1]*item[1])
            round(distance, 5)
            heapq.heappush(heap, [distance, index])
        
        res = []
        for i in range(K):
            pair = heapq.heappop(heap)
            res.append(points[pair[1]])
        
        return res
