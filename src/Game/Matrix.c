// =============================================================================
//  Matrix.h
//  - homogenous matrix functions (4x4)
// =============================================================================
//  Copyright Relic Entertainment, Inc. All rights reserved.
//  Created June 1997 by Gary Shaw
// =============================================================================

#include "Matrix.h"

#include <stdio.h>
#include "Vector.h"

/*=============================================================================
    Private Macros:
=============================================================================*/

#define hmatrixdot(x1,x2,x3,x4,y1,y2,y3,y4) \
    ( ((x1)*(y1)) + ((x2)*(y2)) + ((x3)*(y3)) + ((x4)*(y4)) )

#define matrixdot(x1,x2,x3,y1,y2,y3) \
    ( ((x1)*(y1)) + ((x2)*(y2)) + ((x3)*(y3)) )

#define FPTR    DWORD PTR
#define FSIZE   4
#define FSIZE_STR "4"

#if defined (_MSC_VER)
#define SOURCE  esi
#define DEST    ebx
#define MATRIX  edi
#elif defined (__GNUC__) && defined (__i386__)
#define SOURCE  "%%esi"
#define DEST    "%%ebx"
#define MATRIX  "%%edi"
#endif


/*=============================================================================
    Public constants:
=============================================================================*/

const hmatrix IdentityHMatrix =
{
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};

const matrix IdentityMatrix =
{
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f
};



/*=============================================================================
    Homogenous Matrix Functions:
=============================================================================*/

/*-----------------------------------------------------------------------------
    Name        : hmatMakeHMatFromMat
    Description : makes a homogenous matrix from a matrix
    Inputs      : mat
    Outputs     : result
    Return      :
----------------------------------------------------------------------------*/
void hmatMakeHMatFromMat(hmatrix *result,matrix *mat)
{
    result->m11 = mat->m11;
    result->m21 = mat->m21;
    result->m31 = mat->m31;
    result->m41 = 0.0f;

    result->m12 = mat->m12;
    result->m22 = mat->m22;
    result->m32 = mat->m32;
    result->m42 = 0.0f;

    result->m13 = mat->m13;
    result->m23 = mat->m23;
    result->m33 = mat->m33;
    result->m43 = 0.0f;

    result->m14 = 0.0f;
    result->m24 = 0.0f;
    result->m34 = 0.0f;
    result->m44 = 1.0f;
}

/*-----------------------------------------------------------------------------
    Name        : hmatMakeHMatFromMatAndVec
    Description : makes a homogenous matrix from a matrix and position vector
    Inputs      : mat - 3x3 matrix
                  pos - position vector
    Outputs     : result
    Return      :
----------------------------------------------------------------------------*/
void hmatMakeHMatFromMatAndVec(hmatrix *result,matrix *mat, vector *pos)
{
    result->m11 = mat->m11;
    result->m21 = mat->m21;
    result->m31 = mat->m31;
    result->m41 = 0.0f;

    result->m12 = mat->m12;
    result->m22 = mat->m22;
    result->m32 = mat->m32;
    result->m42 = 0.0f;

    result->m13 = mat->m13;
    result->m23 = mat->m23;
    result->m33 = mat->m33;
    result->m43 = 0.0f;

    result->m14 = pos->x;
    result->m24 = pos->y;
    result->m34 = pos->z;
    result->m44 = 1.0f;
}

/*-----------------------------------------------------------------------------
    Name        : hmatCreateHMatFromHVecs
    Description : create a matrix, given four 4-tuple vectors.
    Inputs      : col1,col2,col3,col4 vectors
    Outputs     : result
    Return      :
----------------------------------------------------------------------------*/
void hmatCreateHMatFromHVecs(hmatrix *result,hvector *col1,hvector *col2,hvector *col3,hvector *col4)
{
    hmatPutHVectIntoHMatrixCol1(*col1,*result);
    hmatPutHVectIntoHMatrixCol2(*col2,*result);
    hmatPutHVectIntoHMatrixCol3(*col3,*result);
    hmatPutHVectIntoHMatrixCol4(*col4,*result);
}

