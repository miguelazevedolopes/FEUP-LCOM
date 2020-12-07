struct Ball{
    int x ;
    int y ; 
    int vx; 
    int vy;
    void(*update_position)(struct Ball * self);
};

extern const struct BallClass  {
	struct Ball (*construct)(int x, int y, int vx, int vy);
} Ball;
