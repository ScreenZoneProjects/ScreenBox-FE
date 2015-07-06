#pragma once

class CHyperSpinThemeVideo
{
public:
	CHyperSpinThemeVideo();

private:
	float m_f32Width;
	float m_f32Height;
	float m_f32PositionX;
	float m_f32PositionY;
	float m_f32Rotation;
	float m_f32RotationPositionX;
	float m_f32RotationPositionY;
	bool m_bIsBelow;
	bool m_bIsOverlayBelow;
	float m_f32OverlayOffsetX;
	float m_f32OverlayOffsetY;
	// forceaspect
	float m_f32Delay;
	float m_f32Time;
	int m_int32BSize;
	int m_int32BSize2;
	int m_int32BSize3;
	int m_int32BColor;
	int m_int32BColor2;
	int m_int32BColor3;
	//int m_int32BShape;
	//int m_int32Type;
	//int m_int32Start;
	//int m_int32Rest;
};
