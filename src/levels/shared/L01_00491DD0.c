#include "common.h"

typedef struct {
    s32 pad[3];
    s32 val;
} S_48DA70;
typedef struct { u8 b[16]; } V16_48DCD8;
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6EC0 - 0x4958];
    u8 fX[1];
} S_func_0048E5D8;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} E_002EB338;
typedef struct {
    s32 w0;
    u8 b4;
    u8 pad5[3];
    void (*fn)(void);
    s32 wC;
} S_48F880e;
typedef struct {
    u8 pad0[0x1C4];
    s32 w1C4;
} S_48F880;

/* declared by functions of L01_00491A30.c, which this file was cut from */
extern void func_L01_00491E28(void);

/* localdecomp:start func_L01_00491DD0 */
extern S_func_0048E5D8 D_00160C40[];
extern void *D_L01_001D8E18;
extern void *D_L01_001D8E1C;
extern void *func_003BB3A8(s32);
extern void *func_003B42F8(s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
void func_L01_00491DD0(void) {
    D_L01_001D8E18 = func_003BB3A8(0);
    D_L01_001D8E1C = func_003BB3A8(0);
    func_003B4528(func_003B42F8(0), (s32)D_L01_001D8E18, (s32)D_L01_001D8E1C, D_00160C40->f4954, (s32)D_00160C40->fX);
}
/* localdecomp:end func_L01_00491DD0 */

/* localdecomp:start func_L01_00491E28 */
extern void *D_L01_001D8E1C;
extern void *D_L01_001D8E18;
extern void *func_003B42F8(s32);
extern void func_003BB468(s32);
void func_L01_00491E28(void) {
    O_49A988 *o = ((O_49A988 * (*)(s32))func_003B42F8)(0);
    o->vt->fn(o);
    func_003BB468((*(s32 *)&D_L01_001D8E18));
    func_003BB468((*(s32 *)&D_L01_001D8E1C));
}
/* localdecomp:end func_L01_00491E28 */

/* localdecomp:start func_L01_00491E68 */
extern s32 D_L01_001D8DE8[2];
extern S_48F880e D_L01_002EB2E8_00491E68[];
extern S_48F880 *D_L01_001D52FC_00491E68;
__asm__(".extern D_L01_001D52FC_00491E68, 16");
extern u8 D_L01_001D672C;
extern s32 func_L01_00517688(void);
extern void func_003A5348(s32, s32, s32);
extern s32 func_L01_0047FE28(void);
extern s32 func_L01_0047EBE0(void);
extern s32 func_L01_004914D0(s32);
extern s32 func_L01_0048D8D8(void);
extern s32 func_L01_004A1128(void);
extern void func_L01_00517748(s32);
extern void func_L01_00516090_00491E68(s32);

void func_L01_00491E68(s32 a0, s32 flags) {
    S_48F880e *t;
    s32 *d;

    if (flags & 0x40) {
        d = D_L01_001D8DE8;
        t = D_L01_002EB2E8_00491E68;
        if (t[d[func_L01_00517688()]].b4 != 0 && D_L01_002EB2E8_00491E68[d[func_L01_00517688()]].fn != 0) {
            t[d[func_L01_00517688()]].fn();
        } else {
            func_003A5348(5, 0, 0);
        }
    }
    if (flags & 0x10) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_0047FE28());
        func_L01_00516090_00491E68(func_L01_004914D0(0));
    } else if (flags & 0x900) {
        if (D_L01_001D672C == 0) {
            func_003A5348(4, 0, 0);
            func_L01_00517748(func_L01_0047EBE0());
            func_L01_00516090_00491E68(func_L01_004914D0(0));
        }
    } else if (D_L01_001D52FC_00491E68->w1C4 & 1) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_0048D8D8());
        func_L01_00516090_00491E68(a0);
    } else if (D_L01_001D52FC_00491E68->w1C4 & 2) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_004A1128());
        func_L01_00516090_00491E68(a0);
    }
}
/* localdecomp:end func_L01_00491E68 */

/* localdecomp:start func_L01_00492028 */

extern s32 D_L01_001D8DE8[2];
extern s32 D_L01_001D8DF8[2];
extern s32 D_L01_001D8E38;
extern E_002EB338 D_L01_002EB2E8[];
extern s32 func_L01_00517688(void);
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C58(s32);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_L01_00516D60(s32, s32);

void func_L01_00492028(void)
{
    s32 i;

    D_L01_001D8DE8[func_L01_00517688()] = func_003B9C58(func_003B9BD0(0));
    i = func_L01_00517688();
    if (D_L01_001D8DF8[i] != D_L01_001D8DE8[func_L01_00517688()]) {
        D_L01_001D8E38 = 30;
    }
    if (D_L01_001D8E38 != 0) {
        if (--D_L01_001D8E38 == 0) {
            func_L01_00517190(0x1C0003, D_L01_002EB2E8[D_L01_001D8DE8[func_L01_00517688()]].unkC);
            func_L01_00516D60(0x1C0003, 1);
        }
    }
    D_L01_001D8DF8[func_L01_00517688()] = D_L01_001D8DE8[func_L01_00517688()];
}
/* localdecomp:end func_L01_00492028 */
