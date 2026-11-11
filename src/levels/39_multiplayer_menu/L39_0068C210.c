#include "common.h"

/* localdecomp:start func_L39_0068C210 */
typedef struct {
    /* 0x000 */ u8 pad0[0x280];
    /* 0x280 */ u8 unk280;
    /* 0x284 */ s32 unk284;
} G_0068C210;

typedef struct {
    /* 0x00 */ u8 pad0[0x50];
    /* 0x50 */ u8 *unk50;
} R_0068C210;

typedef struct {
    /* 0x00 */ u8 pad0[0x4E];
    /* 0x4E */ u8 unk4E;
    /* 0x4F */ u8 pad4F[0x1F0 - 0x4F];
} P_0068C210;

typedef struct {
    /* 0x000 */ u8 pad0[0x180];
    /* 0x180 */ u8 unk180;
    /* 0x181 */ u8 unk181;
    /* 0x182 */ char unk182[0x142];
    /* 0x2C4 */ s32 unk2C4;
    /* 0x2C8 */ u8 pad2C8[0x1C];
    /* 0x2E4 */ u8 unk2E4;
} N_0068C210;

typedef struct {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ u8 pad2[0x13];
    /* 0x15 */ char unk15[0x3B];
} M_0068C210;

typedef struct {
    /* 0x000 */ u8 pad0[0x290];
    /* 0x290 */ s32 unk290;
    /* 0x294 */ u8 pad294[0x24];
    /* 0x2B8 */ u8 unk2B8;
    /* 0x2B9 */ u8 unk2B9;
    /* 0x2BA */ u8 unk2BA;
    /* 0x2BB */ u8 unk2BB;
    /* 0x2BC */ u8 unk2BC[0x30];
    /* 0x2EC */ s32 unk2EC;
    /* 0x2F0 */ s32 unk2F0;
    /* 0x2F4 */ u8 unk2F4[0x44];
    /* 0x338 */ s32 unk338;
} S_0068C210;

extern R_0068C210 *D_L39_0024D760;
extern G_0068C210 *D_L39_00247914;
extern u16 D_L39_00247B18 __attribute__((section(".data")));
extern char D_L39_00247B10[];
extern P_0068C210 D_001FC6B0[];
extern char D_001A5E52[][0x60];
extern N_0068C210 D_001A5CD0;

extern s32 func_00381FF0(s32);
extern void func_L39_00689AC8(S_0068C210 *, s32);
extern void func_00195410(void);
extern void func_001206F4(char *, char *);
extern s32 func_L39_006DC7C8(u8 *, s32, char *, s32);
extern void func_L39_0067BBE8(M_0068C210 *);
extern s32 func_0017E480(M_0068C210 *);
extern s32 func_L39_006872E8(G_0068C210 *, s32, s32, s32, f32, s32);
extern void func_L39_006D8E30(R_0068C210 *);
extern s32 func_00198578(void);
extern void func_001375B0(void *, void *, s32);
extern void func_L39_0067EB98(void);

s32 func_L39_0068C210(S_0068C210 *this) {
    M_0068C210 msg;
    s32 ret;
    s32 choice;
    s32 choice2;
    G_0068C210 *g;
    G_0068C210 *g2;
    s32 text;

retry:
    func_L39_00689AC8(this, func_00381FF0(0xF6A));
    func_00195410();
    func_00195410();
    ret = D_L39_0024D760->unk50[0x9D];
    if (ret == 0) {
        s32 player = this->unk290 - 1;
        P_0068C210 *players = D_001FC6B0;

        this->unk338++;
        if (players[player].unk4E == 0) {
            func_001206F4(D_001A5E52[0], D_001A5E52[3]);
        } else {
            func_001206F4(D_001A5E52[0], D_001A5E52[2]);
        }
        ret = func_L39_006DC7C8(D_L39_0024D760->unk50, D_001A5CD0.unk180, D_001A5CD0.unk182, D_001A5CD0.unk2C4);
        this->unk338--;
    }
    if (ret != 0) {
        this->unk338++;
        func_L39_00689AC8(this, func_00381FF0(0xF6B));
        msg.unk0 = D_L39_00247B18;
        func_001206F4(msg.unk15, (char *)D_L39_0024D760->unk50);
        func_L39_0067BBE8(&msg);
        func_0017E480(&msg);
        this->unk338--;
    } else {
        func_L39_00689AC8(this, func_00381FF0(0xF6C));
        g = D_L39_00247914;
        choice = func_L39_006872E8(g, func_00381FF0(0x130E), (s32)D_L39_00247B10, 3, 0.6f, 0);
        if (choice == 1) {
            goto retry;
        }
        if (choice == 2) {
            g2 = D_L39_00247914;
            text = func_00381FF0(0xF5F);
            choice2 = func_L39_006872E8(g2, text, func_00381FF0(0x1031), 3, 0.6f, 0);
            if (choice2 == 1) {
                this->unk338++;
                if (D_001A5CD0.unk2E4 != 0) {
                    func_L39_006D8E30(D_L39_0024D760);
                }
                func_00198578();
                D_L39_00247914->unk280 = choice2;
                func_001375B0(this->unk2BC, this->unk2F4, 0x40);
                if (this->unk2EC == 5) {
                    D_L39_00247914->unk284 = 0x18;
                    return 0;
                }
                this->unk2BA = choice2;
                func_L39_0067EB98();
                D_L39_00247914->unk280 = 0;
                this->unk338--;
            } else if (choice2 == choice) {
                goto retry;
            }
        }
    }
    this->unk2B8 = ret;
    return ret;
}
/* localdecomp:end func_L39_0068C210 */
