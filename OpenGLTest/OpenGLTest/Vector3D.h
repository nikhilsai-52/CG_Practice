#ifndef VECTOR3D_H
#define	VECTOR3D_H

#include <iostream>
#include <cmath>

class Vector3D {
public:

	double a[3];

	Vector3D() {

		a[0] = 0;
		a[1] = 0;
		a[2] = 0;
	}

	Vector3D(double ax, double ay, double az) {
		a[0] = ax;
		a[1] = ay;
		a[2] = az;
	}

	double x() const { return a[0]; }
	double y() const { return a[1]; }
	double z() const { return a[2]; }

	Vector3D operator-() const { return Vector3D(-a[0], -a[1], -a[2]); }
	double operator[](int i) const { return a[i]; }
	double& operator[](int i) { return a[i]; }

	double length() const {
		return sqrt(length_squared());
	}

	double length_squared() const {
		return a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
	}

	

	Vector3D& operator+=(const Vector3D& v) {
		a[0] += v.a[0];
		a[1] += v.a[1];
		a[2] += v.a[2];
		return *this;
	}

	Vector3D& operator*=(double t) {
		a[0] *= t;
		a[1] *= t;
		a[2] *= t;
		return *this;
	}

	Vector3D& operator/=(double t) {
		return *this *= 1 / t;
	}

};




using point3D = Vector3D;

inline std::ostream& operator<<(std::ostream& out, const Vector3D& v) {
	return out << v.a[0] << ' ' << v.a[1] << ' ' << v.a[2];
}

inline Vector3D operator+(const Vector3D& u, const Vector3D& v) {
	return Vector3D(u.a[0] + v.a[0], u.a[1] + v.a[1], u.a[2] + v.a[2]);
}

inline Vector3D operator-(const Vector3D& u, const Vector3D& v) {
	return Vector3D(u.a[0] - v.a[0], u.a[1] - v.a[1], u.a[2] - v.a[2]);
}

inline Vector3D operator*(const Vector3D& u, const Vector3D& v) {
	return Vector3D(u.a[0] * v.a[0], u.a[1] * v.a[1], u.a[2] * v.a[2]);
}


inline Vector3D operator*(double t, const Vector3D& v) {
	return Vector3D(t * v.a[0], t * v.a[1], t * v.a[2]);
}

inline Vector3D operator*(const Vector3D& v, double t) {
	return t * v;
}


inline Vector3D operator/(Vector3D v, double t) {
	return (1 / t) * v;
}

inline double Red(Vector3D& v) {
	return v.a[0];
}

inline double Green(Vector3D& v) {
	return v.a[1];
}

inline double Blue(Vector3D& v) {
	return v.a[2];
}

inline double dot(const Vector3D &u, const Vector3D &v) {
	return u.a[0] * v.a[0]
		+ u.a[1] * v.a[1]
		+ u.a[2] * v.a[2];
}
inline Vector3D cross(const Vector3D& u, const Vector3D& v) {
	return Vector3D(u.a[1] * v.a[2] - u.a[2] * v.a[1],
		u.a[2] * v.a[0] - u.a[0] * v.a[2],
		u.a[0] * v.a[1] - u.a[1] * v.a[0]);
}

inline Vector3D unit_vector(Vector3D v) {
	return v / v.length();
}




#endif
