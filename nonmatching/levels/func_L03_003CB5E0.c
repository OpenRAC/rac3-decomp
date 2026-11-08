/* near miss (level 3, Starship Phoenix): 106 differences, almost all register allocation (control flow and instruction sequence match; a switch on a0->0x20 with explicit empty cases 0, 1 and 2 reproduces the beq 3 / slti 4 / beq 4 tree): retail keeps a0 in $s4 and the D_L03_001DEF60 loop pointer in $s3, the C swaps them; the case-3 index walk orders and allocates the D_L03_001DE858 and D_001426E0 loads differently; about 17 compiles (loop locals, a table pointer, do-while/for); reading D_001426E0[0x77] directly everywhere took it from 166 to 106 */
#include "common.h"

/* localdecomp:start func_L03_003CB5E0 */
typedef struct {
    u8 pad0[0x40];
    s32 f40;
    s32 f44;
    s32 f48;
    s32 p4C;
    s32 arr50[6];
    s32 arr68[6];
    s32 f80;
    s32 f84;
    u8 pad88[0xC];
    s32 f94;
} S_003CB5E0;
extern u8 D_001426E0[];
extern u8 D_001A4C60[];
extern s32 D_L03_001DE858;
extern s32 D_L03_001DEF28[];
extern s32 D_L03_001DEEF0[];
extern s32 D_L03_001DEF60[];
__asm__(".extern D_L03_001DE858, 16");
extern s32 func_L01_004BA800(void);
extern void func_L03_003CBD50(void *);
extern void func_L03_003CBA20(void *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_00382498(s32, s32);
extern s32 func_L03_003CBB68(void *, s32);
extern f32 func_0038D098(f32);
extern f32 func_L01_004451A8(f32);
extern void func_L03_003CBC28_003CB5E0(void *, f32);
extern void func_L03_003CBBD8_003CB5E0(void *);

void func_L03_003CB5E0(void *a0) {
    S_003CB5E0 *s = *(S_003CB5E0 **)((u8 *)a0 + 0x68);
    s32 i;
    s32 n;
    if (func_L01_004BA800() != 0) {
        if (s->f48 != 0) {
            func_L03_003CBD50(a0);
        }
        return;
    }
    func_L03_003CBA20(a0);
    switch (*((u8 *)a0 + 0x20)) {
    case 0:
    case 1:
    case 2:
        break;
    case 3:
        if (func_00382380(D_001A4C60, s->f44, 0) == 0) {
            if (func_0038CAD0(&s->f40) != 0) {
                if (s->f94 != 0) {
                    s32 m = D_L03_001DE858;
                    s32 st = D_001426E0[0x77];
                    do {
                        n = (D_001426E0[0x77] + 1) % 14;
                        D_001426E0[0x77] = n;
                        if (n == st) return;
                    } while ((((m >> D_L03_001DEF28[(u8)n]) ^ 1) & 1) != 0);
                    s->f94 = 0;
                    s->f40 = (func_00382498(0xE10, 0x1518) * 5 + 2) / 6;
                    if (D_L03_001DEEF0[D_001426E0[0x77]] == 4) {
                        s->f40 = 0x10B;
                    } else if (D_L03_001DEEF0[D_001426E0[0x77]] == 7) {
                        s->f48 = 0xA7;
                        s->f40 = 0x21;
                    }
                }
                if (func_L03_003CBB68(a0, ((s32 *)s)[D_L03_001DEEF0[D_001426E0[0x77]]]) != 0) {
                    s->f94 = 1;
                }
            }
        }
        if (func_0038CAD0(&s->f48) == 0) {
            f32 a = (f32)(s->f48 % 33) * 6.2831855f / 33.0f;
            f32 c = func_0038D098(a);
            func_003CBC28_003CB5E0(a0, func_L01_004451A8((1.0f - c) * 0.5f));
        }
        if (s->f48 == 1) {
            func_L03_003CBD50(a0);
        }
        break;
    case 4:
        for (i = 0; i < 6; i++) {
            if (((s->f84 >> i) & 1) != 0) {
                if ((((s->f80 >> i) ^ 1) & 1) != 0) {
                    if (func_00382380(D_001A4C60, s->arr68[i], 0) != 0) {
                        if (func_L03_003CBB68(a0, s->arr50[D_L03_001DEF60[i]]) != 0) {
                            s->f80 |= 1 << i;
                        }
                    }
                }
            }
        }
        break;
    }
    func_L03_003CBBD8_003CB5E0(a0);
}
/* localdecomp:end func_L03_003CB5E0 */
