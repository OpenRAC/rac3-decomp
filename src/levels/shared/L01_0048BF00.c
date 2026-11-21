#include "common.h"

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 w12;
} E_488750;
typedef struct VT_00489FA8 { u8 p0[12]; void (*f12)(void *); } VT_00489FA8;
typedef struct O_00489FA8 { u8 p0[4]; VT_00489FA8 *vt; } O_00489FA8;
typedef struct Obj_0048B530 Obj_0048B530;
typedef struct {
    void *pad0[3];
    void (*fn)(Obj_0048B530 *);
} ObjVtbl_0048B530;
struct Obj_0048B530 {
    s32 pad0;
    ObjVtbl_0048B530 *vtbl;
};
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6F30 - 0x4958];
    u8 f6F30[1];
} S_48D030;
typedef struct Obj Obj;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj *);
} ObjVt;
struct Obj {
    s32 pad;
    ObjVt *vt;
};
typedef struct {
    s32 w0;
    void (*fn)(u32);
    s32 w8;
} E_0048D0C8;
typedef struct { u8 b[16]; } V16_48DCD8;

/* localdecomp:start func_L01_0048BF00 */
extern s32 D_L01_001E08A0[] __attribute__((section(".sdata")));
extern s32 D_L01_001D8A60;

void func_L01_0048BF00(void) {
    D_L01_001E08A0[0] = 0;
    D_L01_001E08A0[1] = 0;
    D_L01_001E08A0[2] = 0;
    D_L01_001E08A0[3] = 0;
    D_L01_001D8A60 = 0;
}
/* localdecomp:end func_L01_0048BF00 */

/* localdecomp:start func_L01_0048BF28 */
extern s32 D_L01_001D8A10;

void func_L01_0048BF28(s32 a) {
    D_L01_001D8A10 = a;
}
/* localdecomp:end func_L01_0048BF28 */

/* localdecomp:start func_L01_0048BF30 */
extern s32 D_L01_001D8A10;
void func_L01_0048BF30(void) {
    D_L01_001D8A10 = -1;
}
/* localdecomp:end func_L01_0048BF30 */

/* localdecomp:start func_L01_0048BF40 */
typedef struct {
    s32 id;
    u8 on;
    u8 pad5[0xB0 - 5];
} S_0048BF40;

extern s32 D_L01_001D8A10;
extern s32 D_L01_001D8A2C;
extern S_0048BF40 D_L01_00233DD8[];

s32 func_L01_0048BF40(void) {
    s32 key = D_L01_001D8A10;
    s32 found = 0;
    s32 i = 0;

    if (key >= 0) {
        for (i = 0; i < 30; i++) {
            if (D_L01_00233DD8[i].id == key && D_L01_00233DD8[i].on) {
                D_L01_001D8A2C = i;
                found = 1;
                break;
            }
        }
    }
    D_L01_001D8A10 = -1;
    return found;
}
/* localdecomp:end func_L01_0048BF40 */

/* localdecomp:start func_L01_0048BFC8 */

extern s32 D_L01_001D8BE0;
extern struct U_488750 D_L01_001E0900 __attribute__((section(".sdata")));
extern struct U_488750 D_L01_001D8BDC __attribute__((section(".sdata")));
extern char D_L01_001D8BE8[];
extern char D_L01_001D8BF0[];
extern E_488750 D_L01_002BC9F0[];
extern char *func_00381FF0(s32 id);
extern void func_L01_00516FD8(s32 id, char *s);
extern void func_L01_00517190(s32 id, s32 v);
extern void func_L01_00516D60(s32 id, s32 v);
extern void func_0011B2E8(char *dst, char *fmt, char *s);

void func_L01_0048BFC8(void) {
    s32 v = ((s32 *)&D_L01_001E0900)[D_L01_001D8BE0];
    E_488750 *e;

    if (v == -1) {
        **(char **)&D_L01_001D8BDC = 0;
        func_L01_00516FD8(29, D_L01_001D8BE8);
        func_L01_00517190(28, 17);
        return;
    }
    e = &D_L01_002BC9F0[v];
    func_L01_00516D60(28, 1);
    if (e->w0 != -1) {
        func_0011B2E8(*(char **)&D_L01_001D8BDC, D_L01_001D8BF0, func_00381FF0(e->w0));
    }
    if (e->w4 != -1) {
        func_L01_00516FD8(29, func_00381FF0(e->w4));
    } else {
        func_L01_00516FD8(29, D_L01_001D8BE8);
    }
    if (e->w12 != -1) {
        func_L01_00516D60(28, 1);
        func_L01_00517190(28, e->w12);
    } else {
        func_L01_00517190(28, 17);
    }
}
/* localdecomp:end func_L01_0048BFC8 */

