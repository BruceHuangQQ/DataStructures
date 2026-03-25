
// COS30008, tutorial 3, 2025

#include <iostream>

#include "Vector2D.h"
#include "Vector3D.h"
#include "Matrix3x3.h"

#define P1
#define P2

int main()
{
#ifdef P1
    
    Vector2D a( 1.0f, 2.0f );
    Vector2D b( 1.0f, 4.0f );
    Vector2D c( -2.0f, 3.0f );
    Vector2D d( 0.0f, 0.0f );

    std::cout << "Test vector implementation: " << std::endl;
    std::cout << "Vector a = " << a << std::endl;
    std::cout << "Vector b = " << b << std::endl;
    std::cout << "Vector c = " << c << std::endl;
    std::cout << "Vector d = " << d << std::endl;
    
    // passing the 2d into 3d to get the 3d vector
    Vector3D a3( a );
    Vector3D b3( b );
    Vector3D c3( c );
    Vector3D d3( d );

    std::cout << "Vector a3 = " << a << std::endl;
    std::cout << "Vector b3 = " << b << std::endl;
    std::cout << "Vector c3 = " << c << std::endl;
    std::cout << "Vector d3 = " << d << std::endl;

    std::cout << "Test homogeneous vectors:" << std::endl;
    std::cout << a3 << " * 3.0 = " << a3 * 3.0f << std::endl;
    std::cout << a3 << " + " << b3 << " = " << a3 + b3 << std::endl;
    std::cout << a3 << " . " << b3 << " = " << a3.dot( b3 ) << std::endl;
    std::cout << a3 << "[0] = " << a3[0] << " <=> " << a3 << ".x() = " << a3.x() << std::endl;
    std::cout << a3 << "[1] = " << a3[1] << " <=> " << a3 << ".y() = " << a3.y() << std::endl;
    std::cout << a3 << "[2] = " << a3[2] << " <=> " << a3 << ".w() = " << a3.w() << std::endl;

#endif
    
#ifdef P2
    
    std::cout << "Test 3x3 matrix:" << std::endl;
    
    Matrix3x3 MA( Vector3D( 1.0f, 1.0f ), Vector3D( 1.0f, 1.0f ), Vector3D( 1.0f, 1.0f ) );
    
    std::cout << "MA[0] = " << MA[0] << std::endl;
    std::cout << "MA[1] = " << MA[1] << std::endl;
    std::cout << "MA[2] = " << MA[2] << std::endl;

    Matrix3x3 MB = MA * 2.0f;

    std::cout << "MB[0] = " << MB[0] << std::endl;
    std::cout << "MB[1] = " << MB[1] << std::endl;
    std::cout << "MB[2] = " << MB[2] << std::endl;
    
    Matrix3x3 MC = MB + MA;

    std::cout << "MC[0] = " << MC[0] << std::endl;
    std::cout << "MC[1] = " << MC[1] << std::endl;
    std::cout << "MC[2] = " << MC[2] << std::endl;

    Matrix3x3 lS = Matrix3x3::getS( 3.2f, 3.2f );
    Matrix3x3 lR = Matrix3x3::getR( 90.0f );
    Matrix3x3 lT = Matrix3x3::getT( 4.0f, -1.0f );
    
    std::cout << "Scale " << a3 << " by " << 3.2f << " = " << lS * a3 << std::endl;
    std::cout << "Rotate " << b3 << " by " << 90.0f << " degrees = " << lR * b3 << std::endl;
    std::cout << "Translate " << c3 << " by " << lT.column( 2 ) << " = " << lT * c3 << std::endl;
    std::cout << "Translate " << d3 << " by " << lT.column( 2 ) << " = " << lT * d3 << std::endl;

#endif
    
    return 0;
}
