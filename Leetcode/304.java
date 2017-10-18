class NumMatrix 
{
    private int[][] sumOfMatrix;
    
    public NumMatrix(int[][] matrix)
    {
        if(matrix.length == 0 || matrix[0].length == 0)
            return;
        sumOfMatrix = new int[matrix.length][matrix[0].length];
        for(int i = 0; i < matrix.length; i++)
        {
            for(int j = 0; j < matrix[0].length; j++)
            {
                sumOfMatrix[i][j] = matrix[i][j];
                if(i == 0 && j == 0)
                    continue;
                if(i == 0)
                    sumOfMatrix[i][j] += sumOfMatrix[i][j - 1];
                else if(j == 0)
                    sumOfMatrix[i][j] += sumOfMatrix[i - 1][j];
                else
                    sumOfMatrix[i][j] += sumOfMatrix[i][j - 1] + sumOfMatrix[i - 1][j] - sumOfMatrix[i - 1][j - 1];
            }
        }
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2)
    {
        if(row1 == 0 && col1 == 0)
            return sumOfMatrix[row2][col2];
        if(row1 == 0)
            return sumOfMatrix[row2][col2] - sumOfMatrix[row2][col1 - 1];
        if(col1 == 0)
            return sumOfMatrix[row2][col2] - sumOfMatrix[row1 - 1][col2];
        return sumOfMatrix[row2][col2] - sumOfMatrix[row1 - 1][col2] - sumOfMatrix[row2][col1 - 1] + sumOfMatrix[row1 - 1][col1 - 1]; 
    }
}