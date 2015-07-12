#pragma once

class CHyperSpinThemeMedia
{
public:
	CHyperSpinThemeMedia();

	enum EStartingPosition
	{
		StartingPosition_None,
		StartingPosition_Top,
		StartingPosition_Bottom,
		StartingPosition_Left,
		StartingPosition_Right
	};

	enum ERestingAnimation
	{
		RestingAnimation_None,
		RestingAnimation_Hover,
		RestingAnimation_HoverHorizontal,
		RestingAnimation_HoverVertical,
		RestingAnimation_Pulse,
		RestingAnimation_PulseFast,
		RestingAnimation_Rock,
		RestingAnimation_RockFast,
		RestingAnimation_Spin,
		RestingAnimation_SpinSlow,
		RestingAnimation_SpinFast,
		RestingAnimation_Squeeze,
	};

	enum EAnimationType
	{
		AnimationType_None,
		AnimationType_ArcGrow,
		AnimationType_ArcShrink,
		AnimationType_Blur,
		AnimationType_Bounce,
		AnimationType_BounceAround3D,
		AnimationType_BounceRandom,
		AnimationType_Chase,
		AnimationType_Ease,
		AnimationType_Elastic,
		AnimationType_ElasticBounce,
		AnimationType_Fade,
		AnimationType_Flag,
		AnimationType_Flip,
		AnimationType_Grow,
		AnimationType_GrowBlur,
		AnimationType_GrowBounce,
		AnimationType_GrowCenterShrink,
		AnimationType_GrowX,
		AnimationType_GrowY,
		AnimationType_Pendulum,
		AnimationType_Pixelate,
		AnimationType_PixelateZoomOut,
		AnimationType_RainFloat,
		AnimationType_Scroll,
		AnimationType_Stripes,
		AnimationType_Stripes2,
		AnimationType_Strobe,
		AnimationType_SweepLeft,
		AnimationType_SweepRight,
		AnimationType_ZoomOut,
	};

private:
	float m_f32PositionX;
	float m_f32PositionY;
	EStartingPosition m_eStartingPosition;
};
