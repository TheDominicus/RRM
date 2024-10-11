class Robot {
    public:
        Robot();
        void move(double x, double y);
        double getX() const;
        double getY() const;
    private:
        double positionX_;
        double positionY_;
};