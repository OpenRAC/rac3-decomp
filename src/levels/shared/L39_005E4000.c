#include "common.h"

/* declared by functions of L39_005E31D8.c, which this file was cut from */
extern s32 func_L01_00517688(void);
extern void func_L39_005D6A78(s32, s32);
extern void func_L39_0061C0E0(s32, s32);
extern void func_L39_005D6468(s32, s32);
extern void func_L01_00353C80(s32);
extern void func_L01_00353C80(s32 a0);

/* localdecomp:start func_L39_005E4000 */
typedef struct {
    s32 id;
    u8 pad[12];
} E_005E1A90;
extern u8 D_L39_00243A38[8];
extern E_005E1A90 D_L39_0049A0F8[];
extern s32 func_L01_00517688(void);
extern void func_L01_00516AA0(s32, s32, s32);
void func_L39_005E4000(void) {
    s32 i;
    D_L39_00243A38[func_L01_00517688()] = 1;
    for (i = 0; i < 6; i++) {
        if ((u32)(D_L39_0049A0F8[i].id - 0xD0013) < 3) {
            func_L01_00516AA0(D_L39_0049A0F8[i].id, 1, 1);
        } else {
            func_L01_00516AA0(D_L39_0049A0F8[i].id, 1, 0);
        }
    }
    func_L01_00516AA0(0xD0028, 1, 0);
}
/* localdecomp:end func_L39_005E4000 */

/* localdecomp:start func_L39_005E40A8 */
extern E_005E1A90 D_L39_0049A0F8[];
extern s32 func_L01_00517688(void);
extern void func_L01_00516AA0(s32, s32, s32);
extern u8 D_L39_00243A38[8];

typedef struct {
    s32 id;
    s32 pad[3];
} Ent5E1B38;


void func_L39_005E40A8(void) {
    s32 i;

    D_L39_00243A38[func_L01_00517688()] = 0;
    for (i = 0; i < 6; i++) {
        if ((u32)(((Ent5E1B38 *)&D_L39_0049A0F8)[i].id - 0xD0013) < 3) {
            func_L01_00516AA0(((Ent5E1B38 *)&D_L39_0049A0F8)[i].id, 1, 0);
        } else {
            func_L01_00516AA0(((Ent5E1B38 *)&D_L39_0049A0F8)[i].id, 1, 1);
        }
    }
    func_L01_00516AA0(0xD0028, 1, 1);
}
/* localdecomp:end func_L39_005E40A8 */

/* localdecomp:start func_L39_005E4150 */
typedef struct {
    s32 id;
    s32 text;
    u8 f8;
    u8 f9;
    u8 padA[2];
    void (*fC)(void);
} E_005E4150;
typedef struct {
    u8 pad0[0x1C4];
    s32 buttons;
    s32 pad1C8;
    s32 f1CC;
} Pad_005E4150;
typedef struct {
    u8 pad0[0x2534];
    Pad_005E4150 *pad;
} Obj_005E4150;
extern s32 *D_00241120;
__asm__(".extern D_00241120, 16");
extern s32 D_001D8308_sda[] __attribute__((section(".sdata")));
extern s32 D_001D8318_sda[] __attribute__((section(".sdata")));
extern u8 D_001D8328_sda[4];
__asm__(".extern D_001D8308_sda, 4");
__asm__(".extern D_001D8318_sda, 4");
__asm__(".extern D_001D8328_sda, 4");
extern E_005E4150 D_L39_0049A0F8_005E4150[];
extern s32 func_L01_00517688(void);
extern void func_L39_005D6A78(s32, s32);
extern Obj_005E4150 *func_L39_0061BF38_005E4150(s32);
extern void func_L39_005F3548(s32, s32, s32);
extern void func_L39_005E4000(void);
extern void func_L39_005E40A8(void);
extern void func_L39_005E3B00(void);
extern void func_L39_005E3F08(void);
extern void func_L39_0061C0E0(s32, s32);
extern void func_L39_005D6468(s32, s32);
extern void func_L01_00353C80(s32);
extern s32 func_L01_005170B8(s32, s32);
void func_L39_005E4150(s32 arg) {
    s32 p;
    s32 i;
    s32 found;
    s32 b;
    Obj_005E4150 *o;
    p = func_L01_00517688();
    if (p >= *D_00241120) {
        return;
    }
    func_L39_005D6A78(p, 10);
    if (D_001D8318_sda[p] > 0) {
        D_001D8318_sda[p]--;
        return;
    }
    o = func_L39_0061BF38_005E4150(p);
    o->pad->f1CC = 2;
    b = o->pad->buttons;
    if (D_001D8328_sda[p] == 0) {
        if (b & 0x4000) {
            found = 0;
            do {
                if (++D_001D8308_sda[p] >= 6) {
                    D_001D8308_sda[p] = 0;
                }
                if (D_L39_0049A0F8_005E4150[D_001D8308_sda[p]].f8) {
                    found = 1;
                }
            } while (!found);
            func_L39_005F3548(3, 0, 0);
        } else if (b & 0x1000) {
            found = 0;
            do {
                if (--D_001D8308_sda[p] < 0) {
                    D_001D8308_sda[p] = 5;
                }
                if (D_L39_0049A0F8_005E4150[D_001D8308_sda[p]].f8) {
                    found = 1;
                }
            } while (!found);
            func_L39_005F3548(3, 0, 0);
        } else if (b & 0x40) {
            if (D_L39_0049A0F8_005E4150[D_001D8308_sda[p]].f8 && D_L39_0049A0F8_005E4150[D_001D8308_sda[p]].fC) {
                D_L39_0049A0F8_005E4150[D_001D8308_sda[p]].fC();
                func_L01_00353C80(arg);
                func_L39_005F3548(4, 0, 0);
            } else if (D_L39_0049A0F8_005E4150[D_001D8308_sda[p]].f9) {
                func_L39_005E4000();
            }
        } else if (b & 0x910) {
            func_L39_0061C0E0(p, 0);
            func_L39_005D6468(p, 0);
            func_L01_00353C80(arg);
        }
    } else {
        if (b & 0x10) {
            func_L39_005E40A8();
        } else if (b & 0x20) {
            func_L39_005E3B00();
        }
    }
    func_L39_005E3F08();
    for (i = 0; i < 6; i++) {
        if ((u32)(D_L39_0049A0F8_005E4150[i].id - 0xD0013) < 3) {
            continue;
        }
        if (D_L39_0049A0F8_005E4150[i].f8) {
            func_L01_005170B8(D_L39_0049A0F8_005E4150[i].id, 0x8066CCFF);
            if (i == D_001D8308_sda[p]) {
                func_L01_005170B8(D_L39_0049A0F8_005E4150[i].id, 0x66D6EEFA);
            }
        } else {
            func_L01_005170B8(D_L39_0049A0F8_005E4150[i].id, 0x80808080);
        }
    }
}
/* localdecomp:end func_L39_005E4150 */
