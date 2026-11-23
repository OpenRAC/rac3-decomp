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

extern T3_005001E8 D_00478F60;
extern u16 D_00478F68;
extern T3_005001E8 D_00478F70;
extern u16 D_00478F78;
extern u16 D_00478F80;
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
    s32 args[2];
    T3_005001E8 mode;

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
        ret = (*(u16 *)(h + 0xC) >> 5) & 1;
        break;
    case 3:
    case 133:
        ret = func_0011BA80(h);
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
        break;
    case 106:
        func_L39_005000F8(s);
        s->f0C = 1;
        s->f10 = flags & 1;
        s->f20 = (s32)ptr;
        break;
    case 107:
        if (ptr != 0) {
            *ptr = h;
        }
        break;
    case 108:
    case 136:
        if (cmd == 108) {
            if (flags & 8) {
                if (flags & 2) {
                    mode.h = D_00478F60.h;
                    mode.b = D_00478F60.b;
                } else {
                    mode.h = D_00478F68;
                }
            } else if ((flags & 6) == 6) {
                mode.h = D_00478F70.h;
                mode.b = D_00478F70.b;
            } else if (flags & 4) {
                mode.h = D_00478F78;
            } else if (flags & 2) {
                mode.h = D_00478F80;
            } else {
                func_L39_004BC6C8(0x20, 0x6E, 0x64, 0, 0);
                return 0;
            }
            args[0] = (s32)ptr;
            args[1] = (s32)&mode;
        } else {
            args[0] = ptr[0];
            args[1] = ptr[1];
        }
        func_L39_005000F8(s);
        s->f10 = flags & 1;
        h = func_0011AF68(args[0], args[1]);
        if (h == 0) {
            func_L39_004BC6C8(2, 1, *func_0011A6E0(), 0, 0);
            func_L39_004DE348(5, D_00478F88, args[0], D_00478F90, args[1], D_00478F98);
            func_L39_004BC6C8(0x20, 0x6E, 0x802, 0, 0);
            return 0;
        }
        s->f20 = h;
        s->f0C = 1;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}
