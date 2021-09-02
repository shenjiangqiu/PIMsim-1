#ifndef __CONFIG_H_
#define __CONFIG_H_

/////////////////- set unit size - ///////////////////
typedef uint16_t    unit_t;
#define debug_mode
//////////////////////////////////////////////////////

#pragma once
#define NOP_END           77
#define EXIT_END          765

#define BGS_PER_PCH       4
#define BKS_PER_BG        4
#define ROWS_PER_BK       8
#define COLS_PER_BK       32
#define WORDS_PER_BK      (ROWS_PER_BK * COLS_PER_BK)   // 256
#define UNITS_PER_WORD    16
#define UNITS_PER_ROW     (COLS_PER_BK * UNITS_PER_WORD)
#define UNITS_PER_BK      (WORDS_PER_BK * UNITS_PER_WORD)

#define NUM_PCHS          16
#define NUM_BGS           (NUM_PCHS * BGS_PER_PCH)      // 64
#define NUM_BANKS         (NUM_BGS * BKS_PER_BG)        // 256
#define NUM_PIMS          (NUM_BANKS / 2)               // 128

// SIZE IS BYTE
#define UNIT_SIZE         (sizeof(unit_t))
#define WORD_SIZE         (UNITS_PER_WORD * UNIT_SIZE)
#define BANK_SIZE         (WORDS_PER_BK * WORD_SIZE)    // 256 * 16 * 4
#define PIM_PHYSMEM_SIZE  (2 * BANK_SIZE)               // 2 * 256 * 16 * 4
#define PHYSMEM_SIZE      (NUM_BANKS * BANK_SIZE)       // 256 * 256 * 16 * 4

#define GRF_SIZE          (8 * UNITS_PER_WORD * UNIT_SIZE)
#define SRF_SIZE          (8 * UNIT_SIZE)

enum class PIM_OPERATION {
	NOP=0,
	JUMP,
	EXIT,
	MOV=4,
	FILL,
	ADD=8,
	MUL,
	MAC,
	MAD
};

enum class PIM_OP_TYPE {
    CONTROL=0,
    DATA,
    ALU
};

enum class PIM_OPERAND {
    BANK=0,
    GRF_A,
    GRF_B,
    SRF_A,
    SRF_M,
    NONE
};

#endif  // CONFIG_H_
