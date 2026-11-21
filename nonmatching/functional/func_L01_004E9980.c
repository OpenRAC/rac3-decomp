/* functional: high. Float arg order into 004E9470 is interleaving only. VU0 inline asm. */
#include "common.h"
/* localdecomp:start func_L01_004E9980 */
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec_004E9980;
typedef struct { u8 pad[0x25F4]; u8 mode; } Hero_004E9980;
extern u8 D_001A4BE0[];
extern u8 D_L01_001E2DC0[];
extern S_4E56A8m *D_L01_0021E860[];
S_4E56A8m *func_L01_004E9980(s32 source, s32 kind, s32 test, f32 angle, f32 distance, f32 horizontal, f32 vertical) {
    extern void func_0038D5B0(void *,void *);
    extern u8 *func_00382348(void *);
    extern f32 func_L01_004E96E8(S_4E56A8m *,s32,f32,f32,f32,s32 *,s128 *);
    extern f32 func_L01_004E9470(S_4E56A8m *,s32 *,f32,f32,f32,f32);
    extern void func_0038CF68(void *,s32,float);
    extern s32 func_003D3CB0(void *,void *,s32,s32,s32);
    struct { s128 matrix[4]; s128 start; Vec_004E9980 end; s32 reject; } local;
    S_4E56A8m **slot;
    S_4E56A8m *m;
    S_4E56A8m *best = 0;
    f32 score, bestScore = 100000000.0f;
    if ((*(Hero_004E9980 *)D_001A4BE0).mode) func_0038D5B0(local.matrix,D_L01_001E2DC0);
    slot = D_L01_0021E860;
    while ((m=*slot) != 0) {
        if (kind != -1 && m->x24->x46 != kind) goto next;
        if (kind == 5) {
            u8 *damage=func_00382348(m);
            if (!damage || *(f32 *)damage==0.0f) goto next;
        }
        if (*(u16 *)((u8 *)m+0x34)&0x1000) {
            if ((*(Hero_004E9980 *)D_001A4BE0).mode) {
                score=func_L01_004E96E8(m,source,angle,horizontal,vertical,&local.reject,local.matrix);
            } else {
                score=func_L01_004E9470(m,&local.reject,distance,angle,horizontal,vertical);
            }
            if (!local.reject && score<bestScore) {
                if (test) {
                    local.start=*(s128 *)(D_001A4BE0+0xE0);
                    func_0038CF68(&local.end,(s32)((u8 *)m+0xE0),1.0f);
                    __asm__("lqc2 $vf2, %0\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                        : "+m"(local.end) : "m"(*(Vec_004E9980 *)((u8 *)m+0x10)) : "vf1", "vf2");
                    if (func_003D3CB0(&local.start,&local.end,2,0,0)) goto next;
                }
                bestScore=score;
                best=m;
            }
        }
next:
        slot++;
    }
    return best;
}
/* localdecomp:end func_L01_004E9980 */
