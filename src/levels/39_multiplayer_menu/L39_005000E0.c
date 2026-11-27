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

/* localdecomp:start func_L39_005004F8 */
typedef struct S_005004F8 {
    s32 pad0[3];
    s32 f0C;
    s32 pad10;
    s32 f14;
    s32 pad18;
    s32 f1C;
    s32 f20;
} S_005004F8;

s32 func_L39_005004F8(S_005004F8 *p) {
    p->f0C = 0;
    p->f1C = 0;
    p->f20 = 0;
    p->f14 = 0;
    return 1;
}
/* localdecomp:end func_L39_005004F8 */

/* localdecomp:start func_L39_00500510 */
extern s32 func_0012ACC8(s32);

typedef struct S_00500510 {
    s32 pad0[3];
    s32 f0C;
    s32 f10;
    s32 f14;
    s32 pad18;
    s32 f1C;
} S_00500510;

s32 func_L39_00500510(S_00500510 *p) {
    if (p == 0) {
        return 0;
    }
    if (p->f10 == 0) {
        return 1;
    }
    if (p->f0C == 0) {
        p->f14 = 0;
    } else {
        func_0012ACC8(p->f1C);
        p->f14 = 0;
    }
    p->f0C = 0;
    return 1;
}
/* localdecomp:end func_L39_00500510 */

/* localdecomp:start func_L39_00500568 */
s32 *func_0011A6E0(void);
s32 func_0012B080(s32, void *, s32);
void func_L39_004BB428(void *);
void func_L39_004BB400(void *);
s32 func_L39_00505BC8(s32);

s32 func_L39_00500568(Type1 *arg0, void *arg1, s32 arg2) {
    s32 r = 0;

    if (arg1 != 0) {
        *func_0011A6E0() = 0;
        r = func_0012B080(arg0->f1C, arg1, arg2);
        func_L39_004BB428(arg0);
        if (r <= 0 && func_L39_00505BC8(r) != 0) {
            func_L39_004BB400(arg0);
        }
    }
    return r;
}
/* localdecomp:end func_L39_00500568 */

/* localdecomp:start func_L39_00500600 */
s32 *func_0011A6E0(void);
s32 func_0012B2F0(s32, void *, s32);
void func_L39_004BB428(void *);
void func_L39_004BB410(void *);
s32 func_L39_00505BC8(s32);

s32 func_L39_00500600(Type1 *arg0, void *arg1, s32 arg2) {
    s32 r;

    *func_0011A6E0() = 0;
    r = func_0012B2F0(arg0->f1C, arg1, arg2);
    func_L39_004BB428(arg0);
    if (r <= 0 && func_L39_00505BC8(r) != 0) {
        func_L39_004BB410(arg0);
    }
    return r;
}
/* localdecomp:end func_L39_00500600 */

/* localdecomp:start func_L39_00500680 */
typedef struct S_00500680 {
    char *name;
    char *desc;
    s32 flags;
} S_00500680;

s32 func_0012AE40(s32, s32, s32);
s32 func_0012AA38(char *, s32);
void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern char D_L39_004791C0[] __attribute__((aligned(8)));
extern char D_L39_004791D8[] __attribute__((aligned(8)));
extern char D_L39_004791F0[] __attribute__((aligned(8)));
extern char D_L39_00479200[] __attribute__((aligned(8)));
extern char D_L39_00479210[] __attribute__((aligned(8)));
extern char D_L39_00479238[] __attribute__((aligned(8)));

s32 func_L39_00500680(void *arg0, s32 cmd, s64 arg, s32 *arg3) {
    s32 *p = arg0;
    s32 r = 1;
    s32 fd;
    s32 flags;
    char buf[64] __attribute__((aligned(8)));
    S_00500680 open;

    switch (cmd) {
    case 1:
        arg = 0;
    case 128:
        if (func_0012AE40(p[7], arg, 0) != arg) {
            r = -1;
        }
        break;
    case 3:
    case 133:
        r = func_0012AE40(p[7], 0, 1);
        break;
    case 108:
        if (arg & 8) {
            if (arg & 2) {
                flags = 0x203;
                __builtin_memcpy(buf, D_L39_004791C0, 21);
            } else {
                flags = 0x202;
                __builtin_memcpy(buf, D_L39_004791D8, 23);
            }
        } else if ((arg & 6) == 6) {
            flags = 3;
            __builtin_memcpy(buf, D_L39_004791F0, 9);
        } else if (arg & 4) {
            __builtin_memcpy(buf, D_L39_00479200, 11);
            flags = 0x602;
            __builtin_memcpy(buf, D_L39_00479210, 35);
        } else if (!(arg & 2)) {
            func_L39_004BC6C8(0x20, 0x6E, 0x64, 0, 0);
            r = 0;
            break;
        } else {
            flags = 1;
            __builtin_memcpy(buf, D_L39_00479238, 11);
        }
        open.flags = flags;
        open.name = (char *)arg3;
        open.desc = buf;
        goto do_open;
    case 104:
        func_L39_00500510((S_00500510 *)p);
        p[7] = *arg3;
        p[4] = (arg & 1) ? 1 : 0;
        p[3] = 1;
        break;
    case 105:
        if (p[3] == 0) {
            r = -1;
        } else {
            if (arg3 != 0) {
                *arg3 = p[7];
            }
            r = p[7];
        }
        break;
    case 136:
        open.name = ((S_00500680 *)arg3)->name;
        open.desc = ((S_00500680 *)arg3)->desc;
    do_open:
        func_L39_00500510((S_00500510 *)p);
        p[7] = *arg3;
        p[4] = (arg & 1) ? 1 : 0;
        fd = func_0012AA38(open.name, open.flags);
        if (fd < 0) {
            r = 0;
            break;
        }
        p[7] = fd;
        p[3] = 1;
        break;
    case 8:
        r = p[4];
        break;
    case 9:
        p[4] = (arg & 1) ? 1 : 0;
        break;
    case 11:
    case 12:
        r = 1;
        break;
    case 2:
    case 106:
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    default:
        r = 0;
        break;
    }
    return r;
}
/* localdecomp:end func_L39_00500680 */

/* localdecomp:start func_L39_00500948 */
/* Uses the file's declarations of func_00120884 and func_L39_00500600. */
s32 func_L39_00500948(void *a0, u8 *a1) {
    return func_L39_00500600(a0, a1, func_00120884(a1));
}
/* localdecomp:end func_L39_00500948 */

/* localdecomp:start func_L39_00500990 */
s32 func_0012AE40(s32, s32, s32);
s32 func_00120808(char *, char *);
extern char D_00479470[];

s32 func_L39_00500990(void *arg0, char *buf, s32 size) {
    s32 len;
    s32 pos;
    s32 n;

    len = 0;
    buf[0] = 0;
    if (size <= 0) {
        return 0;
    }
    pos = func_0012AE40(*(s32 *)((u8 *)arg0 + 0x1C), 0, 1);
    if (pos == -1) {
        return 0;
    }
    if (func_0012B080(*(s32 *)((u8 *)arg0 + 0x1C), buf, size - 1) <= 0) {
        return 0;
    }
    n = func_00120808(buf, D_00479470);
    if (buf[n] == '\n') {
        n++;
    }
    buf[n] = 0;
    if (buf[0] != 0) {
        len = func_00120884(buf);
    }
    if (func_0012AE40(*(s32 *)((u8 *)arg0 + 0x1C), pos + n, 0) == -1) {
        len = 0;
    }
    return len;
}
/* localdecomp:end func_L39_00500990 */
