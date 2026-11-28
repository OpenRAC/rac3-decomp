#include "common.h"

/* localdecomp:start func_L39_005000E0 */
typedef struct Type1 {
    char _p0[0xC];
    s32 fC;
    char _p10[0x1C - 0x10];
    s32 f1C;
    s32 f20;
} Type1;

/* from rac4-decomp's func_L00_0053BEF0, renamed */
s32 func_L39_005000E0(Type1 *arg0) {
    arg0->fC = 0;
    arg0->f1C = 0;
    arg0->f20 = 0;
    return 1;
}
/* localdecomp:end func_L39_005000E0 */

/* localdecomp:start func_L39_005000F8 */
extern s32 func_0011A7A0(s32);

typedef struct S_005000F8 {
    s32 pad0[3];
    s32 f0C;
    s32 f10;
    s32 pad14[2];
    s32 f1C;
    s32 f20;
} S_005000F8;

s32 func_L39_005000F8(S_005000F8 *p) {
    if (p == 0) {
        return 0;
    }
    if (p->f10 == 0) {
        return 1;
    }
    if (p->f0C != 0) {
        if (p->f20 != 0) {
            func_0011A7A0(p->f20);
            p->f20 = 0;
        }
    }
    p->f0C = 0;
    return 1;
}
/* localdecomp:end func_L39_005000F8 */

/* localdecomp:start func_L39_00500158 */
s32 func_0011AFE8(s32, s32, s32, s32);
s32 func_L39_00500158(void *arg0, s32 arg1, s32 arg2) {
    s32 var_v1;

    var_v1 = 0;
    if ((*(s32 *)((u8 *)arg0 + 0xC)) != 0) {
        if (arg1 != 0) {
            var_v1 = func_0011AFE8(arg1, 1, arg2, (*(s32 *)((u8 *)arg0 + 0x20)));
        }
    }
    return var_v1;
}
/* localdecomp:end func_L39_00500158 */

/* localdecomp:start func_L39_00500198 */
extern s32 func_0011C000(void *, void *, s32, s32);

s32 func_L39_00500198(void *arg0, void *arg1, void *arg2) {
    s32 var_v1;

    var_v1 = 0;
    if ((*(s32 *)((u8 *)arg0 + 0xC)) != 0) {
        if (arg1 != 0) {
            if (func_0011C000(arg1, arg2, 1, (*(s32 *)((u8 *)arg0 + 0x20))) != 0) {
                var_v1 = (s32)arg2;
            }
        }
    }
    return var_v1;
}
/* localdecomp:end func_L39_00500198 */

/* localdecomp:start func_L39_005001E8 */
/* OpenSSL BIO file_ctrl (crypto/bio/bss_file.c): seek, eof, tell, set/get file pointer, set filename
   (the fopen mode chain), get/set close, flush. */
extern s32 func_0011B570(s32, long, s32);
extern s32 func_0011BA80(s32);
extern s32 func_0011AF68(s32, s32);
extern s32 func_0011A8A0(s32);
extern s32 *func_0011A6E0(void);
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

s32 func_L39_005001E8(S_005001E8 *s, s32 cmd, long flags, s32 *ptr) {
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
        func_L39_005000F8((S_005000F8 *)s);
        s->f10 = flags & 1 ? 1 : 0;
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
        } else if ((flags & 2) && (flags & 4)) {
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
        func_L39_005000F8((S_005000F8 *)s);
        s->f10 = flags & 1 ? 1 : 0;
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
        s->f10 = flags & 1 ? 1 : 0;
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
/* localdecomp:end func_L39_005001E8 */

/* localdecomp:start func_L39_00500450 */
extern s32 func_0011A9B8(void *, s32, s32);
extern s32 func_00120884(void *);

typedef struct S_00500450 {
    s32 pad0[8];
    s32 f20;
} S_00500450;

s32 func_L39_00500450(S_00500450 *a0, s8 *a1, s32 a2) {
    s32 var_s1 = 0;

    *a1 = 0;
    func_0011A9B8(a1, a2, a0->f20);
    if (*a1 != 0) {
        var_s1 = func_00120884(a1);
    }
    return var_s1;
}
/* localdecomp:end func_L39_00500450 */

/* localdecomp:start func_L39_005004B0 */
/* from rac2-decomp's func_L00_00323F28 */
/* Uses the file's declarations of func_00120884 and func_L39_00500198. */
s32 func_L39_005004B0(void *a0, u8 *a1) {
    return func_L39_00500198(a0, a1, (void *)func_00120884(a1));
}
/* localdecomp:end func_L39_005004B0 */
