#ifndef NATIVE_EXTENSION_GRAB_H
#define NATIVE_EXTENSION_GRAB_H

#include <nan.h>
#include "./Klondike-Solver/Solitaire.h"

// Example with node ObjectWrap
// Based on https://nodejs.org/api/addons.html#addons_wrapping_c_objects but using NAN
class SolitaireWrap : public Nan::ObjectWrap
{
public:
  static NAN_MODULE_INIT(Init);

private:
  explicit SolitaireWrap(Solitaire *solitaire);
  ~SolitaireWrap();

  static NAN_METHOD(New);
  static NAN_METHOD(Initialize);
  static NAN_METHOD(SetDrawCount);
  static NAN_METHOD(LoadSolitaire);
  static NAN_METHOD(GetSolitaire);
  static NAN_METHOD(LoadPysol);
  static NAN_METHOD(ResetGame);
  static NAN_METHOD(SolveMinimal);
  static NAN_METHOD(Shuffle);
  static NAN_METHOD(GameDiagram);
  static NAN_METHOD(GameDiagramPysol);
  static NAN_METHOD(SolveFast);
  static NAN_METHOD(MovesMadeNormalizedCount);
  static NAN_METHOD(FoundationCount);
  static NAN_METHOD(SolveMinimalMultithreaded);
  static NAN_METHOD(MovesMadeCount);
  static NAN_METHOD(GetMoveInfo);
  static NAN_METHOD(MakeMove);
  static NAN_METHOD(MovesMade);
  static Nan::Persistent<v8::Function> constructor;
  Solitaire *value_;
};

#endif
