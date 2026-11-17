#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L02_004B8000 */
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
extern X_4B8000 D_L02_001E1300;
__asm__(".extern D_L02_001E1300, 16");
extern s32 D_L02_001D673C;
extern s32 D_L02_001D6694;
extern s32 D_001D545C;
extern u8 D_00142CAB[];
typedef int u128_t __attribute__((mode(TI)));
extern void func_L02_004B7370(void);
extern void func_L01_004E1F00(s32);
extern void func_L01_004E1638(void);
extern void func_L01_0050FF00(void);
extern void func_L01_004EE4E0(void);
extern void func_L02_004BDA00(void);
extern void func_L02_004BDFD8(void *, void *, void *);
extern void func_L01_004E90C8(void);
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern s32 func_L01_004FFF58(void);
extern void func_L01_004FF780(void);
extern void func_L01_004FFA10(void);
extern void func_L01_004FFD00(void);
extern void func_L02_004DA1D0(void);
extern void func_L01_005108C0(s32);
extern void func_L01_00510AD0(void);
extern void func_L01_005129A8(void *);
extern void func_L01_004E9450(void);
extern void func_L01_004F5010(void);
extern void func_L01_004E7338(void);
extern void func_L01_004E64C0(void);
extern void func_L01_004E67F8(void);
extern void func_L01_004E6D18(void);
extern void func_L01_00516468(void);
extern void func_L01_004E0618(void);
extern void func_L01_004E0920(void);
extern void func_L01_004F2A08(void);
extern void func_L01_004E04A0(void);
extern void func_L01_004E45C8(void);
extern void func_L01_004E52E0(s32);
extern void func_L01_004ED328(void);
extern void func_L01_004EAEE8(void);
extern s32 func_L01_00513EF0(void);
extern void func_L01_004E3148(void);
extern void func_L01_004E2ED0(void);
extern void func_L01_005138F8(void);
extern void func_L01_004E1218(void);
extern void func_L01_00512E68(void);
extern s32 func_L01_004E26A0(void);
extern void func_L01_00430118(void *);
extern void func_L01_004436F4(void *);
extern void func_L02_004B8AE0(void);
extern void func_L01_004E48C8(void);

void func_L02_004B8000(void) {
    s32 flag;
    s32 near;
    vu0_v4 v, u, w;

    D_001A4BE0.h23D2 = 0;
    D_001A4BE0.h23D0 = 0;
    if (D_001A4BE0.b25E4 != 0) {
        func_L02_004B7370();
        func_L01_004E1F00(0);
        if (D_001A4BE0.b25E4 == 5) func_L01_004E1638();
        return;
    }
    flag = 0;
    func_L01_0050FF00();
    func_L01_004EE4E0();
    func_L02_004BDA00();
    func_L02_004BDFD8(&D_001A4BE0.v80, D_001A4BE0.v90, &D_001A4BE0.v500);
    func_L01_004E90C8();
    if (D_001A4BE0.f338 == 0.0f || 2.0f < D_001A4BE0.f308 - D_001A4BE0.f338 || D_001A4BE0.b147D ||
        D_001A4BE0.b1476 || D_001A4BE0.b147E || D_001A4BE0.b1477 || D_001A4BE0.b1478) flag = 1;
    if (func_L01_004606E8(0x20, 0x11, 0, 0) != 0) {
        if (0.7f < D_001A4BE0.f33C && 0.10000001f < D_001A4BE0.f178) {
            func_0038CE20(&v, &D_001A4BE0.v110, 20.0f);
            v.z = 0.0f;
            vec_add_ba(&v, &v, &D_001A4BE0.v80);
            u = v;
            w = v;
            u.z += 1.0f;
            w.z -= 1.5f;
            if (func_003D3CB0(&u, &w, 2, 0, 0) == 0) flag = 1;
        }
    }
    if (D_L02_001D673C != 0) flag = 0;
    if (func_L01_004606E8(0x20, 4, 0, 0) != 0) {
        if (D_001A4BE0.f1228 == 0xB) goto force;
        near = D_001D545C == 5;
        if (D_001D545C == 0x11) {
            *(u128_t *)&v = 0;
            v.x = 424.5f;
            v.y = 455.7f;
            v.z = 120.27f;
            if (func_0038CF38(&D_001A4BE0.v80, &v) < 11.5f) {
                if (func_0038DBA0(D_001A4BE0.f98, func_0038D160(v.x - D_001A4BE0.v80.x, v.y - D_001A4BE0.v80.y)) < 30.0f) near = 1;
            }
        }
        if (near) {
            func_L01_004FFF58();
            if (D_001A4BE0.fAC4 != 0) flag = 1;
        }
    }
    if (D_001A4BE0.f1228 == 0xB || flag != 0) {
force:
        func_L01_004FF780();
        func_L01_004FFA10();
        func_L01_004FFD00();
        func_L01_004FFF58();
        if ((D_001A4BE0.fA28 != 0 || D_001A4BE0.hA5E != 0 || D_001A4BE0.fAC4 != 0) && flag != 0 &&
            D_001A4BE0.b25E8 == 0 && D_001A4BE0.b25F0 == 0 && D_00142CAB[0] != 0) {
            D_001A4BE0.b25E7 = 1;
        }
    }
    func_L02_004DA1D0();
    if (D_L02_001D6694 == 2 || D_L02_001D6694 == 6) {
        if (D_001A4BE0.b25E5 != 0) func_L01_005108C0(0);
        else func_L01_00510AD0();
        func_L01_004E1F00(0);
        return;
    }
    func_L01_005129A8(D_001A4BE0.f25C0);
    func_L01_004E9450();
    if (D_001A4BE0.b25E4 != 0) {
        func_L01_004E1F00(0);
        return;
    }
    func_L01_004F5010();
    func_L01_004E7338();
    func_L01_004E64C0();
    func_L01_004E67F8();
    func_L01_004E6D18();
    func_L01_00516468();
    func_L01_004E0618();
    func_L01_004E0920();
    func_L01_004F2A08();
    func_L01_004E04A0();
    func_L01_004E45C8();
    func_L01_004E52E0(0);
    func_L01_004ED328();
    func_L01_004EAEE8();
    if (D_001A4BE0.b25E5 != 0 || func_L01_00513EF0() == 2) {
        if (func_L01_00513EF0() == 2 &&
            (D_L02_001E1300.h2A0 != 0 || (D_L02_001E1300.f50 != 0 && *(s16 *)(D_L02_001E1300.f50 + 0x86) == 0))) {
            func_L01_00510AD0();
        } else {
            func_L01_005108C0(0);
        }
    } else {
        func_L01_00510AD0();
    }
    func_L01_004E3148();
    func_L01_004E2ED0();
    func_L01_004E1638();
    func_L01_005138F8();
    func_L01_004E1218();
    func_L01_00512E68();
    if (D_001A4BE0.f25C4 != 0x31 || func_L01_004E26A0() != 0) func_L01_00430118(&D_001A4BE0.v80);
    func_L01_004436F4(D_001A4BE0.f25C0);
    func_L02_004B8AE0();
    func_L01_004E48C8();
    if (func_L01_00513EF0() != 0 && D_001A4BE0.f280C != 4 && D_001A4BE0.f280C != 0x51) D_001A4BE0.f280C = 0x20;
    func_L01_004E1F00(0);
}
/* localdecomp:end func_L02_004B8000 */
