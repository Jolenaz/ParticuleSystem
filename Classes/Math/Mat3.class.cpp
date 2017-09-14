/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mat3.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:18:54 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/14 11:18:57 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mat3.class.hpp"

Mat3::Mat3(){
    for(int i = 0; i < 9; ++i)
    {
        this->value.ml[i] = 0.0f;
    }
}

Mat3::~Mat3(){}

Mat3::Mat3(Mat3 const & src){
    for(int i = 0; i < 9; ++i)
    {
        this->value.ml[i] = src.value.ml[i];
    }
}

Mat3 & Mat3::operator=(Mat3 const & rhs)
{
    for(int i = 0; i < 9; ++i)
    {
        this->value.ml[i] = rhs.value.ml[i];
    }
    return (*this);
}

Mat3    Mat3::operator+(Mat3 const & rhs) const
{
    Mat3 ret;

    for(int i = 0; i < 9; ++i)
    {
        ret.value.ml[i] = this->value.ml[i] + rhs.value.ml[i];
    }
    return ret;
}

void    Mat3::operator+=(Mat3 const & rhs)
{
    for(int i = 0; i < 9; ++i)
    {
        this->value.ml[i] += rhs.value.ml[i];
    }
}

Mat3    Mat3::operator-(Mat3 const & rhs) const
{
    Mat3 ret;

    for(int i = 0; i < 9; ++i)
    {
        ret.value.ml[i] = this->value.ml[i] - rhs.value.ml[i];
    }
    return ret;
}

void    Mat3::operator-=(Mat3 const & rhs)
{
    for(int i = 0; i < 9; ++i)
    {
        this->value.ml[i] -= rhs.value.ml[i];
    }
}

Mat3    Mat3::operator*(Mat3 const & rhs) const
{
    Mat3 ret;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                ret.value.mc[i][j] += this->value.mc[i][k] *  rhs.value.mc[k][j];
            }
        }
    }
    return ret;
}

void    Mat3::operator*=(Mat3 const & rhs)
{
    Mat3 ret;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                ret.value.mc[i][j] += this->value.mc[i][k] *  rhs.value.mc[k][j];
            }
        }
    }
    *this = ret;
}

Vec3    Mat3::operator*(Vec3 rhs) 
{
    Vec3 ret;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ret[i] += this->value.mc[i][j] * rhs[j];
        }
    }
    return ret;
}

Mat3    Mat3::operator*(float const & rhs) const
{
    Mat3 ret;

    for(int i = 0; i < 9; ++i)
    {
        ret.value.ml[i] = this->value.ml[i] * rhs;
    }
    return ret;
}

void    Mat3::operator*=(float const & rhs)
{
    for(int i = 0; i < 9; ++i)
    {
        this->value.ml[i] *= rhs;
    }
}

Mat3    Mat3::operator/(float const & rhs) const
{
    Mat3 ret;

    for(int i = 0; i < 9; ++i)
    {
        ret.value.ml[i] = this->value.ml[i] / rhs;
    }
    return ret;
}

void    Mat3::operator/=(float const & rhs)
{
    for(int i = 0; i < 9; ++i)
    {
        this->value.ml[i] /= rhs;
    }
}

bool    Mat3::operator==(Mat3 const & rhs)
{
    for(int i = 0; i < 9; i++)
    {
        if (this->value.ml[i] != rhs.value.ml[i])
            return false;
    }
    return true;
}

std::ostream & operator<<(std::ostream & o, Mat3 const & input)
{
    for (int i = 0; i < 3; i++)
    {
        o << "| ";
        for (int j = 0; j < 3; j++)
        {
            o << input.value.mc[i][j] << " ";
        }
        o << "|" << std::endl;
    }
    return o;
}

void Mat3::set_identity()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
                this->value.mc[i][j] = 1.0f;
            else
                this->value.mc [i][j] = 0.0f;
        }
    }
}
void Mat3::set_zero()
{
    for (int i = 0; i < 9; i++)
    {
        this->value.ml[i] = 0.0f;
    }
}

Mat3 & Mat3::transpos()
{
    Mat3 tmp(*this);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; i < 3; j++)
        {
            this->value.mc[i][j] = tmp.value.mc[j][i];
        }
    }
    return (*this);
}
