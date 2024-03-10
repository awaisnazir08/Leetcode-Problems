class Solution(object):
    def carPooling(self, trips, capacity):
        """
        :type trips: List[List[int]]
        :type capacity: int
        :rtype: bool
        """
        my_array = [0] * 1001
        for element in trips:
            my_array[element[1]] += element[0]
            my_array[element[2]] += (element[0] * - 1)

        c = 0
        for element in my_array:
            if element is not None:
                c = c + element
            if(c > capacity):
                return False

        return True                