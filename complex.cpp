#include <iostream>

using namespace std ;

class Complex
{
    private:
        int real ;
        int imag ;
    
    public:
        Complex (int real, int imag) : real (real), imag (imag) {}

        int getreal ()
        {
            return real ;
        }

        int getimag ()
        {
            return imag ;
        }

        friend Complex operator+ (Complex &A, Complex &B) ;
        friend Complex operator- (Complex &A, Complex &B) ;
        friend Complex operator* (Complex &A, Complex &B) ;

};


Complex operator+ (Complex &A, Complex &B)
{
    Complex C (0,0) ;

    C.real = A.real + B.real ;
    C.imag = A.imag + B.imag ;

    return C ;
    
}

Complex operator- (Complex &A, Complex &B)
{
    Complex C (0,0) ;

    C.real = A.real - B.real ;
    C.imag = A.imag - B.imag ;

    return C ;
}

Complex operator* (Complex &A, Complex &B)
{
    Complex C (0,0) ;
    
    C.real = A.real * B.real - A.imag * B.imag ;
    C.imag = A.imag * B.real + A.real * B.imag ;

    return C ;
}


int main()
{
    Complex A (1,2) ;
    Complex B (3,4) ;
    Complex C (0,0) ;

    C = A + B ;
    printf ("(%d + j%d) + (%d + j%d) = %d + j%d \n", A.getreal(), A.getimag(), B.getreal(), B.getimag(), C.getreal(), C.getimag()) ;

    C = A - B ;
    printf ("(%d + j%d) - (%d + j%d) = %d + j%d \n", A.getreal(), A.getimag(), B.getreal(), B.getimag(), C.getreal(), C.getimag()) ;

    C = A * B ;
    printf ("(%d + j%d) * (%d + j%d) = %d + j%d \n", A.getreal(), A.getimag(), B.getreal(), B.getimag(), C.getreal(), C.getimag()) ;

    return 0 ;
}