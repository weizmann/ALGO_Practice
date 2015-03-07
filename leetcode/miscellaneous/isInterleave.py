class Solution:

	def isInterleave(self, s1, s2, s3):

		def _is_interleave(s1, s2, s3, i1, i2, i3, dp_table):
			token = (i1, i2, i3)
			if token in dp_table:
				return dp_table[token]
			if s3[i3:] == s1[i1:] or s3[i3:] == s2[i2:]:
			 	dp_table[token] = True
			elif i1 == len(s1) or i2 == len(s2):
				dp_table[token] = False
			elif s3[i3] != s1[i1] and s3[i3] != s2[i2]:
				dp_table[token] = False
			elif s3[i3] == s1[i1] == s2[i2]:
			 	dp_table[token] = \
					_is_interleave(s1, s2, s3, i1 + 1, i2, i3 + 1, dp_table) \
					or \
					_is_interleave(s1, s2, s3, i1, i2 + 1, i3 + 1, dp_table)
			elif s3[i3] == s1[i1]:
			 	dp_table[token] = _is_interleave(s1, s2, s3, i1 + 1, i2, i3 + 1, dp_table)
			elif s3[i3] == s2[i2]:
			 	dp_table[token] = _is_interleave(s1, s2, s3, i1, i2 + 1, i3 + 1, dp_table);
			else:
				assert False
			return dp_table[token]

		if len(s3) != len(s1) + len(s2):
			return False
		return _is_interleave(s1, s2, s3, 0, 0, 0, {})

			
