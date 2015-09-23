/*************************************************************
** Copyright (C) 2015 Михайлусов Алексей (Swamp_Dok)
** Contact: swampDok@gmail.com
** Site: http://73-it.ru/
**
** Licenses:
** Библиотека Qt использована по лицензии GNU Lesser General Public License.
**
** Данный исходный код может свободно использоваться, распространяться
** и модифицироваться, но только в некоммерческих целях.
***************************************************************/
#include "Morse.h"

Morse::Morse(uint duration_point, QString source_sound, QObject *parent) : QObject(parent) {
  duration_dot_ = duration_point;
  sound_.setSource (QUrl::fromLocalFile (source_sound));
  sound_.setLoopCount (QSoundEffect::Infinite);

  stop_ = true;

  string_to_play_ = "";
}

void Morse::AddCode (QChar key, QString code) {

  code.remove (" ");

  QBitArray arr;
  arr.resize (code.size ());

  for(int i = 0; i < code.size (); ++i) {
    if (code.at (i) == '.')
      arr[i] = 1;
    else
      arr[i] = 0;
  }

  codes_.insert (key, arr);
}

void Morse::set_duration_dot (uint duration_dot) {
  duration_dot_ = duration_dot;
}

void Morse::set_string_to_play_ (QString &string) {
  this->Stop();
  string_to_play_ = string;
}

bool Morse::set_source_sound (QString new_source_sound) {
  if (!QFile::exists (new_source_sound))
    return false;

  sound_.setSource (QUrl::fromLocalFile (new_source_sound));
  return true;
}

void Morse::MiniSpace () {

  if (stop_) {
    this->Stop ();
    return;
  }

  sound_.setMuted (true);

  ++id_element_; //Преходим на другой элемент кода
  if (  id_element_ == codes_.value ( string_to_play_.at (id_char_) ).size ()  ) {
    ++id_char_;
    id_element_ = 0;
    QTimer::singleShot (duration_dot_ * 3, this, SLOT ( Mute() )); //Пауза между символами
    return;
  }

  QTimer::singleShot (duration_dot_, this, SLOT ( Mute() )); //Пауза между элементами символа
}



void Morse::Space () {

  if (stop_) {
    this->Stop ();
    return;
  }

  sound_.setMuted (true);
  //Пауза длится 7 точек
  //Но так как после символа идет пауза в три точки, то доп паузу нужно выставить длиной в 4 точки
  QTimer::singleShot (duration_dot_ * 4, this, SLOT ( Mute() ));
}



void Morse::Mute () {

  if (stop_) {
    this->Stop ();
    return;
  }

  if (id_char_ == string_to_play_.size ()) { // Строка закончилась
    this->Stop ();
    return;
  }

  if (string_to_play_.at (id_char_)  == ' ') {
    Space();
    ++id_char_; //Преходим на другой элемент кода
    return;
  }

  if (codes_.find ( string_to_play_.at (id_char_) ) == codes_.end ()) {
    qDebug() << string_to_play_.at (id_char_) << ": No code!";
    sound_.stop ();
    return;
  }

  sound_.setMuted (false); //Включаем звук

  if (  codes_.value ( string_to_play_.at (id_char_) ).at (id_element_)) {
    QTimer::singleShot (duration_dot_, this, SLOT ( MiniSpace() )); //Воспроизводим точку
  } else {
    QTimer::singleShot (duration_dot_ * 3, this, SLOT ( MiniSpace() )); //Воспроизводим тире
  }

}

bool Morse::Play () {

  if (!stop_)
    return false;

  if (string_to_play_ == "")
    return false;

  stop_ = false;

  id_char_ = 0;
  id_element_ = 0;
  sound_.setMuted (true); //Выключаем звук
  sound_.play ();
  Mute ();
}


void Morse::PrintAllCodes () {

  for (int i = 0; i < codes_.size (); ++i) {
    for (int j = 0; j < codes_.value ('a' + i).size (); ++j) {
      qDebug() << (char)('a' + i) << " " << codes_.value ('a' + i).at (j);
    }
    qDebug() << "\n";
  }
}

void Morse::Stop () {

  if (stop_)
    return;

  sound_.stop ();
  id_char_ = 0;
  id_element_ = 0;
  stop_ = true;
}

void Morse::set_stop (bool stop) {
  stop_ = stop;
}

bool Morse::get_stop () const{
  return stop_;
}


