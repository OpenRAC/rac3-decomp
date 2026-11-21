/* functional: medium. Hand-written from asm; every branch read against it (target drop checks, spin rotation chain, close-range snap, bounds, hit record rules rec+0x18/0x1C, face test, expiry path). */
#include "structs/weapon.h"
extern struct WeaponRow D_L01_002C5600[];
extern u8 D_001425C0[];
extern u8 D_L01_001E0140[];
extern u8 D_L01_001EAA00[];
extern u8 D_L01_001EAA20[];
extern u8 D_L01_001EAA40[];
extern u8 D_L01_001E29C0[];
extern u8 D_001A30B0[];
extern u8 D_001A4C60[];
extern s32 D_L01_001DAFEC;
extern void func_003C5180(void *, void *, s32);
extern s32 func_L01_004CB2D8(void);
extern void func_L01_004CAB30(void *, void *);
extern u8 *func_00382348(void *);
extern void func_L01_004C8688(s32, void *, s32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_L01_004CB128(void *, void *, s32);
extern void func_L01_0044BEC8(void *, void *);
extern void func_L01_003303B8(void *pos, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7,
                              s32 s0, s32 s1, s32 s2, s32 s3, s32 s4, s32 s5, s32 s6, s32 s7, s32 s8,
                              s32 s9, s32 s10, s32 s11, s32 s12, s32 s13, s32 s14, s32 s15, s32 s16, s32 s17,
                              f32 f0, f32 f1, f32 f2, f32 f3);
extern void func_L01_00385188(void *, void *);
extern void func_L01_003851F8(void);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_00384F48(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_003C3D30(void *, s32, s32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00384E68(void *, void *, void *);
extern void func_L01_004C8668(s32);
extern void func_003C2880(void *);
extern s32 func_0038CB00(void *);
extern void func_003A4F28(s32);

void func_L01_00384518(u8 *obj) {
    u8 *hero = (u8 *)&D_001A4BE0;
    u8 *d = *(u8 **)(obj + 0x68);
    u8 *target = *(u8 **)(d + 0x10);
    u8 *pos = obj + 0x10;
    u8 *fwd = obj + 0xC0;
    u8 *up = obj + 0xD0;
    u8 *side = obj + 0xE0;
    f32 old_pos[4] __attribute__((aligned(16)));    /* sp+0x90 */
    f32 ground[8] __attribute__((aligned(16)));     /* sp+0xA0: surface normal, then more */
    f32 step[4] __attribute__((aligned(16)));       /* sp+0xC0 */
    f32 rot[4] __attribute__((aligned(16)));        /* sp+0xD0 */
    f32 tmp[4] __attribute__((aligned(16)));        /* sp+0xE0 */
    f32 tmp2[4] __attribute__((aligned(16)));       /* sp+0xF0 */
    u8 hitinfo[0x40] __attribute__((aligned(16)));  /* sp+0x100 .. 0x13F */
    f32 hit_normal[4] __attribute__((aligned(16))); /* sp+0x140 */
    f32 to_cam[4] __attribute__((aligned(16)));     /* sp+0x150 */
    void *hit_moby = 0;                             /* sp+0x160 */

    old_pos[0] = ((f32 *)pos)[0]; old_pos[1] = ((f32 *)pos)[1]; old_pos[2] = ((f32 *)pos)[2]; old_pos[3] = ((f32 *)pos)[3];
    func_003C5180(pos, ground, 1);
    if (func_L01_004CB2D8() != 0) func_L01_004CAB30(pos, pos);

    if (target != 0) {
        u8 *rec = func_00382348(target);
        u8 t = target[0x20];
        s32 drop = 0;
        if (t == 0xFE || t == 0xFD) drop = 1;
        else if (rec != 0 && *(f32 *)rec <= 0.0f) drop = 1;
        else if (*(u16 *)(target + 0x34) & 2) drop = 1;
        else if (target[0x31] == 0) drop = 1;
        if (drop) {
            *(s32 *)(d + 0x10) = 0;
            target = 0;
        }
    }
    func_L01_004C8688(*(s32 *)(d + 0x54), d + 0x30, 0);
    *(f32 *)(fwd + 0) = *(f32 *)(d + 0x30);
    *(f32 *)(fwd + 4) = *(f32 *)(d + 0x34);
    *(f32 *)(fwd + 8) = *(f32 *)(d + 0x38);
    *(f32 *)(fwd + 12) = *(f32 *)(d + 0x3C);
    func_0038CE90(up, fwd, ground);
    func_0038CF68(up, up, 1.0f);
    func_0038CE90(side, up, fwd);
    if (target != 0) {
        *(f32 *)(d + 0) = ground[4];
        *(f32 *)(d + 4) = ground[5];
        *(f32 *)(d + 8) = ground[6];
    }

    if ((*(f32 *)(d + 0x1C) < 0.0f ? -*(f32 *)(d + 0x1C) : *(f32 *)(d + 0x1C)) > 0.003100000089034438f) {
        step[0] = ((f32 *)fwd)[0]; step[1] = ((f32 *)fwd)[1]; step[2] = ((f32 *)fwd)[2]; step[3] = ((f32 *)fwd)[3];
        func_003C4840(rot, up, *(f32 *)(d + 0x1C) * 0.01745329238474369f);
        func_0038D850(fwd, fwd, rot);
        func_0038D850(side, side, rot);
        func_003C4840(rot, step, *(f32 *)(d + 0x28));
        func_0038D850(fwd, fwd, rot);
        func_0038D850(up, up, rot);
        func_0038D850(side, side, rot);
        func_003C4840(rot, fwd, *(f32 *)(d + 0x28));
        func_0038D850(up, up, rot);
        func_0038D850(side, side, rot);
        *(f32 *)(d + 0x28) = func_0038DAB8(*(f32 *)(d + 0x28), *(f32 *)(d + 0x20) * 0.01745329238474369f);
    }
    ((f32 *)fwd)[3] = 0.0f;
    ((f32 *)side)[3] = 0.0f;
    ((f32 *)up)[3] = 0.0f;

    if (target != 0) {
        func_0038CE20(step, fwd, *(f32 *)(d + 0x18));
        /* vadd.xyz: pos.xyz += step.xyz */
        ((f32 *)pos)[0] = ((f32 *)pos)[0] + step[0];
        ((f32 *)pos)[1] = ((f32 *)pos)[1] + step[1];
        ((f32 *)pos)[2] = ((f32 *)pos)[2] + step[2];
        if (func_0038CF00(target + 0x10, pos) < 5.0f) {
            func_L01_004CB128(tmp, target, 0);
            rot[0] = tmp[0] - ((f32 *)pos)[0];
            rot[1] = tmp[1] - ((f32 *)pos)[1];
            rot[2] = tmp[2] - ((f32 *)pos)[2];
            rot[3] = tmp[3];
            func_0038CF68(step, rot, *(f32 *)(d + 0x18));
            ((f32 *)pos)[0] = ((f32 *)pos)[0] + step[0];
            ((f32 *)pos)[1] = ((f32 *)pos)[1] + step[1];
            ((f32 *)pos)[2] = ((f32 *)pos)[2] + step[2];
            func_L01_004CAB30(pos, pos);
        }
    } else {
        func_0038CE20(step, fwd, *(f32 *)(d + 0x18));
        ((f32 *)pos)[0] = ((f32 *)pos)[0] + step[0];
        ((f32 *)pos)[1] = ((f32 *)pos)[1] + step[1];
        ((f32 *)pos)[2] = ((f32 *)pos)[2] + step[2];
    }

    if (((f32 *)pos)[0] < 2.0f || ((f32 *)pos)[0] > 1021.0f ||
        ((f32 *)pos)[1] < 2.0f || ((f32 *)pos)[1] > 1021.0f ||
        ((f32 *)pos)[2] < 2.0f || ((f32 *)pos)[2] > 1021.0f) {
        func_L01_0044BEC8(obj, D_L01_001E0140);
        func_L01_003303B8(pos, 0, 7, 0, 0, 3, 3, 0,
                          0, 1, 0, 0, 0, 0, 0, D_L01_001DAFEC, 0xF78E38, 0xF76300, 0xFF7F40,
                          0xFF2000, 0xFF8F00, 0xFF6430, 0x7FFFA060, 0x28FF0000, 0xFF6430, 0,
                          0.2f, 0.0f, 0.0f, 0.0f);
        func_003C2880(obj);
        return;
    }

    func_L01_00385188(obj, rot);
    d[0x27] = d[0x27] + 1;
    if (d[0x27] >= 4) func_L01_00404A10((void *)func_L01_003851F8, obj);
    func_L01_00384F48(obj, old_pos);

    tmp[0] = ((f32 *)pos)[0]; tmp[1] = ((f32 *)pos)[1]; tmp[2] = ((f32 *)pos)[2]; tmp[3] = ((f32 *)pos)[3];
    func_0038CE20(tmp2, ground, -0.30000001192092896f);
    tmp2[0] = ((f32 *)pos)[0] + tmp2[0];
    tmp2[1] = ((f32 *)pos)[1] + tmp2[1];
    tmp2[2] = ((f32 *)pos)[2] + tmp2[2];
    tmp2[3] = ((f32 *)pos)[3];
    if (func_003D3CB0(tmp, tmp2, 2, 0, 0) != 0) {
        func_0038CE20(tmp, ground, 0.30000001192092896f);
        ((f32 *)pos)[0] = ((f32 *)D_L01_001EAA20)[0] + tmp[0];
        ((f32 *)pos)[1] = ((f32 *)D_L01_001EAA20)[1] + tmp[1];
        ((f32 *)pos)[2] = ((f32 *)D_L01_001EAA20)[2] + tmp[2];
        ((f32 *)pos)[3] = ((f32 *)D_L01_001EAA20)[3];
    }

    *(s32 *)(hitinfo + 0x14) = 0x1030000;
    *(s32 *)(hitinfo + 0x20) = 1;
    *(u8 **)(hitinfo + 0x10) = obj;
    *(f32 *)(hitinfo + 0x1C) = D_L01_002C5600[D_001425C0[0x97]].damage;
    if (*(u16 *)(obj + 0x34) & 0x100) {
        *(f32 *)(hitinfo + 0x30) = step[0]; *(f32 *)(hitinfo + 0x34) = step[1];
        *(f32 *)(hitinfo + 0x38) = step[2]; *(f32 *)(hitinfo + 0x3C) = step[3];
    } else {
        *(f32 *)(hitinfo + 0x30) = func_0038D098(*(f32 *)(obj + 0xF8));
        *(f32 *)(hitinfo + 0x34) = func_0038D0B0(*(f32 *)(obj + 0xF8));
        *(s32 *)(hitinfo + 0x38) = 0;
    }
    *(f32 *)(hitinfo + 0x3C) = 5627.9248046875f;
    *(f32 *)(hitinfo + 0x38) = 1.5f;
    {
        /* sp+0x130 is copied to sp+0x100 and normalised to length 1 */
        *(f32 *)(hitinfo + 0x00) = *(f32 *)(hitinfo + 0x30);
        *(f32 *)(hitinfo + 0x04) = *(f32 *)(hitinfo + 0x34);
        *(f32 *)(hitinfo + 0x08) = *(f32 *)(hitinfo + 0x38);
        *(f32 *)(hitinfo + 0x0C) = *(f32 *)(hitinfo + 0x3C);
    }
    func_0038CF68(hitinfo, hitinfo, 1.0f);
    *(s16 *)(hitinfo + 0x1A) = *(u16 *)(obj + 0xAA);
    *(f32 *)(hitinfo + 0x0C) = 5627.9248046875f;
    hitinfo[0x18] = 3;
    hitinfo[0x19] = 1;
    if (func_003D3CB0(old_pos, pos, 0, *(void **)(hero + 0x25C0), hitinfo) != 0) {
        u8 *rec = D_L01_001EAA00;
        u8 *hit = *(u8 **)(rec + 0x18);
        if (hit == 0) {
            if (*(s32 *)(rec + 0x1C) > 0) {
                obj[0xBC] = 1;
                goto copy_hit_pos;
            }
        } else if (hit != *(u8 **)(hero + 0x25C0)) {
            if (hit != *(u8 **)(d + 0xC)) {
                hit_moby = obj;
                obj[0xBC] = 2;
            copy_hit_pos:
                *(f32 *)(pos + 0) = *(f32 *)(rec + 0x20);
                *(f32 *)(pos + 4) = *(f32 *)(rec + 0x24);
                *(f32 *)(pos + 8) = *(f32 *)(rec + 0x28);
                *(f32 *)(pos + 12) = *(f32 *)(rec + 0x2C);
            }
        }
    }

    if (obj[0xBC] != 0) {
        s32 face = 1;
        u8 *rec;
        *(f32 *)(pos + 0) = *(f32 *)(D_L01_001EAA20 + 0);
        *(f32 *)(pos + 4) = *(f32 *)(D_L01_001EAA20 + 4);
        *(f32 *)(pos + 8) = *(f32 *)(D_L01_001EAA20 + 8);
        *(f32 *)(pos + 12) = *(f32 *)(D_L01_001EAA20 + 12);
        func_003C5180(pos, hit_normal, 1);
        rec = D_L01_001EAA20 - 0x20;
        if (*(s32 *)(rec + 0x18) == 0 || *(s32 *)(rec + 0x1C) > 0) {
            f32 dot;
            func_0038CF68(to_cam, D_L01_001EAA40, 1.0f);
            dot = func_0038CE68(to_cam, hit_normal);
            if ((dot < 0.0f ? -dot : dot) >= 0.10000000149011612f) face = 0;
        } else {
            to_cam[0] = ((f32 *)D_L01_001E29C0)[0] - ((f32 *)pos)[0];
            to_cam[1] = ((f32 *)D_L01_001E29C0)[1] - ((f32 *)pos)[1];
            to_cam[2] = ((f32 *)D_L01_001E29C0)[2] - ((f32 *)pos)[2];
            to_cam[3] = ((f32 *)D_L01_001E29C0)[3];
            func_0038CF68(to_cam, to_cam, 1.0f);
        }
        if (face != 0) func_003C3D30(pos, 0, 0, 0.5f);
        func_L01_003303B8(pos, 0, 7, 0, 0, 3, 3, 0,
                          0, 1, 0, 0, 0, 0, 0, D_L01_001DAFEC, 0xF78E38, 0xF76300, 0xFF7F40,
                          0xFF2000, 0xFF8F00, 0xFF6430, 0x7FFFA060, 0x28FF0000, 0xFF6430, 0,
                          0.2f, 0.0f, 0.0f, 0.0f);
        func_003A52A0(0, 0, obj);
        func_L01_00384E68(obj, hit_normal, hit_moby);
        func_L01_0044BEC8(obj, D_L01_001E0140);
        func_L01_004C8668(*(s32 *)(d + 0x54));
        func_003C2880(obj);
        return;
    }

    {
        s32 expired = func_0038CB00(d + 0x24);
        if (expired == 0) {
            if (!(60.0f < func_0038CF38(pos, D_001A4C60))) return;
        }
        {
            s32 slot = *(s32 *)(d + 0x50);
            s32 clear = -1;
            if (slot != -1) {
                u8 *r = D_001A30B0 + slot * 128;
                if (*(u8 **)(r + 0xDC) == obj && r[0xD0] != 0) func_003A4F28(slot);
            }
            *(s32 *)(d + 0x50) = clear;
            func_L01_0044BEC8(obj, D_L01_001E0140);
            func_L01_004C8668(*(s32 *)(d + 0x54));
            func_003C2880(obj);
        }
    }
}