/*-----------------------------------------------------------------------------
    Name        : hmatMultiplyHMatByHMat
    Description : result = first * second, where matrices are 4 X 4
    Inputs      : first,second
    Outputs     : result
    Return      :
    Warning     : result cannot be the same matrix as first or second.
----------------------------------------------------------------------------*/
void hmatMultiplyHMatByHMat(hmatrix *result,hmatrix *first,hmatrix *second)
{
#define A(row,col) a[4*col+row]
#define B(row,col) b[4*col+row]
#define P(row,col) c[4*col+row]
    real32 *c = (real32*)result;
    real32 *a = (real32*)first;
    real32 *b = (real32*)second;
    real32 ai0, ai1, ai2, ai3;
    sdword i;
    for (i = 0; i < 4; i++)
    {
        ai0 = A(i,0);
        ai1 = A(i,1);
        ai2 = A(i,2);
        ai3 = A(i,3);
        P(i,0) = ai0 * B(0,0) + ai1 * B(1,0) + ai2 * B(2,0) + ai3 * B(3,0);
        P(i,1) = ai0 * B(0,1) + ai1 * B(1,1) + ai2 * B(2,1) + ai3 * B(3,1);
        P(i,2) = ai0 * B(0,2) + ai1 * B(1,2) + ai2 * B(2,2) + ai3 * B(3,2);
        P(i,3) = ai0 * B(0,3) + ai1 * B(1,3) + ai2 * B(2,3) + ai3 * B(3,3);
    }
#undef A
#undef B
#undef P
}

/*-----------------------------------------------------------------------------
    Name        : hmatMultiplyHMatByHVec
    Description : result = matrix * vector (all are homogenous)
    Inputs      : matrix, vector
    Outputs     : result
    Return      :
    Warning     : hvector result cannot be the same as hvector vector.
----------------------------------------------------------------------------*/
void hmatMultiplyHMatByHVec(hvector *result,hmatrix *matrix,hvector *vector)
{
    result->x = hmatrixdot(matrix->m11,matrix->m12,matrix->m13,matrix->m14,vector->x,vector->y,vector->z,vector->w);
    result->y = hmatrixdot(matrix->m21,matrix->m22,matrix->m23,matrix->m24,vector->x,vector->y,vector->z,vector->w);
    result->z = hmatrixdot(matrix->m31,matrix->m32,matrix->m33,matrix->m34,vector->x,vector->y,vector->z,vector->w);
    result->w = hmatrixdot(matrix->m41,matrix->m42,matrix->m43,matrix->m44,vector->x,vector->y,vector->z,vector->w);
}

/*-----------------------------------------------------------------------------
    Name        : hmatMultiplyHVecByHMat
    Description : result = vector * matrix (all homogenous)
    Inputs      : vector, matrix
    Outputs     : result
    Return      :
    Warning     : hvector result cannot be the same as hvector vector.
----------------------------------------------------------------------------*/
void hmatMultiplyHVecByHMat(hvector *result,hvector *vector,hmatrix *matrix)
{
    result->x = hmatrixdot(vector->x,vector->y,vector->z,vector->w,matrix->m11,matrix->m21,matrix->m31,matrix->m41);
    result->y = hmatrixdot(vector->x,vector->y,vector->z,vector->w,matrix->m12,matrix->m22,matrix->m32,matrix->m42);
    result->z = hmatrixdot(vector->x,vector->y,vector->z,vector->w,matrix->m13,matrix->m23,matrix->m33,matrix->m43);
    result->w = hmatrixdot(vector->x,vector->y,vector->z,vector->w,matrix->m14,matrix->m24,matrix->m34,matrix->m44);
}

/*-----------------------------------------------------------------------------
    Name        : hmatTranspose
    Description : Transposes a matrix (exchanges rows and columns)
    Inputs      : matrix
    Outputs     : matrix
    Return      :
----------------------------------------------------------------------------*/
void hmatTranspose(hmatrix *matrix)
{
    real32 temp;

    swap(matrix->m12,matrix->m21,temp);
    swap(matrix->m13,matrix->m31,temp);
    swap(matrix->m14,matrix->m41,temp);
    swap(matrix->m23,matrix->m32,temp);
    swap(matrix->m24,matrix->m42,temp);
    swap(matrix->m34,matrix->m43,temp);
}

/*-----------------------------------------------------------------------------
    Name        : hmatCopyAndTranspose
    Description : takes src matrix, and puts its transpose in dsttrans
    Inputs      : src
    Outputs     : dsttrans
    Return      :
----------------------------------------------------------------------------*/
void hmatCopyAndTranspose(hmatrix *src,hmatrix *dsttrans)
{
    dsttrans->m11 = src->m11;   dsttrans->m12 = src->m21;   dsttrans->m13 = src->m31;   dsttrans->m14 = src->m41;
    dsttrans->m21 = src->m12;   dsttrans->m22 = src->m22;   dsttrans->m23 = src->m32;   dsttrans->m24 = src->m42;
    dsttrans->m31 = src->m13;   dsttrans->m32 = src->m23;   dsttrans->m33 = src->m33;   dsttrans->m34 = src->m43;
    dsttrans->m41 = src->m14;   dsttrans->m42 = src->m24;   dsttrans->m43 = src->m34;   dsttrans->m44 = src->m44;
}

