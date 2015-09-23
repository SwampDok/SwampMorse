/*************************************************************
** Copyright (C) 2015 Михайлусов Алексей (Swamp_Dok)
** Contact: swampDok@gmail.com
** Site: http://73-it.ru/
**
** Licenses:
** Библиотека Qt использована по лицензии GNU Lesser General Public License.
**
***************************************************************/
#ifndef ALPHABET
#define ALPHABET

//Пробел между словами
#define SPACE false << false << false << false << false << false << false

//Пробел между символами
#define MINI_SPACE false << false << false

#define DOT true

#define DASH true << true << true

//
//Между элементами одного символа делается пауза в одну точку
//

#define A DOT << false << DASH

#define B DASH << false << DOT << false << DOT << false << DOT

#define C DASH << false << DOT << false << DASH << false << DOT

#define D DASH << false << DOT << false << DOT

#define E DOT

#define F DOT << false << DOT << false << DASH << false << DOT

#define G DASH << false << DASH << false << DOT

#define H DOT << false << DOT << false << DOT << false << DOT

#define I DOT << false << DOT

#define J DOT << false << DASH << false << DASH << false << DASH

#define K DASH << false << DOT << false << DASH

#define L DOT << false << DASH << false << DOT << false << DOT

#define M DASH << false << DASH

#define N DASH << false << DOT

#define O DASH << false << DASH << false << DASH

#define P DOT << false << DASH << false << DASH << false << DOT

#define Q DASH << false << DASH << false << DOT << false << DASH

#define R DOT << false << DASH << false << DOT

#define S DOT << false << DOT << false << DOT

#define T DASH

#define U DOT << false << DOT << false << DASH

#define V DOT << false << DOT << false << DOT << false << DASH

#define W DOT << false << DASH << false << DASH

#define X DASH << false << DOT << false << DOT << false << DASH

#define Y DASH << false << DOT << false << DASH << false << DASH

#define Z DASH << false << DASH << false << DOT << false << DOT


#endif // ALPHABET

