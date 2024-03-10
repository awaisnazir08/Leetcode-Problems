class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        if n == 0:
            return
        elif m == 0:
            i = 0
            while (i < len(nums2)):
                nums1[i] = nums2[i]
                i +=1
            return nums1
        len1 = len(nums1)
        end_index = len1 - 1
        while m > 0 and n > 0:
            if nums2[n - 1] >= nums1[m - 1]:
                nums1[end_index] = nums2[n - 1]
                n -= 1
            else:
                nums1[end_index] = nums1[m - 1]
                m -= 1
            end_index -= 1
        while n > 0:
            nums1[end_index] = nums2[n - 1]
            end_index -= 1
            n -= 1
        