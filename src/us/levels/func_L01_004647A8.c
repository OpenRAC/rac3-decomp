#include "common.h"

/* NTSC-U counterpart of func_L01_00467DC8 (src/levels/shared/L01_00465878.c): 0.0288 -> 0.02 */
#include "vu0.h"
extern vu0_v4 D_L01_001E2A40_004647A8;
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
extern vu0_v4 D_L01_001E2A40_004647A8;
#include "vu0.h"
#include "vu0.h"

/* localdecomp:start func_L01_004647A8 */
#include "vu0.h"
typedef struct {
    vu0_v4 velocity;
    u8 *anchor, *next;
    s16 a18, a1A, collision, flags;
} Chain_00467DC8;
extern vu0_v4 D_L01_001E2A40_004647A8;
extern vu0_v4 D_L01_001EAAB0, D_L01_001EAAC0;
void func_L01_004647A8(u8 *self) {
    extern void func_00388830(void *,void *,f32);
    extern void func_003886E8(void *,void *,f32);
    extern f32 func_00388770(void *);
    extern s32 func_L01_003F9498(void *,s32,s32,f32);
    extern void func_L01_0040C260(void *,void *,void *);
    extern void func_003C7CE0(u8 *);
    extern void func_003888F0(void *,void *,void *);
    extern f32 func_00388A28(f32,f32);
    vu0_v4 position, delta, sum;
    Chain_00467DC8 *state = (Chain_00467DC8 *)(self + 0x20);
    Chain_00467DC8 *prior;
    u8 *p;
    f32 distance, damping, gain, angle;
    s32 alpha;
    if (state->flags != 255) {
        if (((*(u8 *)&state->flags ^ 1) & 1)) {
            prior = 0;
            p = state->next;
            qzero(&sum);
            distance = 2.0f;
            damping = 0.15f;
            if (p) prior = (Chain_00467DC8 *)(p + 0x20);
            if (!state->collision) {
                while (p && !(*(unsigned long *)((u8 *)prior + 0x18) & 0x1FFFF00000000UL)) {
                    vec_sub_ab(&position,p + 0x10,self + 0x10);
                    func_00388830(&position,&position,0.2f / (distance * distance));
                    distance += 1.0f;
                    damping *= 0.9990000128746033f;
                    vec_add_ab(&sum,&sum,&position);
                    p = prior->next;
                    if (p) prior = (Chain_00467DC8 *)(p + 0x20);
                }
            }
            damping = (0.15f - damping) + 1.0700000524520874f;
            if (!prior || !prior->collision) vec_add_ab(state,state,&sum);
            else func_003886E8(state,state,0.5f);
            if (state->next) func_003886E8(state,state,damping);
            else func_003886E8(state,state,0.9700000286102295f);
            state->velocity.z -= 0.0199999996f;
            vec_add_ab(&position,self + 0x10,state);
        } else {
            *(vu0_q *)&position = *(vu0_q *)(self + 0x10);
        }
        if (state->anchor) {
            vec_sub_ba(&sum,&position,state->anchor + 0x10);
            if (fabs_asm(func_00388770(&sum) - 0.15f) > 0.1f) {
                func_00388830(&sum,&sum,0.15f);
                vec_add_ab(&position,&sum,state->anchor + 0x10);
            }
            if (func_L01_003F9498(&position,0,0,0.15f)) {
                if (!state->collision) *(vu0_q *)&position = *(vu0_q *)&D_L01_001EAAB0;
                else *(vu0_q *)&position = *(vu0_q *)(self + 0x10);
                state->collision = 1;
            } else state->collision = 0;
            if (state->collision) {
                func_L01_0040C260(state,state,&D_L01_001EAAC0);
                func_003886E8(state,state,0.95f);
            } else {
                vec_sub_ba(&delta,&position,self + 0x10);
                vec_add_ab(state,state,&delta);
                func_003886E8(state,state,0.5f);
            }
            vec_sub_ba(&delta,&position,self + 0x10);
            vec_add_ab(state,state,&delta);
            func_003886E8(state,state,0.5f);
        }
        *(vu0_q *)(self + 0x10) = *(vu0_q *)&position;
        if (state->flags & 2) {
            alpha = (*(u32 *)(self + 4) >> 24) - 2;
            if (alpha > 0) *(u32 *)(self + 4) = (*(u32 *)(self + 4) & 0xFFFFFF) | (alpha << 24);
            else if (!state->next) {
                if (state->anchor) *(s32 *)(state->anchor + 0x34) = 0;
                func_003C7CE0(self);
                return;
            }
        }
    }
    if (state->anchor) {
        vec_sub_ab(&position,state->anchor + 0x10,&D_L01_001E2A40_004647A8);
        func_003888F0(&position,&position,(u8 *)&D_L01_001E2A40_004647A8 - 0x80);
        func_003886E8(&position,&position,1.0f / position.w);
        vec_sub_ba(&delta,self + 0x10,&D_L01_001E2A40_004647A8);
        func_003888F0(&delta,&delta,(u8 *)&D_L01_001E2A40_004647A8 - 0x80);
        func_003886E8(&delta,&delta,1.0f / delta.w);
        vec_sub_ab(&position,&position,&delta);
        angle = func_00388A28(position.x,position.y);
        self[8] = (s32)(angle * 128.0f / 3.1415927410125732f) - 32;
    }
}
/* localdecomp:end func_L01_004647A8 */
