#include "common.h"

/* NTSC-U counterpart of func_L01_004BC0F8 (src/levels/shared/L01_004BC0F8.c) */
extern u8 D_001425C0[];
extern s32 func_0037DF98(s32);

/* localdecomp:start func_L01_004B8560 */
typedef struct {
    s32 id;
    u8 ammo;
    u8 pad5[11];
    u8 b16;
    u8 b17;
    u8 all;
    u8 pad19;
} Slot_004BC0F8;
typedef struct {
    u8 pad0[0x28];
    void *sound;
    u8 pad2C[0x30];
    s32 mode;
    u8 pad60[8];
    s32 equipped;
    u8 pad6C[12];
    s32 previous;
    u8 pad7C[4];
    s32 selected;
    s32 state;
    u8 pad88[0xB8];
    Slot_004BC0F8 slots[76];
    u8 pad730[16];
    s32 count;
    u8 pad744[16];
    s32 allCost;
    u8 pad758[28];
    s32 changed;
} Menu_004BC0F8;
typedef struct {
    u8 pad0[0x84];
    u16 cost;
    u16 altCost;
    u8 pad88[2];
    u16 max;
    u8 pad8C[0x64];
} Info_004BC0F8;
typedef struct {
    u8 pad0[0x1C4];
    u32 buttons;
} Pad_004BC0F8;
extern Menu_004BC0F8 D_L01_00244740_004B8560;
extern Info_004BC0F8 D_L01_002C5640_004B8560[];
extern u8 D_00142CA0[];
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern s32 D_00142660_004B8560[];
extern Pad_004BC0F8 *D_001D52FC_004B8560;
extern s32 D_L01_001E0FF8;
extern s32 D_L01_001E1008_004B8560;
extern s32 D_L01_001E100C;
extern s32 D_L01_001E1010;
extern s32 D_L01_001E1014;
extern s32 func_0039FE80(s32, s32, void *);
extern s32 func_0037DF98(s32);
extern void func_L01_004B8520(s32 a0);
extern void func_L01_004B6E88(s32);
extern void func_L01_004BBDD8(void);
extern s32 func_L01_004B6C98(void);
extern s32 func_L01_0050D980(s32, s32);
extern void func_L01_00416B38(s32);
extern void func_L01_00449AE8(s32);
extern void func_L01_004176F8(s32);
extern void func_L01_00419710_004B8560(s32);
extern void func_0038ED78(s32, s32);
extern void func_L01_004789D0(s32);

