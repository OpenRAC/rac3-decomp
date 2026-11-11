/* NEAR MISS: func_L01_004EBDA8. check.py: 386 differing lines but only ~96 differing instructions after alignment (22 ignoring register names). Same frame (0xC0), saved regs, control flow, spill slots 0x54/0x58/0x5C. Differs: (1) fp-loop preheader schedule (sp+0x10 'mat' pointer is a user var here; retail's is hoisted one loop level only), (2) temp register choices in the body start (k*0x50 in a3/slot in a1 in retail), (3) loop-tail delay-slot fill. Uses aliases func_L01_004E9270_004EBDA8 etc. (file defines them as int f(void)) and typedef s64_X mode(DI). */
extern u8 D_001A4BE0[];
extern u8 *D_001A71A0[];
extern u8 D_001425C0[];
extern Def_004EA7D8 D_L01_002C5600[];
extern s32 D_L01_001D6694;
extern s32 D_L01_001DFB40;
__asm__(".extern D_001DBD30_sda, 4");
extern s32 D_001DBD30_sda;
extern u8 D_L01_002F44F0[];
extern u8 D_L01_00251480[];
extern u8 D_L01_00251680[];
extern u8 D_L01_00251880[];
extern u8 D_L01_00251980[];
extern u8 D_L01_001DBD60[];
extern u8 D_L01_001DBD70[];
extern u8 D_L01_001DBD88[];
typedef int s64_X __attribute__((mode(DI)));
typedef struct H_4EBDA8_mtx {
    s128 row[4];
} H_4EBDA8_mtx;
extern H_4EBDA8_mtx D_001A5810[];
typedef struct H_4EBDA8_slot {
    s128 pos;
    s128 rot;
    u8 *moby[3];
    u8 *pack;
    u8 pad_30[0x3A - 0x30];
    u8 thrown;
    u8 pad_3B[0x48 - 0x3B];
    s32 item;
    u8 pad_4C[0x50 - 0x4C];
} H_4EBDA8_slot;
typedef struct H_4EBDA8_hero {
    u8 pad_0[0x80];
    s128 w80;
    s128 w90;
    u8 pad_A0[0xC30 - 0xA0];
    H_4EBDA8_mtx joint[16];
    u8 pad_1030[0x11E0 - 0x1030];
    H_4EBDA8_slot slot[7];
    u8 pad_1410[0x22C0 - 0x1410];
    s128 w22C0;
    u8 pad_22D0[0x25C0 - 0x22D0];
    u8 *moby;
} H_4EBDA8_hero;
typedef struct H_4EBDA8_row {
    u8 pad_0[0x0C];
    s32 attach;
    u8 pad_10[0x18 - 0x10];
    s32 hold;
    u8 pad_1C[0xF0 - 0x1C];
} H_4EBDA8_row;
typedef struct H_4EBDA8_moby {
    u8 pad_0[0x10];
    s128 pos;
    u8 pad_20[0x24 - 0x20];
    s32 w24;
    u8 pad_28[0x2C - 0x28];
    f32 scale;
    u8 pad_30[0x34 - 0x30];
    u16 h34;
    u8 pad_36[0x40 - 0x36];
    s32 w40;
    s32 w44;
    u8 pad_48[0x58 - 0x48];
    u8 *p58;
    u8 *p5C;
    u8 pad_60[0x78 - 0x60];
    s32 w78;
    u8 pad_7C[0xC0 - 0x7C];
    u8 pad_C0[0xF0 - 0xC0];
    f32 rot_x;
    f32 rot_y;
    f32 rot_z;
} H_4EBDA8_moby;

