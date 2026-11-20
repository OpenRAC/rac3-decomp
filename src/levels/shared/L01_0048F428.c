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
extern char *func_00381FF0(s32 id);
extern void func_L01_00516FD8(s32 id, char *s);
extern void func_L01_00517190(s32 id, s32 v);
extern void func_L01_00516D60(s32 id, s32 v);
extern s32 func_003A5348(s32, s32, s32);
extern void func_003BB468(s32);
extern O_00489FA8 *func_003B42F8(s32);
extern void func_003A2750(s32);
extern void func_L01_00517918(s32);
extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void func_0039EF28(void);
extern s32 func_L01_0048FB98(void);

/* localdecomp:start func_L01_0048F428 */
extern s32 D_L01_001D8D08;
extern s32 D_L01_001F43B0[];
extern s32 D_001D545C[] __attribute__((section(".sdata")));
extern void func_L01_00517918(s32);
extern void func_003A2750(s32);
extern void func_003BB468(s32);

void func_L01_0048F428(void)
{
    Obj_0048B530 *obj;

    func_L01_00517918(16);
    func_L01_00517918(17);
    obj = ((Obj_0048B530 * (*)(s32))func_003B42F8)(0);
    obj->vtbl->fn(obj);
    func_003A2750(1);
    func_003BB468(D_L01_001D8D08);
    D_L01_001D8D08 = 0;
    D_L01_001F43B0[0] = D_001D545C[0];
}
/* localdecomp:end func_L01_0048F428 */

/* localdecomp:start func_L01_0048F490 */
extern void func_L01_0047E4B8_0048F490(void);
extern void func_003A9440(s32, s32);
extern void func_L01_0042EBF0(s32);
extern void func_L01_0047E520(void);
void func_L01_0048F490(void) {
    func_L01_0047E4B8_0048F490();
    func_003A9440(66, 68);
    func_003A9440(71, 11);
    func_L01_0042EBF0(1);
    func_L01_0047E520();
}
/* localdecomp:end func_L01_0048F490 */

/* localdecomp:start func_L01_0048F4D8 */
void func_L01_0048F4D8(void) {

}
/* localdecomp:end func_L01_0048F4D8 */

INCLUDE_ASM("asm/levels", func_L01_0048F4E0);

/* localdecomp:start func_L01_0048FB98 */
extern s32 func_L01_0048FB98(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0978;
extern s32 D_L01_001E0960[2];
extern void func_L01_0048EEC8();
extern void func_L01_0048F428();
extern void func_L01_0048F390();
extern void func_L01_0048F490(void);
extern void func_L01_0048F4D8_0048FB98();
s32 func_L01_0048FB98(void) {
    if (D_L01_001E0978 == 0) {
        func_003E6FA0(D_L01_001E0960, (s32)func_L01_0048EEC8, (s32)func_L01_0048F428, (s32)func_L01_0048F390, (s32)func_L01_0048F490, (s32)func_L01_0048F4D8_0048FB98);
        D_L01_001E0978 = 1;
    }
    return (s32)D_L01_001E0960;
}
/* localdecomp:end func_L01_0048FB98 */
