#include "common.h"

typedef struct Obj_4917A0 Obj_4917A0;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj_4917A0 *);
} Vt_4917A0;
struct Obj_4917A0 {
    s32 pad;
    Vt_4917A0 *vt;
};
typedef struct S_492AF0 S_492AF0;
typedef struct { u8 pad[0xC]; void (*fC)(S_492AF0 *); } V_492AF0;
struct S_492AF0 { s32 f0; V_492AF0 *vt; };
typedef struct Obj_492EE8 Obj_492EE8;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj_492EE8 *);
} Vt_492EE8;
struct Obj_492EE8 {
    s32 pad;
    Vt_492EE8 *vt;
};

/* localdecomp:start func_L01_00494F98 */
extern s32 D_L01_001D8F90;
extern void func_L01_00517918(s32);
extern Obj_4917A0 *func_003B42F8(s32);
extern void func_003A2750(s32);
extern void func_003BB468(s32);
void func_L01_00494F98(void) {
    Obj_4917A0 *o;
    func_L01_00517918(13);
    func_L01_00517918(14);
    func_L01_00517918(20);
    o = func_003B42F8(0);
    o->vt->fn(o);
    func_003A2750(1);
    func_003BB468(D_L01_001D8F90);
}
/* localdecomp:end func_L01_00494F98 */

/* localdecomp:start func_L01_00494FF0 */
extern void func_L01_0047E4B8_00494FF0();

void func_L01_00494FF0(void) {
    func_L01_0047E4B8_00494FF0();
}
/* localdecomp:end func_L01_00494FF0 */

/* localdecomp:start func_L01_00495010 */
extern void func_L01_0047E520_00495010();

void func_L01_00495010(void) {
    func_L01_0047E520_00495010();
}
/* localdecomp:end func_L01_00495010 */

/* localdecomp:start func_L01_00495030 */
extern s32 func_L01_00495030(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0B28;
extern s32 D_L01_001E0B10[2];
extern void func_L01_004948E8();
extern void func_L01_00494F98();
extern void func_L01_00494DC8();
extern void func_L01_00494FF0_00495030(void);
extern void func_L01_00495010_00495030();
s32 func_L01_00495030(void) {
    if (D_L01_001E0B28 == 0) {
        func_003E6FA0(D_L01_001E0B10, (s32)func_L01_004948E8, (s32)func_L01_00494F98, (s32)func_L01_00494DC8, (s32)func_L01_00494FF0_00495030, (s32)func_L01_00495010_00495030);
        D_L01_001E0B28 = 1;
    }
    return (s32)D_L01_001E0B10;
}
/* localdecomp:end func_L01_00495030 */

INCLUDE_ASM("asm/levels", func_L01_00495088);

INCLUDE_ASM("asm/levels", func_L01_00495A98);

/* localdecomp:start func_L01_004962F0 */
extern void func_003A2750(s32);
extern Obj_4917A0 *func_003B42F8(s32);
extern s32 D_L01_001D902C;
extern void func_L01_00517918(s32);
extern void func_003BB468(s32);

void func_L01_004962F0(void) {
    S_492AF0 *o;
    func_L01_00517918(13);
    o = ((S_492AF0 * (*)(s32))func_003B42F8)(0);
    o->vt->fC(o);
    ((s32 (*)(s32))func_003A2750)(1);
    func_003BB468(D_L01_001D902C);
}
/* localdecomp:end func_L01_004962F0 */

/* localdecomp:start func_L01_00496338 */
extern void func_L01_0047E4B8_00496338();

void func_L01_00496338(void) {
    func_L01_0047E4B8_00496338();
}
/* localdecomp:end func_L01_00496338 */

/* localdecomp:start func_L01_00496358 */
extern void func_L01_0047E520_00496358();

void func_L01_00496358(void) {
    func_L01_0047E520_00496358();
}
/* localdecomp:end func_L01_00496358 */

/* localdecomp:start func_L01_00496378 */
extern s32 func_L01_00496378(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0B68;
extern s32 D_L01_001E0B50[2];
extern void func_L01_00495088();
extern void func_L01_004962F0();
extern void func_L01_00495A98();
extern void func_L01_00496338_00496378(void);
extern void func_L01_00496358_00496378();
s32 func_L01_00496378(void) {
    if (D_L01_001E0B68 == 0) {
        func_003E6FA0(D_L01_001E0B50, (s32)func_L01_00495088, (s32)func_L01_004962F0, (s32)func_L01_00495A98, (s32)func_L01_00496338_00496378, (s32)func_L01_00496358_00496378);
        D_L01_001E0B68 = 1;
    }
    return (s32)D_L01_001E0B50;
}
/* localdecomp:end func_L01_00496378 */

/* localdecomp:start func_L01_004963D0 */
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad4958[0x7260 - 0x4958];
    u8 f7260[1];
} S_4963D0d_004963D0;
typedef struct S_4963D0o_004963D0 S_4963D0o_004963D0;
typedef struct {
    u8 pad0[0x10];
    s32 (*fn10)(S_4963D0o_004963D0 *, s32);
} S_4963D0vt_004963D0;
struct S_4963D0o_004963D0 {
    u8 pad0[8];
    S_4963D0vt_004963D0 *vt;
    u8 pad0C[0x44];
    Obj_4917A0 *f50;
};
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
} S_513C08g_004963D0;
typedef struct {
    s32 (*f0)(void);
    s32 f4;
    s32 (*f8)(void);
} Vt_4963D0_004963D0;

