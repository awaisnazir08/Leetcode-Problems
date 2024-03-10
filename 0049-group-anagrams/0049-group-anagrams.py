from collections import defaultdict

class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        # Create a defaultdict to store groups of anagrams
        d = defaultdict(list)

        # Iterate through each string in the input list
        for s in strs:
            # Sort the characters of the string to create a hashable representation
            sorted_s = sorted(s)

            # Calculate the hash value of the sorted characters
            hash_value = hash(tuple(sorted_s))

            # Append the original string to the list corresponding to the hash value
            d[hash_value].append(s)

        # Return a list of lists, where each inner list contains anagrams grouped together
        return list(d.values())