extern void func_003C6FE0(u8 *);
extern void func_003C7C38(u8 *);
extern void func_003C7DD8(u8 *);
extern void func_0038D590(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_003C48A8(Vec4 *, Vec4 *);
extern s32 func_L01_004E9270_004EBDA8(s32);
extern s32 func_L01_004E9298_004EBDA8(s32);
extern s32 func_L01_004E92C0_004EBDA8(s32);
extern void func_003C2EC0(u8 *, s32, void *);
extern void *func_003C24B0(s32, s32);
extern void func_L01_00448E10(void *);
extern void func_L01_004E3268(void);
extern void func_L01_004E5520(void *, void *, s32, s32, s32);
extern void func_L01_004EB978(void *, void *, s32);

/* hero_place_item_mobys: puts each item slot's moby on its attach matrix (his joints), and
   the slot's own position and angles from it; the back's Clank and pack are made here. */
void func_L01_004EBDA8(s32 moby_arg)
{
    f32 vec[4];
    s128 scratch[4];
    f32 f;
    u8 *hero_moby;
    s32 k;
    s32 fp;
    s32 mode;
    f32 hundred;
    u8 *slot;
    s128 *mat;
    H_4EBDA8_moby *moby;
    s32 mslot;
    s32 a, b, c;
    u8 *pack;

    hero_moby = (u8 *)moby_arg;
    if (hero_moby == 0) {
        hero_moby = D_001A71A0[0];
    }
    hundred = 100.0f;
    for (k = 0; k < 7; k++) {
        mode = D_L01_001D6694;
        if (mode == 2 || mode == 6) {
            if (!((k == 2 && (*(H_4EBDA8_hero *)&D_001A4BE0).slot[2].item == 0x17) || k == 1 || k == 5 || k == 4)) {
                continue;
            }
        }
        mat = scratch;
        slot = (u8 *)&D_001A4BE0 + k * 0x50;
        for (fp = 0; fp < 3; fp++) {
            if (fp > 0 && !(k == 1 || k == 3 || k == 4)) {
                break;
            }
            moby = (H_4EBDA8_moby *)*(u8 **)(slot + 0x1200);
            if (fp == 1) {
                moby = (H_4EBDA8_moby *)*(u8 **)(slot + 0x1204);
            } else if (fp == 2) {
                moby = (H_4EBDA8_moby *)*(u8 **)(slot + 0x1208);
            }
            if (moby != 0) {
                *(s64_X *)((u8 *)moby + 0x38) = *(s64_X *)((*(H_4EBDA8_hero *)&D_001A4BE0).moby + 0x38);
                mslot = ((H_4EBDA8_row *)&D_L01_002C5600[D_001425C0[(*(H_4EBDA8_hero *)&D_001A4BE0).slot[k].item]])->attach;
                if (k == 1 && fp == 1) {
                    mslot = 3;
                }
                if ((*(H_4EBDA8_hero *)&D_001A4BE0).slot[k].thrown != 0) {
                    (*(H_4EBDA8_hero *)&D_001A4BE0).slot[k].pos = (*(H_4EBDA8_hero *)&D_001A4BE0).joint[mslot].row[3];
                    func_003C48A8((Vec4 *)&D_001A5810[mslot], (Vec4 *)&(*(H_4EBDA8_hero *)&D_001A4BE0).slot[k].rot);
                    func_003C6FE0((u8 *)moby);
                    func_003C7C38((u8 *)moby);
                    moby->h34 &= ~4;
                } else {
                    *(s128 *)((u8 *)moby + 0x10) = (*(H_4EBDA8_hero *)&D_001A4BE0).joint[mslot].row[3];
                    if (D_001DBD30_sda == 0 || ((H_4EBDA8_row *)&D_L01_002C5600[D_001425C0[(*(H_4EBDA8_hero *)&D_001A4BE0).slot[k].item]])->hold == 0) {
                        if (k == 0) {
                            func_L01_004EB978(moby, &D_001A5810[mslot], 0);
                        }
                        a = func_L01_004E9270_004EBDA8(k);
                        b = func_L01_004E9298_004EBDA8(k);
                        c = func_L01_004E92C0_004EBDA8(k);
                        if (!a && !b && !c) {
                            func_003C6FE0((u8 *)moby);
                        }
                        func_003C7C38((u8 *)moby);
                        func_0038D590((u8 *)moby + 0xC0, &D_001A5810[mslot]);
                        if (!a && !b && !c) {
                            func_L01_00448E10((u8 *)moby + 0xC0);
                        }
                        vec[0] = 1.0f;
                        vec[1] = 0.0f;
                        vec[2] = 0.0f;
                        func_0038D000(vec, vec, (u8 *)moby + 0xC0);
                        f = func_0038CED8(vec);
                        moby->rot_y = -func_0038D160(f, vec[2]);
                        moby->rot_z = func_0038D160(vec[0], vec[1]);
                        func_003C7DD8((u8 *)moby);
                        moby->h34 |= 6;
                        if (a) {
                            func_L01_004E5520(D_L01_002F44F0, D_L01_00251480, moby->w24, 0, (s32)hero_moby);
                            moby->w44 = 0;
                            moby->w40 = 0;
                            moby->p58 = D_L01_00251480;
                            moby->p5C = D_L01_00251480;
                        } else if (b) {
                            func_L01_004E5520(D_L01_001DBD60, D_L01_00251680, moby->w24, 0, (s32)hero_moby);
                            moby->w44 = 0;
                            moby->w40 = 0;
                            moby->p58 = D_L01_00251680;
                            moby->p5C = D_L01_00251680;
                        } else if (c) {
                            if (fp == 0) {
                                func_L01_004E5520(D_L01_001DBD70, D_L01_00251880, moby->w24, 0, (s32)hero_moby);
                                moby->p58 = D_L01_00251880;
                                moby->p5C = D_L01_00251880;
                            } else {
                                func_L01_004E5520(D_L01_001DBD88, D_L01_00251980, moby->w24, 0, (s32)hero_moby);
                                moby->p58 = D_L01_00251980;
                                moby->p5C = D_L01_00251980;
                            }
                            moby->w44 = 0;
                            moby->w40 = 0;
                        }
                    } else {
                        func_003C6FE0((u8 *)moby);
                        if (D_001DBD30_sda == 0 || k != 0) {
                            func_003C48A8((Vec4 *)&D_001A5810[mslot], (Vec4 *)((u8 *)moby + 0xF0));
                        } else {
                            func_L01_004EB978(moby, &D_001A5810[mslot], 1);
                        }
                        func_003C7C38((u8 *)moby);
                        func_003C7DD8((u8 *)moby);
                        moby->h34 |= 6;
                    }
                }
            }
            if (k == 3 && fp == 1 && moby != 0) {
                if ((*(H_4EBDA8_hero *)&D_001A4BE0).slot[3].pack == 0) {
                    (*(H_4EBDA8_hero *)&D_001A4BE0).slot[3].pack = func_003C24B0(0x4B4, 0x80);
                    if ((*(H_4EBDA8_hero *)&D_001A4BE0).slot[3].pack == 0) {
                        continue;
                    }
                    ((H_4EBDA8_moby *)(*(H_4EBDA8_hero *)&D_001A4BE0).slot[3].pack)->w78 = (s32)0x801432D7;
                    *(s128 *)((*(H_4EBDA8_hero *)&D_001A4BE0).slot[3].pack + 0x10) = (*(H_4EBDA8_hero *)&D_001A4BE0).w80;
                    *(s128 *)((*(H_4EBDA8_hero *)&D_001A4BE0).slot[3].pack + 0xF0) = (*(H_4EBDA8_hero *)&D_001A4BE0).w90;
                    *(u16 *)((*(H_4EBDA8_hero *)&D_001A4BE0).slot[3].pack + 0x32) = 0x40;
                    (*(H_4EBDA8_hero *)&D_001A4BE0).slot[3].pack[0x31] = 1;
                    (*(H_4EBDA8_hero *)&D_001A4BE0).slot[3].pack[0x30] = 0;
                    *(u16 *)((*(H_4EBDA8_hero *)&D_001A4BE0).slot[3].pack + 0x34) = 0;
                    ((H_4EBDA8_moby *)(*(H_4EBDA8_hero *)&D_001A4BE0).slot[3].pack)->scale = ((H_4EBDA8_moby *)(*(H_4EBDA8_hero *)&D_001A4BE0).slot[3].pack)->scale * 1.3f;
                    func_003C7C38((*(H_4EBDA8_hero *)&D_001A4BE0).slot[3].pack);
                    if ((*(H_4EBDA8_hero *)&D_001A4BE0).slot[3].pack == 0) {
                        continue;
                    }
                }
                pack = (*(H_4EBDA8_hero *)&D_001A4BE0).slot[3].pack;
                if ((pack[0x34] ^ 1) & 1) {
                    func_003C2EC0((u8 *)moby, 8, mat);
                    (*(H_4EBDA8_hero *)&D_001A4BE0).w22C0 = scratch[3];
                    func_L01_004E3268();
                    *(s128 *)(pack + 0x10) = scratch[3];
                    func_0038D590(pack + 0xC0, mat);
                    func_003C7C38(pack);
                    {
                        s32 r = D_L01_001DFB40 % 100;
                        f32 arg = (f32)r / hundred;
                        f32 s;
                        s32 sa, sb, sc;
                        *(s64_X *)(pack + 0x38) = *(s64_X *)((*(H_4EBDA8_hero *)&D_001A4BE0).moby + 0x38);
                        arg = arg + arg;
                        arg = arg * 3.14159274f;
                        arg = arg + (-3.14159274f);
                        s = func_0038D0B0(arg);
                        *(u16 *)(pack + 0x34) |= 0x10;
                        sa = (s32)(s * 10.0f);
                        sb = (s32)(s * 90.0f);
                        sc = (s32)(s * 50.0f);
                        sa = sa + 0x14;
                        sb = sb + 0xD7;
                        sc = sc + 0x32;
                        if (sb >= 0x100) {
                            sb = 0xFF;
                        }
                        ((H_4EBDA8_moby *)pack)->w78 = 0x80000000 | (sc << 8) | (sa << 16) | sb;
                    }
                }
            }
        }
    }
}