/* localdecomp:start func_L01_0048C0F0 */
typedef struct {
    s32 w0;
    u8 pad4[0x3C];
    s16 h40;
    s16 h42;
} S_0048C0F0;

extern S_0048C0F0 D_00142660;
extern u8 D_001426E0[];
extern u8 D_00142CA0[];
extern s32 D_00142C18[];
extern u8 D_001D554F[] __attribute__((section(".sdata")));
extern u8 D_001D5550[] __attribute__((section(".sdata")));
extern u8 D_001D5551[] __attribute__((section(".sdata")));
extern u8 D_001D5552[] __attribute__((section(".sdata")));
extern u8 D_001D5553[] __attribute__((section(".sdata")));
extern s32 D_L01_001E0900_0048C0F0;
extern char *D_L01_001D8BC0[] __attribute__((section(".sdata")));
extern char *D_L01_001D8BC0_0048C0F0;
extern char D_L01_001D8BF8[];
extern s32 func_L01_00517F50(s32, s32, s32);
extern s32 func_L01_00452740(void);
extern s32 func_L01_004526E8(void);
extern s32 func_0011B2E8_0048C0F0(char *, char *, s32);

void func_L01_0048C0F0(void) {
    s32 i;
    s32 id;
    s32 a, b, r;

    for (i = 9; i >= 0; i--) {
        ((s32 *)&D_L01_001E0900)[i] = -1;
    }
    D_L01_001E0900_0048C0F0 = D_00142660.h40 + 11;
    if (D_00142CA0[0x14]) {
        ((s32 *)&D_L01_001E0900)[1] = 0;
    } else if (D_00142CA0[0x21]) {
        if (!(D_00142C18[0] & 0x1000000)) {
            ((s32 *)&D_L01_001E0900)[1] = 3;
        }
    }
    if (D_00142CA0[7]) ((s32 *)&D_L01_001E0900)[2] = 2;
    if (D_00142CA0[5]) ((s32 *)&D_L01_001E0900)[3] = 1;
    if (D_00142CA0[0x20]) ((s32 *)&D_L01_001E0900)[4] = 0x10;
    if (D_001D554F[0]) ((s32 *)&D_L01_001E0900)[5] = 5;
    if (D_001D5551[0]) ((s32 *)&D_L01_001E0900)[6] = 6;
    if (D_001D5552[0]) ((s32 *)&D_L01_001E0900)[7] = 7;
    if (D_001D5550[0]) ((s32 *)&D_L01_001E0900)[8] = 8;
    if (D_00142CA0[0x22]) ((s32 *)&D_L01_001E0900)[9] = 4;
    if (D_001D5553[0]) ((s32 *)&D_L01_001E0900)[9] = 9;

    for (i = 0; i < 10; i++) {
        id = i + 0x30;
        if (((s32 *)&D_L01_001E0900)[i] == -1 || D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w8 == -1) {
            ((s32 (*)(s32, s32))func_L01_00516D60)(id, 0);
        } else {
            ((s32 (*)(s32, s32))func_L01_00516D60)(id, 1);
            if (D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w0 == 0xC6E) {
                func_L01_00517F50(id, D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w8, 0);
            } else if (D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w0 == 0xC6F) {
                func_L01_00517F50(id, D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w8, 1);
            } else if (D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w0 == 0xC70) {
                func_L01_00517F50(id, D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w8, 2);
            } else if (D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w0 == 0xC71) {
                func_L01_00517F50(id, D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w8, 3);
            } else if (D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w0 == 0xC72) {
                func_L01_00517F50(id, D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w8, 4);
            } else {
                func_L01_00517190(id, D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w8);
            }
        }
    }

    a = func_L01_00452740();
    b = func_L01_004526E8();
    r = 40 - a;
    func_0011B2E8_0048C0F0(D_L01_001D8BC0_0048C0F0, D_L01_001D8BF8, a);
    func_0011B2E8_0048C0F0(D_L01_001D8BC0[1], D_L01_001D8BF8, r);
    func_0011B2E8_0048C0F0(D_L01_001D8BC0[2], D_L01_001D8BF8, b);
    a = D_00142660.h42;
    b = D_001426E0[0x7E];
    r = 101 - a - b;
    func_0011B2E8_0048C0F0(D_L01_001D8BC0[3], D_L01_001D8BF8, a);
    func_0011B2E8_0048C0F0(D_L01_001D8BC0[4], D_L01_001D8BF8, r);
    func_0011B2E8_0048C0F0(D_L01_001D8BC0[5], D_L01_001D8BF8, b);
    func_0011B2E8_0048C0F0(D_L01_001D8BC0[6], D_L01_001D8BF8, D_00142660.w0);
    D_L01_001D8BE0 = 0;
    func_L01_0048BFC8();
}
/* localdecomp:end func_L01_0048C0F0 */

