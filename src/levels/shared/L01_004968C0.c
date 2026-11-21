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

/* declared by functions of L01_00494F98.c, which this file was cut from */
extern void func_L01_004968C0(s32 r);
extern void func_0038AE20(s32, s32, s32, s32);

/* localdecomp:start func_L01_004968C0 */
/* following rac3-decomp's func_L07_003C1EB8 */
extern void func_0038AE20(s32, s32, s32, s32);
extern char *func_00381FF0(s32);
extern s32 func_0011B2E8(char *, char *, ...);
extern void func_003910C0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_0038FA18(u16 *, long, char *, s32, unsigned long, f32, f32);
extern void func_0038C3B0(s32, s32, s32, s32, s32, s32);
extern void func_L01_00436020(s32, s32, f32, f32, f32, f32);
extern char D_L01_001D91A0[];
extern f32 D_L01_001E11A4;
__asm__(".extern D_L01_001E11A4, 16");
extern s32 D_L01_001E11A0_004968C0;
__asm__(".extern D_L01_001E11A0_004968C0, 16");
extern s32 D_001D4BC8;
__asm__(".extern D_001D4BC8, 16");

static __inline__ s32 scale_004968C0(f32 v) {
    f32 z0 = 0.0f, z1 = 0.0f;
    return (s32)(v * D_L01_001E11A4 + 0.5f + (D_L01_001E11A0_004968C0 == 1 ? z0 : z1));
}

void func_L01_004968C0(s32 r) {
    char buf[0x400];
    u16 m[16];
    s32 h, w;

    func_0038AE20(0, 0, 0, 0x60);
    func_0011B2E8(buf, D_L01_001D91A0, func_00381FF0(r), func_00381FF0(0xCD5));
    m[12] = 2;
    m[13] = 2;
    func_003910C0((s16 *)m, scale_004968C0(256.0f), scale_004968C0(384.0f), D_001D4BC8 - 0x90, D_001D4BC8 + 0x90, D_001D4BC8, 0x140, 0x10, 0x27);
    func_0038FA18(m, 0x8066CCFFL, buf, -1, 0x80000000UL, 1.0f, 1.0f);
    w = ((s16)m[6] >> 1) + 8;
    h = ((s16)m[7] >> 1) + 8;
    func_0038C3B0(((s16)m[5]) - h, ((s16)m[5]) + h, ((s16)m[4]) - w, ((s16)m[4]) + w, 0x33, 0x331465B7);
    func_L01_00436020(0x33, 0x332299DE, (s16)m[5] - h, (s16)m[5] + h, (s16)m[4] - w, (s16)m[4] + w);
    m[9] &= 0xFFFB;
    func_0038FA18(m, 0x8066CCFFL, buf, -1, 0x80000000UL, 1.0f, 1.0f);
}
/* localdecomp:end func_L01_004968C0 */
