#include "Singleton.h"

#ifndef ANSWER_H
#define ANSWER_H

class Answer : public Singleton<Answer>
{
private:
  friend class Singleton<Answer>;
  Answer();

public:
  bool hasAnswer = false;
  int analog = 0;
  int digital = 0;
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