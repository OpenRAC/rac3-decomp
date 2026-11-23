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

/* declared by functions of L01_0048B738.c, which this file was cut from */
extern u8 *D_001D52FC[] __attribute__((section(".sdata")));
extern s32 func_003A5348(s32, s32, s32);
extern void *func_L01_0047EBE0(void);
extern void *func_L01_0047FE28(void);
extern void func_L01_00517748(void *);
extern s32 func_L01_0047DAB0(void);
extern void func_L01_0047DAC8(void);
extern void func_003BB468(s32);
extern O_00489FA8 *func_003B42F8(s32);
extern void func_003A2750(s32);
extern void func_L01_00517918(s32);
extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001D8C30;
extern s32 D_L01_001D8C84;
extern s32 D_L01_001E0958[] __attribute__((section(".sdata")));
extern s32 func_L01_00516470(s32, f32, f32);

/* localdecomp:start func_L01_0048EB88 */
void func_L01_0048EB88(void) {

}
/* localdecomp:end func_L01_0048EB88 */

/* localdecomp:start func_L01_0048EB90 */
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    u8 b10;
    u8 pad11[3];
} E_0048EB90;

__asm__(".extern D_L01_001D8C80, 4");
__asm__(".extern D_L01_001D8C84, 4");
__asm__(".extern D_L01_001D8CB0, 4");
__asm__(".extern D_L01_001D8CB8, 4");
__asm__(".extern D_L01_001D8C30, 4");
__asm__(".extern D_001D545C_0048EB90, 4");
__asm__(".extern D_001D52FC_0048EB90, 4");
extern void func_0039EF28(void);
extern void func_L01_0048DF60(void);
extern void func_L01_0048E028(void);
extern void func_L01_0048DE98(void);
extern void func_L01_0048D9E8(void);
extern void func_L01_0048BF30(void);
extern void func_L01_0048BF28(s32);
extern s32 D_L01_001D8C80;
extern s32 D_L01_001D8C84;
extern f32 D_L01_001D8CB0;
extern f32 D_L01_001D8CB8;
extern f32 D_L01_001D8CB0_0048EB90[] __attribute__((section(".sdata")));
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern u8 *D_001D52FC[] __attribute__((section(".sdata")));
extern u8 *D_001D52FC_0048EB90;
extern s32 D_L01_001D8C30;
extern s32 D_001D545C_0048EB90;
extern s32 func_003A5348(s32, s32, s32);
extern s32 func_L01_0047DB60(void);
extern s32 func_L01_0048FB98(void);
extern void *func_L01_0047FE28(void);
extern void *func_L01_0048A028(void);
extern void *func_L01_00486980(void);
extern void *func_L01_0047EBE0(void);
extern void func_L01_00517748(void *);
extern void func_L01_00516090_0048EB90(void *);
extern void func_003BB0E8(s32);
extern void func_003BB5D0(void);
extern s32 D_L01_001E0958[] __attribute__((section(".sdata")));
extern void func_L01_0048EA10(void);
extern void func_L01_0048EB88_0048EB90(void);
extern s32 func_L01_0047DAB0(void);
extern void func_L01_0047DAC8(void);
extern u8 D_L01_001D672C_0048EB90[] __attribute__((section(".sdata")));

