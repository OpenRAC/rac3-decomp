/* Historical draft: resolved in src/levels/06_starship_phoenix_under_attack/L06_0032E168.c.
   The direct global loop condition under @ps2as reproduces the bound reloads. */
/* Near miss of func_L06_0032E168: tools/check.py reports 13 diff.
   What differs: the loop's
   bound is re-read from D_L06_001DEDA0 each iteration; retail reads it into `$v0` in the delay
   slots of the skip branches (with `$gp`) and with `lui` after the call. The C reads it into a
   different register and does not copy the load into the delay slots. */
#include "common.h"
typedef struct { u8 p0[0x260]; void *f260; } S_E168_O;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; S_E168_O *f68; u8 p6C[0x3E]; s16 hAA; u8 pAC[4]; u8 bB0; } S_E168_E;
typedef struct { u8 p0[0x10]; s32 f10; u8 p14[0x54]; S_E168_O *f68; } S_E168_A;
extern S_E168_E *D_L06_001DED9C_a;
extern S_E168_E *D_L06_001DEDA0_a;
extern S_E168_E *D_L06_001DEDA0;
extern S_E168_E *D_L06_001DEDA0_c;
__asm__(".extern D_L06_001DED9C_a, 16");
__asm__(".extern D_L06_001DEDA0_a, 16");
__asm__(".extern D_L06_001DEDA0_c, 16");
extern void func_003C2880(void *);
void func_L06_0032E168(S_E168_A *a0) {
    S_E168_E *e = D_L06_001DED9C_a;
    S_E168_E *end = D_L06_001DEDA0_a;
    S_E168_A *o = (S_E168_A *)a0->f68;
    if (e < end) {
        do {
            end = D_L06_001DEDA0;
            if (e->bB0 == o->f10 && e != 0 && e->b20 != 0xFE && e->b20 != 0xFD) {
                switch (e->hAA) {
                case 0x1699:
                    { S_E168_O *x = e->f68; func_003C2880(x->f260); x->f260 = 0; }
                case 0x1619:
                case 0x1BDC:
                    func_003C2880(e);
                    end = D_L06_001DEDA0_c;
                }
            }
            e = (S_E168_E *)((u8 *)e + 0x100);
        } while (e < end);
    }
}
