/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec3.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 17:04:05 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/14 11:19:07 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vec3.class.hpp"

Vec3::Vec3(void) : x(0.0f), y(0.0f), z(0.0f){}

Vec3::Vec3(Vec3 const & src): x(src.x), y(src.y), z(src.z){}

Vec3::Vec3(Vec4 const & src){
    this->x = src.w == 0 ? src.x : src.x / src.w;
    this->y = src.w == 0 ? src.y : src.y / src.w;
    this->z = src.w == 0 ? src.z : src.z / src.w;
}

Vec3::Vec3(Vec2 const & src, float z): x(src.x), y(src.y), z(z){}

Vec3::Vec3(float x, float y, float z): x(x), y(y), z(z){}

Vec3::~Vec3(void){}

Vec3 & Vec3::operator=(Vec3 const & rhs){
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;
    return *this;
}

Vec3 & Vec3::operator=(Vec4 const & rhs){
    this->x = rhs.w == 0 ? rhs.x : rhs.x / rhs.w;
    this->y = rhs.w == 0 ? rhs.y : rhs.y / rhs.w;
    this->z = rhs.w == 0 ? rhs.z : rhs.z / rhs.w;
    return *this;
}

Vec3 Vec3::operator+(Vec3 const & rhs) const{
    return Vec3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
}

void Vec3::operator+=(Vec3 const & rhs){
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;
}

Vec3 Vec3::operator-(Vec3 const & rhs) const{
    return Vec3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
}

void Vec3::operator-=(Vec3 const & rhs){
    this->x -= rhs.x;
    this->y -= rhs.y;
    this->z -= rhs.z;
}

Vec3 Vec3::operator*(float const & num) const{
    return Vec3(this->x * num, this->y * num, this->z * num);
}

void Vec3::operator*=(float const & num){
    this->x *= num;
    this->y *= num;
    this->z *= num;
}

Vec3 Vec3::operator/(float const & num) const{
    return Vec3(this->x / num, this->y / num, this->z / num);
}

void Vec3::operator/=(float const & num){
    this->x /= num;
    this->y /= num;
    this->z /= num;
}

float  & Vec3::operator[](int const i)
{
    if (i == 0)
        return this->x;
    if (i == 1)
        return this->y;
    if (i == 2)
        return this->z;
    std::cout << "Error: mauvais incide pour acceder a un vec3" << std::endl;
    return this->z;
}

bool Vec3::operator==(Vec3 const & rhs)
{
    return (
        this->x == rhs.x &&
        this->y == rhs.y &&
        this->z == rhs.z
    );
}

std::ostream & operator<<(std::ostream & o, Vec3 const & i){
    o << "( " << i.x << " , " << i.y << " , " << i.z << " )";
    return o;
}

float Vec3::dot(Vec3 const & vec)
{
    return (this->x * vec.x + this->y * vec.y + this->z * vec.z);
}

float Vec3::dot(Vec3 const & vec1, Vec3 const & vec2)
{
    return (vec2.x * vec1.x + vec2.y * vec1.y + vec2.z * vec1.z);
}

float   Vec3::magnitude()
{
    return (sqrt(this->x * this->x + this->y * this->y + this->z * this->z));
}

float   Vec3::sqrMagnitude(){
    return (this->x * this->x + this->y * this->y + this->z * this->z);
}

Vec3 & Vec3::normalize()
{
    float mg = this->magnitude();
    if (mg == 0)
    {
        std::cout << "impossible de normailser un vecteur nul" << std::endl;
        return (*this);
    }
    this->x /= mg;
    this->y /= mg;
    this->z /= mg;
    return (*this);
}

Vec3 Vec3::cross(Vec3 const & vec){
    return (Vec3(
        this->y * vec.z - this->z * vec.y,
        this->z * vec.x - this->x * vec.z,
        this->x * vec.y - this->y * vec.x));
}

Vec3 Vec3::cross(Vec3 const & vec1, Vec3 const & vec2){
    return (Vec3(
        vec1.y * vec2.z - vec1.z * vec2.y,
        vec1.z * vec2.x - vec1.x * vec2.z,
        vec1.x * vec2.y - vec1.y * vec2.x));
}
