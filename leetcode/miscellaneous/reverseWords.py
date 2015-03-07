class Solution:
	def reverseWords(self, s):
		s = s[::-1]
		index = 0
		reversedStr = ''
		strLength = len(s)
		while index < strLength:
			if s[index] == ' ':
				reversedStr += s[index]
				index += 1
				continue
			else:
				begin = index
				while index < strLength and s[index] != ' ':
					index += 1
				splitBegin = begin
				splitEnd = index
				if splitEnd == strLength:
					splitEnd -= 1
				reversedStr += s[splitBegin:splitEnd:-1]
		return reversedStr
		
if __name__ == '__main__':
	solution = Solution()
	print solution.reverseWords("hello world !!  ")
