#ifndef __ROKID_UNITY_MATH__H__
#define __ROKID_UNITY_MATH__H__

#include <iostream>
#include <cmath>

// 2D向量类
class Vector2
{
public:
    float x, y;
    Vector2() : x(0), y(0) {}
    Vector2(float _x, float _y) : x(_x), y(_y) {}
};

// 3D向量类
class Vector3
{
public:
    float x, y, z;
    Vector3() : x(0), y(0), z(0) {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

// 四元数类
class Quaternion
{
public:
    float w, x, y, z;
    Quaternion() : w(0), x(0), y(0), z(0) {}
    Quaternion(float _x, float _y, float _z, float _w) : w(_w), x(_x), y(_y), z(_z) {}
};

// 姿态类
class Pose
{
public:
    Vector3 position;
    Quaternion rotation;
    Pose() : position(0, 0, 0), rotation(0, 0, 0, 0){};
    Pose(const Vector3 &_position, const Quaternion &_rotation) : position(_position), rotation(_rotation) {}
};

// Struct for Plane
class Plane
{
public:
    Vector3 normal;
    Vector3 center;

    Plane(const Vector3 &_normal, const Vector3 &_center) : normal(_normal), center(_center) {}

    Plane(const Vector3 &_normal, const Vector2 &_center) : normal(_normal), center(_center.x, _center.y, 0) {}
};

#endif //!__ROKID_UNITY_MATH__H__
