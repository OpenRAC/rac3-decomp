#include "common.h"

typedef struct {
    s16 id;
    s16 h2;
    u16 flags;
    u8 pad6[4];
    s16 hA;
    u8 padC[0x18 - 0xC];
    f32 x;
    f32 y;
    f32 z;
    s32 w24;
} E_00438028;

typedef struct {
    u8 pad0[0x20];
    E_00438028 *ents;
    u8 pad24[0x1A8 - 0x24];
    s32 a1A8[61];
    s32 a29C[1];
} M_00438028;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u8 flag;
    u8 pad[3];
} T_00438028;

typedef struct {
    u8 pad0[0x10];
    f32 x;
    f32 y;
    u8 pad18[0xF8 - 0x18];
    f32 z;
} U_00438028;

typedef struct {
    u8 pad0[0x80];
    f32 x;
    f32 y;
    f32 z;
} G_00438028;

extern M_00438028 D_L01_001F3FA0_00438028;
extern s32 D_001D545C;
extern u8 D_001D5570[];
extern s32 D_L01_002E9AE0[];
extern G_00438028 D_001A4BE0;
extern T_00438028 D_00143230[];
extern u8 D_0014323C[];
extern U_00438028 *D_L01_001EFE20_00438028[];
typedef struct {
    u8 *p;
} P_001DFF38;
extern P_001DFF38 D_L01_001DFF38;
extern u8 D_L01_001D7B6C;
__asm__(".extern D_L01_001D7B6C, 1");
extern u8 D_L01_001D7B78;
__asm__(".extern D_L01_001D7B78, 1");
extern f32 D_L01_001D76E0;
__asm__(".extern D_L01_001D76E0, 4");
extern f32 D_L01_001D76E4;
__asm__(".extern D_L01_001D76E4, 4");
extern f32 D_L01_001D76E8;
__asm__(".extern D_L01_001D76E8, 4");
extern f32 D_L01_001D76EC;
__asm__(".extern D_L01_001D76EC, 4");
extern f32 D_L01_001D76F0;
__asm__(".extern D_L01_001D76F0, 4");
extern f32 D_L01_001D76F4;
__asm__(".extern D_L01_001D76F4, 4");
extern f32 D_L01_001D76F8;
__asm__(".extern D_L01_001D76F8, 4");
extern f32 D_L01_001D76FC;
__asm__(".extern D_L01_001D76FC, 4");
extern f32 D_L01_001D7700;
__asm__(".extern D_L01_001D7700, 4");
extern f32 D_L01_001D7704;
__asm__(".extern D_L01_001D7704, 4");
extern f32 D_L01_001D7708;
__asm__(".extern D_L01_001D7708, 4");
extern f32 D_L01_001D770C;
__asm__(".extern D_L01_001D770C, 4");
extern f32 D_L01_001D7710;
__asm__(".extern D_L01_001D7710, 4");
extern f32 D_L01_001D7714;
__asm__(".extern D_L01_001D7714, 4");
extern f32 D_L01_001D7718;
__asm__(".extern D_L01_001D7718, 4");
extern f32 D_L01_001D771C;
__asm__(".extern D_L01_001D771C, 4");
extern f32 D_L01_001D7720;
__asm__(".extern D_L01_001D7720, 4");
extern f32 D_L01_001D7724;
__asm__(".extern D_L01_001D7724, 4");
extern f32 D_L01_001D7728;
__asm__(".extern D_L01_001D7728, 4");
extern f32 D_L01_001D772C;
__asm__(".extern D_L01_001D772C, 4");
extern f32 D_L01_001D7730;
__asm__(".extern D_L01_001D7730, 4");
extern f32 D_L01_001D7734;
__asm__(".extern D_L01_001D7734, 4");
extern f32 D_L01_001D7738;
__asm__(".extern D_L01_001D7738, 4");
extern f32 D_L01_001D773C;
__asm__(".extern D_L01_001D773C, 4");
extern f32 D_L01_001D7740;
__asm__(".extern D_L01_001D7740, 4");
extern f32 D_L01_001D7744;
__asm__(".extern D_L01_001D7744, 4");
extern f32 D_L01_001D7748;
__asm__(".extern D_L01_001D7748, 4");
extern f32 D_L01_001D774C;
__asm__(".extern D_L01_001D774C, 4");
extern f32 D_L01_001D7750;
__asm__(".extern D_L01_001D7750, 4");
extern f32 D_L01_001D7754;
__asm__(".extern D_L01_001D7754, 4");
extern f32 D_L01_001D7758;
__asm__(".extern D_L01_001D7758, 4");
extern f32 D_L01_001D775C;
__asm__(".extern D_L01_001D775C, 4");
extern f32 D_L01_001D7760;
__asm__(".extern D_L01_001D7760, 4");
extern f32 D_L01_001D7764;
__asm__(".extern D_L01_001D7764, 4");
extern f32 D_L01_001D7768;
__asm__(".extern D_L01_001D7768, 4");
extern f32 D_L01_001D776C;
__asm__(".extern D_L01_001D776C, 4");
extern f32 D_L01_001D7770;
__asm__(".extern D_L01_001D7770, 4");
extern f32 D_L01_001D7774;
__asm__(".extern D_L01_001D7774, 4");
extern f32 D_L01_001D7780;
__asm__(".extern D_L01_001D7780, 4");
extern f32 D_L01_001D7784;
__asm__(".extern D_L01_001D7784, 4");
extern f32 D_L01_001D7788;
__asm__(".extern D_L01_001D7788, 4");
extern f32 D_L01_001D778C;
__asm__(".extern D_L01_001D778C, 4");
extern f32 D_L01_001D7798;
__asm__(".extern D_L01_001D7798, 4");
extern f32 D_L01_001D779C;
__asm__(".extern D_L01_001D779C, 4");
extern f32 D_L01_001D77A0;
__asm__(".extern D_L01_001D77A0, 4");
extern f32 D_L01_001D77A4;
__asm__(".extern D_L01_001D77A4, 4");
extern f32 D_L01_001D77A8;
__asm__(".extern D_L01_001D77A8, 4");
extern f32 D_L01_001D77AC;
__asm__(".extern D_L01_001D77AC, 4");
extern f32 D_L01_001D77B0;
__asm__(".extern D_L01_001D77B0, 4");
extern f32 D_L01_001D77B4;
__asm__(".extern D_L01_001D77B4, 4");
extern f32 D_L01_001D77B8;
__asm__(".extern D_L01_001D77B8, 4");
extern f32 D_L01_001D77BC;
__asm__(".extern D_L01_001D77BC, 4");
extern f32 D_L01_001D77C0;
__asm__(".extern D_L01_001D77C0, 4");
extern f32 D_L01_001D77C4;
__asm__(".extern D_L01_001D77C4, 4");
extern f32 D_L01_001D77C8;
__asm__(".extern D_L01_001D77C8, 4");
extern f32 D_L01_001D77CC;
__asm__(".extern D_L01_001D77CC, 4");
extern f32 D_L01_001D77D0;
__asm__(".extern D_L01_001D77D0, 4");
extern f32 D_L01_001D77D4;
__asm__(".extern D_L01_001D77D4, 4");
extern f32 D_L01_001D77D8;
__asm__(".extern D_L01_001D77D8, 4");
extern f32 D_L01_001D77DC;
__asm__(".extern D_L01_001D77DC, 4");
extern f32 D_L01_001D77E0;
__asm__(".extern D_L01_001D77E0, 4");
extern f32 D_L01_001D77E4;
__asm__(".extern D_L01_001D77E4, 4");
extern f32 D_L01_001D77E8;
__asm__(".extern D_L01_001D77E8, 4");
extern f32 D_L01_001D77EC;
__asm__(".extern D_L01_001D77EC, 4");
extern f32 D_L01_001D77F0;
__asm__(".extern D_L01_001D77F0, 4");
extern f32 D_L01_001D77F4;
__asm__(".extern D_L01_001D77F4, 4");
extern f32 D_L01_001D77F8;
__asm__(".extern D_L01_001D77F8, 4");
extern f32 D_L01_001D77FC;
__asm__(".extern D_L01_001D77FC, 4");
extern f32 D_L01_001D7800;
__asm__(".extern D_L01_001D7800, 4");
extern f32 D_L01_001D7804;
__asm__(".extern D_L01_001D7804, 4");
extern f32 D_L01_001D7808;
__asm__(".extern D_L01_001D7808, 4");
extern f32 D_L01_001D780C;
__asm__(".extern D_L01_001D780C, 4");
extern f32 D_L01_001D7810;
__asm__(".extern D_L01_001D7810, 4");
extern f32 D_L01_001D7814;
extern f32 D_L01_001D7818;
__asm__(".extern D_L01_001D7818, 4");
extern f32 D_L01_001D781C;
__asm__(".extern D_L01_001D781C, 4");
extern f32 D_L01_001D7B70;
__asm__(".extern D_L01_001D7B70, 4");
extern f32 D_L01_001D7B74;
__asm__(".extern D_L01_001D7B74, 4");
extern f32 D_L01_001D8170;
__asm__(".extern D_L01_001D8170, 4");
extern f32 D_L01_001D8174;
__asm__(".extern D_L01_001D8174, 4");

