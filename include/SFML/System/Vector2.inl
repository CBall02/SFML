////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2021 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
template <typename T>
constexpr Vector2<T>::Vector2() :
x(0),
y(0)
{

}


////////////////////////////////////////////////////////////
template <typename T>
constexpr Vector2<T>::Vector2(T X, T Y) :
x(X),
y(Y)
{

}


////////////////////////////////////////////////////////////
template <typename T>
template <typename U>
constexpr Vector2<T>::Vector2(const Vector2<U>& vector) :
x(static_cast<T>(vector.x)),
y(static_cast<T>(vector.y))
{
}


////////////////////////////////////////////////////////////
template <typename T>
constexpr Vector2<T> operator -(const Vector2<T>& right)
{
    return Vector2<T>(-right.x, -right.y);
}


////////////////////////////////////////////////////////////
template <typename T>
constexpr Vector2<T>& operator +=(Vector2<T>& left, const Vector2<T>& right)
{
    left.x += right.x;
    left.y += right.y;

    return left;
}


////////////////////////////////////////////////////////////
template <typename T>
constexpr Vector2<T>& operator -=(Vector2<T>& left, const Vector2<T>& right)
{
    left.x -= right.x;
    left.y -= right.y;

    return left;
}


////////////////////////////////////////////////////////////
template <typename T>
constexpr Vector2<T> operator +(const Vector2<T>& left, const Vector2<T>& right)
{
    return Vector2<T>(left.x + right.x, left.y + right.y);
}


////////////////////////////////////////////////////////////
template <typename T>
constexpr Vector2<T> operator -(const Vector2<T>& left, const Vector2<T>& right)
{
    return Vector2<T>(left.x - right.x, left.y - right.y);
}


////////////////////////////////////////////////////////////
template <typename T>
constexpr Vector2<T> operator *(const Vector2<T>& left, T right)
{
    return Vector2<T>(left.x * right, left.y * right);
}


////////////////////////////////////////////////////////////
template <typename T>
constexpr Vector2<T> operator *(T left, const Vector2<T>& right)
{
    return Vector2<T>(right.x * left, right.y * left);
}


////////////////////////////////////////////////////////////
template <typename T>
constexpr Vector2<T>& operator *=(Vector2<T>& left, T right)
{
    left.x *= right;
    left.y *= right;

    return left;
}


////////////////////////////////////////////////////////////
template <typename T>
constexpr Vector2<T> operator /(const Vector2<T>& left, T right)
{
    return Vector2<T>(left.x / right, left.y / right);
}


////////////////////////////////////////////////////////////
template <typename T>
constexpr Vector2<T>& operator /=(Vector2<T>& left, T right)
{
    left.x /= right;
    left.y /= right;

    return left;
}


////////////////////////////////////////////////////////////
template <typename T>
constexpr bool operator ==(const Vector2<T>& left, const Vector2<T>& right)
{
    return (left.x == right.x) && (left.y == right.y);
}


////////////////////////////////////////////////////////////
template <typename T>
constexpr bool operator !=(const Vector2<T>& left, const Vector2<T>& right)
{
    return (left.x != right.x) || (left.y != right.y);
}


////////////////////////////////////////////////////////////
template <typename T>
constexpr float Vector2<T>::mag() const 
{
    return std::sqrt(x*x + y*y);
}


////////////////////////////////////////////////////////////
template <typename T>
constexpr T Vector2<T>::dot(const Vector2<T>& vector1, const Vector2<T>& vector2)
{
    return vector1.x*vector2.x + vector1.y*vector2.y;
}


////////////////////////////////////////////////////////////
template <typename T>
constexpr double Vector2<T>::angleBetween(const Vector2<T>& vector1, const Vector2<T>& vector2)
{
    return std::acos((dot(vector1, vector2))/(vector1.mag() * vector2.mag()));
}


////////////////////////////////////////////////////////////
template <typename T>
constexpr Vector2<double> Vector2<T>::rotate(const Vector2<T>& vector, float rad)
{
    return Vector2<double>(vector.x*std::cos(rad) - vector.y*std::sin(rad), vector.x*std::sin(rad) + vector.y*std::cos(rad));
}


////////////////////////////////////////////////////////////
template <typename T>
constexpr Vector2<double> Vector2<T>::normalize(const Vector2<T>& vector)
{
    return Vector2<double>(vector.x/vector.mag(), vector.y/vector.mag());
}

template <typename T>
constexpr double Vector2<T>::dist(const Vector2<T>& vector1, const Vector2<T>& vector2)
{
    return Vector2<float>(vector1.x - vector2.x, vector1.y - vector2.y).mag();
}


////////////////////////////////////////////////////////////
template <typename T>
constexpr double Vector2<T>::heading() const
{
    return std::atan((double)y/(double)x);
}


////////////////////////////////////////////////////////////
template <typename T>
constexpr Vector2<double> Vector2<T>::fromAngle(float rad, Vector2<T> vector)
{
    return Vector2::rotate(vector, rad);
}