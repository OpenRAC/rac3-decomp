/* functional: medium. Written from the retail asm; compiles with the file's flags (388 words differ: frame/scheduling). Unsure: func_L01_004501E8 prototype (8 int regs, 3 stack slots 1,-1,0, floats pi/8,pi/4,11.1,0,0; 20-byte D_001DDF10 struct is passed as a pointer to a copy); v20 is read uninitialised when a lock-on target exists, as retail reads stack garbage. D_001E1F14 and D_001D52FC are used both via $gp and lui in retail (same memory). self[0x20] is always set to 1 after the fire/release block as in retail. */
#include "common.h"
typedef struct { float x,y,z,w; } __attribute__((aligned(16))) V_VH;
#define VOP(NAME,OP) static __inline__ void NAME(void *d, void *a, void *b) { \
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\t" OP " $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*(V_VH *)d) : "m"(*(V_VH *)a), "m"(*(V_VH *)b) : "vf1","vf2"); }
VOP(vec_sub_ab,"vsub.xyz")
VOP(vec_add_ab,"vadd.xyz")
typedef int s128_vh __attribute__((mode(TI)));
static __inline__ void vec_copy(void *d, void *s) { *(s128_vh *)d = *(s128_vh *)s; }
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
extern u8 D_001A4C60[];
extern s32 D_001D673C;
extern s32 D_001E1F14;
extern u8 *D_001D52FC __attribute__((section(".data")));
extern u8 D_001425F7[];
extern u8 D_L01_002B3CE0[];
extern u8 D_L01_002C5600[];
extern u8 D_L01_001D66B0[];
extern u8 *D_L01_0022123C;
extern s32 D_001DDF10[5];
extern f32 D_001DDEF0_sda, D_001DDEF4_sda, D_001DDEF8_sda, D_001DDEFC_sda;
extern V_VH D_001DDF00_sda;
extern s32 D_001E1F14_sda;
extern u8 *D_001D52FC_sda;
__asm__(".extern D_001DDEF0_sda,4");
__asm__(".extern D_001DDEF4_sda,4");
__asm__(".extern D_001DDEF8_sda,4");
__asm__(".extern D_001DDEFC_sda,4");
__asm__(".extern D_001DDF00_sda,16");
__asm__(".extern D_001E1F14_sda,4");
typedef struct { s32 w[5]; } Cfg20_0038B280;
extern void func_003C2F58(u8 *);
extern f32 *func_00382348(u8 *);
extern s32 func_0038CAD0(s32 *);
extern void *func_L01_004501E8(void *, void *, void *, s32, s32, s32, s32, void *, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_L01_004C7438(void *, void *, void *, s32, f32, f32, f32, f32);
extern void *func_L01_004C7A18(void *, void *, void *, void *, u8 *, s32, s32, f32);
extern void func_L01_00444F38(u8 *, s32, s32, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_004EAA80(void);
extern s32 func_L01_005118D0(s32, s32);
extern void func_L01_004EA7D8(s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern s32 func_L01_003F2058(void *, s32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00390240(u8 *, void *, void *);
extern void func_003A52A0(s32, s32, u8 *);
extern s32 func_L01_005119E0(s32);
extern void func_L01_003F2278(s32, s32);
extern void func_0038D000(void *, void *, void *);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_004C7D98(void *, void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_0013D3E0(void);
extern void func_L01_00466F50(void *, void *, s32, f32, f32);
extern void func_L01_0040E050(u8 *);
extern void func_L01_00404A10(void (*)(u8 *), u8 *);
extern void func_L01_0038B950(u8 *);
void func_L01_0038B280(u8 *self) {
    V_VH v20, v30, v50, v60, v70;
    Cfg20_0038B280 cfg;
    u8 *inner = *(u8 **)(self + 0x68);
    u8 *hp = (u8 *)&D_001A4BE0;
    u8 *lock;
    u8 *target = 0;
    s32 armed, press;
    u8 *p;
    func_003C2F58(self);
    lock = (u8 *)D_001A4BE0.lockon_target;
    if (lock != 0 && lock[0x20] != 0xFE) {
        if (lock[0x20] != 0xFD) {
            f32 *r = func_00382348(lock);
            if (r != 0 && 0.0f < *r) target = (u8 *)D_001A4BE0.lockon_target;
        }
    }
    armed = 1;
    if (D_001A4BE0.state == 0x1D || D_001A4BE0.state == 1) {
        armed = func_0038CAD0((s32 *)(hp + 0x28BC)) != 0;
    } else {
        *(s32 *)(hp + 0x28BC) = 0x21;
        if (target == 0) {
            cfg = *(Cfg20_0038B280 *)D_001DDF10;
            target = func_L01_004501E8(&v20, hp + 0x6F0, &v70, 0, 0, 0, 0, &cfg, 1, -1, 0,
                                       0.3926991f, 0.7853982f, 11.1f, 0.0f, 0.0f);
        }
    }
    if (D_001D673C != 0) {
        D_001DDEF0_sda = 7.8f; D_001DDEF4_sda = 1e-5f; D_001DDEF8_sda = 12.0f; D_001DDEFC_sda = 10.0f;
    } else {
        D_001DDEF4_sda = 1e-5f; D_001DDEF8_sda = 12.0f; D_001DDEFC_sda = 15.0f; D_001DDEF0_sda = 12.0f;
    }
    func_L01_004C7438(&v30, &v20, target, 0, D_001DDEF4_sda, D_001DDEF0_sda,
                      D_001DDEFC_sda * 0.02f, D_001DDEF8_sda * 0.0004f);
    *(void **)(inner + 0x24) = func_L01_004C7A18(&v20, &v30, inner, inner + 0x10, self, 0, 0,
                                                 D_001DDEF8_sda * 0.0004f);
    if (self[0x42] == self[0x43]) {
        if (self[0x60] & 2) func_L01_00444F38(self, 1, 0, 2, 0);
    }
    if (*(s16 *)(hp + 0x2874) != 0) func_0038CE20(&v30, self + 0xD0, -0.29f);
    if (self[0x20] == 0) {
        self[0x20] = 1;
        *(s32 *)(inner + 0x2C) = -1;
        *(s32 *)(inner + 0x20) = 0;
        goto state1;
    } else if (self[0x20] == 1) {
state1:
        if (D_001A4BE0.firing_count >= 0x12) func_L01_004EAA80();
        if (*(f32 *)(inner + 0x20) != 0.0f) goto idle;
        if (D_001A4BE0.no_firing) goto done;
        press = *(s32 *)(hp + 0x1210);
        if ((*(s32 *)(D_001D52FC_sda + 0x1A0) & press) == 0) goto idle;
        if (armed == 0) goto idle;
        if (*(s32 *)(hp + 0x1220) < 0x13) goto idle;
        if (func_L01_005118D0(-1, 1) != 0) {
            D_001E1F14_sda = 1;
            func_L01_004EA7D8(-1);
            func_003C3A10(self, 2, 0, 0);
            *(s32 *)(inner + 0x2C) = func_L01_003F2058(D_L01_002B3CE0, 0);
            if (0.6f < func_0038CEA8(&v30)) func_0038CF68(&v30, &v30, 0.44f);
            func_L01_00390240(self, &v20, &v30);
            func_003A52A0(0, 0, self);
            *(f32 *)(inner + 0x20) = 1.0f / *(f32 *)(D_L01_002C5600 + D_001425F7[0] * 0xF0 + 0x50);
        } else {
            if ((*(s32 *)((u8 *)D_001D52FC + 0x1A4) & *(s32 *)(hp + 0x1210)) != 0 || D_001E1F14 == 1) {
                func_003A52A0(1, 0, self);
                D_001E1F14 = 0;
            }
        }
        if ((*(s32 *)(D_001D52FC_sda + 0x1A0) & *(s32 *)(hp + 0x1210)) != 0
            && func_L01_005119E0(-1) != 0 && D_001A4BE0.firing != 0) {
            self[0x20] = 1;
        } else {
            if (*(s32 *)(inner + 0x2C) >= 0) {
                func_L01_003F2278(*(s32 *)(inner + 0x2C), 0);
                *(s32 *)(inner + 0x2C) = -1;
            }
            self[0x20] = 1;
        }
    }
idle:
    if (D_001A4BE0.no_firing == 0) {
        s32 life, tex, k;
        func_0038D000(&v50, &D_001DDF00_sda, self + 0xC0);
        vec_add_ab(&v50, &v50, self + 0x10);
        life = (func_00382498(10, 20) * 5 + 2) / 6;
        tex = func_00382498(1, 4);
        p = func_L01_004713C8(&v50, D_L01_001D66B0, life, 0x5A182, tex, 0x30, 0, 0,
                              52500.0f, 157500.0f, 0.0002f);
        if (p != 0) {
            p[3] = func_00382468(2) ? 0x48 : 0x44;
            p[2] = *D_L01_0022123C;
        }
        func_L01_004C7D98(D_001A4C60, &v60);
        func_0038CF68(&v60, &v60, func_003824E0(0.005f, 0.015f));
        v50.x += func_003824E0(-0.075f, 0.075f);
        v50.y += func_003824E0(-0.075f, 0.075f);
        v50.z += func_003824E0(-0.075f, 0.075f);
        k = func_0013D3E0();
        if (k % 12 == 0) func_L01_00466F50(&v50, &v60, 0x4005A182, -1.0f, 0.0f);
    }
done:
    func_L01_0040E050(inner + 0x20);
    func_L01_00404A10(func_L01_0038B950, self);
}