extern void func_L01_004316B0(f32 *a, f32 *b, s32 idx, s32 m, f32 x, f32 y);

/* localdecomp:start func_L01_00438028 */
void func_L01_00438028(s32 idx, s32 flag) {
    E_00438028 *e;
    E_00438028 *q;
    s32 i;
    s32 j;
    f32 buf[2];
    s32 fl;

    if (idx < 61 && D_001D5570[idx] != 0) {
        D_L01_001F3FA0_00438028.ents = (E_00438028 *)D_L01_002E9AE0[idx];
    } else {
        D_L01_001F3FA0_00438028.ents = 0;
    }
    if (D_001A4BE0.z != 0.0f && idx == D_001D545C && flag != 0) {
        func_L01_004316B0(&buf[0], &buf[1], idx, -1, D_001A4BE0.x, D_001A4BE0.y);
        if (D_L01_001D7B6C != 0) {
            buf[0] = D_L01_001D7B70;
            buf[1] = D_L01_001D7B74;
        }
        D_L01_001F3FA0_00438028.a1A8[idx] = (s32)(buf[0] * 4096.0f) << 16;
        D_L01_001F3FA0_00438028.a29C[idx] = (s32)(buf[1] * 4096.0f) << 16;
    } else if (D_L01_001F3FA0_00438028.a1A8[idx] == 0) {
        D_L01_001F3FA0_00438028.a1A8[idx] = 0x8000000;
        D_L01_001F3FA0_00438028.a29C[idx] = 0x8000000;
    }
    if (D_L01_001F3FA0_00438028.ents != 0) {
        if (!(D_L01_001F3FA0_00438028.ents[0].flags & 4)) {
            i = 0;
            do {
                e = &D_L01_001F3FA0_00438028.ents[i];
                if (D_L01_001D7B78 != 0) {
                    e->x = D_L01_001D7818;
                    e->y = D_L01_001D781C;
                }
                else if (e->id == -1000) { e->x = D_L01_001D76E0; e->y = D_L01_001D76E4; }
                else if (e->id == -999) { e->x = D_L01_001D76E8; e->y = D_L01_001D76EC; }
                else if (e->id == -998) { e->x = D_L01_001D76F0; e->y = D_L01_001D76F4; }
                else if (e->id == -997) { e->x = D_L01_001D76F8; e->y = D_L01_001D76FC; }
                else if (e->id == -996) { e->x = D_L01_001D7700; e->y = D_L01_001D7704; }
                else if (e->id == -995) { e->x = D_L01_001D7708; e->y = D_L01_001D770C; }
                else if (e->id == -994) { e->x = D_L01_001D7710; e->y = D_L01_001D7714; }
                else if (e->id == -993) { e->x = D_L01_001D7718; e->y = D_L01_001D771C; }
                else if (e->id == -992) { e->x = D_L01_001D7720; e->y = D_L01_001D7724; }
                else if (e->id == -991) { e->x = D_L01_001D7728; e->y = D_L01_001D772C; }
                else if (e->id == -990) { e->x = D_L01_001D7730; e->y = D_L01_001D7734; }
                else if (e->id == -989) { e->x = D_L01_001D7738; e->y = D_L01_001D773C; }
                else if (e->id == -988) { e->x = D_L01_001D7740; e->y = D_L01_001D7744; }
                else if (e->id == -987) { e->x = D_L01_001D7748; e->y = D_L01_001D774C; }
                else if (e->id == -986) { e->x = D_L01_001D7750; e->y = D_L01_001D7754; }
                else if (e->id == -985) { e->x = D_L01_001D7758; e->y = D_L01_001D775C; }
                else if (e->id == -984) { e->x = D_L01_001D7760; e->y = D_L01_001D7764; }
                else if (e->id == -983) { e->x = D_L01_001D7768; e->y = D_L01_001D776C; }
                else if (e->id == -982) { e->x = D_L01_001D7770; e->y = D_L01_001D7774; }
                else if (e->id == -980) { e->x = D_L01_001D7780; e->y = D_L01_001D7784; }
                else if (e->id == -979) { e->x = D_L01_001D7788; e->y = D_L01_001D778C; }
                else if (e->id == -977) { e->x = D_L01_001D7798; e->y = D_L01_001D779C; }
                else if (e->id == -976) { e->x = D_L01_001D77A0; e->y = D_L01_001D77A4; }
                else if (e->id == -975) { e->x = 0.31f; e->y = 0.185f; }
                else if (e->id == -974) { e->x = 0.19f; e->y = 0.21f; }
                else if (e->id == -972) { e->x = 0.765f; e->y = 0.89f; }
                else if (e->id == -973) { e->x = 0.46f; e->y = 0.145f; }
                else if (e->id == -971) { e->x = 0.54f; e->y = 0.76f; }
                else if (e->id == -970) { e->x = 0.747f; e->y = 0.04f; }
                else if (e->id == -969) { e->x = 0.747f; e->y = 0.95f; }
                else if (e->id == -968) { e->x = 0.465f; e->y = 0.71f; }
                else if (e->id == -967) { e->x = 0.61f; e->y = 0.65f; }
                else if (e->id == -966) { e->x = 0.118f; e->y = 0.62f; }
                else if (e->id == -965) { e->x = D_L01_001D77A8; e->y = D_L01_001D77AC; }
                else if (e->id == -964) { e->x = D_L01_001D77B0; e->y = D_L01_001D77B4; }
                else if (e->id == -963) { e->x = D_L01_001D77B8; e->y = D_L01_001D77BC; }
                else if (e->id == -962) { e->x = 0.485f; e->y = 0.582f; }
                else if (e->id == -961) { e->x = 0.785f; e->y = 0.145f; }
                else if (e->id == -960) { e->x = 0.46f; e->y = 0.145f; }
                else if (e->id == -959) { e->x = 0.0925f; e->y = 0.575f; }
                else if (e->id == -958) { e->x = 0.7f; e->y = 0.053f; }
                else if (e->id == -957) { e->x = 0.68f; e->y = 0.135f; }
                else if (e->id == -936) { e->x = 0.865f; e->y = 0.603f; }
                else if (e->id == -935) { e->x = 0.05f; e->y = 0.56f; }
                else if (e->id == -956) { e->x = 0.55f; e->y = 0.77f; }
                else if (e->id == -955) { e->x = 0.61f; e->y = 0.74f; }
                else if (e->id == -954) { e->x = D_L01_001D77C0; e->y = D_L01_001D77C4; }
                else if (e->id == -953) { e->x = D_L01_001D77C8; e->y = D_L01_001D77CC; }
                else if (e->id == -952) { e->x = 0.44f; e->y = 0.266f; }
                else if (e->id == -951) { e->x = 0.63f; e->y = 0.266f; }
                else if (e->id == -950) { e->x = D_L01_001D77D0; e->y = D_L01_001D77D4; }
                else if (e->id == -940) { e->x = D_L01_001D77F8; e->y = D_L01_001D77FC; }
                else if (e->id == -937) { e->x = D_L01_001D7808; e->y = D_L01_001D780C; }
                else if (e->id == -938) { e->x = D_L01_001D7810; e->y = D_L01_001D7814; }
                else if (e->id == -949) { e->x = 0.62f; e->y = 0.34f; }
                else if (e->id == -948) { e->x = 0.92f; e->y = 0.08f; }
                else if (e->id == -947) { e->x = 0.89f; e->y = 0.96f; }
                else if (e->id == -946) { e->x = D_L01_001D77D8; e->y = D_L01_001D77DC; }
                else if (e->id == -944) { e->x = 0.5f; e->y = 0.0655f; }
                else if (e->id == -943) { e->x = D_L01_001D77F0; e->y = D_L01_001D77F4; }
                else if (e->id == -942) { e->x = D_L01_001D77E0; e->y = D_L01_001D77E4; }
                else if (e->id == -941) { e->x = D_L01_001D77E8; e->y = D_L01_001D77EC; }
                else if (e->id == -939) { e->x = D_L01_001D7800; e->y = D_L01_001D7804; }
                else if (e->id == -945) { e->x = 0.712f; e->y = 0.13f; }
                else {
                        if (idx == D_001D545C) {
                            U_00438028 *u = D_L01_001EFE20_00438028[e->id];
                            if (u != 0) {
                                func_L01_004316B0(&D_L01_001F3FA0_00438028.ents[i].x, &D_L01_001F3FA0_00438028.ents[i].y, idx, -1, u->x, u->y);
                                D_L01_001F3FA0_00438028.ents[i].z = D_L01_001EFE20_00438028[e->id]->z;
                            }
                        } else {
                            func_L01_004316B0(&D_L01_001F3FA0_00438028.ents[i].x, &D_L01_001F3FA0_00438028.ents[i].y, idx, -1, D_00143230[e->id].x, D_00143230[e->id].y);
                            D_L01_001F3FA0_00438028.ents[i].z = D_00143230[e->id].z;
                        }
                    }
                i++;
            } while (!(D_L01_001F3FA0_00438028.ents[i].flags & 4));
        }
        {
            for (j = 0; !(D_L01_001F3FA0_00438028.ents[j].flags & 4); j++) {
                q = &D_L01_001F3FA0_00438028.ents[j];
                q->w24 = 0;
                fl = q->flags;
                q->flags = fl & ~0x10;
                if (q->h2 == -1) {
                    q->w24 = 1;
                } else {
                    q->w24 = *(s16 *)(D_L01_001DFF38.p + q->h2 * 0x30 + 0x2C) == 1;
                }
                if (q->flags & 0x1000) {
                    if ((D_0014323C[q->id * 16] ^ 1) & 1) {
                        q->w24 = 0;
                    }
                }
                if (D_L01_001F3FA0_00438028.ents[j].hA != 0) {
                    D_L01_001F3FA0_00438028.ents[j].flags |= 0x10;
                }
            }
        }
    }
}
/* localdecomp:end func_L01_00438028 */
