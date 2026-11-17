#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void func_00396838(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { u16 x0; u16 x2; u16 x4; u8 x6; u8 x7; } E_38ED00;
extern E_38ED00 *D_001D9EA4[];
s32 func_00392F68(s32);
extern void func_003966D8();


typedef struct {
    u8 pad[0x84];
    u16 f84;
    u8 pad2[0xF0 - 0x86];
} S_391E30;
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern S_391E30 D_001DAA40[];
/* localdecomp:start func_00396690 */
s32 func_00396690(void) {
    u8 *b = D_001A4BE0;
    s32 r = *(s32 *)(b + 0x1228);
    u8 f = b[0x25E4];
    u8 *q = (u8 *)D_001425C0 + r;
    S_391E30 *t = D_001DAA40;
    if (t[*q].f84 == 0) {
        r = 0;
    }
    if (f != 0) {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_00396690 */

typedef struct {
    u8 f0;
    u8 p1[0x37];
    u16 f38;
    u8 p3A[0x50];
    u16 f8A;
    u8 p8C[0xF0 - 0x8C];
} S_391E78;
extern u8 D_001D5EA4;
extern s32 D_001D5E98;
extern s32 D_001D5E9C;
extern s32 D_001D5EA0;
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern S_391E78 D_001DAA40_003966D8[];
extern s32 func_00396690(void);
extern void func_003935B0(s32 id, s32 v);
extern void func_00396390();
extern void func_00397B10();
extern s32 func_003963C0(void);
extern void func_003938F8();
extern s32 func_00396278();
/* localdecomp:start func_003966D8 */
/* from boot_elf's func_00396AB8 */
__asm__(".extern D_001D5E98, 4");
__asm__(".extern D_001D5EA4, 1");
extern void func_00393348();
extern void func_00393930();
extern s32 D_001D5E9C_003966D8[] __attribute__((section(".sdata")));

void func_003966D8(void)
{
    s32 selected;
    u8 *state;
    S_391E78 *record;
    s32 valid;
    u16 label;
    u8 *lookup;
    if (D_001D5EA4 != 0) return;
    if (D_001D5E98 != 0) return;
    selected = func_00396690();
    lookup = D_001425C0 + selected;
    record = &D_001DAA40_003966D8[*lookup];
    label = record->f38;
    valid = record->f0;
    if (selected != 0 && valid != 0) {
        D_001D5E9C_003966D8[0] = selected;
        D_001D5E9C_003966D8[1] = ((s32 (*)())func_00393348)(0x10, label,
            func_00396390, func_00397B10, func_003963C0,
            &D_001427F0[selected], D_001DAA40_003966D8[*lookup].f8A);
        return;
    }
    state = D_001A4BE0;
    if (state[0x25E4] == 2) {
        if (D_001D5E9C_003966D8[1] != -1) {
            func_003935B0(D_001D5E9C_003966D8[1], 0);
            D_001D5E9C_003966D8[1] = -1;
        }
        *(u16 *)(state + 0x1A88) = ((s32 (*)())func_00393348)(0x10, 0xFFFF,
            func_003938F8, func_00393930, func_00396278, state + 0x1A84, 0xC8);
    } else if (D_001D5E9C_003966D8[1] != -1) {
        func_003935B0(D_001D5E9C_003966D8[1], 0);
        D_001D5E9C_003966D8[1] = -1;
    }
}
/* localdecomp:end func_003966D8 */
