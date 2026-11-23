#include "common.h"

/* localdecomp:start func_L09_003C53D8 */
#include "vu0.h"
extern void func_003886E8(void *, void *, f32);
extern u8 *func_L01_0044CF68(void *, void *, f32, f32, f32, f32, f32, void *, s32, s32, s32, s32, void *, s32, s32, s32);
extern void func_003BDA38(void *, int, void *);
extern f32 func_003887C8(void *, void *);
extern f32 *func_0037E0B8(void *);
extern void func_L01_003F4D78(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_0037E4B8(void *, float, float, float);
extern s32 func_L01_00417EA0(void);
extern void func_L09_003DDD48(void *, void *, void *, s32, f32);
extern void func_0039FE80(s32, s32, void *);
extern void func_003883C8(void *);
extern void func_L01_003EFFE0(s32, s32);
extern u8 *D_001D52FC;
extern u8 D_L09_001E2C00[];
extern s32 D_001D545C;
extern u8 D_0014275B[];
extern f32 D_L09_002F1DD0[];
extern f32 D_L09_001DAA30;
__asm__(".extern D_L09_001DAA30, 4");
extern s16 D_L09_001DE9BC;
__asm__(".extern D_L09_001DE9BC, 2");
extern f32 D_L09_001DE9C0;
__asm__(".extern D_L09_001DE9C0, 4");
extern s32 D_L09_001DE900;
__asm__(".extern D_L09_001DE900, 4");

typedef struct {
    u8 pad0[0x6D0];
    u8 *f6D0;
    u8 pad6D4[0x716 - 0x6D4];
    s16 f716;
    u8 pad718[0x762 - 0x718];
    s16 f762;
} P_003C53D8;

void func_L09_003C53D8(u8 *obj) {
    vu0_v4 from;
    vu0_v4 dir;
    vu0_v4 aim;
    vu0_v4 end;
    vu0_v4 at;
    P_003C53D8 *p;
    u8 *q;
    u8 *t;
    f32 *r;
    f32 d;
    f32 k;
    f32 f;

    p = *(P_003C53D8 **)(obj + 0x68);
    q = p->f6D0;
    *(vu0_q *)&aim = *(vu0_q *)(obj + 0xC0);
    *(s32 *)(obj + 0x98) = 0;
    func_003886E8(&from, obj + 0xE0, 0.5f);
    vec_add_ab(&from, &from, obj + 0x10);
    t = func_L01_0044CF68(&from, &aim, 0.12217305f, 0.08726646f, 40.0f, 0.17453292f, 0.2617994f, &at,
                          0, 0, 0, 1, 0, 1, -1, 0);
    *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
    func_003BDA38(obj, p->f762 ? 0x12 : 0x11, &from);
    if (t != 0) {
        d = func_003887C8(D_L09_001E2C00, t + 0x10) / 150.0f;
        r = func_0037E0B8(t);
        k = r ? r[4] : 0.1f;
        func_003886E8(&end, t + 0xE0, k);
        vec_add_ba(&end, t + 0x10, &end);
        func_L01_003F4D78(0, obj, 0xFF0FFF0F, &end, 0x26, -1, 4, fabs_asm(0.9f - d * 0.65f), 0.0f, 90.0f,
                          0.5f, 0.5f, 40.0f, 40.0f);
        vec_sub_ab(&dir, &end, &from);
        func_00388830(&dir, &dir, *(f32 *)(q + 0x138) + 1.50000012f);
    } else {
        func_0037E4B8(&dir, *(f32 *)(q + 0x138) + 1.50000012f, *(f32 *)(obj + 0xF8), *(f32 *)(obj + 0xF4) + 0.03f);
    }
    if ((*(s32 *)(D_001D52FC + 0x1A0) & 0x28) && p->f716 <= 0) {
        p->f716 = D_L09_001DE9BC;
        p->f762 ^= 1;
        f = 12.0f;
        if (D_001D545C != 0x12) {
            f = D_L09_001DE9C0;
        }
        if (func_L01_00417EA0()) {
            if (D_001D545C == 7 && D_0014275B[0] != 0) {
                f *= D_L09_001DAA30;
            } else {
                f *= D_L09_002F1DD0[D_001D545C];
            }
        }
        func_L09_003DDD48(obj, &from, &dir, 0x10001, f);
        func_0039FE80(3, 0, obj);
        func_L01_003EFFE0(D_L09_001DE900, 0);
    }
    func_003883C8(&p->f716);
}
/* localdecomp:end func_L09_003C53D8 */
