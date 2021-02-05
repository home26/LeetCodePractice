class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        
        def keyList(input):
            return input[0]
        intervals.sort(key=keyList)
        
        heap = []
        for i in intervals:
            if heap and i[0] >= heap[0]:
                heapq.heapreplace(heap, i[1])
            else:
                heapq.heappush(heap, i[1])
        return len(heap)