extern void func_L01_00496B00_004963D0(void);
extern void func_003A5348(s32, s32, s32);
extern s32 D_001D545C_004963D0;
__asm__(".extern D_001D545C_004963D0, 16");
extern Vt_4963D0_004963D0 *func_L01_0043B548_004963D0(s32, s32);
extern u8 D_L01_001D9190_004963D0;
extern s32 D_L01_001D9198_004963D0;
extern void *func_003BB3A8(s32);
extern Obj_4917A0 *func_003B42F8(s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
extern S_4963D0d_004963D0 D_160C40;
extern S_513C08g_004963D0 D_L01_001E15E0_004963D0[];
extern S_513C08g_004963D0 *func_003E6C08(void);
extern s32 func_003E6DE8(S_513C08g_004963D0 *);
extern S_4963D0o_004963D0 *func_003E6378(s32, s32);
extern s32 D_L01_001DC1B0_004963D0;

void func_L01_004963D0(void) {
    S_513C08g_004963D0 *g;
    S_513C08g_004963D0 *x;
    S_4963D0o_004963D0 *o;
    func_L01_00496B00_004963D0();
    func_003A5348(0x12, 0, 0);
    if (D_001D545C_004963D0 == 3) {
        Vt_4963D0_004963D0 *v = func_L01_0043B548_004963D0(0x1936, 0x10);
        if (v != 0) {
            v->f8();
        }
    } else if (D_001D545C_004963D0 == 7) {
        Vt_4963D0_004963D0 *v = func_L01_0043B548_004963D0(0x1AD1, 0xC);
        if (v != 0) {
            v->f0();
        }
    }
    D_L01_001D9190_004963D0 = 0;
    D_L01_001D9198_004963D0 = ((u32)func_003BB3A8(1) + 0xF) & 0xFFFFFFF0;
    func_003B4528(func_003B42F8(0), D_L01_001D9198_004963D0, 0, D_160C40.f4954, (s32)D_160C40.f7260);
    g = D_L01_001E15E0_004963D0;
    if (g->w4 != 0) {
        x = g;
    } else {
        x = func_003E6C08();
    }
    o = func_003E6378(func_003E6DE8(x), 0x47001C);
    if (o == 0 || o->vt->fn10(o, D_L01_001DC1B0_004963D0) == 0) {
        o = 0;
    }
    o->f50 = func_003B42F8(0);
}
/* localdecomp:end func_L01_004963D0 */

/* localdecomp:start func_L01_00496518 */
typedef struct { u8 pad0[4]; s32 (*f4)(void); u8 pad8[4]; s32 (*fC)(void); } Vt_00496518;
extern u8 D_L01_001D9190;
extern s16 D_L01_001D9192;
extern f32 D_L01_001D9194;
extern f32 D_L01_001DF950[] __attribute__((section(".sdata")));
extern u8 *D_001D52FC[] __attribute__((section(".sdata")));
extern u8 *D_001D52FC_00496518;
extern s32 D_001D545C_00496518;
extern Vt_00496518 *func_L01_0043B548_00496518(s32, s32);
extern void func_L01_00497BE0(void);
extern void func_L01_0047DAD0(s32);
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32);
extern void func_L01_00516090_00496518(s32);

