#include "common.h"

typedef struct { u8 before[0xB8]; s32 count; u8 *table; } CallbackGlobals;
typedef struct { u8 active; u8 pad[0x5F]; } Slot;

/* localdecomp:start func_L39_005F3828 */
extern u8 D_001FE020[];
extern Slot D_L39_002B8DA0[12];
extern void func_L39_005F3B18(Slot *p);

void func_L39_005F3828(void) {
    s32 i;
    for (i = 0; i < ((CallbackGlobals *)D_001FE020)->count; i++) {
        u8 *entry = (u8 *)(i * 0x90 + (s32)((CallbackGlobals *)D_001FE020)->table);
        void (*callback)(u8 *) = *(void (**)(u8 *))(entry + 4);
        if (callback) callback(entry);
    }
    for (i = 0; i < 12; i++) {
        if (D_L39_002B8DA0[i].active) func_L39_005F3B18(&D_L39_002B8DA0[i]);
    }
}
/* localdecomp:end func_L39_005F3828 */

/* localdecomp:start func_L39_005F38D0 */
typedef struct {
    unsigned char prefix_00[0x40];
    unsigned char selector_40;
    unsigned char axis_41;
    unsigned char mode_42;
    unsigned char dirty_43;
    unsigned char pad_44[0xB0 - 0x44];
    unsigned int value_B0;
    int value_B4;
} S_5F38D0;

/* from rac2-decomp's func_L00_0035F8D0 */
void func_L39_005F38D0(int value60, int selector68, int value64, int axis69, int mode6A)
{
    S_5F38D0 *state = (S_5F38D0 *)D_001FE020;
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
/* localdecomp:end func_L39_005F38D0 */

/* localdecomp:start func_L39_005F3948 */
#include "vu0.h"

extern u8 D_001FE020[];
extern u8 D_001FE070[];
extern s32 D_001D870C_sda;
extern void func_00194670(void);
extern s32 func_00193590(void);
extern void func_00193DF0(void);
extern s32 func_00139E08(s32);
extern void func_003A5620(void);

void func_L39_005F3948(void) {
    s32 i;
    u8 *p;

    func_00194670();
    func_00193590();
    func_00193DF0();
    D_001D870C_sda = 0xB4;
    while (func_00193590() != 0) {
        func_00139E08(0);
        if (D_001D870C_sda == 0) {
            break;
        }
        D_001D870C_sda--;
    }
    for (i = 3; i >= 0; i--) {
        qzero(D_001FE070 + i * 0x10);
    }
    p = D_001FE020;
    *(s32 *)(p + 0x48) = 0;
    for (i = 0x33; i >= 0; i--) {
        *(s32 *)(p + 0xC0) = 0;
        p[0xD0] = 0;
        p += 0x80;
    }
    func_003A5620();
}
/* localdecomp:end func_L39_005F3948 */
