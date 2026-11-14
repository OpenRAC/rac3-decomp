#include "common.h"

/* localdecomp:start func_L39_00571780 */
#include "vu0.h"
typedef int Q_00571780 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00571780;
typedef struct {
    u8 pad0[0x20];
    u8 *target[4];
    u8 pad30[0x30];
    f32 f60[4], f70[4], f80[4], f90[4], fA0[4], fB0[4], fC0[4], fD0[4], fE0[4], fF0[4];
    s32 i100[4];
} Cam_00571780;
typedef struct { u8 pad0[0x1C]; Cam_00571780 *cam; } Row_00571780;
typedef struct { u8 pad0[0x18]; u8 *obj; u8 pad1C[4]; V_00571780 v20,v30,v40; } Hit_00571780;
extern Row_00571780 *D_L39_0024B950;
__asm__(".extern D_L39_0024B950, 16");
extern V_00571780 D_L39_00474940[];
__asm__(".extern D_001DFFE0_sda, 4");
extern f32 D_001DFFE0_sda;
extern Hit_00571780 D_L39_0025F840;
extern u8 *func_L39_006197C0(s32);
extern u8 *func_L39_00665D48(u8 *);
extern void func_L01_00445168(f32 *, f32 *, f32, f32, f32, f32);
extern f32 func_00388978(f32);
extern f32 func_00388960(f32);
extern void func_003886E8(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_003888F0(void *, void *, void *);
extern void func_003886C0(void *, void *, void *, f32);
extern u8 *func_0037E0B8(void *);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_L01_003F9498(void *, s32, void *, f32);

void func_L39_00571780(u8 *a0)
{
    V_00571780 off, pos, up, targetPos, oldPos, temp, axis, side, basis[2], delta, last;
    s32 p, smooth, hit;
    Cam_00571780 *cam;
    u8 *pl, *obj, *state, *vehicle, *move, *tgt, *m, *data;
    f32 *h;
    f32 angle, height, extra, sn, cs, x, z;
    p = *(s32 *)(a0 + 0x94);
    smooth = 0;
    cam = D_L39_0024B950[*(s16 *)(a0 + 0x84)].cam;
    angle = 0.0f;
    extra = 0.0f;
    height = 0.0f;
    *(Q_00571780 *)&up = 0;
    up.z = 1.0f;
    up.w = 1.0f;
    pl = func_L39_006197C0(p);
    qzero(&off);
    tgt = cam->target[p];
    if (tgt != 0) {
        obj = tgt;
        state = func_L39_00665D48(obj);
        off = D_L39_00474940[*(s16 *)(state + 0x2FC)];
        if (*(s16 *)(obj + 0xAA) == 0x107E) {
            m = *(u8 **)(obj + 0x68);
            angle = *(f32 *)(m + 0x350);
            up = *(V_00571780 *)(m + 0x3C0);
        } else if (*(s16 *)(obj + 0xAA) == 0x107C || *(s16 *)(obj + 0xAA) == 0x1A17) {
            vehicle = *(u8 **)(*(u8 **)(state + 0x2D0) + 0x68);
            x = 0.0f;
            height = 0.0f;
            smooth = 1;
            if (*(s16 *)(obj + 0xAA) == 0x1A17) {
                off.x = 7.0f;
                off.y = 0.0f;
                off.z = 2.5f;
                off.w = 1.0f;
            } else {
                off = D_L39_00474940[*(s16 *)(state + 0x2FC)];
            }
            if (*(u8 *)(state + 0x300)) {
                x = 15.0f;
                height = 1.5f;
            }
            func_L01_00445168(&cam->f60[p], &cam->f70[p], x, 0.0014544411096721888f, 0.019392548f, 0.0f);
            func_L01_00445168(&cam->f80[p], &cam->f90[p], height, 0.0035f, 0.1f, 0.0f);
            extra = cam->f80[p];
            angle = cam->f60[p] * 0.017453292f;
            cam->i100[p]++;
            if (*(u8 *)(vehicle + 0x713) == 0 &&
                *(f32 *)(*(u8 **)(vehicle + 0x720) + 0xC) * 0.0166666675f < *(f32 *)(state + 0x310) &&
                cam->i100[p] < 50) {
                if (*(u8 *)(state + 0x300))
                    cam->fC0[p] = -1.25f;
                else
                    cam->fC0[p] = -0.5f;
            } else {
                cam->fC0[p] = -1.5f;
            }
            if (cam->fA0[p] == D_001DFFE0_sda)
                cam->i100[p] = 0;
            height = cam->fC0[p];
        }
    } else {
        obj = *(u8 **)(pl + 0x2524);
    }
    targetPos = *(V_00571780 *)(obj + 0x10);
    if (smooth) {
        func_L01_00445168(&cam->fE0[*(s32 *)(a0 + 0x94)], &cam->fF0[*(s32 *)(a0 + 0x94)], targetPos.z, 0.11111111f, 0.041666668f, 0.0f);
        targetPos.z = cam->fE0[*(s32 *)(a0 + 0x94)];
    } else {
        cam->fE0[*(s32 *)(a0 + 0x94)] = targetPos.z;
    }
    off.x += extra + height;
    move = *(u8 **)(a0 + 0x70);
    h = (f32 *)(move + 0x70);
    oldPos = *(V_00571780 *)(a0 + 0x30);
    if (angle != 0.0f) {
        sn = func_00388978(angle);
        cs = func_00388960(angle);
        temp = off;
        off.x = cs * temp.x - sn * temp.z;
        off.y = temp.y;
        off.z = sn * temp.x + cs * temp.z;
    }
    func_003886E8(&axis, obj + 0xC0, -1.0f);
    basis[1] = targetPos;
    basis[0] = up;
    func_00388758(&side, &axis, &up);
    func_00388830(&side, &side, 1.0f);
    func_00388758(&axis, basis, &side);
    func_003888F0(&temp, &off, &axis);
    vec_sub_ab(&delta, &temp, &targetPos);
    func_003886C0(h, h, &delta, 0.045f);
    up = *(V_00571780 *)(move + 0x70);
    vec_add_ab(a0 + 0x30, &targetPos, &up);
    qzero(&pos);
    data = func_0037E0B8(obj);
    if (data)
        func_003886E8(&pos, obj + 0xE0, *(f32 *)(data + 0x10));
    vec_add_ab(&pos, &pos, &targetPos);
    hit = 0;
    if (func_003CE740(&pos, a0 + 0x30, 4, obj, 0)) {
        if (!D_L39_0025F840.obj || *(s16 *)(D_L39_0025F840.obj + 0xAA) == 0x1AD6) {
            vec_sub_ab(&temp, &pos, &D_L39_0025F840.v20);
            func_00388830(&up, &temp, 0.02f);
            hit = 1;
            vec_add_ab(a0 + 0x30, &D_L39_0025F840.v20, &up);
        }
    }
    if (!hit && func_003CE740(&oldPos, a0 + 0x30, 4, 0, 0)) {
        if (!D_L39_0025F840.obj || *(s16 *)(D_L39_0025F840.obj + 0xAA) == 0x1AD6) {
            vec_sub_ab(&temp, &oldPos, &D_L39_0025F840.v20);
            func_00388830(&up, &temp, 0.02f);
            vec_add_ab(a0 + 0x30, &D_L39_0025F840.v20, &up);
        }
    }
    if (func_L01_003F9498(a0 + 0x30, 4, 0, 0.25f)) {
        if (!D_L39_0025F840.obj)
            *(V_00571780 *)(a0 + 0x30) = D_L39_0025F840.v30;
        if (D_L39_0025F840.obj && *(s16 *)(D_L39_0025F840.obj + 0xAA) == 0x1AD6) {
            func_00388830(&last, &D_L39_0025F840.v40, 1.0f);
            func_003886E8(&last, &last, 0.25f);
            vec_add_ab(a0 + 0x30, a0 + 0x30, &last);
        }
    }
}
/* localdecomp:end func_L39_00571780 */