void func_L01_00496518(s32 a0) {

    if (D_L01_001D9190 == 1) {
        if (*(s32 *)(D_001D52FC[0] + 0x1C4) & 0x10) {
            D_L01_001D9190 = 0;
        }
    } else if (D_L01_001D9190 == 2) {
        D_L01_001D9192++;
        if ((D_L01_001D9194 * 5.0f + 2.0f) / 6.0f <= D_L01_001D9192) {
            func_L01_00497BE0();
            func_L01_00517748(func_L01_0047EBE0());
            func_L01_00516090_00496518(a0);
        }
    } else if (D_001D545C_00496518 == 3) {
        Vt_00496518 *v = func_L01_0043B548_00496518(0x1936, 0x10);
        if (v != 0) {
            if (v->f4() != 0 || (*(s32 *)(D_001D52FC_00496518 + 0x1C4) & 0x80)) {
                func_L01_0047DAD0(4);
                func_L01_00517748(func_L01_0047EBE0());
                func_L01_00516090_00496518(a0);
            } else if (v->fC() != 0) {
                func_L01_00517748(func_L01_0047EBE0());
                func_L01_00516090_00496518(a0);
            }
        }
    } else if (D_001D545C_00496518 == 7) {
        Vt_00496518 *v = func_L01_0043B548_00496518(0x1AD1, 0xC);
        if (*(s32 *)(D_001D52FC[0] + 0x1C4) & 0x80) {
            func_L01_0047DAD0(4);
            func_L01_00517748(func_L01_0047EBE0());
            func_L01_00516090_00496518(a0);
        } else if (v != 0) {
            s32 r = v->f4();
            if (r == 1) {
                func_L01_00517748(func_L01_0047EBE0());
                func_L01_00516090_00496518(a0);
            } else if (r == 3) {
                func_L01_0047DAD0(10);
                D_L01_001D9190 = 2;
                D_L01_001DF950[0] = 1.0f;
                D_L01_001D9192 = 0;
            } else if (r == 2) {
                D_L01_001D9190 = 1;
            }
        }
    }
}
/* localdecomp:end func_L01_00496518 */

/* localdecomp:start func_L01_00496710 */
extern Obj_4917A0 *func_003B42F8(s32);
extern s32 D_L01_001D9198;
extern void func_L01_00497BE0(void);
extern void func_003A5348(s32, s32, s32);
extern void func_003A2750(s32);
extern void func_003BB468(s32);
void func_L01_00496710(void) {
    Obj_492EE8 *o;
    func_L01_00497BE0();
    func_003A5348(20, 0, 0);
    o = ((Obj_492EE8 * (*)(s32))func_003B42F8)(0);
    o->vt->fn(o);
    func_003A2750(1);
    func_003BB468(D_L01_001D9198);
}
/* localdecomp:end func_L01_00496710 */

/* localdecomp:start func_L01_00496768 */
extern void func_L01_0047E4B8_00496768();

void func_L01_00496768(void) {
    func_L01_0047E4B8_00496768();
}
/* localdecomp:end func_L01_00496768 */

/* localdecomp:start func_L01_00496788 */
typedef struct { u8 pad0[8]; s32 (*fn)(void); } Vt_496788;
extern u8 D_L01_001D9190;
extern s16 D_L01_001D9192;
extern f32 D_L01_001D9194;
extern s32 D_001D545C[] __attribute__((section(".sdata")));
extern Vt_496788 *func_L01_0043B548(s32, s32);
extern void func_L01_004968C0(s32 r);
extern void func_0038AE20(s32, s32, s32, s32);
extern void func_L01_0047E520(void);

void func_L01_00496788(void) {
    if (D_L01_001D9190 == 1) {
        if (D_001D545C[0] == 7) {
            Vt_496788 *v = func_L01_0043B548(0x1AD1, 0xC);
            if (v != 0) {
                s32 r = v->fn();
                if (r != -1) {
                    func_L01_004968C0(r);
                } else {
                    D_L01_001D9190 = 0;
                }
            }
        }
    } else if (D_L01_001D9190 == 2) {
        func_0038AE20(0, 0, 0, (s32)(D_L01_001D9192 / ((D_L01_001D9194 * 5.0f + 2.0f) / 6.0f) * 255.0f));
    }
    func_L01_0047E520();
}
/* localdecomp:end func_L01_00496788 */

/* localdecomp:start func_L01_00496868 */
extern s32 func_L01_00496868(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0B88;
extern s32 D_L01_001E0B70[2];
extern void func_L01_004963D0();
extern void func_L01_00496710();
extern void func_L01_00496518();
extern void func_L01_00496768_00496868(void);
extern void func_L01_00496788();
s32 func_L01_00496868(void) {
    if (D_L01_001E0B88 == 0) {
        func_003E6FA0(D_L01_001E0B70, (s32)func_L01_004963D0, (s32)func_L01_00496710, (s32)func_L01_00496518, (s32)func_L01_00496768_00496868, (s32)func_L01_00496788);
        D_L01_001E0B88 = 1;
    }
    return (s32)D_L01_001E0B70;
}
/* localdecomp:end func_L01_00496868 */
