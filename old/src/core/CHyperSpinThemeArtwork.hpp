#pragma once

#include<QtGlobal>

#include "CHyperSpinThemeMedia.hpp"

class CHyperSpinThemeArtwork : public CHyperSpinThemeMedia
{
public:
	CHyperSpinThemeArtwork();

	float getWidth() const;
	void setWidth(float f32Width);

	float getHeight() const;
	void setHeight(float f32Height);

	float getRotation() const;
	void setRotation(float f32Rotation);

	float getRotationPositionX() const;
	void setRotationPositionX(float f32RotationPositionX);

	float getRotationPositionY() const;
	void setRotationPositionY(float f32RotationPositionY);

	float getDelay() const;
	void setDelay(float f32Delay);

	float getTime() const;
	void setTime(float f32Time);

	ERestingAnimation getRestingAnimation() const;
	void setRestingAnimation(const ERestingAnimation& eRestingAnimation);

	EAnimationType getAnimationType() const;
	void setAnimationType(const EAnimationType& eAnimationType);

private:
	float m_f32Width;
	float m_f32Height;

	float m_f32Rotation;
	float m_f32RotationPositionX;
	float m_f32RotationPositionY;
	// forceaspect
	float m_f32Delay;
	float m_f32Time;
	//int m_int32BShape;

	ERestingAnimation m_eRestingAnimation;
	EAnimationType m_eAnimationType;

};
