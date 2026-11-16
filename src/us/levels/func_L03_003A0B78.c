#include "common.h"

/* NTSC-U counterpart of func_L03_003A2398 (src/levels/03_starship_phoenix/L03_003A2398.c) */
void func_L01_00441FB8(s32, s32, s32);

/* localdecomp:start func_L03_003A0B78 */
/* localdecomp:start func_L03_003A0B78 */
typedef struct T_003A2398 {
    char pad0[0x35C];
    void *owner;
    s32 flag;
    char pad1[0x25C0 - 0x364];
    char *cur;
} T_003A2398;
extern T_003A2398 D_001A4BE0_003A0B78;
extern s32 D_L03_002A14A0[];
extern s32 D_L03_002D09F0[];
extern s32 D_001A71A0[];
extern s32 D_001DFA1C_sda;
extern s32 D_001DE430_sda; __asm__(".extern D_001DE430_sda, 4");
extern char *D_001D52FC;
extern u8 D_00142765[];
extern u32 D_00142C1C[];

extern s32 func_003883C8(void *);
extern f32 func_00388978(f32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L02_003B8810(void *, void *);
extern s32 func_L01_004B6C68(void);
extern void func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);
extern void func_00399F90(void);
extern void func_L01_00452F40(void *, s32);
extern void func_0039FE80(s32, s32, void *);
extern f32 func_0037E2A8(void);
extern void func_L01_0050DA68(void *, s32, f32);
extern void func_L01_00443648(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern void func_L03_003A1370(void *);
extern void func_L03_003A11C8(s32);
extern void func_L03_003A0F70(void *, void *);
extern s32 func_L01_0050DAC0(void);
extern void func_L01_004FC518(s32, s32);
extern void func_L03_003A0388(void *, int);
extern s32 func_L01_004A72A8(s32, s32, s32, s32);

void func_L03_003A0B78(char *arg0) {
    char *p = *(char **)(arg0 + 0x68);
    f32 f;
    if (func_003883C8(p + 0x24) != 0) {
        *(s16 *)(p + 0x24) = 60;
    }
    f = func_00388978((f32)*(s16 *)(p + 0x24) * 6.2831855f / 60.0f);
    *(s32 *)(arg0 + 0x78) = func_003894A0(0x80B0B0B0, 0x80505050, f * 0.5f + 0.5f);
    switch (*(u8 *)(arg0 + 0x20)) {
    case 0:
        func_L02_003B8810((void *)D_001A71A0[0], D_L03_002A14A0);
        func_L01_00441FB8((s32)arg0, 2, -1);
        break;
    case 1:
        break;
    case 2:
        if (D_001A4BE0_003A0B78.flag != 0 && D_001A4BE0_003A0B78.owner == arg0) {
            if (func_L01_004B6C68() == 0) {
                func_L01_00441FB8((s32)arg0, 3, -1);
            }
        }
        break;
    case 3:
        func_L01_0044F2E8(0, 12, 0xA27, 1, 0, 0, 0);
        if (D_001A4BE0_003A0B78.flag == 0 || D_001A4BE0_003A0B78.owner != arg0) {
            func_L01_00441FB8((s32)arg0, 2, -1);
        }
        if (D_L03_002D09F0[0] == 12) {
            char *s = D_001D52FC;
            if (*(s32 *)(s + 0x1A4) & 0x10) {
                D_00142765[0] = 1;
                func_00399F90();
                if ((D_00142C1C[0] & 0x40000000) == 0) {
                    char *r = (char *)D_001DFA1C_sda + (*(s32 *)(p + 8) << 8);
                    func_L01_00452F40(r, 1);
                    *(u8 *)(r + 0x30) = 0xFF;
                    (*(void (**)(char *))(r + 0x64))(r);
                    func_L01_00441FB8((s32)arg0, 2, -1);
                } else {
                    f32 g;
                    f32 one = 1.0f;
                    func_0039FE80(0, 0, arg0);
                    *(u16 *)(D_001A4BE0_003A0B78.cur + 0x34) |= 0x2000;
                    g = func_0037E2A8();
                    *(f32 *)(p + 0x18) = g;
                    *(f32 *)(p + 0x14) = 0.0290888231248f;
                    *(f32 *)(p + 0x1C) = 0.8f;
                    *(f32 *)(p + 0x20) = 0.8f;
                    *(f32 *)(p + 0xC) = one;
                    *(f32 *)(p + 0x10) = 0.3f;
                    func_L01_0050DA68(arg0 + 0x10, 0, *(f32 *)(arg0 + 0xF8));
                    func_L01_00443648((u8 *)arg0, (u8 *)arg0 + 0x10, 0x10000, 0, 1, 0, 1.5f, 20.0f, one);
                    func_L01_00441FB8((s32)arg0, 4, -1);
                }
            }
        }
        break;
    case 4:
        func_L03_003A1370(arg0);
        func_L03_003A11C8(-1);
        func_L03_003A0F70(arg0, &D_001DE430_sda);
        *(u16 *)(arg0 + 0x34) &= 0xFFBE;
        *(u16 *)(arg0 + 0x34) |= *(u16 *)(*(char **)(arg0 + 0x24) + 0x44) & 0x1000;
        *(s32 *)(arg0 + 0x98) = *(s32 *)(*(char **)(arg0 + 0x24) + 0x10);
        if (func_L01_0050DAC0() == 2) {
            func_L01_004FC518(0x74, 1);
            func_L01_00441FB8((s32)arg0, 5, -1);
        }
        break;
    case 5: {
        char *q;
        *(u16 *)(arg0 + 0x34) &= 0xFFBE;
        *(u16 *)(arg0 + 0x34) |= *(u16 *)(*(char **)(arg0 + 0x24) + 0x44) & 0x1000;
        *(s32 *)(arg0 + 0x98) = *(s32 *)(*(char **)(arg0 + 0x24) + 0x10);
        q = D_001A4BE0_003A0B78.cur;
        if ((u8)q[0x23] >= 0xD) {
            func_L03_003A11C8(-1);
            func_L03_003A0F70(arg0, &D_001DE430_sda);
            func_L03_003A1370(arg0);
        } else {
            char *w;
            *((u8 *)&D_001A4BE0_003A0B78 + 0x25E5) = 1;
            w = (char *)D_001DFA1C_sda + (*(s32 *)p << 8);
            func_L03_003A0388(w, 1);
            func_L01_004A72A8(1, 0, (s32)w, 0x19CD);
            func_L01_00441FB8((s32)arg0, 2, -1);
        }
        break;
    }
    }
}
/* localdecomp:end func_L03_003A0B78 */
