#include <cstdint>

#ifndef LIB_SC2_UTIL
#define LIB_SC2_UTIL

struct Vec2 {
    float x, y;
};
static_assert(sizeof(Vec2) == 0x8);

struct Vec3 {
    float x, y, z;
};
static_assert(sizeof(Vec3) == 0xC);

struct SVec {
    int16_t x, y, z;
};
static_assert(sizeof(SVec) == 0x6);

struct CameraMatrix {
    Vec3 target;
    Vec3 pos;
};
static_assert(sizeof(CameraMatrix) == 0x18);

#endif  // LIB_SC2_UTIL