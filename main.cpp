#include <QCoreApplication>

#include <QString>
#include <QTimer>

#include "morse.h"

int main (int argc, char *argv[])
{
  QCoreApplication a (argc, argv);

  Morse m (130);

  m.AddCode ('a', ".-");
  m.AddCode ('b', "-...");
  m.AddCode ('c', "-.-.");
  m.AddCode ('d', "-..");
  m.AddCode ('e', ".");
  m.AddCode ('f', "..-.");
  m.AddCode ('g', "--.");
  m.AddCode ('h', "....");
  m.AddCode ('i', "..");
  m.AddCode ('j', ".---");
  m.AddCode ('k', "-.-");
  m.AddCode ('l', ".-..");
  m.AddCode ('m', "--");
  m.AddCode ('o', "---");
  m.AddCode ('p', ".--.");
  m.AddCode ('q', "--.-");
  m.AddCode ('r', ".-.");
  m.AddCode ('s', "...");
  m.AddCode ('t', "-");
  m.AddCode ('u', "..-");
  m.AddCode ('v', "...-");
  m.AddCode ('w', ".--");
  m.AddCode ('x', "-..-");
  m.AddCode ('y', "-.--");
  m.AddCode ('z', "--..");

  QString s = "hi bro";

  m.set_string_to_play_ (s);

  m.Play ();


  return a.exec();
}
