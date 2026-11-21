/* functional: medium. Written from the asm by hand (compiles, 0xB0 stack vs 0xE0 retail); callee semantics inferred, names generic. Unrun-block risk: long-lived paths (level 3/>=4 weapon-finish branch, inactive path) read against asm only. */
#include "structs/weapon.h"
extern struct WeaponRow D_L01_002C5600[];
extern u8 D_001425C0[];
extern u8 D_L01_001E2880[];
extern u8 D_L01_001E29C0[];
extern u8 D_L01_001F1B40[];
extern u8 D_001A30B0[];
extern u8 D_L01_001DDBA0[];
extern s32 D_L01_001E1DC0, D_L01_001E1DC4, D_L01_001E1DC8, D_L01_001E1DCC;
extern f32 D_L01_001DDB88, D_L01_001DDB98, D_L01_001DDB9C, D_L01_001DDBBC;
extern s32 D_L01_001DDB8C, D_L01_001DDB90, D_L01_001DDB94, D_L01_001DDBB0;
extern u8 *D_001D52FC_sda;
extern void func_0038CB00(void *);
extern s32 func_0038CAD0(void *);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_005003D0(s32, s32);
extern void func_0038D590(void *, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L01_0037E8F0(void *, void *, void *, void *);
extern void func_L01_004CB128(void *, s32, s32);
extern void func_L01_003F6F20(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_004EA7D8(s32);
extern u8 *func_00382348(s32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_L01_00451D38(void *, s32, s32, f32);
extern void func_L01_00421988(s32, s32, s32, s32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_003DA3F0(s32, void *);
extern void func_L01_0039FBD0(s32);
extern void func_L01_003D3EE0(s32);
extern void func_L01_0037F948(void *);
extern s32 func_L01_00424B88(void *, u32, f32, f32);
extern s32 func_L01_004AA710(void *, s32);
extern void func_003A4F28(s32);
extern void func_L01_004EAA80(void);
extern void func_L01_00424D88(s32);

void func_L01_0037EFC8(u8 *obj) {
    extern u8 D_001A4BE0[];
    u8 *hero = D_001A4BE0;
    u8 *d = *(u8 **)(obj + 0x68);
    f32 v0[4] __attribute__((aligned(16)));   /* sp+0x00 */
    f32 v1[4] __attribute__((aligned(16)));   /* sp+0x10 */
    f32 v2[4] __attribute__((aligned(16)));   /* sp+0x20 */
    f32 v4[4] __attribute__((aligned(16)));   /* sp+0x40 */
    s32 holding = (*(s32 *)(hero + 0x1224) == 3);
    s32 level;
    s32 active = 1;
    s32 target;

    if (obj[0x20] == 0) {
        obj[0x20] = 1;
        D_L01_001E1DCC = -1;
        D_L01_001E1DC4 = -1;
        D_L01_001E1DC8 = 0;
    }
    level = D_L01_002C5600[D_001425C0[0x8F]].level;
    if (level == 3) *(s16 *)(obj + 0x7C) = 7;
    else if (level == 2) *(s16 *)(obj + 0x7C) = 3;
    else if (level == 1) *(s16 *)(obj + 0x7C) = 1;
    func_0038CB00(d + 0x1C);
    if (*(s32 *)(hero + 0x25C4) == 29) {
        active = (func_0038CAD0(hero + 0x28BC) != 0);
    } else {
        *(s32 *)(hero + 0x28BC) = 0x21;
    }
    func_0038D000(d, D_L01_001DDBA0, obj + 0xC0);
    /* vadd.xyz: d.xyz += obj.pos.xyz, d.w kept */
    ((f32 *)d)[0] = ((f32 *)d)[0] + *(f32 *)(obj + 0x10);
    ((f32 *)d)[1] = ((f32 *)d)[1] + *(f32 *)(obj + 0x14);
    ((f32 *)d)[2] = ((f32 *)d)[2] + *(f32 *)(obj + 0x18);
    if (*(s32 *)(hero + 0x25C4) == 1) func_L01_005003D0(29, 1);
    v0[0] = v0[1] = v0[2] = v0[3] = 0.0f;
    if (*(s32 *)(hero + 0x25C4) == 29 && (*(u16 *)(*(u8 **)(hero + 0x25C0) + 0x34) & 1)) {
        func_0038D590(v1, D_L01_001E2880);
        func_0038D5B0(v4, v1);
        v0[2] = 1.0f;
        func_0038D028(v0, v0, v4);
    } else if (*(s16 *)(hero + 0x2874) == 1) {
        func_0038CE20(v0, obj + 0xD0, -1.0f);
    } else {
        v0[0] = 1.0f;
        func_0038D000(v0, v0, hero + 0x6C0);
    }
    *(f32 *)(d + 0x48) = func_0038D160(v0[0], v0[1]);
    {
        f32 len = func_0038CED8(v0);
        *(f32 *)(d + 0x4C) = func_0038D160(len, v0[2]);
    }
    *(f32 *)(v1 + 0) = ((f32 *)d)[0]; v1[1] = ((f32 *)d)[1]; v1[2] = ((f32 *)d)[2]; v1[3] = ((f32 *)d)[3];
    target = func_L01_0037E8F0(obj, v1, d + 0x48, d + 0x4C);
    if (target != 0) {
        func_L01_004CB128(v1, target, 0);
        if (*(s32 *)(hero + 0x25C4) != 29 && *(s32 *)(hero + 0x16B0) == 0) {
            f32 dist = func_0038CF00(D_L01_001E29C0, v1) / 150.0f;
            f32 ang = func_0038DAB8(*(f32 *)(d + 0x54), 0.03490658476948738f);
            f32 w;
            dist = dist * 0.6499999761581421f;
            *(f32 *)(d + 0x54) = ang;
            w = 0.8999999761581421f - dist;
            if (w < 0.0f) w = -w;
            func_L01_003F6F20(0, obj, 0xFF0FFF0F, v1, 0x26, -1, 4, w, -ang, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        }
    }
    if (*(u32 *)(hero + 0x25CC) < 2) {
        if ((*(u32 *)(D_001D52FC_sda + 0x1A0) & *(u32 *)(hero + 0x1210)) == 0 || active == 0) {
            *(s32 *)(d + 0x10) = 0;
            goto inactive;
        }
        if (hero[0x25E9] == 0) func_L01_004EA7D8(-1);
        if (*(s16 *)(d + 0x1E) == 0) *(s16 *)(d + 0x1E) = 1;
        if (*(s16 *)(d + 0x1C) == 0) *(s16 *)(d + 0x1C) = 12;
        func_0038CAD0(d + 0x44);
        if (*(s32 *)(d + 0x10) != 0) {
            u8 t = (*(u8 **)(d + 0x10))[0x20];
            if (t == 0xFE || t == 0xFD) {
                *(s32 *)(d + 0x10) = 0;
                *(s32 *)(d + 0x44) = 0;
            }
        }
        if (target != 0) {
            u8 *rec = func_00382348(target);
            if (target != *(s32 *)(d + 0x10) && *(s32 *)(d + 0x44) == 0) {
                f32 n;
                *(s32 *)(d + 0x10) = target;
                n = (f32)*(s16 *)(rec + 4);
                *(f32 *)(d + 0x14) = n;
                *(s32 *)(d + 0x44) = 25;
                *(f32 *)(d + 0x18) = *(f32 *)rec;
                if (n <= 1.0f) *(f32 *)(d + 0x18) = 0.0f;
            }
            goto drain;
        } else if (*(s32 *)(d + 0x44) != 0) {
        drain: {
            f32 dmg = D_L01_002C5600[D_001425C0[0x8F]].damage;
            f32 left;
            D_L01_001DDB88 = dmg;
            left = *(f32 *)(d + 0x18) - dmg * 0.020000001415610313f;
            *(f32 *)(d + 0x18) = left;
            if (left < 0.0f) *(f32 *)(d + 0x18) = 0.0f;
            D_L01_001DDBBC = *(f32 *)(d + 0x18) / *(f32 *)(d + 0x14);
        }
        } else {
            D_L01_001DDBBC = 1.0f;
        }
        {
            f32 a = func_003C4088(D_L01_001DDB98, D_L01_001DDB9C, D_L01_001DDBBC);
            s32 r = func_L01_00451D38(d + 0x50, D_L01_001DDB90, D_L01_001DDB94, (a * 0.01745329238474369f) * 0.020000001415610313f);
            func_L01_00421988(1, r, 0, 0, D_L01_001DDBBC);
        }
        if (*(s32 *)(d + 0x10) != 0 && *(f32 *)(d + 0x18) <= 0.0f) {
            s32 lv;
            func_003A52A0(1, 0, obj);
            lv = D_L01_002C5600[D_001425C0[0x8F]].level;
            if (lv == 3) {
                func_L01_0039FBD0(*(s32 *)(d + 0x10));
            } else if (lv < 4) {
                func_L01_003D3EE0(*(s32 *)(d + 0x10));
            } else if (D_L01_001DDBB0 == 0) {
                func_L01_0039FBD0(*(s32 *)(d + 0x10));
            } else {
                func_L01_003DA3F0(*(s32 *)(d + 0x10), obj + 0x10);
            }
            D_L01_001DDB8C = D_L01_001DDB8C + 1;
            *(s32 *)(d + 0x10) = 0;
        }
        func_L01_0037F948(obj);
        if (D_L01_001E1DC4 == -1) {
            u32 color = (D_L01_002C5600[D_001425C0[0x8F]].level < 4) ? 0x804020 : 0x204080;
            D_L01_001E1DC4 = func_L01_00424B88(obj + 0x10, color, 7.5f, 0.0f);
        }
        if (D_L01_001E1DC4 >= 0) {
            D_L01_001E1DC8 = 17;
            func_0038CF68(v1, obj + 0xD0, -0.5f);
            v2[0] = ((f32 *)d)[0] + v1[0];
            v2[1] = ((f32 *)d)[1] + v1[1];
            v2[2] = ((f32 *)d)[2] + v1[2];
            v2[3] = ((f32 *)d)[3];
            {
                f32 *slot = (f32 *)(D_L01_001F1B40 + D_L01_001E1DC4 * 32);
                slot[4] = v2[0];
                slot[7] = 7.5f;
                slot[5] = v2[1];
                slot[6] = v2[2];
            }
        }
        if (func_L01_004AA710(obj, D_L01_001E1DCC) == 0) {
            D_L01_001E1DCC = func_003A52A0(0, 4, obj);
        }
        goto tail;
    }
    *(s32 *)(d + 0x10) = 0;
inactive:
    *(s16 *)(d + 0x1E) = 0;
    *(s32 *)(d + 0x44) = 0;
    D_L01_001E1DC0 = 1;
    if (D_L01_001E1DC4 >= 0) {
        f32 sc;
        f32 *slot;
        func_0038CF68(v1, obj + 0xD0, -0.5f);
        sc = (f32)D_L01_001E1DC8 * 0.05000000074505806f;
        v2[0] = ((f32 *)d)[0] + v1[0];
        v2[1] = ((f32 *)d)[1] + v1[1];
        v2[2] = ((f32 *)d)[2] + v1[2];
        slot = (f32 *)(D_L01_001F1B40 + D_L01_001E1DC4 * 32);
        slot[0] = sc;
        slot[4] = v2[0];
        slot[5] = v2[1];
        slot[6] = v2[2];
        slot[7] = 7.5f;
        slot[2] = sc * 0.25f;
        slot[1] = sc;
    }
    if (func_0038CAD0(&D_L01_001E1DC8) != 0) {
        func_L01_00424D88(D_L01_001E1DC4);
        D_L01_001E1DC4 = -1;
    }
    if (D_L01_001E1DC4 >= 0 && D_L01_001E1DC8 == 0) {
        func_L01_00424D88(D_L01_001E1DC4);
        D_L01_001E1DC4 = -1;
    }
    if (D_L01_001E1DCC >= 0) {
        u8 *rec = D_001A30B0 + D_L01_001E1DCC * 128;
        if (D_L01_001E1DCC != -1 && *(u8 **)(rec + 0xDC) == obj && rec[0xD0] != 0) func_003A4F28(D_L01_001E1DCC);
        D_L01_001E1DCC = -1;
        func_L01_004EAA80();
    } else {
        func_L01_004EAA80();
    }
tail:
    if (holding && D_L01_001E1DC4 >= 0) {
        func_L01_00424D88(D_L01_001E1DC4);
        D_L01_001E1DC4 = -1;
    }
}
