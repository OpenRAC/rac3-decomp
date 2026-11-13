#include "common.h"

/* NTSC-U counterpart of func_L01_003BD608 (src/levels/01_veldin/L01_003BCDF8.c): 6 -> 7 */
/* localdecomp:start func_L01_003BBDC0 */
typedef struct { u8 p0[0x43]; u8 b43; u8 p44[0x54]; s32 f98; u8 p9C[0xE]; s16 hAA; } R_BD608;
typedef struct { u8 p0[0x324]; s32 f324; s32 f328; } P_BD608;
extern u8 *D_L01_001E009C;
__asm__(".extern D_L01_001E009C, 16");
extern u8 *D_L01_001E009C;
__asm__(".extern D_L01_001E009C, 16");
extern s32 D_001E00D8_sda;
__asm__(".extern D_001E00D8_sda, 4");
extern s16 *D_L01_0021DEA0[];
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_0044CB08(void *, void *, s32, s32);
void func_L01_003BBDC0(void *a0, P_BD608 *p) {
    R_BD608 *r;
    s16 *q;
    s32 i;
    if (p->f324 != -1) {
        r = (R_BD608 *)(D_L01_001E009C + (p->f324 << 8));
        if (r->b43 != 5) func_003BE4F0(r, 5, 0, 7);
        func_L01_0044CB08(a0, r, 1, 0);
        r->f98 = 0;
    }
    if (p->f328 != -1) {
        i = 0;
        q = D_L01_0021DEA0[p->f328];
        while ((p->f328 & 0xFF) != 0xFF && p->f328 <= D_001E00D8_sda && q != 0 && (q[-1] >= 0 || q == D_L01_0021DEA0[p->f328])) {
            r = (R_BD608 *)(D_L01_001E009C + ((*(u16 *)q & 0x7FFF) << 8));
            if (r == 0) break;
            switch (r->hAA) {
            case 0x16BD:
                if (r->b43 != 0) func_003BE4F0(r, 0, 0, 7);
                break;
            case 0x16E4:
                if (r->b43 != 5) func_003BE4F0(r, 5, 0, 7);
                break;
            }
            if (r->hAA == 0x16BD || r->hAA == 0x16E4) {
                func_L01_0044CB08(a0, r, i + 2, 0);
                i++;
                r->f98 = 0;
            }
            q++;
        }
    }
}
/* localdecomp:end func_L01_003BBDC0 */