/*-----------------------------------------------------------------------------
    Name        : hmatMakeRotAboutZ
    Description : makes rotation about z-axis matrix
    Inputs      : costheta, sintheta
    Outputs     : matrix
    Return      :
----------------------------------------------------------------------------*/
void hmatMakeRotAboutZ(hmatrix *matrix,real32 costheta,real32 sintheta)
{
    matrix->m11 = costheta;     matrix->m12 = -sintheta;    matrix->m13 = 0.0f;    matrix->m14 = 0.0f;
    matrix->m21 = sintheta;     matrix->m22 = costheta;     matrix->m23 = 0.0f;    matrix->m24 = 0.0f;
    matrix->m31 = 0.0f;         matrix->m32 = 0.0f;         matrix->m33 = 1.0f;    matrix->m34 = 0.0f;
    matrix->m41 = 0.0f;         matrix->m42 = 0.0f;         matrix->m43 = 0.0f;    matrix->m44 = 1.0f;
}

/*-----------------------------------------------------------------------------
    Name        : hmatMakeRotAboutX
    Description : makes rotation about x-axis matrix
    Inputs      : costheta, sintheta
    Outputs     : matrix
    Return      :
----------------------------------------------------------------------------*/
void hmatMakeRotAboutX(hmatrix *matrix,real32 costheta,real32 sintheta)
{
    matrix->m11 = 1.0f;            matrix->m12 = 0.0f;         matrix->m13 = 0.0f;         matrix->m14 = 0.0f;
    matrix->m21 = 0.0f;            matrix->m22 = costheta;     matrix->m23 = -sintheta;    matrix->m24 = 0.0f;
    matrix->m31 = 0.0f;            matrix->m32 = sintheta;     matrix->m33 = costheta;     matrix->m34 = 0.0f;
    matrix->m41 = 0.0f;            matrix->m42 = 0.0f;         matrix->m43 = 0.0f;         matrix->m44 = 1.0f;
}

/*-----------------------------------------------------------------------------
    Name        : hmatMakeRotAboutY
    Description : makes rotation about y-axis matrix
    Inputs      : costheta, sintheta
    Outputs     : matrix
    Return      :
----------------------------------------------------------------------------*/
void hmatMakeRotAboutY(hmatrix *matrix,real32 costheta,real32 sintheta)
{
    matrix->m11 = costheta;     matrix->m12 = 0.0f;            matrix->m13 = sintheta;    matrix->m14 = 0.0f;
    matrix->m21 = 0.0f;         matrix->m22 = 1.0f;            matrix->m23 = 0.0f;        matrix->m24 = 0.0f;
    matrix->m31 = -sintheta;    matrix->m32 = 0.0f;            matrix->m33 = costheta;    matrix->m34 = 0.0f;
    matrix->m41 = 0.0f;         matrix->m42 = 0.0f;            matrix->m43 = 0.0f;        matrix->m44 = 1.0f;
}

/*-----------------------------------------------------------------------------
    Name        : hmatPrintHMatrix
    Description : prints a homogenous matrix
    Inputs      : hmatrix
    Outputs     :
    Return      :
----------------------------------------------------------------------------*/
void hmatPrintHMatrix(hmatrix *a)
{
    printf("(%8f %8f %8f %8f)\n",a->m11,a->m12,a->m13,a->m14);
    printf("(%8f %8f %8f %8f)\n",a->m21,a->m22,a->m23,a->m24);
    printf("(%8f %8f %8f %8f)\n",a->m31,a->m32,a->m33,a->m34);
    printf("(%8f %8f %8f %8f)\n",a->m41,a->m42,a->m43,a->m44);
}



/*=============================================================================
    3 X 3 Matrix Functions:
=============================================================================*/

/*-----------------------------------------------------------------------------
    Name        : matGetMatFromHMat
    Description : gets a 3X3 matrix from a homogenous matrix (just rotation information)
    Inputs      : hmat
    Outputs     : result
    Return      :
----------------------------------------------------------------------------*/
void matGetMatFromHMat(matrix *result,hmatrix *hmat)
{
    result->m11 = hmat->m11;
    result->m21 = hmat->m21;
    result->m31 = hmat->m31;

    result->m12 = hmat->m12;
    result->m22 = hmat->m22;
    result->m32 = hmat->m32;

    result->m13 = hmat->m13;
    result->m23 = hmat->m23;
    result->m33 = hmat->m33;
}

