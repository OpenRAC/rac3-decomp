#include "common.h"
/* localdecomp:start func_L01_00492D18 */
typedef struct { s32 pad; s32 (*f4)(void); s32 pad8; s32 (*fC)(void); } Call_492D18;
extern u8 D_001D91C0_sda;
extern s16 D_001D91C2_sda;
extern f32 D_001D91C4_sda;
extern s32 D_001D545C_sda_00492D18;
extern u8 *D_001D52FC_sda;
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern f32 D_L01_001DF9D0;
__asm__(".extern D_L01_001DF9D0, 16");
extern Call_492D18 *func_L01_00438468(s32,s32);
extern void func_L01_004943A0(void);
extern void func_L01_0047A270(s32);
extern s32 func_L01_0047B380(void);
extern void func_L01_00513758(s32);
extern void func_L01_005120B8_00492D18(void *);
void func_L01_00492D18(void *arg) {
    if (D_001D91C0_sda == 1) {
        if (*(s32 *)(D_001D52FC + 0x1C4) & 0x10) D_001D91C0_sda = 0;
    } else if (D_001D91C0_sda == 2) {
        if (++D_001D91C2_sda >= D_001D91C4_sda) {
            func_L01_004943A0();
            func_L01_00513758(func_L01_0047B380());
                func_L01_005120B8_00492D18(arg);
        }
    } else if (D_001D545C_sda_00492D18 == 3) {
        Call_492D18 *p = func_L01_00438468(0x1936,0x10);
        if (p) {
            if (p->f4() || (*(s32 *)(D_001D52FC_sda+0x1C4)&0x80)) {
                func_L01_0047A270(4);
                func_L01_00513758(func_L01_0047B380());
                func_L01_005120B8_00492D18(arg);
            } else if (p->fC()) {
                func_L01_00513758(func_L01_0047B380());
                func_L01_005120B8_00492D18(arg);
            }
        }
    } else if (D_001D545C_sda_00492D18 == 7) {
        Call_492D18 *p = func_L01_00438468(0x1AD1,0xC);
        if (*(s32 *)(D_001D52FC+0x1C4)&0x80) {
            func_L01_0047A270(4);
            func_L01_00513758(func_L01_0047B380());
                func_L01_005120B8_00492D18(arg);
        } else if (p) {
            s32 r = p->f4();
            if (r == 1) {
                func_L01_00513758(func_L01_0047B380());
                func_L01_005120B8_00492D18(arg);
            } else if (r == 3) {
                func_L01_0047A270(10);
                D_001D91C0_sda = 2;
                D_L01_001DF9D0 = 1.0f;
                D_001D91C2_sda = 0;
            } else if (r == 2) D_001D91C0_sda = 1;
        }
    }
}
/* localdecomp:end func_L01_00492D18 */
