#include"matrix.hpp"

#include<algorithm>
#include<ctime>
#include<cassert>

matrix
matrix::transpose() const
{
    matrix ret (get_cols(), get_rows());
    for(size_t i=0; i<ret.get_rows(); ++i)
        for(size_t j=0; j<ret.get_cols(); ++j)
            ret(i,j)=value(j,i);
    return ret;
}

//C = A*B
// => the dimensions must be compatible, so 
// C m x p <=> A m x n && B n x p 

matrix operator*(const matrix &A, const matrix &B)
{
    matrix C (A.get_rows(), B.get_cols());

    for(size_t i=0; i<C.get_rows();++i)
        for(size_t j=0; j<C.get_rows(); ++j)
            for(size_t k=0; k<A.get_cols(); ++k)
                C(i,j) += A(i,k) * B(k,j);
    
    return C;
}