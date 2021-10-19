#include "functions.h"

// Wrapper Impl

Nan::Persistent<v8::Function> SolitaireWrap::constructor;

NAN_MODULE_INIT(SolitaireWrap::Init)
{
  v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
  tpl->SetClassName(Nan::New("SolitaireWrap").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  Nan::SetPrototypeMethod(tpl, "initialize", Initialize);
  Nan::SetPrototypeMethod(tpl, "setDrawCount", SetDrawCount);
  Nan::SetPrototypeMethod(tpl, "loadSolitaire", LoadSolitaire);
  Nan::SetPrototypeMethod(tpl, "getSolitaire", GetSolitaire);
  Nan::SetPrototypeMethod(tpl, "loadPysol", LoadPysol);
  Nan::SetPrototypeMethod(tpl, "resetGame", ResetGame);
  Nan::SetPrototypeMethod(tpl, "solveMinimal", SolveMinimal);
  Nan::SetPrototypeMethod(tpl, "shuffle", Shuffle);
  Nan::SetPrototypeMethod(tpl, "gameDiagram", GameDiagram);
  Nan::SetPrototypeMethod(tpl, "gameDiagramPysol", GameDiagramPysol);
  Nan::SetPrototypeMethod(tpl, "solveFast", SolveFast);
  Nan::SetPrototypeMethod(tpl, "movesMadeNormalizedCount", MovesMadeNormalizedCount);
  Nan::SetPrototypeMethod(tpl, "foundationCount", FoundationCount);
  Nan::SetPrototypeMethod(tpl, "solveMinimalMultithreaded", SolveMinimalMultithreaded);
  Nan::SetPrototypeMethod(tpl, "movesMadeCount", MovesMadeCount);
  Nan::SetPrototypeMethod(tpl, "getMoveInfo", GetMoveInfo);
  Nan::SetPrototypeMethod(tpl, "makeMove", MakeMove);
  Nan::SetPrototypeMethod(tpl, "movesMade", MovesMade);

  constructor.Reset(Nan::GetFunction(tpl).ToLocalChecked());
  Nan::Set(target, Nan::New("SolitaireWrap").ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked());
}

SolitaireWrap::SolitaireWrap(Solitaire *solitaire) : value_(solitaire)
{
}

SolitaireWrap::~SolitaireWrap()
{
}

NAN_METHOD(SolitaireWrap::New)
{
  if (info.IsConstructCall())
  {
    SolitaireWrap *obj = new SolitaireWrap(new Solitaire());
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
  }
}

NAN_METHOD(SolitaireWrap::Initialize)
{
  SolitaireWrap *obj = Nan::ObjectWrap::Unwrap<SolitaireWrap>(info.This());
  obj->value_->Initialize();
}

NAN_METHOD(SolitaireWrap::SetDrawCount)
{
  SolitaireWrap *obj = Nan::ObjectWrap::Unwrap<SolitaireWrap>(info.This());
  obj->value_->SetDrawCount(Nan::To<int>(info[0]).FromJust());
}

NAN_METHOD(SolitaireWrap::LoadSolitaire)
{
  SolitaireWrap *obj = Nan::ObjectWrap::Unwrap<SolitaireWrap>(info.This());
  // from v8 to cpp
  v8::Isolate *isolate = info.GetIsolate();
  v8::String::Utf8Value str(isolate, info[0]);
  std::string cppStr(*str);
  auto result = obj->value_->LoadSolitaire(cppStr);
  info.GetReturnValue().Set(result);
}

NAN_METHOD(SolitaireWrap::GetSolitaire)
{
  SolitaireWrap *obj = Nan::ObjectWrap::Unwrap<SolitaireWrap>(info.This());
  auto solitaire = obj->value_->GetSolitaire();
  info.GetReturnValue().Set(Nan::New(solitaire.c_str()).ToLocalChecked());
}

NAN_METHOD(SolitaireWrap::ResetGame)
{
  SolitaireWrap *obj = Nan::ObjectWrap::Unwrap<SolitaireWrap>(info.This());
  obj->value_->ResetGame();
}

NAN_METHOD(SolitaireWrap::SolveMinimal)
{
  SolitaireWrap *obj = Nan::ObjectWrap::Unwrap<SolitaireWrap>(info.This());
  auto result = obj->value_->SolveMinimal(Nan::To<int>(info[0]).FromJust());
  info.GetReturnValue().Set(result);
}

NAN_METHOD(SolitaireWrap::Shuffle)
{
  SolitaireWrap *obj = Nan::ObjectWrap::Unwrap<SolitaireWrap>(info.This());
  auto result = obj->value_->Shuffle1(Nan::To<int>(info[0]).FromJust());
  info.GetReturnValue().Set(result);
}

NAN_METHOD(SolitaireWrap::GameDiagram)
{
  SolitaireWrap *obj = Nan::ObjectWrap::Unwrap<SolitaireWrap>(info.This());
  auto diagram = obj->value_->GameDiagram();
  info.GetReturnValue().Set(Nan::New(diagram.c_str()).ToLocalChecked());
}

NAN_METHOD(SolitaireWrap::GameDiagramPysol)
{
  SolitaireWrap *obj = Nan::ObjectWrap::Unwrap<SolitaireWrap>(info.This());
  auto diagram = obj->value_->GameDiagramPysol();
  info.GetReturnValue().Set(Nan::New(diagram.c_str()).ToLocalChecked());
}

NAN_METHOD(SolitaireWrap::SolveFast)
{
  SolitaireWrap *obj = Nan::ObjectWrap::Unwrap<SolitaireWrap>(info.This());
  auto result = obj->value_->SolveFast(Nan::To<int>(info[0]).FromJust(), Nan::To<int>(info[1]).FromJust(), Nan::To<int>(info[2]).FromJust());
  info.GetReturnValue().Set(result);
}

NAN_METHOD(SolitaireWrap::MovesMadeNormalizedCount)
{
  SolitaireWrap *obj = Nan::ObjectWrap::Unwrap<SolitaireWrap>(info.This());
  auto result = obj->value_->MovesMadeNormalizedCount();
  info.GetReturnValue().Set(result);
}

NAN_METHOD(SolitaireWrap::FoundationCount)
{
  SolitaireWrap *obj = Nan::ObjectWrap::Unwrap<SolitaireWrap>(info.This());
  auto result = obj->value_->FoundationCount();
  info.GetReturnValue().Set(result);
}

NAN_METHOD(SolitaireWrap::SolveMinimalMultithreaded)
{
  SolitaireWrap *obj = Nan::ObjectWrap::Unwrap<SolitaireWrap>(info.This());
  auto result = obj->value_->SolveMinimalMultithreaded(Nan::To<int>(info[0]).FromJust(), Nan::To<int>(info[1]).FromJust());
  info.GetReturnValue().Set(result);
}

NAN_METHOD(SolitaireWrap::MovesMadeCount)
{
  SolitaireWrap *obj = Nan::ObjectWrap::Unwrap<SolitaireWrap>(info.This());
  auto result = obj->value_->MovesMadeCount();
  info.GetReturnValue().Set(result);
}

NAN_METHOD(SolitaireWrap::GetMoveInfo)
{
  SolitaireWrap *obj = Nan::ObjectWrap::Unwrap<SolitaireWrap>(info.This());
  auto index = Nan::To<int>(info[0]).FromJust();
  auto move = obj->value_->operator[](index);
  auto result = obj->value_->GetMoveInfo(move);
  info.GetReturnValue().Set(Nan::New(result.c_str()).ToLocalChecked());
}

NAN_METHOD(SolitaireWrap::MakeMove)
{
  SolitaireWrap *obj = Nan::ObjectWrap::Unwrap<SolitaireWrap>(info.This());
  auto index = Nan::To<int>(info[0]).FromJust();
  auto move = obj->value_->operator[](index);
  obj->value_->MakeMove(move);
}

NAN_METHOD(SolitaireWrap::MovesMade)
{
  SolitaireWrap *obj = Nan::ObjectWrap::Unwrap<SolitaireWrap>(info.This());
  auto result = obj->value_->MovesMade();
  info.GetReturnValue().Set(Nan::New(result.c_str()).ToLocalChecked());
}

NAN_METHOD(SolitaireWrap::LoadPysol)
{
  SolitaireWrap *obj = Nan::ObjectWrap::Unwrap<SolitaireWrap>(info.This());
  // from v8 to cpp
  v8::Isolate *isolate = info.GetIsolate();
  v8::String::Utf8Value str(isolate, info[0]);
  std::string cppStr(*str);
  obj->value_->LoadPysol(cppStr);
}
