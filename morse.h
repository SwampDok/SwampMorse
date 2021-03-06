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

#ifndef Morse_H
#define Morse_H

#include <QObject>
#include <QVector>
#include <QTimer>
#include <QSoundEffect>
#include <QUrl>
#include <QDebug>
#include <QFile>

#include <QBitArray>
#include <QString>
#include <QMap>

#include "alphabet.h"


// Класс служит для генерации звукового кода Морзе
// Тире = три точки
// Пауза между элементами одного символа - точка
// Пауза между символами - 3 точки
// Пауза между словами - 7 точек

//
// В качестве источника звука выступает синусоидальный сигнал записанный в .wav файл
// Хранится в корне программы, но может быть программно установлен другой файл

//Пример использования класса:
/*


// По умолчанию используется для генерации звука
// файл sin10s.wav в корне программы

Morse m(90); //В аргументе задается длительность точки в мс
//Добавляем новый код
//Если комбинация с таким же ключем уже имеется,
//то новая комбинации заменит старую
m.AddCode ('A', ".-");

//... //Вставляем нужный набор кодов

//Далее нужно передать строку для воспроизведения
//Коды символов строки должы быть в объекте класса
//Иначе программа остановит воспроизведение
QString s = "hello";
m.set_string_to_play_ (s);

//Воспрозведение заданной строки
m.Play ()
*/

class Morse : public QObject
{
  Q_OBJECT

private:

  //Хранит соответствующие комбинации точек и тире символов
  QMap<QChar, QBitArray> codes_;

  uint duration_dot_;// Длительность точки в мС

  QSoundEffect sound_; //Служит для работы с .wav файлом

  //Хранит строку для воспроизведения
  QString string_to_play_;

  uint id_char_; //Храние текущее положение текущего символа
  uint id_element_; //Хранит положение текущего элемента

  bool stop_; //false - таймеры продолжают вызываться и при выключенном звуке
              //true - запрещает вызов всех таймеров

public:
  explicit Morse (uint duration_point = 150, QString source_sound = "sin10s.wav", QObject *parent = 0);

  //
  // Методы управления кодами
  //

  //Код представляется в виде строки из точек и тире
  //Например, "--.-" или ".-.."
  void AddCode (QChar key, QString code);

  //Выводит все коды в qDebug()
  //Выведет корректно при условии, что коды добавлены в порядке a-z
  void PrintAllCodes ();


  //
  // Методы set_
  //

  void set_duration_dot (uint duration_dot);

  void set_string_to_play_ (QString &string);

  // Устаналивает адрес .wav файла на основе которого будет получено звучание кода Морзе
  // Останавливает воспроизведение и сбрасывает все счетчики
  bool set_source_sound (QString new_source_sound);

  void set_stop (bool stop);

  //
  // Методы get_
  //

  bool get_stop() const;


signals:

public slots:

  //
  // Слоты управлением воспроизведения
  //

  // Запускает воспроизведение строки String_to_play
  // После вызова слота Stop() желательно сделать остановку на несколько сот мС
  // Иначе может случиться некорректная работа программы
  bool Play();

  // Останавливает воспроизведение и сбрасывает все счетчики
  void Stop ();


private slots:
  // Метод вызывает паузы, управляет выбором воспроизводимого символа
  // Воспроизводит точки и тире
  void Mute ();

  void MiniSpace (); // Реализует паузу между символами

  void Space (); // Реализует паузу между словами


};

#endif // Morse_H
