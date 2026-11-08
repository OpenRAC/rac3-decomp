#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_004AB040);

INCLUDE_ASM("asm/levels", func_L01_004AB048);

/* localdecomp:start func_L01_004AB070 */
typedef struct { s32 id; s32 val; } E_4A7680;
extern E_4A7680 D_L01_002F7780[];
typedef struct { s16 id; s16 idx; s32 val; } O_4A7680;
void func_L01_004AB070(O_4A7680 *a0) {
    s32 i;
    for (i = 0; D_L01_002F7780[i].id != -1 && D_L01_002F7780[i].id != a0->id; i++) {
    }
    a0->idx = i;
    a0->val = D_L01_002F7780[i].val;
}
/* localdecomp:end func_L01_004AB070 */

/* localdecomp:start func_L01_004AB0E0 */
extern u8 D_001A30B0[];
typedef struct Ent144 {
    s32 a;
    void (*fn)(struct Ent144 *);
    u8 pad[136];
} Ent144;

typedef struct {
    u8 used;
    u8 pad[95];
} Ent96;

typedef struct {
    u8 pad[184];
    s32 count;
    Ent144 *ents;
} Mgr;

extern Ent96 D_L01_0023A7F0[12];
extern void func_L01_004AB3E8(Ent96 *);

void func_L01_004AB0E0(void) {
    s32 i;

    for (i = 0; i < (*(Mgr *)&D_001A30B0).count; i++) {
        if ((*(Mgr *)&D_001A30B0).ents[i].fn != 0) {
            (*(Mgr *)&D_001A30B0).ents[i].fn(&(*(Mgr *)&D_001A30B0).ents[i]);
        }
    }
    for (i = 0; i < 12; i++) {
        if (D_L01_0023A7F0[i].used != 0) {
            func_L01_004AB3E8(&D_L01_0023A7F0[i]);
        }
    }
}
/* localdecomp:end func_L01_004AB0E0 */

/* localdecomp:start func_L01_004AB188 */
typedef struct {
    unsigned char prefix_00[0x40];
    unsigned char selector_40;
    unsigned char axis_41;
    unsigned char mode_42;
    unsigned char dirty_43;
    unsigned char pad_44[0xB0 - 0x44];
    unsigned int value_B0;
    int value_B4;
} S_4AB188;

/* from rac2-decomp's func_L00_0035F8D0 */
void func_L01_004AB188(int value60, int selector68, int value64, int axis69, int mode6A)
{
    S_4AB188 *state = D_001A30B0;
    state->value_B0 = value60;
    if (state->selector_40 != selector68) {
        state->selector_40 = selector68;
        state->dirty_43 |= 1;
    }
    if (state->value_B4 != value64) {
        state->value_B4 = value64;
        state->dirty_43 |= 4;
    }
    if (state->axis_41 != axis69 || state->mode_42 != mode6A) {
        state->mode_42 = mode6A;
        state->axis_41 = axis69;
        state->dirty_43 |= 2;
    }
}
/* localdecomp:end func_L01_004AB188 */
