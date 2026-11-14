/* NTSC-U draft (2026-11-14, Codex worker): C of func_L01_0033E828, the NTSC-U twin of func_L01_0033EF90, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses" (src/levels/shared/L01_0033E0C8.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses").
 */
#include "common.h"

/* localdecomp:start func_L01_0033E828 */
typedef int Q_E828 __attribute__((mode(TI)));
typedef union { Q_E828 q; f32 f[4]; } V_E828;
extern V_E828 D_L01_001E2A40;
extern V_E828 D_L01_001D66B0;
__asm__(".extern D_L01_001D66B0, 16");
extern f32 D_001DD09C_sda, D_001DD0A8_sda, D_001DD0AC_sda;
extern s32 D_001DD0A0_sda, D_001DD0A4_sda;
extern u32 D_001DD0B0_sda, D_001DD0B4_sda;
extern f32 func_0037E2A8(void);
extern void func_00389158(void *, void *, void *, f32);
extern s32 func_0037E1D8(s32);
extern void func_00388830(void *, void *, f32);
extern u8 *func_L01_004633E8(f32, f32, f32, f32, void *, s32, void *, u32, s32);

static __inline__ void sub_E828(V_E828 *d, V_E828 *a, V_E828 *b) {
    __asm__("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "r"(a), "m"(*b), "m"(*a) : "vf1", "vf2");
}
static __inline__ void add_E828(V_E828 *d, V_E828 *a, V_E828 *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void add2_E828(V_E828 *d, V_E828 *a, V_E828 *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}

void func_L01_0033E828(u8 *m) {
    V_E828 axis, delta, rotated, at, velocity;
    s32 spin, life;
    u8 *p, *q;
    axis.q=0;
    axis.f[2]=D_001DD0A8_sda;
    sub_E828(&delta,&D_L01_001E2A40,(V_E828 *)(m+0x10));
    func_00389158(&rotated,&axis,&delta,func_0037E2A8());
    add_E828(&at,(V_E828 *)(m+0x10),&rotated);
    spin=func_0037E1D8(16);
    if(func_0037E1D8(2)) spin=-spin;
    life=D_001DD0A4_sda;
    func_00388830(&velocity,&rotated,-(D_001DD0A8_sda/(f32)life));
    p=func_L01_004633E8(0.5f,1.0f,0.99f,D_001DD09C_sda*210000.0f,
        &at,spin,&velocity,D_001DD0A0_sda,0);
    if(p) {
        *(s16 *)(p+0xA)=life;
        q=p+0x20;
        *(s32 *)(q+4)=3;
        q[0xA]=0x7F;
        q[0xB]=p[0xA];
    }
    if(func_0037E1D8(3)==0) {
        func_00388830(&delta,&delta,-0.5f);
        add2_E828(&at,(V_E828 *)(m+0x10),&delta);
        p=func_L01_004633E8(0.1f,1.0f,0.8f,D_001DD0AC_sda*210000.0f,
            &at,spin,&D_L01_001D66B0,(D_001DD0B0_sda&0xFFFFFF)|(D_001DD0B4_sda<<24),0);
        if(p) {
            *(s16 *)(p+0xA)=60;
            p[3]=0x44;
            q=p+0x20;
            *(s32 *)(q+4)=3;
            q[0xA]=(u8)D_001DD0B4_sda;
            q[0xB]=p[0xA];
        }
    }
}
/* localdecomp:end func_L01_0033E828 */
