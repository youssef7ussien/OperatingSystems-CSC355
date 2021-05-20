import java.util.Scanner;

class Matrix {
    double[][] list;
    int row, column;

    Matrix(int row,int column) {
        this.row=row;
        this.column=column;
        list = new double[row][column];
    }
}

public class Main {

    public static void main(String[] args) {
        Scanner scan= new Scanner(System.in);

        System.out.print("Enter first matrix size (M*N): ");
        Matrix firstMatrix = new Matrix(scan.nextInt(),scan.nextInt());

        System.out.println("Enter first matrix:");
        inputMatrix(firstMatrix,scan);

        System.out.print("Enter second matrix size (M*N): ");
        Matrix secondMatrix = new Matrix(scan.nextInt(),scan.nextInt());

        System.out.println("Enter second matrix:");
        inputMatrix(secondMatrix,scan);

        try {
            printMatrix(multiplyMatrices(firstMatrix,secondMatrix));
        } catch (Exception e) {
            System.out.println("\n" + e);
        }
    }

    private static void inputMatrix(Matrix matrix, Scanner scan) {
        for(int i=0 ; i<matrix.row ; i++)
            for(int j=0 ; j<matrix.column ; j++)
                matrix.list[i][j]=scan.nextDouble();
    }

    private static Matrix multiplyMatrices(Matrix firstMatrix, Matrix secondMatrix) throws Exception {
        if(firstMatrix.column != secondMatrix.row)
            throw new Exception("ERROR: The number of columns in the first matrix" +
                    "\nshould be equal to the number of rows in the second.\n");

        Matrix result=new Matrix(firstMatrix.row,secondMatrix.column);

        for(int i=0 ; i<firstMatrix.row ; i++)
            for(int j=0 ; j<secondMatrix.column ; j++) {
                result.list[i][j] = 0;
                for(int k=0 ; k<secondMatrix.row ; k++)
                    result.list[i][j] += firstMatrix.list[i][k] * secondMatrix.list[k][j];
            }

        return result;
    }

    private static void printMatrix(Matrix matrix) {
        System.out.println("-------------------\nThe result matrix:");
        for(int i=0 ; i<matrix.row ; i++) {
            for(int j=0 ; j<matrix.column ; j++)
                if (matrix.list[i][j] == (long)matrix.list[i][j]) {
                    System.out.format("  %10d", (long)matrix.list[i][j]);
                } else {
                    System.out.printf("  %10g", matrix.list[i][j]);
                }
            System.out.print("\n");
        }
        System.out.print("\n");
    }
}
