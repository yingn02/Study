#ifndef SVEC_H
#define SVEC_H
#include <cmath>
class SVec {
public:
	float m[4]; // member
	SVec() : SVec(0, 0, 0, 0) {}
	SVec(float x, float y, float z, float w) { m[0] = x; m[1] = y; m[2] = z; m[3] = w; }
	SVec operator+(SVec v) {
		SVec temp(m[0] + v.m[0], m[1] + v.m[1], m[2] + v.m[2], m[3] + v.m[3]);
		return temp;
	}
	SVec operator-(SVec v) {
		SVec temp(m[0] - v.m[0], m[1] - v.m[1], m[2] - v.m[2], m[3] - v.m[3]);
		return temp;
	}
	SVec operator*(float f) { // scale
		SVec temp(m[0] * f, m[1] * f, m[2] * f, m[3]); // m[3]은 불변
		return temp;
	}
	float operator*(SVec v) { // inner product
		float inner = m[0] * v.m[0] + m[1] * v.m[1] + m[2] * v.m[2];
		return inner;
	}
	SVec cross(SVec v) { // 벡터 외적
		SVec temp(m[1]*v.m[2]-m[2]*v.m[1], m[2]*v.m[0]-m[0]*v.m[2], m[0]*v.m[1] - m[1]*v.m[0], 0);
		return temp;
	}
	SVec projection(SVec N)	{ // N 방향으로 projection
		// length(= |*this| * cos) * dir(= N / |N|) = N * size(= |*this| |N| cos / |N|^2 )
		float size = (*this*N) / (N*N);
		return (N * size);
	}
	float length() { // 3d length
		return sqrtf(m[0] * m[0] + m[1] * m[1] + m[2] * m[2]);
	}
	void normalize() {
		float len = length();
		if (len == 0) return; // error
		m[0] /= len;
		m[1] /= len;
		m[2] /= len;
	}
	// x: outside plane, p:on plane
	// (A,B,C,D)*(x,y,z,1) / |N|
	float distance2plane(SVec N, SVec p)
	{
		float d = -(N * p);
		float numerator = fabs((*this * N) + d);
		float denominator = N.length();
		return numerator / denominator;
	}
	SVec reflection(SVec N) {
		return *this*(-1);
		// move + proj = *this
		// *this + refl = 2*move
		SVec proj = projection(N);
		SVec move = *this - proj;
		SVec refl = move - proj; // refl = 2*move - this = 2*move - move - proj
		return refl;
	}

};
#endif
