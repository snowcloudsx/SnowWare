#pragma once



class Velocity {
public:
	static inline bool enabled;
	static inline int Vx;
	static inline int Vy;
	static inline int Vz;



	void setMotionX(int value);
	void setMotionY(int value);
	void setMotionZ(int value);
	void runModule();
	void onDisable();
};