#include "tuple.h"
#include <math.h>

Tuple point(float x, float y, float z){
	return (Tuple){x, y, z, 1};
}

Tuple vector(float x, float y, float z){
	return (Tuple){x, y, z, 0};
}

Tuple add(const Tuple *a, const Tuple *b){
	return (Tuple){
		a->x + b->x,
		a->y + b->y,
		a->z + b->z,
		a->w + b->w
	};
}

Tuple sub(const Tuple *a, const Tuple *b){
	return (Tuple){
		a->x - b->x,
		a->y - b->y,
		a->z - b->z,
		a->w - b->w
	};
}

Tuple neg(const Tuple *a){
	return (Tuple){
		-1.0f * a->x,
		-1.0f * a->y,
		-1.0f * a->z,
		-1.0f * a->w
	};
}

Tuple mul(const Tuple *a, float scalar){
	return (Tuple){
		a->x * scalar,
		a->y * scalar,
		a->z * scalar,
		a->w * scalar
	};
}

Tuple div(const Tuple *a, float scalar){
	return (Tuple){
		a->x / scalar,
		a->y / scalar,
		a->z / scalar,
		a->w / scalar
	};
}

float magnitude(const Tuple *a){
	float square_sum = a->x * a->x + a->y * a->y + a->z * a->z + a->w * a->w;
	return (float)sqrtf(square_sum);
}

Tuple normalize(const Tuple *a){
	float mag = magnitude(a);
	if(mag == 0.0f) return (Tuple){0,0,0,0};
	return (Tuple){
		a->x / mag,
		a->y / mag,
		a->z / mag,
		a->w / mag
	};
}

float dot_pro(const Tuple *a, const Tuple *b) {
	return (float)(a->x * b->x) + (a->y * b->y) + (a->z * b->z) + (a->w * b->w);
}

Tuple cross_pro(const Tuple *a, const Tuple *b){
	return (Tuple){
		(a->y * b->z) - (a->z * b->y),
		(a->x * b->z) - (a->z * b->x),
		(a->x * b->y) - (a->y * b->x),
		0.0f
	};
}