INCLUDE_ASM("asm/levels", func_L01_0048C4A0);

/* localdecomp:start func_L01_0048D588 */
__asm__(".extern D_L01_001D8BE0, 4");
extern void func_L01_0047EC88(void);
extern u8 *D_001D52FC[] __attribute__((section(".sdata")));
extern s32 D_L01_001D8BE0;
extern s32 func_003A5348(s32, s32, s32);
extern void *func_L01_0047EBE0(void);
extern void *func_L01_0047FE28(void);
extern void *func_L01_00489FD0(void);
extern void *func_L01_004914D0(void *);
extern void func_L01_00517748(void *);
extern void func_L01_00516090_0048D588(void *);
extern s32 func_L01_005170B8(s32, s32);
extern u32 func_003825F8(u32, u32, s32, s32, s32, s32);
extern void func_L01_0048BFC8(void);
extern s32 func_L01_0047DAB0(void);
extern void func_L01_0047DAC8(void);
extern u8 D_L01_001D672C_0048D588[] __attribute__((section(".sdata")));

void func_L01_0048D588(void *a0) {
    s32 old;
    u32 pad;
    u32 color;

    func_L01_0047EC88();
    pad = *(u32 *)(D_001D52FC[0] + 0x1C4);
    old = D_L01_001D8BE0;
    if (pad & 0x800) {
        func_L01_00517748(func_L01_0047EBE0());
        func_L01_00516090_0048D588(a0);
    } else if (pad & 0x10) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_0047FE28());
        func_L01_00516090_0048D588(a0);
    } else if (pad & 0x1000) {
        func_003A5348(3, 0, 0);
        D_L01_001D8BE0 -= 5;
        if (D_L01_001D8BE0 < 0) {
            D_L01_001D8BE0 += 10;
        }
    } else if (pad & 0x4000) {
        func_003A5348(3, 0, 0);
        D_L01_001D8BE0 += 5;
        if (D_L01_001D8BE0 >= 10) {
            D_L01_001D8BE0 -= 10;
        }
    } else if (pad & 0x8000) {
        func_003A5348(3, 0, 0);
        D_L01_001D8BE0--;
        if (D_L01_001D8BE0 < 0) {
            D_L01_001D8BE0 = 4;
        } else if (D_L01_001D8BE0 == 4) {
            D_L01_001D8BE0 = 9;
        }
    } else if (pad & 0x2000) {
        func_003A5348(3, 0, 0);
        D_L01_001D8BE0++;
        if (D_L01_001D8BE0 >= 10) {
            D_L01_001D8BE0 = 5;
        } else if (D_L01_001D8BE0 == 5) {
            D_L01_001D8BE0 = 0;
        }
    } else if (pad & 1) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_00489FD0());
        func_L01_00516090_0048D588(a0);
    } else if (pad & 2) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_004914D0(0));
        func_L01_00516090_0048D588(a0);
    }
    if (D_L01_001D8BE0 != old) {
        func_L01_005170B8(old + 0x25, 0x332299DE);
        func_003825F8(0x332299DE, 0x8066CCFF, 40, 0, 1, 1);
    }
    color = func_003825F8(0x332299DE, 0x8066CCFF, 40, 0, 0, 1);
    func_L01_005170B8(D_L01_001D8BE0 + 0x25, color);
    func_L01_0048BFC8();
    if (func_L01_0047DAB0() != 0) {
        func_L01_0047DAC8();
        func_L01_00516090_0048D588(a0);
        if (D_L01_001D672C_0048D588[0] == 0) {
            func_L01_00517748(func_L01_0047EBE0());
        }
    }
}
/* localdecomp:end func_L01_0048D588 */

