def lcs(text1:str,text2:str)->int:

    #initailaizing 2D dp array with all 0's
    dp=[[0 for j in range(len(text2)+1)] for i in range(len(text1)+1)]

    #starting from last 
    for i in range(len(text1)-1,-1,-1):
        #starting from last
        for j in range(len(text2)-1,-1,-1):
            if text1[i]==text2[j]:
                dp[i][j]=1+dp[i+1][j+1]
            else:
                dp[i][j]=max(dp[i+1][j],dp[i][j+1])
    
    return dp[0][0]

longest=lcs("ABCD","ABD")
print(longest)