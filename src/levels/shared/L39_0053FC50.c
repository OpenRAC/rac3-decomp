#include "common.h"

/* localdecomp:start func_L39_0053FC50 */
#include "vu0.h"

typedef struct {
    vu0_v4 pos;
    u8 pad10[0x10];
    f32 f20;
    u8 pad24[4];
    s32 w28;
    s32 w2C;
} E_0053FC50;

extern E_0053FC50 D_L39_0024DE80[];
extern u8 D_L39_00242930[] __attribute__((section(".sdata")));
extern u8 *D_L39_00296818[];
extern s32 func_L39_005BE900(void *, s32, f32);
extern f32 func_0038CF00(void *, void *);
extern void func_L01_0034C300(void *, f32);
extern void func_L39_005B8978(void *, void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, s32, f32, void *, u32, s32);
extern s32 func_L39_005B43C8(s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L39_005BC330(void *, void *, s32);
extern void func_0038CE20(void *, void *, f32);

void func_L39_0053FC50(u8 *a0, s32 a1, s32 a2) {
    vu0_v4 sphere;
    vu0_v4 d;
    vu0_v4 mid;
    vu0_v4 p50;
    vu0_v4 v60;
    vu0_v4 p70;
    vu0_v4 p80;
    f32 heading;
    s32 n;
    s32 i;
    s32 j;
    s32 m;
    s32 s;
    vu0_v4 *pos = (vu0_v4 *)(a0 + 0x10);

    sphere = *pos;
    sphere.w = 2.0f;
    if (func_L39_005BE900(&sphere, 0, 48.0f) == 1) {
        func_L01_0034C300(*(void **)(a0 + 0x68), func_0038CF00(pos, D_L39_0024DE80));
        D_L39_0024DE80[0].w28 = 0x21;
        D_L39_0024DE80[0].f20 = 0.1f;
        D_L39_0024DE80[0].w2C = 0;
    }
    func_L39_005B8978(a0, D_L39_00242930, pos, 0, 0, 0, -1, 0,
                      0.0f, 0.0f, 0.0f, 0.0f, 9.0f, 0.0f, 20.0f, 0, -1, 0, 0x1010001);
    vec_sub_ba(&d, D_L39_0024DE80, pos);
    func_0038CF68(&d, &d, 0.5f);
    vec_add_ab(&mid, pos, &d);
    *pos = mid;
    heading = func_0038D160(D_L39_0024DE80[0].pos.x - *(f32 *)(a0 + 0x10),
                            D_L39_0024DE80[0].pos.y - *(f32 *)(a0 + 0x14));

    n = 20;
    switch (a2) {
    case 2:
        n = 10;
        break;
    case 3:
        n = 5;
        break;
    case 4:
        n = 1;
        break;
    }
    s = 1;
    for (i = 0; i < n; i++) {
        f32 a;
        f32 b;
        u8 *q;
        p50.x = mid.x + func_L39_005B4468(0.0f, 1.0f);
        s = -s;
        p50.y = mid.y + func_L39_005B4468(0.0f, 1.0f);
        p50.z = mid.z + func_L39_005B4468(0.0f, 1.0f);
        a = func_L39_005B4410(0.020000001f, 0.040000003f);
        b = func_L39_005B4468(0.0f, 1.3962634f);
        func_00382760(&v60, a, func_0038DAB8(heading, func_L39_005B4468(0.0f, 1.5707964f)), b);
        q = func_L01_004669B0(&p50, 0.0f, 1.0f, 1.01f, s, 315000.0f, &v60, 0x7F60A0FF, 1);
        if (q != 0) {
            s32 r;
            u8 *data;
            r = func_L39_005B43C8(0x28, 0x46);
            q[9] = 0x44;
            *(s16 *)(q + 0xA) = (r * 5 + 2) / 6;
            data = q + 0x20;
            *(s32 *)(data + 4) = 3;
            r = func_L39_005B43C8(1, 10);
            data[0xA] = 0x40;
            *(f32 *)(data + 0x1C) = (r * 5 + 2) / 6;
            data[0xB] = q[0xA];
        }
    }

    n = 32;
    switch (a2) {
    case 2:
        n = 16;
        break;
    case 3:
        n = 8;
        break;
    case 4:
        n = 2;
        break;
    }
    for (j = 0; j < n; j++) {
        s32 k;
        s32 col;
        s32 r;
        f32 sz;
        f32 big;
        f32 sp;
        f32 yaw;
        u8 *q;
        k = func_L39_005B4468(2.0f, 5.0f);
        r = func_L39_005B43C8(0x32, 0x50);
        p50.x = mid.x + func_L39_005B4468(0.0f, 0.1f);
        p50.y = mid.y + func_L39_005B4468(0.0f, 0.1f);
        p50.z = mid.z + func_L39_005B4468(0.0f, 0.1f);
        sz = func_L39_005B4410(0.35f, 0.75f);
        sp = func_L39_005B4410(4.0f, 8.0f);
        yaw = func_0038DAB8(heading, func_L39_005B4468(0.0f, 1.3962634f));
        sp *= 0.020000001f;
        big = sz * 210000.0f;
        v60.x = func_0038D098(yaw) * sp;
        v60.y = func_0038D0B0(yaw) * sp;
        v60.z = 0.0f;
        v60.z = func_L39_005B4410(0.0f, 12.0f) * 0.020000001f;
        col = (r * 5 + 2) / 6;
        func_L01_0046FB40(&p50, &v60, col, 0x7F7F7F, k, 0x7F, 0x7F, big, 2100.0f, 0.00584f, 1);
        p70.x = p50.x + func_L39_005B4468(0.0f, 0.01f);
        p70.y = p50.y + func_L39_005B4468(0.0f, 0.01f);
        p70.z = p50.z + func_L39_005B4468(0.0f, 0.01f);
        func_L01_0046FB40(&p70, &v60, col, 0x7F7F7F, -k, 0x7F, 0x7F, big, 2100.0f, 0.00584f, 1);
        k *= 2;
        sz *= 6.0f;
        q = func_L01_0046FB40(&p50, &v60, col, 0x202080, -k, 0x30, 0x30, sz * 210000.0f, 4200.0f, 0.00584f, 1);
        if (q != 0) {
            q[2] = *D_L39_00296818[0x35];
        }
    }

    vec_sub_ba(&p50, D_L39_0024DE80, &mid);
    func_0038CF68(&p50, &p50, 1.0f);
    vec_add_ab(&mid, &mid, &p50);

    n = 20;
    switch (a2) {
    case 2:
        n = 10;
        break;
    case 3:
        n = 5;
        break;
    case 4:
        n = 1;
        break;
    }
    for (m = 0; m < n; m++) {
        s32 k;
        s32 r;
        f32 sz;
        u8 *q;
        func_L39_005BC330(&p70, &p70, 0);
        func_0038CE20(&v60, &p70, -(func_L39_005B4410(0.2f, 3.0f) * 0.020000001f));
        r = (func_L39_005B43C8(0x5A, 0xB4) * 5 + 2) / 6;
        k = func_L39_005B4468(1.0f, 2.0f);
        sz = func_L39_005B4410(0.5f, 1.5f) * 210000.0f;
        p80.x = mid.x + func_L39_005B4468(0.0f, 0.75f);
        p80.y = mid.y + func_L39_005B4468(0.0f, 0.75f);
        p80.z = mid.z + func_L39_005B4468(0.0f, 0.75f);
        q = func_L01_004669B0(&p80, 0.0f, 1.0f, 1.01f, k, sz, &v60, 0x7F202020, 1);
        if (q != 0) {
            u8 *data;
            *(s16 *)(q + 0xA) = r;
            q[3] = 0x44;
            q[9] = 0x44;
            data = q + 0x20;
            k = func_L39_005B43C8(7, 0xF);
            *(s32 *)(data + 4) = 3;
            data[0xA] = 0x7F;
            *(f32 *)(data + 0x1C) = (k * 5 + 2) / 6;
            data[0xB] = q[0xA];
        }
    }
}
/* localdecomp:end func_L39_0053FC50 */

INCLUDE_ASM("asm/levels", func_L39_00540570);
