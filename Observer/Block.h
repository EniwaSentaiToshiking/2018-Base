#include "Singleton.h"

class Block : public Singleton<Block>
{
private :
  friend class Singleton<Block>;
  Block();

  int red = 0;
  int blue = 0;
  int green = 0;
  int yellow = 0;
  int black1 = 0;
  int black2 = 0;

  // デフォルトコンストラクタ以外でインスタンスを構築したい場合、createInstance()を上書きする
  /*
  Hoge(int) { std::cout << "Hoge(int)" << std::endl; }
  static Hoge *createInstance()
  {
    return new Hoge(0);
  }
  */
};