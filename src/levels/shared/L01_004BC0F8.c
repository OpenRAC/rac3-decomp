#include "common.h"

typedef struct {
    s32 id;
    u8 pad4[12];
    u8 b16;
    u8 b17;
    u8 pad18[2];
} Slot_004B6C98;
typedef struct {
    u8 pad0[128];
    s32 cur;
    u8 pad84[188];
    Slot_004B6C98 slots[79];
    u8 pad76C[16];
    s32 unk77C;
} S_00244740;
typedef struct {
    u8 pad0[124];
    s32 value;
    u8 pad80[112];
} S_002C5640;
typedef struct {
    u8 pad0[124];
    s32 value;
    u8 pad80[112];
} Info_004B6C98;
typedef struct {
    u8 active;
    u8 pad[0xEF];
} Ent4B6DF8;
typedef struct {
    s32 id;
    s32 val;
    s32 idx;
    s32 pad;
} Item_004B7420;
typedef struct {
    u8 pad0[320];
    Item_004B7420 items[96];
    s32 count;
} List_004B7420;
typedef struct {
    s32 v[5];
} Tbl_004B7420;
typedef struct { u8 p0[72]; s32 f72; } A_4BBAF0;
typedef struct {
    s32 type;
    u8 b4;
    u8 p5[11];
    u8 b16;
    u8 p17[2];
    u8 b19;
} E_4BBAF0;
typedef struct {
    u8 p0[320];
    E_4BBAF0 e[76];
    u8 p1[1856 - 320 - 76 * 20];
    s32 count;
    u8 p2[44];
    s32 f1904;
    u8 p3[4];
    s32 f1912;
} B_4BBAF0;
typedef struct {
    char pad[1916];
    s32 v;
} Unk244740;
typedef struct {
    s32 id;
    s32 f4;
    s32 kind;
    s32 color;
    u8 pad[32];
} Ent4BD808;

/* declared by functions of L01_004BA278.c, which this file was cut from */
extern u8 D_001425C0[];
extern s32 func_00381FF0(s32);

/* localdecomp:start func_L01_004BC0F8 */
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
extern Menu_004BC0F8 D_L01_002446C0_004BC0F8;
extern Info_004BC0F8 D_L01_002C5600_004BC0F8[];
extern u8 D_00142CA0[];
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern s32 D_00142660_004BC0F8[];
extern Pad_004BC0F8 *D_001D52FC_004BC0F8;
extern s32 D_L01_001E0F78;
extern s32 D_L01_001E0F88;
extern s32 D_L01_001E0F8C;
extern s32 D_L01_001E0F90;
extern s32 D_L01_001E0F94;
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_00381FF0(s32);
extern void func_L01_004BC0B8(s32 a0);
extern void func_L01_004BAA20(s32);
extern void func_L01_004BF980(void);
extern s32 func_L01_004BA830(void);
extern s32 func_L01_00511958(s32, s32);
extern void func_L01_00419188(s32);
extern void func_L01_0044CD60(s32);
extern void func_L01_00419D48(s32);
extern void func_L01_0041BE20_004BC0F8(s32);
extern void func_003935B0(s32, s32);
extern void func_L01_0047C220(s32);

