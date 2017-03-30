//
// Created by Adri on 22/03/2017.
//

#ifndef PLD_COMP_IR_IRENUM_H
#define PLD_COMP_IR_IRENUM_H

#ifndef MNEMOTYPE
# define MNEMOTYPE
enum mnemotype {
    MNEMO_CONST = 500,
    MNEMO_PLUS = 501,
    MNEMO_MOINS = 502,
    MNEMO_MULT = 503,
    MNEMO_INF = 504,
    MNEMO_INFEQ = 505,
    MNEMO_SUP = 506,
    MNEMO_SUPEQ = 507,
    MNEMO_EGAL = 508,
    MNEMO_CALL = 509,
    MNEMO_LECT = 510,
    MNEMO_ECR = 511,
    MNEMO_DIV = 512,
};
#endif
#endif //PLD_COMP_IR_IRENUM_H
