#include <math.h>

class Vector
{
public:
	Vector( void )
	{
		x = y = z = 0.0f;
	}

	Vector( float X, float Y, float Z )
	{
		x = X; y = Y; z = Z;
	}

	Vector( float* v )
	{
		x = v[0]; y = v[1]; z = v[2];
	}

	Vector( const float* v )
	{
		x = v[0]; y = v[1]; z = v[2];
	}

	Vector( const Vector& v )
	{
		x = v.x; y = v.y; z = v.z;
	}

	Vector& operator=( const Vector& v )
	{
		x = v.x; y = v.y; z = v.z; return *this;
	}

	float& operator[]( int i )
	{
		return ( ( float* )this )[i];
	}

	float operator[]( int i ) const
	{
		return ( ( float* )this )[i];
	}

	Vector& operator+=( const Vector& v )
	{
		x += v.x; y += v.y; z += v.z; return *this;
	}

	Vector& operator-=( const Vector& v )
	{
		x -= v.x; y -= v.y; z -= v.z; return *this;
	}

	Vector& operator*=( const Vector& v )
	{
		x *= v.x; y *= v.y; z *= v.z; return *this;
	}

	Vector& operator/=( const Vector& v )
	{
		x /= v.x; y /= v.y; z /= v.z; return *this;
	}

	Vector& operator+=( float v )
	{
		x += v; y += v; z += v; return * this;
	}

	Vector& operator-=( float v )
	{
		x -= v; y -= v; z -= v; return *this;
	}

	Vector& operator*=( float v )
	{
		x *= v; y *= v; z *= v; return *this;
	}

	Vector& operator/=( float v )
	{
		x /= v; y /= v; z /= v; return *this;
	}

	Vector operator+( const Vector& v ) const
	{
		return Vector( x + v.x, y + v.y, z + v.z );
	}

	Vector operator-( const Vector& v ) const
	{
		return Vector( x - v.x, y - v.y, z - v.z );
	}

	Vector operator*( const Vector& v ) const
	{
		return Vector( x * v.x, y * v.y, z * v.z );
	}

	Vector operator/( const Vector& v ) const
	{
		return Vector( x / v.x, y / v.y, z / v.z );
	}

	Vector operator+( float v ) const
	{
		return Vector( x + v, y + v, z + v );
	}

	Vector operator-( float v ) const
	{
		return Vector( x - v, y - v, z - v );
	}

	Vector operator*( float v ) const
	{
		return Vector( x * v, y * v, z * v );
	}

	Vector operator/( float v ) const
	{
		return Vector( x / v, y / v, z / v );
	}

	void Set( float X = 0.0f, float Y = 0.0f, float Z = 0.0f )
	{
		x = X; y = Y; z = Z;
	}

	float Length( void ) const
	{
		return sqrtf( x * x + y * y + z * z );
	}

	float LengthSqr( void ) const
	{
		return ( x * x + y * y + z * z );
	}

	float Length2d( void ) const
	{
		return sqrtf( x * x + y * y );
	}

	float Length2dSqr( void ) const
	{
		return ( x * x + y * y );
	}

	float DistTo( const Vector& v ) const
	{
		return ( *this - v ).Length( );
	}

	float DistToSqr( const Vector& v ) const
	{
		return ( *this - v ).LengthSqr( );
	}

	float Dot( const Vector& v ) const
	{
		return ( x * v.x + y * v.y + z * v.z );
	}

	Vector Cross( const Vector& v ) const
	{
		return Vector( y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x );
	}

	bool IsZero( void ) const
	{
		return ( x > -0.01f && x < 0.01f &&
			y > -0.01f && y < 0.01f &&
			z > -0.01f && z < 0.01f );
	}

	void Init(float _x = 0, float _y = 0, float _z = 0)
	{
		this->x = _x;
		this->y = _y;
		this->z = _z;
	}

public:
	float x, y, z;
};
