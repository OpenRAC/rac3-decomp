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

INCLUDE_ASM("asm/levels", func_L01_00494540);

/* localdecomp:start func_L01_00494560 */
s32 func_L01_00494560(void) {
    return 1;
}
/* localdecomp:end func_L01_00494560 */

/* localdecomp:start func_L01_00494568 */
s32 func_L01_00494568(void) {
    return 2;
}
/* localdecomp:end func_L01_00494568 */

/* localdecomp:start func_L01_00494570 */
s32 func_L01_00494570(void) {
    return 0;
}
/* localdecomp:end func_L01_00494570 */

/* localdecomp:start func_L01_00494578 */
s32 func_L01_00494578(void) {
    return 1;
}
/* localdecomp:end func_L01_00494578 */

INCLUDE_ASM("asm/levels", func_L01_00494580);

/* localdecomp:start func_L01_00494590 */
s32 func_L01_00494590(void) {
    return 1;
}
/* localdecomp:end func_L01_00494590 */

/* localdecomp:start func_L01_00494598 */
s32 func_L01_00494598(void) {
    return 0;
}
/* localdecomp:end func_L01_00494598 */

/* localdecomp:start func_L01_004945A0 */
s32 func_L01_004945A0(void) {
    return 0;
}
/* localdecomp:end func_L01_004945A0 */

/* localdecomp:start func_L01_004945A8 */
s32 func_L01_004945A8(void) {
    return 0;
}
/* localdecomp:end func_L01_004945A8 */

/* localdecomp:start func_L01_004945B0 */
s32 func_L01_004945B0(void) {
    return 1;
}
/* localdecomp:end func_L01_004945B0 */

INCLUDE_ASM("asm/levels", func_L01_004945B8);

INCLUDE_ASM("asm/levels", func_L01_00494748);

INCLUDE_ASM("asm/levels", func_L01_004948E8);

INCLUDE_ASM("asm/levels", func_L01_00494DC8);

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

INCLUDE_ASM("asm/levels", func_L01_004963D0);

INCLUDE_ASM("asm/levels", func_L01_00496518);

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

INCLUDE_ASM("asm/levels", func_L01_00496788);

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

INCLUDE_ASM("asm/levels", func_L01_004968C0);

INCLUDE_ASM("asm/levels", func_L01_00496B00);

INCLUDE_ASM("asm/levels", func_L01_00496B60);

INCLUDE_ASM("asm/levels", func_L01_00496C88);

/* localdecomp:start func_L01_00496D58 */
extern void func_L01_004974F0(s32 a, s32 b);
extern void func_L01_00496E08(s32 a, s32 b);
extern f32 D_L01_001D91D8;
extern void func_L01_00518D40_00496D58(s32);
extern void func_003E8630(s32, s32);
extern void func_L01_00497AC8(void *, s32, s32, s32, s32, s32, f32, f32);

void func_L01_00496D58(s32 a0, s32 a1) {
    func_L01_00518D40_00496D58(0x47000C);
    func_L01_00497AC8(((void (*)(void))func_L01_00496E08), 0x47000C, a1, 0, 1, 0, D_L01_001D91D8, 1.0f);
    func_003E8630(a0, 0x47000C);
    func_L01_00497AC8(((void (*)(void))func_L01_004974F0), a0, a1, 2, 1, 0, D_L01_001D91D8, 1.0f);
}
/* localdecomp:end func_L01_00496D58 */

/* localdecomp:start func_L01_00496E08 */
extern void func_L01_00497180(s32 a, s32 b);
extern f32 D_L01_001D91DC;
extern void func_L01_00496E98(void);
extern void func_L01_00497AC8(void *, s32, s32, s32, s32, s32, f32, f32);

void func_L01_00496E08(s32 a, s32 b) {
    func_L01_00497AC8(func_L01_00496E98, a, b, 1, 0, 1, 1.0f, D_L01_001D91DC);
    func_L01_00497AC8(((void (*)(void))func_L01_00497180), a, b, 1, 2, 0, 1.0f, D_L01_001D91DC);
}
/* localdecomp:end func_L01_00496E08 */

INCLUDE_ASM("asm/levels", func_L01_00496E98);

INCLUDE_ASM("asm/levels", func_L01_00496F78);

INCLUDE_ASM("asm/levels", func_L01_00497090);

/* localdecomp:start func_L01_00497180 */
extern f32 D_L01_001D91F8;
extern void func_L01_00497210(void);
extern void func_L01_004973B0(void);
extern void func_L01_00497AC8(void *, s32, s32, s32, s32, s32, f32, f32);

void func_L01_00497180(s32 a, s32 b) {
    func_L01_00497AC8(func_L01_00497210, a, b, 0, 1, 1, D_L01_001D91F8, 1.0f);
    func_L01_00497AC8(func_L01_004973B0, a, b, 2, 1, 1, D_L01_001D91F8, 1.0f);
}
/* localdecomp:end func_L01_00497180 */

INCLUDE_ASM("asm/levels", func_L01_00497210);

INCLUDE_ASM("asm/levels", func_L01_004973B0);

/* localdecomp:start func_L01_004974F0 */
extern f32 D_L01_001D920C;
extern void func_L01_00497580(void);
extern void func_L01_00497680(void);
extern void func_L01_00497AC8(void *, s32, s32, s32, s32, s32, f32, f32);

void func_L01_004974F0(s32 a, s32 b) {
    func_L01_00497AC8(func_L01_00497580, a, b, 1, 0, 1, 1.0f, D_L01_001D920C);
    func_L01_00497AC8(func_L01_00497680, a, b, 1, 2, 1, 1.0f, D_L01_001D920C);
}
/* localdecomp:end func_L01_004974F0 */

INCLUDE_ASM("asm/levels", func_L01_00497580);

INCLUDE_ASM("asm/levels", func_L01_00497680);

INCLUDE_ASM("asm/levels", func_L01_004978A8);

INCLUDE_ASM("asm/levels", func_L01_00497AC8);

/* localdecomp:start func_L01_00497BE0 */
extern void func_L01_00517918(int);

void func_L01_00497BE0(void)
{
    func_L01_00517918(13);
    func_L01_00517918(14);
}
/* localdecomp:end func_L01_00497BE0 */

/* localdecomp:start func_L01_00497C08 */
f32 func_L01_00497C08(s32 a0, f32 a, f32 b) {
    if (a0 == 2) {
        return a * (1.0f - b);
    }
    return a * b;
}
/* localdecomp:end func_L01_00497C08 */

/* localdecomp:start func_L01_00497C38 */
f32 func_L01_00497C38(s32 a0, f32 a, f32 b, f32 c) {
    if (a0 == 0) {
        return a - b * 0.5f + c * 0.5f;
    }
    if (a0 == 2) {
        return a + b * 0.5f - c * 0.5f;
    }
    return a;
}
/* localdecomp:end func_L01_00497C38 */
