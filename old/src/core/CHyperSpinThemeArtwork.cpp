#include "CHyperSpinThemeArtwork.hpp"

CHyperSpinThemeArtwork::CHyperSpinThemeArtwork()
{

}
float CHyperSpinThemeArtwork::getWidth() const
{
	return m_f32Width;
}

void CHyperSpinThemeArtwork::setWidth(float f32Width)
{
	m_f32Width = f32Width;
}

float CHyperSpinThemeArtwork::getHeight() const
{
	return m_f32Height;
}

void CHyperSpinThemeArtwork::setHeight(float f32Height)
{
	m_f32Height = f32Height;
}

float CHyperSpinThemeArtwork::getRotation() const
{
	return m_f32Rotation;
}

void CHyperSpinThemeArtwork::setRotation(float f32Rotation)
{
	m_f32Rotation = f32Rotation;
}
float CHyperSpinThemeArtwork::getRotationPositionX() const
{
	return m_f32RotationPositionX;
}

void CHyperSpinThemeArtwork::setRotationPositionX(float f32RotationPositionX)
{
	m_f32RotationPositionX = f32RotationPositionX;
}

float CHyperSpinThemeArtwork::getRotationPositionY() const
{
	return m_f32RotationPositionY;
}

void CHyperSpinThemeArtwork::setRotationPositionY(float f32RotationPositionY)
{
	m_f32RotationPositionY = f32RotationPositionY;
}

float CHyperSpinThemeArtwork::getDelay() const
{
	return m_f32Delay;
}

void CHyperSpinThemeArtwork::setDelay(float f32Delay)
{
	m_f32Delay = f32Delay;
}
float CHyperSpinThemeArtwork::getTime() const
{
	return m_f32Time;
}

void CHyperSpinThemeArtwork::setTime(float f32Time)
{
	m_f32Time = f32Time;
}

CHyperSpinThemeMedia::ERestingAnimation CHyperSpinThemeArtwork::getRestingAnimation() const
{
	return m_eRestingAnimation;
}

void CHyperSpinThemeArtwork::setRestingAnimation(const ERestingAnimation& eRestingAnimation)
{
	m_eRestingAnimation = eRestingAnimation;
}

CHyperSpinThemeMedia::EAnimationType CHyperSpinThemeArtwork::getAnimationType() const
{
	return m_eAnimationType;
}

void CHyperSpinThemeArtwork::setAnimationType(const EAnimationType& eAnimationType)
{
	m_eAnimationType = eAnimationType;
}

