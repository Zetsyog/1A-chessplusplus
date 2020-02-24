#ifndef POSITION_H
#define POSITION_H
class Position {
  public:
	Position(unsigned int x, unsigned int y);
	unsigned int get_x();
	unsigned int get_y();

  private:
	unsigned int x, y;
};
#endif