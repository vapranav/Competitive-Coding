boolean[][] dp = new boolean[num+1][sum+1];
	dp[0][0] = true;
	
	for(int i = 1; i<num+1; i++) {
		dp[i][0] = true;
	}
	
	for(int j = 1; j<sum+1; j++) {
		dp[0][j] = false;
	}
	
	for(int i = 1; i<num+1; i++) {
		for(int j = 1; j<sum+1; j++) {
			dp[i][j] = dp[i-1][j];
			if(j >= nums[i-1]) {
				dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
			}
		}
	}
	
	return dp[num][sum];
