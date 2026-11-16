/* NTSC-U draft (Codex wave 3): C of func_L01_004B8560, the NTSC-U twin of func_L01_004BC0F8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 412 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_004B8560", whose code is not the PAL one).
 * Worker's note: 412 diff; best log func_L01_004B8560.check10.log; complete retail-derived states 1/2/4, no jump table; 14 checks from 602 diff; check10/12/14 plateau at same score with differing code after pointer-scope and conditional-cost rewrites; mixed GP/absolute alias ...
 */
#include "common.h"

/* localdecomp:start func_L01_004B8560 */
typedef struct {
    s32 id;
    u8 ammo;
    u8 pad5[11];
    u8 flag16, flag17, all;
    u8 pad19;
} Slot_004B8560;
typedef struct {
    u8 pad0[0x28]; void *sound;
    u8 pad2C[0x30]; s32 mode;
    u8 pad60[8]; s32 equipped;
    u8 pad6C[12]; s32 previous;
    u8 pad7C[4]; s32 selected, state;
    u8 pad88[0xB8]; Slot_004B8560 slots[76];
    u8 pad730[16]; s32 count;
    u8 pad744[16]; s32 allCost;
    u8 pad758[28]; s32 changed;
} Menu_004B8560;
typedef struct {
    u8 pad0[0x84]; u16 cost, altCost;
    u8 pad88[2]; u16 maximum;
    u8 pad8C[0x64];
} Info_004B8560;
typedef struct { u8 pad0[0x1C4]; u32 buttons; } Pad_004B8560;
extern Menu_004B8560 D_L01_00244740[];
extern Info_004B8560 D_L01_002C5640[];
extern u8 D_00142CA0[], D_001425C0[];
extern s32 D_001427F0[], D_00142660[];
extern Pad_004B8560 *D_001D52FC_sda;
extern Pad_004B8560 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern s32 D_L01_001E0FF8;
__asm__(".extern D_L01_001E0FF8, 16");
extern s32 D_L01_001E1008;
__asm__(".extern D_L01_001E1008, 16");
extern s32 D_L01_001E100C;
__asm__(".extern D_L01_001E100C, 16");
extern s32 D_L01_001E1010;
__asm__(".extern D_L01_001E1010, 16");
extern s32 D_L01_001E1014;
__asm__(".extern D_L01_001E1014, 16");
extern s32 D_L01_001E1014_004B8560;
__asm__(".extern D_L01_001E1014_004B8560, 16");
extern s32 D_L01_001E100C_sda, D_L01_001E1010_sda, D_L01_001E1014_sda;
extern void func_0039FE80(s32, s32, void *);
extern char *func_0037DF98(s32);
extern void func_L01_004B8520(char *);
extern void func_L01_004B6E88(s32);
extern void func_L01_004BBDD8(void);
extern s32 func_L01_004B6C98(void);
extern s32 func_L01_0050D980(s32, s32);
extern void func_L01_00416B38(s32);
extern void func_L01_00449AE8(s32);
extern void func_L01_004176F8(s32);
extern void func_L01_00419710(s32);
extern void func_0038ED78(s32, s32);
extern void func_L01_004789D0(s32);

