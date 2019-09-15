#include "Singleton.h"

#ifndef BLOCK_H
#define BLOCK_H

class Block : public Singleton<Block>
{
private:
  friend class Singleton<Block>;
  Block();

public:
  int red = 15;
  int yellow = 11;
  int green = 14;
  int blue = 8;
  int black1 = 0;
  int black2 = 1;

  // デフォルトコンストラクタ以外でインスタンスを構築したい場合、createInstance()を上書きする
  /*
  Hoge(int) { std::cout << "Hoge(int)" << std::endl; }
  static Hoge *createInstance()
  {
    return new Hoge(0);
  }
  */
};

#endif