void func_L01_004B8560(u8 *confirmed, u8 *quantity) {
    s32 i;
    s32 accepted;
    s32 price;
    s32 id;
    s32 left;
    s32 total;
    s32 unit;
    s32 amount;

    if (D_L01_00244740_004B8560.state == 1) {
        if (D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].all == 1) {
            if (D_L01_00244740_004B8560.allCost <= 0) {
                func_0039FE80(2, 17, D_L01_00244740_004B8560.sound);
                return;
            }
            accepted = 0;
            if (D_001D52FC_004B8560->buttons & 0x40) {
                for (i = 0; i < 156; i++) {
                    if (D_00142CA0[i]) {
                        Info_004BC0F8 *info = &D_L01_002C5640_004B8560[D_001425C0[i]];
                        if (info->cost) {
                            if (D_L01_00244740_004B8560.mode && (i == 16 || i == 17 || i == 19 || i == 21 || i == 22)) {
                                continue;
                            }
                            if (D_001427F0[i] < info->max) {
                                D_001427F0[i] = info->max;
                            }
                        }
                    }
                }
                D_00142660_004B8560[0] -= D_L01_00244740_004B8560.allCost;
                D_L01_001E0FF8 = 120;
                accepted = 1;
            } else if (D_001D52FC_004B8560->buttons & 0x10) {
                accepted = 1;
                func_0039FE80(0, 17, D_L01_00244740_004B8560.sound);
            }
            func_L01_004B8520(func_0037DF98(0x17A));
            func_L01_004B6E88(0);
            func_0039FE80(7, 17, D_L01_00244740_004B8560.sound);
            if (accepted) {
                D_L01_00244740_004B8560.state = 0;
                func_L01_004BBDD8();
            }
        } else {
            Info_004BC0F8 *info;
            s32 n;

            info = &D_L01_002C5640_004B8560[D_001425C0[D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id]];
            if (info->cost) {
                D_L01_001E1014 = D_00142660_004B8560[0] / info->cost;
            } else {
                D_L01_001E1014 = 0;
            }
            n = (D_L01_002C5640_004B8560 + *(D_001425C0 + D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id))->max - D_001427F0[D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id];
            if (n < D_L01_001E1014) {
                D_L01_001E1014 = n;
            }
            *confirmed = 0;
            *quantity = 0;
            if (D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].ammo == 1
                && D_001427F0[D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id]
                    >= D_L01_002C5640_004B8560[D_001425C0[D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id]].max) {
                func_0039FE80(2, 17, D_L01_00244740_004B8560.sound);
            } else if (D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].ammo == 1) {
                if (D_00142660_004B8560[0] < (D_L01_002C5640_004B8560 + D_001425C0[D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id])->cost) {
                    func_0039FE80(2, 17, D_L01_00244740_004B8560.sound);
                } else {
                    *quantity = 1;
                }
            } else {
                price = func_L01_004B6C98();
                if (D_00142660_004B8560[0] < price) {
                    func_0039FE80(2, 0, D_L01_00244740_004B8560.sound);
                }
            }
            D_L01_00244740_004B8560.state = 2;
        }
    } else if (D_L01_00244740_004B8560.state == 2) {
        if (*quantity == 1) {
            if ((D_001D52FC_004B8560->buttons & 0x8000) || (D_L01_001E1008_004B8560 >= 16 && !(D_L01_001E1008_004B8560 & 7)) || D_L01_001E1008_004B8560 >= 48) {
                if (D_L01_001E1014 >= 2) {
                    D_L01_001E1014 = D_L01_001E1014 - 1;
                    if (!(D_L01_001E1008_004B8560 & 3) || D_L01_001E1008_004B8560 < 16) {
                        func_0039FE80(1, 17, D_L01_00244740_004B8560.sound);
                    }
                }
            }
            if ((D_001D52FC_004B8560->buttons & 0x2000) || (D_L01_001E100C >= 16 && !(D_L01_001E100C & 7)) || D_L01_001E100C >= 48) {
                Info_004BC0F8 *info;
                u16 cost;
                s32 limit;
                s32 n;

                info = &D_L01_002C5640_004B8560[D_001425C0[D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id]];
                if (info->cost) {
                    cost = info->cost;
                    limit = D_00142660_004B8560[0] / cost;
                    n = info->max - D_001427F0[D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id];
                    if (n < limit) {
                        limit = n;
                    }
                    if (D_L01_001E1014 < limit) {
                        D_L01_001E1014 = D_L01_001E1014 + 1;
                        if (!(D_L01_001E100C & 3) || D_L01_001E100C < 16) {
                            func_0039FE80(1, 17, D_L01_00244740_004B8560.sound);
                        }
                    }
                }
            }
        }
        if ((D_001D52FC_004B8560->buttons & 0x10) && !(D_L01_001E1010 & 0x10)) {
            *confirmed = 0;
            D_L01_00244740_004B8560.state = 4;
        } else if ((D_001D52FC_004B8560->buttons & 0x40) && !(D_L01_001E1010 & 0x40)) {
            *confirmed = 1;
            D_L01_00244740_004B8560.state = 4;
        }
    } else if (D_L01_00244740_004B8560.state == 4) {
        if (*confirmed == 1) {
            if (D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].ammo == 1) {
                Info_004BC0F8 *info = &D_L01_002C5640_004B8560[D_001425C0[D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id]];

                total = info->cost * D_L01_001E1014;
            } else {
                total = func_L01_004B6C98();
            }
            if (D_00142660_004B8560[0] < total
                && (D_L01_002C5640_004B8560 + D_001425C0[D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id])->max
                    <= D_001427F0[D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id]) {
                func_0039FE80(0, 17, D_L01_00244740_004B8560.sound);
            } else if (D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].ammo == 1) {
                if (D_001427F0[D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id] < (D_L01_002C5640_004B8560 + D_001425C0[D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id])->max) {
                    if (!D_L01_00244740_004B8560.mode) {
                        amount = (D_L01_002C5640_004B8560 + D_001425C0[D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id])->cost * D_L01_001E1014;
                    } else {
                        amount = (D_L01_002C5640_004B8560 + D_001425C0[D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id])->altCost * D_L01_001E1014;
                    }
                    if (D_00142660_004B8560[0] >= amount) {
                        if (D_001427F0[D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id] > (D_L01_002C5640_004B8560 + D_001425C0[D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id])->max) {
                            D_001427F0[D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id]
                                = (D_L01_002C5640_004B8560 + D_001425C0[D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id])->max;
                        }
                        left = D_L01_001E1014;
                        left -= func_L01_0050D980(D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id, left);
                        if (!D_L01_00244740_004B8560.mode) {
                            unit = D_L01_002C5640_004B8560[D_001425C0[D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id]].cost;
                        } else {
                            unit = D_L01_002C5640_004B8560[D_001425C0[D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id]].altCost;
                        }
                        D_00142660_004B8560[0] -= unit * left;
                        func_L01_004B6E88(0);
                        func_L01_004B8520(func_0037DF98(0x17A));
                        func_0039FE80(7, 17, D_L01_00244740_004B8560.sound);
                    } else {
                        func_L01_004B8520(func_0037DF98(0x17B));
                        func_0039FE80(0, 17, D_L01_00244740_004B8560.sound);
                    }
                } else {
                    func_0039FE80(0, 17, D_L01_00244740_004B8560.sound);
                }
            } else {
                price = func_L01_004B6C98();
                if (D_00142660_004B8560[0] >= price) {
                    id = D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id;
                    if (!D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].b17) {
                        func_L01_00416B38(id);
                        func_L01_00449AE8(id);
                    }
                    D_L01_00244740_004B8560.equipped = id;
                    if (D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].b16) {
                        D_L01_00244740_004B8560.changed = 1;
                    }
                    if (D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].b17) {
                        func_L01_004176F8(D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].id);
                    }
                    func_L01_00419710_004B8560(D_L01_00244740_004B8560.equipped);
                    D_00142660_004B8560[0] -= price;
                    func_L01_004B6E88(0);
                    if (D_L01_00244740_004B8560.previous != -1) {
                        func_0038ED78(D_L01_00244740_004B8560.previous, 0);
                    }
                    D_L01_00244740_004B8560.previous = -1;
                    if (D_L01_00244740_004B8560.slots[D_L01_00244740_004B8560.selected].ammo == 1) {
                        func_L01_004789D0(18000000);
                    } else if (D_L01_00244740_004B8560.count - 1 < D_L01_00244740_004B8560.selected) {
                        D_L01_00244740_004B8560.selected = D_L01_00244740_004B8560.count - 1;
                    }
                    func_L01_004B8520(func_0037DF98(0x17A));
                    func_0039FE80(7, 17, D_L01_00244740_004B8560.sound);
                } else {
                    func_L01_004B8520(func_0037DF98(0x17B));
                    func_0039FE80(0, 17, D_L01_00244740_004B8560.sound);
                }
            }
        } else {
            func_0039FE80(0, 17, D_L01_00244740_004B8560.sound);
        }
        D_L01_00244740_004B8560.state = 0;
    }
}
/* localdecomp:end func_L01_004B8560 */
