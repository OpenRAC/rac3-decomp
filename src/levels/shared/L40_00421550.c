#include "common.h"

/* declared by functions of L40_00420998.c, which this file was cut from */
extern f32 func_L39_005B4410(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

/* localdecomp:start func_L40_00421550 */
#include "vu0.h"
typedef struct { f32 x, y, z; } V3_00421550;
typedef struct { u8 pad[0x88]; s32 a[1]; } S_00421550;
typedef struct { u8 pad[0x310]; s32 a310[6]; s32 a328[6]; } W_00421550;
extern s32 *D_L40_0028FD80[];
__asm__(".extern D_L40_0024112C_00421550, 16");
extern s32 D_L40_0024112C_00421550;
extern void *D_L40_0035746C[];
extern s32 D_001A5DF8[];
__asm__(".extern D_L40_002476F0, 4");
__asm__(".extern D_L40_002476F4, 4");
__asm__(".extern D_L40_002476F8, 4");
extern f32 D_L40_002476F0;
extern f32 D_L40_002476F4;
extern f32 D_L40_002476F8;
extern s32 func_L40_00420B50(u8 *);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L39_005B4398(s32);
extern u8 *func_L39_0066C2B8(void);
extern s32 func_L39_0066C280(s32 type, s32 uid, s32 time, s32 kind, u8 *msg);
extern s32 func_L40_0053E1A8(u8 *m, s32 team, s32 a2, f32 range, f32 b, f32 c, void *a3);
extern s32 func_L40_0053E760(s32 uid, vu0_v4 *pos, s32 a2, s32 a3);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern s32 func_L40_003F4510(s32, void *);
extern s32 func_L39_0066C1F0(s32);

void func_L40_00421550(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 uid = **(s32 **)(m + 0x90);
    vu0_v4 pos;

    switch (*(s32 *)(v + 0x2A4)) {
    case 0:
        *(s32 *)(v + 0x2A4) = 1;
        break;
    case 1:
    {
        s32 t = -1;
        s32 *path;
        s32 i;
        u8 *msg;
        u8 *p;
        f32 a;
        f32 ang;

        *(s32 *)(v + 0x45C) = func_L40_00420B50(m);
        if (*(s32 *)(v + 0x454) != -1) {
            path = D_L40_0028FD80[*(s32 *)(v + 0x454)];
            if ((D_L40_0024112C_00421550 & 0x3F) == (((s32)m >> 8) & 0x3F) &&
                func_0038CF38(m + 0x10, (u8 *)path + 0x10 + *(s32 *)(v + 0x2C4) * 16) < 1.0f &&
                func_L39_005B4398(1) == 0) {
                if (*(s32 *)(v + 0x340) == 0) {
                    *(s32 *)(v + 0x340) = 1;
                }
                i = *(s32 *)(v + 0x2C4) + *(s32 *)(v + 0x340);
                *(s32 *)(v + 0x2C4) = i;
                if (i < 0) {
                    *(s32 *)(v + 0x2C4) = 1;
                    *(s32 *)(v + 0x340) = 1;
                } else if (i >= path[0]) {
                    *(s32 *)(v + 0x340) = -1;
                    *(s32 *)(v + 0x2C4) = i - 2;
                }
                msg = func_L39_0066C2B8();
                if (msg == 0) {
                    return;
                }
                p = msg + func_L39_0066C280(1, uid, D_001A5DF8[0] + 500, 1, msg);
                *(s32 *)p = *(s32 *)(v + 0x2C4);
                p += 4;
                *(s32 *)msg = p - msg;
            }
        }
        if (*(s32 *)(v + 0x45C) != -1) {
            t = func_L40_0053E1A8(m, ((S_00421550 *)D_L40_0035746C[0])->a[*(s32 *)(v + 0x290)], 0,
                                  *(f32 *)(v + 0x2B8), -1.0f, 10.0f, 0);
        }
        if (t == -1) {
            return;
        }
        if (func_L40_0053E760(t, &pos, -1, 0) == 0) {
            return;
        }
        *(s32 *)(v + 0x29C) = -1;
        *(f32 *)(v + 0x2E8) = 0.0f;
        a = ((f32 (*)(f32, f32))func_L39_005B4410)(3.5f, 5.0f);
        ang = func_0038DAB8(*(f32 *)(m + 0xF8), ((f32 (*)(f32, f32))func_L39_005B4410)(D_L40_002476F4, D_L40_002476F8) * 0.017453292f);
        *(f32 *)(v + 0x2E0) = func_0038D098(ang) * a;
        *(f32 *)(v + 0x2E4) = func_0038D0B0(ang) * a;
        *(f32 *)(v + 0x2E8) = 0.0f;
        func_0038CF68(v + 0x2E0, v + 0x2E0, a);
        vec_add_ba(v + 0x2E0, v + 0x2E0, m + 0x10);
        *(f32 *)(v + 0x2E8) += D_L40_002476F0;
        *(f32 *)(v + 0x2E8) = func_003C3D30(v + 0x2E0, 0, 0, 0.5f);
        *(s32 *)(v + 0x2A8) = 0;
        *(s32 *)(v + 0x2A4) = 2;
        msg = func_L39_0066C2B8();
        if (msg == 0) {
            return;
        }
        p = msg + func_L39_0066C280(1, uid, D_001A5DF8[0] + 500, 0, msg);
        *(V3_00421550 *)p = *(V3_00421550 *)(v + 0x2E0);
        p += 0xC;
        *(s32 *)msg = p - msg;
        break;
    }
    case 2:
        if (++*(s32 *)(v + 0x2A8) >= 43 && *(s32 *)(v + 0x29C) == -1) {
            *(s32 *)(v + 0x29C) = func_L40_003F4510(((W_00421550 *)v)->a310[*(s32 *)(v + 0x45C)], v + 0x2E0);
        }
        if ((*(s32 *)(v + 0x44C) * 5 + 2) / 6 < *(s32 *)(v + 0x2A8)) {
            *(s32 *)(v + 0x2A4) = 1;
            ((W_00421550 *)v)->a328[*(s32 *)(v + 0x45C)] = func_L39_0066C1F0(*(s32 *)(v + 0x29C));
        }
        break;
    }
}
/* localdecomp:end func_L40_00421550 */