void func_L01_004B8560(u8 *confirmed, u8 *quantityMode) {
    s32 i, accepted, n, limit, price, id, left;
    u32 buttons;
    if (D_L01_00244740[0].state == 1) {
        if (D_L01_00244740[0].slots[D_L01_00244740[0].selected].all == 1) {
            if (D_L01_00244740[0].allCost <= 0) {
                func_0039FE80(2, 17, D_L01_00244740[0].sound);
                return;
            }
            accepted = 0;
            if (D_001D52FC_sda->buttons & 0x40) {
                for (i=0; i<156; i++) {
                    if (D_00142CA0[i]) {
                    Info_004B8560 *info=&D_L01_002C5640[D_001425C0[i]];
                    if (info->cost) {
                        if (D_L01_00244740[0].mode && (i==16 || i==17 || i==19 || i==21 || i==22)) continue;
                        if (D_001427F0[i] < info->maximum)
                            D_001427F0[i] = info->maximum;
                    }
                    }
                }
                D_00142660[0] -= D_L01_00244740[0].allCost;
                D_L01_001E0FF8 = 120;
                accepted = 1;
            } else if (D_001D52FC_sda->buttons & 0x10) {
                accepted = 1;
                func_0039FE80(0, 17, D_L01_00244740[0].sound);
            }
            func_L01_004B8520(func_0037DF98(0x17A));
            func_L01_004B6E88(0);
            func_0039FE80(7, 17, D_L01_00244740[0].sound);
            if (accepted) {
                D_L01_00244740[0].state=0;
                func_L01_004BBDD8();
            }
        } else {
            Info_004B8560 *info=&D_L01_002C5640[D_001425C0[D_L01_00244740[0].slots[D_L01_00244740[0].selected].id]];
            u16 unitCost=info->cost;
            if (unitCost)
                D_L01_001E1014_sda = D_00142660[0] / unitCost;
            else D_L01_001E1014 = 0;
            info=&D_L01_002C5640[D_001425C0[D_L01_00244740[0].slots[D_L01_00244740[0].selected].id]];
            n=info->maximum-D_001427F0[D_L01_00244740[0].slots[D_L01_00244740[0].selected].id];
            if (n < D_L01_001E1014) D_L01_001E1014_sda=n;
            *confirmed=0;
            *quantityMode=0;
            if (D_L01_00244740[0].slots[D_L01_00244740[0].selected].ammo == 1 && D_001427F0[D_L01_00244740[0].slots[D_L01_00244740[0].selected].id] >= D_L01_002C5640[D_001425C0[D_L01_00244740[0].slots[D_L01_00244740[0].selected].id]].maximum) {
                func_0039FE80(2, 17, D_L01_00244740[0].sound);
            } else if (D_L01_00244740[0].slots[D_L01_00244740[0].selected].ammo == 1) {
                if (D_00142660[0] < D_L01_002C5640[D_001425C0[D_L01_00244740[0].slots[D_L01_00244740[0].selected].id]].cost)
                    func_0039FE80(2, 17, D_L01_00244740[0].sound);
                else *quantityMode=1;
            } else {
                price=func_L01_004B6C98();
                if (D_00142660[0] < price) func_0039FE80(2, 0, D_L01_00244740[0].sound);
            }
            D_L01_00244740[0].state=2;
        }
    } else if (D_L01_00244740[0].state == 2) {
        Pad_004B8560 *pad=D_001D52FC_sda;
        if (*quantityMode == 1) {
            if ((pad->buttons & 0x8000) || (D_L01_001E1008>=16 && !(D_L01_001E1008&7)) || D_L01_001E1008>=48) {
                if (D_L01_001E1014>=2) {
                    D_L01_001E1014_sda = D_L01_001E1014-1;
                    if (!(D_L01_001E1008&3) || D_L01_001E1008<16) {
                        func_0039FE80(1, 17, D_L01_00244740[0].sound);
                        pad=D_001D52FC;
                    }
                }
            }
            if ((pad->buttons & 0x2000) || (D_L01_001E100C>=16 && !(D_L01_001E100C&7)) || D_L01_001E100C>=48) {
                Info_004B8560 *info2=&D_L01_002C5640[D_001425C0[D_L01_00244740[0].slots[D_L01_00244740[0].selected].id]];
                if (info2->cost) {
                    limit = D_00142660[0] / info2->cost;
                    n = info2->maximum - D_001427F0[D_L01_00244740[0].slots[D_L01_00244740[0].selected].id];
                    if (n < limit) limit=n;
                    if (D_L01_001E1014 < limit) {
                        D_L01_001E1014_sda=D_L01_001E1014+1;
                        if (!(D_L01_001E100C_sda&3) || D_L01_001E100C_sda<16)
                            func_0039FE80(1, 17, D_L01_00244740[0].sound);
                    }
                }
                pad=D_001D52FC;
            }
        }
        if ((pad->buttons & 0x10) && !(D_L01_001E1010&0x10)) {
            *confirmed=0;
            D_L01_00244740[0].state=4;
        } else if ((pad->buttons & 0x40) && !(D_L01_001E1010_sda&0x40)) {
            *confirmed=1;
            D_L01_00244740[0].state=4;
        }
    } else if (D_L01_00244740[0].state == 4) {
        if (*confirmed == 1) {
            if (D_L01_00244740[0].slots[D_L01_00244740[0].selected].ammo == 1)
                price = D_L01_002C5640[D_001425C0[D_L01_00244740[0].slots[D_L01_00244740[0].selected].id]].cost * D_L01_001E1014;
            else price=func_L01_004B6C98();
            if (D_00142660[0] < price && D_001427F0[D_L01_00244740[0].slots[D_L01_00244740[0].selected].id] >= D_L01_002C5640[D_001425C0[D_L01_00244740[0].slots[D_L01_00244740[0].selected].id]].maximum) {
                func_0039FE80(0, 17, D_L01_00244740[0].sound);
            } else if (D_L01_00244740[0].slots[D_L01_00244740[0].selected].ammo == 1) {
                if (D_001427F0[D_L01_00244740[0].slots[D_L01_00244740[0].selected].id] < D_L01_002C5640[D_001425C0[D_L01_00244740[0].slots[D_L01_00244740[0].selected].id]].maximum) {
                    if (D_L01_00244740[0].mode)
                        price = D_L01_002C5640[D_001425C0[D_L01_00244740[0].slots[D_L01_00244740[0].selected].id]].altCost;
                    else price = D_L01_002C5640[D_001425C0[D_L01_00244740[0].slots[D_L01_00244740[0].selected].id]].cost;
                    if (D_00142660[0] >= price * D_L01_001E1014) {
                        if (D_L01_002C5640[D_001425C0[D_L01_00244740[0].slots[D_L01_00244740[0].selected].id]].maximum < D_001427F0[D_L01_00244740[0].slots[D_L01_00244740[0].selected].id])
                            D_001427F0[D_L01_00244740[0].slots[D_L01_00244740[0].selected].id]=D_L01_002C5640[D_001425C0[D_L01_00244740[0].slots[D_L01_00244740[0].selected].id]].maximum;
                        left=D_L01_001E1014;
                        left-=func_L01_0050D980(D_L01_00244740[0].slots[D_L01_00244740[0].selected].id,left);
                        if (!D_L01_00244740[0].mode)
                            price=D_L01_002C5640[D_001425C0[D_L01_00244740[0].slots[D_L01_00244740[0].selected].id]].cost;
                        else price=D_L01_002C5640[D_001425C0[D_L01_00244740[0].slots[D_L01_00244740[0].selected].id]].altCost;
                        D_00142660[0]-=left*price;
                        func_L01_004B6E88(0);
                        func_L01_004B8520(func_0037DF98(0x17A));
                        func_0039FE80(7,17,D_L01_00244740[0].sound);
                    } else {
                        func_L01_004B8520(func_0037DF98(0x17B));
                        func_0039FE80(0,17,D_L01_00244740[0].sound);
                    }
                } else func_0039FE80(0,17,D_L01_00244740[0].sound);
            } else {
                price=func_L01_004B6C98();
                if (D_00142660[0] >= price) {
                    id=D_L01_00244740[0].slots[D_L01_00244740[0].selected].id;
                    if (!D_L01_00244740[0].slots[D_L01_00244740[0].selected].flag17) {
                        func_L01_00416B38(id);
                        func_L01_00449AE8(id);
                    }
                    D_L01_00244740[0].equipped=id;
                    if (D_L01_00244740[0].slots[D_L01_00244740[0].selected].flag16) D_L01_00244740[0].changed=1;
                    if (D_L01_00244740[0].slots[D_L01_00244740[0].selected].flag17) func_L01_004176F8(D_L01_00244740[0].slots[D_L01_00244740[0].selected].id);
                    func_L01_00419710(D_L01_00244740[0].equipped);
                    D_00142660[0]-=price;
                    func_L01_004B6E88(0);
                    if (D_L01_00244740[0].previous != -1) func_0038ED78(D_L01_00244740[0].previous,0);
                    D_L01_00244740[0].previous=-1;
                    if (D_L01_00244740[0].slots[D_L01_00244740[0].selected].ammo==1) func_L01_004789D0(18000000);
                    else if (D_L01_00244740[0].count-1 < D_L01_00244740[0].selected) D_L01_00244740[0].selected=D_L01_00244740[0].count-1;
                    func_L01_004B8520(func_0037DF98(0x17A));
                    func_0039FE80(7,17,D_L01_00244740[0].sound);
                } else {
                    func_L01_004B8520(func_0037DF98(0x17B));
                    func_0039FE80(0,17,D_L01_00244740[0].sound);
                }
            }
        } else func_0039FE80(0,17,D_L01_00244740[0].sound);
        D_L01_00244740[0].state=0;
    }
}
/* localdecomp:end func_L01_004B8560 */
