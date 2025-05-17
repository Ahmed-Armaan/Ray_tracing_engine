#ifndef TUPLE_H
#define TUPLE_H
#include <stdbool.h>

typedef struct tuple {
    float x;
    float y;
    float z;
    float w;
} Tuple;

Tuple point(float x, float y, float z);
Tuple vector(float x, float y, float z);
Tuple add(const Tuple* a, const Tuple* b);
Tuple sub(const Tuple* a, const Tuple* b);
Tuple neg(const Tuple* a);
Tuple mul(const Tuple* a, float scalar);
Tuple div(const Tuple* a, float scalar);
float magnitude(const Tuple* a);
Tuple normalize(const Tuple* a);
float dot_pro(const Tuple* a, const Tuple* b);
Tuple cross_pro(const Tuple* a, const Tuple* b);

static inline bool is_point(const Tuple* a){
	return (a->w == 1.0f);
}
static inline bool is_vector(const Tuple* a){
	return (a->w == 0.0f);
}

#endif
