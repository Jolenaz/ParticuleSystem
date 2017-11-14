/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mat4.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <jbelless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:18:58 by jbelless          #+#    #+#             */
/*   Updated: 2017/09/14 11:19:00 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mat4.class.hpp"

Mat4::Mat4(){
    this->set_zero();
}

Mat4::~Mat4(){}

Mat4::Mat4(Mat4 const & src){
    for(int i = 0; i < 16; ++i)
    {
        this->value.ml[i] = src.value.ml[i];
    }
}

Mat4::Mat4(Mat3 const & src){
    for(int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; j++)
        {
            this->value.mc[i][j] = src.value.mc[i][j];
        }
    }
    this->value.m33 = 1.0f;
}

Mat4 & Mat4::operator=(Mat4 const & rhs)
{
    for(int i = 0; i < 16; ++i)
    {
        this->value.ml[i] = rhs.value.ml[i];
    }
    return (*this);
}

Mat4    Mat4::operator+(Mat4 const & rhs) const
{
    Mat4 ret;

    for(int i = 0; i < 16; ++i)
    {
        ret.value.ml[i] = this->value.ml[i] + rhs.value.ml[i];
    }
    return ret;
}

void    Mat4::operator+=(Mat4 const & rhs)
{
    for(int i = 0; i < 16; ++i)
    {
        this->value.ml[i] += rhs.value.ml[i];
    }
}

Mat4    Mat4::operator-(Mat4 const & rhs) const
{
    Mat4 ret;

    for(int i = 0; i < 16; ++i)
    {
        ret.value.ml[i] = this->value.ml[i] - rhs.value.ml[i];
    }
    return ret;
}

void    Mat4::operator-=(Mat4 const & rhs)
{
    for(int i = 0; i < 16; ++i)
    {
        this->value.ml[i] -= rhs.value.ml[i];
    }
}

Mat4    Mat4::operator*(Mat4 const & rhs) const
{
    Mat4 ret;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                ret.value.mc[i][j] += this->value.mc[i][k] *  rhs.value.mc[k][j];
            }
        }
    }
    return ret;
}

Vec4    Mat4::operator*(Vec4 rhs) 
{
    Vec4 ret;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            ret[i] += this->value.mc[i][j] * rhs[j];
        }
    }
    return ret;
}

Mat4    Mat4::operator*(float const & rhs) const
{
    Mat4 ret;

    for(int i = 0; i < 16; ++i)
    {
        ret.value.ml[i] = this->value.ml[i] * rhs;
    }
    return ret;
}

void    Mat4::operator*=(float const & rhs)
{
    for(int i = 0; i < 16; ++i)
    {
        this->value.ml[i] *= rhs;
    }
}

Mat4    Mat4::operator/(float const & rhs) const
{
    Mat4 ret;

    for(int i = 0; i < 16; ++i)
    {
        ret.value.ml[i] = this->value.ml[i] / rhs;
    }
    return ret;
}

void    Mat4::operator/=(float const & rhs)
{
    for(int i = 0; i < 16; ++i)
    {
        this->value.ml[i] /= rhs;
    }
}

bool    Mat4::operator==(Mat4 const & rhs)
{
    for(int i = 0; i < 16; i++)
    {
        if (this->value.ml[i] != rhs.value.ml[i])
            return false;
    }
    return true;
}

std::ostream & operator<<(std::ostream & o, Mat4 const & input)
{
    for (int i = 0; i < 4; i++)
    {
        o << "| ";
        for (int j = 0; j < 4; j++)
        {
            o << input.value.mc[i][j] << " ";
        }
        o << "|" << std::endl;
    }
    return o;
}

Mat4 & Mat4::set_identity()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == j)
                this->value.mc[i][j] = 1.0f;
            else
                this->value.mc [i][j] = 0.0f;
        }
    }
    return *this;
}

Mat4 & Mat4::set_zero()
{
    for (int i = 0; i < 16; i++)
    {
        this->value.ml[i] = 0.0f;
    }
    return *this;
}

Mat4 & Mat4::transpos()
{
    Mat4 tmp(*this);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            this->value.mc[i][j] = tmp.value.mc[j][i];
        }
    }
    return (*this);
}

Mat4    & Mat4::rotateAround(Vec4 const & rotation)
{
    return (Mat4::rotateAround(Vec3(rotation.x, rotation.y, rotation.z), rotation.w));
}

Mat4    & Mat4::rotateAround(Vec3 const & axe, float const & angle)
{
    Mat4 ret;
    ret.set_identity();
    Vec3 NAxe(axe);
    NAxe.normalize();

    float c = cos(angle * M_PI / 180.0f);
    float s = sin(angle * M_PI / 180.0f);

    ret.value.m00 = NAxe.x * NAxe.x + (1 - NAxe.x * NAxe.x) * c;
    ret.value.m01 = NAxe.x * NAxe.y * (1 - c) - NAxe.z * s;
    ret.value.m02 = NAxe.x * NAxe.z * (1 - c) + NAxe.y * s;
    ret.value.m10 = NAxe.x * NAxe.y * (1 - c) + NAxe.z * s;
    ret.value.m11 = NAxe.y * NAxe.y + (1 - NAxe.y * NAxe.y) * c;
    ret.value.m12 = NAxe.y * NAxe.z * (1 - c) - NAxe.x * s;
    ret.value.m20 = NAxe.x * NAxe.z * (1 - c) - NAxe.y * s;
    ret.value.m21 = NAxe.y * NAxe.z * (1 - c) + NAxe.x * s;
    ret.value.m22 = NAxe.z * NAxe.z + (1 - NAxe.z * NAxe.z) * c;

    *this = ret * *this;
    return *this; 
}

Mat4    & Mat4::rotateLocal(Vec3 const & angles)
{
    Mat4 ret;
    ret.set_identity();

    ret.rotateAround(Vec3(1,0,0), angles.x );
    ret.rotateAround(Vec3(ret * Vec4(0,1,0,0)), angles.y );
    ret.rotateAround(Vec3(ret * Vec4(0,0,1,0)), angles.z);

    *this = ret * *this;;
    return *this;
}

Mat4    & Mat4::rotateGlobal(Vec3 const & angles)
{
    Mat4 ret;
    ret.set_identity();

    ret.rotateAround(Vec3(1,0,0), angles.x);
    ret.rotateAround(Vec3(0,1,0), angles.y);
    ret.rotateAround(Vec3(0,0,1), angles.z);

    *this = ret * *this;;
    return *this;
}

Mat4    & Mat4::translate(Vec3 const & trans)
{
    this->value.m03 += trans.x;
    this->value.m13 += trans.y;
    this->value.m23 += trans.z;
    return (*this);
}

Mat4    & Mat4::scale(Vec3 const & scale)
{
    this->value.m00 *= scale.x;
    this->value.m11 *= scale.y;
    this->value.m22 *= scale.z;
    return (*this);
}

Mat4    & Mat4::rotateAroundInverse(Vec4 const & rotation)
{
    return (Mat4::rotateAroundInverse(Vec3(rotation.x, rotation.y, rotation.z), rotation.w));
}

Mat4    & Mat4::rotateAroundInverse(Vec3 const & axe, float const & angle)
{
    Mat4 ret;
    ret.set_identity();
    Vec3 NAxe(axe);
    NAxe.normalize();

    float c = cos(-angle * M_PI / 180.0f);
    float s = sin(-angle * M_PI / 180.0f);

    ret.value.m00 = NAxe.x * NAxe.x + (1 - NAxe.x * NAxe.x) * c;
    ret.value.m01 = NAxe.x * NAxe.y * (1 - c) - NAxe.z * s;
    ret.value.m02 = NAxe.x * NAxe.z * (1 - c) + NAxe.y * s;
    ret.value.m10 = NAxe.x * NAxe.y * (1 - c) + NAxe.z * s;
    ret.value.m11 = NAxe.y * NAxe.y + (1 - NAxe.y * NAxe.y) * c;
    ret.value.m12 = NAxe.y * NAxe.z * (1 - c) - NAxe.x * s;
    ret.value.m20 = NAxe.x * NAxe.z * (1 - c) - NAxe.y * s;
    ret.value.m21 = NAxe.y * NAxe.z * (1 - c) + NAxe.x * s;
    ret.value.m22 = NAxe.z * NAxe.z + (1 - NAxe.z * NAxe.z) * c;

    *this = ret * *this;;

    return (*this); 
}

Mat4    & Mat4::rotateLocalInverse(Vec3 const & angles)
{
    Mat4 ret;
    ret.set_identity();

    ret.rotateAroundInverse(Vec3(1,0,0), angles.x );
    ret.rotateAroundInverse(Vec3(ret * Vec4(0,1,0,0)), angles.y );
    ret.rotateAroundInverse(Vec3(ret * Vec4(0,0,1,0)), angles.z);

    *this = ret * *this;;
    return *this;
}

Mat4    & Mat4::rotateGlobalInverse(Vec3 const & angles)
{
    Mat4 ret;
    ret.set_identity();

    ret.rotateAroundInverse(Vec3(1,0,0), angles.x);
    ret.rotateAroundInverse(Vec3(0,1,0), angles.y);
    ret.rotateAroundInverse(Vec3(0,0,1), angles.z);

    *this = ret * *this;;
    return *this;
}

Mat4    & Mat4::translateInverse(Vec3 const & trans)
{
    this->value.m03 -= trans.x;
    this->value.m13 -= trans.y;
    this->value.m23 -= trans.z;
    return (*this);
}

Mat4    & Mat4::scaleInverse(Vec3 const & scale)
{
    this->value.m00 /= scale.x;
    this->value.m11 /= scale.y;
    this->value.m22 /= scale.z;
    return (*this);
}

