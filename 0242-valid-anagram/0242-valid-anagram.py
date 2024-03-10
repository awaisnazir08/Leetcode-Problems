class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        my_dict = {}
        for letter in s:
            if(letter not in my_dict):
                my_dict[letter] = 1
            else:
                my_dict[letter] += 1

        my_dict2 = {}
        for letter in t:
            if(letter not in my_dict2):
                my_dict2[letter] = 1
            else:
                my_dict2[letter] += 1

        if my_dict == my_dict2:
            return True
        else:
            return False

        