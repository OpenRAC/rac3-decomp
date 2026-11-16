/* NTSC-U draft (Codex wave 3): C of func_L01_00303C18, the NTSC-U twin of func_L01_00303E30, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 94 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_00303C18", whose code is not the PAL one).
 * Worker's note: 94 diff; best log func_L01_00303C18.check1.log; verified allowed GNU assembler literal-pool loads for 0.1, angle and threshold versus retail inline constants; unlisted @ps2as not tried; real VU0 sequences retained, additional scheduling differences
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00303C18 */
typedef struct {
    u8 pad0[0x18]; f32 f18;
    u8 pad1C[0x50-0x1C]; u8 *f50;
    u8 pad54[0x190-0x54]; vu0_v4 position;
    u8 pad1A0[8]; f32 f1A8;
    u8 pad1AC[0x240-0x1AC]; u8 *f240;
    u8 pad244[0x260-0x244]; f32 f260;
    u8 pad264[0x460-0x264];
} S_00303C18;
extern S_00303C18 D_L01_001E2AC0[];
extern f32 func_00388730(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388770(void *);
extern f32 func_00389468(f32, f32);

static __inline__ void sub_00303C18(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void sub_ab_00303C18(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void add_00303C18(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
void func_L01_00303C18(u8 *m) {
    vu0_v4 d, p;
    S_00303C18 *s = &D_L01_001E2AC0[m[0xBC]];
    f32 t;
    if (s->f50) {
        *(vu0_q *)(m+0x10)=*(vu0_q *)(s->f50+0x30);
        sub_00303C18(&d,m+0x10,&s->position);
        t=func_00388730(&d,s->f240+0xE0);
        func_003886E8(&p,s->f240+0xE0,t);
        t=fabs_asm(t);
        sub_ab_00303C18(&d,&d,&p);
        if (t < 2.5f) {
            if (func_00388770(&d)<0.1f || func_00389468(s->f1A8,s->f18)<2.3561945f || s->f260<0.0016666667f) {
                *(f32 *)(m+0x10)=15.0f;
                *(f32 *)(m+0x18)=15.0f;
                *(f32 *)(m+0x14)=15.0f;
            } else {
                t=func_00388730(m+0x10,s->f240+0xE0);
                func_003886E8(&p,s->f240+0xE0,t);
                sub_00303C18(&d,m+0x10,&p);
                t=func_00388730(&s->position,s->f240+0xE0);
                func_003886E8(&p,s->f240+0xE0,t);
                add_00303C18(m+0x10,&d,&p);
            }
        }
    } else {
        *(f32 *)(m+0x10)=5.0f;
        *(f32 *)(m+0x18)=5.0f;
        *(f32 *)(m+0x14)=5.0f;
    }
}
/* localdecomp:end func_L01_00303C18 */