/*-----------------------------------------------------------------------------
    Name        : matCreateCoordSysFromHeading
    Description : creates a coordinate system matrix from a given heading,
                  and assuming a up vector of (0,0,1).
    Inputs      :
    Outputs     :
    Return      :
----------------------------------------------------------------------------*/
void matCreateCoordSysFromHeading(matrix *result,vector *heading)
{
    vector up = {0.0f, 0.0f, 1.0f};
    vector LOF = *heading;
    vector right;

    if (up.x == LOF.x && up.y == LOF.y && up.z == LOF.z)
    {                                                       //if these 2 vectors are identical (both pointing along z)
        up.x = 0.11914522f;                                 //point vector not quite along z
        up.z = 0.99287684f;
    }
    vecCrossProduct(right, LOF, up);
    vecCrossProduct(up, right, LOF);
    vecNormalize(&right);
    vecNormalize(&up);

    matPutVectIntoMatrixCol1(up, *result);
    matPutVectIntoMatrixCol2(right, *result);
    matPutVectIntoMatrixCol3(LOF, *result);
}

/*-----------------------------------------------------------------------------
    Name        : matCreateHMatFromHVecs
    Description : create a matrix, given three 3-tuple vectors.
    Inputs      : col1,col2,col3 vectors
    Outputs     : result
    Return      :
----------------------------------------------------------------------------*/
void matCreateMatFromVecs(matrix *result,vector *col1,vector *col2,vector *col3)
{
    matPutVectIntoMatrixCol1(*col1,*result);
    matPutVectIntoMatrixCol2(*col2,*result);
    matPutVectIntoMatrixCol3(*col3,*result);
}

/*-----------------------------------------------------------------------------
    Name        : matMultiplyMatByMat
    Description : result = first * second, where matrices are 3 X 3
    Inputs      : first,second
    Outputs     : result
    Return      :
    Warning     : result cannot be the same matrix as first or second.
----------------------------------------------------------------------------*/
void matMultiplyMatByMat(matrix *result,matrix *first,matrix *second)
{
#define A(row,col) a[3*col+row]
#define B(row,col) b[3*col+row]
#define P(row,col) c[3*col+row]
    real32 *c = (real32*)result;
    real32 *a = (real32*)first;
    real32 *b = (real32*)second;
    real32 ai0, ai1, ai2;
    sdword i;
    for (i = 0; i < 3; i++)
    {
        ai0 = A(i,0);
        ai1 = A(i,1);
        ai2 = A(i,2);
        P(i,0) = ai0 * B(0,0) + ai1 * B(1,0) + ai2 * B(2,0);
        P(i,1) = ai0 * B(0,1) + ai1 * B(1,1) + ai2 * B(2,1);
        P(i,2) = ai0 * B(0,2) + ai1 * B(1,2) + ai2 * B(2,2);
    }
#undef A
#undef B
#undef P
}

/*-----------------------------------------------------------------------------
    Name        : matMultiplyMatByVec
    Description : result = matrix * vector
    Inputs      : matrix, vector
    Outputs     : result
    Return      :
    Warning     : vector result cannot be the same as vector vector.
----------------------------------------------------------------------------*/
void matMultiplyMatByVec(vector *result,matrix *matrix,vector *vector)
{
    result->x = matrixdot(matrix->m11,matrix->m12,matrix->m13,vector->x,vector->y,vector->z);
    result->y = matrixdot(matrix->m21,matrix->m22,matrix->m23,vector->x,vector->y,vector->z);
    result->z = matrixdot(matrix->m31,matrix->m32,matrix->m33,vector->x,vector->y,vector->z);
}

/*-----------------------------------------------------------------------------
    Name        : matMultiplyVecByMat
    Description : result = vector * matrix
    Inputs      : vector, matrix
    Outputs     : result
    Return      :
    Warning     : vector result cannot be the same as vector vector.
----------------------------------------------------------------------------*/
void matMultiplyVecByMat(vector *result,vector *vector,matrix *matrix)
{
    result->x = matrixdot(vector->x,vector->y,vector->z,matrix->m11,matrix->m21,matrix->m31);
    result->y = matrixdot(vector->x,vector->y,vector->z,matrix->m12,matrix->m22,matrix->m32);
    result->z = matrixdot(vector->x,vector->y,vector->z,matrix->m13,matrix->m23,matrix->m33);
}

