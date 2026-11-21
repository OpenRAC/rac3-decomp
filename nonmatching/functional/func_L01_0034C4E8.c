/* functional: medium. Near-miss draft (compiles under file flags); 204 diff words (stack/FP regalloc); 7 float constants and callee set cross-checked; description inferred from draft and callee inventory, not every branch re-read */
/* localdecomp:start func_L01_0034C4E8 */
#include "vu0.h"
extern vu0_q D_001A4BE0;
extern S_27F600 D_L01_0027F580[];
extern u8 *D_L01_001EEA80[];
typedef struct {
    s32 f0, color1, color2;
    f32 angle, power, period;
    u8 *moby;
    f32 timer;
    s32 f20, count, f28, f2C;
} Effect_0034C4E8;
void func_L01_0034C4E8(u8 *self) {
    extern f32 func_0038DAB8(f32, f32);
    extern s32 func_0038CAD0(void *);
    extern s32 func_L01_0040E050(void *);
    extern s32 func_003D4D00(void *, s32, f32, void *, void *);
    extern f32 *func_00382348(void *);
    extern s32 func_0013D3E0(void);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_00382760(void *, f32, f32, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_0034D078(void *, void *, void *, void *, void *, s32, s32, s32, void *, f32);
    extern void func_L01_0034C910(u8 *s);
    extern f32 func_0038D098(f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern void func_L01_0043B9E8(void *, s32, s32, s32);
    extern void func_L01_0034D2F0(void *);
    extern void func_L01_0034CF88(s32);
    extern void func_L01_00404A10(void *, void *);
    vu0_v4 first, second;
    s32 i = 0;
    *(vu0_q *)(self + 0x10) = D_001A4BE0;
    do {
        s32 next = i + 1;
        if (D_L01_0027F580[i].x18 != 0) {
            Effect_0034C4E8 *p = (Effect_0034C4E8 *)&D_L01_0027F580[i];
            s32 dead;
            p->angle = func_0038DAB8(p->angle, 0.25132742524147034f);
            dead = *(s8 *)(p->moby + 0x20) < 0 || *(s32 *)(p->moby + 0x98) == 0;
            if (func_0038CAD0(p)) dead = 1;
            if (func_L01_0040E050(&p->timer)) {
                s32 n, j;
                u8 **list;
                p->timer = p->period;
                n = func_003D4D00(p->moby + 0x10, 0, 8.0f, p->moby, 0);
                list = D_L01_001EEA80;
                for (j=0; j<n; j++, list++) {
                    u8 *target = *list;
                    f32 *damage = func_00382348(target);
                    if ((*(u16 *)(target + 0x34) & 0x1000) && target != 0 && target[0x20] != 0xFE && target[0x20] != 0xFD && target[0x31] != 0 && !(*(u16 *)(target + 0x34) & 2) && (*(u8 **)(target + 0x24))[0x46] == 5 && *(s16 *)(target + 0xAA) != 0x1AE6 && damage && damage[0] > 0.0f) {
                        qzero(&first);
                        func_L01_0034D078(self, p->moby, target, &first, &first, 1, 10, 30, p, p->power);
                        func_L01_0034D078(self, p->moby, target, &first, &first, 0, 10, 30, p, 0.0f);
                        break;
                    }
                }
            }
            if (func_0013D3E0() % 11 == 0) {
                f32 r, a, b;
                s32 life1, life2;
                r = func_003824E0(0.3f, 0.65f);
                r = *(f32 *)(p->moby + 0xC) * 0.0009765f * r;
                a = func_00382538();
                b = func_00382538();
                func_00382760(&first, r, a, b);
                r = func_003824E0(0.3f, 0.65f);
                r = *(f32 *)(p->moby + 0xC) * 0.0009765f * r;
                a = func_00382538();
                b = func_00382538();
                func_00382760(&second, r, a, b);
                life1 = func_00382498(5, 15);
                life2 = func_00382498(15, 30);
                func_L01_0034D078(self, p->moby, p->moby, &first, &second, 0, life1, life2, p, 0.0f);
            }
            if (dead) {
                func_L01_0034C910((u8 *)p);
                p->moby = 0;
            } else if (p->count == 0) {
                s32 color = func_0038DBD8(p->color1, p->color2, (func_0038D098(p->angle) + 1.0f) * 0.5f);
                func_L01_0043B9E8(p->moby, color & 255, (color >> 8) & 255, (color >> 16) & 255);
            } else p->count--;
        }
        i = next;
    } while (i < 30);
    func_L01_0034D2F0(self);
    func_L01_00404A10(func_L01_0034CF88, self);
}
/* localdecomp:end func_L01_0034C4E8 */
