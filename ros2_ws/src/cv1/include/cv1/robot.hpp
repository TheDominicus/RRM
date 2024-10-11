class Robot {
public:
	Robot();
	void move(double position);
	double getCurrentPosition() const;
private:
	double position_;
};