void func_L01_004BC0F8(u8 *confirmed, u8 *quantity) {
    s32 i;
    s32 accepted;
    s32 price;
    s32 id;
    s32 left;
    s32 total;
    s32 unit;
    s32 amount;

    if (D_L01_002446C0_004BC0F8.state == 1) {
        if (D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].all == 1) {
            if (D_L01_002446C0_004BC0F8.allCost <= 0) {
                func_003A52A0(2, 17, D_L01_002446C0_004BC0F8.sound);
                return;
            }
            accepted = 0;
            if (D_001D52FC_004BC0F8->buttons & 0x40) {
                for (i = 0; i < 156; i++) {
                    if (D_00142CA0[i]) {
                        Info_004BC0F8 *info = &D_L01_002C5600_004BC0F8[D_001425C0[i]];
                        if (info->cost) {
                            if (D_L01_002446C0_004BC0F8.mode && (i == 16 || i == 17 || i == 19 || i == 21 || i == 22)) {
                                continue;
                            }
                            if (D_001427F0[i] < info->max) {
                                D_001427F0[i] = info->max;
                            }
                        }
                    }
                }
                D_00142660_004BC0F8[0] -= D_L01_002446C0_004BC0F8.allCost;
                D_L01_001E0F78 = 100;
                accepted = 1;
            } else if (D_001D52FC_004BC0F8->buttons & 0x10) {
                accepted = 1;
                func_003A52A0(0, 17, D_L01_002446C0_004BC0F8.sound);
            }
            func_L01_004BC0B8(func_00381FF0(0x17A));
            func_L01_004BAA20(0);
            func_003A52A0(7, 17, D_L01_002446C0_004BC0F8.sound);
            if (accepted) {
                D_L01_002446C0_004BC0F8.state = 0;
                func_L01_004BF980();
            }
        } else {
            Info_004BC0F8 *info;
            s32 n;

            info = &D_L01_002C5600_004BC0F8[D_001425C0[D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id]];
            if (info->cost) {
                D_L01_001E0F94 = D_00142660_004BC0F8[0] / info->cost;
            } else {
                D_L01_001E0F94 = 0;
            }
            n = (D_L01_002C5600_004BC0F8 + *(D_001425C0 + D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id))->max - D_001427F0[D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id];
            if (n < D_L01_001E0F94) {
                D_L01_001E0F94 = n;
            }
            *confirmed = 0;
            *quantity = 0;
            if (D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].ammo == 1
                && D_001427F0[D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id]
                    >= D_L01_002C5600_004BC0F8[D_001425C0[D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id]].max) {
                func_003A52A0(2, 17, D_L01_002446C0_004BC0F8.sound);
            } else if (D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].ammo == 1) {
                if (D_00142660_004BC0F8[0] < (D_L01_002C5600_004BC0F8 + D_001425C0[D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id])->cost) {
                    func_003A52A0(2, 17, D_L01_002446C0_004BC0F8.sound);
                } else {
                    *quantity = 1;
                }
            } else {
                price = func_L01_004BA830();
                if (D_00142660_004BC0F8[0] < price) {
                    func_003A52A0(2, 0, D_L01_002446C0_004BC0F8.sound);
                }
            }
            D_L01_002446C0_004BC0F8.state = 2;
        }
    } else if (D_L01_002446C0_004BC0F8.state == 2) {
        if (*quantity == 1) {
            if ((D_001D52FC_004BC0F8->buttons & 0x8000) || (D_L01_001E0F88 >= 16 && !(D_L01_001E0F88 & 7)) || D_L01_001E0F88 >= 48) {
                if (D_L01_001E0F94 >= 2) {
                    D_L01_001E0F94 = D_L01_001E0F94 - 1;
                    if (!(D_L01_001E0F88 & 3) || D_L01_001E0F88 < 16) {
                        func_003A52A0(1, 17, D_L01_002446C0_004BC0F8.sound);
                    }
                }
            }
            if ((D_001D52FC_004BC0F8->buttons & 0x2000) || (D_L01_001E0F8C >= 16 && !(D_L01_001E0F8C & 7)) || D_L01_001E0F8C >= 48) {
                Info_004BC0F8 *info;
                u16 cost;
                s32 limit;
                s32 n;

                info = &D_L01_002C5600_004BC0F8[D_001425C0[D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id]];
                if (info->cost) {
                    cost = info->cost;
                    limit = D_00142660_004BC0F8[0] / cost;
                    n = info->max - D_001427F0[D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id];
                    if (n < limit) {
                        limit = n;
                    }
                    if (D_L01_001E0F94 < limit) {
                        D_L01_001E0F94 = D_L01_001E0F94 + 1;
                        if (!(D_L01_001E0F8C & 3) || D_L01_001E0F8C < 16) {
                            func_003A52A0(1, 17, D_L01_002446C0_004BC0F8.sound);
                        }
                    }
                }
            }
        }
        if ((D_001D52FC_004BC0F8->buttons & 0x10) && !(D_L01_001E0F90 & 0x10)) {
            *confirmed = 0;
            D_L01_002446C0_004BC0F8.state = 4;
        } else if ((D_001D52FC_004BC0F8->buttons & 0x40) && !(D_L01_001E0F90 & 0x40)) {
            *confirmed = 1;
            D_L01_002446C0_004BC0F8.state = 4;
        }
    } else if (D_L01_002446C0_004BC0F8.state == 4) {
        if (*confirmed == 1) {
            if (D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].ammo == 1) {
                Info_004BC0F8 *info = &D_L01_002C5600_004BC0F8[D_001425C0[D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id]];

                total = info->cost * D_L01_001E0F94;
            } else {
                total = func_L01_004BA830();
            }
            if (D_00142660_004BC0F8[0] < total
                && (D_L01_002C5600_004BC0F8 + D_001425C0[D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id])->max
                    <= D_001427F0[D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id]) {
                func_003A52A0(0, 17, D_L01_002446C0_004BC0F8.sound);
            } else if (D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].ammo == 1) {
                if (D_001427F0[D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id] < (D_L01_002C5600_004BC0F8 + D_001425C0[D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id])->max) {
                    if (!D_L01_002446C0_004BC0F8.mode) {
                        amount = (D_L01_002C5600_004BC0F8 + D_001425C0[D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id])->cost * D_L01_001E0F94;
                    } else {
                        amount = (D_L01_002C5600_004BC0F8 + D_001425C0[D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id])->altCost * D_L01_001E0F94;
                    }
                    if (D_00142660_004BC0F8[0] >= amount) {
                        if (D_001427F0[D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id] > (D_L01_002C5600_004BC0F8 + D_001425C0[D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id])->max) {
                            D_001427F0[D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id]
                                = (D_L01_002C5600_004BC0F8 + D_001425C0[D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id])->max;
                        }
                        left = D_L01_001E0F94;
                        left -= func_L01_00511958(D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id, left);
                        if (!D_L01_002446C0_004BC0F8.mode) {
                            unit = D_L01_002C5600_004BC0F8[D_001425C0[D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id]].cost;
                        } else {
                            unit = D_L01_002C5600_004BC0F8[D_001425C0[D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id]].altCost;
                        }
                        D_00142660_004BC0F8[0] -= unit * left;
                        func_L01_004BAA20(0);
                        func_L01_004BC0B8(func_00381FF0(0x17A));
                        func_003A52A0(7, 17, D_L01_002446C0_004BC0F8.sound);
                    } else {
                        func_L01_004BC0B8(func_00381FF0(0x17B));
                        func_003A52A0(0, 17, D_L01_002446C0_004BC0F8.sound);
                    }
                } else {
                    func_003A52A0(0, 17, D_L01_002446C0_004BC0F8.sound);
                }
            } else {
                price = func_L01_004BA830();
                if (D_00142660_004BC0F8[0] >= price) {
                    id = D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id;
                    if (!D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].b17) {
                        func_L01_00419188(id);
                        func_L01_0044CD60(id);
                    }
                    D_L01_002446C0_004BC0F8.equipped = id;
                    if (D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].b16) {
                        D_L01_002446C0_004BC0F8.changed = 1;
                    }
                    if (D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].b17) {
                        func_L01_00419D48(D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].id);
                    }
                    func_L01_0041BE20_004BC0F8(D_L01_002446C0_004BC0F8.equipped);
                    D_00142660_004BC0F8[0] -= price;
                    func_L01_004BAA20(0);
                    if (D_L01_002446C0_004BC0F8.previous != -1) {
                        func_003935B0(D_L01_002446C0_004BC0F8.previous, 0);
                    }
                    D_L01_002446C0_004BC0F8.previous = -1;
                    if (D_L01_002446C0_004BC0F8.slots[D_L01_002446C0_004BC0F8.selected].ammo == 1) {
                        func_L01_0047C220(15000000);
                    } else if (D_L01_002446C0_004BC0F8.count - 1 < D_L01_002446C0_004BC0F8.selected) {
                        D_L01_002446C0_004BC0F8.selected = D_L01_002446C0_004BC0F8.count - 1;
                    }
                    func_L01_004BC0B8(func_00381FF0(0x17A));
                    func_003A52A0(7, 17, D_L01_002446C0_004BC0F8.sound);
                } else {
                    func_L01_004BC0B8(func_00381FF0(0x17B));
                    func_003A52A0(0, 17, D_L01_002446C0_004BC0F8.sound);
                }
            }
        } else {
            func_003A52A0(0, 17, D_L01_002446C0_004BC0F8.sound);
        }
        D_L01_002446C0_004BC0F8.state = 0;
    }
}
/* localdecomp:end func_L01_004BC0F8 */
