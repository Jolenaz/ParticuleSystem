/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec2.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 17:03:41 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/14 11:19:05 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vec2.class.hpp"

Vec2::Vec2(void) : x(0.0f) , y(0.0f){}

Vec2::Vec2(Vec2 const & src): x(src.x) , y(src.y){}

Vec2::Vec2(float x, float y): x(x) , y(y){}

Vec2::~Vec2(void){}

Vec2 & Vec2::operator=(Vec2 const & rhs){
    this->x = rhs.x;
    this->y = rhs.y;
    return *this;
}

Vec2 Vec2::operator+(Vec2 const & rhs) const{
    return Vec2(this->x + rhs.x, this->y + rhs.y);
}

void Vec2::operator+=(Vec2 const & rhs){
    this->x += rhs.x;
    this->y += rhs.y;
}

Vec2 Vec2::operator-(Vec2 const & rhs) const{
    return Vec2(this->x - rhs.x, this->y - rhs.y);
}

void Vec2::operator-=(Vec2 const & rhs){
    this->x -= rhs.x;
    this->y -= rhs.y;
}

Vec2 Vec2::operator*(float const & num) const{
    return Vec2(this->x * num, this->y * num);
}

void Vec2::operator*=(float const & num){
    this->x *= num;
    this->y *= num;
}

Vec2 Vec2::operator/(float const & num) const{
    return Vec2(this->x / num, this->y / num);
}

void Vec2::operator/=(float const & num){
    this->x /= num;
    this->y /= num;
}

bool Vec2::operator==(Vec2 const & rhs)
{
    return (this->x == rhs.x && this->y == rhs.y);
}

std::ostream & operator<<(std::ostream & o, Vec2 const & i){
    o << "( " << i.x << " , " << i.y << " )";
    return o;
}

float &  Vec2::operator[](int const i) {
    if (i == 0)
        return this->x;
    else if (i == 1)
        return this->y;
    else
    {
        std::cout << "Error: mauvais indice pour acceder au Vec" << std::endl;
        return (this->y);
    }
}

float Vec2::dot(Vec2 const & vec)
{
    return (this->x * vec.x + this->y * vec.y);
}

float Vec2::dot(Vec2 const & vec1, Vec2 const & vec2)
{
    return (vec1.x * vec2.x + vec1.y * vec2.y);
}

float Vec2::magnitude()
{
    return (sqrt(this->x * this->x + this->y * this->y));
}

float Vec2::sqrMagnitude()
{
    return (this->x * this->x + this->y * this->y);
}

Vec2 & Vec2::normalize()
{
    float mg = this->magnitude();
    if (mg == 0)
    {
        std::cout << "impossible de normailser un vecteur nul" << std::endl;
        return(*this);
    }
    this->x /= mg;
    this->y /= mg;

    return (*this);
}
