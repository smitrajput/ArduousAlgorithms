public class Solution
{
	public int longestIncreasingPath(int[][] matrix)
	{
	    if(matrix.length == 0 || matrix[0].length == 0)
	        return 0;
		int[][] dp =
				new int[matrix.length][matrix[0].length];


		 // dp[i][j] is defined as the longest path originating
         // from [i, j]

		for(int i = 0; i < matrix.length; i++)
		{
			for(int j = 0; j < matrix[0].length; j++)
			{
				dp[i][j] = -1;
			}
		}
		int answer = 0;
		for(int i = 0; i < matrix.length; i++)
		{
			for(int j = 0; j < matrix[0].length; j++)
			{

				if(dp[i][j] == -1)
				{
					int res = dfs(i, j, matrix, dp);
					answer = Math.max(answer, res);
				}

			}

		}
		return 1 + answer;
	}

	private boolean isValid(int i, int j, int[][] matrix, int orig_i, int orig_j)
	{
		return i >= 0 && i < matrix.length && j >= 0 && j < matrix[0].length
			&& matrix[i][j] > matrix[orig_i][orig_j];
	}


	private int dfs(int i, int j, int[][] matrix, int[][] dp)
	{
		if(dp[i][j] != -1)
			return dp[i][j];

		int one = 0, two = 0, three = 0, four = 0;

		if(isValid(i + 1, j, matrix, i, j))
			one = 1 + dfs(i + 1, j, matrix, dp);

		if(isValid(i - 1, j, matrix, i, j))
			two = 1 + dfs(i - 1, j, matrix, dp);

		if(isValid(i, j + 1, matrix, i, j))
			three = 1 + dfs(i, j + 1, matrix, dp);

		if(isValid(i, j - 1, matrix, i, j))
			four = 1 + dfs(i, j - 1, matrix, dp);

		dp[i][j] = Math.max(one, Math.max(two, Math.max(three, four)));
		return dp[i][j];
	}

}