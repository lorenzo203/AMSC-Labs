#include"matrix.hpp"

#include<algorithm>
#include<Eigen/Dense>
#include<cassert>

matrix
matrix::transpose() const
{
    matrix A_tr(*this); //A_Tr is the current matrix
    Eigen::Map<Eigen::MatrixXd> eigen_ret(A_tr.get_data(), A_tr.get_rows(), A_tr.get_cols());
    eigen_ret.transposeInPlace();//Using the Eigen function in this case
    return A_tr;
}

//C = A*B
// => the dimensions must be compatible, so 
// C m x p <=> A m x n && B n x p 

matrix operator*(const matrix &A, const matrix &B)
{
    assert(A.get_cols()==B.get_rows());

    matrix C (A.get_rows(), B.get_cols());

    Eigen::Map<Eigen::MatrixXd> eigen_ret(C.get_data(), C.get_rows(), C.get_cols());
    // C not const since we still need to do the product

    Eigen::Map<const Eigen::MatrixXd> eigen_A(A.get_data(), A.get_rows(), A.get_cols());
    Eigen::Map<const Eigen::MatrixXd> eigen_B(B.get_data(), B.get_rows(), B.get_cols());

    eigen_ret = eigen_A * eigen_B;

    return C;
}