/*-----------------------------------------------------------------------------
    Name        : matTranspose
    Description : Transposes a matrix (exchanges rows and columns)
    Inputs      : matrix
    Outputs     : matrix
    Return      :
----------------------------------------------------------------------------*/
void matTranspose(matrix *matrix)
{
    real32 temp;

    swap(matrix->m21,matrix->m12,temp);
    swap(matrix->m31,matrix->m13,temp);
    swap(matrix->m32,matrix->m23,temp);
}

/*-----------------------------------------------------------------------------
    Name        : matCopyAndTranspose
    Description : takes src matrix, and puts its transpose in dsttrans
    Inputs      : src
    Outputs     : dsttrans
    Return      :
----------------------------------------------------------------------------*/
void matCopyAndTranspose(matrix *src,matrix *dsttrans)
{
    dsttrans->m11 = src->m11;   dsttrans->m12 = src->m21;   dsttrans->m13 = src->m31;
    dsttrans->m21 = src->m12;   dsttrans->m22 = src->m22;   dsttrans->m23 = src->m32;
    dsttrans->m31 = src->m13;   dsttrans->m32 = src->m23;   dsttrans->m33 = src->m33;
}

/*-----------------------------------------------------------------------------
    Name        : matMakeRotAboutZ
    Description : makes rotation about z-axis matrix
    Inputs      : costheta, sintheta
    Outputs     : matrix
    Return      :
----------------------------------------------------------------------------*/
void matMakeRotAboutZ(matrix *matrix,real32 costheta,real32 sintheta)
{
    matrix->m11 = costheta;     matrix->m12 = -sintheta;    matrix->m13 = 0.0f;
    matrix->m21 = sintheta;     matrix->m22 = costheta;     matrix->m23 = 0.0f;
    matrix->m31 = 0.0f;         matrix->m32 = 0.0f;         matrix->m33 = 1.0f;
}

/*-----------------------------------------------------------------------------
    Name        : matMakeRotAboutX
    Description : makes rotation about x-axis matrix
    Inputs      : costheta, sintheta
    Outputs     : matrix
    Return      :
----------------------------------------------------------------------------*/
void matMakeRotAboutX(matrix *matrix,real32 costheta,real32 sintheta)
{
    matrix->m11 = 1.0f;            matrix->m12 = 0.0f;         matrix->m13 = 0.0f;
    matrix->m21 = 0.0f;            matrix->m22 = costheta;     matrix->m23 = -sintheta;
    matrix->m31 = 0.0f;            matrix->m32 = sintheta;     matrix->m33 = costheta;
}

/*-----------------------------------------------------------------------------
    Name        : matMakeRotAboutY
    Description : makes rotation about y-axis matrix
    Inputs      : costheta, sintheta
    Outputs     : matrix
    Return      :
----------------------------------------------------------------------------*/
void matMakeRotAboutY(matrix *matrix,real32 costheta,real32 sintheta)
{
    matrix->m11 = costheta;     matrix->m12 = 0.0f;            matrix->m13 = sintheta;
    matrix->m21 = 0.0f;         matrix->m22 = 1.0f;            matrix->m23 = 0.0f;
    matrix->m31 = -sintheta;    matrix->m32 = 0.0f;            matrix->m33 = costheta;
}

/*-----------------------------------------------------------------------------
    Name        : matPrintmatrix
    Description : prints a matrix
    Inputs      : matrix
    Outputs     :
    Return      :
----------------------------------------------------------------------------*/
void matPrintmatrix(matrix *a)
{
    printf("(%8f %8f %8f)\n",a->m11,a->m12,a->m13);
    printf("(%8f %8f %8f)\n",a->m21,a->m22,a->m23);
    printf("(%8f %8f %8f)\n",a->m31,a->m32,a->m33);
}

/*-----------------------------------------------------------------------------
    Name        : matCopyAndScale
    Description : Copy a matrix, scaling it in the process
    Inputs      : in - matrix to copy
                  scale - scale factor to apply while scaling
    Outputs     : out - copied/scaled matrix
    Return      :
----------------------------------------------------------------------------*/
void matCopyAndScale(matrix *out, matrix *in, real32 scale)
{
    matrix scaleMatrix = IdentityMatrix;
    out->m11 = in->m11 * scale; out->m21 = in->m21 * scale; out->m31 = in->m31 * scale;
    out->m12 = in->m12 * scale; out->m22 = in->m22 * scale; out->m32 = in->m32 * scale;
    out->m13 = in->m13 * scale; out->m23 = in->m23 * scale; out->m33 = in->m33 * scale;

    scaleMatrix.m11 *= scale; scaleMatrix.m22 *= scale; scaleMatrix.m33 *= scale;
    matMultiplyMatByMat(out, in, &scaleMatrix);
}
