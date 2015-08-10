#pragma once

#include "CHyperSpinThemeMedia.hpp"

class CHyperSpinThemeVideo : public CHyperSpinThemeMedia
{
public:
	CHyperSpinThemeVideo();

	enum EForceAspect
	{
		EForceAspect_None,
		EForceAspect_Horizontal,
		EForceAspect_Vertical,
		EForceAspect_Both
	};

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

	bool IsBelow() const;
	void setIsBelow(bool bIsBelow);

	bool IsOverlayBelow() const;
	void setIsOverlayBelow(bool bIsOverlayBelow);

	float getOverlayOffsetX() const;
	void setOverlayOffsetX(float f32OverlayOffsetX);

	float getOverlayOffsetY() const;
	void setOverlayOffsetY(float f32OverlayOffsetY);

	float getDelay() const;
	void setDelay(float f32Delay);

	float getTime() const;
	void setTime(float f32Time);

	int getBSize() const;
	void setBSize(int int32BSize);

	int getBSize2() const;
	void setBSize2(int int32BSize2);

	int getBSize3() const;
	void setBSize3(int int32BSize3);

	int getBColor() const;
	void setBColor(int int32BColor);

	int getBColor2() const;
	void setBColor2(int int32BColor2);

	int getBColor3() const;
	void setBColor3(int int32BColor3);

	CHyperSpinThemeMedia::EStartingPosition getStartingPosition() const;
	void setStartingPosition(const CHyperSpinThemeMedia::EStartingPosition& eStartingPosition);

	CHyperSpinThemeMedia::EAnimationType getAnimationType() const;
	void setAnimationType(const CHyperSpinThemeMedia::EAnimationType& eAnimationType);

	CHyperSpinThemeMedia::ERestingAnimation getRestingAnimation() const;
	void setRestingAnimation(const CHyperSpinThemeMedia::ERestingAnimation& eRestingAnimation);

	bool IsBelowWheel() const;
	void setIsBelowWheel(bool bIsBelowWheel);

private:
	float m_f32Width;
	float m_f32Height;

	float m_f32Rotation;
	float m_f32RotationPositionX;
	float m_f32RotationPositionY;

	bool m_bIsBelow;
	bool m_bIsOverlayBelow;
	float m_f32OverlayOffsetX;
	float m_f32OverlayOffsetY;

	float m_f32Delay;
	float m_f32Time;
	int m_int32BSize;
	int m_int32BSize2;
	int m_int32BSize3;
	int m_int32BColor;
	int m_int32BColor2;
	int m_int32BColor3;

	CHyperSpinThemeMedia::EStartingPosition m_eStartingPosition;
	CHyperSpinThemeMedia::EAnimationType m_eAnimationType;
	CHyperSpinThemeMedia::ERestingAnimation m_eRestingAnimation;

	bool m_bIsBelowWheel;
};
