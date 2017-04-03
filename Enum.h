//
// Created by Adri on 22/03/2017.
//

#ifndef PLD_COMP_ENUM_H
#define PLD_COMP_ENUM_H

#ifndef YYTOKENTYPE
# define YYTOKENTYPE
enum yytokentype {
    EGAL = 258,
    PLUS = 259,
    MULT = 260,
    DIV = 261,
    MOINS = 262,
    AND = 263,
    DAND = 264,
    OR = 265,
    DOR = 266,
    DEGAL = 267,
    INFEQ = 268,
    SUPEQ = 269,
    DIFF = 270,
    MOD = 271,
    XOR = 272,
    PLUSEQ = 273,
    MULTEQ = 274,
    DIVEQ = 275,
    MOINSEQ = 276,
    DPLUS = 277,
    DMOINS = 278,
    NOT = 279,
    MODEQ = 280,
    DSUP = 281,
    DINF = 282,
    INF = 283,
    SUP = 284,
    ANDEQ = 285,
    OREQ = 286,
    IF = 287,
    ELSE = 288,
    WHILE = 289,
    FOR = 290,
    CHAR = 291,
    INT32 = 292,
    INT64 = 293,
    VOID = 294,
    POINTVIR = 295,
    CHEVOPEN = 296,
    CHEVCLOSE = 297,
    POPEN = 298,
    PCLOSE = 299,
    COPEN = 300,
    CCLOSE = 301,
    VIRG = 302,
    PUTCHAR = 303,
    GETCHAR = 304,
    RETURN = 305,
    BREAK = 306,
    NAME = 307,
    JMPLINE = 308,
    NVALUE = 309,
    CVALUE = 310,
    INCL = 311,
    DPLUSAVANT = 312,
    DMOINSAVANT = 313
};
#endif
#endif //PLD_COMP_ENUM_H
