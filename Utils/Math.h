#pragma once

#include <cmath>

namespace Math
{
	typedef struct _Vec2
	{
		float x, y;
	}Vec2;

	typedef struct _Vec3
	{
		float x, y, z;
	}Vec3;

	typedef struct _Vec4
	{
		float x, y, z, w;
	}Vec4;

    struct Vector {
        Vector() = default;
        constexpr Vector(float x, float y, float z) noexcept : x{ x }, y{ y }, z{ z } {}
        constexpr Vector(Vec3 v) noexcept : x{ v.x }, y{ v.y }, z{ v.z } {}

        constexpr auto notNull() const noexcept
        {
            return x || y || z;
        }

        friend constexpr auto operator==(const Vector& a, const Vector& b) noexcept
        {
            return a.x == b.x && a.y == b.y && a.z == b.z;
        }

        friend constexpr auto operator!=(const Vector& a, const Vector& b) noexcept
        {
            return !(a == b);
        }

        constexpr Vector& operator=(const float array[3]) noexcept
        {
            x = array[0];
            y = array[1];
            z = array[2];
            return *this;
        }

        constexpr Vector& operator+=(const Vector& v) noexcept
        {
            x += v.x;
            y += v.y;
            z += v.z;
            return *this;
        }

        constexpr Vector& operator+=(float f) noexcept
        {
            x += f;
            y += f;
            z += f;
            return *this;
        }

        constexpr Vector& operator-=(const Vector& v) noexcept
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            return *this;
        }

        constexpr Vector& operator-=(float f) noexcept
        {
            x -= f;
            y -= f;
            z -= f;
            return *this;
        }

        friend constexpr auto operator-(const Vector& a, const Vector& b) noexcept
        {
            return Vector{ a.x - b.x, a.y - b.y, a.z - b.z };
        }

        friend constexpr auto operator+(const Vector& a, const Vector& b) noexcept
        {
            return Vector{ a.x + b.x, a.y + b.y, a.z + b.z };
        }

        friend constexpr auto operator*(const Vector& a, const Vector& b) noexcept
        {
            return Vector{ a.x * b.x, a.y * b.y, a.z * b.z };
        }

        constexpr Vector& operator/=(float div) noexcept
        {
            x /= div;
            y /= div;
            z /= div;
            return *this;
        }

        constexpr auto operator*(float mul) const noexcept
        {
            return Vector{ x * mul, y * mul, z * mul };
        }

        constexpr auto operator-(float sub) const noexcept
        {
            return Vector{ x - sub, y - sub, z - sub };
        }

        constexpr auto operator+(float add) const noexcept
        {
            return Vector{ x + add, y + add, z + add };
        }

        Vector& normalize() noexcept
        {
            x = std::isfinite(x) ? std::remainder(x, 360.0f) : 0.0f;
            y = std::isfinite(y) ? std::remainder(y, 360.0f) : 0.0f;
            z = 0.0f;
            return *this;
        }

        auto length() const noexcept
        {
            return std::sqrt(x * x + y * y + z * z);
        }

        auto length2D() const noexcept
        {
            return std::sqrt(x * x + y * y);
        }

        constexpr auto squareLength() const noexcept
        {
            return x * x + y * y + z * z;
        }

        constexpr auto dotProduct(const Vector& v) const noexcept
        {
            return x * v.x + y * v.y + z * v.z;
        }

        auto distTo(const Vector& v) const noexcept
        {
            return (*this - v).length();
        }

        //auto toAngle() const noexcept
        //{
        //    return Vector{ Helpers::rad2deg(std::atan2(-z, std::hypot(x, y))),
        //                   Helpers::rad2deg(std::atan2(y, x)),
        //                   0.0f };
        //}

        //static auto fromAngle(const Vector& angle) noexcept
        //{
        //    return Vector{ std::cos(Helpers::deg2rad(angle.x)) * std::cos(Helpers::deg2rad(angle.y)),
        //                   std::cos(Helpers::deg2rad(angle.x)) * std::sin(Helpers::deg2rad(angle.y)),
        //                  -std::sin(Helpers::deg2rad(angle.x)) };
        //}

        float x, y, z;
    };

	bool WorldToScreen(float* viewMatrix, Vec3 pos, Vec2& screenCoord);
}
