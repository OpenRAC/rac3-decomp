#include "common.h"

/* NTSC-U counterpart of func_L02_004B8000 (src/levels/02_florana/L02_004B8000.c) */
#include "vu0.h"

/* localdecomp:start func_L02_004B3DE0 */
typedef struct {
    u8 pad0[0x80];
    vu0_v4 v80;
    u8 v90[8];
    f32 f98;
    u8 pad9C[0x74];
    vu0_v4 v110;
    u8 pad120[0x58];
    f32 f178;
    u8 pad17C[0x18C];
    f32 f308;
    u8 pad30C[0x2C];
    f32 f338;
    f32 f33C;
    u8 pad340[0x1C0];
    vu0_v4 v500;
    u8 pad510[0x518];
    s32 fA28;
    u8 padA2C[0x32];
    s16 hA5E;
    u8 padA60[0x64];
    s32 fAC4;
    u8 padAC8[0x760];
    s32 f1228;
    u8 pad122C[0x24A];
    u8 b1476;
    u8 b1477;
    u8 b1478;
    u8 pad1479[0x4];
    u8 b147D;
    u8 b147E;
    u8 pad147F[0xF51];
    s16 h23D0;
    s16 h23D2;
    u8 pad23D4[0x1EC];
    u8 * f25C0;
    s32 f25C4;
    u8 pad25C8[0x1C];
    u8 b25E4;
    u8 b25E5;
    u8 pad25E6[0x1];
    u8 b25E7;
    u8 b25E8;
    u8 pad25E9[0x7];
    u8 b25F0;
    u8 pad25F1[0x21B];
    s32 f280C;
} H_4B8000;
extern H_4B8000 D_001A4BE0;
__asm__(".extern D_001A4BE0, 16");
typedef struct { u8 p0[0x50]; u8 *f50; u8 p54[0x24C]; s16 h2A0; } X_4B8000;
extern X_4B8000 D_L02_001E1380;
__asm__(".extern D_L02_001E1380, 16");
extern s32 D_L02_001D673C_004B3DE0;
extern s32 D_L02_001D6694_004B3DE0;
extern s32 D_001D545C;
extern u8 D_00142CAB[];
typedef int u128_t __attribute__((mode(TI)));
extern void func_L02_004B31E0(void);
extern void func_L01_004DE160(s32);
extern void func_L01_004DD928(void);
extern void func_L01_0050BF58(void);
extern void func_L01_004EA708(void);
extern void func_L02_004B97B8(void);
extern void func_L02_004B9D90(void *, void *, void *);
extern void func_L01_004E5300(void);
extern s32 func_L01_0045D358(s32, s32, s32, s32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern f32 func_00388800(void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);
extern s32 func_L01_004FC0A0(void);
extern void func_L01_004FB8C8(void);
extern void func_L01_004FBB58(void);
extern void func_L01_004FBE48(void);
extern void func_L02_004D5DE0(void);
extern void func_L01_0050C8E8(s32);
extern void func_L01_0050CAF8(void);
extern void func_L01_0050E9D0(void *);
extern void func_L01_004E5688(void);
extern void func_L01_004F1208(void);
extern void func_L01_004E3570(void);
extern void func_L01_004E26F8(void);
extern void func_L01_004E2A30(void);
extern void func_L01_004E2F50(void);
extern void func_L01_00512478(void);
extern void func_L01_004DC908(void);
extern void func_L01_004DCC10(void);
extern void func_L01_004EEC00(void);
extern void func_L01_004DC790(void);
extern void func_L01_004E0800(void);
extern void func_L01_004E1518(s32);
extern void func_L01_004E9558(void);
extern void func_L01_004E7118(void);
extern s32 func_L01_0050FF18(void);
extern void func_L01_004DF380(void);
extern void func_L01_004DF108(void);
extern void func_L01_0050F920(void);
extern void func_L01_004DD508(void);
extern void func_L01_0050EE90(void);
extern s32 func_L01_004DE900(void);
extern void func_L01_0042D288(void *);
extern void func_L01_004405F4(void *);
extern void func_L02_004B4898(void);
extern void func_L01_004E0B00(void);

void func_L02_004B3DE0(void) {
    s32 flag;
    s32 near;
    vu0_v4 v, u, w;

    D_001A4BE0.h23D2 = 0;
    D_001A4BE0.h23D0 = 0;
    if (D_001A4BE0.b25E4 != 0) {
        func_L02_004B31E0();
        func_L01_004DE160(0);
        if (D_001A4BE0.b25E4 == 5) func_L01_004DD928();
        return;
    }
    flag = 0;
    func_L01_0050BF58();
    func_L01_004EA708();
    func_L02_004B97B8();
    func_L02_004B9D90(&D_001A4BE0.v80, D_001A4BE0.v90, &D_001A4BE0.v500);
    func_L01_004E5300();
    if (D_001A4BE0.f338 == 0.0f || 2.0f < D_001A4BE0.f308 - D_001A4BE0.f338 || D_001A4BE0.b147D ||
        D_001A4BE0.b1476 || D_001A4BE0.b147E || D_001A4BE0.b1477 || D_001A4BE0.b1478) flag = 1;
    if (func_L01_0045D358(0x20, 0x14, 0, 0) != 0) {
        if (0.7f < D_001A4BE0.f33C && 0.083333336f < D_001A4BE0.f178) {
            func_003886E8(&v, &D_001A4BE0.v110, 20.0f);
            v.z = 0.0f;
            vec_add_ba(&v, &v, &D_001A4BE0.v80);
            u = v;
            w = v;
            u.z += 1.0f;
            w.z -= 1.5f;
            if (func_003CE740(&u, &w, 2, 0, 0) == 0) flag = 1;
        }
    }
    if (D_L02_001D673C_004B3DE0 != 0) flag = 0;
    if (func_L01_0045D358(0x20, 5, 0, 0) != 0) {
        if (D_001A4BE0.f1228 == 0xB) goto force;
        near = D_001D545C == 5;
        if (D_001D545C == 0x11) {
            *(u128_t *)&v = 0;
            v.x = 424.5f;
            v.y = 455.7f;
            v.z = 120.27f;
            if (func_00388800(&D_001A4BE0.v80, &v) < 11.5f) {
                if (func_00389468(D_001A4BE0.f98, func_00388A28(v.x - D_001A4BE0.v80.x, v.y - D_001A4BE0.v80.y)) < 30.0f) near = 1;
            }
        }
        if (near) {
            func_L01_004FC0A0();
            if (D_001A4BE0.fAC4 != 0) flag = 1;
        }
    }
    if (D_001A4BE0.f1228 == 0xB || flag != 0) {
force:
        func_L01_004FB8C8();
        func_L01_004FBB58();
        func_L01_004FBE48();
        func_L01_004FC0A0();
        if ((D_001A4BE0.fA28 != 0 || D_001A4BE0.hA5E != 0 || D_001A4BE0.fAC4 != 0) && flag != 0 &&
            D_001A4BE0.b25E8 == 0 && D_001A4BE0.b25F0 == 0 && D_00142CAB[0] != 0) {
            D_001A4BE0.b25E7 = 1;
        }
    }
    func_L02_004D5DE0();
    if (D_L02_001D6694_004B3DE0 == 2 || D_L02_001D6694_004B3DE0 == 6) {
        if (D_001A4BE0.b25E5 != 0) func_L01_0050C8E8(0);
        else func_L01_0050CAF8();
        func_L01_004DE160(0);
        return;
    }
    func_L01_0050E9D0(D_001A4BE0.f25C0);
    func_L01_004E5688();
    if (D_001A4BE0.b25E4 != 0) {
        func_L01_004DE160(0);
        return;
    }
    func_L01_004F1208();
    func_L01_004E3570();
    func_L01_004E26F8();
    func_L01_004E2A30();
    func_L01_004E2F50();
    func_L01_00512478();
    func_L01_004DC908();
    func_L01_004DCC10();
    func_L01_004EEC00();
    func_L01_004DC790();
    func_L01_004E0800();
    func_L01_004E1518(0);
    func_L01_004E9558();
    func_L01_004E7118();
    if (D_001A4BE0.b25E5 != 0 || func_L01_0050FF18() == 2) {
        if (func_L01_0050FF18() == 2 &&
            (D_L02_001E1380.h2A0 != 0 || (D_L02_001E1380.f50 != 0 && *(s16 *)(D_L02_001E1380.f50 + 0x86) == 0))) {
            func_L01_0050CAF8();
        } else {
            func_L01_0050C8E8(0);
        }
    } else {
        func_L01_0050CAF8();
    }
    func_L01_004DF380();
    func_L01_004DF108();
    func_L01_004DD928();
    func_L01_0050F920();
    func_L01_004DD508();
    func_L01_0050EE90();
    if (D_001A4BE0.f25C4 != 0x31 || func_L01_004DE900() != 0) func_L01_0042D288(&D_001A4BE0.v80);
    func_L01_004405F4(D_001A4BE0.f25C0);
    func_L02_004B4898();
    func_L01_004E0B00();
    if (func_L01_0050FF18() != 0 && D_001A4BE0.f280C != 4 && D_001A4BE0.f280C != 0x51) D_001A4BE0.f280C = 0x20;
    func_L01_004DE160(0);
}
/* localdecomp:end func_L02_004B3DE0 */
