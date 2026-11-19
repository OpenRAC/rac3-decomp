/* functional: medium. From asm; the vector (0,0,-D_L30_001DD5F8) is the 'gravity' term by my reading, not confirmed; n>=3 roots (impossible) leaves t=0 where retail leaves it uninitialised; 173 diff = scheduling */
#include "vu0.h"
extern f32 D_L30_001DD5F8;
extern f32 D_L30_001DD720;
extern f32 D_L30_001DD724;
extern f32 D_L30_001DD728;
__asm__(".extern D_L30_001DD5F8, 4");
__asm__(".extern D_L30_001DD720, 4");
__asm__(".extern D_L30_001DD724, 4");
__asm__(".extern D_L30_001DD728, 4");
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L02_003BA9F8(void *, void *, void *, void *);
extern s32 func_L01_004461B8(f32 *, f32 *, f32, f32, f32);

void func_L30_0034F2D8(u8 *obj, u8 *target) {
    u8 *v = *(u8 **)(obj + 0x68);
    vu0_v4 head;
    vu0_v4 rel;
    vu0_v4 g;
    vu0_v4 parT;
    vu0_v4 perpT;
    vu0_v4 parV;
    vu0_v4 perpV;
    vu0_v4 parG;
    vu0_v4 perpG;
    f32 root[2];
    f32 limit;
    f32 t;
    f32 a;
    f32 b;
    f32 c;
    f32 accel;
    s32 n;
    t = 0.0f;

    if (*(s16 *)(target + 0xAA) == 0x1C83) {
        limit = D_L30_001DD720;
    } else if (*(s16 *)(target + 0xAA) == 0x1974) {
        limit = D_L30_001DD724;
    } else {
        limit = D_L30_001DD728;
    }
    head.x = func_0038D098(*(f32 *)(v + 0x14));
    head.z = func_0038D0B0(*(f32 *)(v + 0x14));
    head.y = 0.0f;
    rel.x = *(f32 *)(target + 0x10) - *(f32 *)(obj + 0x10);
    rel.y = *(f32 *)(target + 0x14) - *(f32 *)(obj + 0x14);
    rel.z = *(f32 *)(target + 0x18) - *(f32 *)(obj + 0x18);
    qzero(&g);
    g.z = -D_L30_001DD5F8;
    func_L02_003BA9F8(&rel, &head, &parT, &perpT);
    func_L02_003BA9F8(v, &head, &parV, &perpV);
    func_L02_003BA9F8(&g, &head, &parG, &perpG);
    a = func_0038CEA8(&perpG) * 0.5f;
    if (func_0038CE68(&perpG, &perpT) < 0.0f) {
        a = -a;
    }
    b = func_0038CEA8(&perpV);
    if (func_0038CE68(&perpV, &perpT) < 0.0f) {
        b = -b;
    }
    n = func_L01_004461B8(&root[0], &root[1], a, b, -func_0038CEA8(&perpT));
    if (n == 0) {
        return;
    }
    if (n == 1) {
        if (!(0.0f < root[0])) {
            return;
        }
        t = root[0];
    } else if (n == 2) {
        if (0.0f < root[1]) {
            t = root[1];
        } else {
            if (!(0.0f < root[0])) {
                return;
            }
            t = root[0];
        }
    }
    a = func_0038CEA8(&parT);
    if (func_0038CE68(&parT, &head) < 0.0f) {
        a = -a;
    }
    b = func_0038CEA8(&parV);
    if (func_0038CE68(&parV, &head) < 0.0f) {
        b = -b;
    }
    c = func_0038CEA8(&parG);
    if (func_0038CE68(&parG, &head) < 0.0f) {
        c = -c;
    }
    accel = (a / (t * t) - b / t) * 2.0f - c;
    if (limit < accel) {
        accel = limit;
    } else if (accel < -limit) {
        accel = -limit;
    }
    func_0038CE20(&head, &head, accel);
    *(f32 *)(v + 0x0) += head.x;
    *(f32 *)(v + 0x4) += head.y;
    *(f32 *)(v + 0x8) += head.z;
}
