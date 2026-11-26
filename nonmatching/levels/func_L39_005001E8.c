/* PAL (k6-a3, 2026-11-26): this C gives MATCH with tools/check.py (level 39, the file's @ee29 @eeas line),
 * but only with `(flags & (v = 6)) == v` for the `(flags & 6) == 6` test (retail loads the 6 before the andi;
 * every plain spelling gives andi first: 3 raw rows). Not landed because of that wording; the rest is plain:
 * the switch needs a 14th case label (`case 4:` on default) to get gcc's jump table (136 entries), case order
 * 1,2,3,106,108,136,107,8,9,11,12, case 12 `ret = 1`, the 0x20 flag via `unsigned long fl; (fl & 0x20) >> 5`
 * (retail's dsrl), the mode strings as unsized struct arrays (lui/addiu, no $gp).
 */
#include "common.h"
/* functional: high. Switch on cmd (1..136) over a FILE-like handle wrapper: seek/tell/close/open dispatch; compiled as a normal switch, so bytes differ (178 diff). All cmds, paths and callee args taken from the jump table and branches. */
extern s32 func_0011B570(s32, s32, s32);
extern s32 func_0011BA80(s32);
extern s32 func_0011AF68(s32, s32);
extern s32 func_0011A8A0(s32);
extern s32 *func_0011A6E0(void);
extern s32 func_L39_005000F8(void *);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void func_L39_004DE348(s32, void *, s32, void *, s32, void *);

typedef struct T3_005001E8 {
    u16 h;
    u8 b;
} T3_005001E8;

extern T3_005001E8 D_00478F60[];
extern u16 D_00478F68[];
extern T3_005001E8 D_00478F70[];
extern u16 D_00478F78[];
extern u16 D_00478F80[];
extern u8 D_00478F88[];
extern u8 D_00478F90[];
extern u8 D_00478F98[];

typedef struct S_005001E8 {
    s32 pad0[3];
    s32 f0C;
    s32 f10;
    s32 pad14[2];
    s32 f1C;
    s32 f20;
} S_005001E8;

s32 func_L39_005001E8(S_005001E8 *s, s32 cmd, s32 flags, s32 *ptr) {
    s32 ret;
    s32 h;
    s32 v;
    T3_005001E8 mode;
    s32 args[2];

    ret = 1;
    h = s->f20;
    switch (cmd) {
    case 1:
    case 128:
        v = func_0011B570(h, flags, 0);
        if (v != 0) {
            ret = -1;
        }
        break;
    case 2:
        {
            unsigned long fl = *(u16 *)(h + 0xC);
            ret = (fl & 0x20) >> 5;
        }
        break;
    case 3:
    case 133:
        ret = func_0011BA80(h);
        break;
    case 106:
        func_L39_005000F8(s);
        s->f10 = flags & 1;
        s->f20 = (s32)ptr;
        s->f0C = 1;
        break;
    case 108:
        if (flags & 8) {
            if (flags & 2) {
                mode.h = D_00478F60[0].h;
                mode.b = D_00478F60[0].b;
            } else {
                mode.h = D_00478F68[0];
            }
        } else if ((flags & (v = 6)) == v) {
            mode.h = D_00478F70[0].h;
            mode.b = D_00478F70[0].b;
        } else if (flags & 4) {
            mode.h = D_00478F78[0];
        } else if (flags & 2) {
            mode.h = D_00478F80[0];
        } else {
            func_L39_004BC6C8(0x20, 0x6E, 0x64, 0, 0);
            ret = 0;
            break;
        }
        args[0] = (s32)ptr;
        args[1] = (s32)&mode;
        if (0) {
    case 136:
            args[0] = ptr[0];
            args[1] = ptr[1];
        }
        func_L39_005000F8(s);
        s->f10 = flags & 1;
        h = func_0011AF68(args[0], args[1]);
        if (h == 0) {
            ret = 0;
            func_L39_004BC6C8(2, 1, *func_0011A6E0(), 0, 0);
            func_L39_004DE348(5, D_00478F88, args[0], D_00478F90, args[1], D_00478F98);
            func_L39_004BC6C8(0x20, 0x6E, 0x802, 0, 0);
            break;
        }
        s->f20 = h;
        s->f0C = 1;
        break;
    case 107:
        if (ptr != 0) {
            *ptr = h;
        }
        break;
    case 8:
        ret = s->f10;
        break;
    case 9:
        s->f10 = flags & 1;
        break;
    case 11:
        v = func_0011A8A0(s->f20);
        if (v != 0) {
            ret = -1;
        }
        break;
    case 12:
        ret = 1;
        break;
    case 4:
    default:
        ret = 0;
        break;
    }
    return ret;
}
