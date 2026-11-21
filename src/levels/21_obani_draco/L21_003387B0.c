#include "common.h"

/* declared by functions of L21_00336EF0.c, which this file was cut from */
extern s32 func_L01_0043B568(s32, s32, s32);
extern s32 func_00382468(s32);

/* declared by functions of L21_00338638.c, which this file was cut from */
extern s32 func_L01_0043B568(s32, s32, s32);
extern void func_L21_00337BF0(void *);

/* localdecomp:start func_L21_003387B0 */
#include "vu0.h"
extern s32 func_L01_0043B568(s32, s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_0038D160(f32, f32);
extern void func_L21_00337BF0(void *arg0);
extern u8 *D_L21_001DED9C_003387B0;
extern s32 D_L21_001DEDD8;
extern u16 *D_L21_0021B860[];
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
extern vu0_v4 D_L21_001D66B0 __attribute__((section(".sdata")));
extern f32 D_L21_001DCF40;
__asm__(".extern D_L21_001DCF40, 4");

void func_L21_003387B0(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    u8 *r = (u8 *)func_L01_0043B568(0x1C18, 0, 0x44);
    vu0_v4 pos;
    vu0_v4 rot;
    u16 *list;
    u16 *q;
    s32 k;
    s32 found;
    s32 near;
    u8 *e;
    u8 *m;
    f32 dist;
    f32 ang;
    u8 *t;

    if (r == 0) {
        return;
    }
    while (p[0x7E] != 0) {
        found = 0;
        list = D_L21_0021B860[*(s32 *)(p + 0x28)];
        while (1) {
            k = *(s32 *)(p + 0x28);
            if ((k & 0xFF) == 0xFF) break;
            if (D_L21_001DEDD8 < k) break;
            if (list == 0) break;
            if (!((s16)list[-1] >= 0 || list == D_L21_0021B860[k])) break;
            e = D_L21_001DED9C_003387B0 + ((*list & 0x7FFF) << 8);
            if (e == 0) break;
            if (((s32 (*)(u8 *))(*(void **)(r + 0x1C)))(e) == 1) {
                found = 1;
                break;
            }
            list++;
        }
        if (!found) {
            return;
        }
        for (;;) {
            dist = func_003824E0(0.0f, 4.0f);
            ang = func_00382538();
            pos.x = func_0038D098(ang) * dist;
            pos.y = func_0038D0B0(ang) * dist;
            pos.z = 0.0f;
            vec_add_ab(&pos, &D_L21_001DCF40, &pos);
            if (func_0038CF38(&pos, &D_001A4BE0.pos) < 0.6f) continue;
            near = 0;
            q = D_L21_0021B860[*(s32 *)(p + 0x28)];
            while (1) {
                k = *(s32 *)(p + 0x28);
                if ((k & 0xFF) == 0xFF) break;
                if (D_L21_001DEDD8 < k) break;
                if (q == 0) break;
                if (!((s16)q[-1] >= 0 || q == D_L21_0021B860[k])) break;
                m = D_L21_001DED9C_003387B0 + ((*q & 0x7FFF) << 8);
                if (m == 0) break;
                if (((s32 (*)(u8 *))(*(void **)(r + 0x1C)))(m) == 3 &&
                    func_0038CF38(&pos, m + 0x10) < 0.6f) {
                    near = 1;
                    break;
                }
                q++;
            }
            if (!near) break;
        }
        pos.z = func_003C3D30(&pos, 0, 0, 0.5f);
        rot = D_L21_001D66B0;
        t = (u8 *)D_001A4BE0.hero_moby;
        rot.z = func_0038D160(*(f32 *)(t + 0x10) - *(f32 *)(e + 0x10), *(f32 *)(t + 0x14) - *(f32 *)(e + 0x14));
        ((void (*)(u8 *, s32, void *, void *))(*(void **)(r + 0xC)))(e, 3, &pos, &rot);
        ((void (*)(u8 *, s32))(*(void **)(r + 0x18)))(e, 3);
        ((void (*)(u8 *, s32))(*(void **)(r + 0x10)))(e, 1);
        func_L21_00337BF0(arg0);
    }
}
/* localdecomp:end func_L21_003387B0 */