/* localdecomp:start func_L01_0048D820 */

extern s32 D_L01_001D8BB8;
extern void func_003BB468(s32);
extern O_00489FA8 *func_003B42F8(s32);
extern void func_003A2750(s32);
extern void func_L01_00517918(s32);

void func_L01_0048D820(void) {
    O_00489FA8 *o;
    func_003BB468(D_L01_001D8BB8);
    o = func_003B42F8(0);
    o->vt->f12(o);
    func_003A2750(1);
    func_L01_00517918(15);
    func_L01_00517918(16);
    func_L01_00517918(17);
    func_L01_00517918(18);
    func_L01_00517918(19);
    func_L01_00517918(20);
}
/* localdecomp:end func_L01_0048D820 */

/* localdecomp:start func_L01_0048D898 */
extern void func_L01_0047E4B8_0048D898();

void func_L01_0048D898(void) {
    func_L01_0047E4B8_0048D898();
}
/* localdecomp:end func_L01_0048D898 */

/* localdecomp:start func_L01_0048D8B8 */
extern void func_L01_0047E520_0048D8B8();

void func_L01_0048D8B8(void) {
    func_L01_0047E520_0048D8B8();
}
/* localdecomp:end func_L01_0048D8B8 */

/* localdecomp:start func_L01_0048D8D8 */
extern s32 func_L01_0048D8D8(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E08F8;
extern s32 D_L01_001E08E0[2];
extern void func_L01_0048C4A0();
extern void func_L01_0048D820();
extern void func_L01_0048D588();
extern void func_L01_0048D898_0048D8D8(void);
extern void func_L01_0048D8B8_0048D8D8();
s32 func_L01_0048D8D8(void) {
    if (D_L01_001E08F8 == 0) {
        func_003E6FA0(D_L01_001E08E0, (s32)func_L01_0048C4A0, (s32)func_L01_0048D820, (s32)func_L01_0048D588, (s32)func_L01_0048D898_0048D8D8, (s32)func_L01_0048D8B8_0048D8D8);
        D_L01_001E08F8 = 1;
    }
    return (s32)D_L01_001E08E0;
}
/* localdecomp:end func_L01_0048D8D8 */

/* localdecomp:start func_L01_0048D930 */
extern void func_L01_0048D930(s32, s32);
extern s32 D_L01_001D8C30;
extern s32 D_L01_001D8C34;

void func_L01_0048D930(s32 a, s32 b) { D_L01_001D8C30 = a; D_L01_001D8C34 = b; }
/* localdecomp:end func_L01_0048D930 */

/* localdecomp:start func_L01_0048D940 */
extern s32 D_L01_001D8C84;
extern s32 D_L01_001D8C78;
extern s32 D_L01_001D8C7C;
extern void func_L01_0047DE68(void);
extern s32 func_003BB118(s32);

void func_L01_0048D940(void) {
    func_L01_0047DE68();
    D_L01_001D8C84 = func_003BB118(0);
    D_L01_001D8C78 = 0;
    D_L01_001D8C7C = 0;
}
/* localdecomp:end func_L01_0048D940 */

/* localdecomp:start func_L01_0048D970 */
extern s32 D_L01_001D8C78;
extern s32 D_L01_001D8C34;
extern s32 D_L01_001D8C84;
extern s32 func_003BB118(s32);
extern s32 func_L01_00437B68(s32, s32 *, s32, s32);

void func_L01_0048D970(void) {
    s32 v;
    D_L01_001D8C78 = 0;
    v = func_003BB118(0);
    D_L01_001D8C84 = v;
    if (func_L01_00437B68(v, &D_L01_001D8C78, 409, D_L01_001D8C34) == 0) {
        D_L01_001D8C78 = 0;
    }
}
/* localdecomp:end func_L01_0048D970 */

/* localdecomp:start func_L01_0048D9B0 */
extern void func_L01_0048D970(void);
extern s32 D_L01_001D8C78;
extern s32 D_L01_001D8C7C;

void func_L01_0048D9B0(void) {
    func_L01_0048D970();
    if (D_L01_001D8C7C >= D_L01_001D8C78) {
        D_L01_001D8C7C = D_L01_001D8C78 - 1;
    }
}
/* localdecomp:end func_L01_0048D9B0 */

/* localdecomp:start func_L01_0048D9E8 */
typedef struct {
    s32 w0;
    u8 b4;
    u8 b5;
    u8 pad6[2];
    s32 w8;
    s32 wC;
    u8 b10;
    u8 pad11[3];
} E_0048D9E8;
typedef struct { s32 w0; s32 w4; } T_0048D9E8;

extern void func_L01_0048D9B0(void);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516D60_0048D9E8(s32, s32);
extern s32 func_L01_00516FD8_0048D9E8(s32, char *);
extern s32 func_0011B2E8_0048D9E8(char *, char *, ...);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_003BB148(s32);
__asm__(".extern D_L01_001D8C30, 4");
__asm__(".extern D_L01_001D8C78, 4");
__asm__(".extern D_L01_001D8C7C, 4");
__asm__(".extern D_L01_001D8C80, 4");
__asm__(".extern D_L01_001D8C84_0048D9E8, 4");
__asm__(".extern D_001D545C_0048D9E8, 4");
__asm__(".extern D_L01_001E0954_0048D9E8, 4");
extern s32 D_L01_001D8C80;
extern s32 D_001D545C_0048D9E8;
extern E_0048D9E8 *D_L01_001D8C84_0048D9E8;
extern s32 D_L01_001E0958[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001E0954, 16");
extern s32 D_L01_001E0954;
extern s32 D_L01_001E0954_0048D9E8;
__asm__(".extern D_L01_001D8C38, 4");
extern char D_L01_001D8C38[] __attribute__((section(".sdata")));
extern char D_L01_001D8CD0[];
extern char D_L01_001D8CD8[];
extern T_0048D9E8 D_L01_002E9DC0[];

static __inline__ s32 name_b_0048D9E8(s32 n) {
    return n > 0 ? D_L01_002E9DC0[n % 60].w4 : D_L01_002E9DC0[1].w4;
}

static __inline__ s32 name_a_0048D9E8(s32 n) {
    return n > 0 ? D_L01_002E9DC0[n % 60].w0 : D_L01_002E9DC0[1].w0;
}

void func_L01_0048D9E8(void) {
    s32 i = 0;
    s32 k;
    s32 idx;
    s32 show;
    s32 a;
    s32 b;
    s32 n;

    func_L01_0048D9B0();
    k = 4;
    idx = D_L01_001D8C7C;
    if (D_L01_001E0958[0] == 1 || D_L01_001E0958[0] == 3) {
        idx--;
    }
    func_L01_00516D60_0048D9E8(0x160003, 0);
    func_L01_00516D60_0048D9E8(0x160006, 0);
    func_L01_00516D60_0048D9E8(0x160007, 0);
    if (D_L01_001E0958[0] == 0) {
        func_L01_00516FD8_0048D9E8(0x160007, D_L01_001D8CD0);
    }
    switch (D_L01_001D8C30) {
    case 0:
    case 1:
        if (D_001D545C_0048D9E8 == 0) {
            show = 1;
        } else {
            n = 1;
        }
        func_L01_00516D60_0048D9E8(0x160007, 0);
        break;
    }
    for (; k > 0; k--, i++, idx++) {
        if (idx >= 0 && idx < D_L01_001D8C78) {
            func_L01_00516AA0(i + 0x160011, 1, 1);
            n = D_L01_001D8C78;
            show = 0;
            if (n == 0 || n == 1) {
            } else if (n == 2) {
                if (i == 0) show = 1;
            }
            if (n >= 3 && i < 2) show = 1;
            func_L01_00516AA0(i + 0x160016, 1, show);
            func_L01_00516FD8_0048D9E8(i + 0x160011, func_00381FF0(D_L01_001D8C84_0048D9E8[idx].w0));
            if (D_L01_001D8C84_0048D9E8[idx].w8 == 0x8D4) {
                func_L01_005170B8(i + 0x160011, 0x80808080);
            } else if (D_L01_001D8C84_0048D9E8[idx].b5 == 1) {
                func_L01_005170B8(i + 0x160011, 0x8066CCFF);
            } else {
                func_L01_005170B8(i + 0x160011, 0x666690CC);
            }
            if (i == D_L01_001D8C80 && D_L01_001E0958[0] == 0) {
                func_L01_00516FD8_0048D9E8(0x160006, func_00381FF0(D_L01_001D8C84_0048D9E8[idx].w0));
                func_L01_00516AA0(0x160006, 1, 1);
                func_L01_00516FD8_0048D9E8(0x160003, func_00381FF0(D_L01_001D8C84_0048D9E8[idx].w8));
                func_L01_00516AA0(0x160003, 1, 1);
                func_L01_00517190(0x160010, func_003BB148(D_L01_001D8C84_0048D9E8[idx].b10));
                func_L01_00516D60_0048D9E8(0x160010, 1);
                switch (D_L01_001D8C30) {
                case 0:
                case 1:
                case 2:
                    a = name_b_0048D9E8(D_L01_001D8C84_0048D9E8[idx].b10);
                    b = name_a_0048D9E8(D_L01_001D8C84_0048D9E8[idx].b10);
                    if (a >= 0 && b >= 0) {
                        char *sb = func_00381FF0(b);
                        func_0011B2E8_0048D9E8(D_L01_001D8C38, D_L01_001D8CD8, sb, func_00381FF0(a));
                    } else {
                        func_0011B2E8_0048D9E8(D_L01_001D8C38, D_L01_001D8CD0);
                    }
                    break;
                default:
                    func_0011B2E8_0048D9E8(D_L01_001D8C38, D_L01_001D8CD0);
                    break;
                }
                func_L01_00516D60_0048D9E8(0x160007, 1);
                func_L01_00516FD8_0048D9E8(0x160007, D_L01_001D8C38);
                if ((D_L01_001E0954_0048D9E8 = D_L01_001E0954 - 1) <= 0) {
                    D_L01_001E0954 = 0;
                    func_L01_00517190(0x160004, D_L01_001D8C84_0048D9E8[idx].wC);
                    func_L01_00516AA0(0x160004, 1, 1);
                }
            }
        } else {
            func_L01_00516AA0(i + 0x160011, 1, 0);
            func_L01_00516AA0(i + 0x160016, 1, 0);
        }
        if (D_L01_001D8C78 == 0 && i == 1) {
            func_L01_00516FD8_0048D9E8(0x160012, func_00381FF0(0x15C7));
            func_L01_00516AA0(0x160012, 1, 1);
            func_L01_00516AA0(0x160017, 1, 1);
        }
    }
}
/* localdecomp:end func_L01_0048D9E8 */

/* localdecomp:start func_L01_0048DE98 */
__asm__(".extern D_L01_001D8C98, 4");
__asm__(".extern D_L01_001D8C9C, 4");
__asm__(".extern D_L01_001D8CA0, 4");
__asm__(".extern D_L01_001D8CA4, 4");
__asm__(".extern D_L01_001D8CA8, 4");
__asm__(".extern D_L01_001D8CCC, 4");
__asm__(".extern D_L01_001D8CE0, 4");
extern s32 D_L01_001E0958[] __attribute__((section(".sdata")));
extern f32 D_L01_001D8C98;
extern f32 D_L01_001D8C9C;
extern f32 D_L01_001D8CA0;
extern f32 D_L01_001D8CA4;
extern f32 D_L01_001D8CA8;
extern f32 D_L01_001D8CCC;
extern f32 D_L01_001D8CE0;
extern s32 func_L01_00516470(s32, f32, f32);

void func_L01_0048DE98(void) {
    f32 y;
    s32 i;

    y = D_L01_001D8CA4 + D_L01_001D8C98 + D_L01_001D8CCC;
    if (D_L01_001E0958[0] == 1 || D_L01_001E0958[0] == 3) {
        y -= D_L01_001D8CA0;
    }
    for (i = 0; i < 4; i++) {
        func_L01_00516470(i + 0x160011, D_L01_001D8CA8, y);
        func_L01_00516470(i + 0x160016, D_L01_001D8CA8, y + D_L01_001D8CE0);
        y += D_L01_001D8C9C;
        y += D_L01_001D8C98;
    }
}
/* localdecomp:end func_L01_0048DE98 */
