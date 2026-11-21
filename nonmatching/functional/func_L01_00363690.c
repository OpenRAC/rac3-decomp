/* functional: high. 313 words differ (loop/register allocation); algorithm checked block by block against asm: all constants, reward formula branches (D_001D7BE0 9/41, id parity, 7-special case), flag clear, delay-slot cases; draft's D_001A4BE0/D_001D545C_00363690 alias names and section attributes kept as given, integrator must unify them with the file's existing declarations */
/* localdecomp:start func_L01_00363690 */
#include "vu0.h"
extern s32 D_L01_001DD790;
__asm__(".extern D_L01_001DD790, 4");
extern s32 D_L01_0028F0C0[];
extern f32 D_L01_0028F110[];
typedef struct { u8 pad[0x21C]; s32 total; } Stats_00363690;
extern Stats_00363690 D_00142DE0 __attribute__((section(".sdata")));
extern u8 D_001A4BE0[] __attribute__((section(".sdata")));
extern s32 D_L01_001D7BE0 __attribute__((section(".data")));
extern s32 D_00142698 __attribute__((section(".data")));
extern s32 D_001D545C_00363690 __attribute__((section(".data")));
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 4");
extern u8 D_001BBE90[];
extern u8 D_L01_001D60E0[], D_L01_001D60D8[];
extern u8 D_0014275B[];
extern f32 D_L01_001DAA34;
__asm__(".extern D_L01_001DAA34, 4");
extern f32 D_L01_002F1600[];
extern u8 D_00142647[];
typedef struct { u8 pad[0x10]; S_38C110v position; } Vars_00363690;
void func_L01_00363690(u8 *self)
{
    extern void func_003C2F58(void *, s32, void *);
    extern void func_L01_00448340(void *, void *, void *, f32, f32, f32);
    extern u8 **func_L01_00448FB8(u8 *);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_0038D308(void *, void *);
    extern void func_003C7C38(u8 *);
    extern f32 func_0038CF00(void *, void *);
    extern DamageRecord_3631C8 *func_00382348(Moby_3631C8 *);
    extern s32 func_L01_00444350(void);
    extern s32 func_L01_004006C8(void *, u16, s16);
    extern s32 func_L01_0041A4F0(void);
    extern s32 func_003C4B50(Moby_3631C8 *);
    extern void func_L01_0033D0E8(void);
    extern void func_L01_00363468(u8 *);
    extern s32 func_003A52A0(s32, s32, void *);
    extern void func_L01_00451FB8(s32, s32, s32, s32);
    u8 *vars = *(u8 **)(self + 0x68);
    s32 i;
    for (i = 0; i < D_L01_001DD790;) {
        s32 next = i + 1;
        u8 **slot = (u8 **)&D_L01_0028F0C0[i];
        u8 *muzzle;
        if (*slot) {
            u8 **group;
            *(u16 *)(*slot + 0x34) |= 2;
            func_003C2F58(self, 0, &((Vars_00363690 *)vars)->position);
            func_L01_00448340(*slot + 0x10, &((Vars_00363690 *)vars)->position, &D_L01_0028F110[i],
                0.014000000432133675f, 0.024000000208616257f, 0.8000000715255737f);
            *(f32 *)(*slot + 0x2C) *= 0.97f;
            muzzle = vars + 0x10;
            group = func_L01_00448FB8(*slot);
            if (group) {
                u8 **children = group;
                s32 j;
                for (j = 3; j >= 0; j--, children++) {
                    if (*children) {
                        func_L01_00448340(*children + 0x10, muzzle, &D_L01_0028F110[i],
                            0.014000000432133675f, 0.024000000208616257f, 0.8000000715255737f);
                        *(f32 *)(*children + 0xF8) = func_0038DAB8(*(f32 *)(*children + 0xF8), 0.3f);
                        *(f32 *)(*children + 0xF0) = func_0038DAB8(*(f32 *)(*children + 0xF0), 0.1f);
                        *(f32 *)(*children + 0xF4) = func_0038DAB8(*(f32 *)(*children + 0xF4), -0.2f);
                        *(f32 *)(*children + 0x2C) *= 0.9519999623298645f;
                        func_0038D308(*children + 0xC0, *children + 0xF0);
                    }
                }
            }
            {
                
                *(f32 *)(((u8 *)D_L01_0028F0C0[i]) + 0xF8) = func_0038DAB8(*(f32 *)(((u8 *)D_L01_0028F0C0[i]) + 0xF8), 0.3f);
                *(f32 *)(((u8 *)D_L01_0028F0C0[i]) + 0xF0) = func_0038DAB8(*(f32 *)(((u8 *)D_L01_0028F0C0[i]) + 0xF0), 0.1f);
                *(f32 *)(((u8 *)D_L01_0028F0C0[i]) + 0xF4) = func_0038DAB8(*(f32 *)(((u8 *)D_L01_0028F0C0[i]) + 0xF4), -0.2f);
                func_0038D308(((u8 *)D_L01_0028F0C0[i]) + 0xC0, ((u8 *)D_L01_0028F0C0[i]) + 0xF0);
                func_003C7C38(((u8 *)D_L01_0028F0C0[i]));
                if (((u8 *)D_L01_0028F0C0[i]) && (func_0038CF00(((u8 *)D_L01_0028F0C0[i]) + 0x10, muzzle) < 0.1f ||
                    *(s32 *)(D_001A4BE0 + 0x25C4) == 0x35 || *(s32 *)(D_001A4BE0 + 0x25C4) == 0x36)) {
                    u8 *record;
                    *(u16 *)(((u8 *)D_L01_0028F0C0[i]) + 0x34) &= 0xFFFD;
                    record = (u8 *)func_00382348((Moby_3631C8 *)((u8 *)D_L01_0028F0C0[i]));
                    if (record) {
                        record[0x30] = 1;
                        record[0x2E] = 1;
                        if ((u32)D_L01_001D7BE0 < 41) {
                            if (D_L01_001D7BE0 != 9) D_00142DE0.total += func_L01_00444350();
                        } else if (D_L01_001D7BE0 != 9) {
                            s32 bonus = (D_00142698 + 49) / 50;
                            s32 reward;
                            u32 id = *(u16 *)(((u8 *)D_L01_0028F0C0[i]) + 0xB2);
                            s32 packed = D_001BBE90[(D_001D545C_00363690 << 10) + ((s16)id >> 1)];
                            void *table;
                            if (id & 1) {
                                if ((packed >> 4) & 8) table = D_L01_001D60E0;
                                else table = D_L01_001D60D8;
                            } else {
                                if (packed & 8) table = D_L01_001D60E0;
                                else table = D_L01_001D60D8;
                            }
                            reward = func_L01_004006C8(table, *(u16 *)(((u8 *)D_L01_0028F0C0[i]) + 0xB6), *(s16 *)(((u8 *)D_L01_0028F0C0[i]) + 0xB2));
                            reward <<= D_001A4BE0[0x28C8];
                            if (func_L01_0041A4F0()) {
                                f32 value = reward;
                                if (D_001D545C == 7 && D_0014275B[0]) reward = value * D_L01_001DAA34;
                                else reward = value * D_L01_002F1600[D_001D545C];
                            }
                            D_00142DE0.total += reward + bonus;
                        }
                    }
                    if (func_003C4B50((Moby_3631C8 *)((u8 *)D_L01_0028F0C0[i]))) {
                        u8 *m = ((u8 *)D_L01_0028F0C0[i]);
                        u8 *p;
                        qzero(m + 0xF0);
                        m[0xA8] = 255;
                        p = *(u8 **)(m + 0x68);
                        *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24);
                        *(s32 *)(p + 0x12C) = 0;
                        if (*(u8 **)(p + 0xD0)) {
                            u8 *child = *(u8 **)(*(u8 **)(p + 0xD0) + 0x68);
                            *(u32 *)(child + 0xDC) |= 0x14;
                        }
                        func_L01_0033D0E8();
                    }
                    func_L01_00363468(self);
                    func_003A52A0(1, 0, self);
                    if (D_L01_002C5600[D_00142647[0]].kind >= 4) func_L01_00451FB8(0x11F4, 1, -1, 0);
                    else func_L01_00451FB8(0x11F3, 1, -1, 0);
                    D_L01_0028F0C0[i] = 0;
                }
            }
        }
        i = next;
    }
}
/* localdecomp:end func_L01_00363690 */
