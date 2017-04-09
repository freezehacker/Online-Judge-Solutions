class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        word_list = s.split( ' ' )
        reverse_word_list = [ word[::-1] for word in word_list ]
        return ' '.join( reverse_word_list )