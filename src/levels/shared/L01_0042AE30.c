#include "common.h"

typedef struct {
    s32 sector;
    s32 size;
} Entry_0042B068;
typedef struct {
    u8 pad0[0x79A4];
    s32 base;
    u8 pad79A8[0x28];
    Entry_0042B068 entries[1];
} Table_0042B068;

INCLUDE_ASM("asm/levels", func_L01_0042AE30);

/* localdecomp:start func_L01_0042AEC0 */
typedef struct {
    s32 cur;
    u8 pad4[8];
    s32 count;
    u8 pad10[16];
    u8 entries[1][16];
} Struct_001F3FC0;

extern Struct_001F3FC0 D_L01_001F3F40;
extern s32 func_L01_0040F5B8(s32, void *, void *);

s32 func_L01_0042AEC0(s32 a0)
{
    s32 i;

    for (i = D_L01_001F3F40.count - 1; i >= 0; i--) {
        if (func_L01_0040F5B8(a0, D_L01_001F3F40.entries[i], D_L01_001F3F40.entries[i + 2])) {
            return i + 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0042AEC0 */

INCLUDE_ASM("asm/levels", func_L01_0042AF50);

/* localdecomp:start func_L01_0042B068 */
extern Table_0042B068 D_00160C40;
extern f32 D_L01_001DF950;
extern s32 D_L01_001E1060[];
extern s32 D_L01_001E1068;
extern s32 D_L01_001E1074;
extern u8 *D_L01_001E0E90;
extern s32 D_L01_001E0E94;

extern void func_L01_004AB188(s32, s32, s32, s32, s32);
extern void func_003A5430(void);
extern void func_003A1C28(void);
extern void func_0038A238(s32);
extern void func_003A92F0(s32);
extern void func_L01_00425198(void);
extern void func_003A26F0(s32 *, s32, s32);
extern void func_11F0A0(s32);
extern void func_003A0760(s32 *, s32);
extern void func_00399E80(s32, s32);
extern void func_L01_00427E58(s32);
extern void func_003D0180(void *);
extern void func_003D9DA8(void);
extern void func_L01_0042AE30(void);
extern void func_L01_0045E798(s32);
extern void func_L01_0042AF50(s32);
extern void func_003A1930(s32, s32, s32);
extern s32 func_003A0EA8(s32);
extern void func_L01_0045F328(s32);

void func_L01_0042B068(s32 index, s32 argument)
{
    s32 *root;
    s32 *block, *first, *second;
    s32 i;

    if (D_L01_001F3F40.cur == index) {
        return;
    }
    func_L01_004AB188(0, 0, 0, 0, 0);
    func_003A5430();
    func_003A1C28();
    if (D_L01_001DF950 >= 0.75f) {
        func_0038A238(2);
    } else {
        func_003A92F0(1);
    }
    D_L01_001F3F40.cur = index;
    root = (s32 *)&D_L01_001F3F40;
    block = (s32 *)D_L01_001E1060[0];
    D_L01_001E1068 = D_L01_001E1060[D_L01_001E1074];
    func_L01_00425198();
    func_003A26F0(block, D_00160C40.entries[index].sector + D_00160C40.base, D_00160C40.entries[index].size);
    first = (s32 *)((u8 *)block + block[0]);
    second = (s32 *)((u8 *)block + block[1]);
    func_11F0A0(0);
    func_003A0760(first, root[2]);
    func_003A0760(second, root[1]);
    func_11F0A0(0);
    func_00399E80(root[2], root[4]);
    func_L01_00427E58(root[1]);
    {
        s32 count = D_L01_001E0E94;
        if (count > 0) {
            u16 *p = (u16 *)(D_L01_001E0E90 + 0x36);
            do {
                *p = 0xffff;
                p += 32;
            } while (--count);
        }
    }
    i = 0;
    while (i < D_L01_001E0E94) {
        u16 *p = (u16 *)0x70003000;
        s32 n = 0;
        while (n < 1023 && i < D_L01_001E0E94) {
            *p++ = i;
            n++;
            i++;
        }
        *p = 0xffff;
        func_003D0180((void *)0x70003000);
    }
    func_003D9DA8();
    func_L01_0042AE30();
    func_L01_0045E798(index);
    func_L01_0042AF50(index);
    func_003A1930(argument, 1, 1024);
    if (func_003A0EA8(2)) {
        func_L01_0045F328(0);
    }
}
/* localdecomp:end func_L01_0042B068 */