void func_L01_0048EB90(void *a0) {
    E_0048EB90 *e;
    u32 pad;

    func_0039EF28();
    func_L01_0048DF60();
    func_L01_0048E028();
    func_L01_0048DE98();
    func_L01_0048D9E8();
    e = (E_0048EB90 *)(D_L01_001D8C80 * 20 + D_L01_001D8C84);
    if (e->w8 == 0x8D4) {
        func_L01_0048BF30();
    } else {
        func_L01_0048BF28(e->b10);
    }
    func_L01_00516470(0x160000, D_L01_001D8CB0, D_L01_001D8CB0_0048EB90[1]);
    func_L01_00517538(0x160000, D_L01_001D8CB8, D_L01_001D8CB0_0048EB90[3]);
    pad = *(u32 *)(D_001D52FC[0] + 0x1C4);
    if (pad & 0x10) {
        func_003A5348(4, 0, 0);
        if (D_L01_001D8C30 == 0) {
            if (func_L01_0047DB60() == 2) {
                func_L01_00517748((void *)func_L01_0048FB98());
            } else {
                func_L01_00517748(func_L01_0047FE28());
            }
        } else {
            func_L01_00517748(func_L01_0048A028());
        }
        func_L01_00516090_0048EB90(a0);
    } else if (pad & 0xD00) {
        if (D_L01_001D8C30 != 0) {
            func_003BB0E8(D_001D545C_0048EB90);
        }
        func_L01_00517748(func_L01_0047EBE0());
        func_L01_00516090_0048EB90(a0);
    } else if (D_L01_001D8C30 == 0 && func_L01_0047DB60() != 2) {
        if (*(u32 *)(D_001D52FC_0048EB90 + 0x1C4) & 2) {
            func_003A5348(4, 0, 0);
            func_L01_00517748(func_L01_00486980());
            func_L01_00516090_0048EB90(a0);
        }
    }
    func_003BB5D0();
    if (D_L01_001E0958[0] == 0) {
        func_L01_0048EA10();
    }
    func_L01_0048EB88_0048EB90();
    if (func_L01_0047DAB0() != 0) {
        func_L01_0047DAC8();
        func_L01_00516090_0048EB90(a0);
        if (D_L01_001D672C_0048EB90[0] == 0) {
            func_L01_00517748(func_L01_0047EBE0());
        }
    }
}
/* localdecomp:end func_L01_0048EB90 */

/* localdecomp:start func_L01_0048EDA8 */
extern O_00489FA8 *func_003B42F8(s32);

extern s32 D_L01_001D8C88;
extern s32 D_L01_001D8C8C;
extern s32 D_L01_001D8C90;
extern void func_L01_00517918(s32);
extern void func_003A2750(s32);
extern void func_003BB468(s32);

void func_L01_0048EDA8(void)
{
    Obj_0048B530 *obj;

    func_L01_00517918(16);
    func_L01_00517918(17);
    func_L01_00517918(18);
    obj = ((Obj_0048B530 * (*)(s32))func_003B42F8)(0);
    obj->vtbl->fn(obj);
    obj = ((Obj_0048B530 * (*)(s32))func_003B42F8)(1);
    obj->vtbl->fn(obj);
    func_003A2750(1);
    func_003BB468(D_L01_001D8C88);
    func_003BB468(D_L01_001D8C8C);
    func_003BB468(D_L01_001D8C90);
}
/* localdecomp:end func_L01_0048EDA8 */

/* localdecomp:start func_L01_0048EE30 */
extern void func_L01_0047E4B8_0048EE30();

void func_L01_0048EE30(void) {
    func_L01_0047E4B8_0048EE30();
}
/* localdecomp:end func_L01_0048EE30 */

/* localdecomp:start func_L01_0048EE50 */
extern void func_L01_0047E520_0048EE50();

void func_L01_0048EE50(void) {
    func_L01_0047E520_0048EE50();
}
/* localdecomp:end func_L01_0048EE50 */

/* localdecomp:start func_L01_0048EE70 */
extern s32 func_L01_0048EE70(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0950;
extern s32 D_L01_001E0938[2];
extern void func_L01_0048E0C0();
extern void func_L01_0048EDA8();
extern void func_L01_0048EB90();
extern void func_L01_0048EE30_0048EE70(void);
extern void func_L01_0048EE50_0048EE70();
s32 func_L01_0048EE70(void) {
    if (D_L01_001E0950 == 0) {
        func_003E6FA0(D_L01_001E0938, (s32)func_L01_0048E0C0, (s32)func_L01_0048EDA8, (s32)func_L01_0048EB90, (s32)func_L01_0048EE30_0048EE70, (s32)func_L01_0048EE50_0048EE70);
        D_L01_001E0950 = 1;
    }
    return (s32)D_L01_001E0938;
}
/* localdecomp:end func_L01_0048EE70 */
