/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mat2.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:18:49 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/14 11:18:52 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mat2.class.hpp"

Mat2::Mat2(){
    for(int i = 0; i < 4; ++i)
    {
        this->value.ml[i] = 0.0f;
    }
}

Mat2::Mat2(float m00, float m01, float m10, float m11){
    this->value.m00 = m00;
    this->value.m01 = m01;
    this->value.m10 = m10;
    this->value.m11 = m11;
}

Mat2::~Mat2(){}

Mat2::Mat2(Mat2 const & src){
    for(int i = 0; i < 4; ++i)
    {
        this->value.ml[i] = src.value.ml[i];
    }
}

Mat2 & Mat2::operator=(Mat2 const & rhs)
{
    for(int i = 0; i < 4; ++i)
    {
        this->value.ml[i] = rhs.value.ml[i];
    }
    return (*this);
}

Mat2    Mat2::operator+(Mat2 const & rhs) const
{
    Mat2 ret;

    for(int i = 0; i < 4; ++i)
    {
        ret.value.ml[i] = this->value.ml[i] + rhs.value.ml[i];
    }
    return ret;
}

void    Mat2::operator+=(Mat2 const & rhs)
{
    for(int i = 0; i < 4; ++i)
    {
        this->value.ml[i] += rhs.value.ml[i];
    }
}

Mat2    Mat2::operator-(Mat2 const & rhs) const
{
    Mat2 ret;

    for(int i = 0; i < 4; ++i)
    {
        ret.value.ml[i] = this->value.ml[i] - rhs.value.ml[i];
    }
    return ret;
}

void    Mat2::operator-=(Mat2 const & rhs)
{
    for(int i = 0; i < 4; ++i)
    {
        this->value.ml[i] -= rhs.value.ml[i];
    }
}

Mat2    Mat2::operator*(Mat2 const & rhs) const
{
    Mat2 ret;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                ret.value.mc[i][j] += this->value.mc[i][k] *  rhs.value.mc[k][j];
            }
        }
    }
    return ret;
}

void    Mat2::operator*=(Mat2 const & rhs)
{
    Mat2 ret;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                ret.value.mc[i][j] += this->value.mc[i][k] *  rhs.value.mc[k][j];
            }
        }
    }
    *this = ret;
}

Vec2    Mat2::operator*(Vec2 rhs) 
{
    Vec2 ret;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ret[i] += this->value.mc[i][j] * rhs[j];
        }
    }
    return ret;
}

Mat2    Mat2::operator*(float const & rhs) const
{
    Mat2 ret;

    for(int i = 0; i < 4; ++i)
    {
        ret.value.ml[i] = this->value.ml[i] * rhs;
    }
    return ret;
}

void    Mat2::operator*=(float const & rhs)
{
    for(int i = 0; i < 4; ++i)
    {
        this->value.ml[i] *= rhs;
    }
}

Mat2    Mat2::operator/(float const & rhs) const
{
    Mat2 ret;

    for(int i = 0; i < 4; ++i)
    {
        ret.value.ml[i] = this->value.ml[i] / rhs;
    }
    return ret;
}

void    Mat2::operator/=(float const & rhs)
{
    for(int i = 0; i < 4; ++i)
    {
        this->value.ml[i] /= rhs;
    }
}

bool    Mat2::operator==(Mat2 const & rhs)
{
    for(int i = 0; i < 4; i++)
    {
        if (this->value.ml[i] != rhs.value.ml[i])
            return false;
    }
    return true;
}

std::ostream & operator<<(std::ostream & o, Mat2 const & input)
{
    for (int i = 0; i < 2; i++)
    {
        o << "| ";
        for (int j = 0; j < 2; j++)
        {
            o << input.value.mc[i][j] << " ";
        }
        o << "|" << std::endl;
    }
    return o;
}

void Mat2::set_identity()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (i == j)
                this->value.mc[i][j] = 1.0f;
            else
                this->value.mc [i][j] = 0.0f;
        }
    }
}
void Mat2::set_zero()
{
    for (int i = 0; i < 4; i++)
    {
        this->value.ml[i] = 0.0f;
    }
}

Mat2 & Mat2::transpos()
{
    Mat2 tmp(*this);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; i < 2; j++)
        {
            this->value.mc[i][j] = tmp.value.mc[j][i];
        }
    }
    return (*this);
}
