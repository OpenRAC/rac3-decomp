#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_00313DD0 */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038CED8(void *);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D328(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CBA0(void *, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_003C4138(void *, f32, f32);
extern s32 func_003C4B50(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern void (**func_L01_0043B548(s32, s32))();
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EB3C0(s32, void *);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB5E0(s32, s32);
extern void func_L01_004A3610(void *, void *);
extern void func_L01_0043B510(s32);
extern void func_L01_0041A5B0(s32, s32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_0040E408(void *, void *, f32);
extern void func_L01_004482A0(void *, void *, f32, f32, f32, f32);
extern void func_L01_00448690(void *, f32, s32, f32);
extern void func_L01_0050FB40(s32, s32, f32);
extern s32 func_L02_003E71A8(void *, void *, f32);
extern s32 func_L04_0050CB28(s32, s32);
extern void func_L04_003FDBF0(s32, f32, f32);
extern void func_L04_004B3440(void *, s32, void *, s32, void *);

typedef struct {
    u8 pad0000[0x80];
    f32 position[4];
    u8 pad0090[0x8];
    f32 yaw;
    u8 pad009C[0x54];
    u8 motionState[0xA0];
    u8 pad0190[0x10];
    f32 targetYaw;
    u8 pad01A4[0x14];
    s32 modeTimer;
    u8 pad01BC[0xC08 - 0x1BC];
    s32 animFlags;
    s32 animBusy;
    u8 pad0C10[0x1200 - 0xC10];
    s32 canInteract;
    u8 pad1204[0x121A - 0x1204];
    u8 interactBusy;
    u8 pad121B[0x1228 - 0x121B];
    s32 groundState;
    u8 pad122C[0x2260 - 0x122C];
    f32 stickY;
    f32 stickX;
    u8 pad2268[0x25C0 - 0x2268];
    u8 *moby;
    s32 moveState;
    u8 pad25C8[0x25E4 - 0x25C8];
    u8 disabled;
} CrankPlayer;
extern CrankPlayer D_001A4BE0;
extern u8 D_001A4C78[];
extern u8 D_001A7E18[];
extern u8 D_001BBE90[];
extern u8 D_001BBC40[];
extern s32 D_001D545C;
extern s32 D_001D4C38;
extern u8 D_001D5469;
extern f32 D_L04_001DC550;
extern u8 *D_L04_001DFDA0;
extern u8 *D_L04_001DFE80;
extern s32 D_L04_001E2890[];
extern u8 D_L04_001E2840[];
extern u8 *D_L04_0021D3E0[];
extern u8 D_L04_00235770[];
typedef struct { u8 pad[0x464]; u8 collected[0]; } CrankLevelState;
extern CrankLevelState D_L04_00236380;
__asm__(".extern D_L04_001DC550, 4");

/* The bolt crank's update (shared by levels 04, 16, 18, 22 and 29): rac2's matched
 * bolt_crank_update_pal (rac2 src/pal/levels/06_notak/L06_0041DED0-sw.c) is the same code, with rac3's
 * extra states 0, 6 and 7, the hero state at its rac3 offsets and the crank's variables 0x40 further on.
 * Case 3's player-motion step is per-instruction VU0 asm; its hero-position copy goes through a 128-bit
 * local. */
void func_L04_00313DD0(u8 *m) {
    u8 *pv = (*(u8 **)(m + 0x68));

    if (pv == 0) {
        *(f32 *)(m + 0xF8) = func_0038DAB8(*(f32 *)(m + 0xF8), 0.12566371f);
        return;
    }
    {
        u8 *h = (u8 *)&D_001A4BE0;
        if (*(s32 *)(h + 0x25C4) != 0x37 && m[0x20] == 3) {
            func_L01_004450F0(m, 1, -1);
            if (D_L04_001E2890[0] != 0) {
                func_L01_003EB5E0(0, 4);
            }
            return;
        }
    }
    switch (m[0x20]) {
    case 0:
        func_L01_00456230(m, 0);
        if (*(s32 *)(pv + 0x30) > 0) {
            void (**vt)() = func_L01_0043B548(0x19E1, 0x6C);
            *(s32 *)(pv + 0x30) = -1;
            pv[0x3E] = 8;
            (*vt[0])(m);
            return;
        }
        *(f32 *)(pv + 0x7C) = *(f32 *)(m + 0x18);
        qzero(pv + 0x80);
        func_L01_004450F0(m, 1, -1);
        if (*(f32 *)(pv + 0x40) == 1.0f) {
            *(f32 *)(m + 0x18) = *(f32 *)(pv + 0x7C) - 0.5f;
            func_L01_004450F0(m, 5, -1);
            if (*(s32 *)(pv + 0x30) != 0) {
                func_L01_0043B548(0x19E1, 0x6C)[2](m, 1);
            } else {
                func_L01_00456230(m, 1);
            }
            return;
        }
        *(f32 *)(pv + 0x40) = 0.0f;
        break;
    case 1:
        if (m < D_L04_001DFDA0 && *(s32 *)(pv + 0x30) == 0) {
            u16 id = *(u16 *)(m + 0xB2);
            if (D_L04_00236380.collected[(s16)id] != 0) {
                goto open;
            }
            {
                s32 b = D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)];
                if (id & 1) {
                    if ((b >> 4) & 7) {
                        goto open;
                    }
                } else if (b & 7) {
                open:
                    *(f32 *)(m + 0x18) = *(f32 *)(m + 0x18) - 0.5f;
                    func_L01_004450F0(m, 5, -1);
                    *(f32 *)(pv + 0x40) = 1.0f;
                    if (*(s32 *)(pv + 0x30) != 0) {
                        func_L01_0043B548(0x19E1, 0x6C)[2](m, 1);
                    } else {
                        func_L01_00456230(m, 1);
                    }
                    return;
                }
            }
        }
        {
            if (func_0038CF38(m + 0x10, D_001A4BE0.position) < 3.0f && !D_001A4BE0.interactBusy && !D_001A4BE0.disabled &&
                func_0038DBA0(D_001A4BE0.yaw, func_0038D160(*(f32 *)(m + 0x10) - D_001A4BE0.position[0], *(f32 *)(m + 0x14) - D_001A4BE0.position[1])) < 19.198622f &&
                fabs_asm(D_001A4BE0.position[2] - 0.3f - *(f32 *)(m + 0x18)) < 0.2f && D_001A4BE0.groundState == 9 && D_001A4BE0.canInteract != 0 &&
                func_L01_004606E8(0x80, 0xA, 0, 0) != 0 && *(u32 *)(pv + 0x54) >= 0x1A && *(f32 *)(m + 0x18) == *(f32 *)(pv + 0x7C) &&
                *(f32 *)(pv + 0x40) < 1.0f) {
                s32 ok = 1;
                s32 i;
                u8 *o;
                *(u32 *)(pv + 0x54) = 0;
                D_L04_001DC550 = 0.0f;
                i = 0;
                o = D_L04_0021D3E0[0];
                while (o != 0) {
                    if (func_003C4B50(o) == 0) {
                        if ((*(u8 **)(o + 0x24)) == 0 || (*(u8 **)(o + 0x24))[0x46] != 0x16) {
                            if (func_L02_003E71A8(m + 0x10, o + 0x10, 4.5f) != 0) {
                                ok = 0;
                                break;
                            }
                        }
                    }
                    i++;
                    o = D_L04_0021D3E0[i];
                }
                if (ok) {
                    func_L04_0050CB28(0x37, 1);
                    func_L01_003EB438(0, D_L04_001E2840, D_L04_001E2840 + 0x10, 3, 0x96, 0);
                    func_L01_003EB3C0(0, D_L04_001DFE80 + (*(s32 *)(pv + 0x60) << 7) + 0x70);
                    func_L01_003EB350(0, D_L04_001DFE80 + (*(s32 *)(pv + 0x60) << 7) + 0x30);
                    func_L04_003FDBF0(0, *(f32 *)(pv + 0x68), *(f32 *)(pv + 0x6C));
                    func_L01_004450F0(m, 3, -1);
                    *(f32 *)(pv + 0x64) = 0.0f;
                    *(f32 *)(pv + 0x58) = *(f32 *)(pv + 0x40) * (*(f32 *)(pv + 0x70) * 6.2831855f);
                    return;
                }
            } else if (*(f32 *)(pv + 0x40) < 1.0f) {
                (*(u32 *)(pv + 0x54))++;
                func_003C4138(pv + 0x40, 0.0f, 0.02f);
                if (0.0f < *(f32 *)(pv + 0x40)) {
                    *(f32 *)(m + 0xF8) = func_0038DB00(*(f32 *)(m + 0xF8), *(f32 *)(pv + 0x70) * 6.2831855f / 50.0f);
                }
                *(f32 *)(m + 0x18) = *(f32 *)(m + 0x18) + 0.010000001f;
                if (*(f32 *)(pv + 0x7C) <= *(f32 *)(m + 0x18)) {
                    *(f32 *)(m + 0x18) = *(f32 *)(pv + 0x7C);
                }
            } else if (*(s32 *)(pv + 0x78) != 0) {
                if (m < D_L04_001DFDA0 && *(s32 *)(pv + 0x30) == 0 && *(s32 *)(pv + 0x74) != -1 &&
                    !(D_001BBC40[m[0xB0] + D_001D545C * 16] & 0x80)) {
                    func_L04_004B3440(pv + 0x40, 4, m, 2, D_L04_00235770);
                    func_L01_0043B510(m[0xB0]);
                    if (*(s32 *)(pv + 0x74) != -1) {
                        u8 *c = D_L04_001DFE80 + (*(s32 *)(pv + 0x74) << 7);
                        func_L01_004A3610(c + 0x30, c + 0x70);
                    }
                }
                *(f32 *)(m + 0x18) = *(f32 *)(m + 0x18) - 0.010000001f;
                if (*(f32 *)(m + 0x18) <= *(f32 *)(pv + 0x7C) - 0.5f) {
                    *(f32 *)(m + 0x18) = *(f32 *)(pv + 0x7C) - 0.5f;
                }
            }
            {
            u8 *g = D_001A7E18;
            if (*(u16 *)(g + 0x8A84) == 0 && func_L01_0040E548(m + 0x10, D_001A4BE0.position) < 9.0f) {
                u32 t = (D_001D4C38 * 5 + 2) / 6;
                u32 cur = *(u32 *)(g + 0x22C);
                if (t - cur >= 0x385 || cur == 0) {
                    func_L01_0041A5B0(0xB8B, 0x2E);
                    return;
                }
                if (cur < t) {
                    *(u32 *)(g + 0x22C) = t;
                }
            }
            }
        }
        break;
    case 3: {
        u8 *hero = (u8 *)&D_001A4BE0;
        f32 mat[16] __attribute__((aligned(16)));
        vu0_v4 v40, v50, v60, v70, v80, v90, vA0;
        vu0_q vB0;
        f32 ang, ang2, z, d, t, groundHeight;

        *(vu0_q *)&v80 = 0;
        {
            u8 *c = D_L04_001E2840;
            v80.z = *(f32 *)(c + 0x18);
        }
        *(vu0_q *)&v70 = *(vu0_q *)&v80;
        ang = func_0038D160(*(f32 *)(hero + 0x80) - *(f32 *)(m + 0x10), *(f32 *)(hero + 0x84) - *(f32 *)(m + 0x14));
        if ((func_L01_004606E8(0x80, 6, 0, 0) != 0 && *(s32 *)(hero + 0x1B8) >= 0x33) || *(f32 *)(pv + 0x40) == 1.0f) {
            func_L04_0050CB28(0, 1);
            if (*(s32 *)(pv + 0x78) != 0) {
                func_L01_004450F0(m, 1, -1);
            } else if (*(f32 *)(pv + 0x40) == 1.0f) {
                {
                    u8 *g = D_001A7E18;
                    if (*(u16 *)(g + 0x8A84) == 0) {
                        *(u16 *)(g + 0x8A84) = 1;
                    }
                }
                if (m < D_L04_001DFDA0 && *(s32 *)(pv + 0x30) == 0) {
                    u16 id;
                    func_L04_004B3440(pv + 0x40, 4, m, 2, D_L04_00235770);
                    func_L01_004450F0(m, 4, -1);
                    id = *(u16 *)(m + 0xB2);
                    if (id & 1) {
                        u8 *p = &D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)];
                        if (((*p >> 4) & 7) != 7) {
                            *p += 0x10;
                        }
                    } else {
                        u8 *p = &D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)];
                        if ((*p & 7) != 7) {
                            *p += 1;
                        }
                    }
                    func_003A52A0(0, 0, m);
                    if (*(s32 *)(pv + 0x74) != -1 && !(D_001BBC40[m[0xB0] + D_001D545C * 16] & 0x80)) {
                        func_L04_004B3440(pv + 0x40, 4, m, 2, D_L04_00235770);
                        func_L01_0043B510(m[0xB0]);
                        if (*(s32 *)(pv + 0x74) != -1) {
                            u8 *c = D_L04_001DFE80 + (*(s32 *)(pv + 0x74) << 7);
                            func_L01_004A3610(c + 0x30, c + 0x70);
                        }
                    }
                } else {
                    func_L01_004450F0(m, 4, -1);
                    func_003A52A0(0, 0, m);
                }
            }
            if (*(s32 *)(pv + 0x90) != -1) {
                func_L01_003EB5E0(0, 4);
                func_L01_003EB438(0, D_L04_001E2840, D_L04_001E2840 + 0x10, 2, 0x96, 0);
                func_L01_003EB3C0(0, D_L04_001DFE80 + (*(s32 *)(pv + 0x90) << 7) + 0x70);
                func_L01_003EB350(0, D_L04_001DFE80 + (*(s32 *)(pv + 0x90) << 7) + 0x30);
                return;
            }
            func_L01_003EB5E0(0, 4);
            return;
        }
        qzero(&v40);
        v40.x = -*(f32 *)(hero + 0x2260);
        v40.y = -*(f32 *)(hero + 0x2264);
        t = func_0038CED8(&v40);
        if (1.0f < t) {
            func_L01_0040E408(&v40, &v40, t);
        }
        func_0038D328(mat, &v70);
        func_0038D028(&v40, &v40, mat);
        v60.x = func_0038D098(*(f32 *)(((*(u8 **)(hero + 0x25C0))) + 0xF8));
        v60.y = func_0038D0B0(*(f32 *)(((*(u8 **)(hero + 0x25C0))) + 0xF8));
        v60.z = 0.0f;
        d = func_0038CE68(pv + 0x80, &v40) - *(f32 *)(pv + 0x5C);
        if (d > 0.0022f) {
            d = 0.0022f;
        }
        if (d < -0.0022f) {
            d = -0.0022f;
        }
        *(vu0_q *)(pv + 0x80) = *(vu0_q *)&v40;
        *(f32 *)(pv + 0x5C) = *(f32 *)(pv + 0x5C) + d;
        if (*(f32 *)(pv + 0x5C) > 0.07400001f) {
            *(f32 *)(pv + 0x5C) = 0.07400001f;
        }
        if (*(f32 *)(pv + 0x5C) < 0.0f) {
            *(f32 *)(pv + 0x5C) = 0.0f;
        }
        if (fabs_asm(*(f32 *)(pv + 0x5C)) < 0.00055f) {
            *(f32 *)(pv + 0x5C) = 0.0f;
        }
        func_0038CF68(&v50, &v60, *(f32 *)(pv + 0x5C));
        if ((*(s32 *)(hero + 0xC08) & 2) && (*(u8 **)(hero + 0x25C0))[0x43] == 0x3F) {
            func_L01_0050FB40(0x3A, 0, 6.0f);
        }
        if ((*(u8 **)(hero + 0x25C0))[0x43] != 0x3F) {
            u8 *h1 = (u8 *)&D_001A4BE0;
            if (*(s32 *)(h1 + 0xC0C) == 0) {
                if ((*(u8 **)(h1 + 0x25C0))[0x42] == 0x3B && fabs_asm(*(f32 *)(pv + 0x5C)) == 0.0f) {
                    func_L01_0050FB40(0x3A, 0, 12.0f);
                } else {
                    u8 *h2 = (u8 *)&D_001A4BE0;
                    if ((*(u8 **)(h2 + 0x25C0))[0x42] == 0x3A) {
                        if (*(f32 *)(pv + 0x5C) > 0.0f) {
                            func_L01_0050FB40(0x3B, 0, 12.0f);
                        }
                    } else {
                        u8 *h2b = (u8 *)&D_001A4BE0;
                        if ((*(u8 **)(h2b + 0x25C0))[0x42] == 0x3B && *(f32 *)(pv + 0x5C) > 0.044400007f) {
                            func_L01_0050FB40(0x3C, 0, 12.0f);
                        } else {
                            u8 *h3 = (u8 *)&D_001A4BE0;
                            if ((*(u8 **)(h3 + 0x25C0))[0x42] == 0x3C && *(f32 *)(pv + 0x5C) < 0.029600004f) {
                                func_L01_0050FB40(0x3B, 0, 13.0f);
                            }
                        }
                    }
                }
            }
        }
        z = D_001A4BE0.position[2];
        vec_add_ba(D_001A4BE0.position, D_001A4BE0.position, &v50);
        ang2 = func_0038D160(D_001A4BE0.position[0] - *(f32 *)(m + 0x10), D_001A4BE0.position[1] - *(f32 *)(m + 0x14));
        v50.x = func_0038D098(ang2) * 1.05f;
        v50.y = func_0038D0B0(ang2) * 1.05f;
        *(s32 *)&v50.z = 0;
        {
            vu0_q c, x, y;
            __asm__("lqc2 %0, %1" : "=j"(c) : "m"(*(vu0_q *)D_001A4BE0.position));
            __asm__("sqc2 %1, %0" : "=m"(vB0) : "j"(c));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_q *)(m + 0x10)));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(vu0_q *)&v50));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(v80) : "j"(x));
            __asm__("lqc2 %0, %1" : "=j"(c) : "m"(v80));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(vB0));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(c) : "j"(c), "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_q *)&v90) : "j"(c));
        }
        *(s32 *)&v90.z = 0;
        vA0.x = -func_0038CED8(&v90);
        func_L01_004482A0(&vA0, &D_L04_001DC550, 0.0f, 0.0216f, 0.43200004f, 0.14000002f);
        func_0038CF68(&v90, &v90, D_L04_001DC550);
        vec_add_ab(D_001A4BE0.position, D_001A4BE0.position, &v90);
        D_001A4BE0.position[2] = z;
        if (D_001D5469) {
            D_001A4BE0.targetYaw = func_0038DAB8(-1.5707964f, ang2);
        } else {
            D_001A4BE0.targetYaw = func_0038DAB8(1.5707964f, ang2);
        }
        {
        f32 *playerYaw = (f32 *)D_001A4C78;
        CrankPlayer *player = (CrankPlayer *)((u8 *)playerYaw - 0x98);
        func_L01_00448690(playerYaw, player->targetYaw, 0, 0.12566371f);
        *(f32 *)(pv + 0x64) = *(f32 *)(pv + 0x64) + 0.00392f;
        player->position[2] -= *(f32 *)(pv + 0x64) - 2.0f;
        groundHeight = func_003C3D30(player->position, 0, 0, 0.5f);
        player->position[2] -= 2.0f;
        if (player->position[2] < groundHeight) {
            player->position[2] = groundHeight;
            *(s32 *)(pv + 0x64) = 0;
        }
        if (player->moby[0x43] != 0x3F) {
            f32 a = func_0038DAB8(0.2617994f, ang2);
            func_L01_00448690(m + 0xF8, a, 0, 0.06283186f);
            if (func_0038DB00(*(f32 *)(m + 0xF8), a) > 1.0471976f) {
                *(f32 *)(m + 0xF8) = func_0038DB00(*(f32 *)(m + 0xF8), 1.0471976f);
            } else if (func_0038DB00(*(f32 *)(m + 0xF8), a) < -1.0471976f) {
                *(f32 *)(m + 0xF8) = func_0038DAB8(*(f32 *)(m + 0xF8), 1.0471976f);
            }
        }
        }
        *(f32 *)(pv + 0x58) = *(f32 *)(pv + 0x58) + func_0038DBA0(ang2, ang);
        *(f32 *)(pv + 0x40) = *(f32 *)(pv + 0x58) / (*(f32 *)(pv + 0x70) * 6.2831855f);
        if (1.0f < *(f32 *)(pv + 0x40)) {
            *(f32 *)(pv + 0x40) = 1.0f;
        }
        if (*(f32 *)(pv + 0x40) < 0.0f) {
            *(f32 *)(pv + 0x40) = 0.0f;
        }
        func_0038CBA0(D_001A4BE0.motionState, 0xA0);
        return;
    }
    case 4:
        *(f32 *)(m + 0x18) = *(f32 *)(m + 0x18) - 0.010000001f;
        if (*(f32 *)(m + 0x18) <= *(f32 *)(pv + 0x7C) - 0.5f) {
            if (*(s32 *)(pv + 0x90) != -1) {
                func_L01_003EB5E0(0, 4);
            }
            *(f32 *)(m + 0x18) = *(f32 *)(pv + 0x7C) - 0.5f;
            func_L01_004450F0(m, 5, -1);
            *(f32 *)(pv + 0x40) = 1.0f;
            if (*(s32 *)(pv + 0x30) != 0) {
                func_L01_0043B548(0x19E1, 0x6C)[2](m, 1);
            } else {
                func_L01_00456230(m, 1);
            }
            return;
        }
        break;
    case 5:
        *(f32 *)(pv + 0x40) = 1.0f;
        if (*(s32 *)(pv + 0x30) != 0) {
            func_L01_0043B548(0x19E1, 0x6C)[2](m, 1);
        } else {
            func_L01_00456230(m, 1);
        }
        return;
    case 6:
        *(f32 *)(pv + 0x40) = 0.0f;
        if (*(s32 *)(pv + 0x30) != 0) {
            func_L01_0043B548(0x19E1, 0x6C)[2](m, 0);
        } else {
            func_L01_00456230(m, 0);
        }
        *(f32 *)(m + 0x18) = *(f32 *)(pv + 0x7C) - 0.5f;
        break;
    case 7:
        if (*(f32 *)(m + 0x18) == *(f32 *)(pv + 0x7C) - 0.5f) {
            func_003A52A0(0, 0, m);
        }
        *(f32 *)(m + 0x18) = *(f32 *)(m + 0x18) + 0.010000001f;
        if (*(f32 *)(pv + 0x7C) <= *(f32 *)(m + 0x18)) {
            *(f32 *)(m + 0x18) = *(f32 *)(pv + 0x7C);
            func_L01_004450F0(m, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L04_00313DD0 */

/* localdecomp:start func_L04_00314F58 */
f32 func_L04_00314F58(void *arg0) {
    return (*(f32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x40));
}
/* localdecomp:end func_L04_00314F58 */

/* localdecomp:start func_L04_00314F68 */
void func_L04_00314F68(u8 *a0, u8 *a1) {
    u8 *v = *(u8 **)(a1 + 104);
    float x = *(float *)(v + 96);
    u8 *o = *(u8 **)(a0 + 104);
    if (0.0f <= x) *(float *)(o + 64) = x;
    else *(float *)(o + 64) = 0.0f;
    *(s32 *)(o + 96) = *(s32 *)(v + 32);
}
/* localdecomp:end func_L04_00314F68 */

/* localdecomp:start func_L04_00314FA0 */
extern void (**func_L01_0043B548())(int);

void func_L04_00314FA0(int a0) {
    (*func_L01_0043B548(6625, 108))(a0);
}
/* localdecomp:end func_L04_00314FA0 */
